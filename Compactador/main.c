#include<stdio.h>
#include "NoArvore.h"
#include "Fila.h"

int tamanho;

int main()
{
   FILE *ponteiroArquivo;
   NoFila* f = NULL;
  char arq[30];

  printf("Opcao escolhida: ");

  scanf("%s", arq);

  ponteiroArquivo = fopen(arq, "r");

  if(ponteiroArquivo == NULL)
     printf("Erro na abertura do arquivo!");

  fseek(ponteiroArquivo, 0, SEEK_END);
  tamanho = ftell(ponteiroArquivo);

  int qtd = 0;
  rewind(ponteiroArquivo);

  char c = getc(ponteiroArquivo);
  while(c != EOF)
    {
        NoFila* atual = buscar(c, f);
        f=atual;
        c = getc(ponteiroArquivo);
      }

       char car;
         int fre;

          NoFila* teste = f;
          while(teste->prox !=NULL)
          {
              car = teste->info->caracter;
              fre = teste->info->frequencia;
              //printf("%c",car);
             // printf("%i", fre);
             // printf("\n");
              teste = teste->prox;
              qtd++;
          }
              car = teste->info->caracter;
              fre = teste->info->frequencia;
             // printf("%c",car);
             // printf("%i", fre);
             // printf("\n\n");
              qtd++;


    while(qtd > 1)
    {
        NoArvore* primeiro = pop(&f);
        printf("%c",primeiro->caracter);
        printf("%i",primeiro->frequencia);

        NoArvore *segundo = pop(&f);
        //printf("%c",segundo->caracter);
        //printf("%i",segundo->frequencia);


        int frequencia = (primeiro->frequencia) + (segundo->frequencia);
        NoFila* novo = (NoFila*)malloc(sizeof(NoFila));
        novo->info->frequencia = frequencia;
        novo->info->vazio = 1;

        //printf("%i", novo->info->frequencia);
        //printf("\n");

        NoFila*esq = (NoFila*) malloc(sizeof(NoFila));
        esq->info = primeiro;

        NoFila*dir = (NoFila*) malloc(sizeof(NoFila));
        dir->info = segundo;

        novo->info->esq = esq;
        novo->info->dir = dir;

        f = insira(f,novo);
    }
    NoFila* filaLet = (*NoFila)malloc(sizeof(NoFila));
    int cod;
    while()
  }
