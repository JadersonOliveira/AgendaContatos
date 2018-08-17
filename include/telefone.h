#ifndef TELEFONE_H
#define TELEFONE_H

class telefone
{
     private:
        char numero[20];
        char operadora[10];
    public:
        telefone();
        void getdata();
        void putdata();
        virtual ~telefone();

};

#endif // TELEFONE_H
