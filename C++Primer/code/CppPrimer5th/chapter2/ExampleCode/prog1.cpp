#include <iostream>
using namespace std;

int main() {

    // 第一个小例子,对应C++ primer 34页
    unsigned u = 10;
    int i = -42;  
    // -84
    cout << i + i << endl;
    // 4,294,967,296 - (-42) % 4,294,967,296  + 10 = 4,294,967,264
    // (-42) % 4,294,967,296应该为正，但是用c++mod得到的值为负 
    // 把负数转为无符号类似于直接给无符号数赋一个f负值
    // 结果等于这个负数加上无符号数的模
    cout << u + i << endl; 
    cout << -42 % 4294967296 << endl;

    // 第二个小例子 
    unsigned u1 = 42, u2 = 10;
    // 32
    cout << u1 - u2 << endl; 
    // 4,294,967,296 - 32 = 4,294,967,264
    // -32转换成uint
    cout << u2 - u1 << endl;

    // 正确
    for (int i = 10; i >= 0; --i) {
        cout << i << endl;
    }
    // 错误,--u的结果将会是 4,294,967,295
    // for (unsigned u = 10; u >= 10; --u) {
    //     cout << u << endl;
    // }
    // 上述错误的解决方法. 
    // 最后一次迭代时ui会变成0,从而跳出循环
    unsigned ui = 11;
    while (ui > 0) {
        --ui;
        cout << ui << endl;
    }

    int x = 10;
    uint y = 10;
    cout << "hello" << y - x << endl;


    return 0;
}