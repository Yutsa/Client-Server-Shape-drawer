package drawingserver;

import shapedrawer.ShapeDrawer;
import shapedrawer.ShapeNotRecognizedException;

import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.*;
import java.net.Socket;

/**
 * The Thread that will draw the shape sent by the client.
 * It will use a shapedrawer to be able to draw it.
 */
public class DrawingThread extends Thread
{
    /**
     * The input stream coming from the client.
     */
    private BufferedReader inputStream;
    /**
     * The output stream to communicate with the client.
     */
    private OutputStream outputStream;
    /**
     * The class that will draw the shape requested.
     */
    private ShapeDrawer shapeDrawer;

    /**
     * The Frame in which the shape will be drawn.
     */
    private Frame _frame;

    /**
     * Minimal constructor for the DrawingThread.
     * @param socket The {@link java.net.Socket} used by the client to communicate.
     * @param threadGroup The {@link java.lang.ThreadGroup} of this {@link java.lang.Thread}.
     * @param shapeDrawer The {@link ShapeDrawer} that will be used to draw the shape.
     * @throws IOException
     */
    public DrawingThread(Socket socket, ThreadGroup threadGroup, ShapeDrawer shapeDrawer)
            throws IOException
    {
        super(threadGroup, "DrawingThread");
        this.shapeDrawer = shapeDrawer;
        inputStream = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        outputStream = new PrintStream(socket.getOutputStream());
        createFrame();
    }

    private void createFrame()
    {
        _frame = new Frame("Fenêtre de dessin");
        //TODO: Don't hardcode the size of the frame.
        _frame.setBounds(0, 0, 500, 500);
        _frame.setVisible(true);
        _frame.addWindowListener(new WindowAdapter()
        {
            @Override
            public void windowClosing(WindowEvent e)
            {
                super.windowClosing(e);
                _frame.dispose();
            }
        });
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
            shapeDrawer.draw(request, _frame);
        }
        catch (IOException e)
        {
            System.err.println("Couldn't get the request from the input stream.");
            e.printStackTrace();
        }
        catch (ShapeNotRecognizedException e)
        {
            System.err.println(e.getMessage());
            //TODO: Send the error to the client using the socket output stream.
        }
    }
}
