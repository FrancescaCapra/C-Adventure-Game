#include "invArray.h"
#include "inv.h"

/*Completo l'ADT di 1 classe*/
struct invArray_s{
    inv_t *inv;
    int max_r;
};
/*Operazioni sulla struct wrapper:*/
invArray_t invArray_init(){
    invArray_t inv=malloc(sizeof(*inv));
    return inv;
}
void invArray_free(invArray_t invArray) {
    free(invArray);//tutti gli altri campi
}

void invArray_read(FILE *fp, invArray_t invArray){
    int i;
    fscanf(fp," %d ",&(invArray->max_r));
    invArray->inv=malloc((invArray->max_r)*sizeof(inv_t));
    for(i=0;i<(invArray->max_r);i++){
        inv_read(fp,&(invArray->inv[i]));
    }
}

void invArray_print(FILE *fp, invArray_t invArray){
    int i;
    printf("\nEcco gli oggetti dell'inventario: ");
    for(i=0;i<(invArray->max_r);i++){
        inv_print(fp,&(invArray->inv[i]));
    }
}

/*Funzioni che servono ad altro*/
void invArray_printByIndex(FILE *fp, invArray_t invArray, int index){
    printf("\nL'oggetto selezionato:");
    inv_print(fp,&(invArray->inv[index]));

}

int invArray_searchByName(invArray_t invArray, char *name){
    int index;
    int i;
    for(i=0;i<invArray->max_r;i++){
        if(strcmp(name,invArray->inv[i].nome)==0){
            index=i;
            return index;
        }
    }
    return -1;
}
inv_t *invArray_getByIndex(invArray_t invArray, int index){
    return &(invArray->inv[index]);
}
stat_t inv_getStat(invArray_t invArray,int index){
    return invArray->inv[index].stat;
}