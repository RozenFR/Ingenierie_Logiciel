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
#include "Error.hpp"

using namespace std;

#define L 200

class Socket {
protected:
    SOCKET * m_socket;
    SOCKADDR_IN * m_sockAddrIn;
public:
    Socket(char * addr, short port) {
        Open(addr, port);
    }

    ~Socket() {
        Close();
        delete m_socket;
        delete m_sockAddrIn;
    }

    /**
     * Initialize Socket of Socket Class
     */
    void SetSocket() {
        SOCKET sock; // Informations concernant le socket à créer : famille d'adresses acceptées, mode connecté ou non, protocole
        int fAdr = AF_INET; // IPv4
        int tSock = SOCK_STREAM; // Mode connecté TCP
        int prot = IPPROTO_TCP; // Protocole, on peut aussi mettre 0 et la fonction choisit le protocole en fonction des 2 premiers paramètres
        sock = socket(fAdr, tSock, prot);
        if (sock == INVALID_SOCKET) {
            ostringstream oss;
            oss << "Fail to create socket : " << WSAGetLastError() << endl;
            throw Error(oss.str());
        }
        (*m_socket) = sock;
        cout << "Socket has been created" << endl;
    }

    /**
     * Create Proxy for Server
     */
    void SetUpProxy(char * adrServ, short portServ) {
        SOCKADDR_IN sockaddrIn; // Informations concernant le serveur avec lequel on va communiquer
        sockaddrIn.sin_family = AF_INET;
        sockaddrIn.sin_addr.s_addr = inet_addr(adrServ); // inet_addr() convertit de l'ASCII en entier
        sockaddrIn.sin_port = htons(portServ); // htons() assure que le port est bien inscrit dans le format réseau (little-endian ou big-endian)
        (*m_sockAddrIn) = sockaddrIn;
    }

    /**
     * Setup Socket Class :
     * - Define WSA of Socket Class
     * - Define Socket of Socket Class
     */
    void Open(char * adrServ, short portServ) {
        SetSocket();
        SetUpProxy(adrServ, portServ);
    }

    /**
     * Close connexion of Server
     */
    void Close() {
        int err;
        err = shutdown((*m_socket), SD_BOTH); // Close send and receive
        if (err) throw Error("Fail to disconnect from server. " + to_string(WSAGetLastError()));

        err = closesocket((*m_socket)); // Renvoie une valeur non nulle en cas d'échec.
        if (err) throw Error("Fail to close socket. " + to_string(WSAGetLastError()));

        cout << "Stopping Server." << endl;
    }

    /**
     * Sending to Client
     */
     void Send(char * request) const {
         int err;

        err = connect((*m_socket), (SOCKADDR *) m_sockAddrIn, sizeof((*m_sockAddrIn)));
        if (err == SOCKET_ERROR) throw Error("Fail to connect.");
        cout << "Successful Connexion !" << endl;

        strcat(request, "\r\n"); // Pour que le serveur réceptionne bien le message
        int l = strlen(request);
        err = send((*m_socket), request, l, 0); // Envoie de la requête au serveur, au plus l octets
        if (err == SOCKET_ERROR) throw Error("Fail to send request to server.");

        char * answer;
        err = recv((*m_socket), answer, l, 0); // Réception de la réponse du serveur, au plus l octets
        if (err == SOCKET_ERROR) throw Error("Fail to receive Server Response.");
        char * p = strchr(answer, '\n');
        *p = '\0';
        cout << answer << endl;
     }

};


#endif //CLIENTCPP_SOCKET_HPP
