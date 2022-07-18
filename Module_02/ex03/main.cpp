#include "Point.hpp"
#include "bsp.cpp"

int	main(void) {
	Point a(1.0f, 1.0f);
	Point b(3.0f, 3.0f);
	Point c(5.0f, 1.0f);
	Point p(3.0f, 2.0f);

	cout << "Point at " << p << " is ";
	if (!bsp(a, b, c, p)) {
		cout << "not ";
	}
	cout << "in triangle at " << a << ", " << b << ", " << c << endl;
}