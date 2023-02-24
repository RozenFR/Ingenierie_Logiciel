package form.server;

import form.RenderForm;
import form.model.Circle;
import form.model.FormException;
import form.model.Point;

import java.io.IOException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;

public class FormServer {
    public static void main(String[] args) throws FormException {
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

        RenderForm renderForm = new RenderForm();
        // new Circle(new Point(400, 250), 50).accept(renderForm);

        while(true) {
            Socket newSock;
            FormInterlocutor newInterlocutor;
            try {
                // attente de connexion de la part d'un nouveau client
                newSock = server.accept();
                // la connexion a eu lieu et un socket a été créé : nouveauClientSocket
                ++noConnexion;
                System.out.println("Connexion n°" + noConnexion + " : successful.");
                // Creation d'un thread pour gerer les transactions avec le nouveau client
                // => Thread en parallele pour gerer les differents clients
                newInterlocutor = new FormInterlocutor(newSock, group, noConnexion, renderForm);
                newInterlocutor.start();
            } catch (IOException e) {
                System.err.println("Connexion n°" + noConnexion + " : failed.");
                throw new RuntimeException(e);
            }

        }
    }
}
