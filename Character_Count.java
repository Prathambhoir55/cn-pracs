import java.util.*;
public class Character_Count
{
	public static void main(String[] args)
	{
		int n;
		String ans=""; 
		String rec_data;
		Scanner sc = new Scanner(System.in); 
		System.out.print("Enter the number of data frames: "); 
		n=sc.nextInt();
		String data[] = new String[n];
		for(int i=0;i<n;i++)
		{
			System.out.print("Enter data: "); 
			data[i]=sc.next(); 
			ans=ans+String.valueOf(data[i].length()+1); 
			ans=ans+data[i];
		}
		System.out.println("\n"+"Frames created: "+ans); 
		System.out.println("\nReceiver side: "); 
		System.out.print("Enter the received data: "); 		
		rec_data = sc.next();
		int c=0; 
		while(n!=0)
		{
			int l=Integer.parseInt(String.valueOf(rec_data.charAt(c))); 
			c++;
			while(l>1)
			{
				System.out.print(rec_data.charAt(c)); 
				l--;
				c++;
			}
			System.out.print("\n");
			n--;
		}
	}
}