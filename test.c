#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
  settickets(30);
  printf(1, "Starting process with id %d\n", getpid());

  int i,k;
  const int loop=20000;

  for(i=0;i<loop;i++)
    for(k=0;k<loop;k++)
        asm("nop");

  getstat();

	exit();
}