#include <stdio.h>
#include <stdlib.h>

#define NUM_STEPS 1018
#define DEBUG

//
// An ant moves on a regular grid of squares that are coloured either black or white.
// The ant is always oriented in one of the cardinal directions (left, right, up or down) 
//     and moves from square to adjacent square according to the following rules:
// - if it is on a black square, it flips the color of the square to white, 
// 	 rotates 90 degrees counterclockwise and moves forward one square.
// - if it is on a white square, it flips the color of the square to black, 
// 	 rotates 90 degrees clockwise and moves forward one square.
// 
// Starting with a grid that is entirely white, how many squares are black after 1018 moves of the ant?
// 

typedef enum
{
	WHITE,
	BLACK
} Color;

typedef enum
{
	LEFT,
	RIGHT,
	UP,
	DOWN
} Facing;

typedef struct
{
	int x;
	int y;
	Color color;
} Square;

Facing rotate_counterclockwise(Facing current)
{
	switch (current)
	{
		case LEFT:
			current = DOWN;
			break;

		case RIGHT:
			current = UP; 
			break;

		case UP:
			current = LEFT;
			break;

		case DOWN:
			current = RIGHT;
			break;

		default:
			break;
	}

	return current;
}

Facing rotate_clockwise(Facing current)
{	
	switch (current)
	{
		case LEFT:
			current = UP;
			break;

		case RIGHT:
			current = DOWN; 
			break;

		case UP:
			current = RIGHT;
			break;

		case DOWN:
			current = LEFT;
			break;

		default:
			break;
	}

	return current;
}

int main(int argc, char *argv[])
{
	int step = 0, 
	int grid_index = 0;

	Square *grid = malloc(sizeof(Square) * 1018);

	Square start = malloc(sizeof(Square));
	start.x = 0;
	start.y = 0;
	start.color= WHITE;

	Square current_square = start;
	Facing direction = UP;

	while (step < NUM_STEPS)
	{

#ifdef DEBUG
		printf("current.x: %i\n", current_square.x);
		printf("current.y: %i\n", current_square.y);
		printf("current.color: %i\n", current_square.color);
		printf("direction: %i\n", direction);
#endif

		// Perform action
		if (current_square.color == BLACK)
		{
			current_square.color = WHITE;
			direction = rotate_counterclockwise(direction);
		}
		else if (current_square.color == WHITE)
		{
			current_square.color = BLACK;
			direction = rotate_clockwise(direction);
		}

		// Store this square 
		grid[grid_index] = current_square;

		// Move the ant
		int next_x, next_y;

		switch (direction)
		{
			case LEFT:
				next_x = current_square.x - 1;
				break;

			case RIGHT:
				next_x = current_square.x + 1;
				break;

			case UP:
				next_y = current_square.y + 1;
				break;

			case DOWN:
				next_y = current_square.y - 1;
				break;

			default:
				break;
		}

		// Find or create the next square, set to current
		int i, found;
		found = 0;
		for (i = 0; i < grid_index; ++i)
		{
			if ( (grid[i].x == next_x) && (grid[i].y == next_y) )
			{
				current_square = grid[i];
				found = 1;
			}
		}

		if (found == 0)
		{
			current_square.x = next_x;
			current_square.y = next_y;
			current_square.color = WHITE;
		}
	}

	int j;
	int black_count = 0;
	for (j = 0; j < grid_index; ++j)
	{
		if (grid[j].color == BLACK)
		{
			++black_count;
		}
	}

	printf("***********\n");
	printf("%i black tiles.\n", black_count);
	printf("***********\n");

	return 0;
}
