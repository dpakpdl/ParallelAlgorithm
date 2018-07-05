#include <mpi.h>
#include "eratosthenes.h"

//  The main function

int main(int argc, char **argv)
{
  int proc_id, nb_proc, n;

  /* Initialize MPI */
  MPI_Init (&argc, &argv);

  /* Get the rank of this process */
  MPI_Comm_rank (MPI_COMM_WORLD, &proc_id);

  /* Get nb of processes */
  MPI_Comm_size (MPI_COMM_WORLD, &nb_proc);

  if (proc_id == 0)
    First_process(nb_proc);
  else if (proc_id < nb_proc - 1)
    Intermediate_process(proc_id);
  else
    Last_process(proc_id);

  /* Finalize MPI */
  MPI_Finalize ();
  return 0;
}

// End of the program