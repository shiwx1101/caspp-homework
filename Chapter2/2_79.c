#include <stdio.h>
/**
 * 
 * 
 * */
int mul3div4(int x){
    return (x<<1+x)>>2;
}


int main(){
    printf("%d\n",0x7f000000);
    printf("%d\n",mul3div4(0x7f000000));
}