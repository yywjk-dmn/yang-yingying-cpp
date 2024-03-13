#ifndef __STRING_H_
#define __STRING_H_

#include <iostream>
class stdString
{
public:
    stdString();
    stdString(const char * str);
    stdString(const stdString & str);
    ~stdString();

    stdString operator+(const stdString & str);
    stdString& operator=(const stdString & str);
    stdString operator-(const stdString & str);
    stdString& operator+=(const char c);

    bool operator==(const stdString& str);
    bool operator!=(const stdString& str);
    bool operator>(const stdString& str);

    char& operator[](int index);
    operator int();
    operator double();

    friend std::ostream& operator<<(std::ostream& os, const stdString& str);
    friend std::istream& operator>>(std::istream& is, stdString& str);
private:
    char * s;
    int size;
    int capacity;
};
std::ostream& operator<<(std::ostream& os, const stdString& str);
std::istream& operator>>(std::istream& is, stdString& str);

class stdStringList
{
public:
    stdStringList();
    ~stdStringList();

    void removeByIndex(int index);
    stdStringList& operator+=(const stdString& str);
    stdStringList& operator-=(const stdString& str);
    stdString& operator[](int index);

    friend std::ostream& operator<<(std::ostream& os, const stdStringList& list);

private:
    stdString *string;
    int size;
    int capacity;
};

std::ostream& operator<<(std::ostream& os, const stdStringList& list);


#endif
