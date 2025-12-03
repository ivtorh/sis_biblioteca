// SISTEMA DE GERENCIAMENTO DE LIVROS
#include <stdio.h>
#include <string.h>

#define TAMANHO_ACERVO 20   // Define o tamanho máximo do acervo

// ----------------------------------------------------------------
// STRUCT PRINCIPAL DO SISTEMA
// REPRESENTA UM LIVRO NO ACERVO
// ----------------------------------------------------------------
struct Livro {
  int codigo;
  char titulo[50];
  char autor[50];
  char area[30];
  int anoPublicacao;
  char editora[50];
};

//----------------------------------------------------------------
// ASSINATURAS DAS FUNÇÕES
//----------------------------------------------------------------
void cadastrarLivros(struct Livro acervo[], int tamanho);
void imprimirLivros(struct Livro acervo[], int tamanho);
void pesquisarLivro(struct Livro acervo[], int tamanho, int codigoBusca);
void ordenarLivros(struct Livro acervo[], int tamanho);

//----------------------------------------------------------------
// FUNÇÃO PRINCIPAL
//----------------------------------------------------------------
int main() {
  struct Livro acervo[TAMANHO_ACERVO]; // Array para armazenar os 20 livros
  int opcao, codigoBusca;

  do {
    // Menu do sistema
    printf("\n--- SISTEMA DE GERENCIAMENTO DE LIVROS ---\n");
    printf("1. Cadastrar Livros\n");
    printf("2. Imprimir Livros\n");
    printf("3. Pesquisar Livro por Código\n");
    printf("4. Ordenar Livros por Título\n");
    printf("5. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        cadastrarLivros(acervo, TAMANHO_ACERVO);
        break;
      case 2:
        imprimirLivros(acervo, TAMANHO_ACERVO);
        break;
      case 3:
        printf("Digite o código do livro para pesquisa: ");
        scanf("%d", &codigoBusca);
        pesquisarLivro(acervo, TAMANHO_ACERVO, codigoBusca);
        break;
      case 4:
        ordenarLivros(acervo, TAMANHO_ACERVO);
        printf("Livros ordenados por título com sucesso!\n");
        break;
      case 5:
        printf("Saindo do sistema...\n");
        break;
      default:
        printf("Opção inválida! Tente novamente.\n");
    }
  } while (opcao != 5);

  return 0;
};

//----------------------------------------------------------------
// FUNÇÃO 1: CADASTRAR LIVROS
//----------------------------------------------------------------
void cadastrarLivros(struct Livro acervo[], int tamanho) {
    int i;
    char linha[256];    // buffer para ler cada linha (suficiente)
    int codigoTemp, anoTemp;
    printf("\n=== CADASTRO DE LIVROS ===\n");

    for (i = 0; i < tamanho; i++) {
        printf("\n--- Livro %d ---\n", i + 1);

        // ---------- LER CÓDIGO (como string -> inteiro) ----------
        while (1) {
            printf("Código: ");
            if (!fgets(linha, sizeof(linha), stdin)) {
                // erro de I/O — tenta novamente
                clearerr(stdin);
                continue;
            }
            // remove \n
            linha[strcspn(linha, "\n")] = '\0';
            if (linha[0] == '\0') {
                // se vazio, pede novamente
                printf("Codigo nao pode ser vazio. Tente novamente.\n");
                continue;
            }
            if (sscanf(linha, "%d", &codigoTemp) == 1) {
                acervo[i].codigo = codigoTemp;
                break;
            } else {
                printf("Entrada invalida. Digite um numero inteiro para o codigo.\n");
            }
        }

        // ---------- LER TITULO ----------
        printf("Título: ");
        fgets(acervo[i].titulo, sizeof(acervo[i].titulo), stdin);
        acervo[i].titulo[strcspn(acervo[i].titulo, "\n")] = '\0';

        // ---------- LER AUTOR ----------
        printf("Autor: ");
        fgets(acervo[i].autor, sizeof(acervo[i].autor), stdin);
        acervo[i].autor[strcspn(acervo[i].autor, "\n")] = '\0';

        // ---------- LER AREA ----------
        printf("Área: ");
        fgets(acervo[i].area, sizeof(acervo[i].area), stdin);
        acervo[i].area[strcspn(acervo[i].area, "\n")] = '\0';

        // ---------- LER ANO (string -> inteiro) ----------
        while (1) {
            printf("Ano de Publicacao: ");
            if (!fgets(linha, sizeof(linha), stdin)) {
                clearerr(stdin);
                continue;
            }
            linha[strcspn(linha, "\n")] = '\0';
            if (linha[0] == '\0') {
                printf("Ano nao pode ser vazio. Tente novamente.\n");
                continue;
            }
            if (sscanf(linha, "%d", &anoTemp) == 1) {
                acervo[i].anoPublicacao = anoTemp;
                break;
            } else {
                printf("Entrada invalida. Digite um numero inteiro para o ano.\n");
            }
        }

        // ---------- LER EDITORA ----------
        printf("Editora: ");
        fgets(acervo[i].editora, sizeof(acervo[i].editora), stdin);
        acervo[i].editora[strcspn(acervo[i].editora, "\n")] = '\0';
    }

    printf("\nCadastro concluído com sucesso!\n");
}

//----------------------------------------------------------------
// FUNÇÃO 2: IMPRIMIR LIVROS
//----------------------------------------------------------------
void imprimirLivros(struct Livro acervo[], int tamanho) {
  int i;
  printf("\n=== LISTA DE LIVROS ===\n");

  for (i = 0; i < tamanho; i++) {
    printf("\n--- Livro %d ---\n", i + 1);
    printf("Código: %d\n", acervo[i].codigo);
    printf("Título: %s\n", acervo[i].titulo);
    printf("Autor: %s\n", acervo[i].autor);
    printf("Área: %s\n", acervo[i].area);
    printf("Ano de Publicação: %d\n", acervo[i].anoPublicacao);
    printf("Editora: %s\n", acervo[i].editora);
  }
}

//----------------------------------------------------------------
// FUNÇÃO 3: PESQUISAR LIVRO POR CÓDIGO
//----------------------------------------------------------------
void pesquisarLivro(struct Livro acervo[], int tamanho, int codigoBusca) {
  int i = 0, encontrado = 0; // Flag para indicar se o livro foi encontrado

  while (i < tamanho) {  // Percorre o acervo
    if (acervo[i].codigo == codigoBusca) {
      printf("\n--- Livro Encontrado ---\n");
      printf("Código: %d\n", acervo[i].codigo);
      printf("Título: %s\n", acervo[i].titulo);
      printf("Autor: %s\n", acervo[i].autor);
      printf("Área: %s\n", acervo[i].area);
      printf("Ano de Publicação: %d\n", acervo[i].anoPublicacao);
      printf("Editora: %s\n", acervo[i].editora);
      encontrado = 1;
      break;
    }
    i++;
  }
  if (!encontrado) {  // Se o livro não foi encontrado
    printf("Livro com código %d não encontrado no acervo.\n", codigoBusca);
  }
}

//----------------------------------------------------------------
// FUNÇÃO 4: ORDENAR LIVROS PELO ANO DE PUBLICAÇÃO
//----------------------------------------------------------------
void ordenarLivros(struct Livro acervo[], int tamanho) {  // Bubble Sort pelo ano de publicação
  int i, j;
  struct Livro temp;

  for (i = 0; i < tamanho - 1; i++){  
    for (j = 0; j < tamanho - i - 1; j++){
      if (acervo[j].anoPublicacao > acervo[j + 1].anoPublicacao){
        // Troca os livros de posição
        temp = acervo[j];
        acervo[j] = acervo[j + 1];
        acervo[j + 1] = temp;

      }
    }
  }
}

// ESSA FOI MINHA PRIMEIRA EXPERIÊNCIA COM C.
// ESPERO QUE TENHAM GOSTADO DO CÓDIGO! :)