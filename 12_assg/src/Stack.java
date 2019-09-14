import java.util.Scanner;

public class Stack {

	public static void main(String[] args) {
		int ch;
		System.out.println("STACK IMPLEMENTATION");
		System.out.println("1.For integers");
		System.out.println("2.For Characters");
		System.out.println("enter choice:");
		
		Scanner x=new Scanner(System.in);
		ch=x.nextInt();
		
		General t;
		switch(ch)
		{
		case 1:t=new IntStack();
			t.GenFunc();
			break;
			
		case 2:t=new CharStack();
			t.GenFunc();
			break;
			
		}
		
		x.close();

	}

}
