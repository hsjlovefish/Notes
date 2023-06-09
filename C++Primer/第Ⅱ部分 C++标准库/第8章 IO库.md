# 第8章
# 目录
1. IO类
   * IO对象无拷贝或赋值
   * 条件状态
   * 管理输出缓冲
2. 文件输入输出
   * 使用文件流对象
   * 文件模式
3. string流
    * 使用istringstream
    * 使用ostringstream
* 小结
* 术语表

> C++语言不直接处理输入输出,而是通过一族定义在标准库中的类型来处理IO。这些类型支持从设备读取数据、向设备写入数据的IO操作，设备可以是文件、控制台窗口等。还有一些类型允许内存IO，即，从string读取数据，向string写入数据
> 之前章节学习过的IO库设施: istream. ostream. cin. cout. cerr. >>. <<. getline函数

## 1.IO类型
* `IO库类型和头文件`
    ```cpp
    // 有些应用程序需要读写宽字符支持的语言

    // header
    iostream
    // type
    istream, wistream
    ostream, wostream
    iostream, woiotream

    fstream
    ifstream, wifstream
    ofstream, wofstream
    fstream, wfstream

    sstream
    istringstream, wistringstream
    ostringstream, wostringstream
    stringstream, wstringstream

    // wcin wcout wcerr
    ```

* `IO类型间的关系`
    1. io类间有继承关系，比如`ifstream`与`istringstream`都继承自`istream`

### 1.1 IO对象无拷贝或赋值
* `注意`
    1. 不能拷贝IO对象，在函数声明中需写成引用方式传递或返回；同时，读写会改变流状态，因此也不能声明为const

### 1.2 条件状态
* `条件状态`
    1. IO可能会发生错误，但IO类定义了一些函数和标志，可以帮助访问和操纵流的`条件状态`
    2. 比如strm::goodbit  badbit，具体见`书P279页表8.2`
    3. 确定一个流对象的状态的最简单的方法是将它当作一个条件来使用

* `查询流的状态`
    1. 将流作为条件使用，只能告诉流是否有效，而无法告诉具体发生了什么。有时也需要知道流为什么失败
    2. IO库定义了一个与机器无关的`iostate类型`，它提供了表达流状态的完整功能。badbit，failbit，eofbit，failbit

* `管理条件状态`
    1. 流对象的`rdstate`成员返回一个iostate值，对应流的当前状态
    2. `setstate`操作将给定条件尾置位，表示发生了错误
    3. `clear不接受参数的版本`清除(复位)所有错误标志位
    ```cpp
    auto old_state = cin.rdstate(); // 记住cin当前状态
    cin.clear();                    // 使cin有效
    process_intput(cin);            // 使用cin
    cin.setstate(old_state);        // 将cin置为原有状态

    // 复位con的failbit和badbit，eofbit保持不变
    cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit);
    ```

### 1.3 管理输出缓冲
* `缓冲刷新的原因`
    1. 程序正常结束
    2. 缓冲区满
    3. endl显式刷新
    4. 用操作符unitbuf设置流内部的状态，来清空缓冲区。默认cerr是设置unitbuf的，因此其立即刷新
    5. 一个输出流可能被关联到另一个流。当读写被关联的流时，关联到的流的缓冲区立即刷新。默认cin和cerr被关联到cout，读cin或写cerr都会导致cout的缓冲区被刷新
    ```cpp
    // 每个输出流都管理一个缓冲区,用来保存程序读写的数据.这是因为由于设备的写操作可能很耗时,允许操作系统将多个输出操作组合为单一的设备写操作可以带来很大的性能提升
    os << "xxxxx: ";  // 后面在用输出，可以一起刷写
    ```

* `刷新输出缓冲区`
    1. 类似endl的操纵符：flush、ends
    ```cpp
    cout << "hi" << endl;  // 输出hi加换行
    cout << "hi" << flush; // 输出hi
    cout << "hi" << ends;  // 输出hi和空字符
    ```

* `unitbuf操作符`
    ```cpp
    cout << unitbuf; // 之后每次输出都会立即刷新
    cout << nounitbuf;  // 回到cout原本的模式

    // 注意：如果程序崩溃，输出缓冲区不会被刷新。不用浪费时间看日志为什么没执行，可能执行了，但没刷新
    ```

* `关联输入和输出流`
    ```cpp
    // 通过tie关联
    cin.tie(&cout);
    // 感觉这个没啥用啊
    ```

## 2.文件输入输出
* `fstream`:iftream ofstream fstream
    ```cpp
    fstream fstrm;
    fstream fstrm(s);
    fstream fstrm(s, mode); // 以指定模式打开文件
    fstrm.open(s)
    fstrm.close()
    fstrm.is_open()
    ```

### 2.1 使用文件流对象
```cpp
iftream in(infile);   // 构造一个ifstream并打开给定文件
ofstream out;         // 输出文件流未关联到任何文件
```

* `用 fstream 代替 iostream&`
    1. fstream继承自iostream，即接受iostream类型引用（或指针）参数的函数，可以用一个对应的fstream类型来调用

* `成员函数open和close`
    ```cpp
    ofstream out;
    out.open(file); // 可以用open绑定为关联文件的ofstream
    if (out) // 检查open是否成功

    // 对于一个已经打开的文件流，需要先close再open。不然打开就会失败
    ```

* `自动构造和析构`
    1. fstream对象被销毁时，close会自动被调用

### 2.2 文件模式
* `文件模式file mode`
    ```cpp
    // 读
    in
    // 写
    out
    // 每次写操作前均定位到文件末尾
    app
    // 打开文件后立即定位到文件末尾
    ate
    // 截断文件
    trunc
    // 以二进制方式进行IO
    binary

    // other
    // 只有out被设定时才能设定truct
    // 即使没有指定trunc,以out模式打开的文件也会被截断.为了保留之前的模式,需要同事指定app模式
    // ate和binary模式可以用于任何类型的文件流对象,且可以与其他任何文件模式组合使用

    // ifstream默认以in模式打开
    // ofstream默认以out模式打开
    // fstream默认以in和out模式打开
    ```

* `以out模式打开文件会丢弃已有数据`
    ```cpp
    // 都会截断文件
    ofstream out(file, ofstream::out | ofstream::trunc)
    ofstream out(file, ofstream::out | ofstream::trunc)
    
    // 不会截断文件
    ofstream out(file, ofstream::out | ofstream::app)
    ```

* `每次调用open时都会确定文件模式`
    1. 每次打开文件，都要设置文件模式，要么显式，要么隐式。未指定就使用默认值
    ```cpp
    ofstream out;
    out.open(file, ofstream::app);
    out.close();
    ```

## 3.string流
```cpp
// sstream定义了三个类型支持内存IO，这些类型可以向string写入数据，从string读取数据，就像string是一个IO流一样
// istringstream ostringstream stringstream

sstream ss;   
sstream (s);  
ss.str()      // 返回strm保存的string的拷贝
ss.str(s)     // 将string拷贝到ss中
```

### 3.1 使用istringstream
```cpp
struct PersonInfo {
    string name;
    vector<string> phones;
};

string line, word;
vector<PersonInfo> people;
while (getline(cin, line)) {
    PersonInfo info;
    istringstream record(line);
    record >> info.name;
    while (record >> word) {
        info.phones.push_back(word);
    }
    people.push_back(info);
}
```

### 3.2 使用ostringstream
```cpp
vector<string> people;
for (const string &entry : people) {
    ostringstream formatted;
    formatted << " " << entry;
}
cout << formatted.str() << endl;
```

## 小结
## 术语表