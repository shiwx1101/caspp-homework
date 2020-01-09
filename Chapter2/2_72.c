#include <stdio.h>
/**
 * 
 * 
 * 有符号数和无符号数混合运算时（包括逻辑运算和算术运算）默认会将有符号数看成无符号数进行运算，返回无符号数结果
 * 32位机器中，比int小的整型（包括short 、unsigned short 、 unsigned char和char）在运算中都要转换成int然后进行运算
 * 
 * 
 * 
 * */

void copy_int(int val, void *buf ,int maxbyte ){
    if(maxbyte-sizeof(val)>=0){                             //sizeof(val) 返图size_t 是一个unsigned类型，maxbyte-size_t也返回unsigned 必然大于等于0
        memcpy(buf,(void*)&val,sizeof(val));
    }
}

void copy_int(int val, void *buf ,int maxbyte ){
    if(maxbyte-(int)(sizeof(val))>=0){                             
        memcpy(buf,(void*)&val,sizeof(val));
    }
}

int main(){
    // printf("%x",xbyte(0xffffffff,3));
}