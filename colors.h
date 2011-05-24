/* Copyright (c) 2011 Kevin Wells */
/* Ascii Pong may be freely redistributed.  See license for details. */

#ifndef colors_h
#define colors_h

using namespace std;

/**To turn a color on, simply call its function with true. To turn it off, call the function again with false. For instance, to display a word in red: call red(true), print the word, then
call red(false).*/

void white(bool color){
    if(color==true)
        attron(COLOR_PAIR(1));
    if(color==false)
        attroff(COLOR_PAIR(1));
}

void white_highlight(bool color){
    if(color==true)
        attron(COLOR_PAIR(2));
    if(color==false)
        attroff(COLOR_PAIR(2));
}

void icy(bool color){
    if(color==true)
        attron(COLOR_PAIR(3));
    if(color==false)
        attroff(COLOR_PAIR(3));
}

void icy_highlight(bool color){
    if(color==true)
        attron(COLOR_PAIR(4));
    if(color==false)
        attroff(COLOR_PAIR(4));
}

void fiery(bool color){
    if(color==true)
        attron(COLOR_PAIR(5));
    if(color==false)
        attroff(COLOR_PAIR(5));
}

void fiery_highlight(bool color){
    if(color==true)
        attron(COLOR_PAIR(6));
    if(color==false)
        attroff(COLOR_PAIR(6));
}

void pingpong(bool color){
    if(color==true)
        attron(COLOR_PAIR(7));
    if(color==false)
        attroff(COLOR_PAIR(7));
}

void pingpong_highlight(bool color){
    if(color==true)
        attron(COLOR_PAIR(8));
    if(color==false)
        attroff(COLOR_PAIR(8));
}

void girly(bool color){
    if(color==true)
        attron(COLOR_PAIR(9));
    if(color==false)
        attroff(COLOR_PAIR(9));
}

void girly_highlight(bool color){
    if(color==true)
        attron(COLOR_PAIR(10));
    if(color==false)
        attroff(COLOR_PAIR(10));
}

#endif
