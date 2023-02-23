//
// Created by iamze on 14/12/2022.
//

/**
 * -lwsock32
 */
#include <iostream>
#include <winsock2.h>
#include "../include/Error.hpp"

using namespace std;

int main() {
    try {
        int r;
        WSADATA wsaDATA;
        r = WSAStartup(MAKEWORD(2, 0), &wsaDATA);
        if (r) throw Error("wsadata start fail");
        cout << "start ok wsa" << endl;
    } catch (const Error &err) {
        cerr << err << endl;
    }
    return 0;
}