#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"

using namespace std;

void mover_soldado(SDL_Surface *screen,
				   int x,
				   int y,
				   int totalElapsedTime,
				   int delay,
				   int lastdt)
{

	string tipo1 = "quartel";
	string tipo2 = "metralhadora";
	Unidade *temp;

	temp = hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->unidade;

	if (temp->tipo == tipo1 || temp->tipo == tipo2) {
		cout << "Nao pode mover" << endl;
		return;
	}

	hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->unidade = NULL;
	hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->contem_unidade = 0;

	SDL_Rect cutBox = {32,0,32,32};

	int tempo_delay;

	if (temp->tipo=="helicoptero") {
		tempo_delay = 10;
	}
	else {
		tempo_delay = 50;
	}

	int w = hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->x;
	int s = hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->y;

	while (w != x || y != s) {
		blit_tela(screen,1);
		int dt = SDL_GetTicks() - lastdt;
		lastdt = SDL_GetTicks();

		if (w == x && s > y) {
			if (abs(y - s) == 1) {
				s = s - 1;
			}
			s = s - 2;
		}

		else if (w < x) {
			if(abs(w - x) == 1) {
				w = w + 1;
			}
			w = w + 2;
		}

		else if (w > x) {
			if(abs(w -y) == 1) {
				w = w -1;
			}
			w = w - 2;
		}

		if (s>y) {
			if (abs(y -s) == 1) {
				s = s - 1;
			}
			s = s - 2;
		}
		else if (s < y) {
			if(abs(y - s) == 1) {
				s = s + 1;
			}
			s = s + 2;
		}
		totalElapsedTime += dt;
		if (totalElapsedTime >= delay) {
			totalElapsedTime -= delay;
			if (cutBox.x == 0) {
				cutBox.x = 32;
			}
			else {
				cutBox.x -= 32;
			}
		}

		SDL_Rect dest = {(Sint16)w, (Sint16)s, 0, 0};
		if (hexagonos[hex_selecao->i_antes]
		    [hex_selecao->j_antes]->contem_unidade)
		{
			cout<<"WOLOLOLO"<<endl;
		}
		SDL_BlitSurface(temp->nome, &cutBox, screen, &dest);
		SDL_Delay(tempo_delay);
		SDL_Flip(screen);
	}
	hexagonos[hex_selecao->i][hex_selecao->j]->unidade = temp;
	hexagonos[hex_selecao->i][hex_selecao->j]->contem_unidade = 1;
}
