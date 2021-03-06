# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct{
    int r[10];
    int length;
} list;

void swap(list *l,int i,int j){
    int temp;
    temp = l->r[i];
    l->r[i] = l->r[j];
    l->r[j] = temp;
}
void print_heap(list *l){
    int i=0;
    for(i=0;i<=9;i++){
        printf("l->r[%d] = %d\n",i,l->r[i]);
    }
}

void shellSort(list *l){
    int incr,tmp,i,j;
    incr = l->length;
    do{
        incr = incr/4 +1;
        for(i=incr;i<l->length;i++){
            if(l->r[i] < l->r[i-incr]){
                tmp = l->r[i];
                for(j=i-incr;j>=0 && tmp < l->r[j];j-=incr){
                    l->r[j+incr] = l->r[j];
                }
                l->r[j+incr] = tmp;
            }
        }
    }while(incr>1);
}

int main(){
    list *l;
    l = (list*)malloc(sizeof(list));
    l->length = 10;
    int r[] ={0,50,10,90,30,70,40,80,60,20};
    memcpy(l->r,r,sizeof(l->r));
    shellSort(l);
    print_heap(l);
    free(l);
    return 0;
}
