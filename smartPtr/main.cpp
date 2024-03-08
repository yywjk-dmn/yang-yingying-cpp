#include <iostream>
#include <memory>
using namespace std;

class Car;
class Person
{
public:
    Person()
    {
        cout<<"Person()"<<endl;
    }
    ~Person()
    {
        cout<<"~Person()"<<endl;
    }
public:
    shared_ptr<Car> m_car = nullptr;

};

class Car
{
public:
    Car()
    {
        cout<<"Car()"<<endl;
    }
    ~Car()
    {
        cout<<"~Car()"<<endl;
    }
public:
    /* 为了解决shared_ptr的循环引用的问题 引出了weak_ptr 弱引用 */
    weak_ptr<Person> m_person;

};


int main()
{
    shared_ptr<Person> person(new Person);
    shared_ptr<Car> car(new Car);

    person->m_car = car;
    car->m_person = person;  

    cout<<person->m_car.use_count()<<endl;
    cout<<car->m_person.use_count()<<endl;
    

    return 0;
}