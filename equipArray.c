#include "equipArray.h"
#define STR 30

struct equipArray_s{
    int equip[EQUIP_SLOT];
    int inUso;
};
equipArray_t equipArray_init(){
    int i;
    equipArray_t wrap_ponte=malloc(sizeof(*wrap_ponte));
    wrap_ponte->inUso=0;
    for(i=0;i<EQUIP_SLOT;i++){
        wrap_ponte->equip[i]='\0';
    }
    return wrap_ponte;
}
void equipArray_free(equipArray_t equipArray){
    free(equipArray);
}

int equipArray_inUse(equipArray_t equipArray){
    if(equipArray->inUso!=0)
        return equipArray->inUso;
    else
        return -1;
}
void equipArray_print(FILE *fp, equipArray_t equipArray, invArray_t invArray){
    int i,j;
    fprintf(fp,"\nNumero di Oggetti:%d",equipArray->inUso);

    for(i=0;i<EQUIP_SLOT;i++){
        j=equipArray_getEquipByIndex(equipArray, i);
        if( j!= -1){
            invArray_printByIndex(fp,invArray,j);
        }
        printf("\n");
    }
}

int equipArray_getEquipByIndex(equipArray_t equipArray, int index){
    return equipArray->equip[index];
}

void equipArray_update(equipArray_t equipArray, invArray_t invArray){
    char string[STR];
    int index,n_oggetto,pos,i,scelta;
    printf("1 > Inserire Oggetto dall'equipaggiamento\n");
    printf("2 > Rimuovere Oggetto dall'equipaggiamento");
    scanf("%d",&scelta);

    printf("Inserire il nome dell'oggetto:");
    scanf("%s", string);
    n_oggetto=invArray_searchByName(invArray,string);
    index=equipArray_inUse(equipArray);
    switch (scelta) {
        case 1:{

            if(index==EQUIP_SLOT){
                printf("\nEquipaggiamento pieno");
                return;
            }

            if(n_oggetto!=-1){
                for(i=0;i<equipArray->inUso;i++){
                    if(equipArray->equip[i]==-1)
                        equipArray->equip[i] = n_oggetto;
                }

                (equipArray->inUso)++;
            }
            return;
        }
        case 2:{
            if(n_oggetto!=-1){
                pos=equipArray_getEquipByIndex(equipArray,n_oggetto);
                equipArray->equip[pos]=-1;

                (equipArray->inUso)--;
            }

        return;
        }
        default:{
            printf("Scelta non valida\n");
        }
        return;
    }

}
equipArray_t AssociaEquip(equipArray_t equipArray){
    int i;
    //Ho dato dei valori fissi a questo vettore solo per non scegliere 10 volte oggetti diversi per 10 eroi diversi:
    int vet[EQUIP_SLOT]={0,1,2,3,4,5,6,7};
    for(i=0;i<EQUIP_SLOT;i++){
        equipArray->equip[i]=vet[i];
        equipArray->inUso++;
    }
    return equipArray;
}

int SommaStat(stat_t *statp,stat_t *statl,equipArray_t equipArray,invArray_t invArray){
    int i,somma=0;
    stat_t st;
    somma=(*statp).hp + (*statp).mp + (*statp).atk + (*statp).def + (*statp).mag + (*statp).spr+
            (*statl).hp + (*statl).mp + (*statl).atk + (*statl).def + (*statl).mag + (*statl).spr;
    for(i=0;i<equipArray->inUso;i++){
        st=inv_getStat(invArray,equipArray->equip[i]);
        somma=st.hp +st.mp + st.atk + st.def + st.mag + st.spr;
    }
    if(somma<=1)
        somma=1;
    return somma;
}