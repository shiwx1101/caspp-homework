#include <stdio.h>
#include<limits.h>
/**
 * 
 *参考 https://blog.csdn.net/zhanyu1990/article/details/24936663 
 *
 * 
 * */


int saturating_add(int x,int y){
    int w = sizeof(int)<<3;
    int s = x+y;

    int xt = x>>(w-1);
    int yt = y>>(w-1);
    int st = s>>(w-1);
    
    int posf = ~xt&~yt&st;
    int negf = xt&yt&~st;
    int novf = ~(negf|posf);

    return (posf & INT_MAX)|(novf&s)|(negf&INT_MIN);

}

int main(){
    printf("%d",saturating_add(0x70000000,0x70000000));
    printf("\n%x",saturating_add(0x70000000,0x70000000));
}