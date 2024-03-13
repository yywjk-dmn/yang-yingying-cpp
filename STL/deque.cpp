#include <iostream>
#include <deque>

template<typename T>
void print(const T& vec)
{
    std::cout << vec.size() << std::endl;
    for (auto ite = vec.begin(); ite != vec.end(); ite++)
    {
        std::cout << *ite << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::deque<int> d;
    d.push_back(1);
    d.push_front(2);



    return 0;
}