#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
/**
 * 
 * https://www.cnblogs.com/liqiuhao/p/7596539.html
 * 
 * */

unsigned unsigned_high_prod(unsigned x, unsigned y);
int signed_high_prod(int x, int y);


unsigned unsigned_high_prod(unsigned x, unsigned y){
    int w = sizeof(int)<<3;
    int64_t signed_totol_prod = signed_high_prod(x,y);
    signed_totol_prod <<= w;
    signed_totol_prod += x*y;
    bool x_w = x < 0 ? true:false;
    bool y_w = y < 0 ? true:false;
    int64_t unsigned_totol_prod = signed_totol_prod +((int) y * x_w + (int) y*y_w) + (x_w*y_w)<<(2*w);
    return (unsigned)unsigned_totol_prod>>w;
}

int main(){
    // printf("%x",unsigned_high_prod(0x0011,0x0011));
}