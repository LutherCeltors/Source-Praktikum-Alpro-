#include <stdio.h>

typedef struct
{
    int contents[100];
    int nEff; 
}list;
int val, idx;

void Printlist(list *l)
{   
    printf("[");
    for (int i =0; i < l->nEff; i++){
        printf("%d", l->contents[i]);
        if (i < l->nEff -1){
            printf(",");
        }
    }
    printf("]\n");
    
}

int main(){
    int aksi;
    list gudang;
    gudang.nEff = 0;

    scanf("%d", &aksi);
    while (aksi != -1){
        if (aksi == 1){

            scanf("%d %d", &val, &idx);
            if (gudang.nEff == 100 || idx < 0 || idx > gudang.nEff){
                printf("Aw, gabisa ngelakuin aksi itu\n");
            }else if (idx >= 0 && idx <= gudang.nEff){
                if (idx >= 0 && idx < gudang.nEff){
                    for (int i = gudang.nEff; i > idx; i--){
                        gudang.contents[i] = gudang.contents[i-1];
                    }
                    gudang.contents[idx] = val;
                    gudang.nEff += 1;

                }else if (idx == gudang.nEff){
                    gudang.contents[idx] = val;
                    gudang.nEff += 1;   
                }
            }
            
        }else if (aksi == 0){

            scanf("%d", &idx);
            if (gudang.nEff == 0 || idx < 0 || idx >= gudang.nEff){
                printf("Aw, gabisa ngelakuin aksi itu\n");
            }else if (idx >= 0 && idx < gudang.nEff){
                if (idx >= 0 && idx < gudang.nEff){
                    for (int i = idx+1; i < gudang.nEff; i++){
                        gudang.contents[i-1] = gudang.contents[i];
                    }
                    gudang.nEff -= 1;

                }else if (idx == gudang.nEff-1){
                    gudang.nEff -= 1;   
                }
            }
            
        }
        Printlist(&gudang);
        scanf("%d", &aksi);
    }
    
}