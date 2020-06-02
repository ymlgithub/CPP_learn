/**
 * g++ p14.cpp -o output/app && output/app
 */

#include <iostream>
#include <set>
using namespace std;
class Person
{
};
class Functor
{
private:
    int id;

public:
    void operator()()
    {
        cout << "id : " << id << endl;
        id++;
    }
};

int main()
{
    /**
     * lambda：定义一个内联函数，可以当做参数或对象
     * 
     * [...](...)mutable throwSpec -> retType {...} 
     * 
     * []           lambda导入符号；[=]：传值；[&]传引用
     * ()           参数
     * mutable      可选
     * throwSpec    可选
     * retType      可选，返回值类型
     * 如果三个可选都不写，()也不用写
     */

    [] {
        cout << "Hello lambda" << endl;
    }(); //没有名称，直接调用，只能调用一次

    auto f = [] { //函数对象，最简形式
        cout << "lambda" << endl;
    };

    f();

    int id = 0;
    auto g = [id]() mutable { //id是按值传递的，函数内定义了一个id，等价于Functor类
                              //mutable是指id可变
        cout << "id : " << id << endl;
        id++;
    };
    id = 42;
    g(); // 0
    g(); // 1
    g(); // 2

    auto h1 = [&id](int param) mutable { //按引用传递
        cout << "id : " << id << endl;
        param++;
        id++;
    };

    id = 31;
    h1(1); //31
    h1(2); //32
    id = 10;
    h1(3); //10

    auto h2 = [id] { //没有mutable，不可修改
        cout << "id : " << id << endl;
        // id++; // increment of read-only variable ‘id’
    };

    auto f1 = [id]() mutable {
        cout << id << endl;
        static int x = 5; // 可以声明变量
        int y = 6;
        return id; //可以返回数值
    };

    int x = 1, y = 2;
    auto f2 = [=, &y] {}; //除了y以外的变量都用值传递，y使用引用传递，并且传递所有变量
    auto f3 = [x, &y] {};
    auto cmp = [](Person &p1, Person &p2) { return true; };
    // set<Person, decltype(cmp)> ss;// error: use of deleted function ‘main()::<lambda(Person&, Person&)>::<lambda>()’ （ lambda 没有默认构造函数 ）
    set<Person, decltype(cmp)> ss(cmp);

    return 0;
}