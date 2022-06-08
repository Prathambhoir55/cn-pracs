import java.io.*; 
import java.util.*; 
import java.net.*;
public class Byte_Stuffing
{
    public static void main(String args[]) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the Message to be Sent : "); 
        String data = sc.nextLine();
        String res = new String();
        for (int i = 0; i < data.length(); i++) 
        {
            if (data.charAt(i) == 'F' && i != 0 && i != (data.length() - 1)) 
                res = res + 'E' + data.charAt(i);
            else if (data.charAt(i) == 'E')   
                res = res + 'E' + data.charAt(i); 
            else
                res = res + data.charAt(i);
        }
        System.out.println("The data being sent (with byte stuffed) is : " + res);


        String out = new String();
        System.out.println("Message Received...Successfully!!!"); 
        System.out.println("Enter the stuffed message : ");
        String rec = sc.nextLine();
        for (int i = 1; i < rec.length() - 1; i++) 
        {
            if (rec.charAt(i) == 'D' || rec.charAt(i) == 'F')
                out = out + rec.charAt(i);
            else if (rec.charAt(i) == 'E' && rec.charAt(i + 1) == 'E') 
            {
                out = out + 'E'; 
                i++;
            }
        }
        System.out.println("The Destuffed Message is : " + out); 
        System.out.println("Messaging is over .... EXITING");

    }
}

