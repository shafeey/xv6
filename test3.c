#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
  int num_tickets = 10;
  printf(1, "Started process id %d with %d tickets\n", getpid(), num_tickets);

  settickets(num_tickets);
  int i,k;
  const int loop=43000;

  for(i=0;i<loop;i++)
    for(k=0;k<loop;k++)
        asm("nop");

  getstat();

  exit();
}