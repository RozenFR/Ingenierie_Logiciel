package form;

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

    private static final long serialVersionUID = 1L;
    private BufferStrategy strategy;
    private boolean running = false;
    private int delay = 10;

    JFrame frame;

    private ArrayList<Circle> circles = new ArrayList<>();
    private ArrayList<Rect> rectangles = new ArrayList<>();

    private static final int max = 255;
    private static final int min = 0;

    public RenderForm() {
        setPreferredSize(new Dimension(1920, 1080));
        addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                if (e.getKeyCode() == KeyEvent.VK_ESCAPE) {
                    running = false;
                }
            }
        });

        frame = new JFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(this);
        frame.pack();
        frame.setVisible(true);
        this.start();
    }

    public JFrame getFrame() {
        return frame;
    }

    private void drawCircle(Graphics g) {
        // Set Color of Circle
        g.setColor(Color.ORANGE);

        for (Circle circle : circles) {
            g.fillOval(circle.getCenter().getX() - circle.getRadius(), circle.getCenter().getY() - circle.getRadius(),
                    2 * circle.getRadius(), 2 * circle.getRadius());
        }
    }

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

    public ArrayList<Circle> getCircles() {
        return circles;
    }

    public void setCircles(ArrayList<Circle> circles) {
        this.circles = circles;
    }

    public ArrayList<Rect> getRectangles() {
        return rectangles;
    }

    public void setRectangles(ArrayList<Rect> rectangles) {
        this.rectangles = rectangles;
    }

    public void addCircle(Circle circle) {
        if (circle == null)  throw new IllegalArgumentException("circle is null.");
        circles.add(circle);
    }

        public void addRect(Rect rect) {
        if (rect == null)  throw new IllegalArgumentException("rect is null.");
        rectangles.add(rect);
    }

    public void start() {
        createBufferStrategy(2);
        strategy = getBufferStrategy();
        running = true;
        new Thread(this).start();
    }

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

    private void draw(Graphics g) {
        g.setColor(Color.WHITE);
        g.fillRect(0, 0, getWidth(), getHeight());
        drawCircle(g);
        drawRectangle(g);
    }

    /**
     * Manage all functionalities of Rectangle
     *
     * @param rect rectangle object to apply functionalities
     */
    @Override
    public void visit(Rect rect) {
        addRect(rect);
    }

    /**
     * Manage all functionalities of Circle
     *
     * @param circle circle object to apply functionalities
     */
    @Override
    public void visit(Circle circle) {
        addCircle(circle);
    }

    /**
     * Manage all functionalities of Circle
     *
     * @param segment segment object to apply functionalities
     */
    @Override
    @Deprecated
    public void visit(Segment segment) {

    }
}