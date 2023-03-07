package form.read;

import form.model.Form;

/**
 * Main class of COR Service for request
 */
public class ReadForm {
    /**
     * static method that read request and transform it in a form object known
     * @param input request
     * @return form
     * @throws ReadFormException
     */
    public static Form StringToForm(String input) throws ReadFormException {
        if (input == null) throw new ReadFormException("StringToForm : string is null.");
        ReadSegment rseg = new ReadSegment(
                            new ReadCircle(
                            new ReadRectangle(null)));
        return rseg.Solve(input);
    }
}
