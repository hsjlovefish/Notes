// i的类型是整型常量
// i和j必须定义在函数体之外
int j = 0;
constexpr int i = 42; 
int main() {

    // 2.4.4节 constexpr和常量表达式代码
    const int max_files = 20; // 是
    const int limit = max_files + 1; // 是
    int staff_size = 27;  //不是
    // const int sz = get_size(); // 不是，get_size运行时才能获得到，所以不是常量表达式

    constexpr int mf = 20;  // 是
    constexpr int limit = mf + 1; // 是
    // constexpr int sz = size();   // 只有当size是一个constexpr函数时才是正确声明

    const int *p = nullptr; // p是一个指向整型常量的指针
    constexpr int *q = nullptr; //q是一个指向整数的常量指针

    constexpr int *np = nullptr; // np是一个指向整数的常量指针，其值为空
    
    constexpr const int *p = &i; // p是指向整型常量的常量指针
    // constexpr int *p1 = &i; // 错误,p1为指向常量的常量指针不能指向整型常量
    constexpr int *p1 = &j; // p1常量指针，指向整数j


    return 0;
}