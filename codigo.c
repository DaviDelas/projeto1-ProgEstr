//BOTA O CODIGO AQUI IRMÃO ! 

#include <stdio.h>
#include <stdlib.h>

int menu();
void cadastro();

char nome[1000][1000], email[100][100], sexo[20][100], endereco[100][100];
int intMenu;
double altura[1000];
int contadorUsuario = 0; 

int main(){

    do {

        switch (menu()) {

        case 1: fflush (stdin); cadastro(); break;
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

    printf("Digite seu email: ");
    fgets(email[contadorUsuario], 100, stdin);

    printf("Digite seu endereço: ");
    fgets(endereco[contadorUsuario], 100, stdin);

    printf("Digite sua altura: ");
    scanf("%lf", &altura[contadorUsuario]);

// printf("tomou a vacina ?");
// fgets(nome[contadorUsuario], 100, stdin);

    contadorUsuario++;

}
