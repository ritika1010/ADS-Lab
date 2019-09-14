#include<iostream>
using namespace std;

class table
{
	string s[26][2];
public:
	table()
	{
		for(int i=0; i<26;i++)
		{
			s[i][0]=" ";
			s[i][1]=" ";
		}
	}
	
	int hashfunc(string w);
	void insert(string w,string m);
	void insertrep(string w,string m);
	int find(string w);
	void del(string w);
	void display();
};


int table :: hashfunc(string w)
{
	char c=w[0];
	int ch=c;
	return ch-97;
}
void table :: insert(string w,string m)
{
	int index=hashfunc(w);
	//cout<<index;
	if(s[index][0]==" ")
	{
		s[index][0]=w;
		s[index][1]=m;
	}
	else
	{
		int p=index+1;
		while(s[p][0]!=" " && p!=index)
		{
			p=(p+1)%26;	
		}
		if(s[p][0]==" ")
		{
			s[p][0]=w;
			s[p][1]=m;
		}
	}
}

void table :: insertrep(string w,string m)
{
	int index=hashfunc(w);
	//cout<<index;
	int t=hashfunc(s[index][0]);
	
	if(s[index][0]==" ")
	{
		insert(w,m);
	}
	else if(s[index][0]>w)
	{	
		string tw,tm;
		tw=s[index][0];
		tm=s[index][1];
		
		s[index][0]=w;
		s[index][1]=m;
		
		insert(tw,tm);
	}
	else
	{
		insert(w,m);
	}
}

int table :: find(string w)
{
	int index=hashfunc(w);
	//cout<<index;
	if(s[index][0]==w)
	{
		cout<<"Found!!!\n"<<s[index][0]<<":"<<s[index][1];
		return index;
	}
	else
	{
		int p=index+1;
		while(s[p][0]!=w && p!=index)
		{
			p=(p+1)%26;	
		}
		if(s[p][0]==w)
		{
			cout<<"Found!!!\n"<<s[p][0]<<":"<<s[p][1];
			return p;
		}
		
	}
	cout<<"NOT FOUND!!!";
}

void table:: display()
{
	for(int i=0;i<26;i++)
	{
		if(s[i][0]==" ")
		continue;
		else
		{
			cout<<i<<" "<<s[i][0]<<" : "<<s[i][1]<<endl;
		}
	}
}

void table :: del(string w)
{
	int key=find(w);
	
	s[key][0]=" ";
	s[key][1]=" ";
	cout<<"\nDeleted!!!";
}
int main()
{
	table T;
	char ch,chh;
	int c,d;
	string a,k;
	int count=0;
	cout<<"1.With replacement/2.Without replacement insertion?";
	int op;
	cin>>op;
	
	do{
		cout<<"\n1.Insert\n2.Find\n3.delete\n4.display\n";
		cin>>c;
		
		switch(c)
		{
			
			case 1:
				if(count<=26)
				{
					cout<<"Enter word :";
					cin>>k;
					cout<<"Enter meaning :";
					cin>>a;
					if(op==2)
						T.insert(k,a);
					else
						T.insertrep(k,a);
					count++;
				}
				else
				{
					cout<<"Table full!";
				}
				break;
			
			case 2:cout<<"word to find?";
				cin>>k;
				T.find(k);
				break;
			
			case 3:cout<<"word to delete?";
				cin>>k;
				T.del(k);
				break;
				
			case 4:T.display();
				break;
			
		}
		cout<<"\nContinue? ";
		cin>>ch;
	}while(ch=='y');
}
