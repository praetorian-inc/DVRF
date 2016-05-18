#include <string.h>
#include <stdio.h>

//Simple Heap Overflow by b1ack0wl for E1550

int main(int argc, char **argv[]){
char *heap_of;
char *heap_of2;

if (argc < 2){
printf("Usage: heap_overflow_01 argument\r\n-By b1ack0wl\r\n");
exit(1);
} 


printf("\r\nWelcome to the first Heap Overflow exercise!\r\n\r\n");
heap_of = malloc(100); 
printf("Heap Address 1 of 100 bytes: %p\r\n", heap_of);
heap_of2 = malloc(100);
printf("Heap Address 2 of 100 bytes: %p\r\n", heap_of2);
printf("Copying contents of argv[1] to Heap Address 1\r\n\r\n");
strcpy(heap_of, argv[1]);
//free(heap_of);
free(heap_of2);

printf("You entered %s \r\n", heap_of);
printf("Try Again\r\n");

return 0;
}

void dat_shell(){

printf("Congrats! I will now execute /bin/sh - b1ack0wl\r\n");
system("/bin/sh -c");
exit(0);

}
