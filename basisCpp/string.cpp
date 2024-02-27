#include <iostream>
#include <string>

int main()
{

    std::string s;

    /* 字符串拷贝直接等于 */
    s = "helloworld";
    /* 相当于直接拼接 */
    std::string s1 = s + "hihihi";
    std::cout<<s<<std::endl;
    /* 字符串的大小 */
    std::cout<<s1.size()<<std::endl;
    /* 字符串的容积 */
    std::cout<<s1.capacity()<<std::endl;
    

    s += "asd";
    s.push_back('p');
    std::cout<<s<<std::endl;

    s = "nihao";
    std::cout<<s<<std::endl;

    if (s == s1)
    {
        std::cout<<"equal"<<std::endl;
    }
    else
    {
        std::cout<<"not equal"<<std::endl;

    }

    /* 找第一个字母 maybe */
    std::cout<<s.find_first_not_of("ello")<<std::endl;

    return 0;
}