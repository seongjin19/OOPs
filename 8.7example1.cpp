#include <iostream>

using namespace std;
enum BREED {YORKIE, POODLE, BULLDOG};

class Animal
{
protected:
	int age;
	int weigth;
public:
	//������ ,�Ҹ���
	Animal();
	~Animal();

	//����Լ���
	void speak() const;
	void sleep() const;
	void eat() const;

};

Animal::Animal()
{
	cout << "Animal ������" << endl;
}

Animal::~Animal()
{
	cout << "Animal �Ҹ���" << endl;
}
// ����Լ���
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
	//�����ڿ� �Ҹ���
	Dog();
	~Dog();
	//����Լ���
	void wag();
	void bite();
	void speak() const;

};

Dog::Dog()
{
	cout << "Dog ������" << endl;
}
Dog::~Dog()
{
	cout << "Dog �Ҹ���" << endl;
}

//��� �Լ���
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