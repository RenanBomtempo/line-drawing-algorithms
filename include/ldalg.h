/*
 *  Bresenham's Algorithm Interface (Integer Version)
 * ----------------------------------------------------------------------------
 *  Protoypes of all functions used for ldalg algorithm.
 * ----------------------------------------------------------------------------
 *  Author: Renan Bomtempo
 * ----------------------------------------------------------------------------
 */
#ifndef LDALG_H
#define LDALG_H

/*
 * Axis of maximum movement.
 */
enum DrivingAxis {
    X,
    Y
};

/*
 * Draw a line between points p1 and p2 using the Bresenham algorithm.
 */
void Bresenham ( screen *scr, point p1, point p2 );

/*
 * Draw a line between points p1 and p2 using the Digital Differential Analyser algorithm.
 */
void DigitalDifferentialAnalyser ( screen *scr, point p1, point p2 );

/*
 * Draw a line between points p1 and p2 using the INTEGER version of Midpoint algorithm.
 */
void FloatMidpoint ( screen *scr, point p0, point p1 );

/*
 * Draw a line between points p1 and p2 using the FLOAT version of Midpoint algorithm.
 */
void IntMidpoint ( screen *scr, point p0, point p1 );

#endif // LDALG_H