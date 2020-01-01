#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer starter,size_t len){

    size_t i;
    for (size_t i = 0; i < len; i++)
    {
        printf("%.2x",starter[i]);
    }

    printf("\n");

}

void  show_short(short x){
    show_bytes((byte_pointer)&x,sizeof(short));
}

void show_long(long x){
    show_bytes((byte_pointer)&x,sizeof(long));
}

void show_double(double x){
    show_bytes((byte_pointer)&x,sizeof(double));
}


int main(){
    short x = 127;
    long y = (long)x;
    double z = (double)x;

    show_short(x);
    show_long(y);
    show_double(z);


// 7f00
// 7f000000

// 0000000000c05f40     
// 小端法如上显示  正真的浮点数二进制表示为 40 5f c0 00 00 00 00 00  根据 k= 11 n =52 
// s = 0 
// exp 字段的值为  100 0000 0101 (11位) (1029)  ==>  E = e - Bias = 1029 - 1023 = 6 
// frac字段值为 1111 1100 0000 0000 .... 0000 (共52位)  ==> M = 1.1111 11 
//  (-1)^s*2^E*M = 1.1111 11 >>6 =1 1111 11 = 127 (7F)

}