#pragma once

#include "Graphics.h"

#include "Location.h"

class Board
{
public:
	Board( Graphics& gfx );
	void DrawCell(const Location& loc, Color c);
	int GetBoardWidth() const;
	int GetBoardHeight() const;
	int GetBoardLeftMost() const;
	int GetBoardRightMost() const;
	int GetBoardTopMost() const;
	int GetBoardBottomMost() const;
	bool IsInsideBoard( const Location& loc ) const;
private:
	Graphics& gfx;
	static constexpr int left_most_tile = 1;
	static constexpr int top_most_tile = 1;
	static constexpr int width = 38;
	static constexpr int height = 28;
	const int right_most_tile = left_most_tile + width - 1;
	const int bottom_most_tile = top_most_tile + height - 1;
	static constexpr int dimension = 20;
};