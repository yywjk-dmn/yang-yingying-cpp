#include "string.h"
#include <cstring>

stdString::stdString()
{
    std::cout<<"无参构造"<<std::endl;
    this->size = 0;
    this->capacity = 15;
    this->s = new char[this->capacity];
    memset(s, 0, 15);
}

stdString::stdString(const char *str)
{
    std::cout<<"有参构造"<<std::endl;
    this->size = strlen(str);
    if (size < 15)
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

stdString::stdString(const stdString &str)
{
    std::cout<<"拷贝函数"<<std::endl;
    this->capacity = str.capacity;
    this->size = str.size;
    this->s = new char[this->capacity];
    memset(s, 0, this->capacity);
    strcpy(this->s, str.s);
}

stdString::~stdString()
{
    std::cout<<"析构函数"<<std::endl;
    this->size = 0;
    this->capacity = 0;
    delete []this->s;
}

stdString stdString::operator+(const stdString &str)
{
    stdString result(*this);
    result.size = this->size + str.size;

    /* 不用扩容的时候 */
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

stdString &stdString::operator=(const stdString &str)
{
    this->size = str.size;
    this->capacity = str.capacity;
    delete []this->s;
    this->s = new char[str.capacity];
    strcpy(this->s, str.s);

    return *this;
}

stdString stdString::operator-(const stdString &str)
{
    stdString result(*this);
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

stdString& stdString::operator+=(const char c)
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

bool stdString::operator==(const stdString &str)
{
    return strcmp(this->s, str.s) == 0;
}

bool stdString::operator!=(const stdString &str)
{
    return !(this->s == str.s);
}

bool stdString::operator>(const stdString &str)
{
    return strcmp(this->s, str.s) > 0;
}

char &stdString::operator[](int index)
{
    return this->s[index];
}

stdString::operator int()
{
    return atoi(this->s);
}

stdString::operator double()
{
    return atof(this->s);
}

std::ostream& operator<<(std::ostream& os, const stdString& str)
{
    os<<str.s;
    return os;
}
/* 输入的重载 */
std::istream& operator>>(std::istream& is, stdString& str)
{
    char c = '\0';
    while ((c = getchar()) != '\n')
    {
        str += c;
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const stdStringList &list)
{
    for (int idx = 0; idx < list.size; idx++)
    {
        os<<list.string[idx]<<std::endl;
    }
    return os;
}

stdStringList::stdStringList()
{
    this->size = 0;
    this->capacity = 15;
    this->string = new stdString[this->capacity];
}

stdStringList::~stdStringList()
{
    this->size = 0;
    this->capacity = 0;
    delete []this->string;
}

void stdStringList::removeByIndex(int index)
{
    /* index是非法值 */
    if (index < 0 || index >= this->size)
        return;
    for (int idx = index; index < this->size - 1; idx++)
    {
        this->string[idx] = this->string[idx + 1];
    }
    this->size--;
}

stdStringList &stdStringList::operator+=(const stdString &str)
{
    if (this->size == this->capacity)
    {
        this->capacity *= 2;
        stdString *newPtr = new stdString[this->capacity];
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

stdStringList &stdStringList::operator-=(const stdString &str)
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

stdString &stdStringList::operator[](int index)
{
    return this->string[index];
}


