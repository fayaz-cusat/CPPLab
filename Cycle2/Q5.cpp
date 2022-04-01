#include <iostream>

class Animal
{
public:
    int legs;
    Animal(int n)
    {
        std::cout << "Animal constructor called!\n";
        legs = n;
    }
};

class Pet
{
    bool hungry;

public:
    Pet(bool h)
    {
        std::cout << "Pet constructor called!\n";
        hungry = h;
    }
    virtual void say() { std::cout << "\nDon't know what to say\n\n"; }
    void feed() { hungry = false; }
    void play()
    {
        if (hungry)
            std::cout << "\nWon't play, I'm hungry\n\n";
        else
            say();
        hungry = true;
    }
    bool is_hungry() { return hungry; }
};

class Dog : public Animal,
            public Pet
{
    bool furry;

public:
    Dog(bool f) : Animal(4), Pet(true)
    {
        std::cout << "Dog constructor called!\n";
        furry = f;
    }
    void bark() { std::cout << "Woof!"; }
    void say()
    {
        std::cout << '\n';
        bark();
        std::cout << ' ';
        bark();
        std::cout << "\n\n";
    }
    bool is_furry() { return furry; }
};

class Husky : public Dog
{
public:
    Husky() : Dog(true)
    {
        std::cout << "Husky constructor called!\n";
    }
};

int main()
{
    int ch;
    do
    {
        std::cout << "1. Initialize husky object\n2. END\n>>> ";
        std::cin >> ch;
        if (ch == 1)
        {
            Husky husky;
            int ch2;
            do
            {
                std::cout << "1. Hungry?\n2. Feed husky\n3. Play with husky\n4. Show number of legs\n5. Speak\n6. Furry?\n7. END\n>>> ";
                std::cin >> ch2;
                switch (ch2)
                {
                case 1:
                    if (husky.is_hungry())
                        std::cout << "\nYES\n\n";
                    else
                        std::cout << "\nNO\n\n";
                    break;

                case 2:
                    husky.feed();
                    break;

                case 3:
                    husky.play();
                    break;

                case 4:
                    std::cout << "\nI have " << husky.legs << " legs!\n\n";
                    break;

                case 5:
                    std::cout << '\n';
                    husky.bark();
                    std::cout << "\n\n";
                    break;

                case 6:
                    if (husky.is_furry())
                        std::cout << "\nYES\n\n";
                    else
                        std::cout << "\nNO\n\n";

                case 7:
                    break;
                }

            } while (ch2 != 7);
        }
        else if (ch == 2)
            break;
    } while (ch != 2);
}
