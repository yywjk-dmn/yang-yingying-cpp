#include <iostream>
#include <map>
#include <set>

struct Student
{
    int id;
    std::string name;
};

int main()
{
    /* 或者std::peir<int, Student> s = {1, {1, "zhangsan"}} */
    std::pair<int, Student> s1 = std::make_pair<int, Student>(2, {2, "lisi"});
    std::pair<int, Student> s;
    s.first = 1;
    s.second = {1, "zhangsan"};

    std::set<std::pair<int, Student>> p;
    /* []会修改当前键值的value */
    std::map<int, Student> p1;
    p1[1] = {1, "zahngsan"};
    p1[2] = {2, "lisi"};
    p1[3] = {3, "wangwu"};
    p1[1] = {1, "yangyingying"};


    p.insert({3, {3, "zhangsan"}});
    p.insert(s);
    p.insert(s1);

    /* 重复的键值无法继续插入 */
    for (auto ite = p.begin(); ite != p.end(); ite++)
    {
        std::cout << ite->first << " " << ite->second.id << " " << ite->second.name << std::endl; 
    }
    /* 如果没有找到就返回end迭代器 */
    auto ite = p1.find(2);
    std::cout << ite->second.name << std::endl;


    return 0;
}