package form.model;

import form.visitor.VisitorForm;

import java.util.ArrayList;
import java.util.Objects;

/**
 * Class that manage a point
 */
public class Point implements Form {

    // x coordinate
    private int x = 0;
    // y coordinate
    private int y = 0;

    /**
     * Constructor of Point
     */
    public Point() {

    }

    /**
     * Constuctor of Point and initialize dimension and coordinates list
     */
    public Point(int x, int y) {
        setX(x);
        setY(y);
    }

    /**
     * Method to set x
     * @param x coordinate x
     */
    public void setX(int x) {
        this.x = x;
    }

    /**
     * Method to set y
     * @param y coordinate y
     */
    public void setY(int y) {
        this.y = y;
    }

    /**
     * Method to get x
     * @return x
     */
    public int getX() {
        return x;
    }

    /**
     * Method to get y
     * @return y
     */
    public int getY() {
        return y;
    }

    /**
     * Overload toString
     * @return string
     */
    @Override
    public String toString() {
        return "Point{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }

    /**
     * Overload equals
     * @param o other point
     * @return true if every value equals
     */
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Point)) return false;
        Point point = (Point) o;
        return Double.compare(point.getX(), getX()) == 0 && Double.compare(point.getY(), getY()) == 0;
    }

    /**
     * overload hashcode
     * @return
     */
    @Override
    public int hashCode() {
        return Objects.hash(getX(), getY());
    }

    /**
     * main accept function for Visitor
     * @param vf Le visiteur fonctionnel
     */
    @Override
    public void accept(VisitorForm vf) {

    }
}
