// 1. Criação do arquivo de cabeçalho para centralizar definições de estruturas e funções.
//    Princípio: Modularidade. Cada arquivo tem uma responsabilidade única.

// 2. Adicionado guarda de inclusão múltipla (#ifndef PACIENT_H ... #endif).
//    Princípio: Robustez. Evita problemas de redefinição de tipos e protótipos.

#ifndef PACIENT_H
#define PACIENT_H

#include <stdio.h>

    typedef struct
{
    int id;
    char name[50];
    float height;
    int age;
    float weight;
} Pacient;

int findPacientById(Pacient pacientsList[], int size, int id);
int findPacientByName(Pacient pacientsList[], int size, const char *name);

Pacient createPacient();
void readPacient(Pacient pacient);
int insertPacient(Pacient pacientsList[], int size);
int updatePacient(Pacient pacientsList[], int size, const char *name);
int deletePacient(Pacient pacientsList[], int size, int id);

void calculateAgeMedia(Pacient pacientsList[], int size);
void findHeaviestPacient(Pacient pacientsList[], int size);

#endif