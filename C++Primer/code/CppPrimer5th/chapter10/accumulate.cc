#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

void elimDups(vector<string> &words) {
    // 按字典序排序words，以便于查找重复单词
    sort(words.begin(), words.end());
    // unique重排输入范围，使得每个单词只出现一次
    // unique会使不重复的元素出现在vector的开始部分
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

int main(int argc, char* argv[]) {
    (void) argc;
    (void) argv;

    {
        vector<string> v = {"666", "777", "a", "bbb"};
        string sum = accumulate(v.cbegin(), v.cend(), string(""));    
        cout << sum << endl;  
    }
    
    {
        // back_inserter
        vector<int> vec;
        fill_n(back_inserter(vec), 10, 0);
        for (const auto& val : vec) {
            cout << val << endl;
        }
    }

    {
        // copy algorithm
        int a1[] = {0, 1, 2, 3, 5};
        int a2[sizeof(a1) / sizeof(*a1)];
        auto ret = copy(begin(a1), end(a1), a2);
        // 返回目的尾置迭代器(递增后)的值。ret恰好指向拷贝到a2的尾元素之后的尾置
        cout << ret << endl;
    }

    {
        // sort unique
        vector<string> words = {"777", "666", "777", "888", "5555", "99"};
        elimDups(words);
        for (const auto& s : words) {
            cout << s << endl;
        }
        stable_sort(words.begin(), words.end(),
                [](const string &a, const string &b) {
            return a.size() < b.size();
        });
        for (const auto& s : words) {
            cout << s << endl;
        }
    }

    {
        // 可变lambda
        size_t v1 = 42;
        auto f = [v1] () mutable { return ++v1; };
        auto v2 = f();
        // 42 43
        cout << "v1: " << v1 << ", v2: " << v2 << endl;

        size_t v3 = 42;
        auto f2 = [&v3] () { return ++v3; };
        auto v4 = f2();
        // 43 43
        cout << "v3: " << v3 << ", v4: " << v4 << endl;
    }

    {
        // 指定lambda返回类型
        vector<int> vi = {1, 2, 3, 4, -1, -2};
        // 书上说会这种lambda报错，但我的mac没有报错
        /*
        * Apple clang version 13.1.6 (clang-1316.0.21.2.5)
        * Target: arm64-apple-darwin21.6.0*
        */
        transform(vi.begin(), vi.end(), vi.begin(), 
                [](int i) {
            if (i < 0) {
                return -i;
            } else {
                return i;
            }
        });
        for (const auto& i : vi) {
            cout << i << endl;
        }
    }

    {
        
        // istream_iterator
        {
            // istream_iterator<int> int_it(cin); // 从cin读取int
            // istream_iterator<int> int_eof;     // 默认初始化将
            // vector<int> vec;
            // while (int_it != int_eof) {
            //     vec.push_back(*int_it++);
            // }
            // for (const auto val : vec) {
            //     cout << val << " ";
            // }
            // cout << endl;
        }

        {
            // istream_iterator<int> in_iter(cin), eof;
            // vector<int> vec(in_iter, eof);
            // for (const auto val : vec) {
            //     cout << val << " ";
            // }
            // cout << endl;
        }
    }

    {
        // reverse_iterator
        string line("first,middle,last");
        auto comma = find(line.cbegin(), line.cend(), ',');
        cout << string(line.cbegin(), comma) << endl;

        auto rcomma = find(line.crbegin(), line.crend(), ',');
        cout << string(line.crbegin(), rcomma) << endl;

        // 想正确的打印LAST
        cout << string(rcomma.base(), line.cend()) << endl;
    }

    return 0;
}