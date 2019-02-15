/*
 *  An implementation of the DDA algorithm in C.
 * ----------------------------------------------------------------------------
 *  Version: 0.0
 *  Author: Renan Bomtempo
 * ----------------------------------------------------------------------------
 *  - Create a screen and manipulate its pixels states.
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "screen.h"
#include "dda.h"
#define _SCREEN_WIDTH_  5
#define _SCREEN_HEIGHT_ 5

int main ( int argc, char const *argv[] ) 
{
    screen *scr = NewScreen(_SCREEN_WIDTH_, _SCREEN_HEIGHT_);

    //SCREEN TEST
    SetPixelState(scr, 0, 0, ON);
    SetPixelState(scr, 0, 1, ON);
    SetPixelState(scr, 0, 2, ON);
    SetPixelState(scr, 0, 3, ON);
    SetPixelState(scr, 0, 4, ON);

    SetPixelState(scr, 1, 0, ON);
    SetPixelState(scr, 2, 0, ON);
    SetPixelState(scr, 3, 0, ON);
    SetPixelState(scr, 4, 0, ON);

    SetPixelState(scr, 0, 4, ON);
    SetPixelState(scr, 1, 4, ON);
    SetPixelState(scr, 2, 4, ON);
    SetPixelState(scr, 3, 4, ON);
    SetPixelState(scr, 4, 4, ON);
    
    SetPixelState(scr, 4, 0, ON);
    SetPixelState(scr, 4, 1, ON);
    SetPixelState(scr, 4, 2, ON);
    SetPixelState(scr, 4, 3, ON);

    SetPixelState(scr, 2, 2, ON);

    PrintScreen(scr);

    TerminateScreen(scr);
} 