#ifndef CADASTRO_H
#define CADASTRO_H
#include <telefone.h>
#include <stdio.h>
#include <endereco.h>
#include <verificar.h>


class cadastro: private telefone, private endereco
{
    private:
        char email[50];
        char profissao[40];
        char idade[5];
        char rg[20];
        char nome[50];
        char cpf[15];

    public:
        cadastro();
        void adicionar();
        void listar();
        void buscarnome(char nometemp[]);
        void buscarcpf(char cpftemp[]);
        virtual ~cadastro();
};

#endif // CADASTRO_H
