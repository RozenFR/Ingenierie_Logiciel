package form.server;

import form.visitor.RenderForm;
import form.model.Form;
import form.read.ReadForm;
import form.read.ReadFormException;

import java.awt.event.WindowEvent;
import java.io.*;
import java.net.Socket;

public class FormInterlocutor extends Thread {
    // Socket linked -> client thread
    private Socket m_socket;
    // Number of connection
    private int m_noConnexion;

    // input : request
    private BufferedReader inputFlux;
    // message to send to client
    private PrintStream outputFlux;
    // Frame of client
    private RenderForm renderForm;


    /**
     * Constructor of FormInterlocutor
     * @param socket socket of client
     * @param group thread group of client
     * @param noConnexion number of client
     * @param renderForm frame of client
     */
    public FormInterlocutor(Socket socket, ThreadGroup group, int noConnexion, RenderForm renderForm) throws IOException {
        super(group, "FormInterlocutor");
        this.m_socket = socket;
        this.m_noConnexion = noConnexion;

        try {
            // Permet au client de rendre inputFlux pret pour lire du texte
            this.inputFlux = new BufferedReader(new InputStreamReader(this.m_socket.getInputStream()));
            // Permet au client de renvoyer une réponse
            this.outputFlux = new PrintStream(this.m_socket.getOutputStream());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        // Permet à l'interlocuteur de modifier la classe renderForm définit dans le main
        // - Ajouter une forme
        // - Supprimer une forme (non implementer)
        this.renderForm = renderForm;
    }

    /**
     * Thread that will listen to request from client
     */
    @Override
    public void run() {

        String input;
        String response;

        try {
            while(!isInterrupted()) {
                // Read from Client
                input = this.inputFlux.readLine();

                if (input.equals("null")) break;

                System.out.print("Client n°" + this.m_noConnexion + " has send : " );
                System.out.println(input);

                renderForm.getCircles().clear();
                renderForm.getRectangles().clear();

                // Process Input
                String inputProcess[] = input.split(":");
                for (String i : inputProcess) {
                    System.out.println(i);
                    Form form = ReadForm.StringToForm(i);
                    form.accept(renderForm);
                }

                // Return response to client
                response = "Form drawn on server.\r\n\0";
                this.outputFlux.println(response);
            }

            renderForm.getFrame().dispatchEvent(new WindowEvent(renderForm.getFrame(), WindowEvent.WINDOW_CLOSING));
        } catch (ReadFormException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            System.err.println("Can't read information from Client");
        }
    }
}
