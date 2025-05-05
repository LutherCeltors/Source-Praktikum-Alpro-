#include <stdio.h>

typedef struct {
    int contents[100];
    int nEff;
}list;

void Printlist(list *l)
{   
    printf("[");
    for (int i =0; i < l->nEff; i++){
        printf("%d", l->contents[i]);
        if (i < l->nEff -1){
            printf(", ");
        }
    }
    printf("]\n");
    
}

int main(){
    int Na, Mb;
    list a, b, c;
    a.nEff = 0;
    b.nEff = 0;
    scanf("%d", &Na);
    for (int i = 0; i < Na; i++){
        scanf("%d", &a.contents[i]);
        a.nEff += 1;
    }
    Printlist(&a);
    
    scanf("%d", &Mb);
    for (int i = 0; i < Mb; i++){
        scanf("%d", &b.contents[i]);
        b.nEff += 1;
    }
    Printlist(&b);

    int i = 0;
    int idxa = 0 ;
    int idxb = 0 ;

    while(idxa < a.nEff && idxb < b.nEff){
        if (a.contents[idxa] <= b.contents[idxb]){
            c.contents[i] = a.contents[idxa];
            idxa = idxa + 1;
        }else if (a.contents[idxa] > b.contents[idxb]){
            c.contents[i] = b.contents[idxb];
            idxb = idxb + 1;
        }
        i = i + 1;
    }
    while(idxa < a.nEff){
  
        c.contents[i] = a.contents[idxa];
        i = i+ 1;
        idxa = idxa + 1;
    }
    while(idxb < b.nEff){

        c.contents[i] = b.contents[idxb];
        i = i + 1;
        idxb = idxb + 1;
    }
    c.nEff = i;

    Printlist(&c);
}