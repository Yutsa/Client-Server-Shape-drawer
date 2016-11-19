package shapedrawer;

import java.awt.*;
import java.awt.image.BufferStrategy;


public class CircleDrawer extends ShapeDrawerLink
{

    public CircleDrawer(ShapeDrawerLink next)
    {
        super(next);
    }

    @Override
    public void drawShape(String request, Frame frame, Graphics graphics, BufferStrategy bufferStrategy) throws ShapeNotRecognizedException
    {
        String[] arguments = request.split(",");

        String shape = arguments[0];

        if (!shape.toLowerCase().equals("circle"))
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
        //TODO: Change the color
        System.out.println("Drawing a Circle");
        System.out.println(request);
        graphics.setColor(color);
        graphics.fillOval(coordX, coordY, diametre, diametre);
        bufferStrategy.show();
        System.out.println("Circle drawn");
    }
}
