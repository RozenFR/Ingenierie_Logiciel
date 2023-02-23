package form.model;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Nested;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;

@DisplayName("Form Test")
public class FormTests {

    @Nested
    @DisplayName("Point Test")
    public class PointTest {

        Point point;

        @BeforeEach
        void setUp() {
            point = new Point();
        }

        @Test
        void AddCoordinatePointTest() throws FormException {
            point.addCoordinate(1);
            assertEquals(1, point.getDimension());
        }

        @Test
        void RemoveCoordinatePointTest() throws FormException {
            point.addCoordinate(1);
            point.removeCoordinate();
            assertEquals(0, point.getDimension());
        }

        @Test
        void GetCoordinatePointTest() throws FormException {
            point.addCoordinate(1);
            assertEquals(1, point.getCoordinate(1));
        }

        @Test
        void UpdateCoordinatePointTest() throws FormException {
            point.addCoordinate(1);
            point.updateCoordinate(1, 2);
            assertEquals(2, point.getCoordinate(1));
        }

    }
}
