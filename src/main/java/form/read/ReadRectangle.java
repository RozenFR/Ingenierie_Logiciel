package form.read;

import form.model.*;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ReadRectangle extends ReadFormCoR {
    public ReadRectangle(ReadFormCoR next) {
        super(next);
    }

    /**
     * @param input
     * @return
     * regex : ^([(]{1}([\+\-]{0,1}[0-9]*[.]{0,1}[0-9]*[,]{0,1}[\s]{0,1})+[)]{1}[;]{0,1}){3}[(]{1}([\+\-]{0,1}[0-9]*[.]{0,1}[0-9]*[,]{0,1}[\s]{0,1})+[)]{1}$
     */
    @Override
    public Form SolveForm(String input) throws ReadFormException, FormException {
        Rectangle rec = new Rectangle();
        String[] inputParsed = input.split(";");

        if (input.isEmpty()) throw new ReadFormException("");

        for(String str : inputParsed) {
            Point point = new Point();
            Pattern p = Pattern.compile("([\\+\\-]{0,1}[0-9]*[.]{0,1}[0-9]+)");
            Matcher m = p.matcher(str);
            while (m.find()) {
                double number = Double.parseDouble(m.group());
                point.addCoordinate(number);
            }
            try {
                rec.addPoint(point);
            } catch (FormException e) {
                throw new RuntimeException(e);
            }
        }

        return rec;
    }

    /**
     * @param input
     * @return
     */
    @Override
    public boolean isForm(String input) {
        return input.matches("^([(]{1}([\\+\\-]{0,1}[0-9]*[.]{0,1}[0-9]*[,]{0,1}[\\s]{0,1})+[)]{1}[;]{1}){3}"
                + "[(]{1}([\\+\\-]{0,1}[0-9]*[.]{0,1}[0-9]*[,]{0,1}[\\s]{0,1})+[)]{1}$");
    }
}
