#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer starter,size_t len){

    size_t i;
    for (size_t i = 0; i < len; i++)
    {
        printf("%.2x",starter[i]);
    }

    printf("\n");

}

void  show_int(int x){
    show_bytes((byte_pointer)&x,sizeof(int));
}

void show_float(float x){
    show_bytes((byte_pointer)&x,sizeof(float));
}

void show_pointer(void *x){
    show_bytes((byte_pointer)&x,sizeof(void *));
}


int main(){
    int x = 12345;
    float y = (float)x;
    int *z = &x;

    show_int(x);
    show_float(y);
    show_pointer(z);

}