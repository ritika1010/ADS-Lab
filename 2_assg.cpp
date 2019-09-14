#include <iostream>
#include <cstring>
using namespace std;

class node
{
public:
	string key,value;
	node *lc,*rc;
	node()
	{
		lc=NULL;
		rc=NULL;
	}

};

class dict
{
	node *root;
	public:
	dict()
	{
		root=NULL;
	}
	void insert()
	{
		string st1,st2;
		cout<<"Enter word";
		cin>>st1;
		cout<<"Enter meaning";
		cin>>st2;
		root=insert_tree(root,st1,st2);
	}
	
	node* insert_tree(node *p,string s1,string s2)
	{
		node *temp;
		if(p==NULL)
		{
			temp=new node();
			temp->key=s1;
			temp->value=s2;
			return temp;
		}
		
		if(p->key > s1)
		{
			p->lc=insert_tree(p->lc,s1,s2);
			return p;
		}
		else if(p->key < s1)
		{
			p->rc=insert_tree(p->rc,s1,s2);
			return p;
		}
		else 
		{
			cout<<"Duplicate entry";
			return p;
		}
	}
	
	void inorder()
	{
		inordert(root);
	}

	void inordert(node *t)
	{
		if(t!=NULL)
		{
			inordert(t->lc);
			cout<<t->key<<" : "<<t->value<<"\n";
			inordert(t->rc);
		}
	}
	
	void decs()
	{ 
		decst(root);
	}

	void decst(node *t)
	{
		if(t!=NULL)
		{
			decst(t->rc);
			cout<<t->key<<" : "<<t->value<<"\n";
			decst(t->lc);
		}
         }

	void update()
	{
		string st1,st2;
		cout<<"Enter word to update meaning of :";
		cin>>st1;
		update_tree(root,st1);
	}

	void update_tree(node *t,string st1)
	{
		int flag=0;
		while(t!=NULL)
		{
			if(t->key > st1)
			{
				t=t->lc;
			}
			else if(t->key < st1)
			{
				t=t->rc;
			}
			else
			{
				flag=1;
				cout<<"word found\n";
				break;
			
			}
		}
		
		if(flag==1)
		{
			string st2;
			cout<<"Meaning before updating\n";
			cout<<t->key<<" : "<<t->value<<"\n";
			cout<<"new meaning?";
			cin>>st2;
			t->value=st2;
			cout<<"Meaning afterting\n";
			cout<<t->key<<" : "<<t->value<<"\n";
		}
		else
			cout<<"no word found";
	}

	void search()
	{
		string st1,st2;
		cout<<"Enter word to search meaning of :";
		cin>>st1;
		search_tree(root,st1);
	}

	void search_tree(node *t,string st1)
	{
		int flag=0,count=0;;
		while(t!=NULL)
		{
			if(t->key > st1)
			{
				t=t->lc;
			}
			else if(t->key < st1)
			{
				t=t->rc;
			}
			else
			{
				flag=1;
				cout<<"word found\n";
				break;
			
			}
			count++;
		}
		
		if(flag==1)
			cout<<t->key<<" : "<<t->value<<" after comparisons "<<count+1<<"\n";
		else
			cout<<"\nno word found\n";
	}
	
	void delete_word()
	{
		string st1;
		cout<<"Enter word to delete :";
		cin>>st1;
		root=delete_tree(root,st1);
		cout<<"\n"<<st1<<" was deleted";
	}

	node* delete_tree(node* t,string st)
	{ 		
		node *temp;
		

		if(t==NULL)
		{
			cout<< "data not found";
			return t;
		}
		if(t->key > st)
		{
			t->lc=delete_tree(t->lc,st);
			return t;
		}
		if(t->key < st)
		{
			t->rc=delete_tree(t->rc,st);
			return t;
		}
		//-------found---------------
		if(t->lc==NULL && t->rc==NULL)
		{
			temp=t;
			delete temp;
			return NULL;
		}
		
		if(t->lc==NULL)
		{
			temp=t;
			t=t->rc;
			return temp;
		}
		
		if(t->rc==NULL)
		{
			temp=t;
			t=t->lc;
			return temp;
		}
		
		//-----both null
		
		temp=t->rc;
		while(temp->lc!=NULL)
		{
			temp=temp->lc;
		}
		t->key=temp->key;
		t->value=temp->value;
		t->rc=delete_tree(t->rc,temp->key);
		return t;
		
	}
};


int main()
{
	dict d,d2;
	int ch;
	char c,chh;
	do{
		cout<<"\n1.insert words to dictionary\n2.display in ascending order\n3.update\n4.search\n5.assign to new tree\n6.Delete keyword\n7.descending\n";
		cin>>ch;
		switch(ch)
		{
			case 1:do{
					d.insert();
					cout<<"continue inserting?";
					cin>>c;
					}while(c=='y');
				break;

			case 2:d.inorder();
				break;

			case 3:d.update();
				break;

			case 4:d.search();
				break;

			case 5:d2=d;
				d2.inorder();
				break;
			case 6:d.delete_word();
				break;
				
			case 7:d.decs();
				break;
		}

		cout<<"\ncontinue";
		cin>>chh;
	}while(chh=='y');
}

