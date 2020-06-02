/**
 * 检测C++版本
 * 
 * g++ p1.cpp -o output/app && output/app
 */

#include <iostream>
using namespace std;

int main()
{
    cout << __cplusplus << endl; // C++版本
    return 0;
}