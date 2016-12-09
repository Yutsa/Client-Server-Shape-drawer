package shapedrawer;

import java.awt.*;
import java.awt.image.BufferStrategy;

/**
 * The implementation of the ShapeDrawer to draw the Circle.
 */
public class CircleDrawer extends ShapeDrawerLink
{

    /**
     * Constructor
     *
     * @param next The next ShapeDrawerLink in the chain of responsibility.
     */
    public CircleDrawer(ShapeDrawerLink next)
    {
        super(next);
    }

    /**
     * Draws the Circle.
     * @param request The request of the shape to draw.
     * @param frame The frame to draw in.
     * @param graphics The frame's graphics.
     * @param bufferStrategy The frame's {@link BufferStrategy}
     * @throws ShapeNotRecognizedException
     */
    @Override
    public void drawShape(String request, Frame frame, Graphics graphics, BufferStrategy bufferStrategy) throws ShapeNotRecognizedException
    {
        String[] arguments = request.split(",");

        String shapeName = arguments[0];

        if (!shapeName.toLowerCase().equals("circle"))
            throw new ShapeNotRecognizedException("Shape not recognized");

        /* Initialise rgb value */
        int r = Integer.parseInt(arguments[1]);
        int g = Integer.parseInt(arguments[2]);
        int b = Integer.parseInt(arguments[3]);
        
        Color color = new Color(r, g, b);
        
        int coordX = Integer.parseInt(arguments[4]);
        int coordY = Integer.parseInt(arguments[5]);
        int diametre = Integer.parseInt(arguments[6]);

        /* Draw the circle */
        System.out.println("Drawing : " + request);
        graphics.setColor(color);
        graphics.fillOval(coordX - (diametre / 2), coordY - (diametre / 2), diametre, diametre);
        bufferStrategy.show();
    }
}
