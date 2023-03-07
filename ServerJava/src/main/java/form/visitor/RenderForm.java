package form.visitor;

import form.model.Circle;
import form.model.Rect;
import form.model.Segment;
import form.visitor.VisitorForm;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.BufferStrategy;
import java.util.ArrayList;

import static java.lang.Math.pow;
import static java.lang.Math.sqrt;

public class RenderForm extends Canvas implements Runnable, VisitorForm {
    private BufferStrategy strategy; // buffer strategy
    private boolean running = false; // running
    private int delay = 10; // time to delay

    JFrame frame; // Main Frame for client

    private ArrayList<Circle> circles = new ArrayList<>(); // List of circle
    private ArrayList<Rect> rectangles = new ArrayList<>(); // list of rectangle

    /**
     * Constructor of RenderForm
     */
    public RenderForm() {
        // Define size of frame
        setPreferredSize(new Dimension(1920, 1080));
        // Set e as escape key
        addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                if (e.getKeyCode() == KeyEvent.VK_ESCAPE) {
                    running = false;
                }
            }
        });

        // Set frame
        frame = new JFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(this);
        frame.pack();
        frame.setVisible(true);
        this.start();
    }

    /**
     * Method to get AWT Frame
     * @return frame
     */
    public JFrame getFrame() {
        return frame;
    }

    /**
     * Method to draw every circle
     * @param g g bind in strategy
     */
    private void drawCircle(Graphics g) {
        // Set Color of Circle
        g.setColor(Color.ORANGE);

        for (Circle circle : circles) {
            g.fillOval(circle.getCenter().getX() - circle.getRadius(), circle.getCenter().getY() - circle.getRadius(),
                    2 * circle.getRadius(), 2 * circle.getRadius());
        }
    }

    /**
     * Method to draw every Rectangle
     * @param g g bind in strategy
     */
    private void drawRectangle(Graphics g) {
        // Set Color of Rectangle
        g.setColor(Color.MAGENTA);

        for (Rect rect : rectangles) {
            g.drawLine(rect.getP1().getX(), rect.getP1().getY(),
                    rect.getP2().getX(), rect.getP2().getY());
            g.drawLine(rect.getP2().getX(), rect.getP2().getY(),
                    rect.getP3().getX(), rect.getP3().getY());
            g.drawLine(rect.getP3().getX(), rect.getP3().getY(),
                    rect.getP4().getX(), rect.getP4().getY());
            g.drawLine(rect.getP4().getX(), rect.getP4().getY(),
                    rect.getP1().getX(), rect.getP1().getY());
        }
    }

    /**
     * Method to get all circles
     * @return list of circle
     */
    public ArrayList<Circle> getCircles() {
        return circles;
    }

    /**
     * Method to set list of circle
     * @param circles list of circle
     */
    public void setCircles(ArrayList<Circle> circles) {
        this.circles = circles;
    }

    /**
     * Method to get all rectangles
     * @return list of rectangle
     */
    public ArrayList<Rect> getRectangles() {
        return rectangles;
    }

    /**
     * Method to set list of rectangle
     * @param rectangles list of rectangle
     */
    public void setRectangles(ArrayList<Rect> rectangles) {
        this.rectangles = rectangles;
    }

    /**
     * Method to add a circle in list
     * @param circle circle to add
     */
    public void addCircle(Circle circle) {
        if (circle == null)  throw new IllegalArgumentException("circle is null.");
        circles.add(circle);
    }

    /**
     * Method to add a rectangle in list
     * @param rect rectangle to add
     */
    public void addRect(Rect rect) {
        if (rect == null)  throw new IllegalArgumentException("rect is null.");
        rectangles.add(rect);
    }

    /**
     * Method start to implements buffer strategy
     */
    public void start() {
        createBufferStrategy(2);
        strategy = getBufferStrategy();
        running = true;
        new Thread(this).start();
    }

    /**
     * Thread that will update frame
     */
    public void run() {
        while (running) {
            try {
                Thread.sleep(delay);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            Graphics g = strategy.getDrawGraphics();
            draw(g);
            g.dispose();
            strategy.show();
        }
        System.exit(0);
    }

    /**
     * Method to draw everything
     * @param g g bind to buffer
     */
    private void draw(Graphics g) {
        g.setColor(Color.WHITE);
        g.fillRect(0, 0, getWidth(), getHeight());
        drawCircle(g);
        drawRectangle(g);
    }

    /**
     * Manage all functionalities of Rectangle
     * @param rect rectangle object to apply functionalities
     */
    @Override
    public void visit(Rect rect) {
        addRect(rect);
    }

    /**
     * Manage all functionalities of Circle
     * @param circle circle object to apply functionalities
     */
    @Override
    public void visit(Circle circle) {
        addCircle(circle);
    }

    /**
     * Manage all functionalities of Circle
     * @param segment segment object to apply functionalities
     */
    @Override
    @Deprecated
    public void visit(Segment segment) {

    }
}