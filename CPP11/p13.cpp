/**
 * g++ p13.cpp -o output/app && output/app
 */

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;

// decltype用法1
template <typename T1, typename T2>
auto add(T1 x, T2 y) -> decltype(x + y); //编译时确定返回值类型，与lambda相似

// decltype用法2
template <typename T>
void test_decltype(T obj)
{
    typedef typename decltype(obj)::iterator iType1;
    typedef typename T::iterator iType2;
    decltype(obj) anotherObj(obj);
    iType1 o1;
    iType2 o2;
}

class P
{
};

int main()
{
    map<string, float> coll;
    decltype(coll)::value_type elem; //推断对象类型
    map<string, float>::value_type elem2;

    test_decltype(vector<int>());

    auto cmp = [](const P &p1, const P &p2) {
        return true;
    };
    set<P, decltype(cmp)> coll2(cmp);//提取类型

    return 0;
}