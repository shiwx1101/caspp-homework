#include <stdio.h>
/**
 * Intel-compatible processors also support an "extended-precision" floating-point format with an 80-bit word
 * 
 * divided into a sign bit, k= 15 exponent bits, a single integer bit ,and n=63 fraction bits.
 * 
 * The integer bit is an explicit copy of the implied bit in the IEEE floating-point representation.
 * 
 * That is, it equals 1 for normalized values and 0 for denormalized values.
 * 
 * Fill in the following table giving the approximate value of some "interesting" numbers in this format.
 * 
 * 
 * K=15  bias =  2^(k-1)-1 
 * 
 * Description:                       Value                                         Decimal                  
 *  Smalllest positive denormalized   2^(-n)*2^(2-2^(k-1))        1/(2^16445)          
 *  Smalllest positive normalized     2^(2-2^(k-1))               1/(2^16382)               
 *  Largest normalized                (2-2^(-n))*2^(2^(k-1)-1)    (2^64-1)*2^16320      
 * 
 * */


int main(){
}