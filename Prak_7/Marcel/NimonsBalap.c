#include <stdio.h>
#define CAPACITY 100
#define IDX_MIN 0
#define IDX_UNDEF -1
#define MARK -9999

typedef int ElType; 
typedef int IdxType;
typedef struct {
   ElType contents[CAPACITY];
} ListStatik;

void CreateListStat(ListStatik *l)
{
   for (int i = 0; i<CAPACITY; i++) l->contents[i] = MARK;
}

int listLth(ListStatik l)
{
   int length = 0;
   int i = 0;
   while(l.contents[i] != MARK && i < CAPACITY){
      length += 1;
      i++;
   }  
   return length;
}

void extremeValues(ListStatik l, ElType *max, ElType *min)
{
   *max = l.contents[0];
   *min = l.contents[1];

   for (int i = 0; i < 0 + listLth(l); i++){
      if (*max < l.contents[i]){
         *max = l.contents[i];
      }else if(*min > l.contents[i]){
         *min = l.contents[i];
      }
   }
}
void instLast(ListStatik *l, ElType val)
{
   l->contents[listLth(*l)] = val;
}
void prtList(ListStatik *l)
{   
    printf("[");
    for (int i =0; i < listLth(*l); i++){
        printf("%d", l->contents[i]);
        if (i < listLth(*l) -1){
            printf(",");
        }
    }
    printf("]\n");
    
}


int main(){
    int N, K, min, max;
    int idxl, idxtw, idxres, tmpi;
    ListStatik l, twipe, result;
    
    CreateListStat(&l);
    CreateListStat(&twipe);
    CreateListStat(&result);

    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &l.contents[i]);
    scanf("%d", &K);

    idxl = 0;
    while(idxl <= listLth(l) - K){
        tmpi = idxl;
        idxtw = 0;
        while(idxtw < K){
            twipe.contents[idxtw] = l.contents[tmpi];
            idxtw++;
            tmpi++;
            // printf("c1\n");
        }
        extremeValues(twipe, &max, &min);
        instLast(&result, max);
        idxl++;
        // prtList(&twipe);
        // prtList(&result);
        // printf("c2\n");
    }
    prtList(&result);
}