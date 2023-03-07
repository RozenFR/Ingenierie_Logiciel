package form.model;

import form.visitor.VisitorForm;

import java.util.Objects;

/**
 * Class that manage Circle
 */
public class Circle extends GroupForm {
    // Center
    private Point m_center = null;
    // Radius of circle
    private int m_radius = 0;

    /**
     * Constructor of Circle
     */
    public Circle() {

    }

    /**
     * Constructor of circle
     * @param center center point
     * @param radius radius of circle
     * @throws FormException
     */
    public Circle(Point center, int radius) throws FormException {
        setCenter(center);
        setRadius(radius);
    }

    /**
     * Method to set Center point
     * @param p point to set
     * @throws FormException
     */
    public void setCenter(Point p) throws FormException {
        if (p == null) throw new FormException("Rectangle : p1 can not be null.");
        this.m_center = p;
    }

    /**
     * Method to set radius
     * @param radius radius of circle
     */
    public void setRadius(int radius) throws FormException {
        if (radius < 0) throw new FormException("Circle : radius must be > 0.");
        this.m_radius = radius;
    }

    /**
     * Method to get center point
     * @return Center Point
     */
    public Point getCenter() {
        return this.m_center;
    }

    /**
     * Method to get radius of circle
     * @return radius of circle
     */
    public int getRadius() {
        return this.m_radius;
    }

    /**
     * Method to Add a Point
     * @param point point to add
     * @throws FormException
     */
    @Override
    public void addPoint(Point point) throws FormException {
        if (this.m_center == null) {
            setCenter(point);
        } else {
            throw new FormException("Rectangle : You can not add more than 4 points");
        }
    }

    /**
     * Fonction abstraite servant à customiser les fonctionnalités de la classe Forme
     * @param vf Le visiteur fonctionnel
     */
    @Override
    public void accept(VisitorForm vf) {
        vf.visit(this);
    }

    /**
     * Overload equals
     * @param o other circle
     * @return if every value equals
     */
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Circle)) return false;
        Circle circle = (Circle) o;
        return Double.compare(circle.m_radius, m_radius) == 0 && m_center.equals(circle.m_center);
    }

    /**
     * overload hashcode
     * @return hashcode
     */
    @Override
    public int hashCode() {
        return Objects.hash(m_center, m_radius);
    }

}
