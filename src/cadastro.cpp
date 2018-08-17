#include "cadastro.h"
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

cadastro::cadastro()
{
    //ctor
}

cadastro::~cadastro()
{
    //dtor
}

void cadastro::adicionar()
{
    cin.ignore();

    cout<<"Digite Nome: ";
    cin.getline(nome,50);

    cout<<"Digite Email: ";
    cin.getline(email,50);

    cout<<"Digite Profissao: ";
    cin.getline(profissao,40);

    cout<<"Digite Idade: ";
    cin.getline(idade,5);

    cout<<"Digite CPF: ";
    cin.getline(cpf,15);

    cout<<"Digite RG: ";
    cin.getline(rg, 15);
    endereco::getdata();
    telefone::getdata();

}

void cadastro::listar()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); // ADICIONAR A COR ESCOLHIDA

    cout<<"***************************************";
    cout<<"\nNome: "<<nome<<endl;
    cout<<"Email: "<<email<<endl;
    cout<<"Profissao: "<<profissao<<endl;
    cout<<"Idade: "<<idade<<endl;
    cout<<"CPF: "<<cpf<<endl;
    cout<<"RG: "<<rg<<endl;
    endereco::putdata();
    telefone::putdata();

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

}

void cadastro::buscarnome(char nometemp[])
{
    strcpy(nometemp,nome);
}

void cadastro::buscarcpf(char cpftemp[])
{
    strcpy(cpftemp,cpf);
}
