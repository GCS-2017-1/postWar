#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <cstdio>
#include <string.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"

using namespace std;
SDL_Rect cutBox;

void setar_soldado(Unit *soldado,
				   string unit_color,
				   string unit_type,
				   SDL_Surface *unit_name,
				   SDL_Surface *attack,
				   SDL_Surface *down_attack,
				   SDL_Surface *up_attack,
				   SDL_Surface *soldado_lateral,
				   int id)
{
	soldado->health_points = 200;
	soldado->attack_points = 100;
	soldado->deffense_points = 100;
	soldado->attack_range = 1;
	soldado->gold_coins = 100;
	soldado->unit_color = unit_color;
	soldado->unit_name = unit_name;
	soldado->attack = attack;
	soldado->down_attack = down_attack;
	soldado->up_attack = up_attack;
	soldado->unit_type = unit_type;
	soldado->lateral_image = soldado_lateral;
	soldado->id = id;
}

void setar_helicoptero(Unit *helicoptero,
					   string unit_color,
					   string unit_type,
					   SDL_Surface *unit_name,
					   SDL_Surface *attack,
					   SDL_Surface *down_attack,
					   SDL_Surface *up_attack,
					   SDL_Surface *helicoptero_lateral,
					   int id)
{
	helicoptero->health_points = 300;
	helicoptero->attack_points = 500;
	helicoptero->deffense_points = 200;
	helicoptero->attack_range = 4;
	helicoptero->gold_coins = 400;
	helicoptero->unit_color = unit_color;
	helicoptero->unit_name = unit_name;
	helicoptero->attack = attack;
	helicoptero->down_attack = down_attack;
	helicoptero->up_attack = up_attack;
	helicoptero->unit_type = unit_type;
	helicoptero->lateral_image = helicoptero_lateral;
	helicoptero->id = id;
}

void setar_metralhadora(Unit *metralhadora,
						string unit_color,
						string unit_type,
						SDL_Surface *unit_name,
						SDL_Surface *attack,
						SDL_Surface *lateral,
						int id)
{
	metralhadora->health_points = 100;
	metralhadora->attack_points = 200;
	metralhadora->deffense_points = 300;
	metralhadora->attack_range = 3;
	metralhadora->gold_coins = 200;
	metralhadora->unit_color = unit_color;
	metralhadora->unit_name = unit_name;
	metralhadora->attack = attack;
	metralhadora->down_attack = attack;
	metralhadora->up_attack = attack;
	metralhadora->unit_type = unit_type;
	metralhadora->lateral_image = lateral;
	metralhadora->id = id;
}

void setar_tanque(Unit *tanque,
				  string unit_color,
				  string unit_type,
				  SDL_Surface *unit_name,
				  SDL_Surface *attack,
				  SDL_Surface *down_attack,
				  SDL_Surface *up_attack,
				  SDL_Surface *tanque_lateral,
				  int id)
{
	tanque->health_points = 350;
	tanque->attack_points = 400;
	tanque->deffense_points = 400;
	tanque->attack_range = 2;
	tanque->gold_coins = 300;
	tanque->unit_color = unit_color;
	tanque->unit_name = unit_name;
	tanque->attack = attack;
	tanque->down_attack = down_attack;
	tanque->up_attack = up_attack;
	tanque->unit_type = unit_type;
	tanque->lateral_image = tanque_lateral;
	tanque->id = id;
}

void setar_quartel(Unit *quartel,
				   string unit_color,
				   string unit_type,
				   SDL_Surface *unit_name,
				   SDL_Surface *attack,
				   SDL_Surface *lateral,
				   int id)
{
	quartel->health_points = 1;
	quartel->attack_points = 0;
	quartel->deffense_points = 400;
	quartel->attack_range = 0;
	quartel->gold_coins = 0;
	quartel->unit_color = unit_color;
	quartel->unit_name = unit_name;
	quartel->attack = attack;
	quartel->down_attack = attack;
	quartel->up_attack = attack;
	quartel->unit_type = unit_type;
	quartel->lateral_image = lateral;
	quartel->id = id;
}

void setar_pais(Pais *pais,
				int gold_coins,
				int food,
				int minerals,
				string unit_name,
				string unit_color)
{
	pais->gold_coins = gold_coins;
	pais->food = food;
	pais->minerals = minerals;
	pais->unit_name = unit_name;
	pais->unit_color = unit_color;
}
void setar_construcao(Building *construcao,
					  SDL_Surface *unit_name,
					  string unit_type,
					  int profit,
					  int conquered)
{
	construcao->unit_name = unit_name;
	construcao->unit_type = unit_type;
	construcao->profit = profit;
	construcao->conquered = conquered;
}

void carrega_construcoes(SDL_Surface *screen)
{

	if (screen) {
	}
	else {
		/* nothing to do */
	}
	/*Building *construcao = new Building();
	string unit_type = "mina";
	int profit = 20;
	int conquered = 0;
	string caminho = "source/GameFeatures/Jogar/Fase1/images/mina_de_ouro.png";
	SDL_Surface *mina = load_Image(caminho, screen);
	setar_construcao(construcao, mina, unit_type, profit, conquered);

	//SDL_BlitSurface(mina, &cutBox,  screen, &dst);
	BlitImage(screen,mina,hexagonos[2][8]->x,hexagonos[2][8]->y);
	hexagonos[2][8]->construcao = construcao;
	hexagonos[2][8]->mina = 1;*/

}

void carrega_china(SDL_Surface *screen)
{

	string lado1("servidor");
	string unit_color = "vermelho";

	for (int i=0, j=1;i<10;i++,j+=30) {

		string caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_vermelho.png";
		SDL_Surface *soldado1 = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_vermelho_ataque.png";
		SDL_Surface *ataque_soldado = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_vermelho_ataque_baixo.png";
		SDL_Surface *down_attack = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_vermelho_ataque_cima.png";
		SDL_Surface *up_attack = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_lateral_vermelho.png";
		SDL_Surface *soldado_lateral_a= load_Image(caminho, screen);
		Unit *soldado = new Unit();

		string unidadea1 = "soldado";
		setar_soldado(soldado, unit_color, unidadea1, soldado1, ataque_soldado, down_attack, up_attack,soldado_lateral_a, id);
		id++;
		unidades_azul.push_back(soldado);
		//if(i+2<=hexagonos.size()){
		SDL_Rect dst;
		dst.x = hexagonos[i*2][3]->x;
		dst.y = hexagonos[i*2][3]->y;
		dst.h = 0;
		dst.w = 0;
		SDL_BlitSurface(unidades_azul[i]->unit_name, &cutBox,  screen, &dst);
		hexagonos[i*2][3]->unidade = unidades_azul[i];
		hexagonos[i*2][3]->contem_unidade = 1;


		caminho = "source/GameFeatures/Jogar/Fase1/images/bryjstudios_cabana_vermelha.png";
		SDL_Surface *quartel_azul_cabana = load_Image(caminho, screen);
		Unit *quartel_a = new Unit();
		string quarte = "quartel";
		setar_quartel(quartel_a,unit_color,quarte,quartel_azul_cabana, quartel_azul_cabana, quartel_azul_cabana, id);
		id++;
		BlitImage(screen,quartel_azul_cabana,hexagonos[6][1]->x,hexagonos[6][1]->y);
		hexagonos[5][1]->unidade = quartel_a;
		hexagonos[5][1]->contem_unidade = 1;
		hexagonos[6][1]->unidade = quartel_a;
		hexagonos[6][1]->contem_unidade = 1;
		hexagonos[6][2]->contem_unidade = 1;
		hexagonos[6][2]->unidade = quartel_a;
		hexagonos[7][1]->contem_unidade = 1;
		hexagonos[7][1]->unidade = quartel_a;
		hexagonos[8][1]->contem_unidade = 1;
		hexagonos[8][1]->unidade = quartel_a;
		hexagonos[8][2]->contem_unidade = 1;
		hexagonos[8][2]->unidade = quartel_a;
		hexagonos[9][1]->contem_unidade = 1;
		hexagonos[9][1]->unidade = quartel_a;

	}

	string caminho = "source/GameFeatures/Jogar/Fase1/images/metralhadora_vermelha_esquerda1.png";
	SDL_Surface *metralhadora1 = load_Image(caminho, screen);
	caminho = "source/GameFeatures/Jogar/Fase1/images/metralhadora_vermelha_ataque.png";
	SDL_Surface *metralhadora_ataque = load_Image(caminho, screen);
	caminho = "source/GameFeatures/Jogar/Fase1/images/barraLateral_vermelho.png";
	SDL_Surface *metralhadora_lateral = load_Image(caminho, screen);
	Unit *metralhadora = new Unit();
	string unidadea2 = "metralhadora";
	setar_metralhadora(metralhadora, unit_color, unidadea2, metralhadora1, metralhadora_ataque, metralhadora_lateral, id);
	id++;
	unidades_azul.push_back(metralhadora);

	BlitImage(screen,unidades_azul[10]->unit_name,hexagonos[6][4]->x,hexagonos[6][4]->y);

	hexagonos[6][4]->contem_unidade=1;
	hexagonos[6][4]->unidade = metralhadora;
	hexagonos[7][4]->contem_unidade=1;
	hexagonos[7][4]->unidade = metralhadora;
	hexagonos[8][4]->contem_unidade=1;
	hexagonos[8][4]->unidade = metralhadora;


	SDL_Color blue;
	blue.g = blue.b = 0;
	blue.r = 255;
	SDL_Color white;
	white.r = white.g = white.b = 255;

	//drawCircle(screen, 20, 44, 137, blue);
	//drawCircle(screen, 20, 78, 157, blue);
}

void carrega_eua(SDL_Surface *screen)
{
	string lado2("cliente");
	string cor2 = "azul";

	for (int i=0;i<3;i++) {
		string caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_andando_esquerda.png";
		SDL_Surface *soldado1 = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_azul_ataque.png";
		SDL_Surface *soldado_ataque = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_azul_ataque_baixo.png";
		SDL_Surface *soldado_ataque_baixo = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_azul_ataque_cima.png";
		SDL_Surface *soldado_ataque_cima = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_lateral.png";
		SDL_Surface *soldado_lateral_v = load_Image(caminho, screen);
		Unit *soldado = new Unit();
		string unidade = "soldado";
		setar_soldado(soldado, cor2, unidade, soldado1, soldado_ataque, soldado_ataque_baixo, soldado_ataque_cima,soldado_lateral_v, id);
		id++;
		unidades_vermelhas.push_back(soldado);

		SDL_Rect dst;
		dst.x = hexagonos[i*2][12]->x;
		dst.y = hexagonos[i*2][12]->y;
		dst.h = 0;
		dst.w = 0;
		SDL_BlitSurface(unidades_vermelhas[i]->unit_name, &cutBox,  screen, &dst);
		//BlitImage(screen,unidades_vermelhas[0]->unit_name,hexagonos[2][12]->x,hexagonos[2][12]->y);
		hexagonos[i*2][12]->unidade = unidades_vermelhas[i];
		hexagonos[i*2][12]->contem_unidade = 1;
		unidades_vermelhas[0]->x = hexagonos[i*2][12]->x;
		unidades_vermelhas[0]->y = hexagonos[i*2][12]->y;

	}

	for (int i=3;i<5;i++) {
		string caminho = "source/GameFeatures/Jogar/Fase1/images/helicoptero_azul_movimentacao_esqueda.png";
		SDL_Surface *helicoptero1 = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/helicoptero_ataque_azul.png";
		SDL_Surface *helicoptero_ataque = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/helicoptero_ataque_azul_baixo.png";
		SDL_Surface *helicoptero_ataque_baixo = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/helicoptero_ataque_azul_cima.png";
		SDL_Surface *helicoptero_ataque_cima = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/helicoptero_barraLateral.png";
		SDL_Surface *helicoptero_lateral = load_Image(caminho, screen);
		//caminho = "source/GameFeatures/Jogar/Fase1/images/helicoptero_azul_ataque_baixo.png";
		//SDL_Surface *helicoptero_ataque_baixo = load_Image(caminho, screen);
		Unit *helicoptero = new Unit();
		string unidade1 = "helicoptero";
		setar_helicoptero(helicoptero, cor2, unidade1, helicoptero1, helicoptero_ataque, helicoptero_ataque_baixo, helicoptero_ataque_cima,helicoptero_lateral, id);
		id++;
		unidades_vermelhas.push_back(helicoptero);

		SDL_Rect dst;
		dst.x = hexagonos[i*2][12]->x;
		dst.y = hexagonos[i*2][12]->y;
		dst.h = 0;
		dst.w = 0;
		SDL_BlitSurface(unidades_vermelhas[i]->unit_name, &cutBox,  screen, &dst);
		//BlitImage(screen,unidades_vermelhas[0]->unit_name,hexagonos[2][12]->x,hexagonos[2][12]->y);
		hexagonos[i*2][12]->unidade = unidades_vermelhas[i];
		hexagonos[i*2][12]->contem_unidade = 1;
		unidades_vermelhas[0]->x = hexagonos[i*2][12]->x;
		unidades_vermelhas[0]->y = hexagonos[i*2][12]->y;
	}

	for (int i=5;i<7;i++) {
		string caminho = "source/GameFeatures/Jogar/Fase1/images/metralha_azul.png";
		SDL_Surface *metrapalhadora1 = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/metralhadora_azul_ataque.png";
		SDL_Surface *metrapalhadora_ataque = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/barraLateral_azul.png";
		SDL_Surface *metrapalhadora_lateral = load_Image(caminho, screen);
		Unit *metralhadora = new Unit();
		string unidade2 = "metralhadora";
		setar_metralhadora(metralhadora, cor2, unidade2, metrapalhadora1, metrapalhadora_ataque, metrapalhadora_lateral, id);
		id++;
		unidades_vermelhas.push_back(metralhadora);
	}

	string caminho = "source/GameFeatures/Jogar/Fase1/images/tanque_azul_esquerda1.png";
	SDL_Surface *tanque1 = load_Image(caminho, screen);
	caminho = "source/GameFeatures/Jogar/Fase1/images/tanque_azul_ataque.png";
	SDL_Surface *tanque_ataque = load_Image(caminho, screen);
	caminho = "source/GameFeatures/Jogar/Fase1/images/tanque_azul_ataque_baixo.png";
	SDL_Surface *tanque_ataque_baixo = load_Image(caminho, screen);
	caminho = "source/GameFeatures/Jogar/Fase1/images/tanque_azul_ataque_cima.png";
	SDL_Surface *tanque_ataque_cima = load_Image(caminho, screen);
	caminho = "source/GameFeatures/Jogar/Fase1/images/tanque_lateral_a.png";
	SDL_Surface *tanque_lateral = load_Image(caminho, screen);
	Unit *tanque = new Unit();
	string unidade3 = "tanque";
	setar_tanque(tanque, cor2, unidade3, tanque1, tanque_ataque, tanque_ataque_baixo, tanque_ataque_cima, tanque_lateral, id);
	id++;
	unidades_vermelhas.push_back(tanque);

	///Carregar os sprites do quartel azul
	caminho = "source/GameFeatures/Jogar/Fase1/images/bryjstudios_cabana_azul1.png";
	SDL_Surface *quartel_azul_cabana = load_Image(caminho, screen);
	Unit *quartel_a = new Unit();
	string quarte = "quartel";
	setar_quartel(quartel_a,cor2,quarte,quartel_azul_cabana, quartel_azul_cabana, quartel_azul_cabana, id);
	id++;
	BlitImage(screen,quartel_azul_cabana,hexagonos[7][13]->x,hexagonos[7][13]->y);
	hexagonos[7][13]->unidade = quartel_a;
	hexagonos[7][13]->contem_unidade= 1;
	hexagonos[7][14]->unidade = quartel_a;
	hexagonos[7][14]->contem_unidade= 1;
	hexagonos[8][14]->unidade = quartel_a;
	hexagonos[8][14]->contem_unidade= 1;
	hexagonos[9][13]->unidade = quartel_a;
	hexagonos[9][13]->contem_unidade= 1;
	hexagonos[9][14]->unidade = quartel_a;
	hexagonos[9][14]->contem_unidade= 1;
	hexagonos[10][14]->unidade = quartel_a;
	hexagonos[10][14]->contem_unidade= 1;
	unidades_vermelhas.push_back(quartel_a);

	/*BlitImage(screen,unidades_vermelhas[5]->unit_name,hexagonos[14][12]->x,hexagonos[14][12]->y);
	hexagonos[14][12]->unidade = unidades_vermelhas[5];
	hexagonos[14][12]->contem_unidade = 1;
	unidades_vermelhas[5]->x = hexagonos[14][12]->x;
	unidades_vermelhas[5]->y = hexagonos[14][12]->y;*/

	BlitImage(screen,unidades_vermelhas[5]->unit_name,hexagonos[10][12]->x,hexagonos[10][12]->y);
	hexagonos[9][12]->unidade = unidades_vermelhas[5];
	hexagonos[9][12]->contem_unidade = 1;
	hexagonos[10][12]->unidade = unidades_vermelhas[5];
	hexagonos[10][12]->contem_unidade = 1;
	hexagonos[11][12]->unidade = unidades_vermelhas[5];
	hexagonos[11][12]->contem_unidade = 1;
	hexagonos[12][12]->unidade = unidades_vermelhas[5];
	hexagonos[12][12]->contem_unidade = 1;
	hexagonos[13][12]->unidade = unidades_vermelhas[5];
	hexagonos[13][12]->contem_unidade = 1;

	unidades_vermelhas[6]->x = hexagonos[10][12]->x;
	unidades_vermelhas[6]->y = hexagonos[10][12]->y;



	SDL_Rect dst;
	dst.x = hexagonos[1][3]->x;
	dst.y = hexagonos[1][3]->y;
	dst.h = 0;
	dst.w = 0;
	SDL_BlitSurface(unidades_vermelhas[7]->unit_name, &cutBox,  screen, &dst);
	//BlitImage(screen,unidades _vermelhas[7]->unit_name,hexagonos[1][3]->x,hexagonos[1][3]->y);
	hexagonos[14][12]->unidade = unidades_vermelhas[7];
	hexagonos[14][12]->contem_unidade = 1;
	unidades_vermelhas[7]->x = hexagonos[14][12]->x;
	unidades_vermelhas[7]->y = hexagonos[14][12]->y;

		   // cout<<"i: "<<i<<unidades_vermelhas[i]->unit_type<<endl;

		/*unidades_vermelhas[i]->x = hexagonos[i][j]->x;
		unidades_vermelhas[i]->y =hexagonos[i][j]->y;*/
	}

string convertInt(int number)
{
	//char *palavra = itoa(number);
	//return = string (palavra);
	char buff[50];
	sprintf(buff,"%d",number);
	return string (buff);
}


void blit_lateral(Unit *unidade,SDL_Surface *screen)
{
	string vida, attack_points, deffense_points, attack_range;

	vida = convertInt(unidade->health_points);
	attack_points = convertInt(unidade->attack_points);
	deffense_points = convertInt(unidade->deffense_points);
	attack_range = convertInt(unidade->attack_range);
	BlitImage(screen,hud2,977,236); //Painel de status
	BlitImage(screen,unidade->lateral_image,1100,230);
	desenha_texto(vida,screen,1130 ,350,20);
	desenha_texto(attack_points,screen,1135,380,20);
	desenha_texto(deffense_points,screen,1140,410,20);
	desenha_texto(attack_range,screen,1145,440,20);
	SDL_Flip(screen);

}

void blit_cima(Pais *pais, SDL_Surface *screen)
{
	string gold_coins, food, minerals;

	gold_coins = convertInt(pais->gold_coins);
	food = convertInt(pais->food);
	minerals = convertInt(pais->minerals);

	desenha_texto(gold_coins,screen, 210, 20, 30);
	desenha_texto(food,screen, 310, 20, 30);
	desenha_texto(minerals,screen, 425, 20, 30);
	SDL_Flip(screen);
}






