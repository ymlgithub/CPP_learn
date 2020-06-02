/**
 * explicit for constructors taking more than one argument
 * 
 * g++ p7.cpp -o output/app && output/app
 */

#include <iostream>
using namespace std;

class P
{
public:
    P(initializer_list<int> args)
    {
        cout << "P(initializer_list<int> args)" << endl;
    }
    explicit P(int a, int b, int c)
    {
        cout << "explicit P(int a, int b, int c)" << endl;
    }
};

int main()
{
    P p1 = {1, 2, 3}; //P(initializer_list<int> args),和讲的不一样
    P p2 = {1, 2};    //P(initializer_list<int> args)
    P p3(1, 2, 3);    //explicit P(int a, int b, int c)
    P p4{1, 2, 3};    //P(initializer_list<int> args)
    P p5({1, 2, 3});  //P(initializer_list<int> args)
    return 0;
}