import java.util.Scanner;

abstract class General
{
	General()
	{}
	int ch,flag,data;
	Scanner in=new Scanner(System.in);
	void GenFunc()
	{
		do{
			flag=0;
			int ch;
			
			System.out.println("1.push");
			System.out.println("2.pop");
			System.out.println("3.top");
			System.out.println("enter choice:");
			
			Scanner in=new Scanner(System.in);
			ch=in.nextInt();
			switch(ch)
			{
				case 1: push();
				break;
				
				case 2:data=pop();
					if(data!=0)
					{
						System.out.println(" is data from stack");
					}
				break;
				
				case 3:data=top();
					if(data!=0)
					{
						System.out.println(" is data from stack");
					}
				break;
				
				case 4:System.out.println("Invalid");
					flag=1;
				break;
				
			}
			
		}while(flag==0);
		
	}
	abstract protected void push();
	abstract protected int pop();
	abstract protected int top();

}
