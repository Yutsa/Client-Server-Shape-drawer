package shapedrawer;

import java.awt.*;
import java.awt.image.BufferStrategy;

/**
 * Interface for the shape drawer.
 */
public interface ShapeDrawer
{
    /**
     * Draws the shape described by the request.
     * @param request String representing the shape to draw.
     * @param frame The frame to draw in.
     * @param graphics
     * @param strategy
     * @throws ShapeNotRecognizedException If no link in the chain could
     * draw the shape, the exception is thrown.
     */
    void draw(String request, Frame frame, Graphics graphics, BufferStrategy strategy) throws ShapeNotRecognizedException;
}
