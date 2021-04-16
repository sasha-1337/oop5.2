#include <iostream>
#include <exception>
#include <cmath>

using namespace std;

class Empty { };

class Error 
{
	string message;
public:
	Error(string m) : message(m) {}
	string What() { return message; }
};

class MyException : public exception
{
	string message;
public:
	MyException(string m) : message(m) {}
	string What() { return message; }
};

double D1(double x1, double x2, double y1, double y2)
{
	if (x1 == x2 && y1 == y2)
		throw 1;
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double D2(double x1, double x2, double y1, double y2) throw()
{
	if (x1 == x2 && y1 == y2)
		throw 2.0;
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double D3(double x1, double x2, double y1, double y2) throw(char)
{
	if (x1 == x2 && y1 == y2)
		throw '3';
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double D4(double x1, double x2, double y1, double y2) throw(Empty)
{
	if (x1 == x2 && y1 == y2)
		throw Empty();
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double D5(double x1, double x2, double y1, double y2) throw(Error)
{
	if (x1 == x2 && y1 == y2)
		throw Error(" P1 = P2 : 5");
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double D6(double x1, double x2, double y1, double y2) throw(int)
{
	if (x1 == x2 && y1 == y2)
		throw MyException(" P1 = P2 : 6");
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void FU()
{
	cout << "unexpected error! - bad_exception" << endl;
	throw;
}
void FT()
{
	cout << "unknown error! - terminate" << endl;
	abort();
}

int main()
{
	set_unexpected(FU);
	//set_terminate(FT);

	double x1, x2, y1, y2;
	cout << " x1 = "; cin >> x1;
	cout << " x2 = "; cin >> x2;
	cout << " y1 = "; cin >> y1;
	cout << " y2 = "; cin >> y2;
	cout << " P1(" << x1 << "," << y1 << ") , " << "P2(" << x2 << "," << y2 << ")" << endl;

	try 
	{
		//cout << " D = " << D1(x1, x2, y1, y2) << endl;
		//cout << " D = " << D2(x1, x2, y1, y2) << endl;
		//cout << " D = " << D3(x1, x2, y1, y2) << endl;
		//cout << " D = " << D4(x1, x2, y1, y2) << endl;
		//cout << " D = " << D5(x1, x2, y1, y2) << endl;
		cout << " D = " << D6(x1, x2, y1, y2) << endl;
	}
	catch (int i)
	{
		cout << " catch (int) <= D1() : " << i << endl;
	}
	catch (double d)
	{
		cout << " catch (double) <= D2() : " << d << endl;
	}
	catch (char c)
	{
		cout << " catch (char) <= D3() : " << c << endl;
	}
	catch (Empty)
	{
		cout << " catch (Empty) <= D4()" << endl;
	}
	catch (Error e)
	{
		cout << " catch (Error) <= D5() : " << e.What() << endl;
	}
	catch (MyException q)
	{
		cout << " catch (MyException) <= D6() : " << q.What() << endl;
	}
	catch (bad_exception)
	{
		cout << " catch (bad_exception) " << endl;
	}

	return 0;
}