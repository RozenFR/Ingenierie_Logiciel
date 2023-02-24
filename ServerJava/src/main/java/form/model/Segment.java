package form.model;

import form.visitor.VisitorForm;

import java.util.Objects;

public class Segment extends GroupForm {
    private Point m_p1 = null;
    private Point m_p2 = null;

    public Segment() {
    }

    public Segment(Point p1, Point p2) {
        this.m_p1 = p1;
        this.m_p2 = p2;
    }

    public Point getP1() {
        return m_p1;
    }

    public Point getP2() {
        return m_p2;
    }

    public void setP1(Point p1) throws FormException {
        if (p1 == null) throw new FormException("Segment : p1 can not be null.");
        this.m_p1 = p1;
    }

    public void setP2(Point p2) throws FormException {
        if (p2 == null) throw new FormException("Segment : p2 can not be null.");
        this.m_p2 = p2;
    }

    public void addPoint(Point point) throws FormException {
        if (m_p1 == null) {
            setP1(point);
        } else if (m_p2 == null) {
            setP2(point);
        } else {
            throw new FormException("Segment : You can not add more than 2 Points in a segment.");
        }
    }

    /**
     * Fonction abstraite servant à customiser les fonctionnalités de la classe Forme
     *
     * @param vf Le visiteur fonctionnel
     */
    @Override
    public void accept(VisitorForm vf) {
        vf.visit(this);
    }

    @Override
    public String toString() {
        return "Segment{" +
                "m_p1=" + m_p1 +
                ", m_p2=" + m_p2 +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Segment)) return false;
        Segment segment = (Segment) o;
        return m_p1.equals(segment.m_p1) && m_p2.equals(segment.m_p2);
    }

    @Override
    public int hashCode() {
        return Objects.hash(m_p1, m_p2);
    }
}
