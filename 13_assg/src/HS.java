import java.util.*;
import java.util.Scanner;

public class HS {

	Scanner obj=new Scanner(System.in);
	
	public void HashSet()
	{
		HashSet<Integer> hs= new HashSet<Integer>();
		int op,flag=0,data;
		while(flag!=1)
		{
			System.out.println("\n1.Add element \n2.Remove element \n3.Display whole \n4.size\n5.Exit");
			op=obj.nextInt();
		switch(op)
		{
		case 1:
			System.out.println("Enter data to be added in HashSet-: ");
			data=obj.nextInt();
			hs.add(data);
			break;
			
		case 2:
			System.out.println("Enter data to be removed from Deque-: ");
			data=obj.nextInt();
			hs.remove(data);
			break;
			
		case 3:
			System.out.println("Elements in whole Hashset are-:  "+hs);
			break;
			
		case 4:
			System.out.println("Size of HashSet is-:  "+hs.size());
			break;
			
		case 5:
			flag=1;
			break;
			
		default:
			System.out.println("Enter valid choice!!");
			break;
		}
		}
		
	}
}

