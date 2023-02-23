#include <iostream>
#include "../include/Socket.hpp"
#include "../include/_WSA.hpp"
#include "../include/FormService/FormService.hpp"

#pragma comment(lib, "ws2_32.lib")

// g++ Croix.o Rond.o Forme.o VisitorForme.o Dessiner.o DessinerJava.o Socket.o _WSA.o main.o -lwsock32

using namespace std;

#define L 200

int main() {
    _WSA * wsa = _WSA::GetInstance();

    try {
        char adrServ[L];
        short portServ;

        cout << "Enter Ip Server Adress : " << endl;
        cin >> adrServ;
        cout << "Enter Server Port : " << endl;
        cin >> portServ;

        Socket * socket = new Socket(adrServ, portServ);

        Form * f1;
        string input = "";
        cout << endl << "In the following instruction, you must pick : "<< endl;
        cout << "1 - Pick a Form" << endl;
        cout << "2 - Enter coordinate" << endl;
        cout << "3 - The end" << endl;
        while (input != "Quitter") {
            cout << "Pick a form to draw on Server (Circle, Rectangle, Cross ou Quitter) : " << endl;
            cin >> input;
            FormService * fs = new FormService();
            Form * f = fs->processInput(input);
        }

    } catch (Error err) {
        cerr << err << endl;
    }


    return 0;
}
