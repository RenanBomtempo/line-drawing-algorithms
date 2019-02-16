/*
 *  Screen ADT Interface
 * ----------------------------------------------------------------------------
 *  All prototypes of functions related to drawing the screen to the console.
 * ----------------------------------------------------------------------------
 *  Author: Renan Bomtempo
 * ----------------------------------------------------------------------------
 */
#ifndef SCREEN_H
#define SCREEN_H

/*
 * A pixel can be ON (o) or OFF ( ).
 */
enum PixelState {
    ON  = '0',
    OFF = '-'
};

/*
 * Screen structure. Contains width, height and pixel array.
 */
typedef struct Screen {
    int width;
    int height;
    char **pixels;  /*Pixel 2D array*/
}   screen;

/* 
 * Allocate memory for the screen and initialize pixel state as OFF.
 */
screen *NewScreen ( int width, int height );

/* 
 * Prints the screen pixels to the console.
 */
void PrintScreen ( screen *sc );

/*
 * Get the state of a given pixel. It can be ON(35) or OFF(45).
 */
char GetPixelState ( screen scr, int x_coord, int y_coord );

/* 
 * Set the state of a given pixel.
 */
void SetPixelState ( screen *scr, int x_coord, int y_coord, char state );

/* 
 * Free all memory previoulsy allocated for the screen structure.
 */
void TerminateScreen ( screen *scr );

/*
 * Delay the programs execution for a given number of seconds.
 */
void Delay ( float number_of_seconds );

#endif // SCREEN_H