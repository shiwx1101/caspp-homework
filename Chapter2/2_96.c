#include <stdio.h>
/**
 * 
 * 
 * */

/* Compute (int)f */

typedef unsigned float_bits;

int float_f2i(float_bits f){
    unsigned sign = f>>31;
    unsigned exp = f>>23&0xff;
    unsigned frac = f&0x7fffff;
    unsigned value = 0;
    // int range - 2^31  ~  +2^31-1

    // 127  E = 126-127 =-1  v=0....
    if(exp<0x7f){
        return 0;
    }
    // 157-127 = 30 E = 30 v= 1...>>30
    if(exp>157){
        return (int)0x80000000;
    }
    //
    if(sign==0){
        value = frac|0x800000;//add imply one
    }else{
        value = frac|0xff800000;
    }

    if(exp-150>=0){
        value = value<<(exp-150);
    }else
    {
        value = !sign*(value>>(150-exp))+sign*((value+2^(150-exp)-1)>>(150-exp));
    }

    return (int)value;

}


int main(){
    printf("%x",float_f2i(0x3f800000));
}                               