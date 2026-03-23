// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class TestString
{
    char *str;
    int length;
    
    public:
    
    TestString() : length(0), str(nullptr) {}
    
    ~TestString() {
         length = 0;
         delete[] str;
    }
     
    TestString(const char *s1)
    {
        length = strlen(s1);
        str = new char[length];
        strcpy(str,s1);
    }
    
    TestString(int val)
    {
        length = 1;
        str = new char[length];
    }
    
    TestString(const TestString& other)
    {
        length = other.length;
        str = new char[length];
        strcpy(str,other.str);
    }
    
    TestString& operator=(const TestString &other)
    {
        if(this != &other)
        {
            delete[] str;
            length = other.length;
            str = new char[length];
            strcpy(str,other.str);
        }
        return *this;
    }
    
    TestString(TestString&& other)
    {
        length = other.length;
        str = new char[length];
        strcpy(str,other.str);
        
        other.length = 0;
        other.str = nullptr;
    }
    
    TestString& operator=(TestString &&other)
    {
        if(this != &other)
        {   
            delete[] str;
            length = other.length;
            str = new char[length];
            strcpy(str,other.str);
        }
        
        other.length = 0;
        other.str = nullptr;
        
        return *this;
    }
    
    TestString operator+(const TestString& other1)
    {
        TestString ts;
        ts.length = length + other1.length - 1;
        ts.str = new char[length];
        strcpy(ts.str,str);
        strcat(ts.str,other1.str);
        return ts;
    }
    
friend ostream& operator<<(ostream &os, const TestString& other)
    {
        if(other.length > 0 && other.str)
        {
            os<<(other.str)<<" length = "<<other.length<<endl;
        }
        
        return os;
    }
    
};

/*Create a user defined String class named TestString
Dont use std::string in your code
*/
 

int main()

{

TestString t;

TestString t1("Hello");

TestString t2 = t1;

TestString t3 = t1 + "World";

std::cout<<t3; // This should print HelloWorld

TestString t4 = std::move(t3);

TestString t6 =1; 

return 0;

}