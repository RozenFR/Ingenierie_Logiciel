#include <iostream>
#include "server/Socket.hpp"
#include "server/_WSA.hpp"
#include "form/service/create/FormServiceCreation.hpp"
#include "CoordinatesSystem.hpp"
#include "form/visitor/CoordinatesConverter.hpp"

#pragma comment(lib, "ws2_32.lib")

// g++ Croix.o Rond.o Forme.o VisitorForm.o Dessiner.o DessinerJava.o Socket.o _WSA.o main.o -lwsock32

using namespace std;

#define L 200

int main() {
    /*
     * MAIN GLOBAL (TEST EN BAS)
     * */

    _WSA * wsa = _WSA::GetInstance();
    FormServiceCreation * formService = new FormServiceCreation();

    try {
        char adrServ[L];
        short portServ;

        cout << "Enter Ip Server Adress : " << endl;
        cin >> adrServ;
        cout << "Enter Server Port : " << endl;
        cin >> portServ;

        Socket * socket = new Socket(adrServ, portServ);

        double px1, px2, py1, py2;

        cout << "============== Define working area ==============" << endl;
        cout << "px1 :  " << endl;
        cin >> px1;
        cout << "py1 :  " << endl;
        cin >> py1;
        cout << "px2 :  " << endl;
        cin >> px2;
        cout << "py2 :  " << endl;
        cin >> py2;
        cout << endl;


        CoordinatesConverter * cc = new CoordinatesConverter(px1, py1, px2, py2);
        CoordinatesSystem * cs = CoordinatesSystem::GetInstance(cc);

        while (true) {
            cout << "============== MENU ==============" << endl;
            cout << "Welcome User, please select one of the option : " << endl;
            cout << "1 - Create Form" << endl;
            cout << "2 - Remove Form" << endl;
            cout << "3 - Modify Form" << endl;
            cout << "0 - Leaving Client" << endl;

            int inputMenu;
            cout << "Choice of Menu :   " << endl;
            cin >> inputMenu;

            if (inputMenu != 0) {
                if (inputMenu == 1) { // 1 - Create Form
                    while (true) {
                        cout << "============== Create Form ==============" << endl;
                        cout << "Please pick one form of your choice : " << endl;
                        cout << "1 - Rectangle" << endl;
                        cout << "2 - Circle" << endl;
                        cout << "0 - Go Back" << endl;

                        // User choice
                        int inputCreateForm;
                        cout << "Choice of your Form :  " << endl;
                        cin >> inputCreateForm;

                        if (inputCreateForm != 0) {
                            // Select a visitor to manage input with a specific selection
                            formService->getForm(inputCreateForm);
                        } else break;

                        // initialize request
                        string sform = (string) *cs;
                        int size = sform.length();
                        char c[size + 1];
                        strcpy(c, sform.c_str());

                        // Send Creation Request
                        socket->Send(c);
                    }
                } else if (inputMenu == 2) { // 2 - Remove Form

                    cout << "============== List of Removable Form ==============" << endl;
                    int count = 0;
                    for (Form * form : cs->getForms()) {
                        cout << count << " - " << *form << endl;
                        count++;
                    }

                    // Choice of User
                    int index;
                    cout << "Choice of your Form :  ";
                    cin >> index;

                    if (index < count && index >= 0) {
                        cs->RemoveForm(index);

                        // initialize request
                        string sform = (string) *cs;
                        int size = sform.length();
                        char c[size + 1];
                        strcpy(c, sform.c_str());

                        // Send Creation Request
                        socket->Send(c);
                    } else cerr << "INDEX IS OUT OF RANGE" << endl;

                } else if (inputMenu == 3) { // 3 - Modify Form
                    while (true) {
                        cout << "============== Modify Form ==============" << endl;
                        cout << "Please pick one form of your choice : " << endl;
                        cout << "1 - Dilation" << endl;
                        cout << "2 - Rotate" << endl;
                        cout << "0 - Go Back" << endl;

                        int inputModifyForm;
                        cout << "Choice of your Modification :  " << endl;
                        cin >> inputModifyForm;

                        if (inputModifyForm != 0) {
                            cout << "============== List of Modifiable Form ==============" << endl;
                            int count = 0;
                            for (Form * form : cs->getForms()) {
                                cout << count << " - " << *form << endl;
                                count++;
                            }

                            // Choice of User
                            int index;
                            cout << "Choice of your Form :  ";
                            cin >> index;

                            if (index < count && index >= 0) {
                                // TODO
                            } else cerr << "INDEX IS OUT OF RANGE" << endl;

                        } else break;
                    }
                }
            } else break;
        }

        delete socket;
        cout << "Client has been closed." << endl;

    } catch (Error err) {
        cerr << err << endl;
    }



//    /*
//     * TEST FORM
//     * */
//
//    Form *f1, *f2;
//    f1 =  new class Circle(1.0, 2.0, 3.0);
//    cout << *f1 << endl;
//
//    f2 = new class Rectangle(1.1, 1.2, 2.1, 2.2, 3.1, 3.2, 4.1, 4.2);
//    cout << *f2 << endl;



//    /*
//     * TEST SERVICE
//     * */
//
//    cout << "============= " << "Define COR" << " =============" << endl;
//
//    FormServiceCOR * fs;
//    fs = new class RectangleServiceCOR(new class CircleServiceCOR());
//    cout << "Service OK" << endl;
//    cout << *fs << endl;
//
//    cout << "============= " << "Test isForm Rectangle" << " =============" << endl;
//
//    cout << "IsResctangle : " << fs->isForm("1") << endl;
//    cout << "IsNotRectangle : " << fs->isForm("0") << endl;
//
//    cout << "============= " << "Test isForm Circle" << " =============" << endl;
//
//    cout << "IsCircle : " << fs->getNext()->isForm("2") << endl;
//    cout << "IsNotCircle : " << fs->getNext()->isForm("1") << endl;
//
//    cout << "============= " << "Test SolveForm Circle" << " =============" << endl;
//
//    Circle * circle = dynamic_cast<Circle *> (fs->getNext()->solveForm());
//    cout << *circle << endl;
//
//    cout << "============= " << "Test SolveForm Rectangle" << " =============" << endl;
//
//    Rect * rect = dynamic_cast<Rect *>(fs->solveForm());
//    cout << *rect << endl;
//
//    cout << "============= " << "Test Solve Rect" << " =============" << endl;
//
//    Form * rect1 = fs->solve("1");
//    cout << "isRectangleSolve : " << *rect1 << endl;
//
//    cout << "============= " << "Test Solve Circle" << " =============" << endl;
//
//    Form * circle1 = fs->solve("2");
//    cout << "isCircleSolve : " << *circle1 << endl;
//
//    cout << "============= " << "Test FormService Rectangle" << " =============" << endl;
//    FormService * fservice = new FormService();
//    Form * rect2 = fservice->getForm("1");
//    cout << "Form Service Rectangle : " << *rect2 << endl;

    return 0;
}
