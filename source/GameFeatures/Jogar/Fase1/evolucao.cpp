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

SDL_Surface *screen;
SDL_Surface *nome1;

/* describes the soldier evolution */
void evolucao_soldado(Pais *pais)
{
	pais->gold_coins -= 30;
	if (pais->gold_coins < 0) {
		return;
	}
	else {
		/* nothing to do */
	}
	pais->minerals -= 50;
	if (pais->minerals < 0) {
		return;
	}
	else {
		/* nothing to do */
	}
	pais->food -= 20;
	if (pais->food <0) {
		return;
	}
	else {
		/* nothing to do */
	}
	for (unsigned int i=0;i<hexagonos.size();i++) {
		for (unsigned int j=0;j<hexagonos[i].size();j++) {
			if (hexagonos[i][j]->contem_unidade==1) {
				if (hexagonos[i][j]->unidade->unit_color == pais->unit_color) {
					if (hexagonos[i][j]->unidade->unit_type == "soldado") {
						hexagonos[i][j]->unidade->health_points = 250;
						hexagonos[i][j]->unidade->attack_points = 150;
						hexagonos[i][j]->unidade->deffense_points = 150;
					}
					else {
						/* nothing to do */
					}
				}
				else {
					/* nothing to do */
				}
			}
			else {
				/* nothing to do */
			}
		}
	}
}

/* describes the evolution of the quartel */
void evolucao_quartel(Pais *pais)
{
	pais->gold_coins -= 50;
	if (pais->gold_coins < 0) {
		return;
	}
	else {
		/* nothing to do */
	}
	pais->minerals -= 50;
	if (pais->minerals < 0) {
		return;
	}
	else {
		/* nothing to do */
	}
	pais->food -= 40;
	if (pais->food <0) {
		return;
	}
	else {
		/* nothing to do */
	}
	for (unsigned int i=0;i<hexagonos.size();i++) {
		for (unsigned int j=0;j<hexagonos[i].size();j++) {
			if (hexagonos[i][j]->contem_unidade==1) {
				if (hexagonos[i][j]->unidade->unit_color == pais->unit_color) {
					if (hexagonos[i][j]->unidade->unit_type == "quartel") {
						if (hexagonos[i][j]->unidade->unit_color == "azul") {
							string caminho = "source/GameFeatures/Jogar/Fase1/images/bryjstudios_quartel_azul.png";
							nome1 = load_Image(caminho, screen);
						}
						else {
							string caminho = "source/GameFeatures/Jogar/Fase1/images/bryjstudios_quartel_vermelho.png";
							nome1 = load_Image(caminho, screen);
						}
						hexagonos[i][j]->unidade->health_points = 1250;
						hexagonos[i][j]->unidade->attack_points = 0;
						hexagonos[i][j]->unidade->deffense_points = 500;
						hexagonos[i][j]->unidade->unit_name = nome1;
					}
					else {
					   /* nothing to do */
					}
				}
				else {
				   /* nothing to do */
				}
			}
			else {
			   /* nothing to do */
			}
		}
	}
}
