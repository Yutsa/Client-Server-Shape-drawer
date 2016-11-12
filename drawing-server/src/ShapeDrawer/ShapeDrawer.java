package ShapeDrawer;

/**
 * Interface for the shape drawer.
 */
public interface ShapeDrawer
{
    /**
     * Draws the shape described by the request.
     * @param request String representing the shape to draw.
     * @throws ShapeNotRecognizedException If no link in the chain could
     * draw the shape, the exception is thrown.
     */
    void draw(String request) throws ShapeNotRecognizedException;
}
