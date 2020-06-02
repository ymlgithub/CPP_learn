/**
 * g++ p10_p11.cpp -o output/app && output/app
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
using Vec = std::vector<T, allocator<T>>; //Alias Template；别名，不能偏特化或者全特化别名

// template template parameter
template <typename T,
          template <typename>
          typename Container>
class XCls
{
private:
    Container<T> c;
};

int main()
{
    // Vec<int> coll;
    XCls<string, Vec> cl;
    return 0;
}