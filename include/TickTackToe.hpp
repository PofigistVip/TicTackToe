#ifndef TICK_TACK_TOE_HPP
# define TICK_TACK_TOE_HPP

typedef unsigned char uchar;

class TickTackToe
{
private:
	uchar	field[9];
	uchar	curr_row;
	uchar	curr_col;
	uchar	player_ch;
	uchar	steps;
public:
	TickTackToe(void);
	~TickTackToe(void);
	void	reset(void);
	uchar	getPlayer(void);
	uchar	getSteps(void);
	uchar	getCell(uchar row, uchar col);
	void	setCell(uchar row, uchar col, uchar ch);
	bool	isCellSelected(uchar row, uchar col);
	void	moveUp(void);
	void	moveDown(void);
	void	moveRight(void);
	void	moveLeft(void);
	bool	doStep(void);
	bool	checkRow(uchar row);
	bool	checkCol(uchar col);
	bool	checkDiagonals(void);
	bool	checkWinner(void);
	void	togglePlayer(void);
};

#endif
