#include <ncurses.h>
#include <stdio.h>

#define HEIGHT 10
#define WIDTH 30


int startx = 0;
int starty = 0;

char *choices[] = {
                        "Pick it up",
                        "Stare at it",
                        "Take a picture of it",
                        "Keep walking",
                        "[Exit Game]",
                  };
int n_choices = sizeof(choices) / sizeof(char *);
void print_menu(WINDOW *menu_win, int highlight);

int main()
{       WINDOW *menu_win;
        int highlight = 1;
        int choice = 0;
        int c;

        initscr();
        clear();
        noecho();
        cbreak();       /* Line buffering disabled. pass on everything */
        startx = (80 - WIDTH) / 2;
        starty = (24 - HEIGHT) / 2;

        menu_win = newwin(HEIGHT, WIDTH, starty, startx);
        keypad(menu_win, TRUE);
        mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice. Choose Wisely.");
        mvprintw(3, 3, "You're walking by a sidewalk when you notice a weirdly shaped rock glowing purple.");
        refresh();
        print_menu(menu_win, highlight);
        while(1)
        {       c = wgetch(menu_win);
                switch(c)
                {       case KEY_UP:
                                if(highlight == 1)
                                        highlight = n_choices;
                                else
                                        --highlight;
                                break;
                        case KEY_DOWN:
                                if(highlight == n_choices)
                                        highlight = 1;
                                else
                                        ++highlight;
                                break;
                        case 10:
                                choice = highlight;
                                
                                if(choice == 0) {
                                    refresh();
                                    mvprintw(3, 3, "You were overwhelmed by the power of the stone and you dissintegrate. The end.");
                                    endwin();
                                }

				else if(choice == 1) {
                                    refresh();
                                    mvprintw(3, 3, "You looked at it for too long and you were blinded by the stone. The end.");
                                    endwin();
                                }

				else if(choice == 2) {
                                    refresh();
                                    mvprintw(3, 3, "Your phone reacts to the stone's radioactive energy and it explodes on your hand. The end.");
                                    endwin();
                                }

				break;
                                
                        default:
                                mvprintw(24, 0, " ", c, c);
                                refresh();
                                break;
                }
                print_menu(menu_win, highlight);
                if(choice != 0) /* User did a choice come out of the infinite loop */
                        break;
        }
        mvprintw(23, 0, "You chose choice %d with choice string %s\n", choice, choices[choice - 1]);
        clrtoeol();
        refresh();
        endwin();
        return 0;
}


void print_menu(WINDOW *menu_win, int highlight)
{
        int x, y, i;

        x = 2;
        y = 2;
        box(menu_win, 0, 0);
        for(i = 0; i < n_choices; ++i)
        {       if(highlight == i + 1) /* High light the present choice */
                {       wattron(menu_win, A_REVERSE);
                        mvwprintw(menu_win, y, x, "%s", choices[i]);
                        wattroff(menu_win, A_REVERSE);
                }
                else
                        mvwprintw(menu_win, y, x, "%s", choices[i]);
                ++y;
        }
        wrefresh(menu_win);
}
