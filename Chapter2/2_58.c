#include <stdio.h>

 
typedef unsigned char *byte_pointer;
/**
 * // int (1)  
 * 在小端的机器上是 按照 01 00 00 00 
 * 在大端法的机器是 按照 00 00 00 01
 * 
 * 
 * */
int is_little_endian(){

    int i=1;

    byte_pointer starter = (byte_pointer)&i;

    return starter[0] == 1;

}


int main(){

    printf("%.2x",is_little_endian());

}