#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"


using namespace std;


void carregar_fase3(SDL_Surface *screen){


    hex_selecao = new Hexagon_selected();

    string caminho = "source/GameFeatures/Jogar/Fase3/images/Loading.png";
    SDL_Surface *loading = load_Image(caminho, screen);
    BlitImage(screen, loading, 0, 0);
    SDL_Flip(screen);

    caminho = "source/GameFeatures/Jogar/Fase3/images/fase_3.png";
    sem_malha = load_Image(caminho, screen);
    BlitImage(screen,sem_malha,0,0);

    caminho = "source/GameFeatures/Jogar/Fase3/images/menu_meio_jogo.png";
    menu_meio = load_Image(caminho,screen);
    BlitImage(screen,menu_meio,568,78);

    caminho = "source/GameFeatures/Jogar/Fase3/images/fundo_menuPartida.png";
    menu_menor = load_Image(caminho,screen);


    caminho = "source/GameFeatures/Jogar/Fase3/images/voltar_jogo_selecionado.png";
    voltar_jogo_sel = load_Image(caminho, screen);

    caminho = "source/GameFeatures/Jogar/Fase3/images/opcoes_selecionado.png";
    opcoes_sel = load_Image(caminho, screen);

    caminho = "source/GameFeatures/Jogar/Fase3/images/sair_selecionado.png";
    sair_sel = load_Image(caminho, screen);

    caminho = "source/GameFeatures/Jogar/Fase3/images/fase_3_malha.png";
    com_malha = load_Image(caminho, screen);



    caminho = "source/GameFeatures/Jogar/Fase3/images/FundoHUD.png";
    hud = load_Image(caminho, screen);
    BlitImage(screen, hud, 0, 0);

    caminho = "source/GameFeatures/Jogar/Fase3/images/painel_status.png";
    hud2 = load_Image(caminho, screen);
    //BlitImage(screen, hud2, 977, 236);
    mapeia_hexagono();
    hexagonos[1][7]->barrier =1;
    hexagonos[3][8]->barrier =1;
    hexagonos[3][9]->barrier =1;
    hexagonos[4][9]->barrier =1;
    hexagonos[1][7]->barrier =1;
    hexagonos[0][8]->barrier =1;
    hexagonos[0][9]->barrier =1;
    hexagonos[5][8]->barrier =1;
    hexagonos[8][9]->barrier =1;
    hexagonos[9][8]->barrier =1;
    hexagonos[10][9]->barrier =1;
    hexagonos[11][8]->barrier =1;
    hexagonos[12][8]->barrier =1;
    hexagonos[13][8]->barrier =1;
    hexagonos[15][8]->barrier =1;
    hexagonos[17][8]->barrier =1;
    hexagonos[19][8]->barrier =1;
    hexagonos[4][10]->barrier =1;
    hexagonos[6][10]->barrier =1;
    hexagonos[9][9]->barrier =1;
    hexagonos[11][9]->barrier =1;
    hexagonos[12][10]->barrier =1;
    hexagonos[13][9]->barrier =1;
    hexagonos[14][9]->barrier =1;
    hexagonos[15][10]->barrier =1;
    hexagonos[16][9]->barrier =1;
    hexagonos[17][9]->barrier =1;
    hexagonos[13][10]->barrier =1;
    hexagonos[13][10]->barrier =1;
    hexagonos[14][10]->barrier =1;
    hexagonos[15][10]->barrier =1;
    hexagonos[16][10]->barrier =1;
    hexagonos[17][10]->barrier =1;
    hexagonos[14][11]->barrier =1;
    hexagonos[18][11]->barrier =1;
    hexagonos[17][11]->barrier =1;
    hexagonos[15][4]->barrier =1;
    hexagonos[14][5]->barrier =1;
    hexagonos[13][5]->barrier =1;
    hexagonos[13][6]->barrier =1;
    hexagonos[12][7]->barrier =1;
    hexagonos[15][6]->barrier =1;
    hexagonos[16][7]->barrier =1;

        carrega_urss(screen);


        carrega_uk(screen);
        carrega_construcoes(screen);
/*
    for(int i=0; i<hexagonos.size();i++){
        for(int j=0; j<hexagonos[i].size();j++){
        BlitImage(screen,unidades_vermelhas[0]->name,hexagonos[i][j]->x,hexagonos[i][j]->y);
        cout<<hexagonos[i][j]->index<<" ";
        }
        cout<<endl;
    }*/
    SDL_Flip(screen);
}

