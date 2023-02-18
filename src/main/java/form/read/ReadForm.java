package form.read;

import form.model.Form;

public class ReadForm {
    public static Form StringToForm(String string) throws ReadFormException {
        if (string == null) throw new ReadFormException("StringToForm : string is null.");
        ReadSegment rseg = new ReadSegment(
                            new ReadCircle(
                            new ReadRectangle(null)));
        return rseg.Solve(string);
    }
}
