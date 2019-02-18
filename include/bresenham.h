/*
 *  Bresenham's Algorithm Interface (Integer Version)
 * ----------------------------------------------------------------------------
 *  Protoypes of all functions used for bresenham algorithm.
 * ----------------------------------------------------------------------------
 *  Author: Renan Bomtempo
 * ----------------------------------------------------------------------------
 */
#ifndef bresenham_H
#define bresenham_H

/*
 * Axis of maximum movement.
 */
enum DrivingAxis {
    X,
    Y
};

/*
 * Draw a line between points p1 and p2 using the bresenham algorithm.
 */
void DrawLineUsingBresenham ( screen *scr, point p1, point p2 );

#endif // bresenham_H