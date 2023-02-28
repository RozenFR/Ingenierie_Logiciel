package form.read;

import form.model.*;

import java.util.ArrayList;
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
        Matcher m = p.matcher(inputParsed[1]);

        ArrayList<String> mlist = new ArrayList<>();
        while (m.find()) {
            mlist.add(m.group());
        }

        center.setX(Integer.parseInt(mlist.get(0)));
        center.setY(Integer.parseInt(mlist.get(1)));

        circ.addPoint(center);
        circ.setRadius((int) Math.round(Double.parseDouble(inputParsed[2])));

        return circ;
    }

    /**
     * @param input
     * @return
     */
    @Override
    public boolean isForm(String input) {
        return input.split(";")[0].toLowerCase().equals("circle");
    }
}
