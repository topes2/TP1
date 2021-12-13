#include <stdio.h>
int maiorvalor(int v[],int sz){
    int i;
    int comparador=0;

    for ( i = 0; i < sz; i++)
    {
        if (comparador<v[i])
        {
            comparador=v[i];
        }
        
    }
    return comparador;

}
int contareperidos(int v[],int sz,int num){
    int i,e=0,contador=0;
    int repeticoes[20];
    
    for ( i = 0; i < sz; i++)
    {
       if (v[i] == num)
       {
        contador++;         
       }
       else
       {
        repeticoes[e]=contador;
        e++;
        contador=0;
        }
    }
    return maiorvalor(repeticoes,e);
}
int main(){
    int v[20];
    int i;
    int num;

    printf("escreva o a sequência acabando com um número negativo");
    for ( i = 0; i < 20; i++)
    {
        scanf("%d",&v[i]);
        if(v[i]<0)
        break;
    }
    printf("Qual o número que quer vereficar a repetição? ");
    scanf("%d",&num);
    printf("%d \n",contareperidos(v,20,num));

}