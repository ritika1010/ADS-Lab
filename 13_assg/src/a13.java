
import java.util.Scanner;

public class a13 {

	public static void main(String[] args) {
		Scanner obj= new Scanner(System.in);
		
			int op,flag=0;
	while(flag!=1)
	{
System.out.println("\n1.Linked List \n2.Stack \n3.Priority Queue \n4.Dequeue \n5.HashSet \n6.Exit");
				op=obj.nextInt();
			switch(op)
			{
			case 1:LL l=new LL();
				l.Linked();
				break;
				
			case 2:ST s=new ST();
				s.Stack();
				break;
				
			case 3:Q q=new Q();
				q.Queue();
				break;
				
			case 4:DQ dq=new DQ();
				dq.Dequeue();
				break;
				
			case 5:HS h=new HS();
				h.HashSet();
				break;
				
			case 6:
				flag=1;
				return;
				
				
				default:
					System.out.println("Enter valid choice!!");
					break;
			}

	}

}
}
