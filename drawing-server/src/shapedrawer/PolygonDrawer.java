package shapedrawer;

import java.awt.*;
import java.awt.image.BufferStrategy;

/**
 * The implementation of the ShapeDrawer to draw a polygon
 */
public class PolygonDrawer extends ShapeDrawerLink
{
    /**
     * Constructor
     *
     * @param next The next ShapeDrawerLink in the chain of responsibility.
     */
    public PolygonDrawer(ShapeDrawerLink next) {
		super(next);
    }

    /**
     * Draws the Polygon.
     * @param request The request of the shape to draw.
     * @param frame The frame to draw in.
     * @param graphics The frame's graphics.
     * @param bufferStrategy The frame's {@link BufferStrategy}
     * @throws ShapeNotRecognizedException
     */
    @Override
	public void drawShape(String request, Frame frame, Graphics graphics, BufferStrategy bufferStrategy) throws ShapeNotRecognizedException {
		
		String[] arguments = request.split(",");
				
		String shapeName = arguments[0];
		
		if(!shapeName.toLowerCase().equals("triangle") && !shapeName.toLowerCase().equals("polygon"))
			throw new ShapeNotRecognizedException("Shape not recognized");
		
		/* Initialise rgb value */
        int r = Integer.parseInt(arguments[1]);
        int g = Integer.parseInt(arguments[2]);
        int b = Integer.parseInt(arguments[3]);
        
        Color color = new Color(r, g, b);

		/* 4 arguments are not coord, and each coord counts as 2 arguments (x and y)
         So take the number of coord with this calcul */
        int nbPoint = (arguments.length - 4) / 2;

        /* Creates the array containing all points. */
        int[] pX = new int[nbPoint];
        int[] pY = new int[nbPoint];
        
        /* For each x and y, store in an array */
        for (int i = 0; i < nbPoint; i++)
        {
        	pX[i] = (Integer.parseInt(arguments[4+i*2]));
        	pY[i] = (Integer.parseInt(arguments[5+i*2]));
        }

        /* Draw the Polygon */
        System.out.println("Drawing : " + request);
        graphics.setColor(color);
        graphics.fillPolygon(pX, pY, nbPoint);
        bufferStrategy.show();
	}
}
