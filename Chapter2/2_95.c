#include <stdio.h>
/**
 * 
 * 
 * */

/* Compute 0.5*f ,if f is NaN return  f */

typedef unsigned float_bits;

float_bits float_twice(float_bits f){
    unsigned sign = f>>31;
    unsigned exp = f>>23&0xff;
    unsigned frac = f&0x7fffff;

    // if f is NaN  ; exp field is all ones;  fraction field is nozero;
    if(exp==0xff&&frac){
        return f;
    }
    
    //very close to denormalized values
    if(exp<=1){
        return (sign<<31)|((exp|frac)>>1);
    }
    // infinity
    if(exp==0xff){
        return f;
    }

    return (sign<<31)|((exp-1)<<23)|frac ;




}


int main(){
    printf("%x",float_twice(0b00000000100000000000000000000001));
}                               