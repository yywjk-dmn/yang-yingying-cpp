#include <iostream>
#include <stdio.h>
#include <string.h>

struct Student
{
    int id;
    char name[20];
};

void printS(Student *ps)
{
    std::cout<<"id = "<<ps->id<<", name = "<<ps->name<<std::endl;
}

void getStudent1(Student **pstu)
{
    Student *tmp = (Student *)malloc(sizeof(Student));
    if (tmp == NULL)
    {
        *pstu = NULL;
        return;
    }

    tmp->id = 10;
    strcpy(tmp->name, "yang");

    *pstu = tmp;
}

/* 指针引用 */
void getStudent2(Student* &pstu)
{
    pstu = (Student *)malloc(sizeof(Student));
    if (pstu == NULL)
    {
        return;
    }

    pstu->id = 10;
    strcpy(pstu->name, "yang");

}

int main()
{
    Student *pstu1 = NULL;
    getStudent1(&pstu1);
    printS(pstu1);

    Student *pstu2 = NULL;
    getStudent1(&pstu2);
    printS(pstu2);



    return 0;
}
