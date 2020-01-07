#include <stdio.h>
/**
 * 
 * 
 * c语言默认无符号逻辑右移，有符号算数右移
 * 
 * 
 * 
 * */
unsigned srl(unsigned x ,int k){
    unsigned xsra = (int)x>>k;  //强制转换成int 后进行算数右移 
    return    xsra&(~(-1<<(8*sizeof(int)-k)));
}

int sra(int x,int k){
    int xsrl = (unsigned)x>>k;
    // return  (~(-(!(~(x|((unsigned)-1>>1))))>>k))&x;
    //(unsigned)-1>>1 求出7f***ff 
    // !~(x|((unsigned)-1>>1)) 如果x的符号位为1则结果为1 反之为0
    // (-!~(x|(unsigned)-1>>1))<<(8*sizeof(int)-k)|xsrl;把符号位1右移产生的0补成1
    return (-!~(x|(unsigned)-1>>1))<<(8*sizeof(int)-k)|xsrl;
}

int main(){   
    unsigned res = srl(0x7fffffff,3);
    int res1 = sra(0xff5fffff,3);
    printf("%x",res);
    printf("\n");
    printf("%x",res1);

}