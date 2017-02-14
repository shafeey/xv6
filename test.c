#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
  int num_proc = 3;
  int ticket1 = 30;
	int ticket2 = 20;
	int ticket3 = 10;
  const int loop=43000;

  settickets(50);

	int pid[3];
  int tickets[3] = {ticket1, ticket2, ticket3};

  int id = 0;
  int n;
  for(n=0; n < num_proc; n++){
    id = fork();
    if(id == 0){
      settickets(tickets[n]);
      printf(1, "Starting process %d with %d tickets. ID: %d\n", n, tickets[n],  getpid() );
      break;
    } else {
      pid[n] = id;
    }
  }


  if(id == 0){
    int i,k;
    for(i=0;i<loop;i++)
      for(k=0;k<loop;k++)
        asm("nop");
  } else {
    int wid = wait();
    printf(1, "\n\n...\n\n");
    if(wid){
      int tick[3];
      tick[0] = getstat(pid[0]);
      tick[1] = getstat(pid[1]);
      tick[2] = getstat(pid[2]);

      int t=tick[0] + tick[1] + tick[2];

      printf(1, "CPU time for process %d:\t%d, (%d\%) \n", 0, tick[0], tick[0]*100/t);
      printf(1, "CPU time for process %d:\t%d, (%d\%) \n", 1, tick[1], tick[1]*100/t);
      printf(1, "CPU time for process %d:\t%d, (%d\%) \n", 2, tick[2], tick[2]*100/t);
    } else {
      printf(1, "Child process didn't return properly\n");
      exit();
    }

    wait();
    wait();

  }

  exit();
}
