#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    (void) argc;
    (void) argv;

    {
        shared_ptr<string> sp;
        // false   0
        cout << sp.unique() << " " << sp.use_count() << endl;
    }

    {
        // make_shared
        shared_ptr<int> p3 = make_shared<int>(42);
        shared_ptr<string> p4 = make_shared<string>(10, '9');
        shared_ptr<int> p5 = make_shared<int>();
    }

    {
        // copy assign
        auto p = make_shared<int>(42);
        auto q(p);
        cout << *q << endl;
    }

    {
        // new delete
        int i, *pi1= &i, *pi2 = nullptr;;
        double *pd = new double(33), *pd2 = pd;
        // delete i; // 错误，不是一个指针
        // delete pi1; // 未定义，pi1纸箱一个局部变量
        delete pd;  // 正确
        // delete pd2; // 未定义，double free
        delete pi2; // 正确 释放一个空指针总是没有错误的

        const int *pci = new const int(1024);
        delete pci;
    }

    {
        // // shared_ptr.get()
        // shared_ptr<int> p(new int(42));
        // int *q = p.get(); // 正确，但不要去释放q
        // {
        //     shared_ptr<int>(q); // 未定义，两个独立的shared_ptr指向相同的内存
        // }
        // int foo = *p;
        // cout << foo << endl;  // 42，最好不要这样玩。是去读一块野内存
    }

    {
        int i = 42;
        auto p1 = make_shared<int>(i);
        auto p2 = make_shared<int>(i);
        (*p1)++;
        (*p2)++;
        cout << "p1 " << *p1 << " p2 " << *p2 << endl;
    }

    {   
        // unique_ptr
        unique_ptr<double> p1;
        unique_ptr<int> p2(new int(42));

        unique_ptr<string> p3(new string("jsh666"));
        // unique_ptr<string> p4(p3); // 错误
        unique_ptr<string> p5;
        // p5 = p4;                   // 错误
    }

    {
        unique_ptr<string> p1(new string("jsh666"));
        unique_ptr<string> p2(p1.release());  // p1放起，转移给p2，p1置为空
        if (p1 == nullptr) {
            cout << "p1 == nullptr" << endl;
        }
        auto p = p2.release(); // p类型是unique_ptr
    }

    {
        auto p = make_shared<int>(42);
        weak_ptr<int> wp(p);
        if (shared_ptr<int> np = wp.lock()) { // 如果np不为空则条件成立
            // 在if中，使用np访问共享对象是安全
        }
    }

    {
        // allocator
        allocator<string> alloc; // 类似vector，这是一个模板
        auto const p = alloc.allocate(10); 

        auto q = p;
        alloc.construct(q++, "wuhu~");
        alloc.construct(q++); // 空string
        alloc.construct(q++, 10, 'c');
        alloc.construct(q++, "jsh666");

        // 使用原始内存(未构造的内存)是有问题的
        cout << *p << endl;
        // cout << *q << endl;   // 有大问题

        // 销毁
        while (q != p) {
            alloc.destroy(--q);
        }

        // p指针不能为空，且必须指向allocate分配的内存。
        // 而且，传递给deallocate的大小参数必须与初始化时一致
        alloc.deallocate(p, 10);
    }

    {
        allocator<int> alloc; // 类似vector，这是一个模板
        vector<int> vi(10000, -1);
        auto p = alloc.allocate(vi.size() * 2);
        auto q = uninitialized_copy(vi.begin(), vi.end(), p);
        uninitialized_fill_n(q, vi.size(), 42);
        while (q != p) {
            alloc.destroy(--q);
        }
        alloc.deallocate(p, vi.size() * 2);
    }

    return 0;
}