#include <iostream>
using namespace std;

int main() {

    /*-----------------------------------------------------*/
    /*2.4.1 const的引用*/
    const int ci = 1024;
    const int &r1 = ci;
    // ① 表达式必须是可修改的左值
    // r1 = 42; 
    // 将 "int &" 类型的引用绑定到 "const int" 类型的初始值设定项时
    // 限定符被丢弃
    // int &r2 = ci;   试图让一个非常量对象引用指向一个常量对象


    /*-----------------------------------------------------*/
    // ② 初始化和对const的引用
    int i = 42;
    const int &r1 = i;
    const int &r2 = 42;
    const int &r3 = r1 * 2;
    // int &r4 = r1 * 2;  // r4非常量引用的初始值必须为左值
    double dval = 3.14;
    const int &ri = dval;
    // 编译器修改为下--->
    const int temp = dval;
    const int &r = temp;


    /*-----------------------------------------------------*/
    // ③ 对const的引用可能引用一个并非const的对象
    int i = 42;
    int &r4 = i;
    const int &r5 = i;
    r4 = 0; // r4 并非常量，可以修改
    // r5 = 0; // r5 是一个对常量的引用，错误

    return 0;
}