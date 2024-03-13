#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>

#define BUFFER_SIZE 30

int main()
{
    int num = 300;
    printf("num:%d\n", num);
    /* 设置域宽 */
    printf("num:%12d\n", num);
    printf("num:%-12d666\n", num);

#if 1
    /* 通过构造函数来打开文件 */
    /* 判断文件是否打开成功 */
    const char * name = "./test.txt";
    std::ifstream ifs(name);

    if (!ifs.is_open())
    {
        std::cout<<"open error"<<std::endl;
    }
#elif 1
    /* open成员函数打开文件 默认是ios::out | ios::trunc ios::app是以追加的方式读文件 */
    std::ifstream ofs;
    ifs.open(name, ios::out | ios::app);
#elif 0
    /* 写数据到文件 */
    char buffer[BUFFER_SIZE];
    ifs<<buffer;

    std::cout <<buffer<<std::endl;

    /* 关闭文件 */
    ifs.close();
#elif 1
    ifs.read(buffer, sizeof(buffer) - 1);
    std::cout<<"buffer:"<<buffer<<std::endl;
#endif
    return 0;
}