#include <mpi.h>
#include <cmath>
#include <iostream>
using namespace std;
#include "eratosthenes.h"

// The first process starts from the first prime number, 2, displays
// it, then generates the entire list of numbers and sends the one not
// divisible by 2 to the next process.
void First_process(int nb_proc)
{
  int x = 2, number, limit;

  if (nb_proc == 1)
    limit = 8;
  else
    limit = 4 * nb_proc * nb_proc - 1;

  cout << "Here are the prime numbers between 1 and "
       << limit << endl;

  cout << x << endl;
  for (number=3; number <= limit; number++)
    if (number % x != 0)
      MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
  number = terminator;
  MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
}

// Receives the first prime number from the previous process, then a
// list of numbers ended by a terminator. The first number is prime
// and is displayed. For each of the other numbers, if they are not
// divisible by the first one, the are sent to the next process.
void Intermediate_process(int proc_id)
{
  int x, number;
  MPI_Status status;
  MPI_Recv(&x, 1, MPI_INT, proc_id -1, 0, MPI_COMM_WORLD, &status);
    cout << x << endl;
  do {
    MPI_Recv(&number, 1, MPI_INT, proc_id-1, 0, MPI_COMM_WORLD, &status);
    if (number == terminator || number % x != 0)
      MPI_Send(&number, 1, MPI_INT, proc_id + 1, 0, MPI_COMM_WORLD);
  } while (number != terminator);
}

// Last process: it receives numbers from the previous one, but
// doesn't any number forwards. All of the numbers that it receives
// that are not divisible by the first one are prime numbers, so this
// process displays them.
void Last_process(int proc_id)
{
  int x, number;
  MPI_Status status;
  MPI_Recv(&x, 1, MPI_INT, proc_id -1, 0, MPI_COMM_WORLD, &status);
    cout << x << endl;
  do {
    MPI_Recv(&number, 1, MPI_INT, proc_id-1, 0, MPI_COMM_WORLD, &status);
    if (number != terminator && number % x != 0)
      cout << number << endl;
  } while (number != terminator);
}
