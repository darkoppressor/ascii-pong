/* Copyright (c) 2011 Kevin Wells */
/* Ascii Pong may be freely redistributed.  See license for details. */

#include <iostream>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <string>
#include <windows.h>
#include <curses.h>
#include "color_defs.h"
#include "colors.h"
#include "misc.h"
#include "screen_draw.h"
#include "game.h"
#include "movement.h"
#include "demo.h"
#include "ai.h"

/**For the color themes, the following are the functions that need to be edited to add new themes:
game()
move_up_ai()
move_down_ai()
move_up_p1()
move_down_p1()
move_up_p2()
move_down_p2()
paddle_check_p1()
paddle_check_p2()
move_ball()
draw_borders()
draw()
draw_main_menu()
draw_options_menu()
credits()
*/

using namespace std;

void game(){
    game_in_progress=true;
    int tick=0;
    erase();
    set_color(true);
    color_fill();
    set_color(false);
    draw_borders();
    draw();
    while(ch=getch()){
        if(gametype==0 && p1_score==max_score || gametype==0 && p2_score==max_score)
        game_end();
        if(gametype==1 && timer_minutes==max_timer)
        game_end();
        input_check();
        if(tick==real_speed-1 && demo==true){
            if(ball_direction==6 || ball_direction==1){
                demo_ai_move();
                demo_ai_move();
            }
        }
        if(tick==real_speed-1 && singleplayer==true){
            if(ball_direction==8 || ball_direction==3){
                ai_move();
                ai_move();
            }
        }
        wait(.0001);
        tick++;
        if(gametype==1){
        if(tick==1000)
        timer++;
        if(timer==20){
            timer_seconds++;
            timer=0;
        }
        if(timer_seconds>59){
            timer_minutes++;
            timer_seconds=0;
        }
        }
        if(tick==real_speed){
            move_ball();
            tick=0;
        }
        draw();
    }
}

int main(){
    srand((unsigned) time(NULL));
    setConsoleSize(80,25);
    SetConsoleTitle("Ascii Pong");
    initscr();/**Start curses mode.*/
    timeout(0);/**getch() will not pause for input, but will check continuously.*/
    raw();/**Disables line buffering.*/
    keypad(stdscr, TRUE);/**Allows use of function keys, arrow keys, etc.*/
    noecho();/**Don't echo() while we do getch*/
    curs_set(0);/**This makes the cursor invisible.*/
    start_color();/**Start color mode.*/
    /**Here we define all of our color pairs.*/
    init_pair(1,CLR_WHITE,COLOR_BLACK);
    init_pair(2,COLOR_BLACK,CLR_WHITE);
    init_pair(3,CLR_WHITE,COLOR_BLUE);
    init_pair(4,COLOR_BLUE,CLR_WHITE);
    init_pair(5,CLR_BRIGHT_YELLOW,COLOR_RED);
    init_pair(6,COLOR_RED,CLR_BRIGHT_YELLOW);
    init_pair(7,CLR_WHITE,COLOR_GREEN);
    init_pair(8,COLOR_GREEN,CLR_WHITE);
    init_pair(9,CLR_WHITE,CLR_BRIGHT_MAGENTA);
    init_pair(10,CLR_BRIGHT_MAGENTA,CLR_WHITE);
    char c;
    int options_temp=0;
    ifstream options_file ("options.cfg");
    if(options_file.is_open()){
        while(options_temp<6){
            options_file.get(c);
            if(options_temp==0){
                if(c=='0')
                singleplayer=false;
                if(c=='1')
                singleplayer=true;
            }
            if(options_temp==1){
                if(c=='0')
                difficulty=0;
                if(c=='1')
                difficulty=1;
                if(c=='2')
                difficulty=2;
                if(c=='3')
                difficulty=3;
            }
            if(options_temp==2){
                if(c=='0')
                theme=0;
                if(c=='1')
                theme=1;
                if(c=='2')
                theme=2;
                if(c=='3')
                theme=3;
                if(c=='4')
                theme=4;
            }
            if(options_temp==3){
                if(c=='1')
                speed=1;
                if(c=='2')
                speed=2;
                if(c=='3')
                speed=3;
                if(c=='4')
                speed=4;
                if(c=='5')
                speed=5;
            }
            if(options_temp==4){
                if(c=='1')
                paddle_size=1;
                if(c=='2')
                paddle_size=2;
                if(c=='3')
                paddle_size=3;
                if(c=='4')
                paddle_size=4;
                if(c=='5')
                paddle_size=5;
            }
            if(options_temp==5){
                if(c=='0')
                gametype=0;
                if(c=='1')
                gametype=1;
                if(c=='2')
                gametype=2;
            }
            options_temp++;
        }
        options_file.close();
    }
    else{
        singleplayer=true;
        difficulty=2;
        theme=0;
        speed=4;
        paddle_size=4;
        gametype=2;
        save_options();
    }
    main_menu();
    endwin();
    return 0;
}
