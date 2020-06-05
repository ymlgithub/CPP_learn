/**
 * g++ term03.cpp -o app && ./app
 * 
 * const在星号左边，被指物是常量；在星号右边，指针是常量；在星号两边，指针和被指物都是常量。
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

void f1(char *p)
{
    p[0] = 'a';
}

void f2(const char *p)
{
    // f1(p); // error: invalid conversion from ‘const char*’ to ‘char*’ [-fpermissive]
}

void f3(char *const p)
{
    f1(p);
    // p = NULL; //error: assignment of read-only parameter ‘p’
}

void f4(const char *s)
{
    cout << "const char*" << endl;
}

void f4(char *s)
{
    cout << "char*" << endl;
}

int main()
{
    char greeting[] = "hello";
    char *p0 = greeting;
    // p1和p2等价
    const char *p1 = greeting;
    char const *p2 = greeting;
    char *const p3 = greeting;
    const char *const p4 = greeting;

    *p0 = 'a';
    // *p1 = 'a'; //error: assignment of read-only location ‘* p1’
    // *p2 = 'a'; //error: assignment of read-only location ‘* p2’
    *p3 = 'a';
    // *p4 = 'a'; //error: assignment of read-only location ‘*(const char*)p4’

    p1 = NULL;
    p2 = NULL;
    // p3 = NULL; //error: assignment of read-only variable ‘p3’
    // p4 = NULL; //error: assignment of read-only variable ‘p4’

    vector<int> arr = {1, 2, 3};
    const vector<int>::iterator iter = arr.begin(); // iter相当于 T* const
    *iter = 10;
    // iter++; //error: passing ‘const iterator {aka const __gnu_cxx::__normal_iterator<int*, std::vector<int> >}’ as ‘this’ argument discards qualifiers [-fpermissive]

    vector<int>::const_iterator cIter = arr.begin();
    // *cIter = 11; // error: assignment of read-only location ‘cIter.__gnu_cxx::__normal_iterator<const int*, std::vector<int> >::operator*()’
    cIter++;

    f4("hahha");  // const char*
    f4(greeting); // char*

    return 0;
}