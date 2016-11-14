package shapedrawer;

import java.awt.*;


public class CircleDrawer extends ShapeDrawerLink
{

    public CircleDrawer(ShapeDrawerLink next)
    {
        super(next);
    }

    @Override
    public void drawShape(String request, Frame frame) throws ShapeNotRecognizedException
    {
        String[] arguments = request.split(",");
        String color = arguments[0];
        String shape = arguments[1];

    }
}
