#include <iostream>

#include <fstream>
#include <stdio.h>
#include <iomanip>

int main()
{
    int num = 300;
    printf("num:%d\n", num);
    /* 设置域宽 */
    printf("num:%12d\n", num);
    printf("num:%-12d666\n", num);

#if 0
    /* 通过构造函数来打开文件 */
    /* 判断文件是否打开成功 */
    const char * name = "./test.txt";
    std::ofstream ofs(name);

    if (ofs.is_open())
    {
        std::cout<<"open error"<<std::endl;
    }
#elif 0
    /* open成员函数打开文件 默认是ios::out | ios::trunc ios::app是以追加的方式读文件 */
    std::ofstream ofs;
    ofs.open(name, ios::out | ios::app);
#elif 1
    /* 写数据到文件 */

#endif
    return 0;
}