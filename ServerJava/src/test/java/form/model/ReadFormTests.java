package form.model;

import form.read.ReadForm;
import form.read.ReadFormException;
import org.junit.jupiter.api.*;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class ReadFormTests {

    @Nested
    @DisplayName("ReadForm String Tests")
    public class ReadFormStringTests {

        private Rect recTest;
        private Segment segTest;
        private Circle circTest;

        @BeforeEach
        void setUp() throws FormException {
            Point p1 = new Point(0, 0);
            Point p2 = new Point(0, 1);
            Point p3 = new Point(1, 1);
            Point p4 = new Point(1, 0);

            this.recTest = new Rect(p1, p2, p3, p4);
            this.segTest = new Segment(p1, p2);
            this.circTest = new Circle(p1, 1);
        }

        @Test
        void ReadSegmentTest() throws ReadFormException, FormException {
            Segment seg = (Segment) ReadForm.StringToForm("segment;(0,0);(0,1)");
            assertEquals(seg, this.segTest);
        }

        @Test
        void ReadCircleTest() throws ReadFormException, FormException {
            Circle circ = (Circle) ReadForm.StringToForm("circle;(0,0);1");
            assertEquals(circ, this.circTest);
        }

        @Test
        void ReadRectangleTest() throws ReadFormException, FormException {
            Rect rec = (Rect) ReadForm.StringToForm("rectangle;(0,0);(0,1);(1,1);(1,0)");
            assertEquals(rec, this.recTest);
        }
    }
}
