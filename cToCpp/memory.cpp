#include <iostream>
#include <cstdlib>
#include <cstring>


int main()
{
    /* 指针数组 */
    char ** str = (char **)malloc(sizeof(char*) * 10);
    if (str == NULL)
        return -1;

    for (int idx = 0; idx < 3; idx++)
    {
        str[idx] = (char*)malloc(sizeof(char) * 10);
        if (str[idx] == NULL)
        {
            std::cout<<"malloc error\n";
            return -1;
        }

        strcpy(str[idx], "hello");
    }

    for (int idx = 0; idx < 3; idx++)
    {
        std::cout<<str<<std::endl;
    }

    for (int idx = 0; idx < 3; idx++)
    {
        free(str[idx]);
    }

    free(str);


    return 0;
}

int main()
{
    /* 等同于malloc */
    /* 1.不需要计算内存的大小
       2.不需要岁指针进行转换
       3.不需要判断指针是否为空：抛出异常，终止程序 */
    /* []申请数组 */
    char * s = new char[10];
    strcpy(s, "hello");
    std::cout<<s<<std::endl;
    /* 代表释放数组 */
    delete []s;
    
    /* 申请一个 ()代表赋值 */
    int *a = new int(10);
    std::cout<<*a<<std::endl;
    /* 直接释放 */
    delete a;

    /* 类似于上面的malloc程序 定义一个二维数组 */
    char **s = new char*[3];
    for (int idx = 0; idx < 3; idx++)
    {
        char * s = new char[10];
        strcpy(&s[idx], "hello");
    }
    for (int idx = 0; idx < 3; idx++)
    {
        std::cout<<&s[idx]<<std::endl;
    }
    for (int idx = 0; idx < 3; idx++)
    {
        //delete []s[idx];
    }

    delete []s;
    
    


    return 0;
}