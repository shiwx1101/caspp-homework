#include <stdio.h>
#include <limits.h>
/**
 * 
 * 
 * */

/* Compute float(i) */

typedef unsigned float_bits;
/**
 * i range from -2^31 ~ 2^31-1
 * 
 * round to even 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */

int leftmost_one(unsigned x)
{
    unsigned sizeof_unsigned = sizeof(unsigned);
    unsigned w = sizeof_unsigned << 3;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x^(x>>1);
}

int end_with_zero(unsigned x){
    return !(x&1);
}


float_bits float_i2f(int i){
    if(i==INT_MIN){
        return (float_bits)0xCF000000; //2^-31
    }
    if(i==0){
        return 0;
    }
    int sign = i>>31;
    int abs_i = ((~i+1)&sign) + ((~sign)&i);

    int l_i = leftmost_one((unsigned)abs_i);
    unsigned shift_count = 0;

    while (l_i!=0)
    {
        l_i<<=1;
        shift_count++;
    }
    unsigned frac = ((unsigned)abs_i<<shift_count)>>9;
    unsigned exp = (127+32-shift_count);

    if(shift_count>=9){//不需要舍入 24位整数 浮点数可以精确表示出来
        return sign|(exp<<23)|frac;
    }else{//<9的
        unsigned bias = ~(-1<<(9-shift_count));
        unsigned lost = (unsigned)i&bias;

        if(lost==0){
            return sign|(exp<<23)|frac;
        }

        if(lost>leftmost_one(bias)){
            i=((i>>(8-shift_count))+1)<<(8-shift_count);
            return float_i2f(i);
        }else if (lost<leftmost_one(bias))
        {
            return sign|(exp<<23)|frac;
        }else
        {// halfway 
            if(end_with_zero(frac)){
                return float_i2f(i-lost);
            }
            return float_i2f(i+lost);
            
        }
   
    }
}

unsigned int float2hexRepr(float* a){
    unsigned int c;  
    c= ((unsigned int*)a)[0];   
    return c;

}
    int main(int argc, char const *argv[])
{
    printf("%#.8x\n", float_i2f(0xfffffe8));
    

    float f1 = 268435432.0;
    printf("%x\n", float2hexRepr(&f1));
    return 0;
}


