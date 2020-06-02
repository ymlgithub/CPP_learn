/**
 * g++ p23_p26.cpp -o output/app && output/app
 */

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

int foo() { return 5; }

void process(int &i) { cout << "process(int& i)" << endl; }
void process(int &&i) { cout << "process(int&& i)" << endl; }
void forward(int &&i)
{
    cout << "void forward(int&& i)" << endl;
    process(i); // process(int& i) ： 右值变成了左值！
}

class MyString
{
private:
    char *_data;
    size_t _len;

public:
    MyString()
    {
        _data = NULL;
        _len = 0;
    };
    MyString(const MyString &str)
    {
        if (str._data)
        {
            _data = new char[strlen(str._data) + 1];
            strcpy(_data, str._data);
        }
        else
        {
            _data = NULL;
        }
        _len = str._len;
        cout << "MyString::copy" << endl;
    } //copy
    MyString(MyString &&str) noexcept : _data(str._data), _len(str._len)
    {
        //move；接收右值，要确保右值不再被使用；函数确保不抛出异常，加noexpect修饰符
        //怎么把右值move过来？
        str._data = nullptr; // 重要！避免右值（str）析构时delete _data指针！
        str._len = 0;
        cout << "MyString::move" << endl;
    }

    MyString &operator=(MyString &str)
    {
        cout << "MyString& operator=(MyString& str)" << endl;
        if (&str == this)
        {
            return *this;
        }
        if (str._data)
        {
            _data = new char[strlen(str._data) + 1];
            strcpy(_data, str._data);
        }
        else
        {
            _data = NULL;
        }
        _len = str._len;
    }

    MyString &operator=(MyString &&str)
    {
        cout << "MyString& operator=(MyString&& str)" << endl;
        if (&str == this)
        {
            return *this;
        }
        if (str._data)
        {
            _data = str._data;
            str._data = NULL;
        }
        else
        {
            _data = NULL;
        }
        _len = str._len;
    }

    virtual ~MyString()
    {
        if (_data)
        {
            delete _data;
        }
    }

    void fun() { cout << "..." << endl; }
};

int main()
{
    // 右值引用，避免不必要的copy
    int a = 4;
    int b = 9;
    a = b;
    b = a;
    a = a + b;

    // 左值：变量；右值：表达式，常量，临时对象

    // a + b = 42; // error: lvalue required as left operand of assignment
    // 以下右值表达式可以编译通过
    string s1("hello");
    string s2("world");
    s1 + s2 = s2;
    string() = "???";
    cout << s1 << "\n"
         << s2 << endl;
    int x = foo();
    // int* p = &foo();//对右值取地址；error: lvalue required as unary ‘&’ operand

    //vector::insert(&&x);

    // move语义：对容器性能有较大提升
    MyString m;
    MyString m1(m);             //拷贝构造MyString::copy
    MyString m2(std::move(m1)); //move构造MyString::move

    int c = 0;
    process(c);       //process(int& i)
    process(1);       //process(int&& i)
    process(move(c)); //process(int&& i)

    forward(1); // void forward(int&& i)
    // forward(c);// error: no matching function for call to ‘forward(int&)’

    vector<MyString> mstrs;
    // *3
    mstrs.push_back(MyString());
    mstrs.push_back(MyString());
    cout << "-------------" << endl;
    // *4
    mstrs.emplace_back(MyString());
    mstrs.emplace_back(MyString());
    cout << "-------------" << endl;
    MyString ms1;
    MyString ms2 = MyString(); //没输出
    cout << "+++" << endl;
    ms1 = ms2; //MyString& operator=(MyString& str)
    cout << "***" << endl;
    MyString ms3(ms1);               //MyString::copy
    MyString ms4 = move(MyString()); //MyString::move
    MyString ms5 = move(ms3);        //MyString::move
    ms5 = move(ms4);                 //MyString& operator=(MyString&& str)
    ms5 = MyString();                //MyString& operator=(MyString&& str)

    return 0;
}