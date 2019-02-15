/*
 *  Screen Implementation
 * ----------------------------------------------------------------------------
 *  Implementation of all functions related to drawing points to the console.
 * ----------------------------------------------------------------------------
 *  Version: 0.0
 *  Author: Renan Bomtempo
 * ----------------------------------------------------------------------------
 */
#include "screen.h"
#define _CONSOLE_LOG_(X) printf("..."#X"...\n");

screen *NewScreen ( int width, int height ) 
{
    _CONSOLE_LOG_(Allocating Memmory for Screen)

    //Initialize screen struct
    screen *scr = (screen*)malloc(sizeof(screen));
    if (scr == NULL) /*NULLCHECK*/ {
        perror("ERROR");
        exit(EXIT_FAILURE);
    }
    scr->height = height;
    scr->width  = width;

    //Allocating memmory for columns
    scr->pixels = (char**)malloc(height * sizeof(char*));
    if (scr->pixels == NULL) /*NULLCHECK*/ {
        perror("ERROR");
        exit(EXIT_FAILURE);
    }
    //Allocating memmory for each row
    for (int i = 0; i < height; i++) {
        scr->pixels[i] = (char*)malloc(width * sizeof(char));
        if (scr->pixels == NULL) /*NULLCHECK*/ {
            perror("ERROR");
            exit(EXIT_FAILURE);
        }
        //Set default state as OFF
        for (int j = 0; j < width; j++) {   
            SetPixelState(scr, j, i, OFF);
        }
    }

     _CONSOLE_LOG_(Memmory Allocated Succesfuly)
    
    return scr;
}

void PrintScreen ( screen *scr ) 
{
    _CONSOLE_LOG_(Printing Pixels)

    for (int i = 0; i < scr->height; i++) {
        for (int j = 0; j < scr->width; j++) {
            printf(" %c ", scr->pixels[i][j]);
        }
        printf("\n");
    }
}

char GetPixelState ( screen *scr, int x_coord, int y_coord ) 
{
     if(x_coord >= scr->width || x_coord < 0 || y_coord >= scr->height || y_coord < 0) {
        perror("ERROR");
        exit(EXIT_FAILURE);
    } else {    
        return scr->pixels[y_coord][x_coord];
    }
}

void SetPixelState ( screen *scr, int x_coord, int y_coord,  char state ) 
{
    if(x_coord >= scr->width || x_coord < 0 || y_coord >= scr->height || y_coord < 0) {
        printf("ERROR: Trying to access element out of bounds\n");
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