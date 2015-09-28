#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int *v,*u,size,i,j=0,menor,m,valor,op;
void quick(int *v,int first,int last){
    int pivo,j,aux,i;
	
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
		if(menor>(v[i]-v[i-1])){
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

		if(v[i]!=v[i+1]&&v[i]!=v[i-1])
			printf("\n%d", v[i]);
		i++;	
	}
}

void fredis(int size){
	j=0;
	i=0;
	u = (int *)malloc(sizeof(int)*(size/2));
	while(i<size){//algoritmo de verificação da unicidade do elemento no vetor
		if(v[i]==v[i+1]){
			if(v[i]!=u[j-1]){
				u[j]=v[i];
				j++;
			}
		}
		i++;	
	}
	printf("Numeros com maior frequencia no vetor:");
	for(i=0;i<j;i++)
		printf("\n%d ",u[i]);
}
int main(){
	
	printf("Qual verificacao deseja aplicar ao vetor?\n\n1-Closest Pair\n2-Element uniqueness\n3-Frequency distribution\n");
	scanf("%d",&op);
	
	while(op<1 || op>3){
		printf("Opção invalida. Digite novamente");
		scanf("%d",&op);
	}
	
  	printf("Entre com um tamanho inteiro do vetor: ");
  	scanf("%d",&size);
  	
  	while(size<=1){
  		printf("\nEntre com um tamanho maior que 1:");
		scanf("%d",&size);  	
	}
  	
  	v = (int *)malloc(sizeof(int)*size);//aloca dinamicamente espaço de memória para o tamanho do vetor entrado
	
  	printf("\nEntre com %d inteiros:\n",size);
  	for(i=0;i<size;i++)
    scanf("%d",&v[i]);

  	quick(v,0,size-1);
  	
	if(op==1) closestpair(size);
	if(op==2) eleuni(size);
	if(op==3) fredis(size);
	free(v);
    return 0;
}
