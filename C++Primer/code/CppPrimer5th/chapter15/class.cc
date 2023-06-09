#include <iostream>
#include <memory>
#include <set>

using namespace std;

class Base {
public:
    virtual int fcn() {
        cout << __LINE__ << " " << __func__ << endl;
        return 0;
    }
};

class D1 : public Base {
public:
    int fcn(int) {  // 会隐藏fcn
        cout << __LINE__ << " " << __func__ << endl;
        return 0;
    }

    virtual void f2() {
        cout << __LINE__ << " " << __func__ << endl;
    }
};

class D2 : public D1 {
public:
    int fcn(int) {
        cout << __LINE__ << " " << __func__ << endl;
        return 0;
    }

    int fcn() {
        cout << __LINE__ << " " << __func__ << endl;
        return 0;
    }

    void f2() {
        cout << __LINE__ << " " << __func__ << endl;
    }
};

// 克隆模式？
class Quote {
public:
    // 克隆左值
    virtual Quote* clone() const & { return new Quote(*this); }
    virtual Quote* clone() && { return new Quote(*this); }
    int isbn() {
        // just for complie
        return 42;
    };
};

class Bulk_quote : public Quote {
    Bulk_quote* clone() const & { return new Bulk_quote(*this); }
    Bulk_quote* clone() && { return new Bulk_quote(*this); }
};

class Basket {
public:
    void add_item(const Quote& sale) {
        items.insert(std::make_shared<Quote>(sale.clone()));
    }

    void add_item(const Quote&& sale) {
        items.insert(std::make_shared<Quote>(std::move(sale).clone()));
    }

private:
    static bool compare(const std::shared_ptr<Quote> &lhs, 
            const std::shared_ptr<Quote> &rhs) {
        return lhs->isbn() < rhs->isbn();
    }
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items;
};

int main(int argc, char* argv[]) {
    (void) argc;
    (void) argv;

    {
        Base bobj;
        D1 d1obj;
        D2 d2obj;

        Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
        bp1->fcn();   // base::fcn
        bp2->fcn();   // base fcn    // 通过基类调用隐藏的虚函数
        bp3->fcn();

        D1 *d1p = &d1obj;
        D2 *d2p = &d2obj;
        // bp2->f2(); // 错误，Base没有f2的成员
        d1p->f2();
        d2p->f2();

        Base *p1 = &d2obj;
        D1 *p2 = &d2obj;
        D2 *p3 = &d2obj;
        // p1->fcn(42);  错误，Base中没有接受一个int的fcn
        p2->fcn(42);
        p3->fcn(42);
    }


    return 0;
}