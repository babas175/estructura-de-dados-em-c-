#include <stdio.h>
#include <stdlib.h>
#include<string.h> // para converter os carateres em string.

typedef struct // igualzinho vista nas aulas
{
    int dia;
    int mes;
    int ano;
} Data;

//a struct AGENDA
struct AGENDA {
  char nome[10];
  char email[40];
  char data_de_nascimento[10];
  char phone[15];
  struct AGENDA *anterior;
  struct AGENDA *proximo;

};



struct AGENDA *inicio;
struct AGENDA*fim;
int tam;
//
int menu(void);
void INSERIR(void);
void INSERIR_CONTATO(void);
void DELETAR(void);
void LISTAR(void);
void CONSULTAR(void);
void ATUALIZAR(void);
void sair(void);

//funcao para executar o menu
int main(void)
{
  inicio = fim = NULL;
  for (;;){
    switch (menu()) {
      case 1: INSERIR ();
        break;
      case 2: INSERIR_CONTATO();
        break;
      case 3: DELETAR();
        break;
      case 4: LISTAR();
        break;
      case 5: CONSULTAR();
        break;
      case 6: ATUALIZAR();
        break;
      case 0: sair();
        break;
      default:
        printf("opcao invalida\n! ");
    }
  }
}

//  menu
int menu (void)
{
  int opcao;
  printf("\nopcoes:\n\n");
  printf("1 - inserir \n");
  printf("2 - inserir contato posicionado\n");
  printf("3 - deletar contato\n");
  printf("4 - listar os contatos\n");
  printf("5 - consultar um contato\n");
  printf("6 - atualizar os campos de um contato\n");
  printf("7 - sair\n");
  printf("=========================\n");
  scanf("%d",&opcao );
  return opcao;

}

//funcao para inserir contato
void INSERIR(void)
{
  struct AGENDA *novo;
  novo=(struct AGENDA*)malloc(sizeof(struct AGENDA));
  if (!novo) {
    printf("sem memoria ");
    return;
  }
  printf("digite o nome: ");
  scanf("%s",novo->nome);
  printf("digite o email: ");
  scanf("%s",novo->email);
  printf("data de nascimento: ");
  scanf("%s",novo->data_de_nascimento);
  printf("phone: ");
  scanf("%s",novo->phone);

  if (fim==NULL){
    novo->proximo=NULL;
    novo->anterior=NULL;
    inicio=novo;
    fim=novo;
    return;
  }
  else{
    fim->proximo=novo;
    novo->proximo=NULL;
    novo->anterior=NULL;
    fim=novo;
  }



}

//funcao para retirar o contato
void DELETAR(void)
{

  if (inicio==NULL){
    printf("nenhum elemento para excluir!\n");
  }
  else{

    struct AGENDA*lista=(struct AGENDA *)malloc(sizeof(struct AGENDA));
    printf("email a ser excluido %s\n", lista->email);
    scanf("%s",lista->email);
    free(lista->email);
    return;
  }

}

//funcao para imprime os contatos
void LISTAR(void)
{
  if (inicio==NULL){
    printf("nenhum elemento para imprime !\n");
  }
  struct AGENDA *percorre;
  percorre = inicio;
  while(percorre!=NULL){
    printf("========CONTATOS==========\n");
    printf("\t nome: %s \n", percorre->nome);
    printf("\t email: %s \n ", percorre->email);
    printf("\t data de nascimento: %s \n ",percorre->data_de_nascimento);
    printf("\t phone: %s \n ", percorre->phone);
    percorre = percorre->proximo;
  }
}

//funcao para inserir contato posicionado
void INSERIR_CONTATO(void)
{
  if (inicio==NULL){
    printf("nenhum elemento para imprime !\n");
  }
  struct AGENDA *percorre;
  percorre = fim;
  while(percorre){
    printf("%s, ", percorre->nome);
    printf("%s, ", percorre->email);
    printf("%s, ",
    percorre->data_de_nascimento);
    printf("%s \n", percorre->phone);
    percorre = percorre->anterior;
  }
}

//funcao para consultar

void CONSULTAR(void)
{
  if(inicio==NULL){
    printf("nenhum elemneto para consultar ! ");
  }

  else{
    int p;
    struct AGENDA *CONSULTA;
    CONSULTA=inicio;


      while(CONSULTA!=NULL){
      printf("digite o nome para consultar");
      scanf("%d",&p);

        printf("%s \n",CONSULTA->nome);
        printf("%s \n",CONSULTA->email);
        printf("%s \n",CONSULTA->data_de_nascimento);
        printf("%s \n",CONSULTA->phone);

      }


  }


}

//atualizar
void ATUALIZAR(void)
{




}
//funcao para sair
void sair(void){
  printf("VOCE SAIU COM SUCESSO ");



}
