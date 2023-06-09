#include <iostream>
#include <memory>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

#include "Blob.h"
#include "Sales_data.h"

using namespace std;

template <typename T>
int compare(const T &v1, const T &v2) {
    // 都用 < ，T就不必支持 > 
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;

    // 这样写也可以
    // if (less<T>()(v1, v2)) return -1;
    // if (less<T>()(v2, v1)) return 1;
    return 0;
}

template <>
int compare(const char* const &p1, const char* const &p2) {
    cout << "template specialization" << endl;
    return strcmp(p1, p2);
}

// 类型参数可以用来指定返回类型或函数的参数类型，以及在函数体内用于变量声明或类型转换
template <typename T> T foo(T* p) {
    T tmp = *p;
    // ... do something
    return tmp;
}

// 推荐使用typename，class是老程序员用的
template <typename T, class U> 
T calc(const T&, const U&);

// 非类型参数模板
template <unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M]) {
    // p1引用一个含有N个证书的数组
    cout << "nontye parameter" << endl;
    return strcmp(p1, p2);
}

// inline和constexpr的函数模板
template <typename T> inline T min(const T&, const T&);

// 书中示例代码
// template <typename T> class Blob {
// public:
//     typedef T value_type;
//     typedef typename std::vector<T>::size_type size_type; // 模板的别名就需要这样写
//     // using size_type = typename std::vector<T>::size_type; // 等价

//     Blob();
//     Blob(std::initializer_list<T> il);

//     size_type size() const {
//         return data->size();
//     }

//     bool empty() const {
//         return data->empty();
//     }

//     void push_back(const T &t) {
//         data->push_back(t);
//     }

//     void push_back(T &&t) {
//         data->push_back(std::move(t));
//     }

//     void pop_back();
//     T& back();
//     T& operator[](size_type i);

// private:
//     std::shared_ptr<std::vector<T>> data;
//     void check(size_t i, const std::string &msg) const;
// };

template <typename T> class Foo {
public:
    static std::size_t count() {
        return ctr;
    }

private:
    static std::size_t ctr;
};

template <typename T>
size_t Foo<T>::ctr = 0;

class DebugDelete {
public:
    DebugDelete(std::ostream &s = std::cerr) : os(s) {}

    template <typename T>
    void operator()(T *p) const {
        os << "deleting unique_ptr" << std::endl;
        delete p;
    }

private:
    std::ostream &os;
};

// // 打开命名空间，以便特例化std::hash
// namespace std {

// // 在Sales_data.h中有定义
// template <>
// struct hash<Sales_data> {
//     // 用来散列一个无序容器的类型必须要定义下列类型
//     typedef size_t result_type;
//     typedef Sales_data argument_type;
//     size_t operator()(const Sales_data& s) const;
// };

// size_t hash<Sales_data>::operator()(const Sales_data& s) const {
//     // 由于hash<Sales_data>要使用Sales_data的私有成员，因此我们将它声明为Sales_data的友元
//     return hash<string>()(s.bookNo) ^
//         hash<unsigned>()(s.units_sold) ^
//         hash<double>()(s.revenue);
// }

// }

int main(int argc, char* argv[]) {
    (void) argc;
    (void) argv;

    {
        cout << "compare(1, 0): " << compare(1, 0) << endl;
        // 实例化出 int compare(const vector<int>&, const vector<int>&)

        vector<int> vec{1, 2, 3}, vec2{4, 5, 6};
        cout << "compare(vec, vec2): " << compare(vec, vec2) << endl;
    }

    {
        // int compare(const char (&p1)[3], const char (&p2)[4]);

        /* 
        * 为什么不调用第一个compare?
        * template.cc:10:5: note: candidate template ignored: deduced conflicting types for parameter 'T' ('char [3]' vs. 'char [4]')
        * int compare(const T &v1, const T &v2)
        * compare("hih", "mom")就可以调用这个compare了
        */
        cout << "compare('hi', 'mom'): " << compare("hi", "mom") << endl;

        const char *p1 = "hi", *p2 = "mom";
        cout << "compare(const char*, const char*): " << compare(p1, p2) << endl;
    }

    {
        Blob<int> ia;
        Blob<int> ia2 = { 0, 1, 2, 3,  4};
        // 编译会实例化成这样的一个类: template <> class Blob<int> { // ... }
    }
    
    {
        Foo<string> fs;      // 实例化static成员 Foo<string>::ctr 和 Foo<string>::count
        Foo<int> f1, f2, f3; // 三个对象共享static成员


        // static template
        Foo<int> fi;                 // 实例化Foo<int>类和static数据成员ctr
        // 类似任何其他成员函数，一个static成员函数只有在使用时才会初始化
        auto ct = Foo<int>::count(); // 实例化Foo<int>::count
        ct = fi.count();             // 使用Foo<int>::count
        cout << "ct: " << ct << endl;
        // ct = Foo::count();           // 错误, 使用哪个模板实例的count
    }

    {
        // debug delete
        {
            double *p = new double;
            DebugDelete d;
            d(p);
            int *ip = new int;
            DebugDelete()(ip);
        }

        {
            // void DebugDelete::operator()(int *p) const { delete p; }
            unique_ptr<int, DebugDelete> p(new int, DebugDelete());
            unique_ptr<string, DebugDelete> sp(new string, DebugDelete());
        }
    }

    {
        // 我们的hash函数计算所有三个数据成员的hash值，从而与我们为Sales_data定义的operator==是兼容的
        unordered_multiset<Sales_data> SDset;
        SDset.insert(Sales_data());
    }
    return 0;
}