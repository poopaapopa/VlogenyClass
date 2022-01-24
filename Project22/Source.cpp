#include <iostream>
using namespace std;

class A
{
public:
	class B
	{
		friend class A;
		B(int val = 0);
		B* next;
		int value;
	};
	class C;
private:
	B* obj;
};
A::B::B(int val)
{
	value = val;
	next = 0;
}
class A::C
{
public:
	C(int val = 0);
	int value;
	C* next;
};
class D
{
private:
	class B;
	class Ref
	{
		B* pli;
	};
	class B
	{
		Ref* pref;
	};
};
class Point
{
	int x;
	int y;
public:
	Point() { x = y = 0; }
	void SetPoint(int iX, int iY)
	{
		x = iX;
		y = iY;
	}
	void Show()
	{
		cout << "-------------------------";
		cout << x << "\t" << y << "\n\n";
		cout << "-------------------------";
	}
};
class Figura
{
	Point* obj;
	int count;
	int color;
public:
	Figura()
	{
		count = color = 0;
		obj = NULL;
	}
	void CreateFigure(int cr, int ct)
	{
		if (ct < 3) exit(0);
		count = ct;
		color = cr;
		obj = new Point[count];
		if (!obj) exit(0);
		int tempX, tempY;
		for (int i = 0; i < count; i++)
		{
			cout << "Set X\n";
			cin >> tempX;
			cout << "Set Y\n";
			cin >> tempY;
			obj[i].SetPoint(tempX, tempY);
		}
	}
	void ShowFigura()
	{
		cout << "-------------------------\n\n";
		cout << "Color" << color << "\n\nPoints- " << count << "\n\n";
		for (int i = 0; i < count; i++)
			obj[i].Show();
	}
	~Figura()
	{
		if (obj != NULL) delete[] obj;
	}
};

int main()
{
	A::B* ptr;
	Figura f;
	f.CreateFigure(255, 3);
	f.ShowFigura();
	return 0;
}