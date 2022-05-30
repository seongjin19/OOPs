#include <iostream>
#include <string>
#define PI 3.14

using namespace std;

// �߻� Ŭ����(abstract class) : ���� ���� �Լ��� ������ �ִ� Ŭ����
// �߻� Ŭ������ �߼����� ������ ǥ���ϴµ� �����ϴ�.

// �߻� Ŭ������ ��ü�� ���̿� "��ȣ �ۿ��ϱ� ���� �������̽�"�� �����ϴ� �뵵�� ����� �� �ִ�.
class shape
{
protected:
	int x, y;
public:
	void setOrigin(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	virtual void draw() = 0;
	virtual void move(int x, int y) = 0;
	virtual double getArea() = 0;
	virtual shape* createshape(int x, int y) = 0;
};
class Rectangle :public shape
{
private:
	int width, height;
public:
	void setWidth(int w)
	{
		width = w;
	}
	void setHeight(int h)
	{
		height = h;
	}
	void draw()
	{
		cout << "Rectangle Draw" << endl;
		cout << "������ : (" << x << "," << y << ")" << endl;
		cout << "�� ��:" << getArea() << endl;
	}
	void move(int x, int y)
	{
		this->x += x;
		this->y += y;
		cout << "�̵���: (" << x << "," << y << ")" << endl;
		cout << "������ : (" << this->x << "," << this->y << ")" << endl;
	}
	double getArea()
	{
		return width * height;
	}
	shape* createshape(int x, int y)
	{
		shape* s = NULL;
		s = new Rectangle();
		s->setOrigin(x, y);
		return s;
	}
};
class Ellipse :public shape
{
private:
	int width, height;
public:
	void setWidth(int w)
	{
		width = w;
	}
	void setHeight(int h)
	{
		height = h;
	}
	void draw()
	{
		cout << "Ellipse Draw" << endl;
		cout << "������ : (" << x << "," << y << ")" << endl;
		cout << "�� ��:" << getArea() << endl;
		
	}
	void move(int x, int y)
	{
		this->x += x;
		this->y += y;
		cout << "�̵���: (" << x << "," << y << ")" << endl;
		cout << "������ : (" << this->x << "," << this->y << ")" << endl;
	}
	double getArea()
	{
		return (width * height) * PI / 4;
	}
	shape* createshape(int x, int y)
	{
		shape* s = NULL;
		s = new Ellipse();
		s->setOrigin(x, y);
		return s;
	}
};
class Triangle :public shape
{
private:
	int width, height;
public:
	void setWidth(int w)
	{
		width = w;
	}
	void setHeight(int h)
	{
		height = h;
	}
	void draw()
	{
		cout << "Triangle Draw" << endl;
		cout << "������ : (" << x << "," << y << ")" << endl;
		cout << "�� ��:" << getArea() << endl;
	}
	void move(int x, int y)
	{
		this->x += x;
		this->y += y;
		cout << "�̵���: (" << x << "," << y << ")" << endl;
		cout << "������ : (" << this->x << "," << this->y << ")" << endl;
	}
	double getArea()
	{
		return width * height/2;
	}
	shape* createshape(int x, int y)
	{
		shape* s = NULL;
		s = new Triangle();
		s->setOrigin(x, y);
		return s;
	}
};
int main(void)
{
	Rectangle r;
	Ellipse e;
	Triangle t;
	
	shape* pr = r.createshape(3,5);
	shape* pe = e.createshape(3,3);
	shape* pt = t.createshape(2,2);

	((Rectangle*)pr)->setWidth(4); // ���� ����ȯ
	((Rectangle*)pr)->setHeight(2);

	((Ellipse*)pe)->setWidth(4); // ���� ����ȯ
	((Ellipse*)pe)->setHeight(2);

	((Triangle*)pt)->setWidth(4); // ���� ����ȯ
	((Triangle*)pt)->setHeight(2);

	pr->draw();
	pr->move(2, 1);

	pe->draw();
	pe->move(2, 0);

	pt->draw();
	pt->move(2, 2);
	
	delete pr;
}