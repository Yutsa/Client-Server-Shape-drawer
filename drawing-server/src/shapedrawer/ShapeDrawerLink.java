package shapedrawer;

import java.awt.*;
import java.awt.image.BufferStrategy;

/**
 * The implementation of a link in the chain of responsibility that will
 * draw the shape.
 */
public abstract class ShapeDrawerLink implements ShapeDrawer
{
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
     * @throws ShapeNotRecognizedException If no links in the chain of
     * responsibility could draw the shape it throws this Exception.
     */
    @Override
    public void draw(String request, Frame frame) throws ShapeNotRecognizedException
    {
        // Implementation
        try
        {
            this.drawShape(request, frame);
        }
        catch (ShapeNotRecognizedException e)
        {
            if (_next != null)
            {
                _next.draw(request, frame);
            }
            else
            {
                throw new ShapeNotRecognizedException("Couldn't find the drawer for this shape.");
            }
        }
    }

    /**
     * Returns the buffer strategy of the frame passed as parameter.
     *
     * @param frame The frame for which you want the parameter.
     * @return Graphics The graphics of the Frame
     */
    public Graphics getGraphics(Frame frame)
    {
        int nbBuffers = 1;
        frame.createBufferStrategy(nbBuffers);

        try
        {
            Thread.sleep(150);
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }

        BufferStrategy strategy = frame.getBufferStrategy();

        return strategy.getDrawGraphics();
    }

    /**
     * Check if it can draw the shape requested, if it can it draws it
     * otherwise it throws a {@link ShapeNotRecognizedException}
     * @param request The request of the shape to draw.
     * @param frame The frame to draw in.
     * @throws ShapeNotRecognizedException Thrown if this link couldn't draw the shape.
     */
    public abstract void drawShape(String request, Frame frame) throws ShapeNotRecognizedException;
}