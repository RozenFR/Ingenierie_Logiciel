package form.model;

import form.visitor.VisitorForm;

import java.util.ArrayList;
import java.util.Objects;

public class Point extends Form {
    /**
     * We define a point in space by its number of dimension (|R^n| = n)
     * So we must know the number of coordinate to define a point
     */
    private int m_dimension;

    /**
     * list of double (coordinate)
     */
    private ArrayList<Double> m_coordinates;

    public final static int MAX_DIM = 2;

    /**
     * Constuctor of Point and initialize dimension and coordinates list
     */
    public Point() {
        m_dimension = 0;
        m_coordinates = new ArrayList<>();
    }

    /**
     * Get number of dimension
     * @return n of R^n
     */
    public int getDimension() {
        return m_dimension;
    }

    /**
     * Get Coordinate's List
     * @return List of (1 DIM)-coordinate
     */
    public ArrayList<Double> getCoordinates() {
        return m_coordinates;
    }

    /**
     *
     * @param dim
     * @return coordinate at dim
     * @throws FormException dim >= m_dimension
     */
    public double getCoordinate(int dim) throws FormException {
        if (dim > m_dimension) throw new FormException("Point : get is out of dimension.");
        return m_coordinates.get(dim - 1);
    }

    /**
     *
     * @param dimension
     */
    private void setDimension(int dimension) throws FormException {
        if (dimension <= 0) throw new FormException("Point : dimension can not be inferior to 0.");
        this.m_dimension = dimension;
    }

    /**
     *
     * @param coordinates
     */
    public void setCoordinates(ArrayList<Double> coordinates) {
        this.m_coordinates = coordinates;
    }

    /**
     *
     * @param x
     */
    public void addCoordinate(double x) throws FormException {
        if (MAX_DIM <= m_dimension) throw new FormException("Point : max dimension attained, can't add coordinate (" + m_dimension + ")");
        m_coordinates.add(x);
        if (m_coordinates.size() > m_dimension) m_dimension++;
    }

    /**
     *
     * @param dim
     * @param x
     * @throws FormException
     */
    public void updateCoordinate(int dim, double x) throws FormException {
        if (dim > m_dimension) throw new FormException("Point : get is out of dimension (" + m_dimension + ")");
        m_coordinates.set(dim - 1, x);
    }

    /**
     *
     */
    public void removeCoordinate() throws FormException {
        if (m_dimension == 0) throw new FormException();
        if (MAX_DIM <= m_dimension) throw new FormException("Point : max dimension attained, can't add coordinate (" + m_dimension + ")");
        m_coordinates.remove(m_dimension - 1);
        m_dimension--;
    }

    /**
     * Fonction abstraite servant à customiser les fonctionnalités de la classe Forme
     *
     * @param vf Le visiteur fonctionnel
     */
    @Override
    void accept(VisitorForm vf) {

    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Point point = (Point) o;
        return m_dimension == point.m_dimension && m_coordinates.equals(point.m_coordinates);
    }

    @Override
    public int hashCode() {
        return Objects.hash(m_dimension, m_coordinates);
    }
}
