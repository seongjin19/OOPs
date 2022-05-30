#include <iostream>
#include <string>
#define PI 3.14

using namespace std;

// 추상 클래스(abstract class) : 순수 가상 함수를 가지고 있는 클래스
// 추상 클래스는 추성적인 개념을 표현하는데 적당하다.

// 추상 클래스는 객체들 사이에 "상호 작용하기 위한 인터페이스"를 정의하는 용도로 사용할 수 있다.
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
		cout << "시작점 : (" << x << "," << y << ")" << endl;
		cout << "면 적:" << getArea() << endl;
	}
	void move(int x, int y)
	{
		this->x += x;
		this->y += y;
		cout << "이동점: (" << x << "," << y << ")" << endl;
		cout << "시작점 : (" << this->x << "," << this->y << ")" << endl;
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
		cout << "시작점 : (" << x << "," << y << ")" << endl;
		cout << "면 적:" << getArea() << endl;
		
	}
	void move(int x, int y)
	{
		this->x += x;
		this->y += y;
		cout << "이동점: (" << x << "," << y << ")" << endl;
		cout << "시작점 : (" << this->x << "," << this->y << ")" << endl;
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
		cout << "시작점 : (" << x << "," << y << ")" << endl;
		cout << "면 적:" << getArea() << endl;
	}
	void move(int x, int y)
	{
		this->x += x;
		this->y += y;
		cout << "이동점: (" << x << "," << y << ")" << endl;
		cout << "시작점 : (" << this->x << "," << this->y << ")" << endl;
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

	((Rectangle*)pr)->setWidth(4); // 하향 형변환
	((Rectangle*)pr)->setHeight(2);

	((Ellipse*)pe)->setWidth(4); // 하향 형변환
	((Ellipse*)pe)->setHeight(2);

	((Triangle*)pt)->setWidth(4); // 하향 형변환
	((Triangle*)pt)->setHeight(2);

	pr->draw();
	pr->move(2, 1);

	pe->draw();
	pe->move(2, 0);

	pt->draw();
	pt->move(2, 2);
	
	delete pr;
}