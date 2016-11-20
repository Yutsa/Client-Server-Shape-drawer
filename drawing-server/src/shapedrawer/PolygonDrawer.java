package shapedrawer;

import java.awt.Color;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.image.BufferStrategy;

/**
 * @author Édouard WILLISSECK
 */
public class PolygonDrawer extends ShapeDrawerLink
{
	public PolygonDrawer(ShapeDrawerLink next) {
		super(next);
	}

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

		// 4 arguments are not coord, and each coord counts as 2 arguments (x and y)
        int nbPoint = (arguments.length-4)/2;
        
        int[] pX = null, pY = null;
        
        for (int i = 0; i < nbPoint; i++)
        {
        	pX[i] = Integer.parseInt(arguments[4+i*2]);
        	pY[i] = Integer.parseInt(arguments[5+i*2]);
        }
        
        /* Draw the Polygon */
        System.out.println("Drawing a Polygon : ");
        System.out.println(request);
        graphics.setColor(color);
        graphics.fillPolygon(pX, pY, nbPoint);
        bufferStrategy.show();
        System.out.println("Polygon drawn");        
	}
}
