#include<iostream>
#include<memory>
using namespace std;
class Resource
{
    public:
        Resource()
        {
            cout<<"Resource acquired"<<endl;
        }
        ~Resource()
        {
            cout<<"Resource released"<<endl;
        }
        void use()
        {
            cout<<"Resource is being used"<<endl;
        }
};
//Memory Smart Pointer using RAII
class MySmartPointer
{
    private:
        Resource *ptr;
    public:
        MySmartPointer(Resource *p)
        {
            ptr=p;
        }
        ~MySmartPointer()
        {
            delete ptr;
            cout<<"Manual Smart Pointer destroyed"<<endl;
        }
        Resource *operator->()
        {
            return ptr;
        }
        //Disable copying to avoid double deletion
        MySmartPointer(const MySmartPointer &)=delete;
        MySmartPointer & operator=(const MySmartPointer&)=delete;
};
int main()
{
    cout<<"-----Manual RAII smart pointer ------"<<endl;
    {
        MySmartPointer smartPtr(new Resource());
        smartPtr->use();
    }
    cout<<"\n------Unique pointer------"<<endl;
    {
        unique_ptr<Resource> uniquePtr=make_unique<Resource>();
        uniquePtr->use();
    }
    cout<<"\n-----Shared Pointer------"<<endl;
    {
        shared_ptr<Resource> sharedPtr1=make_shared<Resource>();
        shared_ptr<Resource> sharedPtr2=sharedPtr1;
        sharedPtr2->use();
        cout<<"Shared Pointer Count:"<<sharedPtr1.use_count()<<endl;
    }
    cout<<"\nProgram Completed Successfully"<<endl;
    return 0;
}
