
/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd( gfx ),
	fruit( rng, brd, snek )
{
	snek.Init({ 5, 5 });
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if( !game_is_over && game_is_started )
	{
		if ( delta_loc.x != 0 )
		{
			if (wnd.kbd.KeyIsPressed(VK_UP))
			{
				delta_loc = { 0, -1 };
			}
			else if (wnd.kbd.KeyIsPressed(VK_DOWN))
			{
				delta_loc = { 0, 1 };
			}
		}

		if ( delta_loc.y != 0 )
		{
			if (wnd.kbd.KeyIsPressed(VK_LEFT))
			{
				delta_loc = { -1, 0 };
			}
			else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
			{
				delta_loc = { 1, 0 };
			}
		}		
	}
	else if ( !game_is_started )
	{
		if ( wnd.kbd.KeyIsPressed( VK_RETURN ) )
		{
			game_is_started = true;
		}
	}
	else
	{
	}

	if ( game_is_started == true )
	{
		if (snek_move_counter >= snek_move_period)
		{
			snek_move_counter = 0;
			const Location next = snek.GetNextHeadLocation(delta_loc);
			if (!brd.IsInsideBoard(next) || snek.IsOverlappingExceptLast(next))
			{
				game_is_over = true;
			}
			else
			{
				const bool eating = (next == fruit.GetLocation());
				if (eating)
				{
					snek.Grow();
					snek_eaten_counter++;
					if ( snek_eaten_counter >= 5 )
					{
						snek_move_period = snek_move_period - 2;
						if ( snek_move_period < snek_move_period_min )
						{
							snek_move_period = snek_move_period_min;
						}
						snek_eaten_counter = 0;
					}
				}
				snek.MoveBy(delta_loc);
				if (eating)
				{
					fruit.Respawn(rng, brd, snek);
				}
			}
		}
		snek_move_counter++;
	}
	else
	{
	}
	
}

void Game::ComposeFrame()
{
	for( int x = brd.GetBoardLeftMost(); x <= brd.GetBoardRightMost(); x++ )
	{
		for( int y = brd.GetBoardTopMost(); y <= brd.GetBoardBottomMost(); y++ )
		{
			Location loc( x, y );
			if ( brd.IsInsideBoard( loc ) )
			{
				brd.DrawCell( loc, Color{ 32, 32, 32 } );
			}
			else
			{
				brd.DrawCell( loc, Color{ 16, 16, 128 } );
			}
			
		}
	}
	snek.Draw( brd );
	fruit.Draw( brd );
	if ( game_is_over )
	{
		SpriteCodex::DrawGameOver( 358, 268, gfx );
	}
	if ( !game_is_started )
	{
		SpriteCodex::DrawTitle( 303, 212, gfx );
	}
}
