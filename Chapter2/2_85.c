#include <stdio.h>
/**
 * 
 * Given a float point format with a k-bit exponent and an n-bit fraction, 
 * 
 * write formulas for the exponent E, the significand M, the fraction f,
 * 
 * And the value V for the quantities that follow,In addition,describle the bit-representation.
 * 
 *              *   ***...***   ***...***
 *              s   k bit       n bit
 * 
 * 
 * A  number 7.0    1.11<<2
 *             s = 0,   E =  2,  f = 0.11,   M = 1+f = 1.11  V = 2^E*M = 111 = 7 
 *              
 *             e  = E+bais(2^(k-1)-1) = 2 + 2^(k-1)-1
 *             
 *             bit-representation:       
 *                                  0   100...001   110...000
 *                                  s   k bit       n bit
 * 
 * 
 * B  The largest odd interger that can be represented extactly
 * 
 *             s = 0,   E =  2^(k-1)-1,  f = 0.11**111,   M = 1+f = 1.11***111  V = 2^E*M  = 2^(2^(k-1)-1)*(2-2^(-n)) 
 *                                                                              V          = 2^(2^(k-1))*(1-2^(-n-1));
 *                                                                              Suppose that E>n, the largest odd interger equal V-1;
 *                                                                              E=n,then V;
 *                                                                              Otherwise, 2^(2^(k-1))*(1-2^(-E-1)) 
 *              
 *             e  = E+bais(2^(k-1)-1) =   2^k-2
 *             
 *             bit-representation:  (E=n)     
 *                                  0   111***110   111...111
 *                                  s   k bit       n bit
 * 
 *         
 * C the reciprocal of the smallest normaized value 
 *          
 *              smallest normaized value:
 * 
 *              bit-representation:    
 *                                  0   000***001   000...000
 *                                  s   k bit       n bit
 * 
 *              s = 0 ,E = 2-2^(k-1) ,f=0, M = 1+f = 1; V = 2^E*M = 2 ^ ( 2-2^(k-1) )
 * 
 *              
 *              reciprocal of the smallest normaized value:
 * 
 *              s = 0 ,E = 2^(k-1)-2 ,f=0, M = 1+f = 1; V = 2^E*M = 2 ^ ( 2^(k-1)-2 ) 
 * 
 *              bit-representation:    
 *                                  0   111***110   000...000
 *                                  s   k bit       n bit
 * 
 * 
 * */


int main(){
}