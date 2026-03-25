// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class SharedPointer
{
	T* ptr;
	int* count;
	
	public:
	
	SharedPointer() : ptr(nullptr), count(nullptr) {}
	
	SharedPointer(T data)
	{
		ptr = new T(data);
		count = new int(1);
	}
	
	SharedPointer(T* otherptr)
	{
		ptr = otherptr;
		count = new int(1);
	}
	
	SharedPointer(const SharedPointer& other)
	{
		ptr = other.ptr;
		count = other.count;
		
		if(count)
			(*count)++;
	}
	
	SharedPointer& operator=(const SharedPointer& other)
	{
		if(this != &other)
		{
			release();
			
			ptr = other.ptr;
			count = other.count;
			
			if(count)
			    (*count)++;
		}
		
		return *this;
	}
	
	SharedPointer(SharedPointer&& other)
	{
	    ptr = other.ptr;
	    count = other.count;
	    
	    other.count = nullptr;
	    other.ptr = nullptr;
	}
	
	SharedPointer& operator=(SharedPointer&& other)
	{
	    if(this != &other)
	    {
	        release();
    	    ptr = other.ptr;
    	    count = other.count;
    	    
    	    other.count = nullptr;
    	    other.ptr = nullptr;
	    }
	    
	    return *this;
	}
	
	auto use_count() {
		
		if(count)
			return *count;
		
		return 0;
	}
	
	T& operator*()
	{
	    
	   return *ptr;
	}
	
	T* operator->()
	{
	    
	   return ptr;
	}
	
	T* get()
	{
		return ptr;
	}
	
	void reset() {
		
		release();
		ptr =  nullptr;
		count = nullptr;	
	}
	
	friend ostream& operator<<(ostream& os, const SharedPointer& other)
	{
	    if(other.ptr)
	        os<<other.ptr<<" "<<other.count;
	        
	    return os;
	}
	
	
	void release()
	{
	    if(count)
	    {
	        (*count)--;
	        
	        if(*count == 0 && ptr)
	        {
	            delete ptr;
	            delete count;
	        }
	    }
	}
	
	~SharedPointer() {
	    release();
	}
};

int main()
{
	SharedPointer<int> p4(100);
	SharedPointer<int> p1(new int(100));
	cout << p1.use_count()<<endl;  // 1

	SharedPointer<int> p2 = p1;
	cout << p1.use_count()<<endl;  // 2

	{
		SharedPointer<int> p3 = p2;
		cout << p1.use_count()<<endl;  // 3
	}

	cout << p1.use_count()<<endl;  // 2

	*p1 = 200;
	cout << *p2<<endl;  // 200
	
	SharedPointer<int> p5(new int(10));
	p5 = p5;

	cout << p5.use_count() << endl;  // should be 1
	cout << *p5 << endl;             // should be 10

    SharedPointer<int> p6(new int(20));
    p6 = std::move(p6);
    
    cout << p6.use_count() << endl;  // should be 1 (or safe state)

    SharedPointer<int> p7(new int(30));
    SharedPointer<int> p8(std::move(p7));
    
    cout << p8.use_count() << endl;  // 1
    cout << p7.use_count() << endl;  // 0


	return 0;
}
