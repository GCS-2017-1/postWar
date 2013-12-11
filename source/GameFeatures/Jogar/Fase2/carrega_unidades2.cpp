#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <cstdio>
#include <string.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"

using namespace std;

void carrega_franca(SDL_Surface *screen,string lado){

    string lado1("servidor");
    string cor = "vermelho";

    for(int i=0, j=1;i<6;i++,j+=30){

        string caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_vermelho.png";
        SDL_Surface *soldado1 = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_vermelho_ataque.png";
        SDL_Surface *ataque_soldado = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_vermelho_ataque_baixo.png";
        SDL_Surface *ataque_baixo = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_vermelho_ataque_cima.png";
        SDL_Surface *ataque_cima = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_lateral_vermelho.png";
        SDL_Surface *soldado_lateral_a= load_Image(caminho, screen);
        Unidade *soldado = new Unidade();

        string unidadea1 = "soldado";
        setar_soldado(soldado, cor, unidadea1, soldado1, ataque_soldado, ataque_baixo, ataque_cima,soldado_lateral_a, id);
        id++;
        unidades_azul.push_back(soldado);
        //if(i+2<=hexagonos.size()){
        SDL_Rect dst;
        dst.x = hexagonos[i*2][3]->x;
        dst.y = hexagonos[i*2][3]->y;
        dst.h = 0;
        dst.w = 0;
        SDL_BlitSurface(unidades_azul[i]->nome, &cutBox,  screen, &dst);
        hexagonos[i*2][3]->unidade = unidades_azul[i];
        hexagonos[i*2][3]->contem_unidade = 1;


        caminho = "source/GameFeatures/Jogar/Fase1/images/bryjstudios_cabana_vermelha.png";
        SDL_Surface *quartel_azul_cabana = load_Image(caminho, screen);
        Unidade *quartel_a = new Unidade();
        string quarte = "quartel";
        setar_quartel(quartel_a,cor,quarte,quartel_azul_cabana, quartel_azul_cabana, quartel_azul_cabana, id);
        id++;
        BlitImage(screen,quartel_azul_cabana,hexagonos[6][1]->x,hexagonos[6][1]->y);
        hexagonos[5][1]->unidade = quartel_a;
        hexagonos[5][1]->contem_unidade = 1;
        hexagonos[6][1]->unidade = quartel_a;
        hexagonos[6][1]->contem_unidade = 1;
        hexagonos[6][2]->contem_unidade = 1;
        hexagonos[6][2]->unidade = quartel_a;
        hexagonos[7][1]->contem_unidade = 1;
        hexagonos[7][1]->unidade = quartel_a;
        hexagonos[8][1]->contem_unidade = 1;
        hexagonos[8][1]->unidade = quartel_a;
        hexagonos[8][2]->contem_unidade = 1;
        hexagonos[8][2]->unidade = quartel_a;
        hexagonos[9][1]->contem_unidade = 1;
        hexagonos[9][1]->unidade = quartel_a;

    }

    for(int i=6, j=1;i<8;i++,j+=30){

        string caminho = "source/GameFeatures/Jogar/Fase2/images/tanque_vermelho.png";
        SDL_Surface *tanque = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase2/images/tanque_vermelho.png";
        SDL_Surface *ataque_tanque = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase2/images/tanque_ataqueParaBaixo(vermelho).png";
        SDL_Surface *ataque_baixo = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase2/images/tanque_ataqueParaCima(vermelho).png";
        SDL_Surface *ataque_cima = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase2/images/tanque_lateral_vermelho.png";
        SDL_Surface *tanque_lateral= load_Image(caminho, screen);
        Unidade *tanque1 = new Unidade();

        string unidadea1 = "tanque";
        setar_tanque(tanque1, cor, unidadea1, tanque, ataque_tanque, ataque_baixo, ataque_cima,tanque_lateral, id);
        id++;
        unidades_azul.push_back(tanque1);
        //if(i+2<=hexagonos.size()){
        SDL_Rect dst;
        dst.x = hexagonos[i*2][3]->x;
        dst.y = hexagonos[i*2][3]->y;
        dst.h = 0;
        dst.w = 0;
        SDL_BlitSurface(unidades_azul[i]->nome, &cutBox,  screen, &dst);
        hexagonos[i*2][3]->unidade = unidades_azul[i];
        hexagonos[i*2][3]->contem_unidade = 1;
    }

    string caminho = "source/GameFeatures/Jogar/Fase2/images/metralhadora_vermelha_esquerda1.png";
    SDL_Surface *metralhadora1 = load_Image(caminho, screen);
    caminho = "source/GameFeatures/Jogar/Fase2/images/metralhadora_vermelha_ataque.png";
    SDL_Surface *metralhadora_ataque = load_Image(caminho, screen);
    caminho = "source/GameFeatures/Jogar/Fase2/images/barraLateral_vermelho.png";
    SDL_Surface *metralhadora_lateral = load_Image(caminho, screen);
    Unidade *metralhadora = new Unidade();
    string unidadea2 = "metralhadora";
    setar_metralhadora(metralhadora, cor, unidadea2, metralhadora1, metralhadora_ataque, metralhadora_lateral, id);
    id++;
    unidades_azul.push_back(metralhadora);

    BlitImage(screen,unidades_azul[8]->nome,hexagonos[6][4]->x,hexagonos[6][4]->y);

    hexagonos[6][4]->contem_unidade=1;
    hexagonos[6][4]->unidade = metralhadora;
    hexagonos[7][4]->contem_unidade=1;
    hexagonos[7][4]->unidade = metralhadora;
    hexagonos[8][4]->contem_unidade=1;
    hexagonos[8][4]->unidade = metralhadora;



    SDL_Color blue;
	blue.g = blue.b = 0;
	blue.r = 255;
	SDL_Color white;
	white.r = white.g = white.b = 255;

	//drawCircle(screen, 20, 44, 137, blue);
	//drawCircle(screen, 20, 78, 157, blue);
}

void carrega_uk(SDL_Surface *screen, string lado){


    string lado2("cliente");
    string cor2 = "azul";

    for(int i=0;i<6;i++){
        string caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_andando_esquerda.png";
        SDL_Surface *soldado1 = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_azul_ataque.png";
        SDL_Surface *soldado_ataque = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_azul_ataque_baixo.png";
        SDL_Surface *soldado_ataque_baixo = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_azul_ataque_cima.png";
        SDL_Surface *soldado_ataque_cima = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_lateral.png";
        SDL_Surface *soldado_lateral_v = load_Image(caminho, screen);
        Unidade *soldado = new Unidade();
        string unidade = "soldado";
        setar_soldado(soldado, cor2, unidade, soldado1, soldado_ataque, soldado_ataque_baixo, soldado_ataque_cima,soldado_lateral_v, id);
        id++;
        unidades_vermelhas.push_back(soldado);

        SDL_Rect dst;
        dst.x = hexagonos[i*2][12]->x;
        dst.y = hexagonos[i*2][12]->y;
        dst.h = 0;
        dst.w = 0;
        SDL_BlitSurface(unidades_vermelhas[i]->nome, &cutBox,  screen, &dst);
        //BlitImage(screen,unidades_vermelhas[0]->nome,hexagonos[2][12]->x,hexagonos[2][12]->y);
        hexagonos[i*2][12]->unidade = unidades_vermelhas[i];
        hexagonos[i*2][12]->contem_unidade = 1;
        unidades_vermelhas[0]->x = hexagonos[i*2][12]->x;
        unidades_vermelhas[0]->y = hexagonos[i*2][12]->y;

    }

    for (int i=6;i<8;i++){
        string caminho = "source/GameFeatures/Jogar/Fase1/images/helicoptero_azul_movimentacao_esqueda.png";
        SDL_Surface *helicoptero1 = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/helicoptero_ataque_azul.png";
        SDL_Surface *helicoptero_ataque = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/helicoptero_ataque_azul_baixo.png";
        SDL_Surface *helicoptero_ataque_baixo = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/helicoptero_ataque_azul_cima.png";
        SDL_Surface *helicoptero_ataque_cima = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/helicoptero_barraLateral.png";
        SDL_Surface *helicoptero_lateral = load_Image(caminho, screen);
        //caminho = "source/GameFeatures/Jogar/Fase1/images/helicoptero_azul_ataque_baixo.png";
        //SDL_Surface *helicoptero_ataque_baixo = load_Image(caminho, screen);
        Unidade *helicoptero = new Unidade();
        string unidade1 = "helicoptero";
        setar_helicoptero(helicoptero, cor2, unidade1, helicoptero1, helicoptero_ataque, helicoptero_ataque_baixo, helicoptero_ataque_cima,helicoptero_lateral, id);
        id++;
        unidades_vermelhas.push_back(helicoptero);

        SDL_Rect dst;
        dst.x = hexagonos[i*2][12]->x;
        dst.y = hexagonos[i*2][12]->y;
        dst.h = 0;
        dst.w = 0;
        SDL_BlitSurface(unidades_vermelhas[i]->nome, &cutBox,  screen, &dst);
        //BlitImage(screen,unidades_vermelhas[0]->nome,hexagonos[2][12]->x,hexagonos[2][12]->y);
        hexagonos[i*2][12]->unidade = unidades_vermelhas[i];
        hexagonos[i*2][12]->contem_unidade = 1;
        unidades_vermelhas[0]->x = hexagonos[i*2][12]->x;
        unidades_vermelhas[0]->y = hexagonos[i*2][12]->y;
    }


    for(int i=8;i<9;i++){
        string caminho = "source/GameFeatures/Jogar/Fase1/images/tanque_azul_esquerda1.png";
        SDL_Surface *tanque1 = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/tanque_azul_ataque.png";
        SDL_Surface *tanque_ataque = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/tanque_azul_ataque_baixo.png";
        SDL_Surface *tanque_ataque_baixo = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/tanque_azul_ataque_cima.png";
        SDL_Surface *tanque_ataque_cima = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/tanque_lateral_a.png";
        SDL_Surface *tanque_lateral = load_Image(caminho, screen);
        Unidade *tanque = new Unidade();
        string unidade3 = "tanque";
        setar_tanque(tanque, cor2, unidade3, tanque1, tanque_ataque, tanque_ataque_baixo, tanque_ataque_cima, tanque_lateral, id);
        id++;
        unidades_vermelhas.push_back(tanque);
        SDL_Rect dst;
        dst.x = hexagonos[i*2][12]->x;
        dst.y = hexagonos[i*2][12]->y;
        dst.h = 0;
        dst.w = 0;
        SDL_BlitSurface(unidades_vermelhas[i]->nome, &cutBox,  screen, &dst);
        //BlitImage(screen,unidades_vermelhas[0]->nome,hexagonos[2][12]->x,hexagonos[2][12]->y);
        hexagonos[i*2][12]->unidade = unidades_vermelhas[i];
        hexagonos[i*2][12]->contem_unidade = 1;
        unidades_vermelhas[0]->x = hexagonos[i*2][12]->x;
        unidades_vermelhas[0]->y = hexagonos[i*2][12]->y;
    }


    ///Carregar os sprites do quartel azul
    string caminho = "source/GameFeatures/Jogar/Fase1/images/bryjstudios_cabana_azul1.png";
    SDL_Surface *quartel_azul_cabana = load_Image(caminho, screen);
    Unidade *quartel_a = new Unidade();
    string quarte = "quartel";
    setar_quartel(quartel_a,cor2,quarte,quartel_azul_cabana, quartel_azul_cabana, quartel_azul_cabana, id);
    id++;
    BlitImage(screen,quartel_azul_cabana,hexagonos[7][13]->x,hexagonos[7][13]->y);
    hexagonos[7][13]->unidade = quartel_a;
    hexagonos[7][13]->contem_unidade= 1;
    hexagonos[7][14]->unidade = quartel_a;
    hexagonos[7][14]->contem_unidade= 1;
    hexagonos[8][14]->unidade = quartel_a;
    hexagonos[8][14]->contem_unidade= 1;
    hexagonos[9][13]->unidade = quartel_a;
    hexagonos[9][13]->contem_unidade= 1;
    hexagonos[9][14]->unidade = quartel_a;
    hexagonos[9][14]->contem_unidade= 1;
    hexagonos[10][14]->unidade = quartel_a;
    hexagonos[10][14]->contem_unidade= 1;
    unidades_vermelhas.push_back(quartel_a);


           // cout<<"i: "<<i<<unidades_vermelhas[i]->tipo<<endl;

        /*unidades_vermelhas[i]->x = hexagonos[i][j]->x;
        unidades_vermelhas[i]->y =hexagonos[i][j]->y;*/
    }








