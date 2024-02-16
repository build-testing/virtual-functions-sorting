#include <stdio.h>



class MyClass
{
public:
	virtual void xx() = 0;
	virtual void yy() = 0;
	virtual void xx(int) = 0;
};

class MyClass2
{
public:
	MyClass2() { printf("MyClass2\n"); }
	~MyClass2() {}

public:
	virtual void xx() { printf("xx1\n"); }
	virtual void yy() { printf("yy\n"); }
	virtual void xx(int a) { printf("xx2=%d\n", a); }
	virtual void xx(int a,int b) { printf("xx3=%d\n", a); }
};


int main()
{

	{
		MyClass2* p = new MyClass2();
		p->xx();//			MSVC-2019: +10
		p->xx(2);//			MSVC-2019: +8
		p->xx(4, 4);//		MSVC-2019: +0
		p->yy();//			MSVC-2019: +18
	}
	
	return 0;
}





