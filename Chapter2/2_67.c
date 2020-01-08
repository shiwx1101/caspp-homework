#include <stdio.h>
/**
 * 题目中的第六行 int beyond_msb = 1<<32  
 * 
 * C语言中位移量k的范围是0~w-1 位 如果位移超过了，那么k=k mod w
 * 也就是说如果int 为32位 那么 1<<32   ==    1<<0
 * 并不是想想中的1向左移动32位结果为0  实际上是移动了k mod w (32 mod 32 = 0)位  结果还是1
 * 
 * 
 * */

int bad_int_size_is_32(){

    int set_msb = 1<<31;

    int beyond_msb = 1<<32;

    return set_msb && !beyond_msb;
    
}

/**
 * 
 * int 的位数是32位
 * 
 * */

int int_size_is_32(){

     int set_msb = 1<<31;

    int beyond_msb = set_msb<<1;

    return set_msb && !beyond_msb;
    
}


int main(){

    printf("%x",int_size_is_32());
}