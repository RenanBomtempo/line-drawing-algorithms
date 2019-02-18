/*
 *  Main file for executing some Line Drawing Algorithms.
 * ----------------------------------------------------------------------------
 *  Version: 0.2.1
 *  Author: Renan Bomtempo
 * ----------------------------------------------------------------------------
 *  - Create a screen and manipulate its pixels states.
 *  - Draw a line between 2 points using DDA.
 *  - Draw a line between 2 points using Bresenham.
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "point.h"
#include "screen.h"
#include "dda.h"
#include "bresenham.h"

#define _SCREEN_WIDTH_      80
#define _SCREEN_HEIGHT_     45

int main ( int argc, char const *argv[] ) 
{
    screen *scr = NewScreen(_SCREEN_WIDTH_, _SCREEN_HEIGHT_);
        
    point p1, p2, p3;

    SetPointCoordinates(&p1, 0, 0);
    SetPointCoordinates(&p2, 3, 5);
    SetPointCoordinates(&p3, 5, 3);

    /*DrawLineUsingDDA(scr, p2, p1);
    DrawLineUsingDDA(scr, p1, p3);
    DrawLineUsingDDA(scr, p3, p2);
    PrintScreen(scr);*/

    DrawLineUsingBresenham(scr, p1, p2);
    PrintScreen(scr);

    TerminateScreen(scr);

    return 0;
} 