1.模板
    1.模板的格式：
        template <typename/class T>  在这里class和typename是等价的 但是尽量使用typename来和class区分开来
    2.在模板中如果没有使用 是不会被实例出来的  程序运行的时候 才会被实例化
    3.模板的使用  float sum = add<float> (num1, num2)
    4.模板的声明和实现如果被分离到.h和.cpp中 会导致连接失败  所以必须放在同一个.hpp文件中

2.避免头文件重复包含
    #pragma once   宏保护更加简洁和可读性更高 但是依赖于编译器的支持 有的编译器可能不支持
    #ifndf  #define #endif 
    extern c    .h文件用来干什么   预处理 展开头文件 编译器将多个.o文件链接在一起生成一个可执行的.out的执行文件

3.函数模板 多参数模板

4.类模板 允许定义通用的类 类的数据成员的类型可以作为模板进行泛化


