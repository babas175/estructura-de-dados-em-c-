#include<stdio.h>
#include<stdlib.h>


typedef struct {
  int dia;
  int mes;
  int ano;
} Data;


typedef struct info {
  char matricula[10];
  char nome[40];
  Data nascimento;
  float nota;
  struct info *proximo;

}info;

void setData(Data *dt, int d,int m, int a)
{
  dt->dia=d;
  dt->mes=m;
  dt->ano=a;
}

void printData(Data d)
{
  printf("Data: %d/%d/%d\n",d.dia,d.mes,d.ano);
}

int tam;

void inicia(info *LISTA){
	LISTA->proximo = NULL;
	tam = 0;
}


info *aloca(){
  info *novo = (info *) malloc(sizeof(info));
	if (!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	return novo;
}

void incluir(info *LISTA)
{
    info *novo = aloca();
    novo->proximo=LISTA->proximo;
    LISTA->proximo=novo;
    printf("matricula\n");
    scanf("%s",novo->matricula);
    printf("nome\n");
    scanf("%s",novo->nome);
    printData(novo->nascimento);
    printf("nota\n");
    scanf("%f",&novo->nota);

    tam++;


}
void excluir(info *LISTA)
{
  if (LISTA->proximo == NULL)
		printf("Lista vazia!");
	else{
		info*tp = LISTA->proximo;
		LISTA->proximo= tp->proximo;
		printf("Matricula %s removido com sucesso!",tp->matricula);
		free(tp);
    tam--;
	}


}
void Listar(info *LISTA) {


  if (LISTA->proximo == NULL)
		printf("Lista vazia!");

  else{

    info *tp= aloca();
    for (tp = LISTA->proximo; tp != NULL; tp = tp->proximo)
    printf("%s", tp->matricula);
    printf("%s", tp->nome);
    printData(tp->nascimento);
    printf("%f", tp->nota);

  }


}
void lista_inversa(info*LISTA){





}

void tamanho(info*LISTA){
  printf("tamanho da lista : %d\n", tam);


}

void sair(info*LISTA){
  printf("----\n");
}


int main (void)
{

  info *LISTA= aloca();
  inicia(LISTA);
  int opcao;


  do{


    scanf("%d",&opcao);



  switch(opcao)
  {

    case 1:
      incluir(LISTA);
      break;

    case 2:
      excluir(LISTA);
      break;

    case 3:
      Listar(LISTA);
      break;

    case 4:
      lista_inversa(LISTA);
      break;

    case 5:
      tamanho(LISTA);
      break;

    case 0:
      sair(LISTA);
      break;

    default:
      printf("comando invalido\n\n");
  }

}while (opcao<=5);
  return 0;
}
