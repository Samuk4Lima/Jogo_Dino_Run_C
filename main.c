#include <windows.h>// Biblioteca dos c�digos do cmd
#include <stdio.h> // Biblioteca de entrada e sa�da de dados
#include <stdlib.h>// Biblioteca de convers�o das strings
#include <time.h>// biblioteca de manipula��o de periodos
#include <locale.h> // Biblioteca de acentua��o de caracteres
#include <conio.h>// Biblioteca de manipula��o de caracteres
#include "Funcoes.h"

//declarando variaveis globais para a inicalizaca das coordenadas do Dino
int dinoX=10, dinoY=15;
int cactoX=70, cactoY=18;
float p;
int a=1;

//funcao que determina a posicao do dino no console
void printdino(int a)
{
    gotoxy1(dinoX,dinoY-1);
    printf("           ^ ^      ");
    gotoxy1(dinoX,dinoY);
    printf("          |o-o|     ");
    gotoxy1(dinoX,dinoY+1);
    printf("         /(*\\_/*)  ");
    gotoxy1(dinoX,dinoY+2);
    printf(" .^^^^.-- /'-'    ");
    gotoxy1(dinoX,dinoY+3);
    printf("  `-._. )/'    ");
    gotoxy1(dinoX,dinoY+4);

    if(a==1)
    {
        gotoxy1(dinoX,dinoY+4);
        printf("      \\\\/  ");
        gotoxy1(dinoX,dinoY+5);
        printf("       ''  ");
    }
    else
    {
        gotoxy1(dinoX,dinoY+4);;
        printf("     // \\\\ ");
        gotoxy1(dinoX,dinoY+5);
        printf("     |_  |_");
    }

    if(dinoY!=15)
    {
        gotoxy1(dinoX,dinoY+6);
        printf("                 ");
    }
}

// funcao que determina o movimento do cacto
void printcacto(int cac)
{

    gotoxy1(cactoX,cactoY-1);
    printf("   ##  ");
    gotoxy1(cactoX,cactoY+0);
    printf("   ## ");
    gotoxy1(cactoX,cactoY+1);
    printf("   ## ");
    gotoxy1(cactoX,cactoY+2);
    printf("   ## ");
    gotoxy1(cactoX,cactoY+3);

}







int main()
{

    //menu
    int a=0;

    system("color 02");
    printf("Dicas: Precione a tecla ESC a qualquer momento para voltar para o menu principal!\nUse as setas para navegar pelo menu.\n\n");
    printf("      1 - JOGAR\n");
    printf("      2 - CREDITOS\n");
    printf("      3 - SAIR\n");


    printf("\n\n\n\n                ======     []    ||\\\\    ||  ======== \n");
    printf("                ||    \\\\         || \\\\   ||  ||    || \n");
    printf("                ||    ||   ||    ||  \\\\  ||  ||    || \n");
    printf("                ||    //   ||    ||   \\\\ ||  ||    || \n");
    printf("                ======     ||    ||    \\\\||  ======== \n\n");

    printf("                =======    ||   ||    ||\\\\    || \n");
    printf("                ||    ||   ||   ||    || \\\\   || \n");
    printf("                ||=====    ||   ||    ||  \\\\  || \n");
    printf("                ||    \\\\   ||   ||    ||   \\\\ || \n");
    printf("                ||     \\\\   =====     ||    \\\\||  \n");

    scanf("%d", &a);

    //opcao inicializando
    switch(a)
    {

    //inicializando o jogo
    case 1:
        system("cls");
        system("color F");
        printf("Pressione W para pular");
        gotoxy1(1,dinoY+6);
        printf("================================================================================");
        printf("\n====      ================   ========    ===========    =====================   ");
        printf("\n ==         =============      =====       ========        ====    ========     ");
        printf("\n              ==     ===        ==           ===            ==       ====       ");
        float tempo=1.5;
        int movimento=0, contagem=0, morreu=0;

        do
        {
            gotoxy1(80,5);
            printf("|%i|", contagem);
            for(movimento=1; movimento<=70; movimento++)
            {
                if(!kbhit())
                {
                    printdino(1);
                    delay(tempo/40);
                    printdino(2);
                    delay(tempo/40);
                    cactoX-=1;
                    printcacto(1);
                    gotoxy1(80,5);
                    if((cactoX<20) && (dinoY > 14))
                    {
                        morreu++;
                    }
                }
                else if(getch()=='w')
                {
                    int subida;

                    for(subida=1; subida<=13; subida++)
                    {
                        dinoY-=1;
                        printdino(2);
                        delay( tempo/20.0  );
                        printdino(2);
                        cactoX-=1;
                        printcacto(1);
                        movimento++;
                        gotoxy1(80,5);
                    }

                    for(subida=1; subida<=13; subida++)
                    {
                        dinoY+=1;
                        printdino(2);
                        delay( tempo/20.0);
                        printdino(2);
                        cactoX-=1;
                        printcacto(1);
                        movimento++;
                        gotoxy1(80,5);
                    }
                    dinoY=15;
                }
            }
            cactoX=70;
            contagem++;
            system("cls");
            gotoxy1(1,dinoY+6);
            printf("================================================================================");
            printf("\n====      ================   ========    ===========    =====================   ");
            printf("\n ==         =============      =====       ========        ====    ========     ");
            printf("\n              ==     ===        ==           ===            ==       ====       ");
            if(tempo>0.2)
            {
                tempo=tempo-0.03;
            }
        }
        while(morreu<=0);
        system("cls");
        printf("Pontuacao = %i\nVoce perdeu!\n", contagem);
        break;

    //creditos da equipe
    case 2:

        system("cls");
        system("color 1");
        printf("Equipe:\n\n1-Samuel Lima\n2-Eric Albuquerque\n3-Matheus Souza\n4-Joao Gabriel Gila\n\n");

        break;

    //op�ao de saida do console
    case 3:
        system("cls");
        system("color 4");
        printf("Voce pediu para sair, fechando programa...");
        for(a=0; a<10; a++)
        {
            printf(".");
            Sleep(250);
        }

        break;

    default:
        system("cls");
        printf("Voc� deve escolher uma op��o v�lida\n");

        break;

    }

    return 0;

}







