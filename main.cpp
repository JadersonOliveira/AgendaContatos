#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <cadastro.h>
#include <string.h>
#include <vector>
#include <conio.h>
#include <string.h>
using namespace std;

void espaco(int coluna, int linha)
{
        COORD point;
        point.X = coluna;
        point.Y = linha;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

void Moldura ( ) {

     int c, l;

     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // ADICIONAR A COR ESCOLHIDA
     for ( c = 3; c <= 78 ; c++ ) {
         espaco ( c , 1 );
         printf ( "%c" , 205 );
         espaco ( c , 4 );
         printf ( "%c" , 205 );
     }
     espaco ( 2 , 1 );
     printf ( "%c" , 201 );
     espaco ( 79 , 1 );
     printf ( "%c" , 187 );
     espaco ( 79 , 4 );
     printf ( "%c" , 188 );
     espaco ( 2 , 4 );
     printf ( "%c" , 200 );
     for ( l = 2; l <= 3 ; l++ ) {
         espaco ( 2 , l );
         printf ( "%c" , 186 );
         espaco ( 79 , l );
         printf ( "%c" , 186 );
     }
 for ( c = 3; c <= 78 ; c++ ) {
         for ( l = 3; l <= 3 ; l++ ) {
              espaco ( c , l );
              printf ( "%c" , 176 );
         }
     }
     for ( c = 3; c <= 78 ; c++ ) {
         espaco ( c , 5 );
         printf ( "%c" , 205 );
         espaco ( c , 25 );
         printf ( "%c" , 205 );
     }
     espaco ( 2 , 5 );
     printf ( "%c" , 201 );
     espaco ( 79 , 5 );
     printf ( "%c" , 187 );
     espaco ( 79 , 25 );
     printf ( "%c" , 188 );
     espaco ( 2 , 25 );
     printf ( "%c" , 200 );
     espaco ( 2 , 8 );
     printf ( "%c" , 204 );
     espaco ( 79 , 8 );
     printf ( "%c" , 185 );
     for ( l = 9; l <= 24 ; l++ ) {
         espaco ( 2 , l );
         printf ( "%c" , 186 );
         espaco ( 79 , l );
         printf ( "%c" , 186 );
     }
     for ( l = 6; l <= 7 ; l++ ) {
         espaco ( 2 , l );
         printf ( "%c" , 186 );
         espaco ( 79 , l );
         printf ( "%c" , 186 );
     }
     for ( c = 3; c <= 78 ; c++ ) {
         espaco ( c , 8 );
         printf ( "%c" , 205 );
     }
     for ( c = 5; c <= 25 ; c++ ) {
         espaco ( c + 25 , 9 );
         printf ( "%c" , 205 );
         espaco ( c + 25 , 24 );
         printf ( "%c" , 205 );
     }
     espaco ( 29 , 9 );
     printf ( "%c" , 201 );
     espaco ( 51 , 9 );
     printf ( "%c" , 187 );
     espaco ( 51 , 24 );
     printf ( "%c" , 188 );
     espaco ( 29 , 24 );
     printf ( "%c" , 200 );
     for ( l = 10; l <= 23 ; l++ ) {
         espaco ( 29 , l );
         printf ( "%c" , 186 );
         espaco ( 51 , l );
         printf ( "%c" , 186 );
     }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}

int main()
{
    FILE *arquivo; // CRIA UM OBJETO CHAMADO ARQUIVO DO TIPO FILE, PARA ARMAZENAR OS DADOS

    int op;
    char nome1[50];
    char cpf1[15];
    int veri=0;
    int n=0;
    cadastro contato;

    do{
            //ABRINDO O ARQUIVO DIRETO DO SEU DIRETÓRIO
            arquivo=fopen ("armazenadoragenda.txt","a+");

        do{
            system("cls");

            Moldura();
            espaco ( 32 , 2.5 );
            cout<<"AGENDA DE CONTATOS";
            espaco ( 38 , 7 );
            cout<<"MENU";

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); // ADICIONAR A COR ESCOLHIDA

            espaco ( 31 , 12 );
            cout<< "1 - INSERIR";
            espaco ( 31 , 13 );
            cout<< "2 - LISTAR";
            espaco ( 31 , 14 );
            cout<< "3 - MODIFICAR";
            espaco ( 31 , 15 );
            cout<< "4 - BUSCAR POR NOME";
            espaco ( 31 , 16 );
            cout<< "5 - BUSCAR POR CPF";
            espaco ( 31 , 17 );
            cout<< "6 - EXCLUIR";
            espaco ( 31 , 18 );
            cout<< "7 - SAIR" ;
            espaco ( 31 , 20 );
            cout<< "-> OPCAO: ";
            cin>>op;

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

            espaco(26,26); //CRIA UMA Moldura

         }while(op<0 || op>7);
            if(op==1){

                system("cls");
                // CHAMANDO O OBJETO DA CLASSE E SUA FUNÇÃO
                cout<<"***************  CADASTRE OS DADOS ***************\n\n";
                contato.adicionar();
                cout<<"\n********* CONTATO CADASTRADO COM SUCESSO! *********\n\n";
                n++;
                // GRAVANDO NO ARQUIVO
                fwrite (&contato,sizeof(cadastro),1,arquivo);

                //FECHANDO ARQUIVO
                fclose(arquivo);
                system("pause");

            }else if(op==2){

                system("cls");

                //LENDO ARQUIVO
                fread(&contato,sizeof(cadastro),1,arquivo);
                //ENQUANTO O FIM NAO SEJA ENCONTRADO
                while(!feof(arquivo))
                {
                    contato.listar(); //listar OS DADOS
                    fread(&contato,sizeof(cadastro),1,arquivo); //LENDO OS DADOS SALVOS NOS ARQUIVOS
                }
                //FECHANDO O ARQUIVO
                fclose(arquivo);
                cout<<"\n";
                system("pause");

            }else if(op==3){

                system("cls");

                FILE *tmp; //CRIANDO ARQUIVO TEMPORARIO

                cout<<"Nome do Cadastrado: ";
                cin>>nome1;

                 //LENDO ARQUIVO
                fread(&contato,sizeof(cadastro),1,arquivo);

                //ARQUIVO TEMPORARIO RECEBENDO O ARQUIVO DEFINITIVO
                tmp = fopen("armazenador2agenda.txt","a+");

                //ENQUANTO O FIM NAO SEJA ENCONTRADO
                while(!feof(arquivo))
                {
                    char nometemp[50];
                    contato.buscarnome(nometemp);
                    n++;

                    if(strcmp(nometemp,nome1) != 0){ // VERIFICA SE O NOME DIGITADO E DIFERENTE DE ALGUM NOME DO BANCO DE DADOS

                        fwrite(&contato,sizeof(cadastro),1,tmp);//SE O NOME DIGITADO FOR DIFERENTE DO NOME NO BANCO DE DADOS, ESCREVE TUDO NO ARQUIVO TEMPORARIO
                        veri++;
                    }
                    if(strcmp(nometemp,nome1) == 0){

                        system("cls");
                        cout<<"            DIGITE OS NOVOS DADOS"<<endl<<endl;
                        // CHAMANDO O OBJETO DA CLASSE E SUA FUNÇÃO
                        contato.adicionar();

                        cout<<"\n********* CONTATO MODIFICADO COM SUCESSO! *********\n\n";
                        // GRAVANDO NO ARQUIVO
                        fwrite (&contato,sizeof(cadastro),1,tmp);

                    }

                    // LENDO DADOS DOS ARQUIVOS
                    fread(&contato,sizeof(cadastro),1,arquivo);

                }

                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // ADICIONAR A COR ESCOLHIDA
                if(veri==n){
                    cout<<endl<<"NOME NAO ENCONTRADO!!!"<<endl<<endl;;
                }
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

                fclose(arquivo);
                fclose(tmp);
                system("del armazenadoragenda.txt"); //DELETA O ARQUIVO DEFINITIVO
                system("ren armazenador2agenda.txt armazenadoragenda.txt");//CRIA UM NOVO ARQUIVO DEFINITIVO COM OS DADOS SALVOS NO TEMPORARIO

                veri=0;
                n=0;
                system("pause");

            }else if(op==4){

                system("cls");
                cout<<"Digite nome procurado: ";
                cin>>nome1;


                 //LENDO ARQUIVO
                fread(&contato,sizeof(cadastro),1,arquivo);

                //ENQUANTO O FIM NAO SEJA ENCONTRADO
                while(!feof(arquivo))
                {
                    char nometemp[50];
                    contato.buscarnome(nometemp);
                    n++;


                    if (strcmp(nometemp,nome1) == 0) // VERIFICA SE O NOME DIGITADO E IGUAL A ALGUM NOME DO BANCO DE DADOS
                    {
                        system("cls");
                        contato.listar(); // IMPRIMI A LISTA DE CADASTRADOS
                        veri++;
                        break;
                    }else{
                        system("cls");

                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // ADICIONAR A COR ESCOLHIDA
                        cout<<endl<<"NOME NAO ENCONTRADO!"<<endl<<endl;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

                    }

                    fread(&contato,sizeof(cadastro),1,arquivo);
                }

                //FECHANDO O ARQUIVO
                fclose(arquivo);

                system("pause");

            }else if(op==5){

                system("cls");
                cout<<"Digite CPF procurado: ";
                cin>>cpf1;

                 //LENDO ARQUIVO
                fread(&contato,sizeof(cadastro),1,arquivo);

                //ENQUANTO O FIM NAO SEJA ENCONTRADO
                while(!feof(arquivo))
                {
                    char cpftemp[15];
                    contato.buscarcpf(cpftemp);

                    if (strcmp(cpftemp,cpf1) == 0) // VERIFICA SE O NOME DIGITADO E IGUAL A ALGUM NOME DO BANCO DE DADOS
                    {
                        system("cls");
                        contato.listar(); // IMPRIMI A LISTA DE CADASTRADOS
                        break;
                    }else{
                        system("cls");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // ADICIONAR A COR ESCOLHIDA
                        cout<<endl<<endl<<"CPF NAO ENCONTRADO!"<<endl<<endl;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
                    }
                    fread(&contato,sizeof(cadastro),1,arquivo);
                }
                //FECHANDO O ARQUIVO
                fclose(arquivo);

                system("pause");

            }else if(op==6){

                system("cls");

                FILE *tmp; //CRIANDO ARQUIVO TEMPORARIO

                cout<<"Digite nome: ";
                cin>>nome1;

                 //LENDO ARQUIVO
                fread(&contato,sizeof(cadastro),1,arquivo);

                //ARQUIVO TEMPORARIO RECEBENDO O ARQUIVO DEFINITIVO
                tmp = fopen("armazenador2agenda.txt","a+");

                //ENQUANTO O FIM NAO SEJA ENCONTRADO
                while(!feof(arquivo))
                {
                      char nometemp[50];
                      contato.buscarnome(nometemp);

                      if (strcmp(nometemp,nome1) != 0) // VERIFICA SE O NOME DIGITADO E DIFERENTE DE ALGUM NOME DO BANCO DE DADOS
                        {
                            fwrite(&contato,sizeof(cadastro),1,tmp);//SE O NOME DIGITADO FOR DIFERENTE DO NOME NO BANCO DE DADOS, ESCREVE TUDO NO ARQUIVO TEMPORARIO
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // ADICIONAR A COR ESCOLHIDA
                            cout<<endl<<"CONTATO REMOVIDO COM SUCESSO!!!"<<endl<<endl;
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
                            break;
                        }else {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // ADICIONAR A COR ESCOLHIDA
                            cout<<endl<<"CONTATO REMOVIDO COM SUCESSO!!!"<<endl<<endl;
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
                            system("pause");
                    }

                    // LENDO DADOS DOS ARQUIVOS
                    fread(&contato,sizeof(cadastro),1,arquivo);

                }

                fclose(arquivo);
                fclose(tmp);
                system("del armazenadoragenda.txt"); //DELETA O ARQUIVO DEFINITIVO
                system("ren armazenador2agenda.txt armazenadoragenda.txt");//CRIA UM NOVO ARQUIVO DEFINITIVO COM OS DADOS SALVOS NO TEMPORARIO

                system("pause");
            }

    }while(op!=7);


}
