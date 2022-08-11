#include "Point.hpp"

float	get_triangle_area(Point const a, Point const b, Point const c) {
	float	subArea1 = a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat());
	float	subArea2 = b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat());
	float	subArea3 = c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat());
	float	area = (subArea1 + subArea2 + subArea3) / 2.0f;

	return (abs(area));
};

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	float	area = get_triangle_area(a, b, c);
	float	area1 = get_triangle_area(point, b, c);
	float	area2 = get_triangle_area(a, point, c);
	float	area3 = get_triangle_area(a, b, point);
	if (area1 && area2 && area3) {
		return (area == area1 + area2 + area3);
	}
	return (false);
};
