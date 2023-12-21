#!/usr/bin/python3

""" a function that returns the perimeter of the island described in grid """


def island_perimeter(grid):
    """Return the perimeter of an island.
    Args:
        grid: A grid of integers describing the island.
    Returns:
        the perimeter of the islande described in arg grid
    """

    grid_height = len(grid)
    grid_width = len(grid[0])
    per = 0

    for i in range(grid_height):
        for j in range(grid_width):
            if grid[i][j] == 1:
                col_per = 4
                if(j > 0 and grid[i][j-1] == 1):
                    col_per = col_per - 2
                if(i > 0 and grid[i-1][j] == 1):
                    col_per = col_per - 2
                per = per + col_per

    return per
