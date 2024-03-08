1.智能指针
    1.传统指针的问题：
        a.需要手动管理内存
        b.容易发生内存泄漏
        c.释放后容易出现野指针
    2.智能指针就是为了解决传统指针存在的问题
        a.auto_ptr    
            意思类似于  Point * ptr = new Point;   delete ptr;
            但是auto_ptr不能应用于数组 
        b.share_ptr（可以适用数组）
            多个shared_Ptr可以指向同一个对象 当最后一个shared_ptr在作用域范围内结束时 对象才会被自动释放  可以解决auto_ptr不能用于数组的缺陷
            （1）一个shared_ptr会对一个对象产生强引用
            （2）每个对象都有与之对应的强引用计数 记录着当前对象被多少个shared_ptr强引用 可以通过shaered_ptr的use_count函数来获得强引用计数
            （3）当有一个新的shared_ptr指向对象时 对象的强引用计数就会+1
            （4）当有一个shared_ptr销毁时（作用域结束） 对象的强引用计数就会-1
            （5）当一个对象的强引用计数为0时（没有任何的shared_ptr指向该对象） 对象就会（在内部）自动销毁
            shared_ptr的循环引用问题 每个对象都有两个sheard_ptr指向 导致无法将强引用计数清零 对象无法自动销毁
        c.weak_ptr
            指向对象的弱引用 主要用于解决shared_ptr的循环引用问题 （将shared_ptr指向对象的实线变为虚线）
        d .unique_ptr(可以适用于数组)
            (1)会对一个对象产生强引用 可以确保同一时间只有一个指针指向对象
            (2)当unique_ptr销毁时（作用域结束） 其指向的对象也就销毁了
            (3)可以使用std::move函数来转移unique_ptr的所有权
