/* Copyright (c) 2011 Kevin Wells */
/* Ascii Pong may be freely redistributed.  See license for details. */

#ifndef ai_h
#define ai_h

using namespace std;

void move_up_ai(){
    set_color(true);
    if(p2_y>1){
    p2_y--;
    mvprintw(p2_y+paddle_size,p2_x," ");
    }
    if(p2_y+paddle_size==24)
    mvprintw(24,p2_x,"_");
    set_color(false);
}

void move_down_ai(){
    set_color(true);
    if(p2_y+paddle_size<25){
    p2_y++;
    mvprintw(p2_y-1,p2_x," ");
    }
    set_color(false);
}

void ai_move_properly(){
    if(p2_y>ball_y)
        move_up_ai();
    if(p2_y+paddle_size-1<ball_y)
        move_down_ai();
}

void ai_move_randomly(){
    int x=random_range(0,1);
    if(x==0)
        move_up_ai();
    if(x==1)
        move_down_ai();
}

void ai_move(){
    int x;
    switch(difficulty){
        /**Very easy mode: There is a 30% chance the ai will move his paddle in the direction of the ball, a 20% chance he will move it randomly, and a 50% chance that he will not move his paddle
        this check.*/
        case 0:
        x=random_range(1,100);
        if(x>=1 && x<=30)
            ai_move_properly();
        if(x>=31 && x<=50)
            ai_move_randomly();
        break;
        /**Easy mode: There is a 35% chance the ai will move his paddle in the direction of the ball, and a 65% chance that he will not move his paddle this check.*/
        case 1:
        x=random_range(1,100);
        if(x>=1 && x<=35)
            ai_move_properly();
        break;
        /**Normal mode: There is a 50% chance the ai will move his paddle in the direction of the ball, and a 50% chance that he will not move his paddle this check.*/
        case 2:
        x=random_range(1,100);
        if(x>=1 && x<=50)
            ai_move_properly();
        break;
        /**Impossible mode: The computer will move his paddle in the direction of the ball every check.*/
        case 3:
        ai_move_properly();
        break;
    }
}

#endif
