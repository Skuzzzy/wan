// Daniel Baird

#include <ncurses.h>
#include <stdlib.h>

char CTRLD = 3;

int row;
int col;

void setup()
{
    initscr();
    raw();
    noecho();
    getmaxyx(stdscr,row,col);
}

void teardown()
{
    endwin();
}

void die(char* error)
{
    endwin();
    printf("%s", error);
    exit(1);
}
int main (int argc, char *argv[])
{
    setup();

    printw("%d row\n%d col\n", row, col);

    char ch = ' ';
    while(ch != CTRLD)
    {
        ch = getch();
        printw("%c: %d, ", ch, ch);
        refresh();
    }

    teardown();
}

