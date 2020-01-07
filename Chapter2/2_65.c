#include <stdio.h>
/**
 * 
 * 返回1  如果x里面的1的个数是奇数  （比如  x= 0010  里面有1个1 返回1）
 * 返回0 其他情况
 * 假设  w=32位
 * 
 * 
 * 答案  https://stackoverflow.com/questions/9133279/bitparity-finding-odd-number-of-bits-in-an-integer/9133406#9133406
 * 
 * x ^= x >> 16;
   x ^= x >> 8;
   x ^= x >> 4;
   x &= 0xf;
   return (0x6996 >> x) & 1;

   折叠异或（相同为0 不同为1）   
   
   如果刚好碰到两个1 直接变成0 相当于去掉了两个1  不影响最后的结果。
   如果刚好碰到01 保留1 
   如果托两个0 结果还是0

   此操作相当于去掉了偶数个1。

   最后剩下的x可能包含0到4个1 

   0个1  0(0000)
   1个1  1(0001) 2(0010) 4(0100) 8(1000)
   2个1  3(0011) 5(0101) 6(0110) 9(1001) 10(1010) 12(1100)
   3个1  7(0111) 11(1011) 13(1101) 14(1110)
   4个1  15(1111)

   奇数个1的数有 1 2 4 7 8 11 13 14

   0x6996 ==  0110 1001 1001 0110  为1的位的下标 刚好是(1 2 4 7 8 11 13 14)

   所以0x6996右移x位,如果x是(1 2 4 7 8 11 13 14)则所得结果的最后一位必然是1 

   1&1=1 
   反之1&0=0

 * 
 * 
 * 
 * 
 * 
 * */

int odd_ones(unsigned x){
    x ^=x>>16;
    x ^=x>>8;
    x ^=x>>4;
    x &=0xf;
    return (0x6996 >> x)&1;
}

int main(){

    printf("%d",odd_ones(0b000101));
}