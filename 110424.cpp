// Определите базовый класс Animal, который представляет животное и который содержит две приватные переменные: строку для хранения имени животного и целое число для хранения веса животного. Также определите общедоступную функцию print, которая выводит на консоль сообщение с указанием имени и веса объекта Animal.
// Также создайте два производных класса Cat (кошка) и Dog (собака), которые наследуются от класса Animal. В функции main создайте несколько объектов типа Cat и Dog и с помощью функции print выведите информацию об этих объектах на консоль.

// ВИРТУАЛЬНАЯ функция print должна быть определена во всех 3 классах. 
#include <iostream>
#include <vector>
#include <string>

class Animal
{
    protected:
        std::string name; 
        int weight;
    public:
        Animal(std::string name ,int weight):name(name), weight(weight){}

        virtual ~Animal(){};
        virtual void print() = 0;
};

class cat : public Animal
{
    protected:
        std::string breed;

    public:
        cat(std::string name ,int weight, std::string breed):Animal(name, weight), breed(breed){}
        virtual ~cat(){};
        virtual void print()
        {
            std::cout << "Cat: " << name << " " << weight << " " << breed << std::endl;
        } 
};

class dog : public Animal
{
    protected:
        std::string breed;

    public:
        dog(std::string name ,int weight, std::string breed):Animal(name, weight), breed(breed){}
        virtual ~dog(){};
        virtual void print()
        {
            std::cout << "Dog: " << name << " " << weight << " " << breed << std::endl;
        } 
};

int main()
{
   std::vector<Animal*> v;
   cat a("Murzik", 4, "breed");
   v.push_back(&a);
   dog b("name", 7, "breed");
   v.push_back(&b);
   
   for(int i = 0; i < v.size(); i++)
    {
        v[i] -> print();
    }

   return 0;
}