#include "telefone.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

telefone::telefone()
{
    //ctor
}

telefone::~telefone()
{
    //dtor
}

void telefone::getdata()
{
    cout<<"Digite Numero Telefonico: ";
    cin.getline(numero,20);

    cout<<"Digite Operadora Telefonica: ";
    cin.getline(operadora,10);
}

void telefone::putdata()
{
    cout<<"Numero Telefonico: "<<numero<<endl;
    cout<<"Operadora Telefonica: "<<operadora<<endl;
}
