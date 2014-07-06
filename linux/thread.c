#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

void fp1(void *args){
    int a=1000;
    while(a--){
        printf("fp1 %d\n",a);
        sleep(5);
    }
}

void fp2(void *args){
    int a=1000;
    while(a--){
        printf("=> fp2 %d\n",a);
        sleep(5);
    }
}
int main(){
    pthread_t p1 , p2;
    if(pthread_create(&p1,NULL,fp1,NULL)){
        printf("p1 wrong");
        return -1;
    }

    if(pthread_create(&p2,NULL,fp2,NULL)){
        printf("p2 wrong");
        return -1;
    }
    while(1){
        sleep(3);
    }

    return 0;
}
