#include<iostream>
using namespace std;

class tbt;
class node
{
	int data,lb,rb;
	node *lc,*rc;
	
public:
	node(int d)
	{
		data=d;
		lb=rb=0;
		lc=rc=NULL;
	}
	friend class tbt;
};

class tbt
{
	node *root;
public:
	tbt()
	{
		root=new node(-1);
		root->lb=0;
		root->rb=1;
		root->lc=root->rc=root;
	}
	void insert()
	{
		int d;
		cout<<"ENter data";
		cin>>d;
		create(d);
	}
	void create(int d)
	{
		node *p,*curr;
		p=new node(d);
		bool norightchild,noleftchild;
		
		if(root->lc==root && root->rc==root )
		{
			p->lc=root->lc;
			p->lb=0;
			root->lc=p;
			root->lb=1;
			p->rc=root;
			p->rb=0;	
		}
		else
		{
			curr=root->lc;
			while(1)
			{
				if(curr->data > p->data)
				{
					if(curr->lb==0)
					{
						noleftchild=true;
						norightchild=false;
						break;
					}
					else
					{
						curr=curr->lc;
					}
				}
				else if(curr->data < p->data)
				{
					if(curr->rb==0)
					{
						noleftchild=false;
						norightchild=true;
						break;
					}
					else
					{
						curr=curr->rc;
					}
				}
				else
				{
					cout<<"\nDuplicate entry";
					break;
				}
			}
			
			if(noleftchild==true)
			{
				p->lc=curr->lc;
				p->lb=0;
				curr->lc=p;
				curr->lb=1;
				p->rc=curr;
				p->rb=0;
			}
			else if(norightchild==true)
			{
				p->rc=curr->rc;
				p->rb=0;
				curr->rc=p;
				curr->rb=1;
				p->lc=curr;
				p->lb=0;
			}
			else 
			{
				cout<<"\nfail";
				return;
			}
		}
		cout<<"\nNode added";
	}
	
	void inorder()
	{
		node *t;
		t=root->lc;
		cout<<"\n";
		while(t->lb==1)
		{
			t=t->lc;		
		}
		while(t!=root)
		{
			cout<<" "<<t->data;
			t=in_succ(t);
		}
	}
	
	node* in_succ(node *p)
	{
		if(p->rb==1)
		{
			p=p->rc;
			while(p->lb==1)
			{
				p=p->lc;
			}
			return p;
		}
		else
			return p->rc;
	}
	
	void preorder()
	{
		node *t;
		t=root->lc;
		cout<<"\n";
		
		while(t!=root)
		{
			cout<<" "<<t->data;
			t=pre_succ(t);
		}
	}
	
	node* pre_succ(node *p)
	{
		if(p->lb==1)
			return p->lc;
		if(p->rb==1)
			return p->rc;
			
		while(p->rb==0)
			p=p->rc;
		return p->rc;
	}
};

int main()
{
	int flag=0,c;
 	tbt t;
	while(flag==0)
	{
		cout<<"\n1.insert\n2.inorder\n3.preorder\n";
		cin>>c;
		
		switch(c)
		{
			case 1:
			t.insert();
			break;
			
			case 2:
			t.inorder();
			break;
			
			case 3:
			t.preorder();
			break;
			
			default:flag=1;
		}
	}
}
