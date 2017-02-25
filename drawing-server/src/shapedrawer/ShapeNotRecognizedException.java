package shapedrawer;

/**
 * The exception thrown when a drawer couldn't draw what is had to.
 */
public class ShapeNotRecognizedException extends Exception
{
    public ShapeNotRecognizedException(String message)
    {
        super(message);
    }
}
