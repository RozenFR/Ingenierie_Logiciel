package form.read;

import form.model.*;

import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Class of COR that manage Segment
 */
public class ReadSegment extends ReadFormCoR {

    /**
     * Constructor of ReadSegment
     * @param next
     */
    public ReadSegment(ReadFormCoR next) {
        super(next);
    }

    /**
     * Method that solve segment
     * @param input request
     * @return form
     */
    @Override
    public Segment SolveForm(String input) throws ReadFormException, FormException {
        Segment segment = new Segment();
        String[] inputParsed = input.split(";");

        if (input.isEmpty()) throw new ReadFormException("");

        boolean type = true;

        for(String str : inputParsed) {
            if (!type) {
                Point point = new Point();
                Pattern p = Pattern.compile("([\\+\\-]{0,1}[0-9]*[.]{0,1}[0-9]+)");
                Matcher m = p.matcher(str);
                ArrayList<String> mlist = new ArrayList<>();

                while (m.find()) {
                    mlist.add(m.group());
                }
                point.setX(Integer.parseInt(mlist.get(0)));
                point.setY(Integer.parseInt(mlist.get(1)));
                try {
                    segment.addPoint(point);
                } catch (FormException e) {
                    throw new RuntimeException(e);
                }
            } else type = false;
        }

        return segment;
    }

    /**
     * Method that verify if request is segment
     * @param input request
     * @return if request is segment
     */
    @Override
    public boolean isForm(String input) {
        // Verify initial condition
        return input.split(";")[0].toLowerCase().equals("segment");
    }
}
