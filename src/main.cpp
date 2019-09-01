#include "TickTackToe.hpp"
#include <stdio.h>

#ifndef __linux
# include <conio.h>
# include <iostream>
#else
# include <unistd.h>
# include <termios.h>

int getch()
{
    int				ch;
    struct termios	oldt, newt;

    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

#endif

void	showCell(TickTackToe &game, uchar row, uchar col)
{
	#ifdef __linux

	if (game.isCellSelected(row, col))
		printf("\033[30;47m>%c<\033[m", game.getCell(row, col));
	else
		printf(" %c ", game.getCell(row, col));

	#else

	if (game.isCellSelected(row, col))
		printf(">%c<", game.getCell(row, col));
	else
		printf(" %c ", game.getCell(row, col));

	#endif
}

void	showRow(TickTackToe &game, uchar row)
{
	uchar	col;

	putchar('\t');
	for (col = 0; col < 3; ++col)
	{
		putchar('|');
		showCell(game, row, col);
	}
	puts("|");
}

void	showGame(TickTackToe &game)
{
	#ifndef __linux

	system("cls");

	#else

	printf("\033[u");

	#endif

	printf("Current player: %c\n", game.getPlayer());
	puts("\t/---|---|---\\");
	showRow(game, 0);
	puts("\t|---+---+---|");
	showRow(game, 1);
	puts("\t|---+---+---|");
	showRow(game, 2);
	puts("\t\\---|---|---/");
	puts("WASD - move, Space - set mark, R - restart, Esc - exit\n");
}

bool	waitAnyKey(TickTackToe &game)
{
	int ch;

	ch = (int)getch();
	if (ch == 27)
		return (true);
	printf("\r%-40c", ' ');
	game.reset();
	return (false);
}

bool	handleKey(TickTackToe &game, int ch)
{
	if (ch == 'w')
		game.moveUp();
	else if (ch == 's')
		game.moveDown();
	else if (ch == 'a')
		game.moveLeft();
	else if (ch == 'd')
		game.moveRight();
	else if (ch ==  ' ')
	{
		if (game.doStep())
		{
			if (game.checkWinner())
			{
				showGame(game);
				printf("Player '%c' won this round!", game.getPlayer());
				return (waitAnyKey(game));
			}	
			else
				game.togglePlayer();
			if (game.getSteps() == 9)
			{
				showGame(game);
				printf("%-40s", "DRAW");
				return (waitAnyKey(game));
			}	
		}
	}
	else if (ch == 'r')
		game.reset();
	return (false);
}

int		main(void)
{
	TickTackToe		game;
	int				ch;

	#ifdef __linux

	printf("\033[s\033[?25l");

	#endif

	while (true)
	{
		showGame(game);
		ch = (int)getch();
		if (ch == 27)
			break ;
		if (handleKey(game, ch))
			break ;
	}
	#ifdef __linux

	printf("\033[?25h");

	#endif

	return (0);
}
