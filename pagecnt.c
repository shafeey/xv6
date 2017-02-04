#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    int LOOP = 20;
    int stdout = 1;

    int** arr;

    arr= (int**) malloc(LOOP * sizeof(int*));

    int ret;
    ret = info(3);
    printf(stdout, "Number of Pages: %d\n", ret);

    int i;
    for(i=0; i<LOOP; i++){
        printf(stdout, "\nAllocating memory...\n");
        arr[i] = (int*) malloc(4096);
        ret = info(3);
        printf(stdout, "Number of Pages: %d\n", ret);
    }

    for(i=0; i<LOOP; i++){
        free(arr[i]);
    }
    free(arr);

	exit();
}