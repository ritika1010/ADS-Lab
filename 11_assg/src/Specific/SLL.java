package Specific;
import Common.CommonList;
import java.util.Scanner;
public class SLL implements CommonList
{
	node head;
	node tail;
	int sizen;

	SLL()
	{
		head=null;
		tail=null;
		sizen=0;
	}
	
	public void add()
	{
		int d;
		System.out.print("Enter data");
		Scanner o=new Scanner(System.in);
		d=o.nextInt();
		if(head==null)
		{
			head=new node(d);
			sizen++;
		}
		else
		{
			node p;
			p=head;
			while(p.next!=null)
			{
				p=p.next;
			}
			p.next=new node(d);
			sizen++;
		}
		//o.close();
	}
	
	public int size()
	{
		return sizen;
	}
	
	public void display()
	{
		node p;
		p=head;
		while(p!=null)
		{
			System.out.println(p.data);
			p=p.next;
		}
	}
	
	public void remove()
	{
		int d;
		System.out.print("Enter data to remove ");
		Scanner o=new Scanner(System.in);
		d=o.nextInt();
		node p,q;
		p=head;
		q=head;
		while(p!=null && p.data !=d)
		{
			q=p;
			p=p.next;
		}
		if(p.data==d)
		{
			sizen--;
			q.next=p.next;
			p=null;
			System.gc();
		}
		else
			System.out.println("data not present");
		
		//o.close();
	}
	
	public int isEmpty()
	{
		if(sizen==0)
			return 1;
		else
			return 0;
	}
}
