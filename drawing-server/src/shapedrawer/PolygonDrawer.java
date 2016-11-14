package shapedrawer;

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
		String shape = arguments[0];
		
		if(!shape.toLowerCase().equals("triangle") && !shape.toLowerCase().equals("polygon"))
		{
			throw new ShapeNotRecognizedException("Shape not recognized");
		}
		
        String color = arguments[1];
        
        int nbPoint = (arguments.length-2)/2;
        
        int[] pX = null, pY = null;
        
        for (int i = 0; i < nbPoint; i++)
        {
        	pX[i] = Integer.parseInt(arguments[2+i*2]);
        	pY[i] = Integer.parseInt(arguments[3+i*2]);
        }
        
        //TODO get color 
        graphics.fillPolygon(pX, pY, nbPoint);
        
	}
	
}
