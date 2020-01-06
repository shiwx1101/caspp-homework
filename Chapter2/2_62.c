#include <stdio.h>

/**
 *
 * -1的十六进制表示为 0xFFFFFFFF
 * 
 * 向右移动如果是算术右移 值应该不变，如果是逻辑右移应该为 int_max 
 *  
 * 
 * 
 * 
 */
int int_shift_are_arithmetic(){
    int x = -1;

    return (x>>1)==-1;

}


int main(){
    printf("%d",int_shift_are_arithmetic());

}