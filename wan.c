// Daniel Baird

#include <ncurses.h>

char CTRLD = 3;

void setup()
{
	initscr();
	raw();
	noecho();
}

void teardown()
{
	endwin();
}

int main (int argc, char *argv[])
{
	setup();
    char ch = ' ';
	while(ch != CTRLD)
	{
		ch = getch();
		printw("%c: %d, ", ch, ch);
		refresh();
	}

	teardown();
}

