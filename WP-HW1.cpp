#include <iostream>

using namespace std;

class CShape
{
protected:
	float x, y;
public:
	/*CShape(float x, float y)
	{
		this->x = x;
		this->y = y;
	}*/
	virtual void Input();
	virtual void Draw();
	float get_x();
	float get_y();
	void set_x(float x);
	void set_y(float y);
};
void CShape::Input() 
{
	float x, y;
	cin >> x >> y;
	this->x = x;
	this->y = y;
};
void CShape::Draw() 
{
	cout << "[SHAPE] Position = " << "<" << x << ", " << y << ">" << endl;
};

float CShape:: get_x()
{
	return x;
}
void CShape :: set_x(float x)
{
	this->x = x;
}
float CShape::get_y()
{
	return y;
}
void CShape::set_y(float y)
{
	this->y = y;
}

class CRectangle : public CShape
{
private:
	float w;
	float h;
public:
	void Input();
	void Draw();
};
void CRectangle::Input()
{

	float x, y, w, h;
	cin >> x >> y >> w >> h;
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
};
void CRectangle::Draw()
{
	cout << "[RECTANGLE] Position = " << "<" << x << ", " << y << ">, " << "Size = <" << w << ", " << h << ">" << endl;
};

class CCircle : public CShape
{
private:
	float r;
public:
	void Input();
	void Draw();
};
void CCircle::Input()
{
	
	float x, y, r;
	cin >> x >> y >> r;
	this->x = x;
	this->y = y;
	this->r = r;
	
};
void CCircle::Draw()
{
	cout << "[Circle] Position = " << "<" << x << ", " << y << ">, " << "Radius = " << r << endl;
};

int main(void)
{
	

	int count = 0;
	CShape** s = new CShape*[10];
	for (int i = 0; i < 10; i++)
	{
		int num = 0;
		cin >> num;
		if (num == 1)
		{	
			s[i] = new CShape(); //¹»±î¿ä
			s[i]->Input();
		}
		else if (num == 2)
		{
			s[i] = new CRectangle();
			s[i]->Input();
			
		}
		else if (num == 3)
		{
			s[i] = new CCircle();
			s[i]->Input();
			
		}
		else if (num == 4)
		{
			for (int j = 0; j < i; j++)
			{
				s[j]->Draw();
			}
		}
		else if (num == 5)
		{
			break;
		}
		count = i;
	}
	for (int i = 0; i < count; i++)
	{
		delete s[i];
		s[i] = nullptr;
	}
	delete[] s;

	return 0;
}