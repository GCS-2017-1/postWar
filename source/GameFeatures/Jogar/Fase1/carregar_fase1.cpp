#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"


using namespace std;



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
            hexagon->obstaculo=0;
            hexagon->obstaculo = 0;
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
            hexagon->obstaculo = 0;
            hexagon->centro_x = ie;
            hexagon->centro_y = je;
            hexagon->indice = contador;
            hexagon->raio = 20;
            hexagon->obstaculo=0;
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

void carregar_fase1(SDL_Surface *screen){




    hex_selecao = new Hex_selecao();

    string caminho = "source/GameFeatures/Jogar/Fase1/images/Loading.png";
    SDL_Surface *loading = load_Image(caminho, screen);
    BlitImage(screen, loading, 0, 0);
    SDL_Flip(screen);

    caminho = "source/GameFeatures/Jogar/Fase1/images/malha1.png";
    sem_malha = load_Image(caminho, screen);
    BlitImage(screen,sem_malha,0,0);

    caminho = "source/GameFeatures/Jogar/Fase1/images/menu_meio_jogo.png";
    menu_meio = load_Image(caminho,screen);
    BlitImage(screen,menu_meio,568,78);

    caminho = "source/GameFeatures/Jogar/Fase1/images/fundo_menuPartida.png";
    menu_menor = load_Image(caminho,screen);


    caminho = "source/GameFeatures/Jogar/Fase1/images/voltar_jogo_selecionado.png";
    voltar_jogo_sel = load_Image(caminho, screen);

    caminho = "source/GameFeatures/Jogar/Fase1/images/opcoes_selecionado.png";
    opcoes_sel = load_Image(caminho, screen);

    caminho = "source/GameFeatures/Jogar/Fase1/images/sair_selecionado.png";
    sair_sel = load_Image(caminho, screen);

    caminho = "source/GameFeatures/Jogar/Fase1/images/malha.png";
    com_malha = load_Image(caminho, screen);



    caminho = "source/GameFeatures/Jogar/Fase1/images/FundoHUD.png";
    hud = load_Image(caminho, screen);
    BlitImage(screen, hud, 0, 0);

    caminho = "source/GameFeatures/Jogar/Fase1/images/painel_status.png";
    hud2 = load_Image(caminho, screen);
    //BlitImage(screen, hud2, 977, 236);

    mapeia_hexagono();

    hexagonos[1][12]->obstaculo =1;
    hexagonos[1][3]->obstaculo =1;
    hexagonos[10][6]->obstaculo =1;
    hexagonos[11][10]->obstaculo =1;
    hexagonos[12][11]->obstaculo =1;
    hexagonos[12][0]->obstaculo =1;
    hexagonos[13][0]->obstaculo =1;



        carrega_china(screen);
        carrega_eua(screen);


    carrega_construcoes(screen);
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

