package form.model;

import form.visitor.VisitorForm;

public interface Form {

    /**
     * main accept function for Visitor
     * @param vf Le visiteur fonctionnel
     */
    public abstract void accept(VisitorForm vf);
}
