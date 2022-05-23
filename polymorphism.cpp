#include <iostream>
#include <string>
using namespace std;

// 다형성(polymorphism) : 객체들이 동일한 메세지에 대하여 서로 다르게 동작하는것
// 다형성은 객체 지향 기법에서 하나의 코드로 다양한 타입의 객체를 처리하는 기술
// 가상함수
// 순수 가상 함수
// 객체 포인터의 형 변환
// 1. 상향 형변환(upcasting): 자식 클래스 타입을 부모 클래스 타입으로 변환
// 2. 하양 형변환(downcasting): 부모 클래스 타입을 자식 클래스 타입으로 변환
// 정적바인딩: 컴파일단계에서 모든 바인딩 완료/컴파일 시간에 호출 함수가 결정. 빠르다. 일반함수
// 동적바인딩(지연바인딩): 바인딩이 실행 시까지 연기되고 실행 시간에 실제 호출되는 함수를 결정하는 것/ 실행 시간에 호출 함수가 결정. 느리다. 가상함수

// 도형예제
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
	virtual void draw() // 가상함수 정의 -> 다형성
	{
		cout << "shape draw" << endl;
	}
};
class Rectangle : public shape
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
		cout << "draw Rectangle" << endl;
	}

};
class Circle :public shape 
{
private:
	int radius;
public:
	void setRadius(int r)
	{
		radius = r;
	}
	void draw()
	{
		cout << "Circle draw" << endl;
	}
};
class Triangle : public shape
{
	int base, heigth;
public:
	void draw()
	{
		cout << "Triangle draw" << endl;
	}
};
// 함수의 매개변수는 자식 클래스 보다는 부모 클래스 타입으로 선언 하는 것이 좋다.
void move(shape& s, int sx, int sy)
{
	s.setOrigin(sx, sy);
}

int main(void)
{
	/*Rectangle r;
	move(r, 0, 0);

	Circle c;
	move(c, 0, 0);*/

	//shape* ps = new Rectangle(); //상향 형변환 발생
	//ps->draw(); // Rectangle draw

	//shape* pc = new Circle();
	//pc->draw(); // Circle draw

	//ps->setHeight shape를 가리키고 있기 때문에 Rectangle 클래스 사용 불가.
	//Rectangle* pr = (Rectangle*)ps; // 하향 형변환 발생
	//pr->setHeight(10);
	//pr->draw();
	/*delete ps;
	delete pc;*/

	//사각형 2개, 원3개, 삼각형 4개
	/*Rectangle r[2];
	Circle c[3];
	Triangle t[4];

	for (int i = 0; i < 2; i++)
	{
		r[i].draw();
	}

	for (int i = 0; i < 3; i++)
	{
		c[i].draw();
	}

	for (int i = 0; i < 4; i++)
	{
		t[i].draw();
	}*/
	const int num = 9;
	shape** array = new shape*[num];
	array[0] = new Rectangle();
	array[1] = new Rectangle();
	array[2] = new Circle();
	array[3] = new Circle();
	array[4] = new Circle();
	array[5] = new Triangle();
	array[6] = new Triangle();
	array[7] = new Triangle();
	array[8] = new Triangle();
	for (int i = 0; i < num; i++)
	{
		array[i]->draw();
	}
	
	return 0;
}
