package form.model;

import form.visitor.VisitorForm;

import java.util.ArrayList;
import java.util.Objects;

public class Point implements Form {

    private int x = 0;
    private int y = 0;

    public Point() {

    }

    /**
     * Constuctor of Point and initialize dimension and coordinates list
     */
    public Point(int x, int y) {
        setX(x);
        setY(y);
    }

    public void setX(int x) {
        this.x = x;
    }

    public void setY(int y) {
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    @Override
    public String toString() {
        return "Point{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Point)) return false;
        Point point = (Point) o;
        return Double.compare(point.getX(), getX()) == 0 && Double.compare(point.getY(), getY()) == 0;
    }

    @Override
    public int hashCode() {
        return Objects.hash(getX(), getY());
    }

    /**
     * main accept function for Visitor
     *
     * @param vf Le visiteur fonctionnel
     */
    @Override
    public void accept(VisitorForm vf) {

    }
}
