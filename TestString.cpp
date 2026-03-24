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
        str = new char[length+1];
        strcpy(str,s1);
    }
    
    TestString(char c)
    {
        length = 1;
        str = new char[length+1];
        str[0] = c;
        str[1] = '\0';
    }
    
    TestString(int val)
    {
        length = val;
        str = new char[length+1];
        str[0] = '\0';
    }
    
    TestString(const TestString& other)
    {
        length = other.length;
        
        if(other.str)
        {
            str = new char[length+1];
            strcpy(str,other.str);
        }
        else
        {
            length = 0;
            str = nullptr;
        }
    }
    
    TestString& operator=(const TestString &other)
    {
        if(this != &other)
        {
            delete[] str;
            length = other.length;
            
            if(other.str)
            {
                str = new char[length+1];
                strcpy(str,other.str);
            }
            else
            {
                length = 0;
                str = nullptr;
            }
        }
        return *this;
    }
    
    TestString(TestString&& other)
    {
        length = other.length;
        str = other.str;
                
        other.length = 0;
        other.str = nullptr;
    }
    
    TestString& operator=(TestString &&other)
    {
        if(this != &other)
        {   
            delete[] str;
            length = other.length;
            str = other.str;
        }
        
        other.length = 0;
        other.str = nullptr;
        
        return *this;
    }
    
    TestString operator+(const TestString& other1)
    {
        TestString ts;
        ts.length = length + other1.length;
        ts.str = new char[ts.length+1];
        
        if(str)
            strcpy(ts.str,str);
        else
            ts.str[0] = '\0';
            
        if(other1.str)
            strcat(ts.str,other1.str);
            
        return ts;
    }
   
    TestString operator+=(const TestString& other1)
    {
        TestString ts;
        ts.length = length + other1.length;
        ts.str = new char[ts.length+1];
        
        if(str)
            strcpy(ts.str,str);
        else
            ts.str[0] = '\0';
            
        delete[] str;
        str = new char[ts.length+1];
        length = ts.length;
        strcpy(str,ts.str);
            
        if(other1.str)
            strcat(str,other1.str);
          
        return str;
    }
    
    bool operator==(const TestString& other1)
    {
        bool isEqual = false;
        
        if(length != other1.length)
            return isEqual;
            
        if(strcmp(str,other1.str) == 0)
            isEqual = true;
        
        return isEqual;
    }
    
    char& operator[](int index)
    {
        return str[index];
    }
     
    int size()
    {
        return length;
    }
    
friend ostream& operator<<(ostream &os, const TestString& other)
    {
        if(other.str)
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
    TestString s1("Hello");
    TestString s2("World");

    TestString s3 = s1 + s2;
    cout << s3 << endl;   // HelloWorld

    s1 += s2;
    cout << s1 << endl;   // HelloWorld

    TestString s4('A');
    cout << s4 << endl;   // A

    if(s1 == s3)
        cout << "Equal\n";

    s1[0] = 'h';
    cout << s1 << endl;   // helloWorld

    cout << s1.size() << endl;

    TestString s5 = std::move(s1);
    
    cout<<s1<<endl;
    
    cout<<s5<<endl;

    return 0;

}