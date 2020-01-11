#include <stdio.h>
/**
 * 
 * 
 * */
int divide_power2(int x ,int k){
    int bias = 1<<k-1;
    unsigned w = sizeof(int)<<3;
    int flag =x>>(w-1); 
    return  (~flag&x>>k) + (flag&((x+bias)>>k));
}



int main(){
    printf("%d\n",divide_power2(-161,2));
    printf("%d",divide_power2(161,2));
}