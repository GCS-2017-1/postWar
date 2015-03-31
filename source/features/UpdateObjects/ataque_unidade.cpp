#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"
#include "../../../include/sound.h"

using namespace std;
char efeito_ataque;
Mix_Chunk *efeito_tiro_tanque;
Mix_Chunk *efeito_tiro_helicoptero;

void ataque_unidade(SDL_Surface *screen,
                    int x,
                    int y,
                    int totalElapsedTime,
                    int delay,
                    int lastdt)
{

	for (int i = 0; i < 5; i++) {
		string tipoquartel = "quartel";
		Unidade *temp;
		Unidade *temp_defensor;
		SDL_Surface *temp_s;
		SDL_Surface *temp_s2;
		int n_sprites = 0;
		int tamanho_sprites = 0;
		int n_sprites2 = 0;
		int tamanho_sprites2 = 0;


		int w = hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->x;
		int s = hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->y;
		int w_def = hexagonos[hex_selecao->i][hex_selecao->j]->x;
		int s_def = hexagonos[hex_selecao->i][hex_selecao->j]->y;


		if (hexagonos[hex_selecao->i_antes]
		    [hex_selecao->j_antes]->contem_unidade == 0)
		{
			break;
		}

		temp = hexagonos[hex_selecao->i_antes][hex_selecao->j_antes]->unidade;
		temp_defensor = hexagonos[hex_selecao->i][hex_selecao->j]->unidade;
		if (temp->tipo == tipoquartel) {
			cout << "Nao pode atacar" << endl;
			return;
		}
		string cor = "vermelho";
		string cor2 = "azul";
		string tipo = "metralhadora";
		string tipo2 = "soldado";
		string tipo3 = "helicoptero";
		string tipo4 = "tanque";

		SDL_Rect cutBox = {0,0,32,32};
		if (temp_defensor->tipo == tipo4 && temp_defensor->cor == cor2) {
			efeito_ataque = 't';
			n_sprites = 4;
			if (s_def < s && w_def == w) {
				temp_s2 = temp_defensor->ataque_baixo;
				cutBox.x = 0;
				cutBox.y = 0;
				cutBox.w = 32;
				cutBox.h = 32;

				tamanho_sprites = 32;
			}
			else if (s_def > s && w_def == w) {
				temp_s2 = temp_defensor->ataque_cima;
				cutBox.x = 0;
				cutBox.y = 32;
				cutBox.w = 32;
				cutBox.h = 32;

				tamanho_sprites = 32;
			}
			else {
				temp_s2 = temp_defensor->ataque;
				cutBox.x = 32;
				cutBox.y = 0;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 64;
			}
		}
		/* acha tanque vermelho */
		if (temp_defensor->tipo == tipo4 && temp_defensor->cor == cor) {
			efeito_ataque = 't';
			n_sprites = 4;
			if (s_def < s && w_def == w) {
				temp_s2 = temp_defensor->ataque_baixo;
				cutBox.x = 0;
				cutBox.y = 0;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 32;
			}
			else if (s_def > s && w_def == w) {
				temp_s2 = temp_defensor->ataque_cima;
				cutBox.x = 0;
				cutBox.y = 32;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 32;
			}
			else {
				temp_s2 = temp_defensor->ataque;
				cutBox.x = 0;
				cutBox.y = 0;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 64;
			}
		}
		/* acha helicoptero vermelho */
		if (temp_defensor->tipo == tipo3 && temp_defensor->cor == cor) {
			efeito_ataque = 'h';
			if (s_def < s && w_def == w) {
				temp_s2 = temp_defensor->ataque_baixo;
				cutBox.x = 0;
				cutBox.y = 0;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 32;
				n_sprites = 4;
			}
			else if (s_def > s && w_def == w) {
				temp_s2 = temp_defensor->ataque_cima;
				cutBox.x = 0;
				cutBox.y = 32;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 32;
				n_sprites = 4;
			}
			else {
				temp_s2 = temp_defensor->ataque;
				cutBox.x = 0;
				cutBox.y = 0;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 64;
				n_sprites = 7;
			}

		}
		/* acha helicoptero azul */
		if (temp_defensor->tipo == tipo3 && temp_defensor->cor == cor2) {
			efeito_ataque = 'h';
			cout << "Achei helicoptero azul" << endl;
			if (s_def < s && w_def == w) {
				temp_s2 = temp_defensor->ataque_baixo;
				cutBox.x = 0;
				cutBox.y = 0;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 32;
				n_sprites = 4;
			}
			else if (s_def > s && w_def == w) {
				temp_s2 = temp_defensor->ataque_cima;
				cutBox.x = 0;
				cutBox.y = 32;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 32;
				n_sprites = 4;
			}
			else {
				temp_s2 = temp_defensor->ataque;
				cutBox.x = 32;
				cutBox.y = 0;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 64;
				n_sprites = 9;
			}

		}
		/* acha metralhadora azul */
		if (temp_defensor->tipo == tipo && temp_defensor->cor == cor2) {
			efeito_ataque = 'm';
			temp_s2 = temp_defensor->ataque;
			cout << "Achei metralhadora" << endl;;
				cutBox.x = 64;
				cutBox.y = 0;
				cutBox.w = 64;
				cutBox.h = 64;
			tamanho_sprites = 64;
			n_sprites = 5;
		}
		/* acha metralhadora vermelha */
		if (temp_defensor->tipo == tipo && temp_defensor->cor == cor) {
			cout << "Achei metralhadora" << endl;
			temp_s2 = temp_defensor->ataque;
			cutBox.x = 0;
			cutBox.y = 0;
			cutBox.w = 64;
			cutBox.h = 64;
			tamanho_sprites = 64;
			n_sprites = 5;
		}
		/* acha soldado vermelho */
		if (temp_defensor->cor == cor && temp_defensor->tipo == tipo2) {
			efeito_ataque = 's';
			cout << "Achei vermelho" << endl;
			n_sprites = 5;
			if (s_def < s && w_def == w) {
				temp_s2 = temp_defensor->ataque_baixo;
				cutBox.x = 0;
				cutBox.y = 0;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 32;
			}
			else if (s_def > s && w_def == w) {
				temp_s2 = temp_defensor->ataque_cima;
				cutBox.x = 0;
				cutBox.y = 32;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 32;
			}
			else {
				temp_s2 = temp_defensor->ataque;
				cutBox.x = 0;
				cutBox.y = 0;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 64;
			}
		}

		/* acha soldado azul */
		if (temp_defensor->cor == cor2 && temp_defensor->tipo == tipo2) {
			efeito_ataque = 's';
			cout << "Achei azul" << endl;
			n_sprites = 5;
			if (s_def < s && w_def == w) {
				temp_s2 = temp_defensor->ataque_baixo;
				cutBox.x = 0;
				cutBox.y = 0;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 32;
			}
			else if (s_def > s && w_def == w) {
				temp_s2 = temp_defensor->ataque_cima;
				cutBox.x = 0;
				cutBox.y = 32;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 32;
			}
			else {
				temp_s2 = temp_defensor->ataque;
				cutBox.x = 32;
				cutBox.y = 0;
				cutBox.w = 32;
				cutBox.h = 32;
				tamanho_sprites = 64;
			}
		}
		SDL_Rect cutBox2 = {0, 0, 32, 32};

		/* acha tanque azul */
		if (temp->tipo == tipo4 && temp->cor == cor2) {
			efeito_ataque = 't';
			n_sprites2 = 4;
			if (s < y && w == x) {
				temp_s = temp->ataque_baixo;
				cutBox2.x = 0;
				cutBox2.y = 0;
				cutBox2.w = 32;
				cutBox2.h = 32;

				tamanho_sprites2 = 32;
			}
			else if (s > y && w == x) {
				temp_s = temp->ataque_cima;
				cutBox2.x = 0;
				cutBox2.y = 32;
				cutBox2.w = 32;
				cutBox2.h = 32;

				tamanho_sprites2 = 32;
			}
			else {
				temp_s = temp->ataque;
				cutBox2.x = 32;
				cutBox2.y = 0;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 64;
			}
		}
		/* acha tanque vermelho */
		if (temp->tipo == tipo4 && temp->cor == cor) {
			efeito_ataque = 't';
			n_sprites2 = 4;
			if (s < y && w == x) {
				temp_s = temp->ataque_baixo;
				cutBox2.x = 0;
				cutBox2.y = 0;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 32;
			}
			else if (s > y && w == x) {
				temp_s = temp->ataque_cima;
				cutBox2.x = 0;
				cutBox2.y = 32;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 32;
			}
			else {
				temp_s = temp->ataque;
				cutBox2.x = 0;
				cutBox2.y = 0;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 64;
			}
		}
		/* acha helicoptero vermelho */
		if (temp->tipo == tipo3 && temp->cor == cor) {
			efeito_ataque = 'h';
			if (s < y && w == x) {
				temp_s = temp->ataque_baixo;
				cutBox2.x = 0;
				cutBox2.y = 0;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 32;
				n_sprites2 = 4;
			}
			else if (s > y && w == x) {
				temp_s = temp->ataque_cima;
				cutBox2.x = 0;
				cutBox2.y = 32;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 32;
				n_sprites2 = 4;
			}
			else {
				temp_s = temp->ataque;
				cutBox2.x = 0;
				cutBox2.y = 0;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 64;
				n_sprites2 = 7;
			}
		}
		/* acha helicoptero azul */
		if (temp->tipo == tipo3 && temp->cor == cor2) {
			cout << "Achei helicoptero azul" << endl;
			if (s < y && w == x) {
				temp_s = temp->ataque_baixo;
				cutBox2.x = 0;
				cutBox2.y = 0;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 32;
				n_sprites2 = 4;
			}
			else if (s > y && w == x) {
				temp_s = temp->ataque_cima;
				cutBox2.x = 0;
				cutBox2.y = 32;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 32;
				n_sprites2 = 4;
			}
			else {
				temp_s = temp->ataque;
				cutBox2.x = 32;
				cutBox2.y = 0;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 64;
				n_sprites2 = 9;
			}

		}
		/* acha metralhadora azul */
		if (temp->tipo == tipo && temp->cor == cor2) {
			efeito_ataque = 'm';
			temp_s = temp->ataque;
			cutBox2.x = 64;
			cutBox2.y = 0;
			cutBox2.w = 64;
			cutBox2.h = 64;
			tamanho_sprites2 = 64;
			n_sprites2 = 5;
		}
		/* acha metralhadora vermelha */
		if (temp->tipo == tipo && temp->cor == cor) {
			efeito_ataque = 'm';
			cout << "Achei metralhadora" << endl;
			temp_s = temp->ataque;
			cutBox2.x = 0;
			cutBox2.y = 0;
			cutBox2.w = 64;
			cutBox2.h = 64;
			tamanho_sprites2 = 64;
			n_sprites2 = 5;
		}
		/* acha soldado vermelho */
		if (temp->cor == cor && temp->tipo == tipo2) {
			efeito_ataque = 's';
			cout << "Achei vermelho" << endl;
			n_sprites2 = 5;
			if (s < y && w == x) {
				temp_s = temp->ataque_baixo;
				cutBox2.x = 0;
				cutBox2.y = 0;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 32;
			}
			else if (s > y && w == x) {
				temp_s = temp->ataque_cima;
				cutBox2.x = 0;
				cutBox2.y = 32;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 32;
			}
			else {
				temp_s = temp->ataque;
				cutBox2.x = 0;
				cutBox2.y = 0;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 64;
			}
		}

		/* acha soldado azul */
		if (temp->cor == cor2 && temp->tipo == tipo2) {
			efeito_ataque = 's';
			cout << "Achei azul" << endl;
			n_sprites2 = 5;
			if (s < y && w == x) {
				temp_s = temp->ataque_baixo;
				cutBox2.x = 0;
				cutBox2.y = 0;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 32;
			}
			else if (s > y && w == x) {
				temp_s = temp->ataque_cima;
				cutBox2.x = 0;
				cutBox2.y = 32;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 32;
			}
			else {
				temp_s = temp->ataque;
				cutBox2.x = 32;
				cutBox2.y = 0;
				cutBox2.w = 32;
				cutBox2.h = 32;
				tamanho_sprites2 = 64;
			}
		}


		int tempo_delay = 50;

		while((cutBox.x <n_sprites * tamanho_sprites) &&
		      (cutBox2.x <n_sprites2*tamanho_sprites2))
		{
			blit_tela_ataque(screen, 1, temp_defensor->id, w, s);
			blit_tela_ataque(screen, 1, temp->id, x, y);

			int dt = SDL_GetTicks() - lastdt;
			lastdt = SDL_GetTicks();

			totalElapsedTime += dt;

			if (totalElapsedTime >= delay) {
				totalElapsedTime -= delay;
				cutBox.x += tamanho_sprites;
				cutBox2.x += tamanho_sprites2;
			}

			switch(efeito_ataque) {
				case 's':
					play_effect(efeito_tiro_soldado);
					break;
				case 'm':
					play_effect(efeito_metralhadora);
					break;
				case 't':
					play_effect(efeito_tiro_tanque);
					break;
				case 'h':
					play_effect(efeito_tiro_helicoptero);
					break;
			}

			SDL_Rect dest = {(Sint16)w, (Sint16)s, 0, 0};
			SDL_Rect dest2 = {(Sint16)w_def, (Sint16)s_def, 0, 0};

			SDL_BlitSurface(temp_s, &cutBox2, screen, &dest);
			SDL_BlitSurface(temp_s2, &cutBox, screen, &dest2);

			SDL_Delay(tempo_delay);

			SDL_Flip(screen);
		}
	}
}
