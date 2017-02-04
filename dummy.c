#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    printf(1, "Starting dummy process...\n");

    sleep(1000);

    printf(1, "Finished dummy process.\n");
    exit();
}