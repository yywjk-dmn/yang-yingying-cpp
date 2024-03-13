#include <iostream>
#include <forward_list>

int main()
{
    std::forward_list<int> l;
    l.push_front(1);

    /* 单链表回不了头 并没有重载-- 而且没有尾插  */
    auto ite = l.end();



    return 0;
}