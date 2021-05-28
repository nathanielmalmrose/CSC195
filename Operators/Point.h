#pragma once
#include <iostream>

namespace rlm
{

	class Point
	{
	public:
		Point() : x{ 0 }, y{ 0 } {}
		Point(float x, float y) : x{ x }, y{ y } {}

		void Add(Point& point);
		Point operator + (Point& point);
		Point operator - (Point& point);
		Point operator * (float s);

		bool operator == (Point& point);

		void Write(std::ostream& ostream);

		friend std::ostream& operator << (std::ostream& ostream, rlm::Point& p);
	public:
		float x, y;

	};

}