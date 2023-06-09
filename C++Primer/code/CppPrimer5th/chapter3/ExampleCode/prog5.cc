#include <string>
#include <iostream>
#include <iterator>
using namespace std;

int main() {

    // string nums[] = {"one", "two", "three"};
    // string *p = &nums[0];
    // string *p2 = nums; // 等价于上一条语句

    // int ia[] = {0,1,2,3,4,5,6,7,8,9};
    // auto ia2(ia); // ia2是一个整型指针，指向ia的第一个元素
    // // 等价于 auto ia2(&ia[0]);
    // // ia2 = 42; // 错误，不能用int值给指针赋值

    // decltype(ia) ia3 = {0,1,2,3,4,5,6,7,8,9};
    // // ia3 = p; 错误：不能用整型指针给数组赋值
    // int i = 0;
    // ia3[4] = i;

    /*----------------------------------*/

    // int arr[] = {0,1,2,3,4,5,6,7,8,9};
    // int *p = arr;
    // ++p;
    // int *e = &arr[10]; // 不能对尾后指针执行解引用或递增的操作
    // for (int *b = arr; b != e; ++b)
    //     cout << *b << endl;


    /*----------------------------------*/
    // int ia[] = {0,1,2,3,4,5,6,7,8,9};
    // int *beg = begin(ia);
    // int *last = end(ia);
    // // 直到数组中第一个负值元素
    // while (beg != last && *beg >= 0)
    //     ++beg;


    /*----------------------------------*/
    // constexpr size_t sz = 5;
    // int arr[sz] = {1,2,3,4,5};
    // int *ip = arr; // ip->arr[0]
    // int *ip2 = ip + 4; // ip2->arr[4]

    // int *p = arr + sz; // p->arr[5];
    // int *p2 = p + 10; // 错误，p2值未定义。编译器检查不出来

    // auto n = end(arr) - begin(arr); // ptrdiff_t类型

    // int *b = arr, *e = arr + sz;
    // while (b < e) {
    //     // do something
    //     ++b;
    // }

    // // 如果两个指针分别指向不相关的对象，则不能比较它们
    // int i = 0, sz = 42;
    // int *p = &i, *e = &sz;
    // while (p < e)  //无意义
    // // void *a = &i, *b = &sz;
    // // while (a < b); // 无意义


    /*----------------------------*/
    // int ia[] = {1, 2, 3, 4 ,5};
    // int last = *(ia + 4); // ia[4]
    // last = *ia + 4; // ia[0] + 4

    /*----------------------------*/
    // int ia[] = {1, 2, 3, 4 ,5}; 
    // // ia[0]是使用了数组名字的表达式
    // // 对数组执行下标运算其实是对指向数组元素的指针执行下标运算
    // int i = ia[2];  // *(ia + 2)
    // int *p = ia;
    // i = *(p + 2); // 等价于 i = ia[2];

    // // 只要指针指向的是数组中的元素(或指向数组中的为元素的下一位置)，都可执行下标运算。
    // int *p = &ia[2];
    // int j = p[1];
    // int k = p[-2]; // 表示ia[0];




    return 0;
}