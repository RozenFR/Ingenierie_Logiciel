package form.server;

import java.io.IOException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;

public class FormServer {
    public static void main(String[] args) {
        ServerSocket server;
        try {
            server = new ServerSocket(9111); // Server listen to port 9111
            System.out.println("Form Server has started : " + server);
        } catch (IOException e) {
            System.out.println("Form Server has failed");
            throw new RuntimeException(e);
        }

        InetAddress machine;
        int localPort;
        ThreadGroup group;

        try {
            localPort = server.getLocalPort();
            machine = InetAddress.getLocalHost();
            System.out.println("IP address of Form Server : " + machine.getHostAddress());
            System.out.println("Server Port : " + localPort);
        } catch (UnknownHostException e) {
            throw new RuntimeException(e);
        }

        group = new ThreadGroup("socketsClients");
        int noConnexion = 0;

        while(true) {
            Socket newSock;
            FormInterlocutor newInterlocutor;

            try {
                newSock = server.accept();
                ++noConnexion;
                System.out.println("Connexion n°" + noConnexion + " : successful.");

                newInterlocutor = new FormInterlocutor(newSock, group, noConnexion);
                newInterlocutor.start();
            } catch (IOException e) {
                System.err.println("Connexion n°" + noConnexion + " : failed.");
                throw new RuntimeException(e);
            }

        }
    }
}
