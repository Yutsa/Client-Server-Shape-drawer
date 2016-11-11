package DrawingServer;

import ShapeDrawer.ShapeDrawer;

import java.io.*;
import java.net.Socket;

/**
 * The Thread that will draw the shape sent by the client.
 * It will use a ShapeDrawer to be able to draw it.
 * @author Édouard WILLISSECK
 */
public class DrawingThread extends Thread
{
    private BufferedReader inputStream;
    //private OutputStream outputStream;
    private ShapeDrawer shapeDrawer;

    /**
     * Minimal constructor for the DrawingThread.
     * @param socket The @Socket used by the client to communicate.
     * @param threadGroup The @ThreadGroup of this @Thread.
     * @param shapeDrawer The @ShapeDrawer that will be used to draw the shape.
     * @throws IOException
     */
    public DrawingThread(Socket socket, ThreadGroup threadGroup, ShapeDrawer shapeDrawer)
            throws IOException
    {
        super(threadGroup, "DrawingThread");
        this.shapeDrawer = shapeDrawer;
        inputStream = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        //outputStream = new PrintStream(socket.getOutputStream());
    }

    /**
     * Draws the shape the client resquested.
     */
    public void run()
    {
        String request;

        try
        {
            request = inputStream.readLine();
            shapeDrawer.draw(request);
        }
        catch (IOException e)
        {
            System.err.println("Couldn't get the request from the input stream.");
            e.printStackTrace();
        }
    }
}
