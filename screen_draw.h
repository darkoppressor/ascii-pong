/* Copyright (c) 2011 Kevin Wells */
/* Ascii Pong may be freely redistributed.  See license for details. */

#ifndef screen_draw_h
#define screen_draw_h

using namespace std;

void draw_borders(){
    set_color(true);
    for(int x=0;x<80;x++){
        mvprintw(0,x,"_");
    }
    for(int x=0;x<80;x++){
        mvprintw(24,x,"_");
    }
    for(int y=1;y<24;y++){
        mvprintw(y,39,"|");
    }
    mvprintw(0,39,"\xDB");
    mvprintw(24,39,"\xDB");
    set_color(false);
}

void check_for_net(){
    if(ball_x==39 && ball_y!=0 && ball_y!=24)
    mvprintw(ball_y,ball_x,"|");
    if(ball_x==39 && ball_y==0)
    mvprintw(ball_y,ball_x,"\xDB");
    if(ball_x==39 && ball_y==24)
    mvprintw(ball_y,ball_x,"\xDB");
}

void draw(){
    set_color(true);
    mvprintw(p1_y,p1_x,"\xDB");
    mvprintw(p2_y,p2_x,"\xDB");
    if(paddle_size>1){
    mvprintw(p1_y+1,p1_x,"\xDB");
    mvprintw(p2_y+1,p2_x,"\xDB");
    }
    if(paddle_size>2){
    mvprintw(p1_y+2,p1_x,"\xDB");
    mvprintw(p2_y+2,p2_x,"\xDB");
    }
    if(paddle_size>3){
    mvprintw(p1_y+3,p1_x,"\xDB");
    mvprintw(p2_y+3,p2_x,"\xDB");
    }
    if(paddle_size>4){
    mvprintw(p1_y+4,p1_x,"\xDB");
    mvprintw(p2_y+4,p2_x,"\xDB");
    }
    mvprintw(ball_y,ball_x,"\xDB");
    if(gametype==1){
    if(timer_minutes<10)
    mvprintw(0,37,"0%d",timer_minutes);
    if(timer_minutes>=10)
    mvprintw(0,37,"%d",timer_minutes);
    mvprintw(0,39,":");
    if(timer_seconds<10)
    mvprintw(0,40,"0%d",timer_seconds);
    if(timer_seconds>=10)
    mvprintw(0,40,"%d",timer_seconds);
    }
    mvprintw(0,15,"%d",p1_score);
    mvprintw(0,62,"%d",p2_score);
    set_color(false);
}

#endif
