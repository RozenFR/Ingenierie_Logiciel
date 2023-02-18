package form.read;

import form.model.*;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ReadCircle extends ReadFormCoR {

    public ReadCircle(ReadFormCoR next) {
        super(next);
    }

    /**
     * @param input
     * @return
     */
    @Override
    public Form SolveForm(String input) throws ReadFormException, FormException {
        Circle circ = new Circle();
        String[] inputParsed = input.split(";");

        if (input.isEmpty()) throw new ReadFormException("");

        Point center = new Point();
        Pattern p = Pattern.compile("([\\+\\-]{0,1}[0-9]*[.]{0,1}[0-9]+)");
        Matcher m = p.matcher(inputParsed[0]);

        while (m.find()) {
            double x = Double.parseDouble(m.group());
            center.addCoordinate(x);
        }

        circ.addPoint(center);
        circ.setRadius(Double.parseDouble(inputParsed[1]));

        return circ;
    }

    /**
     * @param input
     * @return
     */
    @Override
    public boolean isForm(String input) {
        return input.matches("^([(]{1}([\\+\\-]{0,1}[0-9]*[.]{0,1}[0-9]*[,]{0,1}[\\s]{0,1})+[)]{1}){1}"
                + "[;]([0-9]*[.]{0,1}[0-9])+$");
    }
}
