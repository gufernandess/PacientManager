// 1. Implementação das funções auxiliares em "pacient.c".
//    Princípio: Separação de responsabilidades. Funções relacionadas a pacientes foram isoladas.

// 2. Inclusão de "pacient.h" para acessar as definições do cabeçalho.
//    Princípio: Reutilização de código. Mantém o contrato das funções claro entre os arquivos.

// 3. Refatoração das funções de busca (`findPacientById` e `findPacientByName`).
//    Princípio: DRY (Don't Repeat Yourself). Elimina redundância no código principal.

// 4. Funções CRUD (`createPacient`, `readPacient`, `insertPacient`, etc.) movidas para `pacient.c`.
//    Princípio: Organização. Agrupa lógica comum em um único local.

// 5. Funções adicionais (`calculateAgeMedia` e `findHeaviestPacient`) otimizadas para reaproveitar lógica existente.
//    Princípio: Clareza e reutilização de código.

#include "pacient.h"
#include <string.h>

int findPacientById(Pacient pacientsList[], int size, int id)
{
    for (int i = 0; i < size; i++)
    {
        if (pacientsList[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

int findPacientByName(Pacient pacientsList[], int size, const char *name)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(pacientsList[i].name, name) == 0)
        {
            return i;
        }
    }
    return -1;
}

Pacient createPacient()
{
    Pacient pacient;
    printf("Insira o nome do paciente: ");
    scanf("%s", pacient.name);
    printf("Insira o id do paciente: ");
    scanf("%d", &pacient.id);
    printf("Insira a altura do paciente (em metros): ");
    scanf("%f", &pacient.height);
    printf("Insira a idade do paciente: ");
    scanf("%d", &pacient.age);
    printf("Insira o peso do paciente (em quilos): ");
    scanf("%f", &pacient.weight);
    return pacient;
}

void readPacient(Pacient pacient)
{
    printf("\nPaciente:\n");
    printf("\t Nome: %s\n", pacient.name);
    printf("\t Id: %d\n", pacient.id);
    printf("\t Altura: %.2f metros\n", pacient.height);
    printf("\t Idade: %d\n", pacient.age);
    printf("\t Peso: %.2f quilos\n\n", pacient.weight);
}

int insertPacient(Pacient pacientsList[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (pacientsList[i].id == -1)
        {
            pacientsList[i] = createPacient();
            return 1;
        }
    }
    return 0;
}

int updatePacient(Pacient pacientsList[], int size, const char *name)
{
    int index = findPacientByName(pacientsList, size, name);
    if (index != -1)
    {
        printf("Paciente encontrado:\n");
        readPacient(pacientsList[index]);
        printf("Atualize os dados:\n");
        pacientsList[index] = createPacient();
        return 1;
    }
    return 0;
}

int deletePacient(Pacient pacientsList[], int size, int id)
{
    int index = findPacientById(pacientsList, size, id);
    if (index != -1)
    {
        pacientsList[index].id = -1;
        return 1;
    }
    return 0;
}

void calculateAgeMedia(Pacient pacientsList[], int size)
{
    float sum = 0;
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (pacientsList[i].id != -1)
        {
            sum += pacientsList[i].age;
            count++;
        }
    }
    if (count > 0)
    {
        printf("\nMédia de idade: %.2f anos\n\n", sum / count);
    }
    else
    {
        printf("\nNenhum paciente para calcular a média de idade.\n");
    }
}

void findHeaviestPacient(Pacient pacientsList[], int size)
{
    int heaviestIndex = -1;
    float maxWeight = -1;
    for (int i = 0; i < size; i++)
    {
        if (pacientsList[i].id != -1 && pacientsList[i].weight > maxWeight)
        {
            maxWeight = pacientsList[i].weight;
            heaviestIndex = i;
        }
    }
    if (heaviestIndex != -1)
    {
        printf("\nPaciente mais pesado:\n");
        readPacient(pacientsList[heaviestIndex]);
    }
    else
    {
        printf("\nNenhum paciente na lista.\n");
    }
}