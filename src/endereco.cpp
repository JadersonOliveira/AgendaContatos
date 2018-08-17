#include "endereco.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

endereco::endereco()
{
    //ctor
}

endereco::~endereco()
{
    //dtor
}

void endereco::getdata()
{
    cout<<"Digite Rua: ";
    cin.getline(rua,50);

    cout<<"Digite Bairro: ";
    cin.getline(bairro,50);

    cout<<"Digite Cidade: ";
    cin.getline(cidade,50);

    cout<<"Digite Estado: ";
    cin.getline(estado,50);

    cout<<"Digite Numero: ";
    cin.getline(numero,10);

    cout<<"Digite CEP: ";
    cin.getline(cep,15);
}

void endereco::putdata()
{
    cout<<"Rua: "<<rua<<endl;
    cout<<"Bairro: "<<bairro<<endl;
    cout<<"Cidade: "<<cidade<<endl;
    cout<<"Estado: "<<estado<<endl;
    cout<<"Numero: "<<numero<<endl;
    cout<<"CEP: "<<cep<<endl;
}
