package form.server;

import form.RenderForm;
import form.model.Form;
import form.read.ReadForm;
import form.read.ReadFormException;

import java.io.*;
import java.net.Socket;

public class FormInterlocutor extends Thread {
    private Socket m_socket;
    private int m_noConnexion;

    private BufferedReader inputFlux;
    private PrintStream outputFlux;
    private RenderForm renderForm;


    /**
     *
     * @param socket
     * @param group
     * @param noConnexion
     * @param renderForm
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

    @Override
    public void run() {

        String input;
        String response;

        try {
            while(!isInterrupted()) {
                input = this.inputFlux.readLine();
                System.out.print("Client n°" + this.m_noConnexion + " has send : " );
                System.out.println(input);
                Form form = ReadForm.StringToForm(input);
                form.accept(renderForm);

                response = input;

                this.outputFlux.println(response);
            }
        } catch (ReadFormException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            System.err.println("Can't read information from Client");
        }
    }
}
