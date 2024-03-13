#include <iostream>
#include <set>

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
    std::set<int> s;
    s.insert(2);
    s.insert(3);
    s.insert(1);

    s.insert(2);
    print(s);

    /* 查找 */
    auto ite = s.find(2);
    std::cout << *ite << std::endl;
    /* s.count就是检测该集合中有没有这个数字 有就返回1 没有就返回0 */
    std::cout << s.count(1) << std::endl;

    std::multiset<int> m;
    /* 不去重 */
    m.insert(1);
    m.insert(2);
    m.insert(2);
    /* 会将两个2都删除 */
    m.erase(2);

    return 0;
}