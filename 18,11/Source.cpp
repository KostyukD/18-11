#include <iostream>
#include <cstring>  

using namespace std;

class Pet
{
public:
    Pet(const char* name) 
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    virtual void Sound() const = 0;

    virtual void Show() const 
    {
        cout << "Pet's name: " << name << endl;
    }

    virtual void Type() const = 0;

    virtual ~Pet()
    {
        delete[] name;
    }

protected:
    char* name;
};

class Dog : public Pet 
{
public:
    Dog(const char* name) : Pet(name) {}

    void Sound() const override 
    {
        cout << name << " says: Woof!" << endl;
    }

    void Show() const override 
    {
        Pet::Show();
        cout << "Type: Dog" << endl;
    }

    void Type() const override 
    {
        cout << "Breed: Dalmatian" << endl;
    }
};

class Cat : public Pet
{
public:
    Cat(const char* name) : Pet(name) {}

    void Sound() const override 
    {
        cout << name << " says: M'ow!" << endl;
    }

    void Show() const override 
    {
        Pet::Show();
        cout << "Type: Cat" << endl;
    }

    void Type() const override 
    {
        cout << "Breed: British" << endl;
    }
};

class Parrot : public Pet
{
public:
    Parrot(const char* name) : Pet(name) {}

    void Sound() const override 
    {
        cout << name << " says: Squawk!" << endl;
    }

    void Show() const override 
    {
        Pet::Show();
        cout << "Type: Parrot" << endl;
    }

    void Type() const override
    {
        cout << "Breed: Arra" << endl;
    }
};

class Hamster : public Pet 
{
public:
    Hamster(const char* name) : Pet(name) {}

    void Sound() const override 
    {
        cout << name << " says: Squeak!" << endl;
    }

    void Show() const override
    {
        Pet::Show();
        cout << "Type: Hamster" << endl;
    }

    void Type() const override 
    {
        cout << "Breed: Jungarik" << endl;
    }
};

int main() 
{
    Pet* pets[4];

    pets[0] = new Dog("sabaka");
    pets[1] = new Cat("koshka");
    pets[2] = new Parrot("popyga");
    pets[3] = new Hamster("homiak");

    for (int i = 0; i < 4; i++) 
    {
        pets[i]->Show();
        pets[i]->Type();
        pets[i]->Sound();
        cout << "---------------------------------" << endl;
    }

    for (int i = 0; i < 4; i++) 
    {
        delete pets[i];
    }
}
