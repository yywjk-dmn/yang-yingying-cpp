#ifndef __STDMYSTRING_H_
#define __STDMYSTRING_H_

#include <iostream>
class myStringList;
class stdMyString
{
public:
    stdMyString();
    stdMyString(const char * str);
    stdMyString(const stdMyString & str);
    ~stdMyString();

    stdMyString operator+(const stdMyString & str);
    stdMyString& operator=(const stdMyString& str);
    stdMyString operator-(const stdMyString& str);
    stdMyString& operator+=(const char c);

    bool operator==(const stdMyString& str);
    bool operator!=(const stdMyString& str);
    bool operator>(const stdMyString& str);

    char& operator[](int index);
    operator int();
    operator double();

    //bool operator&&(const stdMyString& str);
    myStringList split(const stdMyString& str);
    friend std::ostream& operator<<(std::ostream& os, const stdMyString& str);
    friend std::istream& operator>>(std::istream& is, stdMyString& str);
private:
    char * s;
    int size;
    int capacity;

};
std::ostream& operator<<(std::ostream& os, const stdMyString& str);
std::istream& operator>>(std::istream& is, stdMyString& str);


class myStringList
{
public:
    myStringList();
    ~myStringList();

    void removeByIndex(int index);
    myStringList& operator+=(const stdMyString& str);
    myStringList& operator-=(const stdMyString& str);
    stdMyString & operator[](int index);

    friend std::ostream& operator<<(std::ostream& os, const myStringList& list);
    friend std::istream& operator>>(std::istream& is, myStringList& list);

private:
    stdMyString *string;
    int size;
    int capacity;
};

std::ostream& operator<<(std::ostream& os, const myStringList& list);

#endif