#include <iostream>
#include "Socket.hpp"
#include "_WSA.hpp"
#include "FormService.hpp"

#pragma comment(lib, "ws2_32.lib")

// g++ Croix.o Rond.o Forme.o VisitorForme.o Dessiner.o DessinerJava.o Socket.o _WSA.o main.o -lwsock32

using namespace std;

#define L 200

int main() {
    /*
     * MAIN GLOBAL (TEST EN BAS)
     * */

    _WSA * wsa = _WSA::GetInstance();
    FormService * formService = new FormService();

    try {
        char adrServ[L];
        short portServ;

        cout << "Enter Ip Server Adress : " << endl;
        cin >> adrServ;
        cout << "Enter Server Port : " << endl;
        cin >> portServ;

        Socket * socket = new Socket(adrServ, portServ);

        cout << endl << "In the following instruction, you must pick : "<< endl;
        cout << "- Pick a Form" << endl;
        cout << "- Enter coordinate" << endl;
        cout << "- The end" << endl;
        cout << "1 for Rectangle, 2 for Circle or 0 to Leave" << endl;

        char input[L];
        cout << "Choice : " << endl;
        cin >> input;

        bool leaving = strcmp(input, "0") != 0;

        if (leaving) {

            Form *form = formService->getForm(input);
            // cout << "Form : " << *form << endl;

            string sform = (string) *form;
            // cout << "SForm : " << sform << endl;

            int size = sform.length();
            // cout << "Size : " << size << endl;
            char c[size + 1];
            strcpy(c, sform.c_str());
            // cout << c << endl;

            socket->Send(c);
        }

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
