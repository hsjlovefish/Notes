#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <memory>
#include <random>
#include <regex>
#include <set>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;

vector<vector<list<int>>> files;

typedef tuple<vector<list<int>>::size_type,
              vector<list<int>>::const_iterator,
              vector<list<int>>::const_iterator> matches;

vector<matches> 
findbook(const vector<vector<list<int>>> &files, const string &book);

vector<unsigned> bad_randVec() {
    default_random_engine e;
    uniform_int_distribution<unsigned> u(0, 9);
    vector<unsigned> ret;
    for (size_t i = 0; i < 100; ++i)
        ret.push_back(u(e));
    return ret;
}

vector<unsigned> good_randVec() {
    static default_random_engine e;
    static uniform_int_distribution<unsigned> u(0, 9);
    vector<unsigned> ret;
    for (size_t i = 0; i < 100; ++i)
        ret.push_back(u(e));
    return ret;
}

int main(int argc, char* argv[]) {
    (void) argc;
    (void) argv;

    {
        // tuple
        tuple<size_t, size_t, size_t> threeD; // 0, 0, 0
        tuple<string, vector<double>, int, list<int>>
            someval("jsh666", {1.2, 1.3}, 5, {0, 1, 2, 4});

        // 书中说不能这么写，但编译通过了
        tuple<size_t, size_t, size_t> threeD2 = {1, 2, 3}; // 错误
        tuple<size_t, size_t, size_t> threeD3{1, 2, 3};    // 正确

        auto item = make_tuple("1,2,3", 3, 20.00);
        auto s = get<0>(item);
        auto cnt = get<1>(item);
        auto price = get<2>(item);
        get<2>(item) *= 0.8;

        // 如果不知道tuple的准备类型细节信息
        typedef decltype(item) trans;
        size_t sz = tuple_size<trans>::value;
        cout << sz << endl;
        tuple_element<1, trans>::type cnt2 = get<1>(item);

        cout << (threeD == threeD2) << " "
            << (threeD2 == threeD3) << endl;
    }

    {
        // bitset
        bitset<32> bitvec(1U);

        bitset<13> bitvec1(0xbeef);
        bitset<20> bitvec2(0xbeef);
        bitset<128> bitvec3(~0ULL);
        bitset<32> bitvec4("1100");

        string str("111111111111111111111000000000000000000");
        bitset<32> bitvec5(str, 5, 4);
        bitset<32> bitvec6(str, str.size() - 4);
        cout << "bitvec: "<< bitvec 
             << " " << bitvec1
             << " " << bitvec2 
             << " " << bitvec3
             << " " << bitvec4
             << " " << bitvec5
             << " " << bitvec6 <<  endl;

        // operation
        ~bitvec[0];
        bool b = bitvec[0];

        unsigned long ulong = bitvec3.to_ulong();
        cout << "ulong = " << ulong << endl;
    }

    {
        // regex
        string pattern("[^c]ei");
        pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
        regex r(pattern);
        smatch results;
        string test_str = "receipt freind theif receive";
        if (regex_search(test_str, results, r)) {
            cout << results.str() << endl;
        }
    }

    {
        // random
        default_random_engine e;
        for (size_t i = 0; i < 10; ++i)
            cout << e() << " ";

        // 生成 0 到 9之间均匀分布的随机数
        uniform_int_distribution<unsigned> u(0, 9);
        for (size_t i = 0; i < 10; ++i)
            cout << u(e) << " ";
        cout << endl;

        // 引擎生成随机数列
        vector<unsigned> v1(bad_randVec());
        vector<unsigned> v2(bad_randVec());
        cout << ((v1 == v2) ? "equal" : "not equal") << endl;

        vector<unsigned> v3(good_randVec());
        vector<unsigned> v4(good_randVec());
        cout << ((v3 == v4) ? "equal" : "not equal") << endl;

        // 设置随机数发生器种子
        default_random_engine e1;
        default_random_engine e2(212413214);
        default_random_engine e3;
        e3.seed(23123);

        // 生成种子常用的方法是time, 定义在头文件ctime中
        default_random_engine e4(time(0));

        uniform_real_distribution<> u2(0, 1); // 默认生成double
        uniform_int_distribution<> u3(0, 1);  // 默认生成int

        normal_distribution<> n(4, 1.5); // 均值4，标准差1.5
        default_random_engine e5;
        vector<unsigned> vals(9);
        for (size_t i = 0; i != 200; ++i) {
            unsigned v = lround(n(e5)); // 舍入到最接近的整数
            if (v < vals.size()) {
                ++vals[v];
            }
        }
        for (size_t j = 0; j != vals.size(); ++j) {
            cout << j << ": " << string(vals[j], '*') << endl;
        }

        bernoulli_distribution b; // 默认50/50机会
    }

    {
        // manipulator
        // 1 控制布尔值的格式
        cout << true << " " << false << " "
            << boolalpha << true << " " << false << endl;
        cout << true << " " << false << " "
            << noboolalpha << true << " " << false << endl;

        // 2 指定整形值的进制, 以下操纵符只影响整形对象，浮点之的表示形式不受影响
        cout << "default: " << 20 << " " << 1024 << endl;
        cout << "octal: " << oct << 20 << " " << 1024 << endl;
        cout << "hex: " << hex << 20 << " " << 1024 << endl;
        cout << "decimal: " << dec << 20 << " " << 1024 << endl;
        
        // 3 输出中指出进制
        cout << showbase;
        cout << "default: " << 20 << " " << 1024 << endl;
        cout << "octal: " << oct << 20 << " " << 1024 << endl;
        cout << "hex: " << hex << 20 << " " << 1024 << endl;
        cout << "decimal: " << dec << 20 << " " << 1024 << endl;
        cout << noshowbase;

        // 4 可以用操纵符nouppercase noshowbase dec来重置流的状态
        cout << nouppercase << noshowbase << dec;

        // 5 指定 浮点数 的打印精度
        cout << "presision: " << cout.precision()
            << ", value: " << sqrt(2.0) << endl;
        cout.precision(12);
        cout << "presision: " << cout.precision()
            << ", value: " << sqrt(2.0) << endl;
        cout << setprecision(3); // 定义在#include <iomanip>中
        cout << "presision: " << cout.precision()
            << ", value: " << sqrt(2.0) << endl;


        // 6 指定浮点数记数法
        // scientific   改变流的状态来使用科学记数法
        // fixed        改变流的状态来使用定点十进制
        // hexfloat     强制浮点数使用十六进制格式
        // defaultfloat 将流恢复到默认状态
        cout << "default format: " << 100 * sqrt(2.0) << '\n'
		     << "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
	         << "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
		     << "hexadecimal: " << hexfloat << 100 * sqrt(2.0) << '\n'
		     << "use defaults: " << defaultfloat << 100 * sqrt(2.0) 
		     << "\n\n";

        // 7 打印小数点 showpoint
        // 默认情况，浮点数的小数部分为0，不显示小数点
        cout << 10.0 << endl;
        cout << showpoint << 10.0
            << noshowpoint << endl;

        // 8 输出补白
        // 1) setw      指定下一个数字或字符串的最小空间
        // 2) left      左对齐输出
        // 3) right     右对齐输出, 右对齐是默认格式
        // 4) internal  控制负数的符号的位置, 它左对齐符号，右对齐值，用空格填满所有中间空间
        // 5) setfill   允许指定一个字符代替默认的空格来补白
        int i = -16;
        double d = 3.14159;
        cout << "i: " << setw(12) << i << "next col" << '\n'
            << "d: " << setw(12) << d << "next col" << '\n';
        cout << left 
            << "i: " << setw(12) << i << "next col" << '\n'
            << "d: " << setw(12) << d << "next col" << '\n'
            << right;
        cout << right
            << "i: " << setw(12) << i << "next col" << '\n'
            << "d: " << setw(12) << d << "next col" << '\n';
        cout << internal
            << "i: " << setw(12) << i << "next col" << '\n'
            << "d: " << setw(12) << d << "next col" << '\n';
        cout << setfill('#')
            << "i: " << setw(12) << i << "next col" << '\n'
            << "d: " << setw(12) << d << "next col" << '\n'
            << setfill(' ');   // restore the normal pad character   
        
        // 9 控制输入格式
        // 默认情况下，输入运算符会忽略空白符(空格符、制表符、换行符、换纸符、回车符)
    //     char ch;
    //     while (cin >> ch)
    //         cout << ch;

    //     cin >> noskipws;
    //     while (cin >> ch)
    //         cout << ch;
    }

    return 0;
}