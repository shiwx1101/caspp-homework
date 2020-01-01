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

void show_unsigned(unsigned x){
    show_bytes((byte_pointer)&x,sizeof(unsigned));
}

/**
 * 
 * 
 * 
 * 
 * */
unsigned replace_byte(unsigned x,int i, unsigned char b){
    if(i<0||i>3){
        return -1;//unsigned 类型只有四个字节 下标i只能设置为0-3 一旦查过应该
    }
    ((byte_pointer)&x)[i] = b;
    return x;
}


int main(){
    int x = 0x12345678;
    show_bytes((byte_pointer)&x,sizeof(int));
    show_unsigned(replace_byte(x,-1,0xab));

}