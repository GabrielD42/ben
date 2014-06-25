/** @file */

#ifndef BASE_H
#define BASE_H

// to be declared in main program

void setup();
void loop();
void cleanup();

/**
 * main function, should not be touched. Instead define setup(), loop() and cleanup(). provides safe exiting and GPIO access
 */
int main();

#endif