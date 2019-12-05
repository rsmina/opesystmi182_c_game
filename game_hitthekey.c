#include <ncurses.h>     // ncurses library
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int key;
int input;

/* main function */

int main(void) {
  initscr();
  noecho();
  curs_set(FALSE);


while(1) {
    mvaddstr(10, 33, " Hit the key after the countdown!!!  ");
    /*printf("Hit the key after the countdown!!!");*/
    sleep(3);
    fflush(stdout);

    mvaddstr(10, 33, " 3 ");
    /*printf(" 3 ");*/
    sleep(1);
    fflush(stdout);

    mvaddstr(10, 33, " 2 ");
    /*printf(" 2 ");*/
    sleep(1);
    fflush(stdout);

    mvaddstr(10, 33, " 1 ");
    /*printf(" 1 ");*/
    sleep(1);
    fflush(stdout);


}


}
