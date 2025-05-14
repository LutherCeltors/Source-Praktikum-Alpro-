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

void insertFirst(ListStatik *l, ElType val)
{
   for (int i = getLastIdx(*l); i >= 0; i--){
      l->contents[i + 1] = l->contents[i]; 
   }
   l->contents[0] = val;
}
void insertAt(ListStatik *l, ElType val, IdxType idx)
{
   for(int i = getLastIdx(*(l)); i >= idx; i--){
      l->contents[i + 1] = l->contents[i];
   }
   l->contents[idx] = val;
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
    int N;
    ListStatik l, sorted;

    CreateListStatik(&l);
    CreateListStatik(&sorted);
    scanf("%d", &N);
    for (int i = 0; i < N; i++)scanf("%d", &l.contents[i]); 
    
    sorted.contents[0] = l.contents[0];
    // printf("%d list length\n",listLength(sorted));
    Printlist(&sorted);

    for (int i = 0; i < N; i++){
        for (int j = 0; j < listLength(sorted); j++){
            if (sorted.contents[j] >= l.contents[i] && j != 0){
                insertAt(&sorted, l.contents[i], j-1);
                Printlist(&sorted);
                break;

            }else if (sorted.contents[j] > l.contents[i] && j == 0){
                insertFirst(&sorted, l.contents[i]);
                Printlist(&sorted);
                break;

            }else if(sorted.contents[j] < l.contents[i] && j == listLength(sorted) - 1){
                insertLast(&sorted, l.contents[i]);
                Printlist(&sorted);
                break;
            }
        }
    }
    // Printlist(&sorted);
}