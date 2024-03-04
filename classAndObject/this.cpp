#include <iostream>

class Test
{
public:
    /*  写这个是为了区别形参的a和本类的a 也可以用this来区分 */
    Test(int a, int b):a(a), b(b)
    {
        /*  用来区分 */
        this->a = a;
        std::cout<<"构造：  this:"<<this;
    }
    Test clone()
    {
        return *this;
    }
    void show()
    {
        std::cout<<"hello world"<<std::endl;
    }

private:
    int a;
    int b;

};


int main()
{

    Test t(1,2);
    std::cout<<"t addres:"<<&t<<std::endl;

    t.clone().show();

    return 0;
}