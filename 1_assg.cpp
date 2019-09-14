#include<iostream>
using namespace std;
class tree;
class node
{
	int data;
	node *lc,*rc;
public:
	node(int d)
	{
		data=d;
		lc=NULL;
		rc=NULL;
	}
	friend class tree;
};

class stackofaddr
{
public:
	node *s[30];
	int t;
	stackofaddr()
	{
		t=-1;
	}
	void push(node *p)
	{
		t++;
		s[t]=p;

	}
	node* pop()
	{
		if(empty())
		{
			cout<<"empty";
			return NULL;
		}

		return s[t--];

	}
	int empty()
	{
		if(t==-1)
			return 1;
		else
			return 0;
	}
};
class tree
{
	node *root;
public:
	tree()
	{
		root=NULL;
	}
	void create(int d);
	void insert()
	{
		int d;
		cout<<"\nEnter data";
		cin>>d;
		root=insertT(root,d);
	}
	
	node* insertT(node *p,int d);
	
	void inorder()
	{
		inorderT(root);
	}
	
	void inorderT(node *p);
	
	void preorder()
	{
		preorderT(root);
	}
	
	void preorderT(node *p);
	
	void postorder()
	{
		postorderT(root);
	}
	
	void postorderT(node *p);
	
	void mirror()
	{
		mirrorT(root);
	}
	
	void mirrorT(node *p);		 //in same tree***
	
	void leaf()
	{
		cout<<"Leaf nodes are: "<<leafT(root);
	}
	
	int leafT(node *p);
	
	void interior()
	{
		cout<<"interior nodes are: "<<interiorT(root);
	}
	
	int interiorT(node *p);
	
	void height()
	{
		cout<<"height of tree is: "<<heightT(root);
	}
	
	int heightT(node *p);
	
	void in_nrec()
	{
		in_nrecT(root);
	}
	
	void in_nrecT(node *p);
	
	void pre_nrec()
	{
		pre_nrecT(root);
	}
	
	void pre_nrecT(node *p);
	
	void post_nrec()
	{
		post_nrecT(root);
	}
	
	void post_nrecT(node *p);
	
	
	void erase ()
	{
		eraseT(root);
		delete root;
	}
	
	void eraseT(node *p);
	
	void erase_nrec ()
	{
		erase_nrecT(root);
		delete root;
	}
	
	void erase_nrecT(node *p);
};

void tree:: create(int d)
{
	root=new node(d);
}

node* tree :: insertT(node *p,int d)
{
	int lr;
	node* temp;
	if(p==NULL)
	{
		temp=new node(d);
		return temp;
	}
	else
	{
		cout<<"\nlc/rc (0/1)";
		cin>>lr;
		if(lr==0)
		{
			p->lc=insertT(p->lc,d);
		}
		else
		{
			p->rc=insertT(p->rc,d);
		}
	}
	return p;
}

void tree:: inorderT(node *p)
{
	if(p!=NULL)
	{
		inorderT(p->lc);
		cout<<p->data<<" ";
		inorderT(p->rc);
	}	
}

void tree:: preorderT(node *p)
{
	if(p!=NULL)
	{
		
		cout<<p->data<<" ";
		preorderT(p->lc);
		preorderT(p->rc);
	}	
}

void tree:: postorderT(node *p)
{
	if(p!=NULL)
	{
		postorderT(p->lc);
		postorderT(p->rc);
		cout<<p->data<<" ";
	}	
}

void tree:: mirrorT(node *p)
{
	node *temp;
	if(p!=NULL)
	{
		mirrorT(p->lc);
		mirrorT(p->rc);
		
		temp=p->lc;
		p->lc=p->rc;
		p->rc=temp;
	}
}

/*int tree::leafT(node *p)
{
	static int count=0;
	if(p->lc==NULL && p->rc==NULL)
	{
		cout<<p->data <<" ";
		count++;
		
	}
	else
	{
		leafT(p->lc);
		leafT(p->rc);
	}
	return count;
}*/

int tree:: leafT(node *p)
{
	if(p==NULL)
	return 0;
	else if(p->lc==NULL && p->rc==NULL)
	return 1;
	
	return(leafT(p->lc)+leafT(p->rc));
}


int tree:: interiorT(node *p)
{
	if(p==NULL)
	return 0;
	else if(p->lc==NULL && p->rc==NULL)
	return 0;
	
	return(1+leafT(p->lc)+leafT(p->rc));
}

int tree:: heightT(node *p)
{
	static int h1=0,h2=0;
	
	if(p==NULL)
	return 0;
	if(p->lc==NULL && p->rc==NULL)
	return 0;
	
	h1=heightT(p->lc);
	h2=heightT(p->rc);
	
	if(h1>=h2)
	return (h1+1);
	
	else
	return (h2+1);
}

void tree:: in_nrecT(node *p)
{
	stackofaddr S;
	while(1)
	{
		while(p!=NULL)
		{
			S.push(p);
			p=p->lc;
		}
		if(S.empty())
		{
			return;
		}
		p=S.pop();
		cout<<p->data<<" ";
		p=p->rc;
	}
}

void tree:: pre_nrecT(node *p)
{
	stackofaddr S;
	while(1)
	{
		while(p!=NULL)
		{
			S.push(p);
			cout<<p->data<<" ";
			p=p->lc;
		}
		if(S.empty())
		{
			return;
		}
		p=S.pop();
		p=p->rc;
	}
}


void tree:: post_nrecT(node *p)
{
	stackofaddr S;
	node *temp,*t;
	temp=new node(-1);
	while(1)
	{
		while(p!=NULL)
		{
			S.push(p);
			if(p->rc!=NULL)
			{
				S.push(p->rc);
				S.push(temp);
			}
			p=p->lc;
		}
		if(S.empty())
		{
			if(p!=NULL)
			{
				cout<<p->data;
				return;
			}
			else if(t!=NULL)
			{
				cout<<t->data;
				return;
			}
			else
			{
				return;
			}
		}
		t=S.pop();
		while(t->data!=temp->data  && !S.empty())
		{
			cout<<t->data<<" ";
			t=S.pop();
		}
		if(!S.empty())
		{
			p=S.pop();
		}
		
	}
}

void tree:: eraseT(node *p)
{
	if(p->lc==NULL && p->rc==NULL)
	{
		delete p;
	}
	if(p==NULL)
	{
		delete p;
	}
	if(p->lc!=NULL && p->rc!=NULL)
	{
		eraseT(p->lc);
		eraseT(p->rc);
	}
	else if(p->lc!=NULL && p->rc==NULL)
	{
		eraseT(p->lc);
	}
	else if(p->lc==NULL && p->rc!=NULL)
	{
		eraseT(p->rc);
	}

}

/*void tree:: erase_nrecT(node *p)
{
	stackofaddr S;
	node *t,*temp;
	temp=new node(-1);
	while(1)
	{
		while(p!=NULL)
		{
			S.push(p);
			if(p->rc!=NULL)
			{
				S.push(p->rc);
				S.push(temp);
			}
			p=p->lc;
		}
		if(S.empty())
		{
			if(p!=NULL)
			{
				cout<<p->data;
				delete p;
				return;
			}
			else if(t!=NULL)
			{
				cout<<t->data;
				delete t;
			}
			else
			return;
		}
		t=S.pop();
		if(t->data!=temp->data && !S.empty())
		{
			cout<<t->data;
			delete t;
			t=S.pop();			
		}
		if(!S.empty())
		{
			p=S.pop();
		}
	}
}*/

int main()
{
	tree t;
	int chh,d;
	char ch;
	do{
		cout<<"1.create\n2.insert\n3.inorder\n4.preorder\n5.postorder\n6.mirror\n7.leafnodes\n8.height\n";
		cout<<"9.in-non-rec\n10.pre-non-rec\n11.post-non-rec\n12.interior nodes\n13.erase\n14.erase_nr\n";
		cin>>chh;
		switch(chh)
		{
			case 1:cout<<"Enter Data";
				cin>>d;
				t.create(d);
				break;
				
			case 2:t.insert();
				break;
				
			case 3:t.inorder();
				break;
				
			case 4:t.preorder();
				break;
				
			case 5:t.postorder();
				break;
				
			case 6:t.mirror();
				break;
				
			case 7:t.leaf();
				break;
				
			case 8:t.height();
				break;
				
			case 9:t.in_nrec();
				break;
				
			case 10:t.pre_nrec();
				break;
				
			case 11:t.post_nrec();
				break;
				
			case 12:t.interior();
				break;
				
			case 13:t.erase();
				break;
			
			case 14:t.erase_nrec();
				break;
		}
	cout<<"continue\n";
	cin>>ch;
	}while(ch=='y');
}

