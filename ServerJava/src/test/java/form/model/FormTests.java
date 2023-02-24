package form.model;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Nested;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

@DisplayName("Form Test")
public class FormTests {

    @Nested
    @DisplayName("Point Test")
    public class PointTest {

        Point point;

        @BeforeEach
        void setUp() {
            point = new Point(0, 0);
        }

        @Test
        void CreatePointTest() {
            assertEquals(new Point(0, 0), this.point);
        }

        @Test
        void SetXPointTest() {
            this.point.setX(1);
            assertEquals(new Point(1, 0), this.point);
        }

        @Test
        void SetYPointTest() {
            this.point.setY(1);
            assertEquals(new Point(0, 1), this.point);
        }



    }
}
