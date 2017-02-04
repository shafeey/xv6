#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    int stdout = 1;

    int ret;
    ret = info(2);
    printf(stdout, "Number of syscall done by process: %d\n", ret);

    int i;
    for(i=0; i<10; i++){
        printf(stdout, "Invoking system call... Uptime: %d\n", uptime());
        ret = info(2);
        printf(stdout, "Number of syscall done by process: %d\n", ret);
    }

	exit();
}