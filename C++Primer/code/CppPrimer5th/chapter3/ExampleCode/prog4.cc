#include <iostream>
using namespace std;

int main() {

    unsigned scores[11] = {}; // 11个0，列表初始化是0
    unsigned grade;
    for (auto i : scores)
        cout << i << " ";
    while (cin >> grade) {
        if (grade <= 100)
            ++scores[grade / 10];
    }
    for (auto i : scores) // 因为维度是数组类型的一部分，所以系统知道数组scores中有多少个元素。
        cout << i << " ";

    return 0;
}