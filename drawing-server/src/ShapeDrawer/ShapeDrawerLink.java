package ShapeDrawer;

/**
 * The implementation of a link in the chain of responsibility that will
 * draw the shape.
 */
public abstract class ShapeDrawerLink implements ShapeDrawer
{
    private ShapeDrawerLink _next;

    /**
     * Creates a ShapeDrawerLink by declaring the next link in the chain of responsibility.
     * @param next The next link of the ShapeDrawer chain of responsibility.
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
     * @throws ShapeNotRecognizedException If no links in the chain of
     * responsibility could draw the shape it throws this Exception.
     */
    @Override
    public void draw(String request) throws ShapeNotRecognizedException
    {
        // Implementation
        try
        {
            this.drawShape(request);
        }
        catch (ShapeNotRecognizedException e)
        {
            if (_next != null)
            {
                _next.draw(request);
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
     * @throws ShapeNotRecognizedException Thrown if this link couldn't draw the shape.
     */
    public abstract void drawShape(String request) throws ShapeNotRecognizedException;
}
