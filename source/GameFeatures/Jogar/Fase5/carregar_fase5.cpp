#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"


using namespace std;


void carregar_fase5(SDL_Surface *screen){


    hex_selecao = new Hex_selecao();

    string caminho = "source/GameFeatures/Jogar/Fase5/images/Loading.png";
    SDL_Surface *loading = load_Image(caminho, screen);
    BlitImage(screen, loading, 0, 0);
    SDL_Flip(screen);

    caminho = "source/GameFeatures/Jogar/Fase5/images/fase_5.png";
    sem_malha = load_Image(caminho, screen);
    BlitImage(screen,sem_malha,0,0);

    caminho = "source/GameFeatures/Jogar/Fase5/images/menu_meio_jogo.png";
    menu_meio = load_Image(caminho,screen);
    BlitImage(screen,menu_meio,568,78);

    caminho = "source/GameFeatures/Jogar/Fase5/images/fundo_menuPartida.png";
    menu_menor = load_Image(caminho,screen);


    caminho = "source/GameFeatures/Jogar/Fase5/images/voltar_jogo_selecionado.png";
    voltar_jogo_sel = load_Image(caminho, screen);

    caminho = "source/GameFeatures/Jogar/Fase5/images/opcoes_selecionado.png";
    opcoes_sel = load_Image(caminho, screen);

    caminho = "source/GameFeatures/Jogar/Fase5/images/sair_selecionado.png";
    sair_sel = load_Image(caminho, screen);

    caminho = "source/GameFeatures/Jogar/Fase5/images/fase_5_malha.png";
    com_malha = load_Image(caminho, screen);



    caminho = "source/GameFeatures/Jogar/Fase5/images/FundoHUD.png";
    hud = load_Image(caminho, screen);
    BlitImage(screen, hud, 0, 0);

    caminho = "source/GameFeatures/Jogar/Fase5/images/painel_status.png";
    hud2 = load_Image(caminho, screen);
    //BlitImage(screen, hud2, 977, 236);
    mapeia_hexagono();
    hexagonos[19][1]->barrier =1;
    hexagonos[19][6]->barrier =1;
    hexagonos[3][9]->barrier =1;
    hexagonos[6][11]->barrier =1;


        carrega_franca(screen);


        carrega_eua(screen);
        carrega_construcoes(screen);
/*
    for(int i=0; i<hexagonos.size();i++){
        for(int j=0; j<hexagonos[i].size();j++){
        BlitImage(screen,unidades_vermelhas[0]->unit_name,hexagonos[i][j]->x,hexagonos[i][j]->y);
        cout<<hexagonos[i][j]->index<<" ";
        }
        cout<<endl;
    }*/
    SDL_Flip(screen);
}

