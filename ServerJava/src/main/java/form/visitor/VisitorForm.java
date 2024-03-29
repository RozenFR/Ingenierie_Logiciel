package form.visitor;

import form.model.Circle;
import form.model.Rect;
import form.model.Segment;

public interface VisitorForm {
    /**
     * Manage all functionalities of Rectangle
     * @param rect rectangle object to apply functionalities
     */
    void visit(Rect rect);

    /**
     * Manage all functionalities of Circle
     * @param circle circle object to apply functionalities
     */
    void visit(Circle circle);

    /**
     * Manage all functionalities of Circle
     * @param segment segment object to apply functionalities
     */
    void visit(Segment segment);
}
