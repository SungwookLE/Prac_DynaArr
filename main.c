#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct { 
    int *arr; //선언한 임의의 구조체에 배열을 담아보겠다. 이를 위해 안에 인자를 포인터로 선언
    int index;
}ARR_ST;


int main(int argc, char **argv)
{
    ARR_ST *ARR_T;
    int *cal_arr;
    int i=atoi(argv[1]);
    printf("%d",i);

    assert(i>0);

    cal_arr=(int *)malloc(sizeof(int)*i);
    ARR_T=(ARR_ST*)malloc(sizeof(ARR_ST));
    
    for (int j=0; j<i; j++){
        cal_arr[j]=j;   
    }

    ARR_T->arr = cal_arr;
    ARR_T->index = i; 

    printf("ARR_T->index: %d\n",ARR_T->index);
    for (int k=0; k<i; k++){
        printf("ARR_T->arr[%d]: %d!\n", k, ARR_T->arr[k]);
    }
    for (int k=0; k<i; k++){
        // 26행에서 배열 주소를 서로 동치 시킴으로써 둘은 바로가기가 2개인 원본파일은 1개인것
        cal_arr[k]=cal_arr[k]+10;
        printf("ARR_T->arr[%d]: %d!\n", k, ARR_T->arr[k]);
    }
   
    
    return 0;
}