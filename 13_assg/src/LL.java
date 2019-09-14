import java.util.*;
import java.util.Scanner;
public class LL {
	
	Scanner obj=new Scanner(System.in);
	
	public void Linked()
	{
		LinkedList<Integer> l= new LinkedList<Integer>();
		int op,flag=0,data;
		while(flag!=1)
		{
			System.out.println("\n1.Add First \n2.Add Last \n3.Remove First \n4.Remove Last \n5.Display whole list \n6.Exit");
			op=obj.nextInt();
		switch(op)
		{
		case 1:
			System.out.println("Enter data to be added in list-: ");
			data=obj.nextInt();
			l.addFirst(data);
			break;
			
		case 2:
			System.out.println("Enter data to be added in list-: ");
			data=obj.nextInt();
			l.addLast(data);
			break;
			
		case 3:
			l.removeFirst();
			break;
			
		case 4:
			l.removeLast();
			break;
			
		case 5:
			System.out.println("Contents of Linked List are-: "+l);
			break;
			
		case 6:
			flag=1;
			break;
			
			default:
				System.out.println("Enter valid choice!!");
				break;
		}
		}

		
	}

}
