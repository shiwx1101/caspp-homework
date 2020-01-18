#include <stdio.h>
/**
 * 
 * 
 * */

/* Compute 2*f ,if f is NaN return */

typedef unsigned float_bits;

float_bits float_twice(float_bits f){
    unsigned sign = f>>31;
    unsigned exp = f>>23&0xff;
    unsigned frac = f&0x7fffff;

    // if f is NaN  ; exp field is all ones;  fraction field is nozero;
    if(exp==0xff&&frac){
        return f;
    }
    //+-0
    if(exp==0&&frac==0){
        return 0;
    }
    //denormalized
    if(exp==0&&frac){
        return (sign<<31)|(frac<<1);
    }
    // very close to infinity
    if(exp==0xfe){
        return (sign<<31)|((exp+1)<<23)|(0);//infinity
    }

    return (sign<<31)|((exp+1)<<23)|frac ;




}


int main(){
    printf("%x",float_twice(0b00000000100000000000000000000001));
}                               