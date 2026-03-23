// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>

class TestString
{
    char *str;
    int length;
    
    public:
    
    TestString() {}
    
    TestString(char *s1)
    {
        length = strlen(s1);
        str = new char[length+1];
        strcpy(s1,str);
    }
    
    TestString(const TestString& other)
    {
        length = other.length;
        delete str;
        str = new char[other.length+1];
        strcpy(other.str,str);
    }
    
    TestString& operator=(const TestString &other)
    {
        length = other.length;
        delete str;
        str = new char[other.length+1];
        strcpy(other.str,str);
        return *this;
    }
    
    TestString(const TestString&& other)
    {
        length = other.length;
        delete str;
        str = new char[other.length+1];
        strcpy(other.str,str);
        delete other.str;
    }
    
    TestString& operator=(const TestString &&other)
    {
        length = other.length;
        delete str;
        str = new char[other.length+1];
        strcpy(other.str,str);
        delete other.str;
        return *this;
    }
    
    TestString& operator+(const TestString &other1)
    {
        length = length + other1.length;
        delete str;
        temp = new char[length+1];
        //strcpy(other.str,str); //string append function
        return *this;
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

TestString t4 = std::move(t3);

std::cout<<t3; // This should print HelloWorld

TestString t6 =1; 

return 0;

}