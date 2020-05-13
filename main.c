#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct { 
    int *arr; //선언한 임의의 구조체에 배열을 담아보겠다. 이를 위해 안에 인자를 포인터로 선언
    int index;
}ARR_ST;


void USAGE(){
    printf("USAGE: <배열의 크기 n> <파라미터 1> \n 단, 배열의 요소는 파라미터 1부터 n까지 10씩 증가\n");
    return;
}


int main(int argc, char **argv)
{
    
    ARR_ST *ARR_T;
    int *cal_arr;
    int i;
    int p;
    int hash_key = 190;

    if ((argc)<3){
        USAGE();
    }

    else{   
        i=atoi(argv[1]);
        p=atoi(argv[2]);

        assert(i>0);

        cal_arr=(int *)malloc(sizeof(int)*i);
        ARR_T=(ARR_ST*)malloc(sizeof(ARR_ST));
        
        for (int j=0; j<i; j++){
            cal_arr[j]=p+10*(j);   
        }

        ARR_T->arr = cal_arr; /**/
        ARR_T->index = i; 

        printf("1) 배열의 크기: %d\n",ARR_T->index);
        for (int k=0; k<i; k++){
            printf("2) 배열의 요소[%d]: %d!\n", k+1, ARR_T->arr[k]);
        }

        for (int j=0; j<i; j++){
            if (hash_key > ARR_T->arr[j])
                printf("--> 배열[%d] 보다 암호가 큽니다.\n", j+1);
            else if (hash_key < ARR_T->arr[j])
                printf("--> 배열[%d] 보다 암호가 작습니다.\n", j+1);
            else
                printf("\n\n\n 배열[%d]와 암호가 같습니다. 암호: %d\n\n\n", j+1, ARR_T->arr[j]);
            
        }   

        printf("\n\n\n\nTEST SESSION FOR ME\n");
        for (int k=0; k<i; k++){
            // 43행에서 배열 주소를 서로 동치 시킴으로써 둘은 바로가기가 2개인 원본파일은 1개인것
            cal_arr[k]+=cal_arr[k];
            printf("ARR_T->arr[%d]: %d!\n", k, ARR_T->arr[k]);    
        }

        free(cal_arr);
        free(ARR_T);

    }
   
    
    return 0;
}