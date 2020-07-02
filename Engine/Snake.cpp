#include "Snake.h"
#include "Assert.h"

Snake::Snake()
{
}

void Snake::Init( const Location& loc )
{
	segments[0].InitHead( loc );
}

void Snake::MoveBy( const Location delta_loc )
{
	for ( int i = n_seg; i > 0; i-- )
	{
		segments[i].Follow( segments[i-1] );
	}
	segments[0].MoveBy( delta_loc );
}

Location Snake::GetNextHeadLocation(const Location& delta_loc) const
{
	Location l( segments[0].GetLocation() );
	l.Add( delta_loc );
	return l;	 
}

void Snake::Grow()
{
	if ( n_seg < n_seg_max )
	{
		Color c;
		if ( ( n_seg - 1 ) % 2 == 0 )
		{
			c = body_color_0;
		}
		else
		{
			if ( ( n_seg - 2 ) % 4 == 0 )
			{
				c = body_color_1;
			}
			else
			{
				c = body_color_2;
			}
		}
		segments[n_seg].InitBody( c );
		n_seg++;
	}
}

void Snake::Draw( Board& brd ) const 
{
	for( int i = 0; i < n_seg; i++ )
	{
		segments[i].Draw( brd );
	}
}

bool Snake::IsOverlappingExceptLast(const Location& in_loc) const
{
	for ( int i = 0; i < n_seg-1; i++ )
	{
		if ( segments[i].GetLocation() == in_loc )
		{
			return true;
		}
		else
		{			
		}
	}
	return false;
}

bool Snake::IsOverlapping(const Location& in_loc) const
{
	for (int i = 0; i < n_seg; i++)
	{
		if (segments[i].GetLocation() == in_loc)
		{
			return true;
		}
		else
		{
		}
	}
	return false;
}

Snake::Segment::Segment()
{
}

void Snake::Segment::InitHead( const Location& in_loc )
{
	loc = in_loc;
	c = Snake::head_color;
}

void Snake::Segment::InitBody( const Color in_c )
{

	c = in_c;
}

void Snake::Segment::Follow( const Segment& next )
{
	loc = next.loc;
}

void Snake::Segment::MoveBy( const Location& delta_loc )
{
	assert( abs( delta_loc.x ) + abs( delta_loc.y ) <= 1 );
	loc.Add( delta_loc );
}

void Snake::Segment::Draw( Board& brd ) const 
{
	brd.DrawCell( loc, c );
}

const Location& Snake::Segment::GetLocation() const
{
	return loc;
}
