#include "types.h"
#include "stat.h"
#include "user.h"
#include "syscall.h"

#define PGSIZE 4096

int
main(int argc, char *argv[]){
	printf(1, "hello\n");
	int i, j;
	char *arr[27];
	char input[10];

	for (i = 0; i < 15; ++i)
	{
		arr[i] = sbrk(PGSIZE);
		printf(1, "arr[%d]=0x%x\n", i, arr[i]);
	}
	printf(1, "Called sbrk(PGSIZE) 15 times - all physical pages taken.\nPress any key...\n");
	gets(input, 10);
	for (i = 0; i < 13; ++i) {
		for (j = 0; j < PGSIZE; j++)
			arr[i][j] = 'k';
	}
	printf(1, "Written to all 15 freely allocated pages successfuly\nPress any key...\n");
	gets(input, 10);
	exit();
}
