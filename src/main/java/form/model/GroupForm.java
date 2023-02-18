package form.model;

import form.visitor.VisitorForm;

abstract class GroupForm extends Form {

    /**
     * main accept function for Visitor
     * @param vf Le visiteur fonctionnel
     */
    @Override
    abstract void accept(VisitorForm vf);

    public abstract void addPoint(Point point) throws FormException;
}
