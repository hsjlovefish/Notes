#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

using namespace std;

struct NoDtor {
    NoDtor() = default;
    ~NoDtor() = delete;
};

class PrivateCopy {
    PrivateCopy(const PrivateCopy&);
    PrivateCopy &operator=(const PrivateCopy&);
public:
    PrivateCopy() = default;
    ~PrivateCopy();
};

// 行为像值的类
class HasPtrValue {
    friend void swap(HasPtrValue&, HasPtrValue&);
public:
    HasPtrValue(const std::string &s = std::string()) :
        ps(new std::string(s)), i(0) {}

    HasPtrValue(const HasPtrValue &p) : 
        ps(new std::string(*p.ps)), i(p.i) {}

    HasPtrValue& operator=(const HasPtrValue &rhs) {
        auto newp = new string(*rhs.ps);  // 拷贝底层string
        delete ps;                        // 释放旧内存
        ps = newp;
        i = rhs.i;
        return *this;
    }

    ~HasPtrValue() { delete ps; }

private:
    std::string *ps;
    int i;
};

inline void swap(HasPtrValue &lhs, HasPtrValue &rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    // 与拷贝控制成员不同，swap并不是必要的。但是对于分配了资源的类，定义swap可能是一种很重要的优化手段
}

class HasPtrPointer {
public:
    HasPtrPointer(const std::string &s = std::string()) :
        ps(new std::string(s)), i(0), use(new std::size_t(1)) {}

    HasPtrPointer(const HasPtrPointer &p) :
            ps(p.ps), i(p.i), use(p.use) {
        ++(*use);
    }

    HasPtrPointer& operator=(const HasPtrPointer& rhs) {
        ++(*(rhs.use));
        if (--(*use) == 0) {
            delete ps;
            delete use;
        }
        ps = rhs.ps;
        i = rhs.i;
        use = rhs.use;
        return *this;
    }

    ~HasPtrPointer() {
        if (--(*use) == 0) {
            delete ps;
            delete use;
        }
    }

private:
    std::string *ps;
    int i;
    std::size_t *use;
};

class StrVec {
public:
    StrVec() :  // allocator成员进行默认初始化
       elements(nullptr), first_free(nullptr), cap(nullptr) {
    }

    StrVec(const StrVec&);

    StrVec(StrVec&&) noexcept;

    StrVec &operator=(const StrVec&);

    StrVec &operator=(StrVec&) noexcept;

    ~StrVec();

    void push_back(const std::string&);

    void push_back(std::string&&);

    size_t size() const {
        return cap - elements;
    }

    size_t capacity() const {
        return cap - elements;
    }
    
    std::string *begin() const {
        return elements;
    }

    std::string *end() const {
        return first_free;
    }

private:
    void chk_n_alloc() {
        if (size() == capacity()) {
            reallocate();
        }
    }

    std::pair<std::string*, std::string*> 
    alloc_n_copy(const std::string*, const std::string*);

    void free();
    void reallocate();

    static std::allocator<std::string> alloc;
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};

// static不属于类内成员, 必须在类外定义和初始化
std::allocator<std::string> StrVec::alloc;

StrVec::StrVec(const StrVec &s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

// 必须在类头文件的声明和定义中都指定noexceptr
StrVec::StrVec(StrVec &&s) noexcept :
        elements(s.elements), first_free(s.first_free), cap(s.cap) {
    s.elements = s.first_free = s.cap = nullptr;
    // 如果我们忘记了改变s.first_free，则销毁移后源对象就会释放掉我们刚刚移动的内存
}

StrVec &StrVec::operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec &StrVec::operator=(StrVec& rhs) noexcept {
    // 检测自赋值
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

StrVec::~StrVec() {
    free();
}

void StrVec::push_back(const std::string& s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

void StrVec::push_back(std::string &&s) {
    chk_n_alloc();
    alloc.construct(first_free++, std::move(s));
}

std::pair<std::string*, std::string*> 
StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free() {
    if (elements) {
        for (auto p = first_free; p != elements;) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::reallocate() {
    auto newcapcity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapcity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapcity;
}

int main(int argc, char* argv[]) {
    (void) argc;
    (void) argv;

    {
        // NoDtor nd;  // 错误，NoDtor的析构函数是删除的
        NoDtor *p = new NoDtor(); // 正确，但我们不能delete p
        // delete p;   // 错误 NoDtor的析构函数是删除的
        // 
    }

    {
        // 右值引用
        int i = 42;
        int &r = i;
        // int &&rr = i;      // 错误
        // int &r2 = i * 42;  // 错误
        const int &r3 = i * 42;
        int &&rr2 = i * 42;

        // int &&rr3 = rr2;   //  无法将右值绑定到左值
        int &&rr3 = std::move(rr2);
    }

    return 0;
}