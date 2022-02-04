#include <stdio.h>
#include <stdlib.h>


int menu(void);
void incluir(void);
void excluir(void);
void Listar(void);
void Listar_inversa(void);
void tamanho(void);
void sair(void);


struct info {
  char matricula[10];
  char nome[40];
  char data_de_nascimento[10];
  float nota;
  struct info *anterior;
  struct info *proximo;

};



struct info *inicio;
struct info*fim;
int tam;

int main(void)
{
  inicio = fim = NULL;
  for (;;){
    switch (menu()) {
      case 1: incluir ();
        break;
      case 2: excluir();
        break;
      case 3: Listar();
        break;
      case 4: Listar_inversa();
        break;
      case 5: tamanho();
        break;
      case 0: sair();
        break;
      default:
        printf("opcao invalida\n! ");
    }
  }
}


int menu (void)
{
  int opcao;
  scanf("%d",&opcao );
  return opcao;

}
void incluir(void)
{
  struct info *novo;
  novo=(struct info*)malloc(sizeof(struct info));
  if (!novo) {
    printf("sem memoria ");
    return;
  }
  scanf("%s",novo->matricula);
  scanf("%s",novo->nome);
  scanf("%s",novo->data_de_nascimento);
  scanf("%f",&novo->nota);

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

void excluir(void)
{

  if (inicio==NULL){
    printf("nenhum elemento para excluir!\n");
  }
  else{

    struct info*lista=(struct info *)malloc(sizeof(struct info));
    printf("matricula a ser excluido %s\n", lista->matricula);
    scanf("%s",lista->matricula);
    free(lista->matricula);
    tam--;
    return;
  }

}

void Listar(void)
{
  if (inicio==NULL){
    printf("nenhum elemento para imprime !\n");
  }
  struct info *percorre;
  percorre = inicio;
  while(percorre){
    printf("%s, ", percorre->matricula);
    printf("%s, ", percorre->nome);
    printf("%s, ",percorre->data_de_nascimento);
    printf("%f\n ", percorre->nota);
    percorre = percorre->proximo;
  }
}

void Listar_inversa(void)
{
  if (inicio==NULL){
    printf("nenhum elemento para imprime !\n");
  }
  struct info *percorre;
  percorre = fim;
  while(percorre){
    printf("%s, ", percorre->matricula);
    printf("%s, ", percorre->nome);
    printf("%s, ",
    percorre->data_de_nascimento);
    printf("%f \n", percorre->nota);
    percorre = percorre->anterior;
  }
}

void tamanho(void)
{
printf("tamnho da lista: %d \n",tam);
}

void sair(void)
{
  printf("-\n");
}
