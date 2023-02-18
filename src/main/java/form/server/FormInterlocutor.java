package form.server;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;

public class FormInterlocutor extends Thread {
    private Socket m_socket;
    private int m_noConnexion;

    private BufferedReader inputFlux;
    private PrintStream outputFlux;


    /**
     *
     * @param socket
     * @param group
     * @param noConnexion
     */
    public FormInterlocutor(Socket socket, ThreadGroup group, int noConnexion) throws IOException {
        super(group, "FormInterlocutor");
        this.m_socket = socket;
        this.m_noConnexion = noConnexion;

        this.inputFlux = new BufferedReader(new InputStreamReader(this.m_socket.getInputStream()));
        this.outputFlux = new PrintStream(this.m_socket.getOutputStream());
    }

    @Override
    public void run() {
        String input;
        String response;

        try {
            while(!isInterrupted()) {
                input = this.inputFlux.readLine();
                System.out.println("Client n°" + this.m_noConnexion + "has send :" );
                System.out.println(input);
                // TODO

            }
        } catch (IOException e) {
            System.err.println(" on ne peut pas lire sur le socket provenant du client");
        }
    }
}
