import java.net.*;
import java.io.*;
 
public class Server
{
    public static void main(String[] args) throws IOException 
    {
        ServerSocket s = new ServerSocket(2019);     
        System.out.println("Server Started, waiting for client");
         
        Socket s1 = s.accept();
 
        // Client Send
        BufferedReader br = new BufferedReader(
            new InputStreamReader(s1.getInputStream())
        );
         
        OutputStream out = s1.getOutputStream();
        PrintStream ps  = new PrintStream(out);
 
        BufferedReader br1 = new BufferedReader(
            new InputStreamReader(System.in)
        );
 
        do{         
            String res = br.readLine();
 
            System.out.println("Client Send: "+res);
              
            System.out.print("Server: ");
            String msg = br1.readLine();
            System.out.print("\n\n");
            ps.println(msg);
 
        }
        while(true);
    }
}