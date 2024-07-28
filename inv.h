#ifndef E03_INV_H
#define E03_INV_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define LEN 100
#define MIN_STAT 1

/* quasi ADT statistiche */
typedef struct stat_s {
    int hp, mp, atk, def, mag, spr;
} stat_t;

/* quasi ADT per un singolo oggetto di inventario */
typedef struct inv_s {
    char nome[LEN];
    char tipo[LEN];
    stat_t stat;
} inv_t;

/* funzioni di input/output delle statistiche */
void stat_read(FILE *fp, stat_t *statp);
void stat_print(FILE *fp, stat_t *statp, int soglia);

/* funzioni di input/output di un oggetto dell'inventario */
void inv_read(FILE *fp, inv_t *invp);
void inv_print(FILE *fp, inv_t *invp);

#endif //E03_INV_H
