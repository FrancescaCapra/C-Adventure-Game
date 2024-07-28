#include "pgList.h"
typedef struct node *link;
struct node{
    pg_t pers;
    link next;
};
struct pgList_s{
    link head;
    int n_eroe;
};
link newNode(pg_t pers,link next);
link listInsHead(pgList_t l, pg_t pg);

pgList_t pgList_init(){
    pgList_t pgList=malloc(sizeof(*pgList));
    pgList->head=NULL;
    pgList->n_eroe=0;
    return pgList;
}

void pgList_free(pgList_t pgList){
    link x;
    for (x = pgList->head; x != NULL; x = x->next) {
       pg_clean(&(x->pers));
    }
    free(pgList);
}

void pgList_read(FILE *fp, pgList_t pgList){
    pg_t pg;
    while(pg_read(fp,&(pg))==0){
        pg.equip=equipArray_init();
        pg=Union(&(pg));
        pgList->head=listInsHead(pgList,pg);
        pgList->n_eroe++;
    }
}

link listInsHead(pgList_t l, pg_t pg){
   l->head=newNode(pg, l->head);
   return l->head;
}

void pgList_insert(pgList_t pgList, pg_t pg){
        pgList->head = listInsHead(pgList,pg);
}

link newNode(pg_t pers,link next){
    link x=malloc(sizeof(*x));
    if(x==NULL)
        return NULL;
    x->pers=pers;
    x->next=next;
    return x;
}

void pgList_print(FILE *fp, pgList_t pgList, invArray_t invArray) {
    link x;
    for (x = pgList->head; x != NULL; x = x->next) {
        pg_print(fp, &(x->pers), invArray);
    }
}

pg_t *pgList_searchByCode(pgList_t pgList, char* cod){
    link x;
    for(x=pgList->head;x!=NULL;x=x->next)
        if(strcmp(cod,x->pers.cod)==0)
            return &(x->pers);

    return NULL;
}

void pgList_remove(pgList_t pgList, char* cod){
    link t=pgList->head,x,p;
    if(pgList->head==NULL)
        printf("NULL");

    for(x = t, p = NULL; x != NULL; p = x, x = x->next){
        if(strcmp(cod,x->pers.cod)==0){
            if(x==t)
                t=x->next;
            else
                p->next=x->next;
            free(x);
            break;
        }
    }
}

