#include <iostream>

int sum(int n)
{
    int total = 0;
    for (int i = 1; i <= n; i++)
    {
        total += i;
    }
    return total;
}

int main()
{
    std::cout<<"Input a interge:";
    int n;
    std::cin>>n;
    std::cout<<"Total:"<<sum(n)<<std::endl;
    return 0;
}