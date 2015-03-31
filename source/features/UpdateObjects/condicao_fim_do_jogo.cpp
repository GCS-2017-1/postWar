#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../../../include/draw.h"
#include "../../../include/video.h"
#include "../../../include/loop.h"
#include "../../../include/gamefeatures.h"

void verifica_derrota(SDL_Surface *screen)
{
	cout << "Entrei na condicao" << endl;
	Unidade *temp;
	string tipo = "quartel";
	for (unsigned int i = 0; i < hexagonos.size(); i++) {
		cout << "andando i: " << i << endl;
		for (unsigned int j = 0; j < hexagonos[i].size() ; j++) {
			cout << "andando j: " << j << endl;
			if (hexagonos[i][j]->contem_unidade == 1) {
				cout << "achei uma unidade" << endl;
				temp = hexagonos[i][j]->unidade;
				cout << "temp tipo:" << temp->tipo << endl;
				if (temp->tipo == tipo && temp->hp == 0) {
					string mensagem = "Você perdeu!LOSER!!";
					desenha_texto(mensagem, screen, 50, 50, 60);
				}
				else {
					break;
				}
			}
		}
	}
}
