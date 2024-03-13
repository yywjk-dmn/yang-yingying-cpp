#include <iostream>
#include <queue>

/* 约瑟夫环问题 有13个人那就是13号活下来 有31个人就是1号活下来 */
int main()
{
    std::queue<int> q;

    for (int idx = 1; idx <= 13; idx++)
    {
        q.push(idx);
    }

    int count = 0;
    while (q.size() > 1)
    {
        count++;
        int num = q.front();
        q.pop();
        if (count == 3)
        {
            std::cout << num << "出局\n";
            count = 0;
        }
        else
        {
            q.push(num);
        }
    }
    std::cout << q.front() << "活了下来!\n";


    return 0;
}