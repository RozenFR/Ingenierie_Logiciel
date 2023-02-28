package form.read;

import form.model.Form;
import form.model.FormException;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public abstract class ReadFormCoR {
    private ReadFormCoR m_next = null;

    public ReadFormCoR(ReadFormCoR next) {
        this.m_next = next;
    }

    public void setNext(ReadFormCoR next) {
        this.m_next = next;
    }

    public void addReadForm(ReadFormCoR rfc) {
        if (this.m_next == null) {
            this.m_next = rfc;
        } else {
            this.m_next.addReadForm(rfc);
        }
    }

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

    public abstract Form SolveForm(String input) throws ReadFormException, FormException;
    public abstract boolean isForm(String input);
}
