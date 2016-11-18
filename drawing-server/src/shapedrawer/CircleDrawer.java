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

        String color = arguments[1];
        int coordX = Integer.parseInt(arguments[2]);
        int coordY = Integer.parseInt(arguments[3]);
        int diametre = Integer.parseInt(arguments[4]);


        /* Draw the circle */
        //TODO: Change the color
        System.out.println("Drawing a Circle");
        System.out.println(request);
        graphics.fillOval(coordX, coordY, diametre, diametre);
        bufferStrategy.show();
        System.out.println("Circle drawn");


    }
}
