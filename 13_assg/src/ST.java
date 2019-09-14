import java.util.*;
import java.util.Scanner;
public class ST {

	Scanner obj=new Scanner(System.in);
	

	public void Stack()
	{
		Stack<Integer> st=new Stack<Integer>();
		int op,flag=0,data;
		while(flag!=1)
		{
			System.out.println("\n1.Push \n2.Pop \n3.Display Top \n4.IsEmpty \n5.Exit");
			op=obj.nextInt();
		switch(op)
		{
		case 1:
			System.out.println("Enter data to be added in list-: ");
			data=obj.nextInt();
			st.push(data);
			break;
			
		case 2:
			System.out.println("Data popped from stack is-: " +st.pop());
			break;
			
		case 3:
			System.out.println("Data at top of stack is-: " +st.peek());
			break;
			
		case 4:
			if(st.isEmpty())
			{
				System.out.println("Stack is Empty!!");
			}
			else
			{
				System.out.println("Stack is not empty!!");
			}
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
