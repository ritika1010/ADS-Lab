import java.util.Scanner;

class CharStack extends General
{
	char[] stack=new char[50];
	int t;
	CharStack()
	{
		t=-1;
	}
	protected void push()
	{
		Scanner x=new Scanner(System.in);
		char d;
		d=x.next().charAt(0);
		
		RuntimeException re=new RuntimeException("Overflow");
		try
		{
			if(t>=50)
			{
				x.close();
				throw re;
			}
			else
			{
				stack[++t]=d;
			}
		}
		catch(RuntimeException ret)
		{
			System.out.println("Exception Caught: " + ret);
		}
		
		
	}
	protected int pop()
	{
		char d;
		RuntimeException re=new RuntimeException("Underflow");
		try
		{
			if(t==-1)
			{
				throw re;
			}
			else
			{
				d=stack[t--];
				System.out.print(d);
				return 1;
			}
		}
		catch(RuntimeException ret)
		{
			System.out.println("Exception Caught: " + ret);
			return 0;
		}
	}
	protected int top()
	{
		char d;
		RuntimeException re=new RuntimeException("Underflow");
		try
		{
			if(t==-1)
			{
				throw re;
			}
			else
			{
				d=stack[t];
				System.out.print(d);
				return 1;
			}
		}
		catch(RuntimeException ret)
		{
			System.out.println("Exception Caught: " + ret);
			return 0;
		}
	}
}
