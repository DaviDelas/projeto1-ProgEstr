#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int menu();
void cadastro();
void editarUsuario();
void testeEmail();
int verificaEmail(char *email);
int buscarEmail();
void testeSexo();
void testeVacina();
void testeAltura();
void imprimirUsuario();
void idAutomatico();
int buscarUsuarioId();
void imprimirUsuarioId(int posicao);
void excluir();
void backupCadastro();
void restaurarBackup();
int stricmp(const char *a, const char *b);

char funcaoEmail[100], nome[1000][100], email[100][100], sexo[1000][20], endereco[1000][100];
int intMenu, id[1000];
double altura[1000];
bool vacina[1000];
int contadorUsuario = 0;

char backupNome[1000][1000], backupEmail[100][100], backupSexo[20][100], backupEndereco[100][100];
double backupAltura[1000];
bool backupVacina[1000];
int backupContadorUsuario = 0;

int main(){
    system("cls");
    srand(time(NULL));
    do{
        switch(menu()){
        case 1:
            cadastro();
            break;
        case 2:
            editarUsuario(); 
            break;
        case 3:
            excluir(); 
            break;
        case 4:
            imprimirUsuarioId(buscarUsuarioId()); 
            break;
        case 5:
            imprimirUsuario(buscarEmail()); 
            break;
        case 6:
            imprimirUsuario(); 
            break;
        case 7:
            backupCadastro(); 
            break;
        case 8:
            restaurarBackup(); 
            break;
        case 9:
            printf("\nSair "); 
            break;
        default:
            printf(" \nExeculte o programa corretamente");
            break;
        }
    }while(intMenu != 9);
    return 0;
}
int menu(){
    printf(" \n\nMenu\n\n1 - Incluir usuario \n2 - Editar usuario \n3 - Excluir usuario \n4 - Buscar usuario pelo id \n5 - Buscar usuario pelo email");
    printf(" \n6 - Imprimir todos usuario cadastrados\n7 - Faça backup dos usuarios cadastrado\n8 - Faça restauração dos dados\n9 - sair \n\n");
    scanf("%i", &intMenu);
    return intMenu;
}
void cadastro(){
    printf("\nDigite seu nome completo: ");
    getchar();
    gets(nome[contadorUsuario]);
    testeSexo(contadorUsuario);
    testeEmail(contadorUsuario);
    printf("Digite seu endereço: ");
    gets(endereco[contadorUsuario]);
    testeAltura(contadorUsuario);
    testeVacina(contadorUsuario);
    idAutomatico();
    system("cls");
    printf("\nUsuario cadastrado - seu ID e: %d", id[contadorUsuario]);
    contadorUsuario++;
}
void editarUsuario(){
    int alterar;
    char escolha;
    int teste;
    int editarEscolha;
    printf(" \nDigite a opção para editar: \n\n1 - buscar por ID\n2 - buscar por email\n\n ");
    scanf("%d", &editarEscolha);
    if(editarEscolha == 1){
        teste = buscarUsuarioId();
    }
    else if(editarEscolha == 2){
        teste = buscarEmail();
    }
    else{
        printf("Opção invalida");
        teste = -1;
    }
    imprimirUsuarioId(teste);
    if(teste >= 0){
        do{
            fflush(stdin);
            printf("\n\nDeseja realmente editar o usuario ?  S - sim / N - não ");
            scanf("%c", &escolha);
            if(escolha == 'S' || escolha == 's'){
                printf(" \n 1 - Nome \n 2 - Email \n 3 - Sexo \n 4 - Endereço \n 5 - Altura \n 6 - Tomou a vacina ?");
                printf("\n\nInsira um número para alteração ");
                scanf("%d",&alterar);
                switch(alterar){
                    case 1:
                        fflush(stdin);
                        printf("\n Digite seu nome completo ");
                        gets(nome[teste]);
                        break;
                    case 2:
                        fflush(stdin);
                        testeEmail(teste);
                        break;
                    case 3:
                        fflush(stdin);
                        testeSexo(teste);
                        break;
                    case 4:
                        fflush(stdin);
                        printf("Digite seu endereço: ");
                        gets(endereco[teste]);
                        break;
                    case 5:
                        testeAltura(teste);
                        break;
                    case 6:
                        testeVacina(teste);
                        break;
                    default:
                    printf("\nOpção invalida");
                    break;
                }
                printf("\nUsuario editado\n");
            }else if(escolha == 'N' || escolha == 'n'){
                printf(" Operação cancelada\n");
            }else if(escolha != 'S' && escolha != 's' && escolha != 'N' && escolha != 'n'){
                printf(" Opção invalida");
            }
        }while(escolha != 'S' && escolha != 's' && escolha != 'N' && escolha != 'n');
    }
}
void excluir(){
    char escolha;
    int teste;
    int excluirEscolha;
    printf(" \nDigite a opção para excluir: \n\n1 - Exclusão por ID\n2 - Exclusão por email\n\n ");
    scanf("%d", &excluirEscolha);
    if(excluirEscolha == 1){
        teste = buscarUsuarioId();
    }
    else if(excluirEscolha == 2){
        teste = buscarEmail();
    }
    else{
        printf("Opção invalida");
        teste = -1;
    }
    imprimirUsuarioId(teste);
    if(teste >= 0){
        do{
            fflush(stdin);
            printf("\n\nDeseja realmente excluir o usuario ?  S - sim / N - não ");
            scanf("%c", &escolha);
            if(escolha == 'S' || escolha == 's'){
                for(int i = teste; i <= contadorUsuario; i++){
                    if(i != contadorUsuario){
                        strcpy(nome[i], nome[i + 1]);
                        strcpy(email[i], email[i + 1]);
                        strcpy(sexo[i], sexo[i + 1]);
                        strcpy(endereco[i], endereco[i + 1]);
                        altura[i] = altura[i + 1];
                        vacina[i] = vacina[i + 1];
                        id[i] = id[i + 1];
                    }else{
                        strcpy(nome[i], "");
                        strcpy(email[i], "");
                        strcpy(sexo[i], "");
                        strcpy(endereco[i], "");
                        altura[i] = 0;
                        vacina[i] = 0;
                        id[i] = 0;
                    }
                }
                contadorUsuario -= 1;
                printf("\nUsuario removido\n");
            }
            else if(escolha == 'N' || escolha == 'n'){
                printf(" Operação cancelada\n");
            }
            else if(escolha != 'S' && escolha != 's' && escolha != 'N' && escolha != 'n'){
                printf(" Opção invalida");
            }
        }while(escolha != 'S' && escolha != 's' && escolha != 'N' && escolha != 'n');
    }
}
int verificaEmail(char *email){
    bool teste = 1;
    for(int i = 0; i <= 100; i++){
        if(email[i] == '@'){
            teste = 1;
            break;
        }
        else{
            teste = 0;
        }
    }
    if(teste == 0){
        printf("Digite seu email corretamente com @ \n");
    }
    return teste;
}
void testeEmail(int posicao){
    int teste;
    do{
        printf("Digite seu email: ");
        gets(email[posicao]);
        teste = verificaEmail(email[posicao]);
    }while(teste != 1);
}
int buscarEmail(){
    strcpy(funcaoEmail,"");
    int teste, posicao;
    do{
        fflush(stdin);
        printf("\nInsira o email do usuario: ");
        gets(funcaoEmail);
        teste = verificaEmail(funcaoEmail);
    }while(teste != 1);
    for(int i = 0; i <= 100; i++){
        if(strcmp (funcaoEmail, email[i]) == 0){
            posicao = i;
            break;
        }else{
            posicao = -1;
        }
    }
    if(posicao < 0){
        printf("\nEmail não cadastrado");
    }
    return posicao;
}
void testeSexo(int posicao){
    int sexoTeste;
    do{
        fflush(stdin);
        printf("Digite seu sexo: masculino, feminino ou não declarar): ");
        gets(sexo[posicao]);
        if(strcmp(sexo[posicao], "masculino") == 0 || strcmp(sexo[posicao], "feminino") == 0 || strcmp(sexo[posicao], "nao declarar") == 0){
            sexoTeste = 1;
        }
        else{
            sexoTeste = 0;
        }
        if(sexoTeste == 0){
            printf("Digite seu sexo corretamente\n");
        }
    }while(sexoTeste == 0);
}
void testeVacina(int posicao){
    do{
        printf("Tomou a vacina ? (Sim = 1 / Não = 0): ");
        scanf("%d", &vacina[posicao]);
        if(vacina[posicao] != 0 && vacina[posicao] != 1){
            printf("\nDigite as opções corretamente ");
        }
    }while(vacina[posicao] != 0 && vacina[posicao] != 1);
}
void testeAltura(int posicao){
    do{
        printf("Digite sua altura: ");
        scanf("%lf", &altura[posicao]);
        if(altura[posicao] > 2 || altura[posicao] < 1){
            printf("Digite uma altura valida para o programa\n");
        }
    }while(altura[posicao] > 2 || altura[posicao] < 1);
}
void imprimirUsuario(){
    if(contadorUsuario != 0){
    char imprimir[10];
    for(int i = 0; i < contadorUsuario; i++){
            if(vacina[i] == 1){
                strcpy(imprimir, "sim");
            }
            else{
                strcpy(imprimir, "não");
            }
            printf(" \n Nome: %s\n Email: %s\n Sexo: %s\n Endereço: %s Altura: %.2lf\n Tomou a vacina ?: %s \n ID usuario: %d\n", nome[i], email[i], sexo[i], endereco[i], altura[i], imprimir, id[i]);
        }
    }else{
        printf("\nNão existe usuario cadastrado\n");
    }
}
void idAutomatico(){
    int idUsuario, teste = 0;
    do{
        idUsuario = rand();
        for(int i = 0; i < 1000; i++){
            if(idUsuario == id[i]){
                teste = 1;
                break;
            }
        }
    }while(teste == 1);
    id[contadorUsuario] = idUsuario;
}
int buscarUsuarioId(){
    int buscarUsuarioId, teste = 0, posicao;
    printf("\nDigite o número ID do usuario ");
    scanf("%d", &buscarUsuarioId);
    for(int i = 0; i < 1000; i++){
        if(buscarUsuarioId == id[i]){
            teste = 1;
            posicao = i;
            break;
        }
        else{
            posicao = -1;
        }
    }
    if(posicao < 0){
        printf(" \nid não encontrado");
    }
    return posicao;
}
void imprimirUsuarioId(int posicao){
    char imprimir[7];
    if(posicao >= 0){
        if(vacina[posicao] == 1){
            strcpy(imprimir, "sim");
        }
        else{
            strcpy(imprimir, "não");
        }
        printf(" \n Nome: %s Email: %s Sexo: %s\n Endereço: %s Altura: %.2lf\n Tomou a vacina ?: %s \n ID usuario: %d", nome[posicao], email[posicao], sexo[posicao], endereco[posicao], altura[posicao], imprimir, id[posicao]);
    }
}
void backupCadastro(){
    for(int i = 0; i < contadorUsuario; i++){
        strcpy(backupNome[i], nome[i]);
        strcpy(backupEmail[i], email[i]);
        strcpy(backupSexo[i], sexo[i]);
        strcpy(backupEndereco[i], endereco[i]);
        backupAltura[i] = altura[i];
        backupVacina[i] = vacina[i];
    }
    backupContadorUsuario = contadorUsuario;
    printf(" \nBackup Realizado com sucesso");
}
void restaurarBackup(){
    for(int i = 0; i < backupContadorUsuario; i++){
        strcpy(nome[i], "");
        strcpy(email[i], "");
        strcpy(sexo[i], "");
        strcpy(endereco[i], "");
        altura[i] = 0;
        vacina[i] = 0;
    }
    for(int i = 0; i < backupContadorUsuario; i++){
        strcpy(nome[i], backupNome[i]);
        strcpy(email[i], backupEmail[i]);
        strcpy(sexo[i], backupSexo[i]);
        strcpy(endereco[i], backupEndereco[i]);
        altura[i] = backupAltura[i];
        vacina[i] = backupVacina[i];
    }
    contadorUsuario = backupContadorUsuario;
    printf(" \nRestauração dos dados Realizado com sucesso");
}
