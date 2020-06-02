/**
 * Uniform Initialization：一致性初始化
 * 
 * g++ p4.cpp -o output/app && output/app
 */

#include <iostream>
#include <vector>
#include <complex>
#include <string>
using namespace std;

int main()
{
    // 一致性初始化
    // 编译器将{t1,t2,...,tn}做出一个initializer_list<T>，关联至一个array<T,n>
    int values[]{1, 2, 3};
    int a = 4, b = 5, d{6};
    //STL容器都有一个参数为initializer_list<T>的构造函数
    vector<int> v{2, 3, a, b, d};
    vector<string> ss{"123", "456", "789"};
    complex<double> c{4.0, 3.0};//array<double,2>中的元素会被分解之后传给comlex的构造函数
    return 0;
}