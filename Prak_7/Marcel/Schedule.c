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

IdxType getLstIdx(ListStatik l)
{
   int i = listLth(l) - 1;
   return i;
}

void instFirst(ListStatik *l, ElType val)
{
   for (int i = getLstIdx(*l); i >= 0; i--){
      l->contents[i + 1] = l->contents[i]; 
   }
   l->contents[0] = val;
}
void instAt(ListStatik *l, ElType val, IdxType idx)
{
   for(int i = getLstIdx(*(l)); i >= idx; i--){
      l->contents[i + 1] = l->contents[i];
   }
   l->contents[idx] = val;
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
    int N, jump;
    ListStatik l, sorted;

    CreateListStat(&l);
    CreateListStat(&sorted);
    scanf("%d", &N);
    for (int i = 0; i < N; i++)scanf("%d", &l.contents[i]); 
    
    sorted.contents[0] = l.contents[0];
    // printf("%d list length\n",listLth(sorted));
    prtList(&sorted);
    for (int i = 0; i < N; i++){
        jump  = 1;
        for (int j = 0; j < listLth(sorted) && jump; j++){
            if (sorted.contents[j] >= l.contents[i] && jump && j != 0){
                instAt(&sorted, l.contents[i], j);
                prtList(&sorted);
                jump = 0;

            }else if (sorted.contents[j] > l.contents[i] && jump && j == 0){
                instFirst(&sorted, l.contents[i]);
                prtList(&sorted);
                break;

            }else if(sorted.contents[j] < l.contents[i] && jump && j == listLth(sorted) - 1){
                instLast(&sorted, l.contents[i]);
                prtList(&sorted);
                break;
            }
        }
    }
    // prtList(&sorted);
}