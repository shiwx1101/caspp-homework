#include <stdio.h>
/**
 * 
 *参考 https://blog.csdn.net/zhanyu1990/article/details/24936663 
 *
 * 
 * */


int tsub_ok(int x,int y){
    int w = sizeof(int)<<3;
    int s = x-y;

    int xt = x>>(w-1);
    int yt = y>>(w-1);
    int st = s>>(w-1);
    
   return !((xt!=yt)&&(yt==st));

}

int main(){
    printf("%d",tsub_ok(0x7fffffff,0x80000000));
    printf("\n%x",tsub_ok(0x1,0x80000000));
}