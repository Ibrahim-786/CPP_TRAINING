#include<iostream>
using namespace std;

class circle
{

protected:
    //void *vptr; // an invisiable pointer field assumed by the compiler
private:
	int radius;
public:
	circle(int x=0):radius(x){ cout <<"Circle constructor" << endl; }
    //virtual member function or overridable methods
    virtual	void draw(){ cout <<"circle drawn" << endl; }
	virtual ~circle(){ cout <<"Circle destructor" << endl;}
};

class rectangle :public circle
{
private:
	int length, breadth;
public:
	rectangle(int x=0, int y=0):length(x), breadth(y) { cout <<"rectangle constructor" << endl; }
	void draw(){ cout <<"rectangle drawn" << endl; }
	~rectangle(){ cout <<"rectangle destructor" << endl;}
};

class triangle :public circle
{
private:
	int base, height;
public:
	triangle(int x=0, int y=0):base(x), height(y) { cout <<"triangle constructor" << endl; }
	void draw(){ cout <<"triangle drawn" << endl; }
	~triangle(){ cout <<"triangle destructor" << endl;}
};

class polygon: public circle{
    public:
        polygon(){cout<<"polygon constructed "<<endl;}
        void draw()
        {
        cout<<"poly draw "<<endl;
        }
        ~polygon()
        {
            cout<<"poly destructor"<<endl;
        }




};

void graphics(circle *);

int main()
{
	cout <<"size of circle object " << sizeof(circle) << endl;
	cout <<"size of rectangle object " << sizeof(rectangle) << endl;
	cout <<"size of triangle object " << sizeof(triangle) << endl;
	circle *c = new(nothrow) circle;
	graphics(c);
	cout <<"-----------------------"<<endl;
	rectangle *r = new(nothrow) rectangle;
	graphics(r);
	cout <<"-----------------------"<<endl;
	triangle *t = new(nothrow) triangle;
	graphics(t);

    cout <<"-----------------------"<<endl;
	polygon *p = new(nothrow) polygon;
	graphics(p);

	return 0;
}

void graphics(circle* p)
{
	p->draw();
	//...
	delete p;
}
