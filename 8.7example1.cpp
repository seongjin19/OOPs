#include <iostream>

using namespace std;
enum BREED {YORKIE, POODLE, BULLDOG};

class Animal
{
protected:
	int age;
	int weigth;
public:
	//생성자 ,소멸자
	Animal();
	~Animal();

	//멤버함수들
	void speak() const;
	void sleep() const;
	void eat() const;

};

Animal::Animal()
{
	cout << "Animal 생성자" << endl;
}

Animal::~Animal()
{
	cout << "Animal 소멸자" << endl;
}
// 멤버함수들
void Animal::speak() const
{
	cout << "Animal speak()" << endl;
}
void Animal::sleep() const
{
	cout << "Animal sleep()" << endl;
}
void Animal::eat() const
{
	cout << "Animal eat()" << endl;
}

class Dog : public Animal
{
private:
	BREED breed;
public:
	//생성자와 소멸자
	Dog();
	~Dog();
	//멤버함수들
	void wag();
	void bite();
	void speak() const;

};

Dog::Dog()
{
	cout << "Dog 생성자" << endl;
}
Dog::~Dog()
{
	cout << "Dog 소멸자" << endl;
}

//멤버 함수들
void Dog::wag()
{
	cout << "Dog wag()" << endl;
}
void Dog::bite()
{
	cout << "Dog bite()" << endl;
}
void Dog::speak() const
{
	cout << "Dog speak()" << endl;
}

int main(void)
{
	Dog dog;
	dog.eat();
	dog.sleep();
	dog.speak();
	dog.wag();

	return 0;
}