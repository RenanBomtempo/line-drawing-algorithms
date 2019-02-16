/*
 *  Main file for executing some Line Drawing Algorithms.
 * ----------------------------------------------------------------------------
 *  Version: 0.1
 *  Author: Renan Bomtempo
 * ----------------------------------------------------------------------------
 *  - Create a screen and manipulate its pixels states.
 *  - Draw a line between 2 points using DDA.
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "point.h"
#include "screen.h"
#include "dda.h"
#define _SCREEN_WIDTH_      80
#define _SCREEN_HEIGHT_     45

int main ( int argc, char const *argv[] ) 
{
    screen *scr = NewScreen(_SCREEN_WIDTH_, _SCREEN_HEIGHT_);
    
    point p1, p2, p3;

    SetPointCoordinates(&p1, 2,  5);
    SetPointCoordinates(&p2, 75, 39);
    SetPointCoordinates(&p3, 35, 1);

    DrawLineUsingDDA(scr, p2, p1);
    DrawLineUsingDDA(scr, p1, p3);
    DrawLineUsingDDA(scr, p3, p2);

    PrintScreen(scr);

    TerminateScreen(scr);
} 