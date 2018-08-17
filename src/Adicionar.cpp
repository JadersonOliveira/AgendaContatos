#include "Adicionar.h"
#include <cadastro.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

Adicionar::Adicionar()
{
    //ctor
}

Adicionar::~Adicionar()
{
    //dtor
}
void Adicionar::adicionarcontato()
{
     FILE *arquivo;
  // cadastro contato;

    char nome2[20];

    arquivo = fopen("testeagenda.txt","a");
    if (arquivo == NULL)
    {
        cout<<"Erro ao abrir arquivo\n";
        return;
    }

    cout<<"\n\n";
   // printf("Digite o nome: ");
   // fflush(stdin);
   // gets(nome);

 //   if (verifica(nome) == 1)
  //  {

  //      printf("\nNome ja existe.\n");
  //  }
   // else
   // {
     //   fflush(stdin);
     //   strcpy(nome,nome2);
    //    printf("Digite o telefone: ");
     //   scanf("%d", &contato.telefone);
        fwrite(&cadastro::getdata(),sizeof(cadastro::getdata()),1,arquivo);

    fclose(arquivo);
}
