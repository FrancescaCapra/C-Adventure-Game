#include "inv.h"

void inv_read(FILE *fp, inv_t *invp){
    fscanf(fp,"%s %s",(*invp).nome,(*invp).tipo);
    stat_read(fp,&(invp->stat));
}
void stat_read(FILE *fp, stat_t *statp){
    fscanf(fp," %d %d %d %d %d %d",&((*statp).hp),&((*statp).mp),&((*statp).atk),
           &((*statp).def),&((*statp).mag),&((*statp).spr));
}

void inv_print(FILE *fp, inv_t *invp){
    int tot=0;
    fprintf(fp,"\n%s %s",(*invp).nome,(*invp).tipo);
    stat_print(fp,&(invp->stat),tot);
}

void stat_print(FILE *fp, stat_t *statp, int soglia){
    printf("\nStatistiche generali:");
    fprintf(fp," %d %d %d %d %d %d",(*statp).hp,(*statp).mp,(*statp).atk,
            (*statp).def,(*statp).mag,(*statp).spr);

}
