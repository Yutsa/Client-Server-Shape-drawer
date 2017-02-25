package shapedrawer;

import java.awt.*;
import java.awt.image.BufferStrategy;

/**
 * The implementation of a link in the chain of responsibility that will
 * draw the shape.
 */
public abstract class ShapeDrawerLink implements ShapeDrawer
{
    /**
     * The next link of the chain of responsibility.
     */
    private ShapeDrawerLink _next;

    /**
     * Creates a ShapeDrawerLink by declaring the next link in the chain of responsibility.
     * @param next The next link of the shapedrawer chain of responsibility.
     */
    public ShapeDrawerLink(ShapeDrawerLink next)
    {
        _next = next;
    }

    /**
     * Tries to draw the shape itself using its drawShape method, if it can't
     * it checks if it has a next link a calls its draw method. Otherwise it
     * throws a {@link ShapeNotRecognizedException}.
     * @param request String representing the shape to draw.
     * @param frame The frame to draw in.
     * @param graphics
     * @param strategy
     * @throws ShapeNotRecognizedException If no links in the chain of
     * responsibility could draw the shape it throws this Exception.
     */
    @Override
    public void draw(String request, Frame frame, Graphics graphics, BufferStrategy strategy) throws ShapeNotRecognizedException
    {
        try
        {
            this.drawShape(request, frame, graphics, strategy);
        }
        catch (ShapeNotRecognizedException e)
        {
            if (_next != null)
            {
                _next.draw(request, frame, graphics, strategy);
            }
            else
            {
                throw new ShapeNotRecognizedException("Couldn't find the drawer for this shape.");
            }
        }
    }


    /**
     * Check if it can draw the shape requested, if it can it draws it
     * otherwise it throws a {@link ShapeNotRecognizedException}
     * @param request The request of the shape to draw.
     * @param frame The frame to draw in.
     * @param graphics The frame's graphics.
     * @param bufferStrategy The frame's {@link BufferStrategy}
     * @throws ShapeNotRecognizedException Thrown if this link couldn't draw the shape.
     */
    public abstract void drawShape(String request, Frame frame, Graphics graphics, BufferStrategy bufferStrategy) throws ShapeNotRecognizedException;
}
