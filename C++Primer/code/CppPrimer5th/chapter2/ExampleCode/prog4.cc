int main() {

    /*-----------------------------------------------------*/
    /*2.4.2 指针和const*/
    // ① pointer to const
    const double pi = 3.14;
    // double *ptr = &pi; 错误，ptr是一个普通指针
    const double *cptr = &pi; // 正确
    // const double *ptr = 3.12; // 错误   double" 类型的值不能用于初始化 "const double *" 类型的实体
    // *cptr = 42; // 错误，不能给cptr指向的对象赋值

    // 指针的类型必须与其所指对象的类型一致，以下为第一种例外情况
    double dval = 3.14;
    cptr = &dval;  // 正确，但是不能通过cptr改变dval的值
    

    /*-----------------------------------------------------*/
    // ② const pointer
    int errNumb = 0;

    // const int i = 0;
    // int *const curErr = &i;  错误,不能引用i

    // 不能把errNumb的作为地址给curErr
    // invalid conversion from ‘int’ to ‘int*
    // int *const curErr = errNumb; 

    int *const curErr = &errNumb;

    const double pi1 = 3.14159;
    const double *const pip = &pi1;

    // *pip = 2.72; // 错误
    if (*curErr) {
        // errorHandler();
        *curErr = 0; // 把curErr所指的对象的值重置
    }

    return 0;
}