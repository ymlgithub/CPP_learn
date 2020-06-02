/**
 * g++ p12.cpp -o output/app && output/app
 */

#include <iostream>
using namespace std;
using std::string;

template <typename T>
struct Container
{
    using value_type = T; //等价于typedef T value_type;
};

class Base
{
public:
    virtual void vfunc(float) {}

    virtual void vfunc2() final {}

    Base(Base &&base) noexcept {} // move function要保证不能抛出异常
};

class Derived final : public Base
{
public:
    // virtual void vfunc(int) override {} //编译失败：member function declared with 'override' does not override a base class member
    virtual void vfunc(float) override {} //override避免函数签名写错，导致没有覆写

    // virtual void vfunc2() {} // 编译失败：cannot override 'final' function "Base::vfunc2"
};

// class Derived2 : public Derived{};//a 'final' class type cannot be used as a base class

void foo() noexcept;       //保证函数不抛出异常
void foo() noexcept(true); //括号内的表达式为true时保证没有异常

int main()
{
    typedef void (*func)(int, int);
    using f = void (*)(int, int); //Type Alias
    return 0;
}