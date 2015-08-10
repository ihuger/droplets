#include<string.h>
#include<stdio.h>
int reverse(int x) {
    int min_int = -1<<31;
    int max_int = -(min_int+1);
    int r = 0; 
    int d = 1;
    long y = x; 
    if(x<0){
        d=-1;
        y=-y;
    }
    while(y!=0){
        int tmp = (int)(y%10);
        if(tmp!=0 || r!=0){
            long rr= (long)r*10 + tmp;
            if(rr*d>max_int || rr*d<min_int)
                return 0;
            r = (int)rr;
        }
        y /= 10;
    }
    return r*d;
}

int main(){
    printf("%d\n",reverse(-123));
    printf("%d\n",reverse(-1000));
    printf("%d\n",reverse(0));
    printf("%d\n",reverse(1234));
    printf("%d\n",reverse(1534236469));
    printf("%d\n",reverse(-1534236469));
    printf("%d\n",reverse(-2147483648));
    return 0;
}
