package form.read;

import form.model.*;

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
     * @param input
     * @return
     */
    @Override
    public boolean isForm(String input) {
        // Verify initial condition
        return input.split(";")[0].toLowerCase().equals("segment");
    }
}
