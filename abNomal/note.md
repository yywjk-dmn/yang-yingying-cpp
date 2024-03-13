异常：

异常的抛出声明：
1. void func() 或者 void func() noexcept(false)  可能抛出任何类型的异常
2. void func() throw() 或者 void func()  noexcept 或者 void func() noexcept(true) 不会抛出异常
3. void func() throw(int, double)  会抛出int和double类型的异常

抽象类：
1. 具有纯虚函数的类叫做抽象类  （纯虚函数：虚函数的初始化为0）
2. 抽象类不能实例化对象

安全检测不算异常