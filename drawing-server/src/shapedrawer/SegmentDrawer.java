package shapedrawer;
import java.awt.*;
import java.awt.image.BufferStrategy;

public class SegmentDrawer extends ShapeDrawerLink
{
    public SegmentDrawer(ShapeDrawerLink next)
    {
        super(next);
    }
    public void drawShape(String request, Frame frame, Graphics graphics, BufferStrategy bufferStrategy) throws ShapeNotRecognizedException
    {
        String[] arguments = request.split(",");
        
        String shapeName = arguments[0];
        if(!shapeName.toLowerCase().equals("segment"))
            throw new ShapeNotRecognizedException("Shape Not Recognized");
        
        /* Initialise rgb value */
        int r = Integer.parseInt(arguments[1]);
        int g = Integer.parseInt(arguments[2]);
        int b = Integer.parseInt(arguments[3]);
        
        Color color = new Color(r, g, b);
        
        int coordXA = Integer.parseInt(arguments[4]);
        int coordYA = Integer.parseInt(arguments[5]);
        int coordXB = Integer.parseInt(arguments[6]);
        int coordYB = Integer.parseInt(arguments[7]);

        /* Draw the segment */
        System.out.println("Drawing a Semgent : ");
        System.out.println(request);
        graphics.setColor(color);
        graphics.drawLine(coordXA,coordYA,coordXB,coordYB);
        bufferStrategy.show();
        System.out.println("Segment drawn");

        bufferStrategy.show();

    }
}
