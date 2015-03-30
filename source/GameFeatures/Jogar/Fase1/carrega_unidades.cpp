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

void setar_soldado(Unidade *soldado, 
				   string cor,
				   string tipo,
				   SDL_Surface *nome, 
				   SDL_Surface *ataque, 
				   SDL_Surface *ataque_baixo, 
				   SDL_Surface *ataque_cima,
				   SDL_Surface *soldado_lateral, 
				   int id)
{
	soldado->hp = 200;
	soldado->atk = 100;
	soldado->def = 100;
	soldado->alcance = 1;
	soldado->ouro = 100;
	soldado->cor = cor;
	soldado->nome = nome;
	soldado->ataque = ataque;
	soldado->ataque_baixo = ataque_baixo;
	soldado->ataque_cima = ataque_cima;
	soldado->tipo = tipo;
	soldado->imagem_lateral = soldado_lateral;
	soldado->id = id;
}

void setar_helicoptero(Unidade *helicoptero, 
					   string cor, 
					   string tipo, 
					   SDL_Surface *nome, 
					   SDL_Surface *ataque, 
					   SDL_Surface *ataque_baixo, 
					   SDL_Surface *ataque_cima, 
					   SDL_Surface *helicoptero_lateral, 
					   int id)
{
	helicoptero->hp = 300;
	helicoptero->atk = 500;
	helicoptero->def = 200;
	helicoptero->alcance = 4;
	helicoptero->ouro = 400;
	helicoptero->cor = cor;
	helicoptero->nome = nome;
	helicoptero->ataque = ataque;
	helicoptero->ataque_baixo = ataque_baixo;
	helicoptero->ataque_cima = ataque_cima;
	helicoptero->tipo = tipo;
	helicoptero->imagem_lateral = helicoptero_lateral;
	helicoptero->id = id;
}

void setar_metralhadora(Unidade *metralhadora, 
						string cor, 
						string tipo,
						SDL_Surface *nome, 
						SDL_Surface *ataque, 
						SDL_Surface *lateral, 
						int id)
{
	metralhadora->hp = 100;
	metralhadora->atk = 200;
	metralhadora->def = 300;
	metralhadora->alcance = 3;
	metralhadora->ouro = 200;
	metralhadora->cor = cor;
	metralhadora->nome = nome;
	metralhadora->ataque = ataque;
	metralhadora->ataque_baixo = ataque;
	metralhadora->ataque_cima = ataque;
	metralhadora->tipo = tipo;
	metralhadora->imagem_lateral = lateral;
	metralhadora->id = id;
}

void setar_tanque(Unidade *tanque, 
				  string cor, 
				  string tipo, 
				  SDL_Surface *nome, 
				  SDL_Surface *ataque, 
				  SDL_Surface *ataque_baixo, 
				  SDL_Surface *ataque_cima,
				  SDL_Surface *tanque_lateral, 
				  int id)
{
	tanque->hp = 350;
	tanque->atk = 400;
	tanque->def = 400;
	tanque->alcance = 2;
	tanque->ouro = 300;
	tanque->cor = cor;
	tanque->nome = nome;
	tanque->ataque = ataque;
	tanque->ataque_baixo = ataque_baixo;
	tanque->ataque_cima = ataque_cima;
	tanque->tipo = tipo;
	tanque->imagem_lateral = tanque_lateral;
	tanque->id = id;
}

void setar_quartel(Unidade *quartel, 
				   string cor, 
				   string tipo, 
				   SDL_Surface *nome, 
				   SDL_Surface *ataque, 
				   SDL_Surface *lateral, 
				   int id)
{
	quartel->hp = 1;
	quartel->atk = 0;
	quartel->def = 400;
	quartel->alcance = 0;
	quartel->ouro = 0;
	quartel->cor = cor;
	quartel->nome = nome;
	quartel->ataque = ataque;
	quartel->ataque_baixo = ataque;
	quartel->ataque_cima = ataque;
	quartel->tipo = tipo;
	quartel->imagem_lateral = lateral;
	quartel->id = id;
}

void setar_pais(Pais *pais, 
				int ouro, 
				int comida, 
				int minerio, 
				string nome, 
				string cor)
{
	pais->ouro = ouro;
	pais->comida = comida;
	pais->minerio = minerio;
	pais->nome = nome;
	pais->cor = cor;
}
void setar_construcao(Construcao *construcao, 
					  SDL_Surface *nome, 
					  string tipo, 
					  int ganho, 
					  int conquistado)
{
	construcao->nome = nome;
	construcao->tipo = tipo;
	construcao->ganho = ganho;
	construcao->conquistado = conquistado;
}

void carrega_construcoes(SDL_Surface *screen)
{

	if (screen) {
	}
	else {
		/* nothing to do */
	}
	/*Construcao *construcao = new Construcao();
	string tipo = "mina";
	int ganho = 20;
	int conquistado = 0;
	string caminho = "source/GameFeatures/Jogar/Fase1/images/mina_de_ouro.png";
	SDL_Surface *mina = load_Image(caminho, screen);
	setar_construcao(construcao, mina, tipo, ganho, conquistado);

	//SDL_BlitSurface(mina, &cutBox,  screen, &dst);
	BlitImage(screen,mina,hexagonos[2][8]->x,hexagonos[2][8]->y);
	hexagonos[2][8]->construcao = construcao;
	hexagonos[2][8]->mina = 1;*/

}

void carrega_china(SDL_Surface *screen)
{

	string lado1("servidor");
	string cor = "vermelho";

	for (int i=0, j=1;i<10;i++,j+=30) {

		string caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_vermelho.png";
		SDL_Surface *soldado1 = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_vermelho_ataque.png";
		SDL_Surface *ataque_soldado = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_vermelho_ataque_baixo.png";
		SDL_Surface *ataque_baixo = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_vermelho_ataque_cima.png";
		SDL_Surface *ataque_cima = load_Image(caminho, screen);
		caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_lateral_vermelho.png";
		SDL_Surface *soldado_lateral_a= load_Image(caminho, screen);
		Unidade *soldado = new Unidade();

		string unidadea1 = "soldado";
		setar_soldado(soldado, cor, unidadea1, soldado1, ataque_soldado, ataque_baixo, ataque_cima,soldado_lateral_a, id);
		id++;
		unidades_azul.push_back(soldado);
		//if(i+2<=hexagonos.size()){
		SDL_Rect dst;
		dst.x = hexagonos[i*2][3]->x;
		dst.y = hexagonos[i*2][3]->y;
		dst.h = 0;
		dst.w = 0;
		SDL_BlitSurface(unidades_azul[i]->nome, &cutBox,  screen, &dst);
		hexagonos[i*2][3]->unidade = unidades_azul[i];
		hexagonos[i*2][3]->contem_unidade = 1;


		caminho = "source/GameFeatures/Jogar/Fase1/images/bryjstudios_cabana_vermelha.png";
		SDL_Surface *quartel_azul_cabana = load_Image(caminho, screen);
		Unidade *quartel_a = new Unidade();
		string quarte = "quartel";
		setar_quartel(quartel_a,cor,quarte,quartel_azul_cabana, quartel_azul_cabana, quartel_azul_cabana, id);
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
	Unidade *metralhadora = new Unidade();
	string unidadea2 = "metralhadora";
	setar_metralhadora(metralhadora, cor, unidadea2, metralhadora1, metralhadora_ataque, metralhadora_lateral, id);
	id++;
	unidades_azul.push_back(metralhadora);

	BlitImage(screen,unidades_azul[10]->nome,hexagonos[6][4]->x,hexagonos[6][4]->y);

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
		Unidade *soldado = new Unidade();
		string unidade = "soldado";
		setar_soldado(soldado, cor2, unidade, soldado1, soldado_ataque, soldado_ataque_baixo, soldado_ataque_cima,soldado_lateral_v, id);
		id++;
		unidades_vermelhas.push_back(soldado);

		SDL_Rect dst;
		dst.x = hexagonos[i*2][12]->x;
		dst.y = hexagonos[i*2][12]->y;
		dst.h = 0;
		dst.w = 0;
		SDL_BlitSurface(unidades_vermelhas[i]->nome, &cutBox,  screen, &dst);
		//BlitImage(screen,unidades_vermelhas[0]->nome,hexagonos[2][12]->x,hexagonos[2][12]->y);
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
		Unidade *helicoptero = new Unidade();
		string unidade1 = "helicoptero";
		setar_helicoptero(helicoptero, cor2, unidade1, helicoptero1, helicoptero_ataque, helicoptero_ataque_baixo, helicoptero_ataque_cima,helicoptero_lateral, id);
		id++;
		unidades_vermelhas.push_back(helicoptero);

		SDL_Rect dst;
		dst.x = hexagonos[i*2][12]->x;
		dst.y = hexagonos[i*2][12]->y;
		dst.h = 0;
		dst.w = 0;
		SDL_BlitSurface(unidades_vermelhas[i]->nome, &cutBox,  screen, &dst);
		//BlitImage(screen,unidades_vermelhas[0]->nome,hexagonos[2][12]->x,hexagonos[2][12]->y);
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
		Unidade *metralhadora = new Unidade();
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
	Unidade *tanque = new Unidade();
	string unidade3 = "tanque";
	setar_tanque(tanque, cor2, unidade3, tanque1, tanque_ataque, tanque_ataque_baixo, tanque_ataque_cima, tanque_lateral, id);
	id++;
	unidades_vermelhas.push_back(tanque);

	///Carregar os sprites do quartel azul
	caminho = "source/GameFeatures/Jogar/Fase1/images/bryjstudios_cabana_azul1.png";
	SDL_Surface *quartel_azul_cabana = load_Image(caminho, screen);
	Unidade *quartel_a = new Unidade();
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

	/*BlitImage(screen,unidades_vermelhas[5]->nome,hexagonos[14][12]->x,hexagonos[14][12]->y);
	hexagonos[14][12]->unidade = unidades_vermelhas[5];
	hexagonos[14][12]->contem_unidade = 1;
	unidades_vermelhas[5]->x = hexagonos[14][12]->x;
	unidades_vermelhas[5]->y = hexagonos[14][12]->y;*/

	BlitImage(screen,unidades_vermelhas[5]->nome,hexagonos[10][12]->x,hexagonos[10][12]->y);
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
	SDL_BlitSurface(unidades_vermelhas[7]->nome, &cutBox,  screen, &dst);
	//BlitImage(screen,unidades _vermelhas[7]->nome,hexagonos[1][3]->x,hexagonos[1][3]->y);
	hexagonos[14][12]->unidade = unidades_vermelhas[7];
	hexagonos[14][12]->contem_unidade = 1;
	unidades_vermelhas[7]->x = hexagonos[14][12]->x;
	unidades_vermelhas[7]->y = hexagonos[14][12]->y;

		   // cout<<"i: "<<i<<unidades_vermelhas[i]->tipo<<endl;

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


void blit_lateral(Unidade *unidade,SDL_Surface *screen)
{
	string vida, atk, def, alcance;

	vida = convertInt(unidade->hp);
	atk = convertInt(unidade->atk);
	def = convertInt(unidade->def);
	alcance = convertInt(unidade->alcance);
	BlitImage(screen,hud2,977,236); //Painel de status
	BlitImage(screen,unidade->imagem_lateral,1100,230);
	desenha_texto(vida,screen,1130 ,350,20);
	desenha_texto(atk,screen,1135,380,20);
	desenha_texto(def,screen,1140,410,20);
	desenha_texto(alcance,screen,1145,440,20);
	SDL_Flip(screen);

}

void blit_cima(Pais *pais, SDL_Surface *screen)
{
	string ouro, comida, minerio;

	ouro = convertInt(pais->ouro);
	comida = convertInt(pais->comida);
	minerio = convertInt(pais->minerio);

	desenha_texto(ouro,screen, 210, 20, 30);
	desenha_texto(comida,screen, 310, 20, 30);
	desenha_texto(minerio,screen, 425, 20, 30);
	SDL_Flip(screen);
}






