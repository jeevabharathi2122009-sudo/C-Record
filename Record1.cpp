#include<iostream>
using namespace std;
class Student
{
	private:
		int rollno;
		string name;
	public:
		//constructor
		Student(int r,string n)
		{
			rollno=r;
			name=n;
			cout<<"Student Object created"<<endl;
		}
		//Member function
		void display()
		{
			cout<<"Roll Number:"<<rollno<<endl;
			cout<<"Name:"<<name<<endl;
		}
		//Destructor
		~Student()
		{
			cout<<"Student Object Destroyed"<<endl;
		}
};
int main()
{
	Student s1(101,"Arun");
	s1.display();
	return 0;
}
