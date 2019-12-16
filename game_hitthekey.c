#include <ncurses.h>     // ncurses library
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int key;
int input;
int screenX = 0;
int screenY = 0;

/* main function */

int main(void) {
  initscr();
  noecho();
  curs_set(FALSE);
  
  cbreak();
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
   
  bool windowActive = TRUE;

while(windowActive) {
    
    getmaxyx(stdscr, screenY, screenX);
    int keyInput = getch(); 
    
    mvaddstr(10, 33, " Hit the key after the countdown!!!  ");
    sleep(3000);
    
    mvaddstr(10, 33, " 3 ");
    sleep(1000);

    mvaddstr(10, 33, " 2 ");
    sleep(1);

    mvaddstr(10, 33, " 1 ");
    sleep(1);


}

endwin();
return (0);
}

