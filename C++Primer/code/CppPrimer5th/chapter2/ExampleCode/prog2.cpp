#include <iostream>
using namespace std;

int main() {

    int ival = 1024;
    int &refVal = ival;
    // int &refVal2; // 错误，引用必须被初始化

    refVal = 2;
    int ii = refVal;

    int &refVal3 = refVal;
    int z = refVal;

    int i = 1024, i2 = 2048;
    int &r = i, r2 = i2;
    int i3 = 1024, &ri = i3;
    int &r3 = i3, &r4 = i2;

    // int &refVal4 = 10; // 错误: 引用类型得初始值必须是一个对象
    double dval = 3.14;
    // int &refVal5 = dval;  //错误?:此处引用类型得初始值必须是int型对象

    return 0;
}