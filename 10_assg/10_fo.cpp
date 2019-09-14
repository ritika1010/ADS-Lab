/*
Department maintains a student information. The file contains roll number,
name, division and address.
Allow user to add, delete information of
student. Display information of particular employee. If record of student
does not exist an appropriate message is displayed. If it is, then the system
displays the student details. Use sequential file to main the data.*/

#include<iostream>
#include<fstream> 
using namespace std;
int n;
class student
{
	public:
	
	char name[10],addr[10];
	int rno,div;
	
};

class fileOP
{
public: 
	student sp,sg;
	
	void create();
	void insert();
	int index_calc(int x);
	int find(int key);
	void del(int key);
	void modify(int key);
	void display();
	
};

int fileOP:: index_calc(int x)
{
	return (x%(10));
}
void fileOP:: create()
{
	cout<<"No. of entries";
	cin>>n;
	
	sp.rno=-1;
	sp.name[0]=' ';
	sp.addr[0]=' ';
	sp.div=-1;
	
	ofstream fout("data.txt");
	for(int i=0;i<10;i++)
	{
		fout.write((char*)&sp, sizeof(sp));
	}
	
	fout.close();
}

void fileOP:: insert()
{
	cout<<"\nEnter name: ";
	cin>>sp.name;
	cout<<"\nEnter rno: ";
	cin>>sp.rno;
	cout<<"\nEnter addr: ";
	cin>>sp.addr;
	cout<<"\nEnter div: ";
	cin>>sp.div;
	
	int index=index_calc(sp.rno);
	
	fstream fp("data.txt");
	
	fp.seekg((sizeof(sg)*index), ios::beg);
	fp.read((char*)&sg,sizeof(sg));
	
	if(sg.rno==-1)
	{
		fp.seekp((sizeof(sp)*index), ios::beg);
		fp.write((char*)&sp,sizeof(sp));
	}
	else
	{
		int temp=index+1;
		
		while(sg.rno!=-1 && temp!=index)
		{ cout<<"n";
			temp=(temp+1)%n;
			fp.seekg((sizeof(sg)*temp), ios::beg);
			fp.read((char*)&sg,sizeof(sg));
		}
		if(sg.rno==-1)
		{
			fp.seekp((sizeof(sp)*temp), ios::beg);
			fp.write((char*)&sp,sizeof(sp));
		}
		else 
		{
			cout<<"Database full";
		}
		
	}
	
	fp.close();
	
}


int fileOP:: find(int key)
{
	
	int index=index_calc(key);
	
	fstream fp("data.txt");
	
	fp.seekg((sizeof(sg)*index), ios::beg);
	fp.read((char*)&sg,sizeof(sg));
	
	if(sg.rno==key)
	{
		cout<<"Found\n";
		cout<<sg.name<<" "<<sg.rno<<" "<<sg.addr<<" "<<sg.div;
		return index;
		
	}
	else
	{
		int temp=index+1;
		
		while(sg.rno!=key && temp!=index)
		{ cout<<"n";
			temp=(temp+1)%n;
			fp.seekg((sizeof(sg)*temp), ios::beg);
			fp.read((char*)&sg,sizeof(sg));
		}
		if(sg.rno==key)
		{
			cout<<"Found\n";
			cout<<sg.name<<" "<<sg.rno<<" "<<sg.addr<<" "<<sg.div;
			return temp;
		}
		else 
		{
			cout<<"Not Found\n";
			return -1;
		}
		
	}
	
	fp.close();
	
}

void fileOP:: display()
{
	fstream fp("data.txt");
	cout<<"\nName Rno Addr Div\n";
		for(int i=0;i<10;i++)
		{ 
			fp.seekg((sizeof(sg)*i), ios::beg);
			fp.read((char*)&sg,sizeof(sg));
			if(sg.rno==-1)
				continue;
			else
			{
				cout<<sg.name<<" "<<sg.rno<<" "<<sg.addr<<" "<<sg.div<<endl;
			}
		}
	fp.close();
}

void fileOP :: del(int key)
{
	int index=find(key);
	if(index==-1)
	{
		cout<<"\ncannot beDeleted\n";
		return;
	}
	fstream fp("data.txt");
	
	fp.seekg((sizeof(sg)*index), ios::beg);
	fp.read((char*)&sg,sizeof(sg));
	
	sg.name[0]=' ';
	sg.addr[1]=' ';
	sg.rno=-1;
	sg.div=-1;
	
	fp.seekp((sizeof(sg)*index), ios::beg);
	fp.write((char*)&sg,sizeof(sg));
	fp.close();
}

void fileOP :: modify(int key)
{
	int index=find(key);
	if(index==-1)
	{
		cout<<"\ncannot beDeleted\n";
		return;
	}
	fstream fp("data.txt");
	
	fp.seekg((sizeof(sg)*index), ios::beg);
	fp.read((char*)&sg,sizeof(sg));
	cout<<"Enter name";
	cin>>sg.name;
	cout<<"Enter addr";
	cin>>sg.addr;
	cout<<"ENter div";
	cin>>sg.div;

	
	fp.seekp((sizeof(sg)*index), ios::beg);
	fp.write((char*)&sg,sizeof(sg));
	fp.close();
}

int main()
{
	fileOP f;
	int c;
	f.create();
	for(int i=0;i<n;i++)
	{
		f.insert();
	}
	cin>>c;
	f.find(c);
	f.display();
	cin>>c;
	f.del(c);
	f.display();
	cin>>c;
	f.modify(c);
	f.display();
}
