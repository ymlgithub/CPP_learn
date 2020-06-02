/**
 * g++ p8.cpp -o output/app && output/app
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> a{1, 2, 4};
    for (auto &e : a) //引用方式
    {
        e++;
    }
    for (auto e : a)
    {
        cout << e << endl;
    }
    for (const auto &e : a)
    {
        cout << e << endl;
    }
    return 0;
}