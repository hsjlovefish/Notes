int main() {
    // 2.5.2 auto类型说明符
    int i = 0, &r = i;
    auto a = r;   // a是整型

    const int ci = i, &cr = ci;
    auto b = ci; // b是整数(ci的顶层const特性被忽略掉了)
    auto c = cr; // c是一个整数 (cr是c的别名)
    auto d = &i;  // d是一个整型指针(整数的地址就是指向整数的指针)
    auto e = &ci;  // e是一个指向整数常量的指针(对常量对象取地址是一种底层const)
    const auto &f = ci; // f 是 const int

    auto &g = ci; // g是一个整型常量引用(就是const int &g)，绑定到ci
    // auto &h = 42; // 错误：不能为非常量引用绑定到字面值
    const auto &j = 42; // 正确，可以将常量引用绑定字面值

    auto k = ci, &l = i;     // 对
    auto &m = ci, *p = &ci;  // 对
    // auto &n = i, *p2 = &ci;  // 错误，i是int ，ci是const int

    return 0;
}