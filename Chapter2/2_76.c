#include <stdio.h>
/**
 * 
 * 
 * */

void *calloc(size_t nmemb,size_t size){
void *p;
    if(!(nmemb*size) || !(p = malloc(size*nmemb)))
        return NULL;
    else if (((size_t)(nmemb*size))/size != nmemb)
    {
        printf("Too large space to calloc.\n");
        return NULL;
    }
    else
    {
        memset(p, 0, size*nmemb);
        return p;
    }
}



int main(){
}