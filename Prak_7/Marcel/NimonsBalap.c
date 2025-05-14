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

void CreateListStatik(ListStatik *l)
{
   for (int i = 0; i<CAPACITY; i++) l->contents[i] = MARK;
}

int listLength(ListStatik l)
{
   int length = 0;
   int i = 0;
   while(l.contents[i] != MARK && i < CAPACITY){
      length += 1;
      i++;
   }  
   return length;
}

IdxType getLastIdx(ListStatik l)
{
   int i = listLength(l) - 1;
   return i;
}

void extremeValues(ListStatik l, ElType *max, ElType *min)
{
   *max = l.contents[0];
   *min = l.contents[1];

   for (int i = 0; i < 0 + listLength(l); i++){
      if (*max < l.contents[i]){
         *max = l.contents[i];
      }else if(*min > l.contents[i]){
         *min = l.contents[i];
      }
   }
}
void insertLast(ListStatik *l, ElType val)
{
   l->contents[listLength(*l)] = val;
}
void Printlist(ListStatik *l)
{   
    printf("[");
    for (int i =0; i < listLength(*l); i++){
        printf("%d", l->contents[i]);
        if (i < listLength(*l) -1){
            printf(",");
        }
    }
    printf("]\n");
    
}


int main(){
    int N, K, min, max;
    int idxl, idxtw, idxres, tmpi;
    ListStatik l, twipe, result;
    
    CreateListStatik(&l);
    CreateListStatik(&twipe);
    CreateListStatik(&result);

    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &l.contents[i]);
    scanf("%d", &K);

    idxl = 0;
    while(idxl <= listLength(l) - K){
        tmpi = idxl;
        idxtw = 0;
        while(idxtw < K){
            twipe.contents[idxtw] = l.contents[tmpi];
            idxtw++;
            tmpi++;
            // printf("c1\n");
        }
        extremeValues(twipe, &max, &min);
        insertLast(&result, max);
        idxl++;
        // Printlist(&twipe);
        // Printlist(&result);
        // printf("c2\n");
    }
    Printlist(&result);
}