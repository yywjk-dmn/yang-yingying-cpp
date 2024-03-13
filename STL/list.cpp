#include <iostream>
#include <list>

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
    std::list<int> l = {1, 2, 3, 4,5};
   
    auto ite = l.begin();
    for (int idx = 0; idx < 3; idx++)
    {
        ite++;
    }
    l.insert(ite, 99);

    /* 链表逆序 */
    l.reverse();

    return 0;
}