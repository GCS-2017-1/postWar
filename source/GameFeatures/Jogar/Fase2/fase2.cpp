#include <iostream>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <cstdio>
#include <string.h>
#include <iostream>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"


void fase2(SDL_Surface *screen,string qual_maquina){

    FPS = 150;
    Pais *china = new Pais();
    string nome = "China";
    string cor = "vermelho";
    setar_pais(china, 50, 100, 50, nome, cor);
    Pais *eua = new Pais();
    nome = "EUA";
    cor = "azul";
    setar_pais(eua, 100, 50, 50, nome, cor);

    char pais_serv[100] = "franca";
    char pais_client[100] = "eua";


    carregar_fase2(screen,pais_serv,pais_client);
    int lastdt = SDL_GetTicks();
    int totalElapsedTime = 0;
    int delay = 200;

    int minha_vez;

    Vetor_mouse *vetor = new Vetor_mouse();
    blit_tela(screen,0);
    SDL_Flip(screen);

    //string opcao = "source/GameFeatures/Jogar/Fase1/images/bryjstudios_mouse.png";
    //SDL_Surface *mouse = load_Image(opcao, screen);
    int start1 =0;
    if(qual_maquina.compare("cliente")){
        minha_vez=1;

        while(1){
            start = SDL_GetTicks();
            //memset (codigo_s,'0',100);
            if(minha_vez){

                blit_cima(china,screen); //verifica_hexagono.cpp
                desenha_pontos(pontos_jogador1, screen); //fase1.cpp
                vetor = get_Input();
                string palavra = "Sua vez.";
                red = 255;
                green = 0;
                blue = 0;
                desenha_texto(palavra,screen,200, 200, 60);

                if(vetor->click == 1){

                    if(compara_selecao(568,647,vetor->x,78,111,vetor->y)){
                        clica_menu_menor(screen);
                    }

                    if(verifica_hexagono(vetor->x,vetor->y)){

                    //if(compara_selecao(unidades_vermelhas[0]->x, unidades_vermelhas[0]->x+32, vetor->x, unidades_vermelhas[0]->y, unidades_vermelhas[0]->y+32, vetor->y)){
                        hex_selecao->i_antes = hex_selecao->i;
                        hex_selecao->j_antes = hex_selecao->j;
                        if(possui_unidade("vermelho") && !hexagonos[hex_selecao->i][hex_selecao->j]->obstaculo){
                            blit_tela(screen,1);
                            blit_selecao(screen);
                            blit_lateral(hexagonos[hex_selecao->i][hex_selecao->j]->unidade,screen);
                            blit_cima(china,screen);
                            while(1){
                                start1 = SDL_GetTicks();
                                vetor = get_Input();
                                if(vetor->click == 1){
                                    //cout<<"What?"<<endl;
                                    verifica_hexagono(vetor->x,vetor->y);

                                    if(possui_unidade("vermelho")){
                                        //cout<<"VÉSH"<<endl;
                                        break;
                                    }
                                    if(alcance_ataque_soldado()){

                                        codifica_ataque(codigo_s);
                                        //cout << "passei codifica" << endl;
                                        enviar_msg(Sclient,codigo_s);
                                        ataque_unidade(screen, hexagonos[hex_selecao->i][hex_selecao->j]->x,hexagonos[hex_selecao->i][hex_selecao->j]->y, totalElapsedTime, delay, lastdt);
                                        dano_ataque(screen);
                                        //cout << "enviei" << endl;
                                        //cout << "animei ataque" << endl;
                                        if(derrotado.compare(cor1) == 0){
                                            vermelhoperde = 1;
                                            vermelhoganha = 0;
                                            azulganha = 1;
                                            azulperde = 0;
                                        }
                                        if(derrotado.compare(cor2) == 0){
                                            cout << "Entrei aqui 1" << endl;
                                            azulperde = 1;
                                            azulganha = 0;
                                            vermelhoganha = 1;
                                            vermelhoperde = 0;
                                        }
                                        cout << "cout 1" << endl;
                                        cout << "Vermelho perde:" << vermelhoperde << endl;
                                        cout << "Vermelho ganha:" << vermelhoganha << endl;
                                        cout << "Azul perde:" << azulperde << endl;
                                        cout << "Azul ganha:" << azulganha << endl;

                                        pontos_jogador1 -= 6;
                                        if(pontos_jogador1<3){
                                            minha_vez = 0;
                                            pontos_jogador1 = 20;
                                        }
                                        if(vermelhoperde == 1 && azulganha == 1){
                                            perdeu_jogo(screen);
                                        }
                                        if(azulganha == 1 && vermelhoganha == 1){
                                            venceu_jogo(screen);
                                        }
                                        break;
                                    }

                                    if(alcance_movimento_soldado()){
                                        strcpy (codigo_s,"00");
                                        codigo_s[2] = (char)(((int)'0')+hex_selecao->i_antes);
                                        codigo_s[3] = (char)(((int)'0')+hex_selecao->j_antes);
                                        codigo_s[4] = (char)(((int)'0')+hex_selecao->i);
                                        codigo_s[5] = (char)(((int)'0')+hex_selecao->j);
                                        //cout<<"Enviando msg..."<<endl;
                                        enviar_msg(Sclient,codigo_s);
                                        //cout<<"A mensagem enviada foi: "<<codigo_s  <<endl;
                                        mover_soldado(screen, hexagonos[hex_selecao->i][hex_selecao->j]->x,hexagonos[hex_selecao->i][hex_selecao->j]->y, totalElapsedTime, delay, lastdt);
                                        pontos_jogador1 -= 3;
                                        if(pontos_jogador1<3){
                                            minha_vez = 0;
                                            pontos_jogador1 = 20;
                                            coleta_minerio(china, minerio_vermelho);
                                            minerio_vermelho += 5;
                                        }
                                        break;
                                    }
                                        else{
                                            blit_tela(screen,0);
                                            blit_cima(china,screen);
                                            break;
                                        }
                                }
                                if((unsigned)(SDL_GetTicks() - start1) < (unsigned)(1000/FPS)){
                                    SDL_Delay((1000/FPS) - (SDL_GetTicks() - start1));
                                }
                            }
                        }
                        //verifica_derrota(screen);
                        blit_tela(screen,0);
                        blit_cima(china,screen);
                    }


                }

                if(derrotado.compare(cor1) == 0){
                    vermelhoperde = 1;
                    vermelhoganha = 0;
                    azulganha = 1;
                    azulperde = 0;
                }
                if(derrotado.compare(cor2) == 0){
                    cout << "Entrei aqui 2" << endl;
                    azulperde = 1;
                    azulganha = 0;
                    vermelhoganha = 1;
                    vermelhoperde = 0;
                }
                cout << "cout 2" << endl;
                cout << "Vermelho perde:" << vermelhoperde << endl;
                cout << "Vermelho ganha:" << vermelhoganha << endl;
                cout << "Azul perde:" << azulperde << endl;
                cout << "Azul ganha:" << azulganha << endl;

                if(azulganha == 1 && vermelhoperde == 1){
                    perdeu_jogo(screen);
                }
                if(vermelhoganha == 1 && azulperde == 1){
                    venceu_jogo(screen);
                }
            if((unsigned)(SDL_GetTicks() - start) < (unsigned)(1000/FPS)){
                SDL_Delay((1000/FPS) - (SDL_GetTicks() - start));
            }
            SDL_Flip(screen);
            }

                else{

                    blit_cima(china,screen);
                    string palavra = "Vez do outro jogador.";
                    blit_tela(screen,0);
                    desenha_texto(palavra,screen,200, 200, 60);
                    if((unsigned)(SDL_GetTicks() - start) < (unsigned)(1000/FPS)){
                        SDL_Delay((1000/FPS) - (SDL_GetTicks() - start));
                    }
                    SDL_Flip(screen);
                    char code_recv[100];
                    receber_msg(Sclient,code_recv);
                    //cout<<"Recebi a msg: "<<code_recv<<endl;
                    amigo_movimenta(code_recv,screen, totalElapsedTime,delay,lastdt);
                    if(code_recv[0] == '0' && code_recv[1] == '0'){
                        pontos_jogador2 -=3;
                    }
                    if(code_recv[0] == '0' && code_recv[1] == '1'){
                        pontos_jogador2 -=6;
                    }
                    if(derrotado.compare(cor1) == 0){
                        vermelhoperde = 1;
                        vermelhoganha = 0;
                        azulganha = 1;
                        azulperde = 0;
                    }
                    if(derrotado.compare(cor2) == 0){
                        azulperde = 1;
                        azulganha = 0;
                        vermelhoganha = 1;
                        vermelhoperde = 0;
                    }
                    cout << "cout 3" << endl;
                    cout << "Vermelho perde:" << vermelhoperde << endl;
                    cout << "Vermelho ganha:" << vermelhoganha << endl;
                    cout << "Azul perde:" << azulperde << endl;
                    cout << "Azul ganha:" << azulganha << endl;

                    if(pontos_jogador2<3){
                        minha_vez = 1;
                        pontos_jogador2 = 20;
                    }
                    if(vermelhoperde == 1 && azulganha == 1){
                        perdeu_jogo(screen);
                    }
                    if(azulganha == 1 && vermelhoperde == 1){
                        venceu_jogo(screen);
                    }
                }
        }

    }


    else{
        blit_cima(eua,screen);
        minha_vez = 0;
        red = 0;
        green = 200;
        blue = 200;

        while(1){
            start1 = SDL_GetTicks();
            if(minha_vez == 0){

                blit_cima(eua,screen);
                string palavra = "Vez do outro jogador.";
                blit_tela(screen,0);
                desenha_texto(palavra,screen,200, 200, 60);
                if((unsigned)(SDL_GetTicks() - start) < (unsigned)(1000/FPS)){
                        SDL_Delay((1000/FPS) - (SDL_GetTicks() - start));
                }
                SDL_Flip(screen);
                //cout<<"Sou cliente"<<endl;
                vetor = get_Input();

                if(compara_selecao(568,647,vetor->x,78,111,vetor->y)){
                        clica_menu_menor(screen);
                }

                char code_recv[100];
                receber_msg(Cserver,code_recv);
                //cout<<"Recebi a msg: "<<code_recv<<endl;
                amigo_movimenta(code_recv,screen, totalElapsedTime,delay,lastdt);
                //cout<<"opa!! cheguei aqui"<<endl;
                if(code_recv[0] == '0' && code_recv[1] == '0'){
                        pontos_jogador1 -=3;
                }
                if(code_recv[0] == '0' && code_recv[1] == '1'){
                    pontos_jogador1 -=6;
                }
                if(derrotado.compare(cor1) == 0){
                    vermelhoperde = 1;
                    vermelhoganha = 0;
                    azulganha = 1;
                    azulperde = 0;
                }
                if(derrotado.compare(cor2) == 0){
                    vermelhoganha = 1;
                    vermelhoperde = 0;
                    azulperde = 1;
                    azulganha = 0;
                }
                cout << "cout 4" << endl;
                cout << "Vermelho perde:" << vermelhoperde << endl;
                cout << "Vermelho ganha:" << vermelhoganha << endl;
                cout << "Azul perde:" << azulperde << endl;
                cout << "Azul ganha:" << azulganha << endl;

                if(pontos_jogador1<3){
                    minha_vez = 1;
                    pontos_jogador1 = 20;
                }
                if(azulperde == 1 && vermelhoganha == 1){
                    perdeu_jogo(screen);
                }
                if(vermelhoperde == 1 && azulganha == 1){
                    venceu_jogo(screen);
                }

            }
            else{

                blit_cima(eua,screen);
                desenha_pontos(pontos_jogador2, screen);
                //cout<<"eu cliente, fui até aqui"<<endl;
                vetor = get_Input();
                string palavra = "Sua vez.";
                desenha_texto(palavra,screen,200, 200, 60);

                if(vetor->click == 1){

                    if(verifica_hexagono(vetor->x,vetor->y)){


                    //if(compara_selecao(unidades_vermelhas[0]->x, unidades_vermelhas[0]->x+32, vetor->x, unidades_vermelhas[0]->y, unidades_vermelhas[0]->y+32, vetor->y)){
                        hex_selecao->i_antes = hex_selecao->i;
                        hex_selecao->j_antes = hex_selecao->j;
                        if(possui_unidade("azul")){
                            blit_cima(eua,screen);
                            blit_tela(screen,1);
                            blit_selecao(screen);
                            blit_lateral(hexagonos[hex_selecao->i][hex_selecao->j]->unidade,screen);
                                    while(1){
                                        start1 = SDL_GetTicks();
                                        blit_cima(eua,screen);
                                        vetor = get_Input();
                                        if(vetor->click == 1){
                                            verifica_hexagono(vetor->x,vetor->y);
                                            if(possui_unidade("azul")){
                                                break;
                                            }
                                            if(alcance_ataque_soldado()){

                                                codifica_ataque(codigo_s);
                                                //cout << "passei codifica" << endl;
                                                enviar_msg(Cserver,codigo_s);
                                                //cout << "enviei" << endl;
                                                ataque_unidade(screen, hexagonos[hex_selecao->i][hex_selecao->j]->x,hexagonos[hex_selecao->i][hex_selecao->j]->y, totalElapsedTime, delay, lastdt);
                                                dano_ataque(screen);
                                                //cout << "animei ataque" << endl;
                                                if(derrotado.compare(cor1) == 0){
                                                    vermelhoperde = 1;
                                                    vermelhoganha = 0;
                                                    azulganha = 1;
                                                    azulperde = 0;
                                                }
                                                if(derrotado.compare(cor2) == 0){
                                                    vermelhoganha = 1;
                                                    vermelhoperde = 0;
                                                    azulperde = 1;
                                                    azulganha = 0;
                                                }

                                                cout << "cout 5" << endl;
                                                cout << "Vermelho perde:" << vermelhoperde << endl;
                                                cout << "Vermelho ganha:" << vermelhoganha << endl;
                                                cout << "Azul perde:" << azulperde << endl;
                                                cout << "Azul ganha:" << azulganha << endl;

                                                pontos_jogador2 -= 6;
                                                if(pontos_jogador2<3){
                                                    minha_vez = 0;
                                                    pontos_jogador2 = 20;
                                                }
                                                break;
                                            }



                                            if(alcance_movimento_soldado()){

                                                strcpy (codigo_s,"00");
                                                codigo_s[2] = (char)(((int)'0')+hex_selecao->i_antes);
                                                codigo_s[3] = (char)(((int)'0')+hex_selecao->j_antes);
                                                codigo_s[4] = (char)(((int)'0')+hex_selecao->i);
                                                codigo_s[5] = (char)(((int)'0')+hex_selecao->j);
                                                //cout<<"Enviando msg..."<<endl;
                                                enviar_msg(Cserver,codigo_s);
                                                //cout<<"A mensagem enviada foi: "<<codigo_s  <<endl;

                                                mover_soldado(screen, hexagonos[hex_selecao->i][hex_selecao->j]->x,hexagonos[hex_selecao->i][hex_selecao->j]->y, totalElapsedTime, delay, lastdt);
                                                pontos_jogador2 -= 3;
                                                if(pontos_jogador2<3){
                                                    minha_vez = 0;
                                                    pontos_jogador2 = 20;
                                                }
                                                if((azulganha == 1) && (vermelhoperde == 1)){
                                                    venceu_jogo(screen);
                                                }
                                                if((vermelhoperde == 1) && (azulganha == 1)){
                                                    perdeu_jogo(screen);
                                                }
                                                break;
                                            }
                                                else{
                                                        blit_tela(screen,0);
                                                        blit_cima(eua,screen);
                                                        break;
                                                }

                                        }
                                        if((unsigned)(SDL_GetTicks() - start1) < (unsigned)(1000/FPS)){
                                            SDL_Delay((1000/FPS) - (SDL_GetTicks() - start1));
                                        }

                                    }
                        }
                        blit_tela(screen,0);
                        blit_cima(eua,screen);

                    }

                }

                if((azulganha == 1) && (vermelhoperde == 1)){
                    venceu_jogo(screen);
                }
                if((vermelhoperde == 1) && (azulganha == 1)){
                    perdeu_jogo(screen);
                }
                //blit_tela(screen);
                //BlitImage(screen,mouse,vetor->x-13,vetor->y-13 );
                if((unsigned)(SDL_GetTicks() - start) < (unsigned)(1000/FPS)){
                        SDL_Delay((1000/FPS) - (SDL_GetTicks() - start));
                }
                SDL_Flip(screen);
            }
        }
    }


}





