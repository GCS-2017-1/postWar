#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"


using namespace std;


void carregar_fase4(SDL_Surface *screen){


    hex_selecao = new Hex_selecao();

    string caminho = "source/GameFeatures/Jogar/Fase4/images/Loading.png";
    SDL_Surface *loading = load_Image(caminho, screen);
    BlitImage(screen, loading, 0, 0);
    SDL_Flip(screen);

    caminho = "source/GameFeatures/Jogar/Fase4/images/fase_4.png";
    sem_malha = load_Image(caminho, screen);
    BlitImage(screen,sem_malha,0,0);

    caminho = "source/GameFeatures/Jogar/Fase4/images/menu_meio_jogo.png";
    menu_meio = load_Image(caminho,screen);
    BlitImage(screen,menu_meio,568,78);

    caminho = "source/GameFeatures/Jogar/Fase4/images/fundo_menuPartida.png";
    menu_menor = load_Image(caminho,screen);


    caminho = "source/GameFeatures/Jogar/Fase4/images/voltar_jogo_selecionado.png";
    voltar_jogo_sel = load_Image(caminho, screen);

    caminho = "source/GameFeatures/Jogar/Fase4/images/opcoes_selecionado.png";
    opcoes_sel = load_Image(caminho, screen);

    caminho = "source/GameFeatures/Jogar/Fase4/images/sair_selecionado.png";
    sair_sel = load_Image(caminho, screen);

    caminho = "source/GameFeatures/Jogar/Fase4/images/fase_4_malha.png";
    com_malha = load_Image(caminho, screen);



    caminho = "source/GameFeatures/Jogar/Fase4/images/FundoHUD.png";
    hud = load_Image(caminho, screen);
    BlitImage(screen, hud, 0, 0);

    caminho = "source/GameFeatures/Jogar/Fase4/images/painel_status.png";
    hud2 = load_Image(caminho, screen);
    //BlitImage(screen, hud2, 977, 236);
    mapeia_hexagono();
    hexagonos[3][6]->obstaculo =1;
    hexagonos[5][6]->obstaculo =1;
    hexagonos[6][7]->obstaculo =1;
    hexagonos[5][7]->obstaculo =1;
    hexagonos[3][7]->obstaculo =1;
    hexagonos[1][7]->obstaculo =1;
    hexagonos[2][7]->obstaculo =1;
    hexagonos[3][6]->obstaculo =1;
    hexagonos[5][6]->obstaculo =1;
    hexagonos[2][4]->obstaculo =1;
    hexagonos[3][4]->obstaculo =1;
    hexagonos[5][4]->obstaculo =1;
    hexagonos[7][4]->obstaculo =1;
    hexagonos[8][4]->obstaculo =1;
    hexagonos[12][4]->obstaculo =1;
    hexagonos[13][4]->obstaculo =1;
    hexagonos[15][4]->obstaculo =1;
    hexagonos[16][4]->obstaculo =1;
    hexagonos[17][4]->obstaculo =1;
    hexagonos[19][6]->obstaculo =1;
    hexagonos[18][7]->obstaculo =1;
    hexagonos[11][6]->obstaculo =1;
    hexagonos[19][7]->obstaculo =1;
    hexagonos[13][6]->obstaculo =1;
    hexagonos[14][7]->obstaculo =1;
    hexagonos[13][7]->obstaculo =1;
    hexagonos[11][7]->obstaculo =1;
    hexagonos[10][7]->obstaculo =1;
    hexagonos[2][10]->obstaculo =1;
    hexagonos[6][10]->obstaculo =1;
    hexagonos[8][10]->obstaculo =1;
    hexagonos[12][10]->obstaculo =1;
    hexagonos[14][10]->obstaculo =1;
    hexagonos[16][10]->obstaculo =1;
    hexagonos[18][10]->obstaculo =1;
        carrega_urss(screen);


        carrega_china_azul(screen);
        carrega_construcoes(screen);
/*
    for(int i=0; i<hexagonos.size();i++){
        for(int j=0; j<hexagonos[i].size();j++){
        BlitImage(screen,unidades_vermelhas[0]->unit_name,hexagonos[i][j]->x,hexagonos[i][j]->y);
        cout<<hexagonos[i][j]->indice<<" ";
        }
        cout<<endl;
    }*/
    SDL_Flip(screen);
}

