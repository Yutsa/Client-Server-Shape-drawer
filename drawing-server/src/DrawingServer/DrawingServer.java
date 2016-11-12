package DrawingServer;

import ShapeDrawer.*;

import java.io.IOException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;

/**
 * @author Édouard WILLISSECK
 * This class will be have the ServerSocket and create Threads
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

        port = 9111;
        try
        {
            server = new ServerSocket(port);
            /* Gets the address of the computer running the server */
            serverAddress = InetAddress.getLocalHost();
        }
        catch (UnknownHostException e)
        {
            System.err.println("The local host InetAddress couldn't be retrieved.");
        }
        catch (IOException e)
        {
            System.err.println("Error when creating the ServerSocket.");
        }

        /* Printing the InetAddress and Port of the server on stdout */
        System.out.println("The drawing server can be accessed through " + serverAddress + ":" + port);


        /* We create a ThreadGroup for all the DrawingThreads that will be created. */
        threadGroup = new ThreadGroup("drawingThreads");

        /*
         * The loop that will wait for a connection, then create a DrawingServer.DrawingThread
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
                /* Creating a ShapeDrawer for the drawing thread */
                ShapeDrawer shapeDrawer = new CircleDrawer();
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
