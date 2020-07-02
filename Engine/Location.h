#pragma once

class Location
{
public:
	Location()
	{
		x = 0;
		y = 0;
	}
	Location(int in_x, int in_y)
	{
		x = in_x;
		y = in_y;
	}
	void Add(const Location& val) {
		x += val.x;
		y += val.y;
	}
	bool operator==( const Location& rhs ) const
	{
		return x == rhs.x && y == rhs.y;
	}
	int x;
	int y;
};