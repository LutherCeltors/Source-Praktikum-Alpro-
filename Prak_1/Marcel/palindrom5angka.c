#include<stdio.h>

int main(){
    int n, i;
    int s,p,rt,rb,prb; /*satuan, puluhan, ratusan,dst*/
    scanf("%d",&n);
    s = n%10;
    // printf("%d\n", s);
    p = (n%100 - s)/10;
    // printf("%d\n", p);
    rt = (n%1000 - s - (p*10))/100;
    // printf("%d\n", rt);
    rb = (n%10000 - s - (p*10) - (rt*100))/1000;
    // printf("%d\n", rb);
    prb = (n%100000 - s - (p*10) - (rt*100) - (rb*1000))/10000;
    // printf("%d\n", prb);
    if (s==prb && p==rb){
        printf("Palindrom\n");
    }else{
        printf("Bukan palindrom\n");
    }
}