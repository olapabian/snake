#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
int szerokosc;
int wysokosc;
int szybkosc;
int gora,dol,lewo,prawo;
char pole[35][35];
int wspolzednaXweza,wspolzednaYweza;
int wspolzednaXjedzenia,wspolzednaYjedzenia;
int dlugosc, historiaWspolzednejX[10000], historiaWspolzednejY[10000];
int ile=0;
int klawisz;
char kierunek='p';
void zwymyslaj()
{
    cout<<"Podaj dobre liczby brzydalu!"<<endl;
    cout<< "Podaj szerokosc planszy od 5 do 35:"<<endl;
    cin>>szerokosc;
    cout<<"Podaj wysokosc planszy od 5 do 35:"<<endl;
    cin>>wysokosc;
    if(szerokosc<5 or szerokosc>35 or wysokosc<5 or wysokosc>35)
    {
        zwymyslaj();
    }
}
int main()
{
    dlugosc=3;
    cout<< "Podaj szerokosc planszy od 5 do 35:"<<endl;
    cin>>szerokosc;
    cout<<"Podaj wysokosc planszy od 5 do 35:"<<endl;
    cin>>wysokosc;
    if(szerokosc<5 or szerokosc>35 or wysokosc<5 or wysokosc>35)
    {
        zwymyslaj();
    }
    cout<<"Podaj szybkosc od 1 do 10:"<<endl;
    cin>>szybkosc;
    if(szybkosc<1) szybkosc=1;
    if(szybkosc>10) szybkosc=10;
    cout<<"Nacisnij klawisze ktorymi chcesz zagrac:"<<endl;
    cout<<"Gora:"<<endl;
    gora=getch();
    if(gora==224)
    {
        gora+=getch();
    }
    if(gora==0)
    {
        gora-=getch();
    }
    cout<<"Dol:"<<endl;
    dol=getch();
    if(dol==224)
    {
        dol+=getch();
    }
    if(dol==0)
    {
        dol-=getch();
    }
    cout<<"Lewo:"<<endl;
    lewo=getch();
    if(lewo==224)
    {
        lewo+=getch();
    }
    if(lewo==0)
    {
        lewo-=getch();
    }
    cout<<"Prawo:"<<endl;
    prawo=getch();
    if(prawo==224)
    {
        prawo+=getch();
    }
    if(prawo==0)
    {
        prawo-=getch();
    }
    for(int i=0;i<wysokosc;++i)
    {
        for(int j=0;j<szerokosc;++j)
        {
            pole[i][j]='p';
        }
    }
    srand(time(0));
    //losowanie pola dla weza
    wspolzednaXweza=rand()%szerokosc;
    wspolzednaYweza=rand()%wysokosc;
    pole[wspolzednaXweza][wspolzednaYweza]='w';
    //losowanie pola dla jedzenia
    do
    {
        wspolzednaXjedzenia=rand()%szerokosc;
        wspolzednaYjedzenia=rand()%wysokosc;
    }while(pole[wspolzednaXjedzenia][wspolzednaYjedzenia]!='p');
    pole[wspolzednaXjedzenia][wspolzednaYjedzenia]='j';

    //ROZPOCZECIE GRY
    int x=1;
    for(;;)
    {
    	x++;
        srand(time(0));
        ile++;
        historiaWspolzednejX[ile]=wspolzednaXweza;
        historiaWspolzednejY[ile]=wspolzednaYweza;
        //rysownaie planszy
        system("CLS");
        // gorna ramka
        for(int i=0;i<=szerokosc;++i)
        {
            cout<<"--";
        }
        for(int i=0;i<wysokosc;++i)
        {
            cout<<endl<<"|";
            for(int j=0;j<szerokosc;++j)
            {
                if(pole[i][j]=='p') cout<<"  ";
                if(pole[i][j]=='w') cout<<" O";
                if(pole[i][j]=='j') cout<<" X";
            }
            cout<<"|";
        }
        cout<<endl;
        for(int i=0;i<=szerokosc;++i)
        {
            cout<<"--";
        }
        if(x%100==0 && szybkosc<10) szybkosc++;
        Sleep(1000-szybkosc*100); //czekanie w milisekundach
        if(kbhit()) //jesli zostanie nacisniety jakis klawisz
        {
           klawisz=getch();
           if(klawisz==224) klawisz+=getch();
           if(klawisz==0) klawisz-=getch();
           if(klawisz==gora) kierunek='g';
           if(klawisz==dol) kierunek='d';
           if(klawisz==lewo) kierunek='l';
           if(klawisz==prawo) kierunek='p';
        }
        if(kierunek=='l') wspolzednaYweza--;
        if(kierunek=='p') wspolzednaYweza++;
        if(kierunek=='g') wspolzednaXweza--;
        if(kierunek=='d') wspolzednaXweza++;
        //przechodzenie przez scaiany
        if(wspolzednaYweza==szerokosc) wspolzednaYweza=0;
        if(wspolzednaYweza==-1) wspolzednaYweza=szerokosc-1;
        if(wspolzednaXweza==wysokosc) wspolzednaXweza=0;
        if(wspolzednaXweza==-1) wspolzednaXweza=wysokosc-1;
        Sleep(100-szybkosc*10); //czekanie w milisekundach
        //co jesl iwpadnie w siebie
        if(pole[wspolzednaXweza][wspolzednaYweza]=='w')
        {
            cout<<endl<<"Koniec gry"<<endl;
            cout<<"dlugosc "<<dlugosc+1<<endl;
            break;
        }
        //co jesli zje;
        if(pole[wspolzednaXweza][wspolzednaYweza]=='j')
        {
            dlugosc++;
            do
            {
                wspolzednaXjedzenia=rand()%szerokosc;
                wspolzednaYjedzenia=rand()%wysokosc;
            }while(pole[wspolzednaXjedzenia][wspolzednaYjedzenia]!='p');
            pole[wspolzednaXjedzenia][wspolzednaYjedzenia]='j';
        }else{ pole[historiaWspolzednejX[ile-dlugosc]][historiaWspolzednejY[ile-dlugosc]]='p';}
        pole[wspolzednaXweza][wspolzednaYweza]='w';

    }
    getch();
}
