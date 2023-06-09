#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <iterator>
#include <cstring>
using namespace std;

bool isArrEqual(int arr1[], size_t len1, int arr2[], size_t len2) {
    if (len1 != len2)
        return false;
    // int len = end(arr1) - begin(arr1);
    // int *beg1 = begin(arr1), *last1 = end(arr1); // 错误，没有与参数列表匹配的 重载函数 "begin" 实例 -- 参数类型为:  (int *)
    // int *beg2 = begin(arr2), *last2 = end(arr2);
    
    size_t index1 = 0, index2 = 0;
    while (index1 != len1 && index2 != len2) {
        if (arr1[index1] != arr2[index2])
            return false;
        ++index1;
        ++index2;
    }
    return true;
}

int main() {

    // 3.2.2节练习  练习3.4
    // string s1, s2;
    // cin >> s1 >> s2;
    // if (s1 == s2)
    //     cout << s1 << endl;
    // else
    //     cout << (s1 < s2 ? s2 : s1) << endl;

    // if (s1.size() < s2.size())
    //     cout << s2 << endl;
    // else if (s1.size() > s2.size())
    //     cout << s1 << endl;
    // // 相等不输出

    // 练习3.5
    // string s, strs;
    // while (cin >> s)
    //     strs += s;
    // cout << strs << endl;

    // string s, strs;
    // while (cin >> s)
    //     strs += s + ' ';
    // cout << strs << endl;


    /*--------------------------------*/
    // 3.2.3节练习
    // string s1("hello world");
    // for (char &ch : s1) {
    //     ch = 'X';
    // }
    // cout << s1 << endl;

    // const string s2 = "Keep out!";
    // for (auto &c : s2) {/* .. */}

    // const string s3 = "arkj ajw/;'!";
    // string result;
    // for (auto &ch : s3) {
    //     //   if ((c>='0' && c<='9')
    //     //   || (c>='a' && c<='z') || (c>='A' && c<='Z'))
    //     if (!ispunct(ch)) {
    //         result += ch;
    //     } 
    // }
    // cout << result << endl;

    /*--------------------------------*/
    // 3.3.2节练习
    // vector<int> arr;
    // int ival = 0;
    // while (cin >> ival)
    //     arr.push_back(ival);
    // for (auto num : arr) cout << num << endl;
    // vector<string> text;
    // string word;
    // while (cin >> word)
    //     text.push_back(word);
    // for (auto str : text) cout << str << endl;

    /*--------------------------------*/
    // 3.3.3节练习
    // string word;
    // vector<string> text;
    // while (cin >> word) 
    //     text.push_back(word);
    // for (auto &str : text) {
    //     for (auto &ch : str) {
    //         ch = toupper(ch);
    //     }
    // }
    // for (auto &str : text)
    //     cout << str << endl;

    // 练习3.19
    // vector<int> ivec(10, 42);

    // vector<int> ivec2;
    // for (int i = 0; i < 10; ++i) 
    //     ivec2.push_back(42);

    // vector<int> ivec3(10);
    // for (auto it = ivec3.begin(); it != ivec3.end(); ++it)
    //     *it = 42;

    // vector<int> ivec4 {42, 42, 42, 42, 42, 42, 42, 42, 42, 42};

    // 练习3.20
    // vector<int> ivec;
    // int ival = 0;
    // while (cin >> ival)
    //     ivec.push_back(ival);
    // int len = ivec.size();
    // for (int i = 0; i < len - 1; ++i)
    //     cout << ivec[i] + ivec[i + 1] << endl;
    // for (int i = 0, j = len - 1; i < len && j >= 0 && i <= j; ++i, --j)
    //     cout << ivec[i] + ivec[j] << endl; 


    /*--------------------------------*/
    // 3.4.1节练习
    // vector<int> ivec(10, 10);
    // for (vector<int>::iterator it = ivec.begin(); it != ivec.end(); ++it)
    //     *it = *it * 2;
    // for (int ival : ivec)
    //     cout << ival << endl;

    /*--------------------------------*/
    // 3.4.2节练习
    // vector<unsigned> scores(11, 0);
    // unsigned grade;
    // auto it = scores.begin();
    // while (cin >> grade) {
    //     if (grade <= 100) {
    //         auto iter = it + grade / 10;
    //         (*iter)++;
    //     }   
    // }
    // for (int a : scores) {
    //     cout << a << " ";
    // }

    // vector<int> ivec;
    // int ival = 0;
    // while (cin >> ival) {
    //     ivec.push_back(ival);
    // }
    // auto beg = ivec.begin();
    // for (auto beg = ivec.begin(); beg != ivec.end() - 1;) {
    //     int val1 = *beg;
    //     beg++;
    //     int val2 = *beg;
    //     cout << val1 + val2 << " ";
    // }
    // cout << endl;

    // auto end = ivec.end() - 1;
    // for (beg = ivec.begin(); beg <= end; beg++, end--) {
    //     cout << *beg + *end << " ";
    // }
    // cout << endl;
    // vector<int> text{1 , 2 ,3 ,4, 5, 6 ,7 ,8};
    // int sought = 7;
    // auto beg = text.begin(), end = text.end();
    // auto mid = beg + end; // 错误两个迭代器不能相加
    // while (mid != end && *mid != sought)
    // {
    //     if (sought < *mid)
    //         end = mid;
    //     else
    //         beg = mid + 1;
    //     mid = beg + (end - beg) / 2;
    // }
    // cout << *mid << endl;


    /*--------------------------------*/
    // 3.5.2节练习
    // constexpr size_t len = 10;
    // int arr[len];
    // for (auto i : arr) // 未初始化
    //     cout << i << " ";
    // for (size_t ix = 0; ix < len; ++ix)
    //     arr[ix] = ix;
    // for (auto i : arr)
    //     cout << i << " ";

    // vector<int> ivec;
    // for (size_t ix = 0; ix < len; ++ix)
    //     ivec.emplace_back(arr[ix]);
    // for (int i : ivec)
    //     cout << i << " ";



    /*--------------------------------*/
    // 3.5.3节练习
    // int arr[] = {1, 2, 3};
    // int len = end(arr) - begin(arr);
    // int *beg = arr, *end = beg + len;
    // while (beg < end) {
    //     *beg = 0;
    //     ++beg;
    // }
    // for (auto i : arr) 
    //     cout << i << " ";
    // cout << endl;

    // int testArr1[] = {0, 1, 2}, testArr2[] = {0, 1, 2};
    // int testArr3[] = {0}, testArr4[] = {0, 1, 2, 3};
    // cout << "arr1 0 1 2  vs  arr2 0 1 2：isEqual? " 
    //      << isArrEqual(testArr1, 3, testArr2, 3) << endl;
    // cout << "arr1 0 1 2  vs  arr3 0：isEqual? " 
    //      << isArrEqual(testArr1, 3, testArr3, 1) << endl;
    // cout << "arr1 0 1 2  vs  arr4 0 1 2 3：isEqual? " 
    //      << isArrEqual(testArr1, 3, testArr4, 4) << endl;


    /*--------------------------------*/
    // 3.5.4节练习
    // const char ca[] = {'h', 'e', 'y', '1', '2'};
    // const char *cp = ca;
    // // while (*cp) {
    // //     cout << *cp << endl;
    // //     ++cp;
    // // }
    // const char ca2[] = "hey12";
    // const char ca3[] = {'h', 'e', 'y', '1', '2', '\0'};
    // cout << strcmp(ca, ca2) << endl;
    // cout << strcmp(ca2, ca3) << endl;

    char str1[] = "nihao";
    char str2[] = "shijie";
    cout << sizeof(str1) << endl;
    char str[12];
    strcpy(str, str1);
    strcat(str, str2);
    cout << str << " sizeof(str) " << sizeof(str) <<  endl;

    return 0;
}