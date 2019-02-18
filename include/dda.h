/*
 *  Digital Differential Analyser Interface
 * ----------------------------------------------------------------------------
 *  All prototypes of functions of the DDA algorithm.
 * ----------------------------------------------------------------------------
 *  Author: Renan Bomtempo
 * ----------------------------------------------------------------------------
 */
#ifndef DDA_H
#define DDA_H

/*
 * Draw a line on the screen between points p1 and p2 using DDA algorithm.
 */
void DrawLineUsingDDA ( screen *scr, point p1, point p2 );

#endif // DDA_H