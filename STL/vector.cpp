#include <iostream>
#include <vector>

void print(const std::vector<int>& vec)
{
    std::cout << vec.size() << std::endl;
    for (auto ite = vec.begin(); ite != vec.end(); ite++)
    {
        std::cout << *ite << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    std::cout << vec.size() << std::endl;
#if 0
    /* 遍历 方法1 */
    for (int idx = 0; idx < vec.size(); idx++)
    {
        std::cout << vec[idx] << std::endl;
    }
#elif 0 
    /* auto自动类型推导 迭代器都可以这么定义 */
    /* 动态数组的第一个元素 */
    auto ite = vec.begin();
    std::cout << *ite << std::endl;
    /* 动态数组的最后一个 是最后一个元素的后一个元素 所以需要-1 */
    auto ite_end = vec.end();
    std::cout << *(ite_end - 1) << std::endl;
    /* 动态数组的遍历 方法2（更推荐） */
    for (auto ite = vec.begin(); ite != vec.end(); ite++)
    {
        std::cout << *ite << std::endl;
    }
#elif 1
    std::vector<int> myvec(6);
    /* 插入数据 相当于尾插 */
    myvec.push_back(1);
    myvec.push_back(2);
    myvec.push_back(3);

    /* 尾部删除 */
    myvec.pop_back();
    print(myvec);
    /* 插入 */
    myvec.insert(myvec.begin() + 1, 99);
    print(myvec);
    /* 删除 */
    myvec.erase(myvec.begin() + 1);
    print(myvec);

    /* 取第一个位置上的元素 []和at的区别在于 在at中 如果越界 会抛出异常 
        但是[]不会抛出异常 所以在输出一个位置上的元素的时候 使用[]会存在越界的风险 */
    std::cout << myvec.at(1) << std::endl;
    std::cout << myvec[1] << std::endl;

    std::cout << myvec.capacity() << std::endl;
    /* 对动态数组的容量进行缩减到合适的容量 用来进行节省内存 */
    vec.shrink_to_fit();
    std::cout << myvec.capacity() << std::endl;
#endif

    return 0;
}