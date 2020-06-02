/**
 * Initializer list
 * 
 * g++ p5_p6.cpp -o output/app && output/app
 */

#include <iostream>
#include <vector>
#include <array>
#include <complex>
#include <string>
using namespace std;

template <typename T>
void print(initializer_list<T> vals)
{
    cout << vals.size() << " : ";
    for (auto p = vals.begin(); p != vals.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;
}

void print(initializer_list<int> vals)
{
    cout << vals.size() << " : ";
    for (auto p = vals.begin(); p != vals.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;
}

void print(initializer_list<int> vals, initializer_list<double> ds)
{
    cout << vals.size() + ds.size() << " : ";
    for (auto p = vals.begin(); p != vals.end(); p++)
    {
        cout << *p << " ";
    }
    for (auto p = ds.begin(); p != ds.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;
}

class P
{
public:
    P(int a, int b)
    {
        cout << "P(int a,int b)" << endl;
    }
    P(initializer_list<int> vals)
    {
        cout << "P(initializer_list<int> vals)" << endl;
    }
};

class Q
{
public:
    Q(int a, int b)
    {
        cout << "Q(int a, int b)" << endl;
    }
};

int main()
{
    int i;    //未知初值
    int j{};  //初值为0
    int *p;   //未知地址
    int *q{}; //nullptr

    int x1(5.3);    //5
    int x2 = 5.3;   //5
    // int x3{5.0};    //报错
    // int x4 = {5.3}; //报错

    print({i, j});
    print({x1, x2, 3});
    // print({1, 2, 3.0, 4.0});//编译失败
    print({1, 2}, {3.1, 4.2}); //可以运行
    print({3.4, 5.6});

    P p1(1, 2);    //P(int a,int b)
    P p2{1, 2};    //P(initializer_list<int> vals)
    P p3{1, 2, 3}; //P(initializer_list<int> vals)
    P p4 = {4, 5}; //P(initializer_list<int> vals)

    Q q1(1, 2); //Q(int a, int b)
    Q q2{1, 2}; //Q(int a, int b)

    initializer_list<int> ilist; //initializer_list内包含一个array
    array<int, 10> as;

    return 0;
}