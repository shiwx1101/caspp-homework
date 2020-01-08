#include <stdio.h>
/**
 *
 * n =6  --> 0x3f(0011 1111)  n=17 --> 0x1ffff(0001 1111 1111 1111 1111)
 * 
 * 
 * 
 * 
 * */

int lower_one_mask(int n){
    return (unsigned)-1>>(sizeof(int)*8-n);
}

int main(){

    printf("%x",lower_one_mask(31));
}