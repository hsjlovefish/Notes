int f(){return 0;}

int main() {
    // 2.5.3 decltype类型指示符
    const int ci = 0, &cj = ci;
    decltype(ci) x = 0;
    decltype(cj) y = x;
    // decltype(cj) z; // 错误，z是引用，必须初始化

    decltype(f()) sum = x;

    int i = 42, *p = &i, &r = i;
    decltype(r + 0) b; // 正确，加法的结果是int，因此b是一个未初始化的int
    // decltype(*p) c; // 错误：c是int &，必须初始化

    // decltype((i)) d;  // 错误：d是int&，必须初始化 
    decltype(i) e;    // 正确：e是一个(未初始化的)int
}