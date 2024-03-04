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

private:
    char * s;
    int size;
    int capacity;

};

#endif
