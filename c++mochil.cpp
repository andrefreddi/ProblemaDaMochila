/* by Igor Duarte - 02/04/2016
 * Problema da mochila booleana
 */
 
#include <stdio.h>
#include <vector>
 
 
#define maxN 200	//coloque aqui a quantidade maxima de objetos 
#define maxC 1000	//coloque aqui o valor maximo do peso da mochila
 
 
using namespace std;
 
int tabela[maxN+1][maxC+1];
int peso[maxN+1];
int valor[maxN+1];
 
int main(){
	int capacidadedamochila, ValorDoObjeto, PesoDoObjeto, i, b, NumeroDeObjetos, s, soma, aux;
	vector<int> mochilaFinal;
 	
 	printf("> Capacidade da Mochila: ");
	while(scanf("%d", &capacidadedamochila),
		  printf("> Numero de objetos: "),
		  scanf("%d", &NumeroDeObjetos), capacidadedamochila ){ //capacidade da mochila, numero de objetos
 
		//lendo os elementos:
		for(i = 1; i<=NumeroDeObjetos; i++){

            printf("\n ----------------- \n");
            printf("> Peso do Objeto: ");
			scanf("%d", &PesoDoObjeto), //peso do objeto, valor do objeto
            printf("> Valor do Objeto: "),
            scanf("%d", &ValorDoObjeto);
			peso[i] = PesoDoObjeto;
			valor[i] = ValorDoObjeto;
		}
 
		//zerando a primeira coluna:
		for(i=0; i<=NumeroDeObjetos; i++){
			tabela[i][0] = 0;
		}
 
		//iniciando o algoritmo da mochila booleana:
		for(b = 1; b<=capacidadedamochila; b++){
			tabela[0][b] = 0;
 
			for(i=1; i<=NumeroDeObjetos; i++){
				s = tabela[i-1][b];
 
				//se o novo objeto nao ultrapassar o peso e tiver maior valor:
				if( peso[i] <= b){
					soma = tabela[i-1][b-peso[i]] + valor[i];
					if( s < soma){
						s = soma;
					}
				}
 
				tabela[i][b] = s;
			}
		}
 
 
		//imprimindo o valor maximo que ? possivel carregar na mochila:
            printf("\n ----------------- \n");
		printf("%d\n", tabela[NumeroDeObjetos][capacidadedamochila]); 
            printf("\n ----------------- \n");
		//obs. sim, o valor maximo sempre vai ficar na ultima posi?ao da matriz
 
 
 
 
		//imprimindo a matriz utilizada na programa?ao dinamica:
		for(i= 0; i<=NumeroDeObjetos; i++){
			for(b = 0; b<=capacidadedamochila; b++){
				printf("%d\t", tabela[i][b]);
			}
			puts("");
		}
		//obs remover-la da solu?ao final (apenas para depura?ao)
 
 
 
 
		 //encontrando os objetos que entraram na mochila:
		 i = NumeroDeObjetos;
		 b = capacidadedamochila;
		 aux = tabela[i][b];
 
		 while(aux){
			 if(tabela[i][b] != tabela[i-1][b]){ //significa que o objeto i entrou;
				 mochilaFinal.push_back(i);
				 b -= peso[i];
			 }
			 i--;
			 aux = tabela[i][b];
		 }
 
		 puts("Objetos na mochila:");
		 for(i=0; i<int(mochilaFinal.size()); i++){
			 printf("%d ", mochilaFinal[i]);
		 }
		 puts("");
 
 
		 mochilaFinal.clear();
 
 
	}
}

