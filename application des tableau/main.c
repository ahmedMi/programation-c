#include <stdio.h>
#include <stdlib.h>

void remplire_tk(int tk[],int n);
void affiche_tk(int tk[],int n);
float affiche_mmm(int tk[],int n);
void affiche_p(int tk[],int n,float moy);
void remplir_tkn(int tk[],int n,int tkn[]);
void rech_affiche(int tk[],int n);

int main()
{
    int tk[20];
    int tkn[20];
    int n=5;
    float moy;

   do{
       printf("\n********introduire le numero des voiture*************:\n");
       scanf("%d",&n);
     }while((n<=0)||(n>20));

     printf("\n*********************************************************\n");
     remplire_tk(tk,n);

     printf("\n*********************************************************\n");
     affiche_tk(tk,n);

     printf("\n*********************************************************\n");
     moy=affiche_mmm(tk,n);

     printf("\n*********************************************************\n");
     affiche_p(tk,n,moy);
    remplir_tkn(tk,n,tkn);
    rech_affiche(tk,n);



    return 0;
}


void remplire_tk(int tk[],int n)
{
    int i;
   for (i=0;i<n;i++){
       do{
           printf("\n******************introduire le kilometrage des voiture**************:\n");
           scanf("%d",&tk[i]);

       }while(tk[i]<10000);
   }
}

void affiche_tk(int tk[],int n)
{
    int i;
    printf("-----------------\n");
    for(i=0;i<n;i++){
        printf("les kilometrage des voiture **%d** :%d\n",i+1,tk[i]);
    }
}

float affiche_mmm(int tk[],int n)
{
    int max=0;
    int min;
    float moy;
    int i,somme=0;

    for(i=0;i<n;i++)
    {
        if (max<tk[i])
            {
            max=tk[i];
            }
        if (min>tk[i])
            {
            min=tk[i];
            }
        somme=somme+tk[i];

    }
    moy=somme/n;
     printf("\n*****le maximum et :%d\n",max);
     printf("\n*****le minimum et :%d\n",min);
     printf("\n*****le moy et :%f\n",moy);
     return(moy);

}

void affiche_p(int tk[],int n,float moy)
{
    int i;
    float p=0;
    int x=0;
    int somme=0;
    float s1=0;
    for(i=0;i<n;i++)
    {
        somme=somme+tk[i];

        if (tk[i]>moy)
            {
            x=x+tk[i];
            }
    }

    s1=x*100;
    p=s1/somme;
    printf("le pourcentage des voiture qui sercule plus que la moyenne est:\n%f\n\n",p);
}


void remplir_tkn(int tk[],int n,int tkn[])
{
    int i=0;
    for(i=0;i<n;i++){

        tkn[i]=tk[i]/10000;
        printf("le tableau 2 : %d\n",tkn[i]);
    }
}

void rech_affiche(int tk[],int n)
{
    int a=0;
    int trv[20];
    int min;
    int minp=0;
    int i;
    for(i=0;i<n;i++)
     {   a=0;
         printf("\n*********************************************\n");
         a=tk[i]%10000;
         trv[i]=10000-a;
         printf("\nle reste des kilometre c'est par la voiture %d:\n%d",i+1,trv[i]);
     }
     min=trv[0];
     for(i=1;i<n;i++)
     {

          if (trv[i]<min){
                min=trv[i];
                minp=i;
         }
     }
      printf("\n*********************************************\n");
      printf("\n\nla voiture numero:%d a parcourue: %d km est reste :%dkm",minp,tk[minp],min);

}
