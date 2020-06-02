/**
 * Variadic Templates，数量不定的模板参数
 * 
 * g++ p2.cpp -o output/app && output/app
 */

#include <iostream>
using namespace std;

void print() {} //最终调用

template <typename T, typename... Types>         // ...
void print(const T &arg1, const Types &... args) // ...
{
    cout << "Size of args: " << sizeof...(args) << " | " << arg1 << endl;
    print(args...); // ...
}

template <typename... Types>
void print(const Types &... args) //共存，更泛化的版本
{
    cout << "void print(const Types &... args)" << endl;
}

int main()
{
    print(1, 2.3, '4', "567");
    return 0;
}