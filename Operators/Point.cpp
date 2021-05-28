#include "Point.h"


namespace rlm
{
	void Point::Add(Point& point)
	{
		x += point.x;
		y += point.y;
	}
	Point Point::operator+(Point& point)
	{
		Point p;
		p.x = x + point.x;
		p.y = y + point.y;

		return Point();
	}
	Point Point::operator-(Point& point)
	{
		Point p;
		p.x = x - point.x;
		p.y = y - point.y;
		return Point();
	}
	Point Point::operator*(float s)
	{
		Point p;
		p.x = x * s;
		p.y = y * s;
		return Point();
	}
	bool Point::operator==(Point& point)
	{
		return (x == point.x) && (y == point.y);
	}
	void Point::Write(std::ostream& ostream)
	{
		ostream << x << " : " << y << std::endl;
	}

	std::ostream& operator << (std::ostream& ostream, rlm::Point& p)
	{
		ostream << p.x << " : " << p.y << std::endl;
		return ostream;
	}
}