#include <stdio.h>
/**
 *
 * 
 * 
 * */
unsigned rotate_left(unsigned x,int n){
     unsigned right = x>>(sizeof(int)*8-n);
     unsigned left = x<<n;
     return left|right;

}


int main(){

    printf("%x",rotate_left(0x12345678,20));
}