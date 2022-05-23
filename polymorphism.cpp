#include <iostream>
#include <string>
using namespace std;

// ������(polymorphism) : ��ü���� ������ �޼����� ���Ͽ� ���� �ٸ��� �����ϴ°�
// �������� ��ü ���� ������� �ϳ��� �ڵ�� �پ��� Ÿ���� ��ü�� ó���ϴ� ���
// �����Լ�
// ���� ���� �Լ�
// ��ü �������� �� ��ȯ
// 1. ���� ����ȯ(upcasting): �ڽ� Ŭ���� Ÿ���� �θ� Ŭ���� Ÿ������ ��ȯ
// 2. �Ͼ� ����ȯ(downcasting): �θ� Ŭ���� Ÿ���� �ڽ� Ŭ���� Ÿ������ ��ȯ
// �������ε�: �����ϴܰ迡�� ��� ���ε� �Ϸ�/������ �ð��� ȣ�� �Լ��� ����. ������. �Ϲ��Լ�
// �������ε�(�������ε�): ���ε��� ���� �ñ��� ����ǰ� ���� �ð��� ���� ȣ��Ǵ� �Լ��� �����ϴ� ��/ ���� �ð��� ȣ�� �Լ��� ����. ������. �����Լ�

// ��������
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
	virtual void draw() // �����Լ� ���� -> ������
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
// �Լ��� �Ű������� �ڽ� Ŭ���� ���ٴ� �θ� Ŭ���� Ÿ������ ���� �ϴ� ���� ����.
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

	//shape* ps = new Rectangle(); //���� ����ȯ �߻�
	//ps->draw(); // Rectangle draw

	//shape* pc = new Circle();
	//pc->draw(); // Circle draw

	//ps->setHeight shape�� ����Ű�� �ֱ� ������ Rectangle Ŭ���� ��� �Ұ�.
	//Rectangle* pr = (Rectangle*)ps; // ���� ����ȯ �߻�
	//pr->setHeight(10);
	//pr->draw();
	/*delete ps;
	delete pc;*/

	//�簢�� 2��, ��3��, �ﰢ�� 4��
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
