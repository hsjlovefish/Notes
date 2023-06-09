#include <string>
#include <iostream>
using namespace std;

int main() {

    // unsigned cnt = 42; // 不是常量表达式
    // constexpr unsigned sz = 42; // 是常量表达式
    // int arr[10];
    // int *parr[sz];
    // string bad[cnt]; // 运行通过，但书本上却说错误
    // string strs[get_size()]; //当get_size是constexpr时正确；否则错误
    
    
    // const unsigned sz = 3;
    // int ial[sz] = {0 ,1 ,2};
    // int a2[] = {0, 1, 2};
    // int a3[5] = {0, 1, 2};
    // string a4[3] = {"hi", "bye"};
    // int a5[2] = {0, 1, 2}; // 错误，初始值过多

    // char a1[] = {'C', '+'}; // 没有空字符， 大小为2
    // char a2[] = {'C', '+', '\n'}; // 有显示的空字符
    // char a3[] = "C++"; // 自动添加空字符 大小为4
    // const char a4[6] = "Daniel"; // 错误：没有空间可存放空字符！
    // char a[5] = "an"; // 合法

    // int a[] = {0, 1, 2};
    // int a2[] = a; // 错误，不允许使用一个数组初始化另一个数组
    // a2 = a; // 表达式必须是可修改的左值；  不能把一个数组直接赋值给另一个数组

    // int arr[10];
    // int *ptrs[10]; // ptrs时含有10个整型指针的数组
    // int &refs[10]; // 数组里不能放引用
    // cout << arr << endl;
    // cout << &arr << endl;
    // int (*Parray)[10] = &arr; // Parray指向一个含有10个整数的数组
    // int (&arrRef)[10] = arr; // arrRef引用一个含有10个整数的数组
    // int *(&arry)[10] = ptrs; // arry是数组的引用，该数组含有10个int型指针
    return 0;
}