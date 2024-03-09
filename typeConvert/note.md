1.类型转换：
    static_cast
    dynamic_cast
    reinterpret_cast
    const_cast

(1) const_cast  主要功能是进行强转 将const 属性转换为非const 属性
(2) dynamic_cast 运行的时候有安全检测 如果是指向了错误的地址 就会将结果置为NULL 地址为0
(3) static_cast  非const转成const 运行时没有安全检测
(4) reinterpret_cast  没有安全检测 

总结：只有dynamic_cast有安全检测 其中static_cast(将非const转成const)和const_cast(将const转成非const)刚好相反 