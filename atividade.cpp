#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int v1[20]; // nosso vetor!!

char Menu(char a);

//---------------------------------------------------------	

void GerarNumeros(){  //O nome diz tudo... Gera numeros até 5000
	system("cls");
	printf("Numeros gerados: \n");
	for(int x=0;x<20;x++){
		v1[x]=rand()%4999;
		printf("[%d]\n", v1[x]);
	}
	printf("\nPressione ENTER para retornar ao menu... \n"); //Somente uma parada para não enviar diretamente o usuario ao menu.
	getchar();
	getchar(); //O uso de dois getchar foi o metodo mais simples que encontrei pra limpar o buffer e ler o proximo input do usuario.
}
//---------------------------------------------------------	

void SelectionSort (){
	int tmp;
	system ("cls");
	for (int x=0;x<19;x++){
		for(int y=x+1;y<20;y++){ // Um laço bem simples de comparação, troca os numeros de lugar caso a condicao seja verdadeira.
			if (v1[y]<v1[x]){
				tmp=v1[x];
				v1[x]=v1[y];
				v1[y]=tmp;
			}
		}
	}
	printf("Numeros em ordem: \n\n");
	for (int x = 0; x < 20; x++) { //Mostrando todo o conteudo do vetor
        printf("[%d]\n", v1[x]);
    }
	printf("\nPressione ENTER para retornar ao menu... \n");
	getchar();
	getchar();
}
	

//---------------------------------------------------------

void BubbleSort(){
	int tmp;
	system("cls");
	for(int x=0;x<19;x++){// Bubble sort compara de dois em dois, jogando os maiores valores para baixo.
		for(int y=0;y<20-x-1;y++){
			if(v1[y]>v1[y+1]){
				tmp=v1[y];
				v1[y]=v1[y+1];
				v1[y+1]=tmp;
			}
		}
	}
	printf("Numeros em ordem: \n\n");
	for (int x = 0; x < 20; x++) {
        printf("[%d]\n", v1[x]);
    }
	printf("\nPressione ENTER para retornar ao menu... \n");
	getchar();
	getchar();
}

//---------------------------------------------------------	
void InsertionSort(){
	int tmp;
	system("cls");
	for(int x=1;x<20;x++){
		int y=x;
		while(y > 0 && v1[y] < v1[y-1]){ // A insercao faz comparaçoes de dois a dois e vai ordenando o vetor inteiro, o percorrendo apenas uma vez.
			tmp=v1[y];
			v1[y]=v1[y-1];
			v1[y-1]=tmp;
			y--;
		}
	}
	printf("Numeros em ordem: \n\n");
	for (int x = 0; x < 20; x++) {
        printf("[%d]\n", v1[x]);
    }
	printf("\nPressione ENTER para retornar ao menu... \n");
	getchar();
	getchar();
}
//---------------------------------------------------------	

int main(){
	char escolha; //Auto explicativo
	srand(time(NULL));//Usado para sempre reiniciar os numeros gerados!
	
	do{// Permite a repeticao da chamada do menu
		system ("cls");//famoso limpatela
		escolha=Menu(escolha);
		switch (escolha){//Determinando que procedimento sera acessado
			case '0':
				printf("Ate mais!");
				break;
			case '1':
				GerarNumeros();
				break;
			case '2':
				SelectionSort();
				break;
			case '3':
				BubbleSort();
				break;	
			case '4':
				InsertionSort();
		}
	}while (escolha!='0');

}


char Menu(char a){ //Fica mais pratico quando é uma função!!
	printf("  Menu\nO que deseja escolher?\n\n1 - Gerar numeros (Precisa ser acessado primeiro!)\n2 - Selection Sort\n3 - Bubble Sort\n4 - Insertion Sort\n0 - Finalizar programa\nEscolha: ");
	scanf(" %c", &a);
	return a;
}
