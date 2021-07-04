#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

typedef struct {
    char tamanho[100];//Define o tamanho da variavel que vai colher todos os valores de entrada
} entra_valores;

struct tCircuito {
  entra_valores dado;//responsavel pelos dados de entrada e pela lista encadeada 
  struct tCircuito* prox;//atribuo um ponteiro que aponta para a lista encadeada
};

typedef struct {
  struct tCircuito* inicio;//Responsavel pela construção da lista, esta estrutura e a anterior criam a lista encadeada
} Lista;

void ler(entra_valores *pe) {
  cin >> pe->tamanho;//le a entrada que o usuario vai digitar, no limite de 100 caracteres
}

void menu(){
  cout <<"===========ESCOLHA UMA APÇÃO==========="<<endl;
  cout <<" 1 - Para inserir o valor de resistencia e gravar " <<endl;
  cout <<" 2 - para exibir os valores de dados "<<endl;
  cout <<" 3 - para parar "<<endl;
  cout <<"                Opcão: ";
 //essa função apenas printa as opções possiveis para o usuario
}

void inserir(Lista *lista, entra_valores dado) {
  struct tCircuito* tCircuitovo = (struct tCircuito*) malloc(sizeof(struct tCircuito));//alocando uma quantidade de dados do tamanho de 100 caracteres, da estrutura declarada anteriormente
  tCircuitovo->dado = dado;
  tCircuitovo->prox = lista->inicio;//recebe o inicio da lista 
  lista->inicio = tCircuitovo;
  //pegamos o dado,coloco na lista e aloco na memoria posteriormente
}

void mostrar(Lista lista){//recebe uma lista, recebe o primeiro valor da lista, o ultimo valor da lista é sempre nula, percorre a lista ate chegar no valor null
  struct tCircuito* circuito;
  for(circuito = lista.inicio; circuito != NULL; circuito= circuito->prox){
    cout<<circuito->dado.tamanho<<" ";
  }
  cout<<endl;
}

void gravar(Lista lista){//recebe uma lista,abre o arq txt,escreve os valores digitados dentro do arquivo e fecha o arquivo, define os parametros recebidos
  FILE *file = fopen("./Banco_de_dados.txt", "w");
  struct tCircuito* circuito;
    for(circuito = lista.inicio; circuito != NULL; circuito = circuito->prox){
      fwrite(&circuito->dado, sizeof(entra_valores), 1, file);
    }
  fclose(file);
}

Lista buscar(){//declara a lista, pega os valores da lista e não do usuario, mostra e fecha novamente
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

  Lista lista;//declara a lista do tipo lista 
  lista.inicio = NULL;
  int op, quant, i=0;//declara uma variavel opcao e um contador

  menu();
  cin >> op;//le a opção do usuario 
 while(op!=3) {//um loop de interaçao con o usuario pra ver qual opção sera escolhida

    if(op == 1) {
      cout<<"Quantos dados deseja gravar? ";
      cin>>quant;//le quantos valores serão adicionador a lista
      while(i<quant){
        cout<<"Insira o "<<i+1<<"º dado ";
        entra_valores e;
        ler(&e);
        inserir(&lista, e);
        i++;//le todos os dados escolhidos
      }
      gravar(lista); //grava na lista
    }

    if(op == 2) {
      lista = buscar();//busca na lista e apresenta os dados gravados 
      mostrar(lista);
    }
    menu();
    cin >> op;
  }

 

  return 0;
}