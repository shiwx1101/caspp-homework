#include <stdio.h>
/**
 * 
 * 向右移动n-1位 如果结果位0则可以表示 且这个数的符号位位0
 *              如果结果为0xffffffff 说明这个数的符号i位为1
 * 
 * */

int fits_bits(int x, int n){
    x = x>>(n-1);
    return !x|!(x+1);

}

int main(){
    printf("%x",fits_bits(0b11001111,9));
}