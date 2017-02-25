package drawingserver;

import shapedrawer.ShapeDrawer;
import shapedrawer.ShapeNotRecognizedException;

import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.image.BufferStrategy;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
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
    private PrintStream outputStream;
    /**
     * The class that will draw the shape requested.
     */
    private ShapeDrawer shapeDrawer;

    /**
     * The Frame in which the shape will be drawn.
     */
    private Frame _frame;

    /**
     * The Graphics of the client's Frame.
     */
    private Graphics _graphics;

    /**
     * The BufferStrategy for the Frame of the client.
     */
    private BufferStrategy _strategy;

    /**
     * The Socket to communicate with the client.
     */
    private Socket _socket;

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
        _socket = socket;
        createFrame();
    }

    /**
     * Creates the client's Frame.
     */
    private void createFrame()
    {
        initFrame();

        _frame.setIgnoreRepaint(true);

        int nbBuffers = 1;

        _frame.createBufferStrategy(nbBuffers);
        _strategy = _frame.getBufferStrategy();
        _graphics = _strategy.getDrawGraphics();

        // Waits for the BufferStrategy and Graphics to be ready
        try
        {
            Thread.sleep(200);
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }
    }
    
    private void initFrame() 
    {
    	_frame = new Frame("Fenêtre de dessin");
        
   		Toolkit tk = Toolkit.getDefaultToolkit(); Dimension d = tk.getScreenSize();
    	int displayHeight, displayWidth, windowHeight, windowWidth, xWindow, yWindow;
    		
    	displayHeight = d.height; 
    	displayWidth = d.width; 
   		windowHeight = displayHeight*3/4; 
   		windowWidth = displayWidth*3/4; 
   		xWindow = displayWidth/10; 
   		yWindow = displayHeight/10;
    		
        _frame.setBounds(xWindow, yWindow, windowWidth, windowHeight);
    	
    	_frame.addWindowListener(new WindowAdapter()
        {
            @Override
            public void windowClosing(WindowEvent e)
            {
                super.windowClosing(e);
                _frame.dispose();
            }
        });
    	
        _frame.setVisible(true);
    }


    /**
     * Draws the shape the client requested.
     */
    public void run()
    {
        String request;
        boolean stop = false;

        while (!stop)
        {
            try
            {
                request = inputStream.readLine();
                if (request == null || request == "quit")
                {
                    stop = true;
                    _socket.close();
                }
                else
                {
                    shapeDrawer.draw(request, _frame, _graphics, _strategy);

                    outputStream.println("Forme dessinée.");
                }
            }
            catch (IOException e)
            {
                System.err.println("Couldn't get the request from the input stream.");
                e.printStackTrace();
            }
            catch (ShapeNotRecognizedException e)
            {
                System.err.println(e.getMessage());
                /* Sends the error to the client using the socket output stream. */
                outputStream.println(e.getMessage());
            }
        }
    }
}
