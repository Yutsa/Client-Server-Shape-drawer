package ShapeDrawer;

/**
 * @author Édouard WILLISSECK
 * Interface for the shape drawer.
 */
public interface ShapeDrawer
{
    /**
     * Draws the shape described by the @request.
     * @param request String representing the shape to draw.
     */
    void draw(String request) throws ShapeNotRecognizedException;
}
