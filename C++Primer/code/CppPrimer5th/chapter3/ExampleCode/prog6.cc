#include <cstring>
#include <iostream>
using namespace std;

int main() {

    const char ca1[] = "hhhh";
    const char *ca2 = "aaaa";
    cout << *ca2 << endl; // 可看出const char *和[] 的区别
    strcmp(ca1, ca2);
    // strcat(ca1, ca2); // 第一个参数必须是变量
    char largeStr[15];
    strcpy(largeStr, ca1);
    strcat(largeStr, " ");
    strcat(largeStr, ca2);
    cout << largeStr << endl;
    char *index = largeStr;
    while (index && *index != '\0') {
        cout << *index;
        index++;
    }
    return 0;
}
