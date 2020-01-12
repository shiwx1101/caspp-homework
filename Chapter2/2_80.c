#include <stdio.h>
/**
 * 
 * 绝对值
 * 
 * 分开算 0byte ~ 1byte 先乘后除  防止像3这样的值 3>>2 = 0   实际3*3/4 = 2.多
 *       2byte ~ 31byte 先除后乘  防止溢出。     
 * 
 * 
 * */
int mul3div4(int x){
    // int bias = (1<<2)-1;
    int flag = x>>(sizeof(int)*8-1);
    int x_absolute = (~flag&x) + (flag&~(x-1)); 
    // return x_absolute;
    int cuttwo = x_absolute&0x3; //cut last two
    int xdiv4 = x_absolute>>2; //shift right 2
    int cuttwo_mul3 = (cuttwo<<1)+cuttwo; //mul 3 
    int result_absolute = (xdiv4<<1)+xdiv4 + (cuttwo_mul3>>2);
    return (~flag&result_absolute)+(flag&(~result_absolute+1)); 
}


int main(){
    printf("%d",mul3div4(1));
    printf("%d",mul3div4(2));
    printf("%d",mul3div4(3));
    printf("%d",mul3div4(4));
    printf("%d",mul3div4(5));
    printf("%d",mul3div4(6));
    printf("%d",mul3div4(7));
    printf("%d",mul3div4(8));
    printf("\n");
    printf("%d",mul3div4(-1));
    printf("%d",mul3div4(-2));
    printf("%d",mul3div4(-3));
    printf("%d",mul3div4(-4));
    printf("%d",mul3div4(-5));
    printf("%d",mul3div4(-6));
    printf("%d",mul3div4(-7));
    printf("%d",mul3div4(-8));
}