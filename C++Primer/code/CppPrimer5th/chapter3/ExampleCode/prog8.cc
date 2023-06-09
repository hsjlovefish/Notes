#include <cctype>
#include <iterator>
#include <iostream>
using namespace std;

int main() {

    // int ia[3][4];  // 大小为3的数组，每个元素是含有4个整数的数组  // 想像成树
    int arr[10][20][30] = {};

    int ia[3][4] = {
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11}
    };
    // 内嵌的花括号并非必要 ->等价于
    int ia2[3][4] = {0,1,2,3,4,5,6,7,8,9};

    // 如果仅仅想初始化每一行的第一个元素，其他未列出的元素执行默认初始化
    int ia3[3][4] = {{0}, {4}, {8}};

    // 它仅仅初始化第一行的4个元素
    int ia4[3][4] = { 0, 3, 6, 9 };

    ia[2][3] = arr[0][0][0];
    int (&row)[4] = ia[1]; // 把row绑定到ia的第二行

    constexpr size_t rowCnt = 3, colCnt = 4;
    int ia5[rowCnt][colCnt];
    for (size_t i = 0; i != rowCnt; ++i) {
        for (size_t j = 0; j != colCnt; ++j) {
            ia5[i][j] = i * colCnt + j; // 该元素的在数组中的序号
        }
    }

    size_t cnt = 0;
    for (auto &row : ia) {
        for (auto &col : row) {
            col = cnt;
            ++cnt;
        }
    }
    // 不改变元素时候
    for (const auto &row : ia) {
        for (auto col : row) {
            cout << col << endl;
        }
    }
    // 没有写操作时，还是将外层循环的控制变量声明称了引用类型，为了避免数组被自动转化成指针
    for (auto row : ia) { // row被转换成了指向该数组内首元素的指针  int *..... 分别变成ia[0]  ia[1]  ia[2]数组内的首元素
        // for (auto col : row);   // 编译器试图在一个 int *内遍历，显然不合法。 
    }

    int ia6[3][4];
    int (*p)[4] = ia;
    p = &ia6[2];

    for (auto p = ia6; p != ia6 + 3; ++p) { // p指向含有4个整数的数组
        for (auto q = *p; q != *p + 4; ++q) // q指向一个整数
            cout << *q << ' ';
        cout << endl;
    }
    for (auto p = begin(ia6); p != end(ia6); ++p) { // p指向ia的第一个数组
        for (auto q = begin(*p); q != end(*p); ++q) // q指向内层数组的首元素
            cout << *q << ' ';
        cout << endl;
    }

    using int_array = int[4]; // 两者等价
    typedef int int_array[4]; // 两者等价
    for (int_array *p = ia6; p != ia6 + 3; ++p) {
        for (int *q = *p; q != *p + 4; ++q) 
            cout << *q << ' ';
        cout << endl;
    }

    return 0;
}