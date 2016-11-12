package ShapeDrawer;

/**
 * @author Édouard WILLISSECK
 */
public abstract class ShapeDrawerLink implements ShapeDrawer
{
    private ShapeDrawerLink _next;

    public ShapeDrawerLink(ShapeDrawerLink next)
    {
        _next = next;
    }

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

    public abstract void drawShape(String request) throws ShapeNotRecognizedException;
}
