#pragma once

#include "Board.h"
#include "Snake.h"
#include <random>

class Fruit
{
public:
	Fruit( std::mt19937& rng, const Board& brd, const Snake& snake );
	void Respawn( std::mt19937& rng, const Board& brd, const Snake& snake );
	void Draw( Board& brd ) const;
	Location GetLocation();
private:
	static constexpr Color c = Colors::Green;
	Location loc;
};