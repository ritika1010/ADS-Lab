import java.util.*;
import java.util.Scanner;

public class Q {

	Scanner obj=new Scanner(System.in);
	
	public void Queue()
	{
		PriorityQueue<Integer> pq= new PriorityQueue<Integer>();
		int op,flag=0,data;
		while(flag!=1)
		{
			System.out.println("\n1.Add Data \n2.Pop \n3.Display head \n4.size \n5.Exit");
			op=obj.nextInt();
		switch(op)
		{
		case 1:
			System.out.println("Enter data to be added in Priority Queue-: ");
			data=obj.nextInt();
			pq.add(data);
			break;
			
		case 2:
			System.out.println("Data popped from Priority Queue is-: " +pq.poll());
			break;
			
		case 3:
			System.out.println("Data at top of Priority Queue is-: " +pq.peek());
			break;
			
		case 4:
			System.out.println("Size of Priority Queue is-: " +pq.size());
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
