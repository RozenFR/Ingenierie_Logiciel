package form.model;

import form.visitor.VisitorForm;

import java.util.Objects;

public class Rectangle extends GroupForm {
    private Point m_p1 = null;
    private Point m_p2 = null;
    private Point m_p3 = null;
    private Point m_p4 = null;

    public Rectangle() {

    }

    public Rectangle(Point p1, Point p2, Point p3, Point p4) {
        this.m_p1 = p1;
        this.m_p2 = p2;
        this.m_p3 = p3;
        this.m_p4 = p4;
    }

    public void setP1(Point p) throws FormException {
        if (p == null) throw new FormException("Rectangle : p1 can not be null.");
        this.m_p1 = p;
    }

    public void setP2(Point p) throws FormException {
        if (p == null) throw new FormException("Rectangle : p1 can not be null.");
        this.m_p2 = p;
    }

    public void setP3(Point p) throws FormException {
        if (p == null) throw new FormException("Rectangle : p1 can not be null.");
        this.m_p3 = p;
    }

    public void setP4(Point p) throws FormException {
        if (p == null) throw new FormException("Rectangle : p1 can not be null.");
        this.m_p4 = p;
    }

    public Point getP1() {
        return this.m_p1;
    }

    public Point getP2() {
        return this.m_p2;
    }

    public Point getP3() {
        return this.m_p3;
    }

    public Point getP4() {
        return this.m_p4;
    }

    @Override
    public void addPoint(Point point) throws FormException {
        if (this.m_p1 == null) {
            setP1(point);
        } else if (this.m_p2 == null) {
            setP2(point);
        } else if (this.m_p3 == null) {
            setP3(point);
        } else if (this.m_p4 == null) {
            setP4(point);
        } else {
            throw new FormException("Rectangle : You can not add more than 4 points");
        }
    }

    /**
     * Fonction abstraite servant à customiser les fonctionnalités de la classe Forme
     * @param vf Le visiteur fonctionnel
     */
    @Override
    void accept(VisitorForm vf) {
        vf.visit(this);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Rectangle)) return false;
        Rectangle rectangle = (Rectangle) o;
        return m_p1.equals(rectangle.m_p1) && m_p2.equals(rectangle.m_p2) && m_p3.equals(rectangle.m_p3) && m_p4.equals(rectangle.m_p4);
    }

    @Override
    public int hashCode() {
        return Objects.hash(m_p1, m_p2, m_p3, m_p4);
    }
}
