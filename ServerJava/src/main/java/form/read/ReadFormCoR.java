package form.read;

import form.model.Form;
import form.model.FormException;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Abstract class that manage chain of responsability for reading request
 */
public abstract class ReadFormCoR {
    // Next node
    private ReadFormCoR m_next = null;

    /**
     * Constructor of ReadFormCoR
     * @param next
     */
    public ReadFormCoR(ReadFormCoR next) {
        this.m_next = next;
    }

    /**
     * Method to set next node
     * @param next next to set
     */
    public void setNext(ReadFormCoR next) {
        this.m_next = next;
    }

    /**
     * Method to set next node in random part of COR
     * @param rfc new node
     */
    public void addReadForm(ReadFormCoR rfc) {
        if (this.m_next == null) {
            this.m_next = rfc;
        } else {
            this.m_next.addReadForm(rfc);
        }
    }

    /**
     * Method to solve CoR
     * @param input request
     * @return Form
     */
    public Form Solve(String input) {

        if (isForm(input)) {
            try {
                return SolveForm(input);
            } catch (ReadFormException | FormException e) {
                throw new RuntimeException(e);
            }
        } else {
            if (this.m_next == null) throw new NullPointerException("ReadFormCor : next is null.");
            return this.m_next.Solve(input);
        }
    }

    /**
     * Abstract method to solve a Form
     * @param input request
     * @return form
     * @throws ReadFormException
     * @throws FormException
     */
    public abstract Form SolveForm(String input) throws ReadFormException, FormException;

    /**
     * Method that verify if request is known in form
     * @param input request
     * @return if request is known in form
     */
    public abstract boolean isForm(String input);
}
