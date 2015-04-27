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
	 * Unit *unit;
	 * int aux=0;
	 */
	for (unsigned int i = 0; i < hexagonos.size(); i++) {
		for (unsigned int j=0; j<hexagonos[i].size(); j++) {
			if (hexagonos[i][j]->contem_unidade == 1) {
				if (hexagonos[i][j]->unidade->unit_type == "soldado" ||
				    hexagonos[i][j]->unidade->unit_type == "helicoptero" ||
				    hexagonos[i][j]->unidade->unit_type == "tanque")
				{
					SDL_Rect cutBox = {32, 0, 32, 32};
					SDL_Rect dst;
					dst.x = hexagonos[i][j]->x;
					dst.y = hexagonos[i][j]->y;
					dst.h = 0;
					dst.w = 0;
					SDL_BlitSurface(hexagonos[i][j]->unidade->unit_name,
					                &cutBox,
					                screen,
					                &dst);
				}
				else if (hexagonos[i][j]->unidade->unit_type == "quartel" &&
				        hexagonos[i][j]->unidade->unit_color == "vermelho")
				{
					BlitImage(screen,
					          hexagonos[6][1]->unidade->unit_name,
					          hexagonos[6][1]->x,
					          hexagonos[6][1]->y);
				}
				else if (hexagonos[i][j]->unidade->unit_type == "quartel" &&
				         hexagonos[i][j]->unidade->unit_color == "azul")
				{
					BlitImage(screen,
					          hexagonos[7][13]->unidade->unit_name,
					          hexagonos[7][13]->x,
					          hexagonos[7][13]->y);
				}
				else {
					if (hexagonos[6][4]->contem_unidade) {
						BlitImage(screen,hexagonos[6][4]->unidade->unit_name,
						          hexagonos[6][4]->x,
						          hexagonos[6][4]->y);
					}
					//BlitImage(screen,hexagonos[14][12]->unidade->unit_name,hexagonos[14][12]->x,hexagonos[14][12]->y);
					if (hexagonos[10][12]->contem_unidade) {
						BlitImage(screen,hexagonos[10][12]->unidade->unit_name,
						          hexagonos[10][12]->x,
						          hexagonos[10][12]->y);
					}
					if (hexagonos[2][13]->contem_unidade) {
						BlitImage(screen,hexagonos[2][13]->unidade->unit_name,
						          hexagonos[2][13]->x,
						          hexagonos[2][13]->y);
					}
				}
			}
			//BlitImage(screen, hexagonos[2][8]->construcao->unit_name, hexagonos[2][8]->x, hexagonos[2][8]->y);
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
				 * cout << "unidade unit_type:"
				 *      << hexagonos[hex_selecao->i_antes]
				 *      			[hex_selecao->j_antes]->unidade->unit_type
				 *      << endl;
				 */
				if (hexagonos[i][j]->unidade->id == id) {
					/* cout << "entrei if" << endl; */
					int w = hexagonos[hex_selecao->i_antes]
					                 [hex_selecao->j_antes]->unidade->x;
					int s = hexagonos[hex_selecao->i_antes]
					                 [hex_selecao->j_antes]->unidade->y;
					Unit *temp;
					temp = hexagonos[hex_selecao->i_antes]
					                [hex_selecao->j_antes]->unidade;
					/* cout << "temp:" << temp->unit_type << endl; */
					SDL_Surface *temp_s;
					string unit_color = "vermelho";
					string cor2 = "azul";
					string unit_type = "metralhadora";
					string tipo2 = "soldado";
					string tipo3 = "helicoptero";
					string tipo4 = "tanque";
					/* cout << "unit_color da unidade atual:" << temp->unit_color << endl; */
					/* cout << "Tipo unidade atual:" << temp->unit_type << endl; */

					SDL_Rect cutBox = {0, 0, 32, 32};
					/* acha tanque azul */
					if (temp->unit_type == tipo4 && temp->unit_color == cor2) {
						if (s < y && w == x) {
							temp_s = temp->down_attack;
							cutBox.x = 0;
							cutBox.y = 0;
							cutBox.w = 32;
							cutBox.h = 32;
						}
						else if (s > y && w == x) {
							temp_s = temp->up_attack;
							cutBox.x = 0;
							cutBox.y = 32;
							cutBox.w = 32;
							cutBox.h = 32;
						}
						else {
							temp_s = temp->attack;
							cutBox.x = 32;
							cutBox.y = 0;
							cutBox.w = 32;
							cutBox.h = 32;
						}
					}
					/* acha tanque vermelho */
					if (temp->unit_type == tipo4 && temp->unit_color == unit_color) {
						if (s < y && w == x){
							temp_s = temp->down_attack;
							cutBox.x = 0;
							cutBox.y = 0;
							cutBox.w = 32;
							cutBox.h = 32;
						}
						else if (s > y && w == x) {
							temp_s = temp->up_attack;
							cutBox.x = 0;
							cutBox.y = 32;
							cutBox.w = 32;
							cutBox.h = 32;
						}
						else {
							temp_s = temp->attack;
							cutBox.x = 32;
							cutBox.y = 0;
							cutBox.w = 32;
							cutBox.h = 32;
						}
					}
					/* acha helicoptero vermelho */
					if (temp->unit_type == tipo3 && temp->unit_color == unit_color) {
					/* por enquanto nunca vai achar, hu3 */
					}
					/* acha helicoptero azul */
					if (temp->unit_type == tipo3 && temp->unit_color == cor2) {
						if (s < y && w == x) {
							temp_s = temp->down_attack;
							cutBox.x = 0;
							cutBox.y = 0;
							cutBox.w = 32;
							cutBox.h = 32;
						}
						else if (s > y && w == x) {
							temp_s = temp->up_attack;
							cutBox.x = 0;
							cutBox.y = 32;
							cutBox.w = 32;
							cutBox.h = 32;
						}
						else {
							temp_s = temp->attack;
							cutBox.x = 32;
							cutBox.y = 0;
							cutBox.w = 32;
							cutBox.h = 32;
						}
						SDL_Rect dst = {(Sint16)w, (Sint16)s, 0, 0};
						SDL_BlitSurface(temp_s, &cutBox,  screen, &dst);

					}

				}

				if ((hexagonos[i][j]->unidade->unit_type == "soldado" ||
				      hexagonos[i][j]->unidade->unit_type == "helicoptero" ||
				      hexagonos[i][j]->unidade->unit_type == "tanque") &&
				 	 (hexagonos[i][j]->unidade->id != id))
				{
					SDL_Rect cutBox = {32, 0, 32, 32};
					SDL_Rect dst;
					dst.x = hexagonos[i][j]->x;
					dst.y = hexagonos[i][j]->y;
					dst.h = 0;
					dst.w = 0;
					/* cout << "fiz isso i " << i << endl; */

					SDL_BlitSurface(hexagonos[i][j]->unidade->unit_name,
					                &cutBox,
					                screen,
					                &dst);
				}
				else if (hexagonos[i][j]->unidade->unit_type == "quartel" &&
				         hexagonos[i][j]->unidade->unit_color == "vermelho")
				{
					BlitImage(screen,
					          hexagonos[6][1]->unidade->unit_name,
					          hexagonos[6][1]->x,
					          hexagonos[6][1]->y);
				}
				else if (hexagonos[i][j]->unidade->unit_type == "quartel" &&
				         hexagonos[i][j]->unidade->unit_color == "azul")
				{
					if (hexagonos[7][13]->contem_unidade) {
						BlitImage(screen,
						          hexagonos[7][13]->unidade->unit_name,
						          hexagonos[7][13]->x,
						          hexagonos[7][13]->y);
					}
				}
				else {
					if (hexagonos[6][4]->contem_unidade) {
						BlitImage(screen,
						          hexagonos[6][4]->unidade->unit_name,
						          hexagonos[6][4]->x,
						          hexagonos[6][4]->y);
					}
					//BlitImage(screen,hexagonos[14][12]->unidade->unit_name,hexagonos[14][12]->x,hexagonos[14][12]->y);
					if (hexagonos[10][12]->contem_unidade) {
						BlitImage(screen,
						          hexagonos[10][12]->unidade->unit_name,
						          hexagonos[10][12]->x,
						          hexagonos[10][12]->y);
					}
				}



				/*
				 * else if (hexagonos[i][j]->unidade->unit_type == "quartel") {
				 *     BlitImage(screen,
				 *	             hexagonos[6][1]->unidade->unit_name,
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
				 *		             hexagonos[i][j]->unidade->unit_name,
				 *		             hexagonos[i][j]->x,
				 *		             hexagonos[i][j]->y);
				 *	    }
				 * }
				 */
			}
		}
	}
}
