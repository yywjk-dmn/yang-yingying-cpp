#include <iostream>

class singleTon
{
public:
    /* 单例 */
    static singleTon* getInstance()
    {
        static singleTon s;
        return &s;

    }
    ~singleTon()
    {
        std::cout<<"析构：";
    }



private:
    singleTon()
    {
        std::cout<<"构造：";
    }


};

int main()
{
    singleTon *s1 = singleTon::getInstance();
    singleTon *s2 = singleTon::getInstance();
    singleTon *s3 = singleTon::getInstance();

    /* 输出的指针是一个 说明全局只创建了一个对象 这就是单例模式 */
    std::cout<<s1<<" "<<s2<<" "<<s3<<std::endl;

    return 0;
}