/**
 * g++ p9.cpp -o output/app && output/app
 */

#include <iostream>
using namespace std;

class Zoo
{
public:
    /**
     * 如果自行定义了一个构造函数，那么编译器就不会再给一个默认构造函数
     * 
     * 如果强制加上=default，那么可以重新获得默认构造函数
     * 
     * = delete：删除这个函数
     * 
     * 只对BigTree函数用有意义
     */
    Zoo(int i, int j) : d1(i), d2(j) {}
    Zoo(const Zoo &) = delete; //不要这个函数
    Zoo(Zoo &&) = default;     //右值引用
    Zoo &operator=(const Zoo &) = default;
    Zoo &operator=(const Zoo &&) = delete; //move assignment
    virtual ~Zoo();

private:
    int d1, d2;
};

int main()
{
    return 0;
}