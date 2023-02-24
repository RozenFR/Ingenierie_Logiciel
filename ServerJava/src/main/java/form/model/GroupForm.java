package form.model;

import form.visitor.VisitorForm;

abstract class GroupForm implements Form {
    public abstract void addPoint(Point point) throws FormException;
}
