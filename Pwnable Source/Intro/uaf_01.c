#include <string.h>
#include <stdio.h>

//Simple heap free list example by b1ack0wl

int main(int argc, char **argv[]){
char *heap_of;
char *heap_of2;

if (argc < 2){
printf("Usage: %s argument\r\n-By b1ack0wl\r\n", argv[0]);
exit(1);
} 

char message[17] = "StringThatisUsed\0";

printf("\r\nWelcome to the first Use-After-Free exercise!\r\n\r\n");
heap_of = malloc(sizeof(message)); 
strncpy(heap_of,message,sizeof(message));
printf("Heap Address 1 of 17 bytes: %p\r\n", heap_of);
free(heap_of);
int size = strlen(argv[1]);
heap_of2 = malloc(size);
printf("Heap Address 2 of %d bytes: %p \r\n", size, heap_of2);
printf("Copying contents of argv[1] to Heap Address 2\r\n\r\n");
strncpy(heap_of2, argv[1], size);
if (heap_of2 != heap_of){
printf("You entered %s \r\n", heap_of);
printf("Try Again\r\n");
free(heap_of2);
exit(1);
}
else{
printf("Awesome! :D\r\n");
free(heap_of2);
}
return 0;
}
