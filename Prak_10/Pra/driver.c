#include "listlinier.h"
#include <stdio.h>

int main(){
   List l, l1, l2;
   CreateList(&l);  
   CreateList(&l1);  
   CreateList(&l2);  
   ElType val, out, out1;
   for (int i = 0; i < 20; i++){
       scanf("%d",&val);
       insertFirst(&l, val);
   }

   for (int i = 0; i < 3; i++){
       scanf("%d",&val);
       insertFirst(&l1, val);
   }
   displayList(l);
   printf("\n");
   displayList(l1);
   printf("\n");
   deleteLast(&l, &out);
   displayList(l);
   printf("%d\n", out);
   deleteLast(&l1, &out1);
   displayList(l1);
   printf("%d\n", out1);
   l2 = concat(l, l1);
   displayList(l2);
   
   for (int i = 0; i < 3; i++){
     scanf("%d",&val);
     insertLast(&l2, val);
   }
   displayList(l2);
   printf("\n");
   insertAt(&l2, 35, length(l2));
   displayList(l2);printf("\n");
   deleteAt(&l2, 3, &out1);
   displayList(l2);
   printf("%d\n", out1);
   deleteAt(&l2, 0, &out1);
   displayList(l2);
   printf("%d\n", out1);
   deleteAt(&l2, length(l2) - 1, &out1);
   displayList(l2);
   printf("%d\n", out1);
   deleteLast(&l2, &out1);
   displayList(l2);
   printf("%d\n", out1);
   deleteLast(&l2, &out1);
   displayList(l2);
   printf("%d\n", out1);
   deleteLast(&l2, &out1);
   displayList(l2);
   printf("%d\n", out1);
   deleteLast(&l2, &out1);
   displayList(l2);
   printf("%d\n", out1);
   printf("\nlength: %d\n", length(l2));
   printf("L2 value : %p\n", l2);
   return 0;
}
