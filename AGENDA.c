#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//os struct
struct agenda {
    char nome[20];
    char data_de_nascimento[30];
    struct agenda *prox;
    struct tel *t;
    struct mail *m;

};
struct tel{
       char telefone[20];
       struct tel *prox;
};
struct mail{
       char email[30];
       struct mail *prox;
};


struct agenda* criaAgenda (){
     return NULL;
}
struct tel* criaTel(){
     return NULL;
}
struct mail*criaMail(){
       return NULL;
}
//funcao pra inserir tel
void insereTel(struct tel **t,char tel[]){
     struct tel *p,*q;

      p=(struct tel*)malloc(sizeof(struct tel));
      strcpy(p->telefone,tel);
      p->prox=*t;
      *t=p;

}

//funcao para inserir email
void insereMail(struct mail **m,char mail[]){
     struct mail *p;
      p=(struct mail*)malloc(sizeof(struct mail));

      strcpy(p->email,mail);
      p->prox=*m;
      *m=p;
}


void inserePessoa (struct agenda **L, struct tel *T,struct mail *M, char n[], char end[]){
     struct agenda *p;


     p=(struct agenda*)malloc(sizeof(struct agenda));


     strcpy(p->nome,n); strcpy(p->data_de_nascimento,end);
     p->prox=*L;
     p->t=T;
     p->m=M;
     *L=p;


}
//funcao para inserir contato posicionado
void insereContatoPosicionado(struct agenda **L, struct tel *T,struct mail *M, char n[], char end[]){
     struct agenda *p;


     p=(struct agenda*)malloc(sizeof(struct agenda));


     strcpy(p->nome,n); strcpy(p->data_de_nascimento,end);
     p->prox=*L;
     p->t=T;
     p->m=M;
     *L=p;
}





struct agenda* localiza(struct agenda *L,char n[]){
     struct agenda *p;
     struct tel *auxt;
     struct mail *auxm;
     int cont=0;
     p=L;
     auxt=p->t;
     auxm=p->m;
     while(p!=NULL){
        if (strcmp(p->nome,n)!=0)
            p=p->prox;
          else{
                  printf("\n\nNome -> %s",p->nome);
                  printf("\n\nData_de_nascimento -> %s",p->data_de_nascimento);
                  while(auxt!=NULL){
                     printf("\n\nTelefone -> %s",auxt->telefone);
                     auxt =auxt->prox;
                  }
                  while (auxm!=NULL){
                     printf("\n\nemail -> %s",auxm->email);
                     auxm=auxm->prox;
                  }

           return p;
           }


     }
     return NULL;
}
//funcao para imprime 
void listarTodos(struct agenda *L){
     struct agenda *p;
     struct tel *auxt;
     struct mail *auxm;
     p=L;
     auxt=p->t;
     auxm=p->m;
     while (p!=NULL){
             printf("\n\nNome -> %s",p->nome);
             printf("\n\ndata_de_nascimento -> %s",p->data_de_nascimento);
             while(auxt!=NULL){
                     printf("\n\nTelefone -> %s",auxt->telefone);
                     auxt =auxt->prox;
                  }
                  while (auxm!=NULL){
                     printf("\n\nemail -> %s",auxm->email);
                     auxm=auxm->prox;
                  }
           p=p->prox;
           printf("\n\n=================\n\n");
     }
}

//funcao para buscar
void listaLetra(struct agenda *L,char n){
     struct agenda *p;
     struct tel *auxt;
     struct mail *auxm;
     p=L;
     auxt=p->t;
     auxm=p->m;
     while (p!=NULL){
           if(p->nome[0]!=n)
              p=p->prox;
           else{
             printf("\n\nNome -> %s",p->nome);
             printf("\n\ndata_de_nascimento -> %s",p->data_de_nascimento);
             while(auxt!=NULL){
                     printf("\n\nTelefone -> %s",auxt->telefone);
                     auxt=auxt->prox;
                  }
                  while (auxm!=NULL){
                     printf("\n\nemail -> %s",auxm->email);
                     auxm=auxm->prox;
                  }
             p=p->prox;
             printf("\n\n======================\n\n");
             }
     }
}

//funcao para alterar dados
void alterarDados(struct agenda *L,char n[]){
     int cont=0;
     struct agenda *p;
     struct tel *auxt;
     struct mail *auxm;
     auxt=p->t;
     auxm=p->m;
     p=localiza(L,n);
        if(p==NULL)
        printf("\nNome não encontrado");
        else{
                printf("\n\nDigite uma nova data de nascimento: ");
                scanf("%s",p->data_de_nascimento);

                while (auxt!=NULL){
                      printf("\n\n Digite o novo telefone:");
                      scanf("%s",auxt->telefone);
                      auxt=auxt->prox;
                }
               while (auxm!=NULL){
                     printf("\n\n Digite o novo email:");
                     scanf("%s",auxm->email);
                     auxm=auxm->prox;
               }
    }
}

//struct para remover 

struct agenda* removerNome(struct agenda *L,char n[]){
    struct agenda *p, *q;
    p=localiza(L,n);
    if (p==NULL)
        printf("\nNome nao encontrado");
    else{
        q=L;
        if(q==p){
            L=p->prox;
            free(p);
        }else{
        while (q->prox!=p)
            q=q->prox;

         q->prox=p->prox;
         free(p);
        }
        printf("\n\ncontato removido com sucesso");
    }
    return L;
}



//programa main

int main(){
       struct agenda *Lista;
       struct tel *Tel;
       struct mail *Mail;
       int op;
       char nome[30], data_de_nascimento[30], telefone[15], email[40];
       char no;

       Lista=criaAgenda();
       Tel=criaTel();
       Mail=criaMail();
          //menu
       do{
          system("cls");
          printf("\n\n===Agenda telefonica eletronia===\n");
          printf("\n1- INSERIR ");
          printf("\n2- INSERIR CONTATO");
          printf("\n3- DELETAR CONTATO");
          printf("\n4- LISTA OS CONTATOS");
          printf("\n5- CONSULTAR UM CONTATO");
          printf("\n6 -ATUALIZAR CONTATO\n");
          printf("<======================================>\n ");
          fflush(stdin);
          scanf("%d",&op);
            //as opcoes do menu
      switch (op){
             case 1: printf("\n Nome:");
                     fflush(stdin);
                     scanf("%s",nome);
                     printf("\n data_de_nascimento: ");
                     fflush(stdin);
                     scanf("%s",data_de_nascimento);

                     do{
                        printf("\n telefone:");
                        fflush(stdin);
                        scanf("%s",telefone);
                        insereTel(&Tel,telefone);
                        printf("\n possui mais telefone? 1 para sim e 2 para não\n\n");
                        scanf("%d",&op);
                     }while(op!=2);

                     do{
                           printf("\nemail:");
                           fflush(stdin);
                           scanf("%s", email);
                           insereMail(&Mail,email);
                           printf("\n possui mais mail? 1 para sim e 2 para não\n\n");
                           scanf("%d",&op);
                      }while(op!=2);

                     inserePessoa(&Lista,Tel,Mail,nome,data_de_nascimento);
              break;

              case 2: if(Lista==NULL)
                      printf("\nAgenda vazia");
                      else{
                      printf("\n Digite um email:");
                      fflush(stdin);
                      scanf("%s",nome);
                    if(localiza(Lista,nome)==NULL)
                      printf("\n Nome não encontrado na agenda");
                      }                                   break;

              case 3: if(Lista==NULL)
                      printf("\nAgenda vazia");
                      else{
                        printf("\nDigite o nome que deseja deletar da agenda:");
                        scanf("%s",nome);
                        Lista=removerNome(Lista,nome);
                      }
                      break;

              case 4: if(Lista==NULL)
                      printf("\nAgenda vazia");
                      else
                      listarTodos(Lista);

                      break;

              case 5: if(Lista==NULL)
                      printf("\nAgenda vazia");
                      else{
                       printf("\n Digite um nome:");
                      fflush(stdin);
                      scanf("%s",nome);
                      if(localiza(Lista,nome)==NULL)
                       printf("\n Nome não encontrado na agenda");
                      }
                      break;

              case 6: if(Lista==NULL)
                      printf("\nAgenda vazia");
                      else{
                        printf("Digite o nome que deseja alterar os dados:");
                        scanf("%s",nome);
                        alterarDados(Lista,nome);

                      }
                      break;
      }
      }while (op!=0);
  }
