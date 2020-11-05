/** lab26.h
* ================================================================
* Name: CS210
* Section: n/a
* Project: Lab26 - Vector ADT
* =================================================================
*/

#ifndef MYEXE_LAB26_H
#define MYEXE_LAB26_H

#include <string.h>
#include <stdio.h>
#include <math.h>
#include "vector.h"

int getNumLines(char filename[]);
void readFile(char filename[], vector* vectorPtr, int records);
void printData(vector* theData, int numElem);

#endif //MYEXE_LAB26_H
