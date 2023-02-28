package form.read;

import form.model.Form;
import form.model.FormException;
import form.model.Point;
import form.model.Segment;

import java.io.IOException;
import java.util.ArrayList;
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
        // Setup new Segment
        Segment seg = new Segment();

        // Split input
        String[] inputParsed = input.split(";");

        // Verify initial condition
        if (input.isEmpty()) throw new ReadFormException("");

        // Loop every coordinate str = (x, y)
        for(String str : inputParsed) {
            // Setup Regex
            Pattern p = Pattern.compile("([\\+\\-]{0,1}[0-9]*[.]{0,1}[0-9]+)");
            Matcher m = p.matcher(str);

            // Setup List to Store all Match
            ArrayList<String> mlist = new ArrayList<>();
            while (m.find()) {
                mlist.add(m.group());
            }

            // Create Point
            Point point = new Point(Integer.parseInt(mlist.get(0)), Integer.parseInt(mlist.get(1)));

            // Add Point to Segment
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
        // Verify initial condition
        return input.split(";")[0].toLowerCase().equals("segment");
    }
}
