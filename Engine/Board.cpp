#include "Board.h"
#include <assert.h>

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{
}

void Board::DrawCell(const Location& loc, Color c)
{
	assert( loc.x >= left_most_tile );
	assert( loc.x <= right_most_tile );
	assert( loc.y >= top_most_tile );
	assert( loc.y <= bottom_most_tile );
	gfx.DrawRectDim(loc.x*dimension + 1, loc.y*dimension + 1, dimension - 2, dimension - 2, c);
}

int Board::GetBoardWidth() const 
{
	return width;
}

int Board::GetBoardHeight() const 
{
	return height;
}

int Board::GetBoardLeftMost() const
{
	return left_most_tile;
}

int Board::GetBoardRightMost() const
{
	return right_most_tile;
}

int Board::GetBoardTopMost() const
{
	return top_most_tile;
}

int Board::GetBoardBottomMost() const
{
	return bottom_most_tile;
}

bool Board::IsInsideBoard(const Location& loc) const
{
	return ( loc.x >= ( left_most_tile + 1 ) && ( loc.x <= right_most_tile - 1)
			&& ( loc.y >= top_most_tile + 1 ) && loc.y <= ( bottom_most_tile - 1 ) );
}
