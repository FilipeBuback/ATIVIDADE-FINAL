#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

typedef struct {
    char tamanho[100];
} entra_valores;

struct tCircuito {
  entra_valores dado;
  struct tCircuito* prox;
};

typedef struct {
  struct tCircuito* inicio;
} Lista;

void ler(entra_valores *pe) {
  cin >> pe->tamanho;
}

void menu(){
  cout <<"===========ESCOLHA UMA APÇÃO==========="<<endl;
  cout <<" 1 - Para inserir e gravar " <<endl;
  cout <<" 2 - para exibir os dados "<<endl;
  cout <<" 3 - para parar "<<endl;
  cout <<"                Opcão: ";

}

void inserir(Lista *lista, entra_valores dado) {
  struct tCircuito* tCircuitovo = (struct tCircuito*) malloc(sizeof(struct tCircuito));
  tCircuitovo->dado = dado;
  tCircuitovo->prox = lista->inicio;
  lista->inicio = tCircuitovo;
}

void mostrar(Lista lista){
  struct tCircuito* circuito;
  for(circuito = lista.inicio; circuito != NULL; circuito= circuito->prox){
    cout<<circuito->dado.tamanho<<" ";
  }
  cout<<endl;
}

void gravar(Lista lista){
  FILE *file = fopen("./Banco_de_dados.txt", "w");
  struct tCircuito* circuito;
    for(circuito = lista.inicio; circuito != NULL; circuito = circuito->prox){
      fwrite(&circuito->dado, sizeof(entra_valores), 1, file);
    }
  fclose(file);
}

Lista buscar(){
  Lista lista;
  lista.inicio = NULL;
  FILE *file = fopen("./Banco_de_dados.txt", "r");
    entra_valores a;
    while(fread(&a, sizeof(entra_valores), 1, file)){
      inserir(&lista, a);
    }
  fclose(file);
  return lista;
}

int main() {

  Lista lista;
  lista.inicio = NULL;
  int op, quant, i=0;

  menu();
  cin >> op;

 

  return 0;
}