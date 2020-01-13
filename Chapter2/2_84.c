#include <stdio.h>
/**
 * Fill in the return value for the following procedure.
 * 
 * which tests whether its first argument is less than or equal to its second,
 * 
 * Assume the function f2u returns an unsigned 32 bit number having the same bit representation as its float-point argument.
 * 
 * You can assume that neither argument is NaN. 
 * 
 * The two flavor of Zero +0 and -0, are considered equal.
 * 
 * 
 * 
 * */

unsigned f2u(float x){
    return *(unsigned*)&x;
}
// x<=y
int float_le(float x,float y){
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    unsigned sx = ux>>31;
    unsigned sy = uy>>31;

    return sx==sy?((sx==0&&uy>=ux)|(sx==1&&ux>=uy)):!sy;

}

int main(){
    printf("%x \n",float_le(0.5,0.4));
    printf("%x \n",float_le(-0.5,0.4));
    printf("%x \n",float_le(0.5,-0.4));
    printf("%x \n",float_le(-0.5,-0.4));
}