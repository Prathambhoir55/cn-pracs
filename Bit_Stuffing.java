import java.io.*;
import java.net.*;
import java.util.Scanner; 
public class Bit_Stuffing
{
    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the Message to be Sent : "); 
        String data = sc.nextLine();
        int cnt = 0; 
        String s = "";
        for (int i = 0; i < data.length(); i++) 
        { 
            char ch = data.charAt(i);
            if (ch == '1') 
            {
                cnt++;
                if (cnt < 5) 
                    s += ch;
                else 
                {
                    s = s + ch + '0';
                    cnt = 0;
                }
            }
            else
            {
                s += ch; 
                cnt = 0;
            }
        }
        s = "01111110" + s + "01111110";
        System.out.println("Data stuffed in client: " + s); 
        System.out.println("Sending to server for unstuffing"); 
   
        System.out.println("Enter the Stuffed data received : "); 
        String s1 = sc.nextLine();
        System.out.println("Stuffed data from client: " + s1);
        System.out.println("Unstuffed data: "); 
        int c = 0;
        for (int i = 8; i < s.length() - 8; i++) 
        { 
            char ch = s1.charAt(i);
            if (ch == '1') 
            { 
                c++;
                System.out.print(ch);
                if (c == 5) 
                {
                    i++;
                    c = 0;
                }
            }
            else 
            {
                System.out.print(ch);
                c = 0;
            }
        }
    }
}
