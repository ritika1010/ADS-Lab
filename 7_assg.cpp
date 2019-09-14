#include <iostream>
using namespace std;
#define max 30
class node
{
public:
	string key,attribute;
	int chain;
	
	node()
	{
		key=" ";
		attribute=" ";
		chain=-1;
	}	
	
	
};

class table
{

	int n;
public:
	node *s[30];
	void create(int d);
	void insert(string k,string a);
	void insertrep(string k,string a);
	int find(string k);
	void del(string k);
	void display();
	int hashfunc(string l);
	
};

void table:: create(int d)
{
	n=d;
	for(int i=0;i<n;i++)
	{
		s[i]=new node();
	}
}

int table:: hashfunc(string l)
{
	int len=l.length()%n;
	return len;
}
void table:: insert(string k,string a)
{
	int index;
	index=hashfunc(k);
	cout<<index;
	if(s[index]->key==" ")
	{
		s[index]->key=k;
		s[index]->attribute=a;
	}
	else 
	{
		if(s[index]->chain==-1)
		{
			int temp=index;
			int p=index;
			while(s[p]->key!=" " && p!=index-1)
			{
				p=(p+1)%n;
			}
			s[p]->key=k;
			s[p]->attribute=a;
			
			s[temp]->chain=p;	//**
		}
		else
		{
			int p,q;
			q=s[index]->chain;
			p=index;
			
			while( q!=-1 && s[p]->key!=" ")
			{
				p=q;
				q=s[p]->chain;
			}
			int temp=p;
			while(s[p]->key!=" " && p!=index)
			{
				p=(p+1)%n;
			}
			s[p]->key=k;
			s[p]->attribute=a;
			
			s[temp]->chain=p;	//**
		}
	}
}

void table:: insertrep(string k,string a)
{
	int index;
	index=hashfunc(k);
	cout<<index;
	if(s[index]->key==" ")
	{
		s[index]->key=k;
		s[index]->attribute=a;
	}
	else 
	{			
		if((hashfunc(s[index]->key))==index)
		{
			insert(k,a);
		}
		else
		{
			string tk,ta;
			int tc,q;
			tk=s[index]->key;
			ta=s[index]->attribute;
			tc=s[index]->chain;
			s[index]->key=k;
			s[index]->attribute=a;
			s[index]->chain=-1;
			
			int temp=index;
			int p=index;
			while(s[p]->key!=" " && p!=index-1)
			{
				p=(p+1)%n;
			}
			s[p]->key=tk;
			s[p]->attribute=ta;
			s[p]->chain=tc;
			
			int tt=hashfunc(tk);
			if(s[tt]->chain!=-1)
			{
				int i=0;
				while(s[i]->chain!=index)
				{
					i++;
				}
				s[i]->chain=p;
			}
			else
			{
				while(s[tt]->chain!=-1)
				{
					q=tt;
					tt=s[tt]->chain;
				}
				s[q]->chain=p;
			}
		}
			
	}	
}

int table:: find(string k)
{
	int index=hashfunc(k);
	
	
	if(s[index]->key==k)
	{
		cout<<"\nFound!!!\n"<<s[index]->key<<" "<<s[index]->attribute;
		return index;
	}
	else
	{
		if(s[index]->chain==-1)
		{
			int temp=index;
			int p=index+1;
			while(s[p]->key!=k && p!=index)
			{
				p=(p+1)%n;
			}
			if(s[p]->key==k)
			{
				cout<<"\nFound!!!\n"<<s[p]->key<<" "<<s[p]->attribute;
				return p;
			}
		}
		else
		{
			int p,q;
			q=s[index]->chain;
			p=index;
			
			while( q!=-1 && s[p]->key!=k)
			{
				p=q;
				q=s[p]->chain;
			}
			if(s[p]->key==k)
			{
				cout<<"\nFound!!!\n"<<s[p]->key<<" "<<s[p]->attribute;
				return p;
			}
			int temp=p;
			p=p+1;
			while(s[p]->key!=k && p!=index)
			{
				p=(p+1)%n;
			}
			if(s[p]->key==k)
			{
				cout<<"\nFound!!!\n"<<s[p]->key<<" "<<s[p]->attribute;
				return p;
			}
		}	
	}
	cout<<"Not found";
	return -1;
}

void table:: del(string k)
{

	int flag=find(k);
	if(flag==-1)
		return;
	else
	{
		cout<<"\ndeleted!!!\n";
		s[flag]->key=" ";
		s[flag]->attribute=" ";
		s[flag]->chain=-1;
		return;
	}

	int i=0;
	while(s[i]->chain!=flag)
	{
		i++;
	}
	s[i]->chain=-1;
	
	
}

void table:: display()
{
	for(int i=0;i<n;i++)
	{	if(s[i]->key==" ")
		continue;
		else
		{
			cout<<s[i]->key<<" "<<s[i]->attribute<<" "<<s[i]->chain<<endl;
		}
	}
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
		cout<<"\n1.Create\n2.Insert entry\n3.Find\n4.delete\n5.display\n";
		cin>>c;
		
		switch(c)
		{
			case 1: cout<<"No.of entries? ";
				cin>>d;
				T.create(d);
				break;
			
			case 2:
				if(count<=d)
				{
					cout<<"Enter symbol name: ";
					cin>>k;
					cout<<"Enter attribute :";
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
			
			case 3:cout<<"ENtry to find?";
				cin>>k;
				T.find(k);
				break;
			
			case 4:cout<<"ENtry to delete?";
				cin>>k;
				T.del(k);
				break;
				
			case 5:T.display();
				break;
			
		}
		cout<<"\nContinue? ";
		cin>>ch;
	}while(ch=='y');
}
