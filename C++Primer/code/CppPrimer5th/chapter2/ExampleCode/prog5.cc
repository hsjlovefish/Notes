int main() {

    // 2.4.3节
    int i = 0;
    int *const p1 = &i;  // 不能改变p1的值，顶层const
    const int ci = 42;  // 不能修改ci的值， 顶层const
    const int *p2 = &ci;  // 能修改p2的值，底层const
    const int *const p3 = p2; // 左边是底层const  右边是顶层const
    const int &r = ci; // 指向的值不能改变，底层const

    i = ci; // 正确：拷贝ci的值，ci是顶层const，对此操作无影响
    p2 = p3; // 正确：指向类型相同，虽然p3不可以改变指向，但p2可以改变指向，p3顶层const部分不影响这个操作。


    // int *p = p3; // 错误：p3底层const是指向const int， 而int *p不是，所以不能。
    p2 = p3; // 正确：p2和p3指向的东西都一样，都是底层const,p2指向可以修改
    p2 = &i; // 正确，int*能转换成const int*，指向常量的指针没有规定指向的对象必须是常量
    // int &r = ci; // 错误，ci是底层const，而r是普通的引用，ci是对常量的引用
    const int &r2 = i;  // 正确，对常量的引用对引用的对象是不是常量未作限定

    return 0;
}