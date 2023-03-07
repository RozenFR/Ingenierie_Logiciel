package form.read;

import form.model.*;

import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Class of COR that manage Circle
 */
public class ReadCircle extends ReadFormCoR {

    /**
     * Constructor of ReadCircle
     * @param next
     */
    public ReadCircle(ReadFormCoR next) {
        super(next);
    }

    /**
     * Method that solve circle
     * @param input request
     * @return form
     */
    @Override
    public Form SolveForm(String input) throws ReadFormException, FormException {
        // Create new circle
        Circle circ = new Circle();
        // Parse form
        String[] inputParsed = input.split(";");

        if (input.isEmpty()) throw new ReadFormException("");

        // Set regex pattern to read number of point
        Point center = new Point();
        Pattern p = Pattern.compile("([\\+\\-]{0,1}[0-9]*[.]{0,1}[0-9]+)");
        Matcher m = p.matcher(inputParsed[1]);

        // Subsidiary : add to list
        ArrayList<String> mlist = new ArrayList<>();
        while (m.find()) {
            mlist.add(m.group());
        }

        // add to circle objet
        center.setX(Integer.parseInt(mlist.get(0)));
        center.setY(Integer.parseInt(mlist.get(1)));
        circ.addPoint(center);
        circ.setRadius((int) Math.round(Double.parseDouble(inputParsed[2])));

        return circ;
    }

    /**
     * Method that verify if request is circle
     * @param input request
     * @return if request is circle
     */
    @Override
    public boolean isForm(String input) {
        return input.split(";")[0].toLowerCase().equals("circle");
    }
}
