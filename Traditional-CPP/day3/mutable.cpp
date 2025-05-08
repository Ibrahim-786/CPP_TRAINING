#include<iostream>
using namespace std;

//An example on mutable member and const objects.
// The mutable qualifier permits changes to a class data member, 
//though the object is qualified to 'const'

class Screen
{
private:
	 int rows, columns;
       mutable  int curR, curC;
public:
	Screen(int row = 10, int column = 10, int r = 1, int c = 1) :rows(row), columns(column), curR(r), curC(c) {   }

	void Resize() const
	{
		cout << "Initial window layout..." << endl;
		cout << "Row height:" << rows << endl;
		cout << "Column height:" << columns << endl;
		cout << "cursor location:" << curR << "," << curC << endl;
		cout << "Window layout upon resizing ..." << endl;
	//	rows = rows + 10;
		//columns = columns + 5;
		curR++;
		curC++;
		cout << "Row height:" << rows << endl;
		cout << "Column height:" << columns << endl;
		cout << "cursor location:" << curR << "," << curC << endl;
		cout << "Window layout upon resizing ..." << endl;
	}
	void Resize()
	{
		cout << "Initial window layout..." << endl;
		cout << "Row height:" << rows << endl;
		cout << "Column height:" << columns << endl;
		cout << "cursor location:" << curR << "," << curC << endl;
		cout << "Window layout upon resizing ..." << endl;
		rows = rows + 10;
		columns = columns + 5;
		curR++;
		curC++;
		cout << "Row height:" << rows << endl;
		cout << "Column height:" << columns << endl;
		cout << "cursor location:" << curR << "," << curC << endl;
		cout << "----------------------" << endl;
	}
};

//****class consumer*****
int main()
{
	cout <<"*********Windows user.... **********" << endl;
	Screen s1(35, 80, 1, 1);
	s1.Resize();
	cout <<"*********Dos user.... **********" << endl;
	const Screen s2(25, 80, 1, 1);
	s2.Resize();
	return 0;
}




