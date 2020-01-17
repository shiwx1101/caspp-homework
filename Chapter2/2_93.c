#include <stdio.h>
/**
 * 
 * 
 * */

/* Compute |f|,if f is NaN return */

typedef unsigned float_bits;

float_bits float_absval(float_bits f){
    unsigned sign = f>>31;
    unsigned exp = f>>23&0xff;
    unsigned frac = f&0x7fffff;

    // whether f is NaN  ; exp field is all ones;  fraction field is nozero;

    if(exp==0xff&&frac){
        return f;
    }
    return  (0)|(exp<<23)|frac;




}


int main(){
    printf("%x",float_absval(0b11111111100000000000000000000001));
}                               