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

    // Remain window displayed for 5 seconds
    gw.sleep(5000);
    gw.setCloseOperation(gw.CLOSE_EXIT);
    gw.close();

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
    // Drawing Attributes
    double lineUnit = 0.5*size;
    double xl = x - lineUnit;
    double xr = x + lineUnit;
    double yt = y - lineUnit;
    double yb = y + lineUnit;

    // The vertical line, the left horizontal line and the right horizontal line
    GLine vLine(xl, y, xr, y);
    GLine hLineL(xl, yt, xl, yb);
    GLine hLineR(xr, yt, xr, yb);

    // Draw objects
    gw.draw(vLine);
    gw.draw(hLineL);
    gw.draw(hLineR);

    if (order != 0) {
        // Recursive drawing with smaller scale
        drawHFractal(gw, xl, yt, lineUnit, order-1);
        drawHFractal(gw, xl, yb, lineUnit, order-1);
        drawHFractal(gw, xr, yt, lineUnit, order-1);
        drawHFractal(gw, xr, yb, lineUnit, order-1);
    }
}
