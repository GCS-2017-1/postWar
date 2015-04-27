#include <SDL/SDL_ttf.h>
#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include "../../../include/draw.h"
#include "../../../include/gamefeatures.h"

void desenha_texto(string texto, SDL_Surface* screen, int x, int y, int size)
{
	char fonte[] = "atfantrg.ttf";
	TTF_Font *font = TTF_OpenFont(fonte, size);
	if (font == NULL) {
		cout << "Nao carreguei a fonte" << endl;
	}
	const char *txt = texto.c_str();
	SDL_Color unit_color;
	unit_color.r = red;
	unit_color.g = green;
	unit_color.b = blue;

	SDL_Surface *escrita = TTF_RenderText_Solid(font, txt, unit_color);
	SDL_Rect pos;
	pos.x = x;
	pos.y = y;
	SDL_BlitSurface(escrita, NULL, screen, &pos);
	TTF_CloseFont(font);
}
