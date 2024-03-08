#include <iostream>
#include <cstring>

class Point
{
public:
    //friend std::ostream &operator<<(std::ostream &);
private:
    int m_x;
    int m_y;
public:
    Point(int x, int y) : m_x(x), m_y(y){}
    Point operator+(const Point & p)
    {
        return Point(m_x + p.m_x, m_y + p.m_y);
    }
};

template <typename Item>
class Array
{
private:
    Item * m_data;
    int m_size;
    int m_capacity;
    const int dafault_value = 10;
private:
    bool checkIndexLegal(int index);
public:
    Array() : Array(dafault_value) {}

    Array(int capacity)
    {
        if (capacity <= 0)
        {
            capacity = dafault_value;
        }
        m_data = new Item[capacity];
        if (m_data == nullptr)
        {
            throw "new error";
        }

        memset(m_data, 0, sizeof(Item) * capacity);
        m_size = 0;
        m_capacity = capacity;

    }

    void add(Item value);
    void insert(int index, Item value);
    Item get(int index);
    void remove(int index);
    int size();
    Item operator[](int index);

};

/* 类模板在类外实现必须加上这一行 */
template <typename Item>
bool Array<Item>::checkIndexLegal(int index)
{
    if (index < 0 || index > this->m_capacity)
    {
        return false;
    }

    return true;
}

template <typename Item>
void Array<Item>::add(Item value)
{
    /* 扩容 */
    if (m_size == m_capacity)
    {
        m_size *= 2;
        m_capacity = m_size + 1;
    }

    m_data[m_size++] = value;
}

template <typename Item>
void Array<Item>::insert(int index, Item value)
{
}

template <typename Item>
Item Array<Item>::get(int index)
{
    if (!checkIndexLegal(index))
    {
        return ;
    }
    return this->m_data[index];
}

template <typename Item>
void Array<Item>::remove(int index)
{
}

template <typename Item>
int Array<Item>::size()
{
    return 0;
}

template <typename Item>
Item Array<Item>::operator[](int index)
{
    return this->m_data[index];
}

int main()
{
    Array<int> array;
    return 0;

}