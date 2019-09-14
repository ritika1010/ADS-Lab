/*To create ADT that implements the SET concept.
14-12-2018
a)Add (new Element) -Place a value into the set
b)Remove (element) Remove the value
c) Contains (element) Return true if element is in collection
d)Size () Return number of values in collection ,Iterator () Return an
iterator used to loop over collection
e)Intersection of two sets,
f)Union of two sets,
g) Difference between two sets,
h)Subset
*/

#include<iostream>
using namespace std;
class set;
class node
{
	int data;
	node *next;
public:
	node(int d)
	{
		data=d;
		next=NULL;
	}
	friend class set;
};

class set
{
	int size;
	node *head;
	
public:
	set()
	{
		head=NULL;
	}
	
	void add(int d)
	{
		if(head==NULL)
		{
			head=new node(d);
			size++;
		}
		else
		{
			node *p;
			p=head;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			p->next=new node(d);
			size++;
		}
		cout<<"\nAdded";
	}
	
	void remove(int d)
	{
			node *p,*q;
		if(head->data==d)
		{
			p=head;
			head=p->next;
			delete p;
			size--;
		}
		else
		{
			p=head;
			while(p->data!=d)
			{
				q=p;
				p=p->next;
				if(p==NULL)
				{
					cout<<"\nNOT FOUND";
					return;
				}
			
			}
			if(p->data==d)
			{
				q->next=p->next;
				delete p;
				size--;
			}
			
			
		}
		cout<<"\nremoved";
	}
	
	void display()
	{
		node *p;
			p=head;
			cout<<" { ";
			while(p->next!=NULL)
			{
				cout<<p->data<<" , ";
				p=p->next;
			}
			cout<<p->data<<" } ";
	}
	
	bool contains(int d)
	{
		node *p;
		p=head;
			if(p==NULL)
				return false;
			while(p->data!=d)
			{
				p=p->next;
				
				if(p==NULL)
				{
					cout<<"q";
					return false;
				}
			
			}
			if(p->data==d)
			{
				return true;	
			}
			
	}
	
	void intersection(set s1,set s2)
	{
		set s3;
		
		node *p1,*p2;
		bool poa,poa3;
		p1=s1.head;
		p2=s2.head;
		
		while(p1!=NULL)
		{
			poa=s2.contains(p1->data);
			poa3=s3.contains(p1->data);
			if(poa && poa3==false)
			{
				s3.add(p1->data);
			}
			
			p1=p1->next;
		}
		
		
		
		s3.display();
		
	}
	
	void unions(set s1,set s2)
	{
		set s3;
		
		node *p1,*p2;
		bool poa,poa3;
		p1=s1.head;
		p2=s2.head;
		
		while(p1!=NULL)
		{
			s3.add(p1->data);
			p1=p1->next;
		}
		
		while(p2!=NULL)
		{
			poa3=s3.contains(p2->data);
			if(poa3==false)
			{
				s3.add(p2->data);
			}
			
			p2=p2->next;
		}
		
		s3.display();
		
	}
	
	void diff(set s1,set s2)
	{
		
		set s3;
		
		node *p1,*p2;
		bool poa,poa3;
		
		p1=s1.head;
		p2=s2.head;
		
		while(p1!=NULL)
		{
			poa=s2.contains(p1->data);
			//poa3=s3.contains(p1->data);
			if(poa==false)
			{
				s3.add(p1->data);
			}
			
			p1=p1->next;
		}
		
		
		
		s3.display();
	}
	
};

int main()
{
	set s1,s2;
	int c,chh,flag=0,d;
	bool ap;
	char ch,cs;
	do{
		cout<<"set1/set2\n";
		cin>>chh;
		switch(chh)
		{
			case 1:do
				{

					cout<<"\n1.add\n2.remove\n3.display\n4.Conatins\n5.int\n6.union\n7.s1-s2";
					cin>>c;
					switch(c)
					{
						case 1:cout<<"\nEnter data:";
						cin>>d;
						s1.add(d);
						break;
			
						case 2:cout<<"\nEnter data to remove:";
						cin>>d;
						s1.remove(d);
						break;
			
						case 3:
						s1.display();
						break;
			
						case 4:cout<<"\nEnter data:";
						cin>>d;
						ap=s1.contains(d);
						cout<<ap;
						if(ap)
						{
							cout<"\npresent";
						}
						else
						{
							cout<<"\nabsent";
						}
						break;
			
						case 5:
						s1.intersection(s1,s2);
						break;
						
						case 6:
						s1.unions(s1,s2);
						break;
						
						case 7:
						s1.diff(s1,s2);
						break;
			
			
						default: flag=1;
						break;
			
					}
					cout<<"continue in same set";
					cin>>cs;
				}while(cs=='y');
				break;
		
			case 2:do
				{

					cout<<"\n1.add\n2.remove\n3.display\n4.Conatins\n5.int\n6.union\n7.s2-s1";
					cin>>c;
					switch(c)
					{
						case 1:cout<<"\nEnter data:";
						cin>>d;
						s2.add(d);
						break;
			
						case 2:cout<<"\nEnter data to remove:";
						cin>>d;
						s2.remove(d);
						break;
			
						case 3:
						s2.display();
						break;
			
						case 4:cout<<"\nEnter data:";
						cin>>d;
						ap=s2.contains(d);
						cout<<ap;
						if(ap)
						{
							cout<"\npresent";
						}
						else
						{
							cout<<"\nabsent";
						}
						break;
			
						case 5:
						s2.intersection(s1,s2);
						break;
			
						case 6:
						s2.unions(s1,s2);
						break;
						
						case 7:
						s2.unions(s2,s1);
						break;
			
						default: flag=1;
						break;
			
					}
					cout<<"continue in same set";
					cin>>cs;
				}while(cs=='y');
				break;
			
		}

		cout<<"\ncontinue";
		cin>>ch;
	}while(ch=='y');
}
