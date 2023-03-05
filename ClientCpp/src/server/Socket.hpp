//
// Created by iamze on 14/12/2022.
//

#ifndef CLIENTCPP_SOCKET_HPP
#define CLIENTCPP_SOCKET_HPP

#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <winsock2.h>
#include "../Error.hpp"

using namespace std;

#define L 200

class Socket {
protected:
    SOCKET m_socket;
    SOCKADDR_IN m_sockAddrIn;
public:
    Socket(char * addr, short port) {
        Open(addr, port);
    }

    ~Socket() {
        Close();
    }

    /**
     * Initialize Socket of Socket Class
     */
    void SetSocket() {
        // SETUP ATTRIBUTE
        // Informations concernant le socket à créer : famille d'adresses acceptées, mode connecté ou non, protocole
        SOCKET sock;
        // IPv4
        int fAdr = AF_INET;
        // Mode connecté TCP
        int tSock = SOCK_STREAM;
        // Protocole, on peut aussi mettre 0 et la fonction choisit le protocole en fonction des 2 premiers paramètres
        int prot = IPPROTO_TCP;

        cout << "Socket creation ..." << endl;
        sock = socket(fAdr, tSock, prot);

        // Failure Case is socket can't initialize
        if (sock == INVALID_SOCKET) {
            ostringstream oss;
            oss << "Fail to create socket : " << WSAGetLastError() << endl;
            throw Error(oss.str().c_str());
        }

        // Assign socket to class attribute
        m_socket = sock;
        cout << "Socket has been created" << endl;
    }

    /**
     * Create Proxy for Server
     */
    void SetUpProxy(char * adrServ, short portServ) {
        // Informations concernant le serveur avec lequel on va communiquer
        SOCKADDR_IN sockaddrIn;
        sockaddrIn.sin_family = AF_INET;
        // inet_addr() convertit de l'ASCII en entier
        sockaddrIn.sin_addr.s_addr = inet_addr(adrServ);
        // htons() assure que le port est bien inscrit dans le format réseau (little-endian ou big-endian)
        sockaddrIn.sin_port = htons(portServ);
        // On l'a stock dans la classe
        m_sockAddrIn = sockaddrIn;
    }

    /**
     * * Setup Socket Class :
     * - Define WSA of Socket Class
     * - Define Socket of Socket Class
     * @param adrServ Address of Socket
     * @param portServ Port of Socket
     */
    void Open(char * adrServ, short portServ) {
        SetSocket();
        SetUpProxy(adrServ, portServ);

        cout << "Try to connect to server ..." << endl;
        int err;
        err = connect(m_socket, (SOCKADDR *) &m_sockAddrIn, sizeof(m_sockAddrIn));
        if (err == SOCKET_ERROR) throw Error("Fail to connect.");
        cout << "Successful Connexion !" << endl;
    }

    /**
     * Close connexion of Server
     */
    void Close() const {
        int err;
        err = shutdown(m_socket, SD_BOTH); // Close send and receive
        if (err) throw Error("Fail to disconnect from server. " + to_string(WSAGetLastError()));

        err = closesocket(m_socket); // Renvoie une valeur non nulle en cas d'échec.
        if (err) throw Error("Fail to close socket. " + to_string(WSAGetLastError()));

        WSACleanup();

        cout << "Stopping Server." << endl;
    }


    /**
    * Sending to Client
    */
    void Send(char * request) const {
        int err;

        // Pour que le serveur réceptionne bien le message
        strcat(request, "\r\n");
        int l = strlen(request);

        // Envoie de la requête au serveur, au plus max_len octets
        cout << "Sending ..." << endl;
        err = send(m_socket, request, l, 0);
        if (err == SOCKET_ERROR) throw Error("Fail to send request to Server.");
        cout << "Message has been sent !" << endl;

        char answer[l + 1];
        cout << "Waiting for answer ..." << endl;
        // Réception de la réponse du serveur, au plus l octets
        err = recv(m_socket, answer, l, 0);
        if (err == SOCKET_ERROR) throw Error("Fail to receive Server Response.");

        cout << answer << endl;
    }

};


#endif //CLIENTCPP_SOCKET_HPP