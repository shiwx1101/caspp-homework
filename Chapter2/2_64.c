#include <stdio.h>
/**
 * 
 * 返回1  如果x的任意奇数位（odd bit）有等于1的  （比如  x= 0010  第1位为1 返回1）
 * 返回0 其他情况
 * 
 * 
 * */

int any_odd_one(unsigned x){
    return !!(x&0xAAAAAAAA);  // A = 1010 他的全部奇数位都为1 
}

int main(){

    printf("%d",any_odd_one(0));
}