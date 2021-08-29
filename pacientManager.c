#include<stdio.h>
#include<string.h>
#include<locale.h>

typedef struct {

    int id;
    char name[50];
    float height;
    int age;
    float weight;

} Pacient;

void readMenu() {

    printf("Gerenciamento de pacientes: \n\n");
    
    printf("\t 1 - Inicializar a lista \n");
    printf("\t 2 - Inserir um paciente \n");
    printf("\t 3 - Impressão da lista de pacientes \n");
    printf("\t 4 - Editar um paciente \n");
    printf("\t 5 - Remover um paciente \n");
    printf("\t 6 - Média de idade dos pacientes \n");
    printf("\t 7 - Paciente mais pesado \n");
    printf("\t 0 - Para sair \n\n");
}

// ---------------------- CRUD - Pacient ---------------------- 

Pacient createPacient() {

    Pacient createPacient;

    printf("Insira o nome do paciente: ");
    scanf("%s", createPacient.name);
    printf("Insira o id do paciente: ");
    scanf("%d", &createPacient.id);
    printf("Insira a altura do paciente (em metros): ");
    scanf("%f", &createPacient.height);
    printf("Insira a idade do paciente: ");
    scanf("%d", &createPacient.age);
    printf("Insira o peso do paciente (em quilos): ");
    scanf("%f", &createPacient.weight);

    return createPacient;
}

int insertPacient(Pacient pacientsList[], int size) {

    int i = 0, insert = 0;

    for(i = 0; i < size; i++) {
        if(pacientsList[i].id == -1) {

            Pacient pacient = createPacient();
            pacientsList[i] = pacient;
            insert = 1;
            i = size;
        }
    }

    return insert;
}

void readPacient(Pacient pacient) {

    printf("Paciente: \n\n");
    printf("\t Nome: %s \n", pacient.name);
    printf("\t Id: %d \n", pacient.id);
    printf("\t Altura: %.2f metros \n", pacient.height);
    printf("\t Idade: %d \n", pacient.age);
    printf("\t Peso: %.2f quilos \n\n", pacient.weight);

}

int updatePacient(Pacient pacientsList[], int size) {

    char searchName[50];

    printf("Insira o nome do paciente desejado: ");
    scanf("%s", searchName);

    int i = 0, updated = 0;

    for(i = 0; i < size; i++) {
        if(strcmp(pacientsList[i].name, searchName) == 0) {

            readPacient(pacientsList[i]);
            int id = pacientsList[i].id;
            Pacient editedPacient = createPacient();
            editedPacient.id = id;
            pacientsList[i] = editedPacient;
            updated = 1;
        }
    }

    return updated;
}

int deletePacient(Pacient pacientsList[], int size, int deleteId) {

    int i = 0, deleted = 0;

    for(i = 0; i < size; i++) {
        if(pacientsList[i].id == deleteId) {

            pacientsList[i].id = -1;
            deleted = 1;
        }
    }

    return deleted;
}

// ------------------------------------------------------------------

// --------------- Funções da lista --------------------------------

void initializePacientsList(Pacient pacientsList[], int size) {

    int i = 0;

    for(i = 0; i < size; i++) {
        pacientsList[i].id = -1;
    }
}


void readPacientsList(Pacient pacientsList[], int size) {

    int i = 0, emptyList = 0;

    for(i = 0; i < size; i++) {
        if(pacientsList[i].id != -1) {
            
            readPacient(pacientsList[i]);
            emptyList = 1;
        }
    }

    if(emptyList == 0) {

        printf("A lista está vazia. \n\n");
    }
}

// --------------------------------------------------------

// ----------- Funções adicionais -------------------------

void ageMedia(Pacient pacientsList[], int size) {

    int i = 0, j = 0;
    float sumMedia = 0;

    for(i = 0; i < size; i++) {
        if(pacientsList[i].id != -1) {

            sumMedia += pacientsList[i].age;
            j++;
        }

    }

    float media = sumMedia / j;

    printf("\n A média de idade dos pacientes listados é de %.2f anos. \n\n", media);
}

void heaviestPacient(Pacient pacientsList[], int size) {

    int i = 0, j = 0;
    float heaviestPacient = pacientsList[0].weight;

    for(i = 0; i < size; i++) {
        float currentWeight = pacientsList[i].weight;
        if(pacientsList[i].id != -1 && pacientsList[i].weight >= heaviestPacient) {

            heaviestPacient = currentWeight;
            j = i;
        }
    }

    printf("\n O paciente mais pesado pesa %.2f quilos \n\n", heaviestPacient);
    readPacient(pacientsList[j]);
}

// --------------------------------------------------------

int main() {

    setlocale(LC_ALL, "Portuguese");

    int size = 100;
    Pacient pacientsList[size];

    int option = 1;

    while(option != 0) {

        readMenu();
        scanf("%d", &option);

        printf("\n");

            if(option == 1) {

                initializePacientsList(pacientsList, size);

            } else if (option == 2) {

                int response = insertPacient(pacientsList, size);

                if(response == 1) {

                    printf("\n O paciente foi inserido com sucesso! \n\n");

                } else {

                    printf("\n Não foi possível inserir o paciente. \n\n");
                }
            } else if (option == 3) {
                readPacientsList(pacientsList, size);
            } else if(option == 4) {
                int response = updatePacient(pacientsList, size);

                if(response == 1) {

                    printf("\n O paciente foi atualizado com sucesso! \n\n");

                } else {

                    printf("\n Não foi possível atualizar o paciente. \n\n");
                }
            } else if(option == 5) {

                int deleteId = 0;

                readPacientsList(pacientsList, size);

                printf("\n\n Digite o id do paciente que quer deletar: ");
                scanf("%d", &deleteId);

                int response = deletePacient(pacientsList, size, deleteId);

                if(response == 1) {

                    printf("\n O paciente foi excluído com sucesso! \n\n");

                } else {

                    printf("\n Não foi possível excluir o paciente. \n\n");
                }

            } else if(option == 6) {
                ageMedia(pacientsList, size);
            } else if(option == 7) {
                heaviestPacient(pacientsList, size);
            }
    }

    return 0;
}