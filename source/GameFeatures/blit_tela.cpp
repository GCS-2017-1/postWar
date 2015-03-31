#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../include/draw.h"
#include "../../include/video.h"
#include "../../include/loop.h"
#include "../../include/gamefeatures.h"

using namespace std;

void blit_tela(SDL_Surface *screen, int tela)
{
	if (tela == 0) {
		BlitImage(screen, sem_malha, 0, 0);
	}
	else {
		BlitImage(screen, com_malha, 0, 0);
	}
	BlitImage(screen, hud, 0, 0);
	BlitImage(screen, menu_meio, 568, 78);
	/*
	 * string bora;
	 * string bora1;
	 * for (int i = 0; i < hexagonos.size(); i++) {
	 *		for (int j = 0; j < hexagonos[i].size(); j++) {
	 *			int start4 = SDL_GetTicks();
	 *			bora[0] += i;
	 *			bora1[0] += j;
	 *			cout << "bora: " << bora1 << endl;
	 *			desenha_texto(bora,
	 *                        screen,
	 *                        hexagonos[i][j]->x,
	 *                        hexagonos[i][j]->y,
	 *                        20);
	 *			desenha_texto(bora1,
	 *                        screen,
	 *                        hexagonos[i][j]->x + 10,
	 *                        hexagonos[i][j]->y,
	 *                        20);
	 *			bora = "0";
	 *			bora1 = "0";
	 *			frame_delay(start4);
	 *		}
	 *  }
	 */

	/*
	 * int i_menor;
	 * int j_menor;
	 * Unidade *unit;
	 * int aux=0;
	 */
	for (unsigned int i = 0; i < hexagonos.size(); i++) {
		for (unsigned int j=0; j<hexagonos[i].size(); j++) {
			if (hexagonos[i][j]->contem_unidade == 1) {
				if (hexagonos[i][j]->unidade->tipo == "soldado" ||
				    hexagonos[i][j]->unidade->tipo == "helicoptero" ||
				    hexagonos[i][j]->unidade->tipo == "tanque")
				{
					SDL_Rect cutBox = {32, 0, 32, 32};
					SDL_Rect dst;
					dst.x = hexagonos[i][j]->x;
					dst.y = hexagonos[i][j]->y;
					dst.h = 0;
					dst.w = 0;
					SDL_BlitSurface(hexagonos[i][j]->unidade->nome,
					                &cutBox,
					                screen,
					                &dst);
				}
				else if (hexagonos[i][j]->unidade->tipo == "quartel" &&
				        hexagonos[i][j]->unidade->cor == "vermelho")
				{
					BlitImage(screen,
					          hexagonos[6][1]->unidade->nome,
					          hexagonos[6][1]->x,
					          hexagonos[6][1]->y);
				}
				else if (hexagonos[i][j]->unidade->tipo == "quartel" &&
				         hexagonos[i][j]->unidade->cor == "azul")
				{
					BlitImage(screen,
					          hexagonos[7][13]->unidade->nome,
					          hexagonos[7][13]->x,
					          hexagonos[7][13]->y);
				}
				else {
					if (hexagonos[6][4]->contem_unidade) {
						BlitImage(screen,hexagonos[6][4]->unidade->nome,
						          hexagonos[6][4]->x,
						          hexagonos[6][4]->y);
					}
					//BlitImage(screen,hexagonos[14][12]->unidade->nome,hexagonos[14][12]->x,hexagonos[14][12]->y);
					if (hexagonos[10][12]->contem_unidade) {
						BlitImage(screen,hexagonos[10][12]->unidade->nome,
						          hexagonos[10][12]->x,
						          hexagonos[10][12]->y);
					}
					if (hexagonos[2][13]->contem_unidade) {
						BlitImage(screen,hexagonos[2][13]->unidade->nome,
						          hexagonos[2][13]->x,
						          hexagonos[2][13]->y);
					}
				}
			}
			//BlitImage(screen, hexagonos[2][8]->construcao->nome, hexagonos[2][8]->x, hexagonos[2][8]->y);
		}
	}
}

void blit_tela_ataque(SDL_Surface *screen, int tela, int id, int x, int y)
{
	/*
	 * cout << "ENTREI BLIT ATAQUE" << endl;
	 * cout << "FUNCAO BLITE ATAQUE:" << endl;
	 * cout << "x:" << x << endl;
	 * cout << "y:" << y << endl;
	 */
	if (tela == 0) {
		BlitImage(screen, sem_malha, 0, 0);
	}
	else {
		BlitImage(screen, com_malha, 0, 0);
	}

	BlitImage(screen, hud, 0, 0);

	for (unsigned int i = 0; i < hexagonos.size(); i++) {
		for (unsigned int j = 0; j < hexagonos[i].size(); j++) {

			if (hexagonos[i][j]->contem_unidade == 1) {
				/*
				 * cout << "foi, i: " << i << "j: " << j << endl;
				 * cout << "cheguei aqui" << endl;
				 * cout << "unidade ID:"
				 *		<<	hexagonos[i][j]->unidade->id
				 *		<<	endl;
				 * cout << "x e y aponta para:"
				 *      << hexagonos[x][y]->unidade
				 *      << endl;
				 * cout << "unidade tipo:"
				 *      << hexagonos[hex_selecao->i_antes]
				 *      			[hex_selecao->j_antes]->unidade->tipo
				 *      << endl;
				 */
				if (hexagonos[i][j]->unidade->id == id) {
					/* cout << "entrei if" << endl; */
					int w = hexagonos[hex_selecao->i_antes]
					                 [hex_selecao->j_antes]->unidade->x;
					int s = hexagonos[hex_selecao->i_antes]
					                 [hex_selecao->j_antes]->unidade->y;
					Unidade *temp;
					temp = hexagonos[hex_selecao->i_antes]
					                [hex_selecao->j_antes]->unidade;
					/* cout << "temp:" << temp->tipo << endl; */
					SDL_Surface *temp_s;
					string cor = "vermelho";
					string cor2 = "azul";
					string tipo = "metralhadora";
					string tipo2 = "soldado";
					string tipo3 = "helicoptero";
					string tipo4 = "tanque";
					/* cout << "cor da unidade atual:" << temp->cor << endl; */
					/* cout << "Tipo unidade atual:" << temp->tipo << endl; */

					SDL_Rect cutBox = {0, 0, 32, 32};
					/* acha tanque azul */
					if (temp->tipo == tipo4 && temp->cor == cor2) {
						if (s < y && w == x) {
							temp_s = temp->ataque_baixo;
							cutBox.x = 0;
							cutBox.y = 0;
							cutBox.w = 32;
							cutBox.h = 32;
						}
						else if (s > y && w == x) {
							temp_s = temp->ataque_cima;
							cutBox.x = 0;
							cutBox.y = 32;
							cutBox.w = 32;
							cutBox.h = 32;
						}
						else {
							temp_s = temp->ataque;
							cutBox.x = 32;
							cutBox.y = 0;
							cutBox.w = 32;
							cutBox.h = 32;
						}
					}
					/* acha tanque vermelho */
					if (temp->tipo == tipo4 && temp->cor == cor) {
						if (s < y && w == x){
							temp_s = temp->ataque_baixo;
							cutBox.x = 0;
							cutBox.y = 0;
							cutBox.w = 32;
							cutBox.h = 32;
						}
						else if (s > y && w == x) {
							temp_s = temp->ataque_cima;
							cutBox.x = 0;
							cutBox.y = 32;
							cutBox.w = 32;
							cutBox.h = 32;
						}
						else {
							temp_s = temp->ataque;
							cutBox.x = 32;
							cutBox.y = 0;
							cutBox.w = 32;
							cutBox.h = 32;
						}
					}
					/* acha helicoptero vermelho */
					if (temp->tipo == tipo3 && temp->cor == cor) {
					/* por enquanto nunca vai achar, hu3 */
					}
					/* acha helicoptero azul */
					if (temp->tipo == tipo3 && temp->cor == cor2) {
						if (s < y && w == x) {
							temp_s = temp->ataque_baixo;
							cutBox.x = 0;
							cutBox.y = 0;
							cutBox.w = 32;
							cutBox.h = 32;
						}
						else if (s > y && w == x) {
							temp_s = temp->ataque_cima;
							cutBox.x = 0;
							cutBox.y = 32;
							cutBox.w = 32;
							cutBox.h = 32;
						}
						else {
							temp_s = temp->ataque;
							cutBox.x = 32;
							cutBox.y = 0;
							cutBox.w = 32;
							cutBox.h = 32;
						}
						SDL_Rect dst = {(Sint16)w, (Sint16)s, 0, 0};
						SDL_BlitSurface(temp_s, &cutBox,  screen, &dst);

					}

				}

				if ((hexagonos[i][j]->unidade->tipo == "soldado" ||
				      hexagonos[i][j]->unidade->tipo == "helicoptero" ||
				      hexagonos[i][j]->unidade->tipo == "tanque") &&
				 	 (hexagonos[i][j]->unidade->id != id))
				{
					SDL_Rect cutBox = {32, 0, 32, 32};
					SDL_Rect dst;
					dst.x = hexagonos[i][j]->x;
					dst.y = hexagonos[i][j]->y;
					dst.h = 0;
					dst.w = 0;
					/* cout << "fiz isso i " << i << endl; */

					SDL_BlitSurface(hexagonos[i][j]->unidade->nome,
					                &cutBox,
					                screen,
					                &dst);
				}
				else if (hexagonos[i][j]->unidade->tipo == "quartel" &&
				         hexagonos[i][j]->unidade->cor == "vermelho")
				{
					BlitImage(screen,
					          hexagonos[6][1]->unidade->nome,
					          hexagonos[6][1]->x,
					          hexagonos[6][1]->y);
				}
				else if (hexagonos[i][j]->unidade->tipo == "quartel" &&
				         hexagonos[i][j]->unidade->cor == "azul")
				{
					if (hexagonos[7][13]->contem_unidade) {
						BlitImage(screen,
						          hexagonos[7][13]->unidade->nome,
						          hexagonos[7][13]->x,
						          hexagonos[7][13]->y);
					}
				}
				else {
					if (hexagonos[6][4]->contem_unidade) {
						BlitImage(screen,
						          hexagonos[6][4]->unidade->nome,
						          hexagonos[6][4]->x,
						          hexagonos[6][4]->y);
					}
					//BlitImage(screen,hexagonos[14][12]->unidade->nome,hexagonos[14][12]->x,hexagonos[14][12]->y);
					if (hexagonos[10][12]->contem_unidade) {
						BlitImage(screen,
						          hexagonos[10][12]->unidade->nome,
						          hexagonos[10][12]->x,
						          hexagonos[10][12]->y);
					}
				}



				/*
				 * else if (hexagonos[i][j]->unidade->tipo == "quartel") {
				 *     BlitImage(screen,
				 *	             hexagonos[6][1]->unidade->nome,
				 *	             hexagonos[6][1]->x,
				 *	             hexagonos[6][1]->y);
				 * }
				 *
				 * // Lógica mágica para dar blit na metralhadora
				 * else {
				 *	   if (aux == 0){
				 *	       aux = 1;
				 *		   unit = hexagonos[i][j]->unidade;
				 *		   i_menor = i;
				 *		   j_menor = j;
				 *		   BlitImage(screen,
				 *		             hexagonos[i][j]->unidade->nome,
				 *		             hexagonos[i][j]->x,
				 *		             hexagonos[i][j]->y);
				 *	    }
				 * }
				 */
			}
		}
	}
}
