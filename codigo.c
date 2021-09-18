#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int menu();
void cadastro();
void testeEmail();

char nome[1000][1000], email[100][100], sexo[20][100], endereco[100][100];
int intMenu;
double altura[1000];
int contadorUsuario = 0;
bool vacina[1000]; 

int main(){

    do {

        switch (menu()) {

        case 1: cadastro(); break;
        case 2: printf("\nEditar usuário"); break;
        case 3: printf("\nExcluir usuário: "); break;
        case 4: printf("\nBuscar usuário: "); break;
        case 5: printf("\nBuscar usuário pelo email "); break;
        case 6: printf("\nImprimir todos usuário cadastrados "); break;
        case 7: printf("\nFaça backup dos usuários cadastrado "); break;
        case 8: printf("\nFaça restauração dos dados "); break;
        case 9: printf("\nSair "); break;
        default: printf(" \nExeculte o programa corretamente"); break;
        
        }

    } while (intMenu != 9);

    return 0;
    
}

int menu() {

    printf(" \n\nMenu\n\n1 - Incluir usuário \n2 - Editar usuário \n3 - Excluir usuário \n4 - Buscar usuário pelo id \n5 - Buscar usuário pelo email");
    printf(" \n6 - Imprimir todos usuário cadastrados\n7 - Faça backup dos usuários cadastrado\n8 - Faça restauração dos dados\n9 - sair \n\n");

    scanf("%i", &intMenu);

    return intMenu;
    
}

void cadastro() {
    
    printf("\nDigite seu nome completo: ");
    getchar();
    fgets(nome[contadorUsuario], 100, stdin);

    printf("Digite seu sexo: ");
    fgets(sexo[contadorUsuario], 100, stdin);

    testeEmail();

    printf("Digite seu endereço: ");
    fgets(endereco[contadorUsuario], 100, stdin);
  
    printf("Digite sua altura: ");
    scanf("%lf", &altura[contadorUsuario]);

    printf("Tomou a vacina ? (Sim = 1 / Não = 0): ");
    scanf("%d", &vacina[contadorUsuario]);

    for (int i = 0; i <= contadorUsuario; i++) {

        printf("%d", vacina[contadorUsuario]);

    }

    contadorUsuario++;

}

void testeEmail() {

    bool teste;

    do {

        printf("Digite seu email: ");
        fgets(email[contadorUsuario], 100, stdin);

        for (int i = 0; i <= 100; i++) {

            if(email[contadorUsuario][i] == '@') {

                teste = 1;

            }
            
           /* else {

                teste = 0;
                printf(" Digite seu email com @ PINTO");

            } */ 

        }   

    } while(teste != 1);

}
