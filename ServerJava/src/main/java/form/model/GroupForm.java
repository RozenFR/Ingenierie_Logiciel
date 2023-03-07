package form.model;

import form.visitor.VisitorForm;

/**
 * SubClass To differentiate between point and form
 */
abstract class GroupForm implements Form {
    /**
     * Abstract Method to add Point in Form
     * @param point point to add
     * @throws FormException
     */
    public abstract void addPoint(Point point) throws FormException;
}
