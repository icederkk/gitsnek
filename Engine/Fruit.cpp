#include "Fruit.h"

Fruit::Fruit( std::mt19937& rng, const Board& brd, const Snake& snake )
{
	Respawn( rng, brd, snake );
}

void Fruit::Respawn( std::mt19937& rng, const Board& brd, const Snake& snake )
{
	std::uniform_int_distribution<int> x_distribution( brd.GetBoardLeftMost() + 1, brd.GetBoardRightMost() - 1 );
	std::uniform_int_distribution<int> y_distribution( brd.GetBoardTopMost() + 1, brd.GetBoardBottomMost() - 1 );

	Location new_loc;
	do
	{
		new_loc.x = x_distribution( rng );
		new_loc.y = y_distribution( rng );
	} while ( snake.IsOverlapping( new_loc ) );

	loc = new_loc;
}

void Fruit::Draw(Board& brd) const
{
	brd.DrawCell( loc, c );
}

Location Fruit::GetLocation()
{
	return loc;
}
