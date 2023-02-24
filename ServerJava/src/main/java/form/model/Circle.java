package form.model;

import form.visitor.VisitorForm;

import java.util.Objects;

public class Circle extends GroupForm {
    /**
     *
     */
    private Point m_center = null;

    private int m_radius = 0;

    /**
     *
     */
    public Circle() {

    }

    /**
     *
     * @param center
     * @throws FormException
     */
    public Circle(Point center, int radius) throws FormException {
        setCenter(center);
        setRadius(radius);
    }

    /**
     *
     * @param p
     * @throws FormException
     */
    public void setCenter(Point p) throws FormException {
        if (p == null) throw new FormException("Rectangle : p1 can not be null.");
        this.m_center = p;
    }

    /**
     *
     * @param radius
     * @return
     */
    public void setRadius(int radius) throws FormException {
        if (radius < 0) throw new FormException("Circle : radius must be > 0.");
        this.m_radius = radius;
    }

    /**
     *
     * @return
     */
    public Point getCenter() {
        return this.m_center;
    }

    /**
     *
     * @param point
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

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Circle)) return false;
        Circle circle = (Circle) o;
        return Double.compare(circle.m_radius, m_radius) == 0 && m_center.equals(circle.m_center);
    }

    @Override
    public int hashCode() {
        return Objects.hash(m_center, m_radius);
    }

    public int getRadius() {
        return this.m_radius;
    }
}
