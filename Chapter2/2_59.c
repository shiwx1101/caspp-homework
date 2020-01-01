#include <stdio.h>

 
typedef unsigned char *byte_pointer;
/**
 * x
 * 
 * 
 * */
int  combination(int x ,int y){
    int x1= x&0xff;
    int y1 = y&0xffffff00;
    return x1+y1;

}

// void show_bytes(byte_pointer starter,size_t len){

//     size_t i;
//     for (size_t i = 0; i < len; i++)
//     {
//         printf("%.2x",starter[i]);
//     }

//     printf("\n");

// }


// void  show_int(int x){
//     show_bytes((byte_pointer)&x,sizeof(int));
// }


int main(){
    int x = 0x89abcdef;
    int y = 0x76543210;

    printf("%.2x",x);
    printf("%.2x",y);
    printf("%.2x",combination(x,y));
}