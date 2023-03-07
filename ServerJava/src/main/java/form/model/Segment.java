package form.model;

import form.visitor.VisitorForm;

import java.util.Objects;

/**
 * Class that manage segment form
 */
public class Segment extends GroupForm {
    // P1
    private Point m_p1 = null;
    // P2
    private Point m_p2 = null;

    /**
     * Constructor of Segment
     */
    public Segment() {
    }

    /**
     * Constructor of Segment
     * @param p1 1st point
     * @param p2 2nd point
     */
    public Segment(Point p1, Point p2) {
        this.m_p1 = p1;
        this.m_p2 = p2;
    }

    /**
     * Method to get P1
     * @return P1
     */
    public Point getP1() {
        return m_p1;
    }

    /**
     * Method to get P2
     * @return P2
     */
    public Point getP2() {
        return m_p2;
    }

    /**
     * Method to set P1
     * @param p1 1st point
     * @throws FormException
     */
    public void setP1(Point p1) throws FormException {
        if (p1 == null) throw new FormException("Segment : p1 can not be null.");
        this.m_p1 = p1;
    }

    /**
     * Method to set P2
     * @param p2 2nd point
     * @throws FormException
     */
    public void setP2(Point p2) throws FormException {
        if (p2 == null) throw new FormException("Segment : p2 can not be null.");
        this.m_p2 = p2;
    }

    /**
     * Method to add point / construct
     * @param point point to add
     * @throws FormException
     */
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
     * @param vf Le visiteur fonctionnel
     */
    @Override
    public void accept(VisitorForm vf) {
        vf.visit(this);
    }

    /**
     * Overload toString
     * @return string
     */
    @Override
    public String toString() {
        return "Segment{" +
                "m_p1=" + m_p1 +
                ", m_p2=" + m_p2 +
                '}';
    }

    /**
     * Overload equals
     * @param o other segment
     * @return if every value equals
     */
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Segment)) return false;
        Segment segment = (Segment) o;
        return m_p1.equals(segment.m_p1) && m_p2.equals(segment.m_p2);
    }

    /**
     * overload hashcode
     * @return hashcode
     */
    @Override
    public int hashCode() {
        return Objects.hash(m_p1, m_p2);
    }
}
