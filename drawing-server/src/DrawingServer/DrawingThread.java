package DrawingServer;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;

/**
 * @author Édouard WILLISSECK
 */
public class DrawingThread extends Thread
{
    Socket socket;
    BufferedReader inputStream;
    PrintStream outputStream;
    int nbConnexion;

    public DrawingThread(Socket socket, ThreadGroup threadGroup, int nbConnexion) throws IOException
    {
        this.socket = socket;
        this.nbConnexion = nbConnexion;
        inputStream = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        outputStream = new PrintStream(socket.getOutputStream());
    }
}
