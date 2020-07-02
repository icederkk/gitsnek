#pragma once

//#include "SnakeSegment.h"
#include "Board.h"

class Snake
{
private:
	class Segment
	{
	public:
		Segment();
		void InitHead(const Location& in_loc);
		void InitBody(const Color in_c);
		void Follow(const Segment& next);
		void MoveBy(const Location& delta_loc);
		void Draw(Board& brd) const;
		const Location& GetLocation() const;
	private:
		Location loc;
		Color c;
	};
public:
	Snake();
	void Init( const Location& loc );
	void MoveBy( const Location delta_loc );
	Location GetNextHeadLocation( const Location& delta_loc ) const;
	void Grow();
	void Draw( Board& brd ) const;
	bool IsOverlappingExceptLast( const Location& in_loc ) const;
	bool IsOverlapping(const Location& in_loc) const;
private:
	static constexpr Color head_color = Color{ 192, 0, 0 };
	static constexpr Color body_color_0 = Color{ 8, 8, 8 };
	static constexpr Color body_color_1 = Color{ 255, 255, 96 };
	static constexpr Color body_color_2 = Color{ 128, 0, 0 };
	static constexpr int n_seg_max = 100;
	Segment segments[n_seg_max];
	int n_seg = 1;
};