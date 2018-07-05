/**********************************************************
  File:          eratosthenes.h
  Description:   A program that finds all of the prime
                 numbers below a certain limit.
		 The parallel functions.

  Author:        Dana Vrajitoru
  Organization:  IUSB
  Date:          September 30, 2004
***********************************************************/

#ifndef ERATOSTHENES_H
#define ERATOSTHENES_H

const int terminator = -1;

// The first process starts from the first prime number, 2, displays
// it, then generates the entire list of numbers and sends the one not
// divisible by 2 to the next process.
void First_process(int nb_proc);

// Receives the first prime number from the previous process, then a
// list of numbers ended by a terminator. The first number is prime
// and is displayed. For each of the other numbers, if they are not
// divisible by the first one, the are sent to the next process.
void Intermediate_process(int proc_id);

// Last process: it receives numbers from the previous one, but
// doesn't any number forwards. All of the numbers that it receives
// that are not divisible by the first one are prime numbers, so this
// process displays them.
void Last_process(int proc_id);

#endif