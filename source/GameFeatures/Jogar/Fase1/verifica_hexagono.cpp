#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"
#include <math.h>

using namespace std;

/* verifies the hexagon models */
int verifica_hexagono(int x, int y)
{
	float vx, vy;
	float re=0;
	float x_f = (float) x;
	float y_f = (float) y;

	for (unsigned int i=0;i<hexagonos.size();i++) {
		for (unsigned int j=0;j<hexagonos[i].size();j++) {
			vx = abs(x_f - hexagonos[i][j]->center_in_x);
			vy = abs(y_f - hexagonos[i][j]->center_in_y);
			re = (vx*vx)+(vy*vy);
			re = sqrt(re);
			if (re <= 20) {
				hex_selecao->i = i;
				hex_selecao->j = j;
				return 1;
			}
			else {
				/* nothing to do */
			}
		}
	}
return 0;
}

/* verifies if theres a unit */
int possui_unidade(string color)
{
	if (hexagonos[hex_selecao->i][hex_selecao->j]->contains_unit) {
		if (!hexagonos[hex_selecao->i][hex_selecao->j]->unit->color.compare(color)) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

/* verifies the range of moving of a soldier */
int alcance_movimento_soldado()
{
	if ((abs(hex_selecao->j_before - hex_selecao->j) <= 1)
		 &&(abs(hex_selecao->i_before - hex_selecao -> i)  >0)
		 &&(abs(hex_selecao->i_before - hex_selecao->i) < 3)) {
		if ((abs(hex_selecao->i_before - hex_selecao->i) == 2)
			 &&(abs(hex_selecao->j_before - hex_selecao->j) == 1 )) {
			return 0;
		}
		else {
			/* nothing to do */
		}
		if (hexagonos[hex_selecao->i][hex_selecao->j]->contains_unit) {
			return 0;
		}
		else {
			/* nothing to do */
		}
		return 1;
	}
	else {
		return 0;
	}


}

/* verifies the range of the soldier's atack */
int alcance_ataque_soldado()
{
	if ((abs(hex_selecao->j_before - hex_selecao->j) <= 1)
		 &&(abs(hex_selecao->i_before - hex_selecao->i) > 0)
		 &&(abs(hex_selecao->i_before - hex_selecao->i) < 3)) {
		if ((abs(hex_selecao->i_before - hex_selecao->i) == 2)
			 &&(abs(hex_selecao->j_before - hex_selecao->j) == 1 )) {
			return 0;
		}
		else {
			/* nothing to do */
		}

		if (hexagonos[hex_selecao->i][hex_selecao->j]->contains_unit) {
			Unit *temp1 = hexagonos[hex_selecao->i_before][hex_selecao->j_before]->unit;
			Unit *temp2 = hexagonos[hex_selecao->i][hex_selecao->j]->unit;
			if (temp2->color != temp1->color) {
				return 1;
			}
			else {
				/* nothing to do */
			}
		}
		else {
			/* nothing to do */
		}

		return 0;
	}
	else {
		return 0;
	}

}
