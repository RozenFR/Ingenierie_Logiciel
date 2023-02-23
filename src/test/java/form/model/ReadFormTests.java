package form.model;

import form.read.ReadCircle;
import form.read.ReadForm;
import form.read.ReadFormException;
import form.read.ReadSegment;
import org.junit.jupiter.api.*;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class ReadFormTests {

    @Nested
    @DisplayName("ReadForm String Tests")
    public class ReadFormStringTests {

        private Rectangle recTest;
        private Segment segTest;
        private Circle circTest;

        @BeforeEach
        void setUp() throws FormException {
            Point p1 = new Point();
            p1.addCoordinate(0);
            p1.addCoordinate(0);

            Point p2 = new Point();
            p2.addCoordinate(0);
            p2.addCoordinate(1);

            Point p3 = new Point();
            p3.addCoordinate(1);
            p3.addCoordinate(1);

            Point p4 = new Point();
            p4.addCoordinate(1);
            p4.addCoordinate(0);

            this.recTest = new Rectangle(p1, p2, p3, p4);
            this.circTest = new Circle(p1, 1);
            this.segTest = new Segment(p1, p2);

        }

        @Test
        void ReadSegmentTest() throws ReadFormException, FormException {
            Segment seg = (Segment) ReadForm.StringToForm("(0,0);(0,1)");
            assertEquals(seg, this.segTest);
        }

        @Test
        void ReadCircleTest() throws ReadFormException, FormException {
            Circle circ = (Circle) ReadForm.StringToForm("(0,0);1");
            assertEquals(circ, this.circTest);
        }

        @Test
        void ReadRectangleTest() throws ReadFormException, FormException {
            Rectangle rec = (Rectangle) ReadForm.StringToForm("(0,0);(0,1);(1,1);(1,0)");
            assertEquals(rec, this.recTest);
        }

    }

}
