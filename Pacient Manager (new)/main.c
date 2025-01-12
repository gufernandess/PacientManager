// 1. Separação do fluxo principal em "main.c".
//    Princípio: Responsabilidade única. "main.c" gerencia a interação do usuário.

// 2. Refatoração do menu e do loop principal para chamar funções de "pacient.c".
//    Princípio: Simplicidade. Reduz a complexidade do código principal.

// 3. Uso de `switch` para organizar as opções do menu.
//    Princípio: Legibilidade. Facilita o entendimento do fluxo lógico.

// 4. Inclusão de `setlocale(LC_ALL, "Portuguese")` para suporte a caracteres acentuados.
//    Princípio: Usabilidade. Garante uma interface amigável para o usuário.

#include "pacient.h"
#include <locale.h>

void displayMenu()
{
    printf("Gerenciamento de pacientes:\n\n");
    printf("1 - Inicializar a lista\n");
    printf("2 - Inserir um paciente\n");
    printf("3 - Listar pacientes\n");
    printf("4 - Atualizar um paciente\n");
    printf("5 - Remover um paciente\n");
    printf("6 - Média de idade dos pacientes\n");
    printf("7 - Paciente mais pesado\n");
    printf("0 - Sair\n");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int size = 100;
    Pacient pacientsList[size];
    for (int i = 0; i < size; i++)
    {
        pacientsList[i].id = -1;
    }

    int option;
    do
    {
        displayMenu();
        printf("\nEscolha uma opção: \n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            for (int i = 0; i < size; i++)
            {
                pacientsList[i].id = -1;
            }
            printf("\nLista inicializada.\n\n");
            break;
        case 2:
            if (insertPacient(pacientsList, size))
            {
                printf("\nPaciente inserido com sucesso!\n\n");
            }
            else
            {
                printf("\nLista cheia!\n");
            }
            break;
        case 3:
            for (int i = 0; i < size; i++)
            {
                if (pacientsList[i].id != -1)
                {
                    readPacient(pacientsList[i]);
                }
            }
            break;
        case 4:
        {
            char name[50];
            printf("\nDigite o nome do paciente a ser atualizado: ");
            scanf("%s", name);
            if (updatePacient(pacientsList, size, name))
            {
                printf("\nPaciente atualizado com sucesso!\n");
            }
            else
            {
                printf("\nPaciente não encontrado.\n");
            }
            break;
        }
        case 5:
        {
            int id;
            printf("\nDigite o ID do paciente a ser removido: ");
            scanf("%d", &id);
            if (deletePacient(pacientsList, size, id))
            {
                printf("\nPaciente removido com sucesso!\n");
            }
            else
            {
                printf("\nPaciente não encontrado.\n");
            }
            break;
        }
        case 6:
            calculateAgeMedia(pacientsList, size);
            break;
        case 7:
            findHeaviestPacient(pacientsList, size);
            break;
        case 0:
            printf("\nSaindo...\n");
            break;
        default:
            printf("\nOpção inválida!\n");
        }
    } while (option != 0);

    return 0;
}
