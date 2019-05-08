#include "data.h"

alberghi *inizializza(alberghi *p)
{
    alberghi *p2=NULL;
    FILE *f=fopen("alberghi.txt","r");
    char v[150];

    while(!feof(f))
    {
       p=fgets(v,50,f);

    if(!feof(f))
    {
        p2=(alberghi*)malloc(sizeof(alberghi));
        p2->next=p;
    }
    else
    {
        p=(alberghi*)malloc(sizeof(alberghi));
        p->next=NULL;
        p2=p;
    }

          printf("%s \n",v);
       }
       fflush(f);
       fclose(f);

       return p;
    }


alberghi *inserisci(alberghi *p)
{
    char nome[MAX];
    char stelle[MAX];
    char numero[MAX];
    char servizio[MAX];
    info da_agg;
    alberghi *p2=NULL;

    printf("Inserisci le info dell'albergo\n");
    printf("Inserisci nome\n");
    scanf("%s",nome);
    strcpy(da_agg.nome, nome);
    printf("Inserisci stelle\n");
    scanf("%s", stelle);
    strcpy(da_agg.stelle, stelle);
    printf("Inserisci numero\n");
    scanf("%s", numero);
    strcpy(da_agg.numero, numero);
    printf("Inserisci elenco\n");
    scanf("%s",servizio);
    strcpy(da_agg.servizio, servizio);

    if(p!=NULL)
    {
        p2=(alberghi*)malloc(sizeof(alberghi));
        p2->albergo=da_agg;
        p2->next=p;
    }
    else
    {
        p=(alberghi*)malloc(sizeof(alberghi));
        p->next=NULL;
        p2=p;
    }
    return p2;
}

alberghi *stampa_s(alberghi *p)
{
    char servizio[50];
    alberghi *p2;

    printf("Inserisci il servizio che vuoi ricercare\n");
    scanf("%s", servizio);

    while(p!=NULL)
    {
        if(strcmp(p2->albergo.servizio,servizio)==0)
        {
            printf("%s",p->albergo.nome);
            p=p->next;
            p2=p;
        }
        else
        {
            p=p->next;
            p2=p;
        }
    }
    return p2;

}

alberghi *stampa_s_s(alberghi *p)
{
    char servizio[50];
    char stelle[10];
    alberghi *p2;

    printf("inserisci il servizio\n");
    scanf("%s", servizio);
    printf("inserisci il numero di stelle\n");
    scanf("%s", stelle);

    while(p!=NULL)
    {
        if(strcmp(p2->albergo.servizio==servizio) && strcmp(p2->albergo.stelle==stelle))
        {
            printf("%s",p->albergo);
            p=p->next;
            p2=p;
        }
        else
        {
            p=p->next;
            p2=p;
        }

    }
    return p2;
}

void salva(alberghi *p)
{
    FILE *f=fopen("archivio.txt","a");

    while(p!=NULL)
    {
        fprintf(f,"%s/t%s\t%s\t%s\n",p->albergo.nome,p->albergo.stelle,p->albergo.numero,p->albergo.servizio);
        p=p->next;
    }
    fflush(f);
    fclose(f);

    return;
}
void printLista(alberghi *p){
  if(p==NULL){
    printf("Lista vuota.\n");
  } else {
    while(p!=NULL){
      printf("%s,%s,%s,%s\n",p->albergo, p->albergo.stelle, p->albergo.numero, p->albergo.servizio);
      p = p->next;
    }
}
}


