package form.read;

import form.model.Form;
import form.model.FormException;
import form.model.Point;
import form.model.Segment;

import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ReadSegment extends ReadFormCoR {

    public ReadSegment(ReadFormCoR next) {
        super(next);
    }

    /**
     * @param input
     * @return
     */
    @Override
    public Segment SolveForm(String input) throws ReadFormException, FormException {
        Segment seg = new Segment();
        String[] inputParsed = input.split(";");

        if (input.isEmpty()) throw new ReadFormException("");
        if (!input.matches("^([(]{1}([\\+\\-]{0,1}[0-9]*[.]{0,1}[0-9]*[,]{0,1}[\\s]{0,1})+[)]{1}[;]{1}){1}"
                + "[(]{1}([\\+\\-]{0,1}[0-9]*[.]{0,1}[0-9]*[,]{0,1}[\\s]{0,1})+[)]{1}$"))
            throw new ReadFormException("ReadCircle : Incorrect Circle Format, must be (x, y);(x, y)");

        for(String str : inputParsed) {
            Point point = new Point();
            Pattern p = Pattern.compile("([\\+\\-]{0,1}[0-9]*[.]{0,1}[0-9]+)");
            Matcher m = p.matcher(str);
            while (m.find()) {
                Double number = Double.parseDouble(m.group());
                point.addCoordinate(number);
            }
            try {
                seg.addPoint(point);
            } catch (FormException e) {
                throw new RuntimeException(e);
            }
        }

        return seg;
    }

    /**
     * @param input
     * @return
     */
    @Override
    public boolean isForm(String input) {
        return input.matches("^([(]{1}([\\+\\-]{0,1}[0-9]*[.]{0,1}[0-9]*[,]{0,1}[\\s]{0,1})+[)]{1}[;]{1}){1}"
                + "[(]{1}([\\+\\-]{0,1}[0-9]*[.]{0,1}[0-9]*[,]{0,1}[\\s]{0,1})+[)]{1}$");
    }
}
