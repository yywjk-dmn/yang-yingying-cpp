#include <iostream>

class complex
{
public:
    friend std::ostream& operator<<(std::ostream& os, const complex& c);
    friend std::istream& operator>>(std::istream& is, complex& c);
    complex(int real, int vir):real(real), vir(vir){}

    complex operator+(const complex& c)
    {
        complex result(0, 0);
        result.real = this->real + c.real;
        result.vir = this->vir + c.vir;

        return result;

    }

    complex operator-(const complex& c)
    {
        complex result(0, 0);
        result.real = this->real - c.real;
        result.vir = this->vir - c.vir;

        return result;
    }

    /* 前置++ */
    complex operator++()
    {
        this->real++;
        this->vir++;
        return *this;
    }

    /* 占位参数 用来重载 后置++ a++  */
    complex operator++(int)
    {
        complex temp = *this;
        this->real++;
        this->vir++;
        return temp;
        
    }


private:
    int real;
    int vir;

};

std::ostream& operator<<(std::ostream& os, const complex& c)
{
    if (c.vir != 0)
        std::cout<<c.real<<"+"<<c.vir<<"i"<<std::endl;
    else
        std::cout<<c.real<<std::endl;

    return os;

}
std::istream& operator>>(std::istream& is, complex& c)
{
    is>>c.real>>c.vir;
    return is;
}

int main()
{
    
    complex c(2, 0);
    complex c1(3, 0);
    complex c2 = c + c1;

    /**/
    std::cin>>c2;
    std::cout<<c2<<std::endl;
    return 0;
}