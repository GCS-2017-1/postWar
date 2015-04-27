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

void carrega_china_azul(SDL_Surface *screen){

    string lado2("cliente");
    string cor2 = "azul";

    for(int i=0;i<10;i++){
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
        Unit *soldado = new Unit();
        string unit = "soldado";
        setar_soldado(soldado, cor2, unit, soldado1, soldado_ataque, soldado_ataque_baixo, soldado_ataque_cima,soldado_lateral_v, id);
        id++;
        unidades_vermelhas.push_back(soldado);

        SDL_Rect dst;
        dst.x = hexagonos[i*2][12]->x;
        dst.y = hexagonos[i*2][12]->y;
        dst.h = 0;
        dst.w = 0;
        SDL_BlitSurface(unidades_vermelhas[i]->unit_name, &cutBox,  screen, &dst);
        //BlitImage(screen,unidades_vermelhas[0]->unit_name,hexagonos[2][12]->x,hexagonos[2][12]->y);
        hexagonos[i*2][12]->unit = unidades_vermelhas[i];
        hexagonos[i*2][12]->contains_unit = 1;
        unidades_vermelhas[0]->x = hexagonos[i*2][12]->x;
        unidades_vermelhas[0]->y = hexagonos[i*2][12]->y;

    }


    for (int i=10;i<11;i++){
        string caminho = "source/GameFeatures/Jogar/Fase1/images/metralha_azul.png";
        SDL_Surface *metrapalhadora1 = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/metralhadora_azul_ataque.png";
        SDL_Surface *metrapalhadora_ataque = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/barraLateral_azul.png";
        SDL_Surface *metrapalhadora_lateral = load_Image(caminho, screen);
        Unit *metralhadora = new Unit();
        string unidade2 = "metralhadora";
        setar_metralhadora(metralhadora, cor2, unidade2, metrapalhadora1, metrapalhadora_ataque, metrapalhadora_lateral, id);
        id++;
        unidades_vermelhas.push_back(metralhadora);

        BlitImage(screen,unidades_vermelhas[i]->unit_name,hexagonos[2][13]->x,hexagonos[2][13]->y);
        hexagonos[2][13]->unit = unidades_vermelhas[i];
        hexagonos[2][13]->contains_unit = 1;
        hexagonos[3][13]->unit = unidades_vermelhas[i];
        hexagonos[3][13]->contains_unit = 1;
        hexagonos[4][13]->unit = unidades_vermelhas[i];
        hexagonos[4][13]->contains_unit = 1;
        hexagonos[5][13]->unit = unidades_vermelhas[i];
        hexagonos[5][13]->contains_unit = 1;
        hexagonos[6][13]->unit = unidades_vermelhas[i];
        hexagonos[6][13]->contains_unit = 1;
    }

    ///Carregar os sprites do quartel azul
    string caminho = "source/GameFeatures/Jogar/Fase1/images/bryjstudios_cabana_azul1.png";
    SDL_Surface *quartel_azul_cabana = load_Image(caminho, screen);
    Unit *quartel_a = new Unit();
    string quarte = "quartel";
    setar_quartel(quartel_a,cor2,quarte,quartel_azul_cabana, quartel_azul_cabana, quartel_azul_cabana, id);
    id++;
    BlitImage(screen,quartel_azul_cabana,hexagonos[7][13]->x,hexagonos[7][13]->y);
    hexagonos[7][13]->unit = quartel_a;
    hexagonos[7][13]->contains_unit= 1;
    hexagonos[7][14]->unit = quartel_a;
    hexagonos[7][14]->contains_unit= 1;
    hexagonos[8][14]->unit = quartel_a;
    hexagonos[8][14]->contains_unit= 1;
    hexagonos[9][13]->unit = quartel_a;
    hexagonos[9][13]->contains_unit= 1;
    hexagonos[9][14]->unit = quartel_a;
    hexagonos[9][14]->contains_unit= 1;
    hexagonos[10][14]->unit = quartel_a;
    hexagonos[10][14]->contains_unit= 1;
    unidades_vermelhas.push_back(quartel_a);

    /*BlitImage(screen,unidades_vermelhas[5]->unit_name,hexagonos[14][12]->x,hexagonos[14][12]->y);
    hexagonos[14][12]->unit = unidades_vermelhas[5];
    hexagonos[14][12]->contains_unit = 1;
    unidades_vermelhas[5]->x = hexagonos[14][12]->x;
    unidades_vermelhas[5]->y = hexagonos[14][12]->y;*/


}




