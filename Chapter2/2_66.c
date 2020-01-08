#include <stdio.h>
/**
 *  参考 https://www.it610.com/article/2593837.htm
 * 
 * 提示线将x转换成[000**011***1]的位向量
 * 
 *    x |= x>>1
 *    x |= x>>2 
 *    x |= x>>4
 *    x |= x>>8
 *    x |= x>>16
 *    x ^= x>>1
 * 
 * */

int leftmmost_one(unsigned x){
  x |= x>>1;
  x |= x>>2;
  x |= x>>4;
  x |= x>>8;
  x |= x>>16;
  return x^(x>>1);
    
}

int main(){

    printf("%x",leftmmost_one(0xffff));
}