/**
 * Variadic Templates 变参模板
 * 模板的参数量变化、类型变化
 * 
 * g++ p15_21.cpp -o output/app && output/app
 */

#include <iostream>
#include <string>
#include <bitset>
using namespace std;

void printX() {}

template <typename T, typename... Types>
void printX(const T &arg1, const Types &... args)
{
    cout << "Size of args : " << sizeof...(args)
         << " ; arg1 : " << arg1 << endl;
    printX(args...);
}

namespace test
{ //递归继承
    template <typename... Values>
    class tuple; //声明

    template <>
    class tuple<> //终止
    {
    };
    template <typename Head, typename... Tail>
    class tuple<Head, Tail...> : private tuple<Tail...>
    {
        typedef tuple<Tail...> composited; //是一种类型

    protected:
        Head m_head;

    public:
        tuple() {}
        tuple(Head v, Tail... vtail) : composited(vtail...), m_head(v) {} //调用了父类的构造函数

        // auto head() -> decltype(m_head) { return m_head; }
        Head head() { return m_head; }
        composited &tail() { return *this; }
    };

} // namespace test

int main()
{
    printX(1.2, "string", bitset<16>(377), 42); //参数量、类型都可变
    test::tuple<int, double, string> t(1, 2.3, "456");
    cout << sizeof(t) << endl;              // 48
    cout << t.head() << endl;               // 1
    cout << t.tail().head() << endl;        // 2.3
    cout << t.tail().tail().head() << endl; // 456
    return 0;
}