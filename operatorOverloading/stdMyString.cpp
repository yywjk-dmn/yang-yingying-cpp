#include "stdMyString.h"
#include <cstring>

stdMyString::stdMyString()
{
    std::cout<<"无参构造"<<std::endl;
    this->size = 0;
    this->capacity = 15;
    this->s = new char[this->capacity];
    memset(s, 0, 15);
}

stdMyString::stdMyString(const char *str)
{
    std::cout<<"有参构造"<<std::endl;
    this->size = strlen(str);
    if (size <= 15)
    {
        this->capacity = 16;
        this->s = new char[this->capacity];
        memset(s, 0, 15);
        strcpy(this->s, str);

    }
    else
    {
        this->capacity = this->size + 1;
        this->s = new char[this->capacity];
        memset(s, 0, this->capacity);
        strcpy(this->s, str);

    }
}

stdMyString::stdMyString(const stdMyString &str)
{
    std::cout<<"拷贝构造"<<std::endl;
    this->capacity = str.capacity;
    this->size = str.size;
    this->s = new char[this->capacity];
    memset(s, 0, this->capacity);
    strcpy(this->s, str.s);
    
}

stdMyString::~stdMyString()
{
    std::cout<<"析构函数"<<std::endl;
    this->size = 0;
    this->capacity = 0;
    delete []this->s;
}

stdMyString stdMyString::operator+(const stdMyString &str)
{
    stdMyString result(*this);
    result.size = this->size + str.size;

    /* 不需要扩容 */
    if (result.size < result.capacity)
    {
        strcat(result.s, str.s);
    }
    else
    {
        result.capacity = result.size + 1;
        char *newStr = new char[result.capacity];
        strcpy(newStr, this->s);
        strcat(newStr, str.s);
        delete []result.s;
        result.s = newStr;

    }
    return result;
}

/* 避免浅拷贝  return的是一个左值 左值不可以直接把内存给别人 所以只能发生拷贝 所以为了避免发生拷贝函数 就用了引用 */
/* 用了拷贝函数 说明就会多了一个对象 */
stdMyString& stdMyString::operator=(const stdMyString &str)
{
    this->size = str.size;
    this->capacity = str.capacity;
    delete []this->s;
    this->s = new char[str.capacity];
    strcpy(this->s, str.s);

    return *this;
}

stdMyString stdMyString::operator-(const stdMyString &str)
{
    stdMyString result(*this);
    /* 字符串匹配 */
    char * deleteS = strstr(result.s, str.s);
    while (deleteS != nullptr)
    {
        char * backS = deleteS + str.size;
        while (*backS != '\0')
            *deleteS++ = *backS++;
        *deleteS = '\0';
        
        deleteS = strstr(result.s, str.s);
    }
     
    return result;
}

stdMyString& stdMyString::operator+=(const char c)
{
    if (this->size + 1 == this->capacity)
    {
        this->capacity *= 2;
        char *newStr = new char[this->capacity];
        strcpy(newStr, this->s);
        delete []this->s;
        this->s = newStr;
    }

    this->s[this->size] = c;
    this->s[this->size + 1] = '\0';
    this->size++;
    return *this;
}

bool stdMyString::operator==(const stdMyString &str)
{

    return strcmp(this->s, str.s) == 0;
}

bool stdMyString::operator!=(const stdMyString &str)
{
    return !(*this == str);
}

bool stdMyString::operator>(const stdMyString &str)
{
    return strcmp(this->s, str.s) > 0;
}

char &stdMyString::operator[](int index)
{
    return this->s[index];
    // TODO: 在此处插入 return 语句
}

stdMyString::operator int()
{
    return atoi(this->s);
}

stdMyString::operator double()
{
    return atof(this->s);
}

myStringList stdMyString::split(const stdMyString &str)
{
    stdMyString temp(*this);
    myStringList list;
    
    char *s = strtok(temp.s, str.s);
    while (s != nullptr)
    {
        list += s;
        s = strtok(nullptr, str.s);
    }
    return list;
}

// bool stdMyString::operator&&(const stdMyString &str)
// {
//     return this->size != 0 && str.size != 0;
// }

std::ostream &operator<<(std::ostream &os, const stdMyString &str)
{
    os<<str.s;
    return os;
}

std::istream &operator>>(std::istream &is, stdMyString &str)
{
    char c = '\0';
    while ((c = getchar()) != '\n')
    {
        str += c;
    }
    return is;
}


myStringList::myStringList()
{
    this->size = 0;
    this->capacity = 15;
    this->string = new stdMyString[this->capacity];
}

myStringList::~myStringList()
{
    this->size = 0;
    this->capacity = 0;
    delete []this->string;
}

void myStringList::removeByIndex(int index)
{
    if (index < 0 || index >= this->size)
        return;
    for (int idx = index; idx < this->size - 1; idx++)
    {
        this->string[idx] = this->string[idx + 1];
    }
    this->size--;
}

myStringList &myStringList::operator+=(const stdMyString &str)
{
    if (this->size == this->capacity)
    {
        this->capacity *= 2;
        stdMyString *newPtr = new stdMyString[this->capacity];
        for (int idx = 0; idx < this->size; idx++)
        {
            newPtr[idx] = this->string[idx];
        }
        delete []this->string;
        this->string = newPtr;
    }
    this->string[this->size++] = str;
    return *this;

}
myStringList &myStringList::operator-=(const stdMyString &str)
{
    for (int idx = 0; idx < this->size; idx++)
    {
        if (this->string[idx] == str)
        {
            removeByIndex(idx);
            idx--;
        }

    }
    return *this;
}
stdMyString &myStringList::operator[](int index)
{
    return this->string[index];
}
std::ostream &operator<<(std::ostream &os, const myStringList &list)
{
    for (int idx = 0; idx < list.size; idx++)
    {
        os<<list.string[idx]<<std::endl;
    }
    return os;
}