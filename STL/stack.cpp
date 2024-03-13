#include <iostream>
#include <stack>


int main()
{
    std::stack<int> s;
    for (int idx = 0; idx < 10; idx++)
    {
        s.push(idx);
    }
    while (s.empty() == false)
    {
        std::cout << s.top() << std::endl;;
        s.pop();
    }


    return 0;
}