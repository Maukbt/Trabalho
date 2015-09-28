#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int *v,*u,size,i,j=0,menor,op;

void quick(int *v,int first,int last){
    int pivo,aux;
	
	if(first<last){
        pivo=first;
        i=first;
        j=last;
		
	while(i<j){ 
            while(v[i]<=v[pivo]&&i<last)
                i++;
            while(v[j]>v[pivo])
                j--;
            if(i<j){ //realiza a troca dos valores com variavel temporal auxiliar
            	aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
        }
		aux=v[pivo]; //realiza a troca do pivo
        v[pivo]=v[j];
        v[j]=aux;
        quick(v,first,j-1); //ordenação dos subvetores restantes
       	quick(v,j+1,last);

    }
}


void closestpair(int size){
	quick(v,0,size-1);
	i=1;
	menor=INT_MAX;
	while(i<size){//algoritmo de verificação do par mais próximo(closest pair)
		if(menor>(v[i]-v[i-1])){//realiza a diferença e compara com a salva anterior, caso for menor, ela irá substituir a anterior
			menor=v[i]-v[i-1];
			j=i;
		}
		i++;
	}
	printf("\nO par (%d) e (%d) possuem menor diferenca de valor =%d", v[j-1],v[j],menor); 
}


void eleuni(int size){
	i=0;
	printf("\nNumero unicos no vetor:");
	while(i<size){//algoritmo de verificação da unicidade do elemento no vetor

		if(v[i]!=v[i+1]&&v[i]!=v[i-1])//compara se é diferente dos vetor à esquerda e à direita
			printf("\n%d", v[i]);
		i++;	
	}
}


void fredis(int size)
{ 
int j=0,cont = 0,atual = 1,freq = 0,key = 0;
	i=0;
	while(i<size){//verifica se todos os elementos são diferentes
		if(v[i]!=v[i+1]&&v[i]!=v[i-1])
			j++;
		i++;	
	}
	if(j==size){//caso eles forem, será imprimido todos - pois tem a mesma frequência
		printf("Numeros com maior frequencia no vetor:");
		for (i=0;i<size;i++) printf("\n%d",v[i]);
		return 0;
	}
	//caso existir pelo menos um elemento repitido ele entra no loop abaixo
	for(i = 0; i < size-1; i++){//verifica e salva o primeiro elemento que tem maior frequência no vetor
    	key = v[i];
    	for(j =i+1; j < size; j++){
        	if(key == v[j] && freq != key)
        	{
            	atual++;
        	}
    	}
    	if(cont < atual){
        	cont = atual;
        	atual = 1;
        	freq = key;
    	}
	}
printf("Primeiro elemento com mais frequencia: %d", freq);
}


int main(){
	
	printf("Qual verificacao deseja aplicar ao vetor?\n\n1-Closest Pair\n2-Element uniqueness\n3-Frequency distribution\n");
	scanf("%d",&op);
	
	while(op<1 || op>3){//teste de consistência para entrada das opções (1 a 3)
		printf("Opção invalida. Digite novamente");
		scanf("%d",&op);
	}
	
  	printf("Entre com um tamanho inteiro do vetor: ");
  	scanf("%d",&size);
  	
  	while(size<=1){//teste de consistência para as entradas (maior que 1)
  		printf("\nEntre com um tamanho maior que 1:");
		scanf("%d",&size);  	
	}
  	
  	v = (int *)malloc(sizeof(int)*size);//aloca dinamicamente espaço de memória para o tamanho do vetor entrado
	
  	printf("\nEntre com %d inteiros:\n",size);
  	
  	for(i=0;i<size;i++) scanf("%d",&v[i]);//leitura do vetor
	
  	quick(v,0,size-1);
  	
	if(op==1) closestpair(size);//opções apresentadas no menu do programa
	if(op==2) eleuni(size);
	if(op==3) fredis(size);
	
	free(v);
    	return 0;
}
