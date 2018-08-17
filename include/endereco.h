#ifndef ENDERECO_H
#define ENDERECO_H

class endereco
{
    private:
        char rua[50];
        char bairro[50];
        char cidade[50];
        char estado[50];
        char numero[10];
        char cep[15];
    public:
        endereco();
        void getdata();
        void putdata();
        virtual ~endereco();

};

#endif // ENDERECO_H
