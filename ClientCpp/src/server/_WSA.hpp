//
// Created by iamze on 14/12/2022.
//

#ifndef CLIENT__WSA_HPP
#define CLIENT__WSA_HPP

#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <winsock2.h>
#include "../Error.hpp"

using namespace std;

class _WSA {
protected:
    static _WSA * s_wsa;
    WSAData * m_wsadata;

    _WSA() {
        SetWSA();
    }

    /**
     * Initialize WSA of Socket Class
     */
    void SetWSA() {
        int err;
        WSAData wsaData; //Structure concernant les donnees de la librairie WinSock à init
        err = WSAStartup(MAKEWORD(2, 0), &wsaData); // MAKEWORD sert à indiquer la version de la librairie à utiliser : 1 pour winsock, 2 pour winsock2
        if (err) throw Error("Fail to initialize.");
        m_wsadata = &wsaData;
        cout << "Client for Forme is Online." << endl;
    }

public:

    _WSA(_WSA &wsa) = delete;

    ~_WSA() {
        WSACleanup();
    }

    static _WSA * GetInstance() {
        if (s_wsa == nullptr) {
            s_wsa = new _WSA();
        }
        return s_wsa;
    }
};


#endif //CLIENT__WSA_HPP
