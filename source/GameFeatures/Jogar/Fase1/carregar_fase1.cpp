#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"


using namespace std;

Hex_selecao *hex_selecao;
char codigo[100];
SDL_Surface *mapa1;
void mapeia_hexagono(){

 SDL_Color blue;
	blue.g = blue.b = 0;
	blue.r = 255;
	SDL_Color white;
	white.r = white.g = white.b = 255;

    int ia=0;
    int ja=124;
    int ie=44;
    int je=136;
    int contador=0;
    while(ja<500){
        vector <Hexagono *> hex_temp;
        for(ia=35, ie=44;ia<1050;ia+=68,ie+=68 ){

            //BlitImage(screen,unidades_azul[0]->nome,ia,ja);
            Hexagono *hexagon = new Hexagono;
            hexagon->centro_x = ie;
            hexagon->centro_y = je;
            hexagon->raio = 20;
            hexagon->x = ia;
            hexagon->y = ja;
            hexagon->indice = contador;
            hexagon->contem_unidade=0;
            if(contador==132){
                //string caminho = "source/GameFeatures/Jogar/Fase1/images/unidade_azul_direita1.png";
                //SDL_Surface *soldado1 = load_Image(caminho, screen);
               // BlitImage(screen,soldado1,ie,je);
             }

            hex_temp.push_back(hexagon);
            contador++;
        }
        hexagonos.push_back(hex_temp);
        ja+=19;
        je+=20;
        vector <Hexagono *> hex_temp2;
        for(ia=65,ie=78;ia<1050;ia+=68,ie+=68){

            //BlitImage(screen,unidades_azul[0]->nome,ia,ja);

            Hexagono *hexagon = new Hexagono;
            hexagon->x = ia;
            hexagon->y = ja;
            hexagon->centro_x = ie;
            hexagon->centro_y = je;
            hexagon->indice = contador;
            hexagon->raio = 20;
            hexagon->contem_unidade=0;
            hex_temp2.push_back(hexagon);
            contador++;
        }
        hexagonos.push_back(hex_temp2);
        ja+=20;
        je+=20;
    }
    /*
    string bora="0";
    string bora1="0";
    for(int i=0; i<hexagonos.size();i++){
        for(int j=0; j<hexagonos[i].size();j++){
            bora[0]+=i;
            bora1[0] += j;
            //cout<<"bora: "<<bora1<<endl;
            desenha_texto(bora,screen,hexagonos[i][j]->x,hexagonos[i][j]->y,20);
            desenha_texto(bora1,screen,hexagonos[i][j]->x+10,hexagonos[i][j]->y,20);
            bora="0";
            bora1="0";
        }
    }*/



}

SDL_Surface *sem_malha;
SDL_Surface *com_malha;
SDL_Surface *hud;
SDL_Surface *hud2;
int x_painel = 977;
int y_painel = 236;
void carregar_fase1(SDL_Surface *screen, char pais_serv[],char pais_client[]){




    hex_selecao = new Hex_selecao();

    string caminho = "source/GameFeatures/Jogar/Fase1/images/Loading.png";
    SDL_Surface *loading = load_Image(caminho, screen);
    BlitImage(screen, loading, 0, 0);
    SDL_Flip(screen);

    caminho = "source/GameFeatures/Jogar/Fase1/images/malha1.png";
    sem_malha = load_Image(caminho, screen);
    BlitImage(screen,sem_malha,0,0);

    caminho = "source/GameFeatures/Jogar/Fase1/images/malha.png";
    com_malha = load_Image(caminho, screen);

    caminho = "source/GameFeatures/Jogar/Fase1/images/FundoHUD.png";
    hud = load_Image(caminho, screen);
    BlitImage(screen, hud, 0, 0);

    caminho = "source/GameFeatures/Jogar/Fase1/images/painel_status.png";
    hud2 = load_Image(caminho, screen);
    //BlitImage(screen, hud2, 977, 236);

    mapeia_hexagono();

    if(strcmp("china",pais_serv) == 0){
        string escolha = "servidor";
        carrega_china(screen,escolha);
    }

    if(strcmp("eua",pais_client)==0){
        string escolha = "cliente";
        carrega_eua(screen,escolha);
    }
/*
    for(int i=0; i<hexagonos.size();i++){
        for(int j=0; j<hexagonos[i].size();j++){
        BlitImage(screen,unidades_vermelhas[0]->nome,hexagonos[i][j]->x,hexagonos[i][j]->y);
        cout<<hexagonos[i][j]->indice<<" ";
        }
        cout<<endl;
    }*/




    SDL_Flip(screen);
}

