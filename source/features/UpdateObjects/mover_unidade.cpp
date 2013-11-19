#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"


void mover_soldado(SDL_Surface *screen, int i, int x, int y, int totalElapsedTime, int delay, int lastdt){
    /*for(int h = unidades_vermelhas[i]->x, w = unidades_vermelhas[i]->y;h>x; h = h-25){
    cout << "entrei for com h = " << h << endl;
    cout << "entrei com w = " << w << endl;
    int posi = unidades_vermelhas[i]->x;

    for(int j = posi;j>x;j--){
    SDL_Rect pos = {j, y};
    unidades_vermelhas[i]->x = j;
    //SDL_BlitSurface(unidades_vermelhas[i]->nome, NULL, screen, &pos);
    blit_tela(screen);
    }*/
    SDL_Rect cutBox = {32,0,32,32};
    int w = unidades_vermelhas[i]->x;
    while(w > x){
        blit_tela(screen);
        int dt = SDL_GetTicks() - lastdt;
        lastdt = SDL_GetTicks();
        cout << "w:" << w << endl;
        cout << "x:" << x << endl;
        cout << "dt:" << dt << endl;
        cout << "lastdt:" << lastdt << endl;
        cout << "delay:" << delay << endl;
        if(w>x){
        w = w - 2;
        cout << "w:" << w << endl;
        totalElapsedTime += dt;
        cout << "totalElapsedTime:" << totalElapsedTime << endl;
        if(totalElapsedTime >= delay) {
            totalElapsedTime -= delay;
            cout << "cutbotx:  " << cutBox.x << endl;
            if(cutBox.x == 0){
                cout << "Entrei aqui" << endl;
                cutBox.x = 32;
            }
            else {
                cutBox.x -= 32;
            }
        }



        SDL_Rect dest = {(Sint16)w, (Sint16)y, 0, 0};
        SDL_BlitSurface(unidades_vermelhas[i]->nome, &cutBox, screen, &dest);
        SDL_Delay(200);
        SDL_Flip(screen);
        unidades_vermelhas[i]->x = x;
        unidades_vermelhas[i]->y = y;

    }
    }



}
