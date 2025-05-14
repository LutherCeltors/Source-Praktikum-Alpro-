#include <stdio.h>
typedef struct {
    int contents[1000];
    int nEff;
}List;

void reverse (List *l, int kiri, int kanan){
    List templ;
    int templ_idx = 0;

    templ.nEff = 0;

    for (int i = kanan; i >= kiri ; i--){
        templ.contents[templ_idx] = l->contents[i];
        ++templ_idx;
        templ.nEff++;
    }
    templ_idx = 0;
    for (int i = kiri; i <= kanan; i++){
        l->contents[i] = templ.contents[templ_idx];
        ++templ_idx;
    }
    // for (int i = 0; i < l->nEff; i++) printf("%d ", l->contents[i]);
    // printf("\n");
}
void copyList(List l1, List *l2){
    l2->nEff = l1.nEff;
    for(int i = 0; i < l1.nEff; i++){
        l2->contents[i] = l1.contents[i];
    }
}

int isSorted (List l){
    int sorted = 1;
    int i = 0;

    while (i < l.nEff - 1 && sorted){
        if (l.contents[i] > l.contents[i + 1]){
            sorted = 0;
        }
        i++;
    }
    return sorted;
}

int main(){
    int N, kiri, kanan, sorted;
    List l, templ;

    scanf("%d", &N);
    l.nEff = N;
    for (int i = 0; i < N; i++) scanf("%d", &l.contents[i]);

    // reverse(&l, 1, 3);
    kiri = 0;
    kanan = 1;
    sorted = isSorted(l);

    if (sorted){
        printf("YA\n");
    }else if(!sorted){
        copyList(l, &templ);
        while (!sorted && kiri <= l.nEff - 2){
            while(!sorted && kanan <= l.nEff -1){

                copyList(l, &templ);
                reverse(&templ, kiri, kanan);
                sorted = isSorted(templ);
                kanan++;
            }
            copyList(l, &templ);
            reverse(&templ, kiri, kanan);
            sorted = isSorted(templ);
            kiri++;
        }
        if (sorted){
            printf("YA\n");
            if (kanan == l.nEff){
                kanan--;
            }
            if (kiri == l.nEff -1){
                kiri--;
            }
            
            printf("%d %d\n", kiri, kanan);

        }else if(!sorted){
            printf("TIDAK\n");
        }
    }
    return 0;
}