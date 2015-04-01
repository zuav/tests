/*
  Compute heights in centimeters for a range of heights
  expressed in feet and inches
*/

import std.stdio;

void main()
{
    // Values unlikely to change soon
    immutable inches_per_foot = 12;
    immutable cm_per_inch = 2.54;

    // Loop'n write
    foreach (feet; 5 .. 7) {
        foreach (inches; 0 .. inches_per_foot) {
            //writeln(feet, "'", inches, "''\t", (feet * inches_per_foot + inches) * cm_per_inch);
            writefln("%s'%s''\t%s", feet, inches, (feet * inches_per_foot + inches) * cm_per_inch);
        }
    }
}
