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
    int x = 0, y = 0;
    while(ch != CTRLD)
    {
        move(y, x);
        ch = getch();
        switch(ch){
            case 27:
                ch = getch();
                ch = getch();
                switch(ch){
                    case 68: // Left
                        x -= 1;
                        break;
                    case 65: // Up
                        y -= 1;
                        break;
                    case 67: // Right
                        x += 1;
                        break;
                    case 66: // Down
                        y += 1;
                        break;
                }
                /*printw("TEST", ch);*/
                break;
            case 10: // Newline
                x = 0;
                y += 1;
                break;
            case 127: // Backspace

                if (y == 0 && x == 0)
                {
                    break;
                }

                x -= 1;
                if(x < 0)
                {
                    x = col - 1;
                    y -= 1;
                }
                mvaddch(y, x, ' ');
                break;
            default:
                /*move(0,0);*/
                /*printw("%d", ch);*/
                /*mvaddch(y, x, ch);*/
                mvaddch(y, x, ch);
                refresh();
                x += 1;
                if( x >= col )
                {
                    x = 0;
                    y += 1;
                }
                break;
        }

    }

    teardown();
}

