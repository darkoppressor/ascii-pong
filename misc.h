/* Copyright (c) 2011 Kevin Wells */
/* Ascii Pong may be freely redistributed.  See license for details. */

#ifndef misc_h
#define misc_h

#include <cstdlib>

using namespace std;

void demo_return_to_menu();
void move_up_p1();
void move_up_p2();
void move_down_p1();
void move_down_p2();
void menu();
void draw();
void quitgame();
void game_end();

enum{
    /**A few keys are already defined by pdcurses, most of the rest are handled simply by placing the character of the key in single quotes. There are a few others that we define here.*/
    KEY_ESC        = 27,
    KEY_NTR        = 13,
    KEY_SPACE      = 32,
    KP_UP          = 56,
    KP_DOWN        = 50,
    KP_LEFT        = 52,
    KP_RIGHT       = 54,
    KP_UPLEFT      = 55,
    KP_UPRIGHT     = 57,
    KP_DOWNLEFT    = 49,
    KP_DOWNRIGHT   = 51
};

/**Global variables used for various purposes throughout the game.*/
int print_x;/**Used to tell curses where to print things with mvprintw().*/
int print_y;/**Ditto.*/
int ch;/**Used with getch() to get input.*/
bool paddle=false;/**Did a paddle just hit the ball?*/
int menu_item=0;/**0=New game. 1=Options. 2=Credits. 3=Quit game.*/
int options_menu_item=0;/**0=Singleplayer/multiplayer. 1=Difficulty. 2=Theme. 3=Back.*/
bool singleplayer;/**True=Singleplayer mode, and an AI control player 2. False=Multiplayer mode; no AI, and a player must control player 2 as well as player 1.*/
int difficulty;/**0=Very easy. 1=Easy. 2=Normal. 3=Impossible.*/
int theme;/**0=Classic Pong. 1=Icy Waters. 2=Fiery Wastes. 3=Ping Pong. 4=Girly.*/
int paddle_size;/**1=One tile. 2=Two tiles. 3=Three tiles. 4=Default size(four tiles). 5=Five tiles.*/
int speed;/**This variable is used to save and load settings from the options file. 5=Slow. 4=Default speed. 3=Fast. 2=Faster. 1=Fastest.*/
int gametype;/**Reflects what gametype the game is currently set to. 0=Standard. 1=Timed.*/
bool demo=false;/**Used to turn demo mode on and off(currently starts demo mode if the user remains inactive for  seconds on the main menu.*/
bool game_in_progress=false;
int real_speed;/**This is the actual speed variable used by the engine.*/
int p1_x;
int p1_y;
int p2_x;
int p2_y;
int p1_score;
int p2_score;
int p1_hits;
int p2_hits;
int p1_misses;
int p2_misses;
int max_score;
int timer;
int timer_minutes;
int timer_seconds;
int max_timer;
int ball_x;
int ball_y;
int ball_direction;

void wait(float seconds){
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC ;
  while (clock() < endwait) {}
}

void color_fill(){
    for (int x=0;x<80;x++){
        for (int y=0;y<25;y++){
            mvprintw(y,x," ");
        }
    }
}

void set_color(bool color_temp){
    if(color_temp==true){
        if(theme==0)
            white(true);
        if(theme==1)
            icy(true);
        if(theme==2)
            fiery(true);
        if(theme==3)
            pingpong(true);
        if(theme==4)
            girly(true);
    }
    if(color_temp==false){
        if(theme==0)
            white(false);
        if(theme==1)
            icy(false);
        if(theme==2)
            fiery(false);
        if(theme==3)
            pingpong(false);
        if(theme==4)
            girly(false);
    }
}

void set_highlight(bool color_temp){
    if(color_temp==true){
        if(theme==0)
            white_highlight(true);
        if(theme==1)
            icy_highlight(true);
        if(theme==2)
            fiery_highlight(true);
        if(theme==3)
            pingpong_highlight(true);
        if(theme==4)
            girly_highlight(true);
    }
    if(color_temp==false){
        if(theme==0)
            white_highlight(false);
        if(theme==1)
            icy_highlight(false);
        if(theme==2)
            fiery_highlight(false);
        if(theme==3)
            pingpong_highlight(false);
        if(theme==4)
            girly_highlight(false);
    }
}

///This function moves the cursor to x,y.
void go_to_xy(int x,int y){
    print_x=x;
    print_y=y;
}

///This function moves the cursor to the top of the screen.
void go_to_top(){
     print_x=0;
     print_y=0;
}

/**This function randomly selects a number from lownum to highnum and then returns it to where it was called.
Using this we can randomly generate numbers anywhere in the game whenever we need them.*/
int random_range(int lownum, int highnum){
	if(lownum > highnum)
	swap(lownum, highnum);
	int range = highnum - lownum + 1;
	return lownum + int(range * rand()/(RAND_MAX + 1.0));
}

void input_check(){
        switch(ch){
            /**default encompasses all keys not covered by the cases below.*/
            default:
            demo_return_to_menu();
            break;
            case KEY_UP:
            if(demo==false)
                move_up_p1();
            demo_return_to_menu();
            break;
            case KP_UP:
            if(singleplayer==false)
                move_up_p2();
            demo_return_to_menu();
            break;
            case KEY_DOWN:
            if(demo==false)
                move_down_p1();
            demo_return_to_menu();
            break;
            case KP_DOWN:
            if(singleplayer==false)
                move_down_p2();
            demo_return_to_menu();
            break;
            case KEY_ESC:
            menu();
            break;
            case 'q':
            if(demo==false)
            game_end();
            if(demo==true)
            quitgame();
            break;
            case 'p': case KEY_SPACE:
            timeout(-1);
            go_to_xy(34,11);
            set_color(true);
            mvprintw(print_y,print_x,"Game paused.");
            getch();
            go_to_xy(34,11);
            mvprintw(print_y,print_x,"     |      ");
            set_color(false);
            draw();
            timeout(0);
            break;
        }
}

/**Sets the console window's size(this is currently used in 'int Main()' to set the console window to the Windows default).*/
int setConsoleSize(int width, int height){
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD scr_dim;
    scr_dim.X = width;
    scr_dim.Y = height;
    SetConsoleScreenBufferSize(hOut, scr_dim);
}

#endif
