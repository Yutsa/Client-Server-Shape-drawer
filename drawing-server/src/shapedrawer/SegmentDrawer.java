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
        String shape = arguments[0];
        if(!shape.toLowerCase().equals("segment")){
            throw new ShapeNotRecognizedException("Shape Not Recognized");
        }
        String color = arguments[1];
        int coordXA = Integer.parseInt(arguments[2]);
        int coordYA = Integer.parseInt(arguments[3]);
        int coordXB = Integer.parseInt(arguments[4]);
        int coordYB = Integer.parseInt(arguments[5]);

        //TODO : Mettre la couleur
        graphics.drawLine(coordXA,coordYA,coordXB,coordYB);

        bufferStrategy.show();

    }
}
