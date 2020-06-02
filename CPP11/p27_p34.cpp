/**
 * g++ p27_p34.cpp -o output/app && output/app
 * 
 * hashtable:
 *  1. 元素个数超过哈希桶个数就rehashing，桶个数增加两倍左右
 *  2. 桶个数是质数
 * 
 */

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <tuple>
#include <complex>

using namespace std;

namespace hash_test
{
    template <class Key>
    struct hash
    {
    };

    template <>
    struct hash<int> //特化版的hash
    {
        size_t operator()(int x) const { return x; }
    };
} // namespace hash_test

int main()
{
    vector<int> va{1, 2, 3};
    vector<int> vb(move(va));
    cout << va.size() << "," << vb.size() << endl; //0,3

    array<int, 10> arr; // int arr[10];

    // int[100] b;
    typedef int T[100];
    T c; //int c[100];

    cout << hash<int>()(123) << endl;
    cout << hash<long>()(123L) << endl;
    cout << hash<string>()("123") << endl;
    cout << hash<const char *>()("123") << endl;
    cout << hash<float>()(3.14) << endl;
    cout << hash<double>()(3.14) << endl;
    cout << hash<char>()('A') << endl;

    cout << sizeof(string) << endl;          //32
    cout << sizeof(double) << endl;          //8
    cout << sizeof(float) << endl;           //4
    cout << sizeof(int) << endl;             //4
    cout << sizeof(complex<double>) << endl; //16
    auto tp = make_tuple("ss", 1, 2, complex<double>(1.1, 2.2));
    cout << sizeof(tp) << endl; // 32；有内存对齐
    cout << ">>>>" << endl;
    cout << get<0>(tp) << get<1>(tp) << endl; //ss1
    get<1>(tp) = 10;
    cout << get<1>(tp) << endl; //10

    string s0;
    int i1, i2;
    complex<double> c3;
    tie(s0, i1, i2, c3) = tp;
    cout << c3 << endl; // (1.1,2.2)

    //meta programming
    typedef tuple<int, float, string> TupleType;
    cout << tuple_size<TupleType>::value << endl; //3
    tuple_element<1, TupleType>::type f1 = 1.0;   //float
    typedef tuple_element<1, TupleType>::type TT;

    return 0;
}