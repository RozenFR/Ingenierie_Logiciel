package form.model;

import form.visitor.VisitorForm;

import java.util.Objects;

import static java.lang.Math.pow;
import static java.lang.Math.sqrt;

/**
 * Class that manage Rectangle Form
 */
public class Rect extends GroupForm {
    // P1
    private Point m_p1 = null;
    // P2
    private Point m_p2 = null;
    // P3
    private Point m_p3 = null;
    // P4
    private Point m_p4 = null;

    /**
     * Construtor of Rect
     */
    public Rect() {

    }

    /**
     * Constructor of Rect
     * @param p1 1st Point
     * @param p2 2nd Point
     * @param p3 3rd Point
     * @param p4 4th Point
     */
    public Rect(Point p1, Point p2, Point p3, Point p4) {
        this.m_p1 = p1;
        this.m_p2 = p2;
        this.m_p3 = p3;
        this.m_p4 = p4;
    }

    /**
     * Method to set P1
     * @param p P1
     * @throws FormException
     */
    public void setP1(Point p) throws FormException {
        if (p == null) throw new FormException("Rectangle : p1 can not be null.");
        this.m_p1 = p;
    }

    /**
     * Method to set P2
     * @param p P2
     * @throws FormException
     */
    public void setP2(Point p) throws FormException {
        if (p == null) throw new FormException("Rectangle : p2 can not be null.");
        this.m_p2 = p;
    }

    /**
     * Method to set P3
     * @param p P3
     * @throws FormException
     */
    public void setP3(Point p) throws FormException {
        if (p == null) throw new FormException("Rectangle : p3 can not be null.");
        this.m_p3 = p;
    }

    /**
     * Method to set P4
     * @param p P4
     * @throws FormException
     */
    public void setP4(Point p) throws FormException {
        if (p == null) throw new FormException("Rectangle : p4 can not be null.");
        this.m_p4 = p;
    }

    /**
     * Method to get P1
     * @return P1
     */
    public Point getP1() {
        return this.m_p1;
    }

    /**
     * Method to get P2
     * @return P2
     */
    public Point getP2() {
        return this.m_p2;
    }

    /**
     * Method to get P3
     * @return P3
     */
    public Point getP3() {
        return this.m_p3;
    }

    /**
     * Method to get P4
     * @return P4
     */
    public Point getP4() {
        return this.m_p4;
    }

    /**
     * Method to add a point in Rect
     * @param point point to add
     * @throws FormException
     */
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
     * Method to get Area of rectangle
     * @return Aire du rectangle
     */
    @Deprecated
    public double getArea() {
        // On transforme nos points en vecteurs, on suppose que vect(AB) et vect(AD) ont un angle de 90°
        double[] v1 = new double[2];
        double[] v2 = new double[2];
        // vect(AB)
        v1[0] = getP2().getX() - getP1().getX();
        v1[1] = getP2().getY() - getP1().getY();
        // vect(AD)
        v2[0] = getP4().getX() - getP1().getX();
        v2[1] = getP4().getY() - getP1().getY();
        // Calcul de la norme de |vect(AB)|
        double normev1 = sqrt(pow(v1[0], 2) + pow(v1[1],2));
        // Calcul de la norme de |vect(AD)|
        double normev2 = sqrt(pow(v2[0], 2) + pow(v2[1],2));

        return normev1 * normev2;
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
     * @param o other Rect
     * @return if every value equals
     */
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Rect)) return false;
        Rect rect = (Rect) o;
        return m_p1.equals(rect.m_p1) && m_p2.equals(rect.m_p2) && m_p3.equals(rect.m_p3) && m_p4.equals(rect.m_p4);
    }

    /**
     * overload hashcode
     * @return hashcode
     */
    @Override
    public int hashCode() {
        return Objects.hash(m_p1, m_p2, m_p3, m_p4);
    }
}
