/**
 * g++ p3.cpp -o output/app && output/app
 */

#include <iostream>
#include <vector>
using namespace std;

void f(int)
{
    cout << "void f(int);" << endl;
}
void f(void *)
{
    cout << "void f(void*);" << endl;
}

int g()
{
    return 10;
}

int main()
{
    // Spaces in Template Expressions
    // vector<vector<int> > a;//旧版
    vector<vector<int>> b; //新版

    // nullptr and std::nullptr_t
    f(0); //void f(int);

    // f(NULL); //NULL的定义是0，同时符合f(int)和f(void*)，编译不通过：error: call of overloaded ‘f(NULL)’ is ambiguous

    f(nullptr); //void f(void*); nullptr的类型是std::nullptr_t

    // auto，自动推导类型，类型特别长才会用
    auto i = 10;
    auto j = g();
    auto k = [](int x) -> int { //lambda
        x *= 10;
        return x + 1;
    };
    cout << k(10) << endl;
    return 0;
}