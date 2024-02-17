//#include <stdio.h>



class MyClass
{
public:
	virtual void xx() = 0;
	virtual void xx(double) = 0;
	virtual void yy() = 0;
	virtual void xx(float) = 0;
	virtual void xx(int) = 0;
	virtual void xx(int, int) = 0;
};

class MyClass2
{
public:
	MyClass2() { //printf("MyClass2\n"); 
	}
	~MyClass2() {}

public:
	virtual void xx() { //printf("xx1\n"); 
	}
	virtual void yy() { //printf("yy\n"); 
	}
	virtual void xx(int a) { //printf("xx2=%d\n", a); 
	}
	virtual void xx(int a, int b) { //printf("xx3=%d\n", a); 
	}
	virtual void xx(double a) { //printf("xx4=%f\n", a); 
	}
	virtual void xx(float a) { //printf("xx5=%f\n", a); 
	}
};


int main()
{

	{
		MyClass2* p = new MyClass2();
		p->xx();//						LLVM-MSVC/MSVC-2015/2019: +20
		p->xx(2);//						LLVM-MSVC/MSVC-2015/2019: +18
		p->xx(4, 4);//					LLVM-MSVC/MSVC-2015/2019: +10
		p->yy();//						LLVM-MSVC/MSVC-2015/2019: +28
		p->xx((double)0.2f);//			LLVM-MSVC/MSVC-2015/2019: +8
		p->xx((float)0.4f);//			LLVM-MSVC/MSVC-2015/2019: +0
	}

	return 0;
}


