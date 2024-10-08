#ifndef E03_EQUIPARRAY_H
#define E03_EQUIPARRAY_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define EQUIP_SLOT 8

#include "invArray.h"

/* ADT di prima classe collezione di oggetti di equipaggiamento */
typedef struct equipArray_s *equipArray_t;

/* creatore e disruttore */
equipArray_t equipArray_init();
void equipArray_free(equipArray_t equipArray);

/* quanti equipaggiamenti sono in uso */
int equipArray_inUse(equipArray_t equipArray);

/* scrittura su file */
void equipArray_print(FILE *fp, equipArray_t equipArray, invArray_t invArray);

/* modifica equipaggiamento scegliendo un oggetto da inventario */
void equipArray_update(equipArray_t equipArray, invArray_t invArray);//DAFARE

/* torna indice (nel vettore inventario) dell'oggetto in posizione index (0..EQUIP_SLOT-1) di equipArray */
int equipArray_getEquipByIndex(equipArray_t equipArray, int index);

/* Questa funzione inserire gli indici degli oggetti che sono nel vettore invArray */
equipArray_t AssociaEquip(equipArray_t equipArray);

int SommaStat(stat_t *statp,stat_t *statl,equipArray_t equipArray,invArray_t invArray);
#endif //E03_EQUIPARRAY_H
