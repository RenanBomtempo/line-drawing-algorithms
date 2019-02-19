/*
 *  Screen ADT Implementation
 * ----------------------------------------------------------------------------
 *  Implementation of all functions related to drawing the screen to the console.
 * ----------------------------------------------------------------------------
 *  Version: 0.3.3
 *  Author: Renan Bomtempo
 * ----------------------------------------------------------------------------
 *  - Create a new screen;
 *  - Get a pixel state;
 *  - Set a pixel state;
 *  - Print the screen in the console;
 *  - Terminate a screen;
 *  - Delay function;
 *  - Clear the screen;
 *  - Choose the position of the origin point on the screen;
 */
#include <stdio.h> 
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include "screen.h"
#define _CONSOLE_LOG_(X)            printf("..."#X"...\n");
#define _NULL_POINTER_CHECK_(X)     if (X == NULL) {perror("ERROR"); exit(EXIT_FAILURE);}
#define _PIXEL_LAYOUT_              " %c"
#define _DELAY_TIME_                0.01f

char g_origin_position = BOTTOM_LEFT;

void Delay ( float number_of_seconds ) 
{ 
    float milli_seconds = 1000 * number_of_seconds; 
    clock_t start_time = clock(); 
  
    // Loop until input time is reached.
    while (clock() < start_time + milli_seconds); 
} 

screen *NewScreen ( int width, int height ) 
{
    _CONSOLE_LOG_(Allocating Memmory for Screen)

    //Initialize screen struct
    screen *scr = (screen*)malloc(sizeof(screen));
    _NULL_POINTER_CHECK_(scr)
    scr->height = height;
    scr->width  = width;

    //Allocating memmory for columns
    scr->pixels = (char**)malloc(height * sizeof(char*));
    _NULL_POINTER_CHECK_(scr->pixels)

    //Allocating memmory for each row
    for (int i = 0; i < height; i++) {
        scr->pixels[i] = (char*)malloc(width * sizeof(char));
        _NULL_POINTER_CHECK_(scr->pixels)
        
        //Set default state as OFF
        for (int j = 0; j < width; j++) {   
            SetPixelState(scr, j, i, OFF);
        }
    }

     _CONSOLE_LOG_(Memmory Succesfuly Allocated)
    
    return scr;
}

void PrintScreen ( screen *scr ) 
{
    _CONSOLE_LOG_(Printing Pixels)
    
    switch (g_origin_position)
    {
        case BOTTOM_LEFT:
            for (int i = scr->height-1; i >= 0; i--) {
                for (int j = 0; j < scr->width; j++) {
                    PrintPixel(GetPixelState(*scr, j, i));
                }
                printf("\n");
            }
            break;
        
        case BOTTOM_RIGHT:
            for (int i = scr->height-1; i >= 0; i--) {
                for (int j = scr->width-1; j >= 0 ; j--) {
                    PrintPixel(GetPixelState(*scr, j, i));
                }
                printf("\n");
            }
            break;
    
        case TOP_LEFT:
            for (int i = 0; i < scr->height; i++) {
                for (int j = 0; j < scr->width; j++) {
                    PrintPixel(GetPixelState(*scr, j, i));
                }
                printf("\n");
            }
            break;
        
        case TOP_RIGHT:
             for (int i = 0; i < scr->height; i++) {
                for (int j = scr->width-1; j >= 0 ; j--) {
                    PrintPixel(GetPixelState(*scr, j, i));
                }
                printf("\n");
            }
            break;

        default:
            //BOTTOM_LEFT
            for (int i = scr->height-1; i >= 0; i--) {
                for (int j = 0; j < scr->width; j++) {
                    PrintPixel(GetPixelState(*scr, j, i));
                }
                printf("\n");
            }
            break;
    }
}

char GetPixelState ( screen scr, int x_coord, int y_coord )
{
    if(x_coord >= scr.width || x_coord < 0 || y_coord >= scr.height || y_coord < 0) {
        printf("ERROR: Trying to access element out of bounds\n x=%d  y=%d", x_coord, y_coord);
        exit(EXIT_FAILURE);
    } else {
        return scr.pixels[y_coord][x_coord];
    }
}

void SetPixelState ( screen *scr, int x_coord, int y_coord,  char state ) 
{
    if(x_coord >= scr->width || x_coord < 0 || y_coord >= scr->height || y_coord < 0) {
        printf("ERROR: Trying to access element out of bounds\n x=%d  y=%d", x_coord, y_coord);
        exit(EXIT_FAILURE);
    } else {
        scr->pixels[y_coord][x_coord] = state;
    }
}

void TerminateScreen ( screen *scr ) 
{
    _CONSOLE_LOG_(Terminating Screen)

    for (int i = 0; i < scr->height; i++) {
        free(scr->pixels[i]);
    }
    free(scr->pixels);
    free(scr);
    
    _CONSOLE_LOG_(Screen Terminated Succesfuly)
}

void ClearScreen ( screen *scr )
{
    _CONSOLE_LOG_(Clearing Screen)

    for (int i = 0; i < scr->height; i++) {
        for (int j = 0; j < scr->width; j++) {
            SetPixelState(scr, j, i, OFF);
        }
    }    

    _CONSOLE_LOG_(Screen Cleared Succesfuly)
}

void SetScreenOriginPoisition ( char origin_position ) 
{
    g_origin_position = origin_position;
}

void PrintPixel ( char state )
{
    if (state == ON) Delay(_DELAY_TIME_);
    printf(_PIXEL_LAYOUT_, state);
}