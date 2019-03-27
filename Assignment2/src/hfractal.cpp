/*
 * File: HFractal.cpp
 * ------------------
 * This program draws an H-fractal on the graphics window.int main() {
 */

#include "gwindow.h"

/* Function prototypes */

void drawHFractal(GWindow & gw, double x, double y, double size, int order);

/* Main program */

int main() {
    GWindow gw;
    double xc = gw.getWidth() / 2;
    double yc = gw.getHeight() / 2;
    drawHFractal(gw, xc, yc, 100, 3);
    return 0;
}

/*
 * Function: drawHFractal
 * Usage: drawHFractal(gw, x, y, size, order);
 * -------------------------------------------
 * Draws a fractal diagram consisting of an H in which each additional
 * fractal layer draws half-size fractals at the four endpoints of each H.
 */

void drawHFractal(GWindow & gw, double x, double y, double size, int order) {
    // TODO
    double lineUnit = 0.5*size;
    double xl = x - lineUnit;
    double xr = x + lineUnit;
    double yt = y - lineUnit;
    double yb = y + lineUnit;

    GPoint lefttop(xl, yt);
    GPoint righttop(xr, yt);
    GPoint leftbottom(xl, yb);
    GPoint rightbottom(xr, yb);
    GPoint leftMidway(xl, y);
    GPoint rightMidway(xr, y);
    GPoint center(x, y);

    gw.drawLine(center, leftMidway);
    gw.drawLine(leftbottom, lefttop);
    gw.drawLine(center, rightMidway);
    gw.drawLine(rightbottom, righttop);

    if (order != 1) {
        drawHFractal(gw, xl, yt, lineUnit, order-1);
        drawHFractal(gw, xl, yb, lineUnit, order-1);
        drawHFractal(gw, xr, yt, lineUnit, order-1);
        drawHFractal(gw, xr, yb, lineUnit, order-1);
    }
}
