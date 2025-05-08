#include<iostream>
using namespace std;


/* Introduce a layer class, whose purpose id to only act as a base kind
and serve as broad frame-work to the derived ones


as such we do not have intention of creating an object this class.
being a generalized class any attempt to create one must be prevented */

class shape
{

protected:
    //void vptr; //an invisiable pointer field assumed by the compiler
public:

/*

    compiler will assume a default constructor
    shape():vptr(&shape::VTABLE)
    {

    }
*/
//over rideable method
    virtual void draw()=0;
    virtual ~shape(){}

};
class circle :public shape
{

protected:
    //void *vptr; // an invisiable pointer field assumed by the compiler
private:
	int radius;
public:
	circle(int x=0):radius(x){ cout <<"Circle constructor" << endl; }
    // overridable methods
    	void draw(){ cout <<"circle drawn" << endl; }
	 ~circle(){ cout <<"Circle destructor" << endl;}
};

class rectangle :public shape
{
private:
	int length, breadth;
public:
	rectangle(int x=0, int y=0):length(x), breadth(y) { cout <<"rectangle constructor" << endl; }
	void draw(){ cout <<"rectangle drawn" << endl; }
	~rectangle(){ cout <<"rectangle destructor" << endl;}
};

class triangle :public shape
{
private:
	int base, height;
public:
	triangle(int x=0, int y=0):base(x), height(y) { cout <<"triangle constructor" << endl; }
	void draw(){ cout <<"triangle drawn" << endl; }
	~triangle(){ cout <<"triangle destructor" << endl;}
};

class polygon: public shape
{
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

void graphics(shape *);

int main()
{
	cout <<"size of shape object " << sizeof(shape) << endl;
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

void graphics(shape* p)
{
	p->draw();
	//...
	delete p;
}
