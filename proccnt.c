#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    int stdout = 1;

    int ret;
    ret = info(1);
    printf(stdout, "Number of processes: %d\n\n", ret);

//    info(2);
//    info(3);

	exit();
}