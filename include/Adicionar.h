#ifndef ADICIONAR_H
#define ADICIONAR_H
#include <cadastro.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

class Adicionar: private cadastro
{
    public:
        Adicionar();
        void adicionarcontato();
        virtual ~Adicionar();

    protected:

    private:
};

#endif // ADICIONAR_H
