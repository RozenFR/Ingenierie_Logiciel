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
            return this.m_next.Solve(input);
        }
    }

    public int stringCounter(String input) {
        Pattern p = Pattern.compile(";");
        Matcher m = p.matcher(input);
        int count = 0;
        while (m.find()){
            count +=1;
        }
        return count;
    }

    public abstract Form SolveForm(String input) throws ReadFormException, FormException;
    public abstract boolean isForm(String input);
}