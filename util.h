#ifndef UTIL_H
#define UTIL_H

int row, col;

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

#endif
