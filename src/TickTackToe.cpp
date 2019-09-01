# include "TickTackToe.hpp"
# include <limits.h>
# include <string.h>


TickTackToe::TickTackToe(void)
{
	reset();
}

TickTackToe::~TickTackToe(void)
{
}

void			TickTackToe::reset(void)
{
	player_ch = 'x';
	steps = 0;
	curr_row = curr_col = 0;
	memset(field, '.', sizeof(field));
}

uchar	TickTackToe::getPlayer(void)
{
	return (player_ch);
}

uchar	TickTackToe::getSteps(void)
{
	return (steps);
}

uchar	TickTackToe::getCell(uchar row, uchar col)
{
	return (field[row * 3 + col]);
}

void		TickTackToe::setCell(uchar row, uchar col, uchar ch)
{
	field[row * 3 + col] = ch;
}

bool	TickTackToe::isCellSelected(uchar row, uchar col)
{
	return (row == curr_row && col == curr_col);
}

void			TickTackToe::moveUp(void)
{
	--curr_row;
	if (curr_row == UCHAR_MAX)
		curr_row = 2;
}

void			TickTackToe::moveDown(void)
{
	++curr_row;
	if (curr_row == 3)
		curr_row = 0;
}

void			TickTackToe::moveRight(void)
{
	++curr_col;
	if (curr_col == 3)
		curr_col = 0;
}

void			TickTackToe::moveLeft(void)
{
	--curr_col;
	if (curr_col == UCHAR_MAX)
		curr_col = 2;
}

bool			TickTackToe::doStep(void)
{
	if (field[curr_row * 3 + curr_col] != '.')
		return (false);
	field[curr_row * 3 + curr_col] = player_ch;
	++steps;
	return (true);
}

void		TickTackToe::togglePlayer(void)
{
	player_ch = (player_ch == 'x') ? 'o' : 'x';
}

bool		TickTackToe::checkRow(uchar row)
{
	return (getCell(row, 0) == player_ch &&
		getCell(row, 1) == player_ch &&
		getCell(row, 2) == player_ch);
}

bool		TickTackToe::checkCol(uchar col)
{
	return (getCell(0, col) == player_ch &&
		getCell(1, col) == player_ch &&
		getCell(2, col) == player_ch);
}

bool		TickTackToe::checkDiagonals(void)
{
	return ((getCell(0, 0) == player_ch &&
		getCell(1, 1) == player_ch &&
		getCell(2, 2) == player_ch) ||
		(getCell(2, 0) == player_ch &&
		getCell(1, 1) == player_ch &&
		getCell(0, 2) == player_ch));
}

bool			TickTackToe::checkWinner(void)
{
	return (checkCol(0) || checkCol(1) || checkCol(2) ||
		checkRow(0) || checkRow(1) || checkRow(2) ||
		checkDiagonals());
}
