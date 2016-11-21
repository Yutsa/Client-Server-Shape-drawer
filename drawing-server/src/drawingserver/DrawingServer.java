package drawingserver;

import shapedrawer.*;

import java.io.IOException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;

/**
 * This class will have the ServerSocket and create Threads
 * for each connection by a client.
 */
public class DrawingServer
{
    /**
     * Launches the drawing server.
     */
    public static void main(String[] args)
    {
        ServerSocket server = null;
        ThreadGroup threadGroup = null;
        InetAddress serverAddress = null;
        int port = 0;
        int nbConnection = 0;

        port = 9112;

        try
        {
            server = new ServerSocket(port);
            /* Gets the address of the computer running the server */
            serverAddress = InetAddress.getLocalHost();
        }
        catch (UnknownHostException e)
        {
            System.err.println("The local host InetAddress couldn't be retrieved.");
            System.exit(-1);
        }
        catch (IOException e)
        {
        	e.printStackTrace();
            System.err.println("Error when creating the ServerSocket.");
            System.exit(-1);
        }

        /* Printing the InetAddress and Port of the server on stdout */
        System.out.println("The drawing server can be accessed through " + serverAddress + ":" + port);


        /* We create a ThreadGroup for all the DrawingThreads that will be created. */
        threadGroup = new ThreadGroup("drawingThreads");

        /* Creation of the chain of responsibility that will draw the shapes. */
        ShapeDrawerLink circleDrawer = new CircleDrawer(null);
        ShapeDrawerLink segmentDrawer = new SegmentDrawer(circleDrawer);
        ShapeDrawerLink polygonDrawer = new PolygonDrawer(segmentDrawer);
        ShapeDrawer shapeDrawer = polygonDrawer;

        /*
         * The loop that will wait for a connection, then create a DrawingThread
         * with for the client that connected.
         */
        while (true)
        {
            Socket newClientSocket;
            DrawingThread drawingThread;

            try
            {
                newClientSocket = server.accept();
                System.out.println("Connection successful.");
                /* Creating a shapedrawer for the drawing thread */
                drawingThread = new DrawingThread(newClientSocket, threadGroup, shapeDrawer);
                drawingThread.start();
            }
            catch (IOException e)
            {
                System.err.println("I/O error when waiting for a connection.");
                e.printStackTrace();
            }
        }
    }
}
