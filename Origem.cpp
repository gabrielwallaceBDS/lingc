#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int menu();
void adicionar();
void Listar();
void Buscar();
void Sair();
void IncializarAcervo();
void InsereItemNaLista(struct Musica musica);

struct Musica {
  char titulo[50];
  char artista[50];
  char duracao[6];
  struct Musica *prox;
} *Head;

int main(int argc, char const *argv[])
{
  setlocale(LC_ALL, "Portuguese");

  int opcao;
  char resp;

  Head = NULL;


  IncializarAcervo();

  while(1)
  {
    opcao = menu();

    switch (opcao)
    {
    case 1: //LISTAR MÚSICAS
      Listar();
      break;
    case 2: //INSERIR MÚSICA
      adicionar();
      break;
    case 3:
      Buscar();
      break;
    case 4:
      Sair();
      break;
    default:
      printf("Opção inválida.");
      break;
    }
  }
  return 0;
}

int menu()
{
  int op, c;
  // system("clear");
  printf("________________________\n\n");
  printf("Music Player\n");
  printf("1 - Listar Músicas\n");
  printf("2 - Inserir Música\n");
  printf("3 - Procurar Música\n");
  printf("4 - Sair\n\n");
  printf("Digite a opção que deseja executar: ");
  printf("\n\n");
  printf("________________________\n");
  scanf("%d", &op);

  while((c = getchar()) != '\n' && c != EOF) {} //reset buffer
  system("clear");
  return op;
}

void adicionar()
{
  printf("Inserir Música.\n");
  int c;


  Musica *NovaMusica;
  NovaMusica = (struct Musica *)malloc(sizeof(struct Musica));
  Musica *ElementoVarredura;

  printf("\nDados da música a ser inserida: ");
  printf("\nTítulo: ");
  fgets(NovaMusica->titulo, 49, stdin);
  printf("Artista: ");
  fgets(NovaMusica->artista, 49, stdin);
  printf("Duração: ");
  fgets(NovaMusica->duracao, 5, stdin);
  while((c = getchar()) != '\n' && c != EOF) {} //reset buffer

  InsereItemNaLista(*NovaMusica);
}

void Buscar()
{
  char tituloBuscado[50];
  int c;

  Musica *ElementoVarredura;

  printf("Pesquise a musica: ");
  fgets(tituloBuscado, 49, stdin);

  ElementoVarredura = Head;

  while (ElementoVarredura != NULL)
  {
    if( strcmp(ElementoVarredura->titulo, tituloBuscado) == 0 ) {
    printf("\n----------------------------\n");
      printf("Título: %s", ElementoVarredura->titulo);
      printf("Artista: %s", ElementoVarredura->artista);
      printf("Duração: %s", ElementoVarredura->duracao);
    }
    ElementoVarredura = ElementoVarredura->prox;
  }
  printf("\n");

  getchar();
  return;
}

void Listar()
{
  
  Musica *ElementoVarredura = Head;

  while (ElementoVarredura != NULL)
  {
    printf("\n======================================\n");
    printf("Título: %s", ElementoVarredura->titulo);
    printf("Artista: %s", ElementoVarredura->artista);
    printf("Duração: %s", ElementoVarredura->duracao);
    ElementoVarredura = ElementoVarredura->prox;
  }
  printf("\n");
  getchar();
  return;
  
}


void IncializarAcervo() {

  struct Musica acervo[] = {
    {"Nova Era\n", "Yunk vino\n", "2:13", NULL},
    {"Mercury\n", "Ghostemane\n", "2:05", NULL},
    {"Star Shopping\n", "Lil Peep\n", "2:22", NULL},
    {"Ghxwth\n", "Scarlxrd\n", "2:44", NULL},
    {"Molho\n", "Did Brock\n", "2:44", NULL},
    {"Rei dos Piratas\n", "enygma98\n", "7:14", NULL},
    {"Molho\n", "Did Brock\n", "2:44", NULL},
    {"Rei dos Piratas\n", "enygma98\n", "7:14", NULL}
  };

  unsigned int tamanhoAcervo = 10;
  for(int i = 0; i < tamanhoAcervo; i++) {
    InsereItemNaLista(acervo[i]);
  }
}

void InsereItemNaLista(struct Musica musica) {

  struct Musica* NovaMusica = (struct Musica *) malloc(sizeof(struct Musica));

  strcpy(NovaMusica->titulo, musica.titulo);
  strcpy(NovaMusica->artista, musica.artista);
  strcpy(NovaMusica->duracao, musica.duracao);
  NovaMusica->prox = NULL;

  if(Head == NULL)
  {
    Head = NovaMusica;
    Head->prox = NULL;
  }
  else
  {
    struct Musica* ElementoVarredura = Head;
    while (ElementoVarredura->prox != NULL)
      ElementoVarredura = ElementoVarredura->prox;
    ElementoVarredura->prox = NovaMusica;
    NovaMusica->prox = NULL;
  }
}

void Sair() {
  printf("Obrigado por utilizar nosso app! :)\n\n");
  exit(0);
}
