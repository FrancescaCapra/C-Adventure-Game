#include "pg.h"

int pg_read(FILE *fp, pg_t *pgp){
    if(fscanf(fp," %s %s %s ",pgp->cod,pgp->nome,pgp->classe)==3) {
        stat_read(fp, &((*pgp).b_stat));
        stat_read(fp, &((*pgp).eq_stat));
        (*pgp).equip = NULL;
        return 0;
    }else
        return 1;
}
void pg_print(FILE *fp, pg_t *pgp, invArray_t invArray){
    int i;
    printf("\nPersonaggio:%s %s %s", (*pgp).cod,(*pgp).nome,(*pgp).classe);
    equipArray_print(fp,(*pgp).equip,invArray);
    i=SommaStat(&(pgp->b_stat),&(pgp->eq_stat),pgp->equip,invArray);

    printf("\nPunteggio totale:%d",i);
}
void pg_clean(pg_t *pgp){
    equipArray_free((*pgp).equip);
}

void pg_updateEquip(pg_t *pgp, invArray_t invArray){
    equipArray_update((*pgp).equip,invArray);
}
pg_t Union(pg_t *pers){
    (*pers).equip=AssociaEquip((*pers).equip);
    return *pers;
}