#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <curses.h>
#include <SFML/Audio.hpp>
#include "coordenadas.h"
#include "objeto.h"

#define PI 3.14159265

using namespace std;

int menu=0;
int contador2=0;
int teta2;
int menu_anterior;
int escolhe;
int contador=0;
int foto=1;
int controla_fogos=0;
int foto2=31;
int controla_menus=0;
int controla_movimento1=0;
int controla_movimento2=0;
int controla_movimento3=0;
int controla_movimento4=0;
int controla_subindo=0;
int controla_descendo=0;
int flag_carregando=1;
int larguraJanela=1000;
int alturaJanela=650;
int largura_coluna=15;
int largura_maquina=200;
int altura_maquina=300;
int tex=0;
int pode_desce=0;
int tela=0;
int largura_chapa=45;
int largura_tela;
int altura_tela;
int contador_frames=0;
int garra_frente=0;
int garra_atras=0;
int garra_direita=0;
int garra_esquerda=0;
int movimento=0;
int garra_aberta=0;
int garra_fechada=1;
int acrescimo_garra=1;
int fps=60;
int raio_pokeball=10;
int intervalo_pokeball=20;
int tempo=0;
int desce_garra=0;
float incremento_aceleracao=0;
int sobe_garra=0;
int controla_abrindo=0;
int raio_alcance;
int dificuldade;
int incremento=0;
int controla_audio_auto=0;
float intervalo_frames;
float expessura_chapa=4;
float angulo_cotoco_1=45;
float angulo_cotoco_2=45;
float altura_pokeball;
float incremento_anulo_cam;
double raio_camera=400;
double fi;
int controla_caiu=0;
double teta;

GLfloat mat_ambient[]= {1,0.5,0,1};
GLfloat mat_diffuse[]= {1,0.5,0,1};
GLfloat mat_specular[]= {1,1,1,1};
GLfloat mat_emission[]= {0,0,0,1};
GLfloat matshininess[]= {50};


GLfloat mat_ambient2[]= {1,1,1,1};
GLfloat mat_diffuse2[]= {1,1,1,1};
GLfloat mat_specular2[]= {1,1,1,1};
GLfloat mat_emission2[]= {0,0,0,1};
GLfloat matshininess2[]= {100};


GLfloat mat_ambient3[]= {0.35,0.35,0.35,1};
GLfloat mat_diffuse3[]= {0.35,0.35,0.35,1};
GLfloat mat_specular3[]= {1,1,1,1};
GLfloat mat_emission3[]= {0.3,0.3,0.3,1};
GLfloat matshininess3[]= {20};


GLfloat mat_ambient4[]= {0.33,0.35,0.40,1};
GLfloat mat_diffuse4[]= {0.33,0.35,0.40,1};
GLfloat mat_specular4[]= {1,1,1,1};
GLfloat mat_emission4[]= {0,0,0,1};
GLfloat matshininess4[]= {100};

GLfloat mat_ambient5[]= {0.87,0.85,0.5,0};
GLfloat mat_diffuse5[]= {0.87,0.85,0.5,1};
GLfloat mat_specular5[]= {0,0,0,1};
GLfloat mat_emission5[]= {0,0,0,1};
GLfloat matshininess5[]= {50};

GLfloat mat_ambient6[]= {0.1,0.1,0.1,0};
GLfloat mat_diffuse6[]= {0.1,0.1,0.1,1};
GLfloat mat_specular6[]= {0,0,0,1};
GLfloat mat_emission6[]= {0,0,0,1};
GLfloat matshininess6[]= {50};

GLfloat lightAmb[]= {1,1,1,1};
GLfloat lightDif[]= {1,1,1,1};
GLfloat lightSpec[]= {1,1,1,1};

GLfloat lightAmb2[]= {0,0,0,1};
GLfloat lightDif2[]= {0.2,0.2,0.2,1};
GLfloat lightSpec2[]= {1,1,1,1};

GLfloat lightAmb3[]= {0,0,0,1};
GLfloat lightDif3[]= {0.3,0.3,0.3,1};
GLfloat lightSpec3[]= {1,1,1,1};


GLfloat lightPos0[]= {400,0,400,1};
GLfloat lightPos1[]= {-400,0,-400,1};
GLfloat lightPos2[]= {400,0,-400,1};
GLfloat lightPos3[]= {-400,0,400,1};

GLfloat globAmb[4]= {0.2,0.2,0.2,1};
GLuint texturaLogo;
GLuint texturaPokeball_1;
GLuint texturaPokeball_2;
GLuint texturaPokemon1;
GLuint texturaPokemon2;
GLuint texturaPokemon3;
GLuint texturaPokemon4;
GLuint texturaPokemon5;
GLuint texturaPokemon6;
GLuint texturaPokemon7;
GLuint texturaPokemon8;
GLuint texturaPokemon9;
GLuint texturaPokemon10;
GLuint texturaPokemon11;
GLuint texturaPokemon12;
GLuint texturaPokemon13;
GLuint texturaPokemon14;
GLuint texturaPokemon15;
GLuint texturaPokemon16;
GLuint texturaPokemon17;
GLuint texturaPokemon18;
GLuint texturaPokemon19;
GLuint texturaPokemon20;
GLuint texturaPokemon21;
GLuint texturaPokemon22;
GLuint texturaPokemon23;
GLuint texturaPokemon24;
GLuint texturaPokemon25;
GLuint texturaPokemon26;
GLuint texturaPokemon27;
GLuint texturaPokemon28;
GLuint texturaPokemon29;
GLuint texturaPokemon30;
GLuint texturaPokemon31;
GLuint texturaPokemon32;
GLuint texturaPokemon33;
GLuint texturaPokemon34;
GLuint texturaPokemon35;
GLuint texturaPokemon36;
GLuint texturaPokemon37;
GLuint texturaPokemon38;
GLuint texturaPokemon39;
GLuint texturaPokemon40;
GLuint texturaPokemon41;
GLuint texturaPokemon42;
GLuint texturaPokemon43;
GLuint texturaPokemon44;
GLuint texturaPokemon45;
GLuint texturaPokemon46;
GLuint texturaPokemon47;
GLuint texturaPokemon48;
GLuint texturaPokemon49;
GLuint texturaPokemon50;
GLuint texturaPokemon51;
GLuint texturaPokemon52;
GLuint texturaPokemon53;
GLuint texturaPokemon54;
GLuint texturaPokemon55;
GLuint texturaPokemon56;
GLuint texturaPokemon57;
GLuint texturaPokemon58;
GLuint texturaPokemon59;
GLuint texturaPokemon60;
GLuint texturaPokemon61;
GLuint texturaPokemon62;
GLuint texturaPokemon63;
GLuint texturaPokemon64;
GLuint texturaPokemon65;
GLuint texturaPokemon66;
GLuint texturaPokemon67;
GLuint texturaPokemon68;
GLuint texturaPokemon69;
GLuint texturaPokemon70;
GLuint texturaPokemon71;
GLuint texturaPokemon72;
GLuint texturaPokemon73;
GLuint texturaPokemon74;
GLuint texturaPokemon75;
GLuint texturaPokemon76;
GLuint texturaPokemon77;
GLuint texturaPokemon78;
GLuint texturaPokemon79;
GLuint texturaPokemon80;
GLuint texturaPokemon81;
GLuint texturaPokemon82;
GLuint texturaPokemon83;
GLuint texturaPokemon84;
GLuint texturaPokemon85;

GLuint cursor;

GLuint textura_badges1;
GLuint textura_badges2;
GLuint textura_badges3;
GLuint textura_badges4;
GLuint textura_badges5;
GLuint textura_badges6;
GLuint textura_badges7;
GLuint textura_badges8;
GLuint textura_pokebola;
GLuint textura_fogos;

GLuint ambiente1;

GLuint menu_principal;
GLuint novo_jogo;
GLuint tutorial1;
GLuint tutorial2;
GLuint premio;
GLuint continuar;
GLuint carregando1;
GLuint carregando2;
GLuint carregando3;
GLuint carregando4;
GLuint carregando5;

GLuint facil;
GLuint medio;
GLuint dificil;

GLuint botao_nj;
GLuint botao_t;
GLuint botao_s;
GLuint botao_v;
GLuint botao_c;
GLuint botao_n;
GLuint botao_m;
GLuint botao_p;
GLuint botao_f;
GLuint botao_d;

objeto pokeball[50];
objeto cilindro;
objeto garra;
objeto botao1;
objeto botao2;
objeto botao3;
objeto botao4;
objeto botao5;
objeto botao6;
objeto pokemon;
objeto chapa_topo;
objeto chapa_chao;
objeto chapa_frente_inferior;
objeto chapa_frente_superior;
objeto chapa_atras_inferior;
objeto chapa_atras_superior;
objeto chapa_lateral_frente_inferior;
objeto chapa_lateral_frente_superior;
objeto chapa_lateral_atras_inferior;
objeto chapa_lateral_atras_superior;

ponto cordenada_mouse;
ponto cam;


void redimensiona(int, int);
void solidSphere(int, int, int);
void atualiza(int);
void desenha_jogo();
void faz2d();
void faz3d();
sf::Music menus;
sf::Music subindo;
sf::Music descendo;
sf::Music fogos;
sf::Music frente;
sf::Music esquerda;
sf::Music direita;
sf::Music atras;
sf::Music clike;
sf::Music fundo;
sf::Music caindo;
sf::Music caiu;
sf::Music garra_abrindo;

float* coordena_sprite(int linhas,int colunas,int posisao,int foto)
{
	float *xy;
	xy = (float*) malloc(2 * sizeof(float));
	int i,j;
	float intevalo_linha=(float)1/linhas;
	float intevalo_colunas=(float)1/colunas;
	for(i=0; i<linhas; i++)
	{
		for(j=0; j<colunas; j++)
		{
			if(i*colunas+j+1==foto)
			{
				if(posisao==1)
				{
					xy[0]=intevalo_colunas*j;
					xy[1]=1-intevalo_linha*(i+1);
				}
				if(posisao==2)
				{
					xy[0]=intevalo_colunas*j + intevalo_colunas;
					xy[1]=1-intevalo_linha*(i+1);
				}
				if(posisao==3)
				{
					xy[0]=intevalo_colunas*j + intevalo_colunas;
					xy[1]=1-intevalo_linha*(i+1) + intevalo_linha;
				}
				if(posisao==4)
				{
					xy[0]=intevalo_colunas*j;
					xy[1]=1-intevalo_linha*(i+1) + intevalo_linha;
				}
			}
		}
	}
	return xy;
}
void inicializa_audio()
{
	menus.openFromFile("audio/PokemonAbertura.wav");
	subindo.openFromFile("audio/subindo.wav");
	descendo.openFromFile("audio/descendo.wav");
	frente.openFromFile("audio/machine_frente.wav");
	direita.openFromFile("audio/machine_frente.wav");
	atras.openFromFile("audio/machine_atras.wav");
	esquerda.openFromFile("audio/machine_atras.wav");
	clike.openFromFile("audio/clico.wav");
	fundo.openFromFile("audio/supermario.wav");
	caindo.openFromFile("audio/caindo.wav");
	caiu.openFromFile("audio/caiu.wav");
	garra_abrindo.openFromFile("audio/drill_raw.wav");
	fogos.openFromFile("audio/fogos.wav");
	fundo.setLoop(true);
	frente.setLoop(true);
	subindo.setLoop(true);
	descendo.setLoop(true);
	atras.setLoop(true);
	esquerda.setLoop(true);
	direita.setLoop(true);
	menus.setLoop(true);
	fogos.setLoop(true);
	garra_abrindo.setLoop(true);
	garra_abrindo.setVolume(30.0);
	fundo.setVolume(20.0);
	clike.setVolume(30.0);
	menus.setVolume(15.0);
}
ponto converte_cordenadas_mouse(ponto mouse)
{
	float porcentagemX, porcentagemY;
	porcentagemX=mouse.x/largura_tela;
	porcentagemY=mouse.y/altura_tela;
	float parte_andadax,parte_andaday;
	float meia_largura_tela,meia_altura_tela;
	meia_largura_tela=largura_tela/2;
	meia_altura_tela=altura_tela/2;
	parte_andadax=porcentagemX*largura_tela;
	parte_andaday=porcentagemY*alturaJanela;
	mouse.x=parte_andadax-meia_largura_tela;
	mouse.y=meia_altura_tela-parte_andaday;
	return mouse;
}
void mouse_motion(int x, int y)
{
	cordenada_mouse.x=x;
	cordenada_mouse.y=y;
	cordenada_mouse=converte_cordenadas_mouse(cordenada_mouse);
	float porcentagem_x=(cordenada_mouse.x+largura_tela/2)/largura_tela;
	float porcentagem_y=(cordenada_mouse.y+altura_tela/2)/altura_tela;
	cordenada_mouse.porcentagem_x=porcentagem_x;
	cordenada_mouse.porcentagem_y=porcentagem_y;
	int flag2=0;
	if(menu==7)
	{
		if(cordenada_mouse.x<=botao4.x_maximo && cordenada_mouse.x>=botao4.x_minimo)
		{
			if(cordenada_mouse.y<=botao4.y_maximo && cordenada_mouse.y>=botao4.y_minimo)
			{
				flag2=1;
			}
		}
		if(cordenada_mouse.x<=botao5.x_maximo && cordenada_mouse.x>=botao5.x_minimo)
		{
			if(cordenada_mouse.y<=botao5.y_maximo && cordenada_mouse.y>=botao5.y_minimo)
			{
				flag2=2;
			}
		}
		if(cordenada_mouse.x<=botao6.x_maximo && cordenada_mouse.x>=botao6.x_minimo)
		{
			if(cordenada_mouse.y<=botao6.y_maximo && cordenada_mouse.y>=botao6.y_minimo)
			{
				flag2=3;
			}
		}
		switch(flag2)
		{
		case 0:
			tela=0;
			break;
		case 1:
			tela=1;
			break;
		case 2:
			tela=2;
			break;
		case 3:
			tela=3;
			break;
		}
	}

}
void click_mouse(int butom, int state, int x,int y)
{
	cordenada_mouse.x=x;
	cordenada_mouse.y=y;
	cordenada_mouse=converte_cordenadas_mouse(cordenada_mouse);

	if(menu==0)
	{

		if(cordenada_mouse.x<=botao1.x_maximo && cordenada_mouse.x>=botao1.x_minimo)
		{
			if(cordenada_mouse.y<=botao1.y_maximo && cordenada_mouse.y>=botao1.y_minimo)
			{
				clike.play();
				menu=7;
			}
		}
		if(cordenada_mouse.x<=botao2.x_maximo && cordenada_mouse.x>=botao2.x_minimo)
		{
			if(cordenada_mouse.y<=botao2.y_maximo && cordenada_mouse.y>=botao2.y_minimo)
			{
				clike.play();
				menu=1;
			}
		}
		if(cordenada_mouse.x<=botao3.x_maximo+400 && cordenada_mouse.x>=botao3.x_minimo+400)
		{
			if(cordenada_mouse.y<=botao3.y_maximo && cordenada_mouse.y>=botao3.y_minimo)
			{
				clike.play();
				exit(0);
			}
		}
	}

	if(menu==1)
	{
		if(cordenada_mouse.x<=botao3.x_maximo-100 && cordenada_mouse.x>=botao3.x_minimo-100)
		{
			if(cordenada_mouse.y<=botao3.y_maximo-20 && cordenada_mouse.y>=botao3.y_minimo-20)
			{
				clike.play();
				menu=0;
			}
		}
		if(cordenada_mouse.x<=botao6.x_maximo+100 && cordenada_mouse.x>=botao6.x_minimo+100)
		{
			if(cordenada_mouse.y<=botao6.y_maximo-20 && cordenada_mouse.y>=botao6.y_minimo-20)
			{
				clike.play();
				menu=2;
			}
		}
	}

	if(menu==4)
	{
		if(cordenada_mouse.x<=botao3.x_maximo-100 && cordenada_mouse.x>=botao3.x_minimo-100)
		{
			if(cordenada_mouse.y<=botao3.y_maximo-20 && cordenada_mouse.y>=botao3.y_minimo-20)
			{
				clike.play();
				menu=6;
				fundo.play();
				faz3d();
			}
		}
		if(cordenada_mouse.x<=botao6.x_maximo+100 && cordenada_mouse.x>=botao6.x_minimo+100)
		{
			if(cordenada_mouse.y<=botao6.y_maximo-20 && cordenada_mouse.y>=botao6.y_minimo-20)
			{
				clike.play();
				exit(0);
			}
		}
	}

	if(menu==8)
	{
		if(cordenada_mouse.x<=botao3.x_maximo+300 && cordenada_mouse.x>=botao3.x_minimo+300)
		{
			if(cordenada_mouse.y<=botao3.y_maximo+500 && cordenada_mouse.y>=botao3.y_minimo+500)
			{
				clike.play();
				menu=menu_anterior;
				if(menu==6)
				{
					fundo.play();
					faz3d();
				}
				else
				{
					if(menu==0)
					{
						menus.play();
					}
					else
					{
						faz2d();
					}
				}
			}
		}
		if(cordenada_mouse.x<=botao6.x_maximo-300 && cordenada_mouse.x>=botao6.x_minimo-300)
		{
			if(cordenada_mouse.y<=botao6.y_maximo-20 && cordenada_mouse.y>=botao6.y_minimo-20)
			{
				clike.play();
				exit(0);
			}
		}
	}

	if(menu==5)
	{
		if(cordenada_mouse.x<=botao3.x_maximo-100 && cordenada_mouse.x>=botao3.x_minimo-100)
		{
			if(cordenada_mouse.y<=botao3.y_maximo-20 && cordenada_mouse.y>=botao3.y_minimo-20)
			{
				clike.play();
				menu=6;
				fundo.play();
				if(controla_fogos==1)
				{
					controla_fogos=0;
					fogos.stop();
				}
				garra.x=0;
				garra.z=0;
				faz3d();
			}
		}
		if(cordenada_mouse.x<=botao6.x_maximo+100 && cordenada_mouse.x>=botao6.x_minimo+100)
		{
			if(cordenada_mouse.y<=botao6.y_maximo-20 && cordenada_mouse.y>=botao6.y_minimo-20)
			{
				clike.play();
				exit(0);
			}
		}
	}

	if(menu==2)
	{
		if(cordenada_mouse.x<=botao2.x_maximo+435 && cordenada_mouse.x>=botao2.x_minimo+435)
		{
			if(cordenada_mouse.y<=botao2.y_maximo && cordenada_mouse.y>=botao2.y_minimo-20)
			{
				clike.play();
				menu=1;
			}
		}
		if(cordenada_mouse.x<=botao5.x_maximo+90 && cordenada_mouse.x>=botao6.x_minimo+90)
		{
			if(cordenada_mouse.y<=botao5.y_maximo && cordenada_mouse.y>=botao5.y_minimo)
			{
				clike.play();
				menu=0;
			}
		}
	}
	if(menu==7)
	{
		if(cordenada_mouse.x<=botao3.x_maximo && cordenada_mouse.x>=botao3.x_minimo)
		{
			if(cordenada_mouse.y<=botao3.y_maximo && cordenada_mouse.y>=botao3.y_minimo)
			{
				clike.play();
				menu=0;
			}
		}
		if(cordenada_mouse.x<=botao4.x_maximo && cordenada_mouse.x>=botao4.x_minimo)
		{
			if(cordenada_mouse.y<=botao4.y_maximo && cordenada_mouse.y>=botao4.y_minimo)
			{
				clike.play();
				menu=3;
				dificuldade=1;
			}
		}
		if(cordenada_mouse.x<=botao5.x_maximo && cordenada_mouse.x>=botao5.x_minimo)
		{
			if(cordenada_mouse.y<=botao5.y_maximo && cordenada_mouse.y>=botao5.y_minimo)
			{
				clike.play();
				menu=3;
				dificuldade=2;
			}
		}
		if(cordenada_mouse.x<=botao6.x_maximo && cordenada_mouse.x>=botao6.x_minimo)
		{
			if(cordenada_mouse.y<=botao6.y_maximo && cordenada_mouse.y>=botao6.y_minimo)
			{
				clike.play();
				menu=3;
				dificuldade=3;
			}
		}
	}
}
void faz_quadrado(float x,float y,int tamanho)
{
	glBegin(GL_POLYGON);
	glVertex3f(x,y, 0.0);
	glVertex3f(x,y+tamanho, 0.0);
	glVertex3f(x+tamanho,y+tamanho, 0.0);
	glVertex3f(x+tamanho,y, 0.0);
	glEnd();
}
void configura_material(int tipo)
{
	if(tipo==1)
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  mat_diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat_emission);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,matshininess);
	}
	if(tipo==2)
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient2);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  mat_diffuse2);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular2);
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat_emission2);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,matshininess2);
	}
	if(tipo==3)
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient3);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  mat_diffuse3);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular3);
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat_emission3);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,matshininess3);
	}
	if(tipo==4)
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient4);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  mat_diffuse4);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular4);
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat_emission4);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,matshininess4);
	}
	if(tipo==5)
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient5);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  mat_diffuse5);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular5);
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat_emission5);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,matshininess5);
	}
	if(tipo==6)
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient6);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,  mat_diffuse6);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular6);
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat_emission6);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,matshininess6);
	}
}
void inicializa_luz(int tipo)
{
	if(tipo==1)
	{
		glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif);
		glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec);
		glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

		glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmb2);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDif2);
		glLightfv(GL_LIGHT1, GL_SPECULAR, lightSpec2);
		glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

		glLightfv(GL_LIGHT2, GL_AMBIENT, lightAmb3);
		glLightfv(GL_LIGHT2, GL_DIFFUSE, lightDif3);
		glLightfv(GL_LIGHT2, GL_SPECULAR, lightSpec3);
		glLightfv(GL_LIGHT2, GL_POSITION, lightPos3);

		glLightfv(GL_LIGHT3, GL_AMBIENT, lightAmb3);
		glLightfv(GL_LIGHT3, GL_DIFFUSE, lightDif3);
		glLightfv(GL_LIGHT3, GL_SPECULAR, lightSpec3);
		glLightfv(GL_LIGHT3, GL_POSITION, lightPos3);


	}
	if(tipo==2)
	{
		glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb2);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif2);
		glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec2);
		glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	}
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb);
}
int verifica_posicao(objeto pokeball,int i)
{
	if(garra.x+raio_alcance>=pokeball.x && garra.x-raio_alcance<=pokeball.x && desce_garra==1 && garra.z+raio_alcance>=pokeball.z && garra.z-raio_alcance<=pokeball.z)
	{
		if(i!=1 && i!=6 && i!=31 && i!=36 && i!=5 && i!=11 && i!=4 && i!=10)
		{
			garra.x=pokeball.x;
			garra.z=pokeball.z;
			return i;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}
int verifica_bug(int i)
{
	if(garra.x+4>=pokeball[i].x && garra.x-4<=pokeball[i].x && garra.z+4>=pokeball[i].z && garra.z-4<=pokeball[i].z)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int contato(objeto pokeball)
{
	int raio_esfera_pequena=1;
	if(garra.y-20-garra.raio-pokeball.y<raio_esfera_pequena+raio_pokeball)
	{
		return 1;
	}
	return 0;
}
void movimentacao_garra()
{
	int i;
	for(i=0; i<36; i++)
	{
		if(verifica_posicao(pokeball[i],i+1)!=0)
		{
			garra.status=2;
			if(contato(pokeball[i])==1)
			{
				garra.bola=i;
				garra.status=4;
				if(controla_descendo==1)
				{
					controla_descendo=0;
					descendo.stop();
				}
				desce_garra=0;
				sobe_garra=1;
			}
		}
	}
	if(angulo_cotoco_2>=45 && angulo_cotoco_1>=45)
	{
		garra_fechada=1;
		controla_abrindo=1;
	}
	else
	{
		garra_fechada=0;
	}
	if(angulo_cotoco_1<=10 && angulo_cotoco_2<=20)
	{
		garra_aberta=1;
		controla_abrindo=1;
	}
	else
	{
		garra_aberta=0;
	}
	if(controla_abrindo==0 && garra_fechada==0 && garra_aberta==0)
	{
		controla_abrindo=2;
		garra_abrindo.play();
	}
	else
	{
		if(controla_abrindo==1 && (garra_fechada==1 || garra_aberta==1))
		{
			controla_abrindo=0;
			garra_abrindo.stop();
		}
	}

	if(desce_garra==1)
	{
		if(garra_fechada==1)
		{
			movimento=1;
			garra.status=1;
		}
		if(garra_aberta==1 )
		{
			if(garra.status==1 )
			{
				if(controla_descendo==0)
				{
					controla_descendo=1;
					descendo.play();
				}
				if(garra.y>altura_pokeball+raio_pokeball+40)
				{
					garra.y-=1;
				}
				if(garra.y<=altura_pokeball+raio_pokeball+40)
				{
					garra.status=3;
				}
			}
			if(garra.status==2)
			{
				garra.y-=1;
				if(controla_descendo==0)
				{
					descendo.play();
					controla_descendo=1;
				}
			}

			if(garra.status==3)
			{
				if(controla_descendo==1)
				{
					controla_descendo=0;
					descendo.stop();
				}
				desce_garra=0;
				sobe_garra=1;
			}
		}
	}
	if(sobe_garra==1)
	{
		if(garra_aberta==1)
		{
			movimento=2;
		}
		if(garra_fechada==1)
		{
			if(garra.status==3)
			{
				garra.status=5;
			}

			if(garra.status==4)
			{
				garra.status=6;
				pokeball[garra.bola].status=1;
			}

			if(garra.status==5)
			{
				if(controla_subindo==0)
				{
					controla_subindo=1;
					subindo.play();
				}
				if(garra.y<altura_maquina/2-garra.raio-largura_chapa)
				{
					garra.y+=1;
				}
				if(garra.y>=altura_maquina/2-garra.raio-largura_chapa)
				{
					sobe_garra=0;
					garra.status=7;
					if(controla_subindo==1)
					{
						controla_subindo=0;
						subindo.stop();
					}
				}
			}
			if(garra.status==6)
			{
				if(pokeball[garra.bola].status==1)
				{
					if(controla_subindo==0)
					{
						controla_subindo=1;
						subindo.play();
					}
					if(garra.y<altura_maquina/2-garra.raio-largura_chapa)
					{
						garra.y+=1;
						pokeball[garra.bola].y+=1;
					}
					if(garra.y>=altura_maquina/2-garra.raio-largura_chapa)
					{
						sobe_garra=0;
						garra.status=9;
						if(controla_subindo==1)
						{
							controla_subindo=0;
							subindo.stop();
						}
						pokeball[garra.bola].status=0;
					}
				}
			}
		}
	}
	if(sobe_garra==0 && desce_garra==0)
	{
		if(garra.status==7)
		{
			garra.status=0;
		}
		if(garra.status==8)
		{
			if(garra_fechada==1 && pokeball[garra.bola].status!=2)
			{
				movimento=1;
				pokeball[garra.bola].status=2;
			}
			if(pokeball[garra.bola].status==2)
			{
				if(contador_frames%10==0)
				{
					incremento_aceleracao+=0.4;

				}
				if(garra_aberta==1)
				{
					movimento=2;
				}
				if(pokeball[garra.bola].y>altura_pokeball-(2*(raio_pokeball+intervalo_pokeball)+8))
				{
					pokeball[garra.bola].y-=(0.5+incremento_aceleracao);
					if(controla_caiu==0)
					{
						caindo.play();
						controla_caiu=1;
					}
				}
				if(pokeball[garra.bola].y<=altura_pokeball-(2*(raio_pokeball+intervalo_pokeball)+8))
				{
					if(controla_caiu==1)
					{
						caindo.stop();
						caiu.play();
						controla_caiu=0;
					}
					pokeball[garra.bola].y=altura_pokeball-(2*(raio_pokeball+intervalo_pokeball)+8);
					if(garra_fechada==1)
					{
						pokeball[garra.bola].status=7;
						incremento_aceleracao=0;
						garra.status=0;
						menu=5;
						fundo.pause();
						escolhe=rand()%85 + 1;
						contador2=0;
					}
				}
			}
		}
	}
	if(garra.status==9)
	{
		if(controla_audio_auto==0)
		{
			frente.play();
			controla_audio_auto=1;
		}
		if(garra.z<-74)
		{
			garra.z+=0.5;
		}
		if(garra.z>-75)
		{
			garra.z-=0.5;
		}
		if(garra.z<=-74 && garra.z>=-75)
		{
			if( pokeball[garra.bola].status==6)
			{
				garra.status=10;
			}
			if(controla_audio_auto==1)
			{
				frente.stop();
				controla_audio_auto=2;
			}
		}

		if(pokeball[garra.bola].z<-74)
		{
			pokeball[garra.bola].z+=0.5;
		}
		if(pokeball[garra.bola].z>-75)
		{
			pokeball[garra.bola].z-=0.5;
		}
		if(pokeball[garra.bola].z<=-74 && pokeball[garra.bola].z>=-75)
		{
			pokeball[garra.bola].status=6;
		}
	}

	if(garra.status==10)
	{
		if(controla_audio_auto==2)
		{
			atras.play();
			controla_audio_auto=3;
		}
		if(garra.x<44)
		{
			if(contador_frames%1==0)
			{
				garra.x+=0.5;
			}
		}
		if(garra.x>45)
		{
			if(contador_frames%1==0)
			{
				garra.x-=0.5;
			}
		}
		if(garra.x>=44 && garra.x<=45)
		{
			if(pokeball[garra.bola].status==0)
			{
				garra.status=8;
			}
			if(controla_audio_auto==3)
			{
				atras.stop();
				controla_audio_auto=0;
			}
		}

		if(pokeball[garra.bola].x<44)
		{
			if(contador_frames%1==0)
			{
				pokeball[garra.bola].x+=0.5;
			}
		}
		if(pokeball[garra.bola].x>45)
		{
			if(contador_frames%1==0)
			{
				pokeball[garra.bola].x-=0.5;
			}
		}
		if(pokeball[garra.bola].x>=44 && pokeball[garra.bola].x<=45)
		{
			pokeball[garra.bola].status=0;
		}
	}
}
void movimenta_garra()
{
	if(movimento==1)
	{
		if(angulo_cotoco_2>20)
		{
			angulo_cotoco_2-=0.2;
		}
		if(angulo_cotoco_1>10)
		{
			angulo_cotoco_1-=0.2;
		}
	}
	if(movimento==2)
	{
		if(angulo_cotoco_2<45)
		{
			angulo_cotoco_2+=0.2;
		}
		if(angulo_cotoco_1<45)
		{
			angulo_cotoco_1+=0.2;
		}
	}
}
void faz_pokeball(objeto pokeball)
{
	glPushMatrix();
	configura_material(3);
	tex=1;
	glTranslatef(pokeball.x,pokeball.y,pokeball.z);
	glEnable(GL_TEXTURE_2D);
	if(pokeball.tipo==0)
	{
		glBindTexture(GL_TEXTURE_2D, texturaPokeball_1);
	}
	if(pokeball.tipo==1)
	{
		glBindTexture(GL_TEXTURE_2D, texturaPokeball_2);
	}
	glRotatef(270,1,0,0);

	solidSphere(raio_pokeball,20,20);
	tex=0;
	configura_material(1);
	glPopMatrix();
}
void inicializa_pokeball()
{

	int x=-largura_maquina/2-5;
	altura_pokeball=-altura_maquina/2+20+largura_chapa/2+raio_pokeball;
	int z=-largura_maquina/2-5;
	int i;
	int contador=1;
	int numero_colunas=6;
	int numero_linhas=6;
	for(i=0; i<numero_linhas*numero_colunas; i++)
	{

		if(i%numero_colunas==0)
		{
			x=-largura_maquina/2-5;
			z=-largura_maquina/2-5+contador*(intervalo_pokeball+raio_pokeball);
			contador++;
		}
		x=x+intervalo_pokeball+raio_pokeball;
		pokeball[i].tipo=rand()%2;
		pokeball[i].x=x;
		pokeball[i].y=-altura_maquina/2+20+largura_chapa/2+raio_pokeball;
		pokeball[i].z=z;
		pokeball[i].status=0;
	}
}
void move_garra()
{
	if(garra.status==0)
	{
		if(garra_atras==1 && garra.z-acrescimo_garra>=-largura_maquina/2+garra.raio+expessura_chapa+12)
		{
			garra.z-=acrescimo_garra;
		}
		else
		{
			atras.stop();
		}
		if(garra_frente==1 && garra.z+acrescimo_garra<=largura_maquina/2-garra.raio-expessura_chapa-12)
		{
			garra.z+=acrescimo_garra;
		}
		else
		{
			frente.stop();
		}
		if(garra_direita==1 && garra.x+acrescimo_garra<=largura_maquina/2-garra.raio-expessura_chapa-12)
		{
			garra.x+=acrescimo_garra;
		}
		else
		{
			direita.stop();
		}
		if(garra_esquerda==1 && garra.x-acrescimo_garra>=-largura_maquina/2+garra.raio+expessura_chapa+12)
		{
			garra.x-=acrescimo_garra;
		}
		else
		{
			esquerda.stop();
		}
		if(garra_esquerda==1 && garra_direita==1)
		{
			esquerda.stop();
			direita.stop();
		}
		if(garra_frente==1 && garra_atras==1)
		{
			frente.stop();
			atras.stop();
		}
		if(garra_esquerda!=garra_direita && (controla_movimento3==2 || controla_movimento4==2) && garra.status==0)
		{
			if(garra_direita==1 && garra.x+acrescimo_garra<=largura_maquina/2-garra.raio-expessura_chapa-12)
			{
				controla_movimento3=1;
				direita.play();
			}
			if(garra_esquerda==1 && garra.x-acrescimo_garra>=-largura_maquina/2+garra.raio+expessura_chapa+12 )
			{
				controla_movimento4=1;
				esquerda.play();
			}
		}
		if(garra_frente!=garra_atras && (controla_movimento1==2 || controla_movimento2==2) && garra.status==0 )
		{
			if(garra_atras==1 && garra.z-acrescimo_garra>=-largura_maquina/2+garra.raio+expessura_chapa+12)
			{
				controla_movimento2=1;
				atras.play();
			}
			if(garra_frente==1 && garra.z+acrescimo_garra<=largura_maquina/2-garra.raio-expessura_chapa-12)
			{
				controla_movimento1=1;
				frente.play();
			}
		}
	}
}
void desenha_maquina()
{
	glPushMatrix();
	configura_material(1);

	glColorMaterial(GL_FRONT, GL_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	glTranslatef(0,-altura_maquina/2+20,-largura_maquina/2);
	glPushMatrix();
	glScalef(chapa_frente_inferior.comprimento,chapa_frente_inferior.largura,expessura_chapa);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,largura_maquina-expessura_chapa);
	glScalef(chapa_atras_inferior.comprimento,chapa_atras_inferior.largura,expessura_chapa);
	glutSolidCube(1);
	glPopMatrix();

	chapa_frente_inferior.x_minimo=-1*chapa_frente_inferior.comprimento/2;
	chapa_frente_inferior.x_maximo=chapa_frente_inferior.comprimento/2;
	chapa_frente_inferior.y_minimo=-1*chapa_frente_inferior.largura/2;
	chapa_frente_inferior.y_maximo=chapa_frente_inferior.largura/2;
	chapa_frente_inferior.z_minimo=-1*expessura_chapa/2;
	chapa_frente_inferior.z_maximo=expessura_chapa/2;

	chapa_atras_inferior.x_minimo=-1*chapa_atras_inferior.comprimento/2;
	chapa_atras_inferior.x_maximo=chapa_atras_inferior.comprimento/2;
	chapa_atras_inferior.y_minimo=-1*chapa_atras_inferior.largura/2;
	chapa_atras_inferior.y_maximo=chapa_atras_inferior.largura/2;
	chapa_atras_inferior.z_minimo=largura_maquina-expessura_chapa;
	chapa_atras_inferior.z_maximo=largura_maquina;

	glPushMatrix();
	glTranslatef(chapa_frente_inferior.x_minimo+15,altura_maquina/2 + chapa_frente_inferior.y_minimo,0);
	glScalef(30,altura_maquina,expessura_chapa);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(chapa_frente_inferior.x_maximo-15,altura_maquina/2 + chapa_frente_inferior.y_minimo,0);
	glScalef(30,altura_maquina,expessura_chapa);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,0,largura_maquina-expessura_chapa);
	glTranslatef(chapa_atras_inferior.x_minimo+15,altura_maquina/2 + chapa_atras_inferior.y_minimo,0);
	glScalef(30,altura_maquina,expessura_chapa);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,largura_maquina-expessura_chapa);
	glTranslatef(chapa_atras_inferior.x_maximo-15,altura_maquina/2 + chapa_atras_inferior.y_minimo,0);
	glScalef(30,altura_maquina,expessura_chapa);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,altura_maquina-chapa_frente_superior.largura,0);
	glPushMatrix();
	glScalef(chapa_frente_superior.comprimento,chapa_frente_superior.largura,expessura_chapa);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,largura_maquina-expessura_chapa);
	glScalef(chapa_atras_superior.comprimento,chapa_atras_superior.largura,expessura_chapa);
	glutSolidCube(1);
	glPopMatrix();

	chapa_frente_superior.x_minimo=-1*chapa_frente_superior.comprimento/2;
	chapa_frente_superior.x_maximo=chapa_frente_superior.comprimento/2;
	chapa_frente_superior.y_minimo=altura_maquina-chapa_frente_superior.largura;
	chapa_frente_superior.y_maximo=altura_maquina-chapa_frente_superior.largura/2;
	chapa_frente_superior.z_minimo=-1*expessura_chapa/2;
	chapa_frente_superior.z_maximo=expessura_chapa/2;
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,altura_maquina-chapa_frente_superior.largura/2-expessura_chapa/2,chapa_topo.comprimento/2-expessura_chapa/2);
	glPushMatrix();
	glScalef(chapa_topo.largura-2,expessura_chapa,chapa_topo.comprimento-2);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();

	chapa_topo.x_minimo=-largura_maquina/2;
	chapa_topo.x_maximo=largura_maquina/2;
	chapa_topo.y_maximo=altura_maquina/2;
	chapa_topo.y_minimo=altura_maquina/2-expessura_chapa;
	chapa_topo.z_minimo=-1*expessura_chapa/2;
	chapa_topo.z_maximo=largura_maquina-expessura_chapa/2;
	configura_material(2);
	glPushMatrix();
	configura_material(5);
	glTranslatef(0,chapa_frente_superior.largura/2-expessura_chapa/2,chapa_topo.comprimento/2+expessura_chapa/2+raio_pokeball+intervalo_pokeball);
	glPushMatrix();
	glScalef(chapa_topo.largura-expessura_chapa*2-0.1,expessura_chapa,chapa_topo.comprimento-2+pokeball[10].z-raio_pokeball-intervalo_pokeball);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	configura_material(5);
	glTranslatef(-50,chapa_frente_superior.largura/2-expessura_chapa/2,chapa_topo.comprimento/2+2*expessura_chapa-75+4);
	glPushMatrix();
	glScalef(chapa_topo.largura/2-expessura_chapa*2-0.1,expessura_chapa,2*(raio_pokeball+intervalo_pokeball)+8);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	configura_material(5);
	glTranslatef(80,chapa_frente_superior.largura/2-expessura_chapa/2,chapa_topo.comprimento/2+2*expessura_chapa-75+4);
	glPushMatrix();
	glScalef(chapa_topo.largura/5-expessura_chapa*2,expessura_chapa,2*(raio_pokeball+intervalo_pokeball)+8);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	configura_material(5);
	glTranslatef(80-(chapa_topo.largura/5-expessura_chapa*2)/2-expessura_chapa/2,chapa_frente_superior.largura/2-raio_pokeball-intervalo_pokeball-4,chapa_topo.comprimento/2+2*expessura_chapa-75+4);
	glPushMatrix();
	glScalef(expessura_chapa,2*(raio_pokeball+intervalo_pokeball)+8,2*(raio_pokeball+intervalo_pokeball)+8);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	configura_material(5);
	glTranslatef(-50+(chapa_topo.largura/2-expessura_chapa*2-0.1)/2+expessura_chapa/2,chapa_frente_superior.largura/2-raio_pokeball-intervalo_pokeball-4,chapa_topo.comprimento/2+2*expessura_chapa-75+4);
	glPushMatrix();
	glScalef(expessura_chapa,2*(raio_pokeball+intervalo_pokeball)+8,2*(raio_pokeball+intervalo_pokeball)+8);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	configura_material(5);
	glTranslatef(-50+(chapa_topo.largura/2-expessura_chapa*2-0.1)/2-expessura_chapa/2+20,chapa_frente_superior.largura/2-raio_pokeball-intervalo_pokeball-4,chapa_topo.comprimento/2+2*expessura_chapa-75+4-raio_pokeball-intervalo_pokeball-4+2*(raio_pokeball+intervalo_pokeball)+8);
	glPushMatrix();
	glScalef(2*(raio_pokeball+intervalo_pokeball)+50,2*(raio_pokeball+intervalo_pokeball)+8,expessura_chapa);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	configura_material(1);
	glPushMatrix();
	glTranslatef(0,chapa_frente_superior.largura/2-expessura_chapa/2-2*(raio_pokeball+intervalo_pokeball)-8,chapa_topo.comprimento/2-expessura_chapa/2);
	glPushMatrix();
	glScalef(chapa_topo.largura-expessura_chapa*2-0.1,expessura_chapa,chapa_topo.comprimento-2);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	chapa_chao.x_minimo=-1*chapa_chao.comprimento/2;
	chapa_chao.x_maximo=chapa_chao.comprimento/2;
	chapa_chao.y_maximo=chapa_frente_inferior.y_maximo;
	chapa_chao.y_minimo=chapa_frente_superior.largura/2-expessura_chapa/2;
	chapa_chao.z_minimo=-1*expessura_chapa/2;
	chapa_chao.z_maximo=largura_tela-expessura_chapa/2;
	configura_material(1);

	glPushMatrix();
	glTranslatef(largura_maquina/2 - expessura_chapa/2,0,largura_maquina/2-expessura_chapa/2);
	glScalef(expessura_chapa,chapa_lateral_frente_inferior.largura,chapa_lateral_frente_inferior.comprimento);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-largura_maquina/2 + expessura_chapa/2,0,largura_maquina/2-expessura_chapa/2);
	glScalef(expessura_chapa,chapa_lateral_atras_inferior.largura,chapa_lateral_atras_inferior.comprimento);
	glutSolidCube(1);
	glPopMatrix();

	chapa_lateral_frente_inferior.x_minimo=largura_maquina/2-expessura_chapa;
	chapa_lateral_frente_inferior.x_maximo=largura_maquina/2;
	chapa_lateral_frente_inferior.y_minimo=-1*chapa_lateral_frente_inferior.largura/2;
	chapa_lateral_frente_inferior.y_maximo=chapa_lateral_frente_inferior.largura/2;
	chapa_lateral_frente_inferior.z_minimo=-1*expessura_chapa/2;
	chapa_lateral_frente_inferior.z_maximo=chapa_lateral_frente_inferior.z_minimo+largura_maquina;

	chapa_lateral_atras_inferior.x_minimo=expessura_chapa-largura_maquina/2;
	chapa_lateral_atras_inferior.x_maximo=-1*largura_maquina/2;
	chapa_lateral_atras_inferior.y_minimo=-1*chapa_lateral_atras_inferior.largura/2;
	chapa_lateral_atras_inferior.y_maximo=chapa_lateral_atras_inferior.largura/2;
	chapa_lateral_atras_inferior.z_minimo=-1*expessura_chapa/2;
	chapa_lateral_atras_inferior.z_maximo=chapa_lateral_frente_inferior.z_minimo+largura_maquina;

	glPushMatrix();
	glTranslatef(largura_maquina/2-expessura_chapa/2,altura_maquina/2 + chapa_lateral_frente_inferior.y_minimo,chapa_lateral_frente_inferior.z_minimo+15);
	glScalef(expessura_chapa,altura_maquina,30);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(largura_maquina/2-expessura_chapa/2,altura_maquina/2 + chapa_lateral_frente_inferior.y_minimo,chapa_lateral_frente_inferior.z_maximo-15);
	glScalef(expessura_chapa,altura_maquina,30);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-largura_maquina/2+expessura_chapa/2,altura_maquina/2 + chapa_lateral_atras_inferior.y_minimo,chapa_lateral_atras_inferior.z_minimo+15);
	glScalef(expessura_chapa,altura_maquina,30);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-largura_maquina/2+expessura_chapa/2,altura_maquina/2 + chapa_lateral_atras_inferior.y_minimo,chapa_lateral_atras_inferior.z_maximo-15);
	glScalef(expessura_chapa,altura_maquina,30);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,altura_maquina-chapa_frente_superior.largura,0);
	glPushMatrix();
	glTranslatef(largura_maquina/2 - expessura_chapa/2,0,largura_maquina/2-expessura_chapa/2);
	glScalef(expessura_chapa,chapa_lateral_frente_superior.largura,chapa_lateral_frente_superior.comprimento);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-largura_maquina/2 + expessura_chapa/2,0,largura_maquina/2-expessura_chapa/2);
	glScalef(expessura_chapa,chapa_lateral_atras_inferior.largura,chapa_lateral_atras_inferior.comprimento);
	glutSolidCube(1);
	glPopMatrix();

	chapa_lateral_frente_superior.x_minimo=largura_maquina/2-expessura_chapa;
	chapa_lateral_frente_superior.x_maximo=largura_maquina/2;
	chapa_lateral_frente_superior.y_minimo=altura_maquina-chapa_lateral_frente_superior.largura;
	chapa_lateral_frente_superior.y_maximo=altura_maquina-chapa_lateral_frente_superior.largura/2;
	chapa_lateral_frente_superior.z_minimo=-1*expessura_chapa/2;
	chapa_lateral_frente_superior.z_maximo=largura_maquina-expessura_chapa/2;

	chapa_lateral_atras_inferior.x_minimo=-1*largura_maquina/2+expessura_chapa;
	chapa_lateral_atras_inferior.x_maximo=-1*largura_maquina/2;
	chapa_lateral_atras_inferior.y_minimo=-1*chapa_lateral_frente_superior.largura/2;
	chapa_lateral_atras_inferior.y_maximo=chapa_lateral_frente_superior.largura/2;
	chapa_lateral_atras_inferior.z_minimo=-1*expessura_chapa/2;
	chapa_lateral_atras_inferior.z_maximo=largura_maquina-expessura_chapa/2;
	glPopMatrix();
	configura_material(1);
	glPushMatrix();
	glTranslatef(0,-largura_chapa/2-110,0);
	glScalef(largura_maquina-2*30,220,expessura_chapa);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(chapa_frente_inferior.x_minimo+15,chapa_frente_inferior.y_minimo-altura_maquina/2,0);
	glScalef(30,altura_maquina,expessura_chapa);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(chapa_frente_inferior.x_maximo-15,chapa_frente_inferior.y_minimo-altura_maquina/2,0);
	glScalef(30,altura_maquina,expessura_chapa);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,largura_maquina-expessura_chapa);

	glPushMatrix();
	glTranslatef(0,-largura_chapa/2-110,0);
	glScalef(largura_maquina-2*30,220,expessura_chapa);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(chapa_frente_inferior.x_minimo+15,chapa_frente_inferior.y_minimo-altura_maquina/2,0);
	glScalef(30,altura_maquina,expessura_chapa);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(chapa_frente_inferior.x_maximo-15,chapa_frente_inferior.y_minimo-altura_maquina/2,0);
	glScalef(30,altura_maquina,expessura_chapa);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(largura_maquina/2 - expessura_chapa/2,-largura_chapa/2-110,largura_maquina/2-expessura_chapa/2);
	glScalef(expessura_chapa,220,largura_maquina-2*30);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(largura_maquina/2-expessura_chapa/2,chapa_frente_inferior.y_minimo-altura_maquina/2,chapa_lateral_frente_inferior.z_minimo+15);
	glScalef(expessura_chapa,altura_maquina,30);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(largura_maquina/2-expessura_chapa/2,chapa_frente_inferior.y_minimo-altura_maquina/2,chapa_lateral_frente_inferior.z_maximo-15);
	glScalef(expessura_chapa,altura_maquina,30);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-largura_maquina+expessura_chapa,0,0);

	glPushMatrix();
	glTranslatef(largura_maquina/2 - expessura_chapa/2,-largura_chapa/2-110,largura_maquina/2-expessura_chapa/2);
	glScalef(expessura_chapa,220,largura_maquina-2*30);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(largura_maquina/2-expessura_chapa/2,chapa_frente_inferior.y_minimo-altura_maquina/2,chapa_lateral_frente_inferior.z_minimo+15);
	glScalef(expessura_chapa,altura_maquina,30);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(largura_maquina/2-expessura_chapa/2,chapa_frente_inferior.y_minimo-altura_maquina/2,chapa_lateral_frente_inferior.z_maximo-15);
	glScalef(expessura_chapa,altura_maquina,30);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}
void inicializa()
{
	glEnable(GL_LESS);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH);
	chapa_topo.largura=largura_maquina;
	chapa_topo.comprimento=largura_maquina;
	chapa_chao.largura=largura_maquina;
	chapa_chao.comprimento=largura_maquina;
	chapa_frente_inferior.comprimento=largura_maquina;
	chapa_frente_superior.comprimento=largura_maquina;
	chapa_atras_inferior.comprimento=largura_maquina;
	chapa_atras_superior.comprimento=largura_maquina;
	chapa_lateral_frente_inferior.comprimento=largura_maquina;
	chapa_lateral_frente_superior.comprimento=largura_maquina;
	chapa_lateral_atras_inferior.comprimento=largura_maquina;
	chapa_lateral_atras_superior.comprimento=largura_maquina;
	chapa_frente_inferior.largura=largura_chapa;
	chapa_frente_superior.largura=largura_chapa;
	chapa_atras_inferior.largura=largura_chapa;
	chapa_atras_superior.largura=largura_chapa;
	chapa_lateral_frente_inferior.largura=largura_chapa;
	chapa_lateral_frente_superior.largura=largura_chapa;
	chapa_lateral_atras_inferior.largura=largura_chapa;
	chapa_lateral_atras_superior.largura=largura_chapa;
	garra.raio=10;
	garra.x=0;
	garra.y=altura_maquina/2-garra.raio-largura_chapa;
	garra.z=0;

	incremento_anulo_cam=0.7;
	fi=0;
	teta=0;
	cam.x=sin(teta*PI/180)*raio_camera;
	cam.y=sin(fi*PI/180)*raio_camera;
	cam.z=cos(fi*PI/180)*raio_camera;
	cam.w=1;

	botao1.largura=90;
	botao1.comprimento=200;
	botao1.x=-400;
	botao1.y=200;

	botao2.largura=90;
	botao2.comprimento=200;
	botao2.x=-400;
	botao2.y=-botao2.largura/2;

	botao3.largura=90;
	botao3.comprimento=200;
	botao3.x=-400;
	botao3.y=-200 - botao2.largura;

	botao4.largura=90;
	botao4.comprimento=200;
	botao4.x=400-botao4.comprimento;
	botao4.y=200;

	botao5.largura=90;
	botao5.comprimento=200;
	botao5.x=400-botao5.comprimento;
	botao5.y=-botao5.largura/2;

	botao6.largura=90;
	botao6.comprimento=200;
	botao6.x=400-botao6.comprimento;
	botao6.y=-200 - botao6.largura;

	botao1.x_minimo=botao1.x;
	botao1.x_maximo=botao1.x+botao1.comprimento;
	botao1.y_minimo=botao1.y;
	botao1.y_maximo=botao1.y+botao1.largura;

	botao2.x_minimo=botao2.x;
	botao2.x_maximo=botao2.x+botao2.comprimento;
	botao2.y_minimo=botao2.y;
	botao2.y_maximo=botao2.y+botao2.largura;

	botao3.x_minimo=botao3.x;
	botao3.x_maximo=botao3.x+botao3.comprimento;
	botao3.y_minimo=botao3.y;
	botao3.y_maximo=botao3.y+botao3.largura;

	botao4.x_minimo=botao4.x;
	botao4.x_maximo=botao4.x+botao4.comprimento;
	botao4.y_minimo=botao4.y;
	botao4.y_maximo=botao4.y+botao4.largura;

	botao5.x_minimo=botao5.x;
	botao5.x_maximo=botao5.x+botao5.comprimento;
	botao5.y_minimo=botao5.y;
	botao5.y_maximo=botao5.y+botao5.largura;

	botao6.x_minimo=botao6.x;
	botao6.x_maximo=botao6.x+botao6.comprimento;
	botao6.y_minimo=botao6.y;
	botao6.y_maximo=botao6.y+botao6.largura;

	pokemon.largura=450;
	pokemon.comprimento=450;
	pokemon.x=-pokemon.largura/2;
	pokemon.y=-2*pokemon.comprimento/3;

	pokemon.x_minimo=pokemon.x;
	pokemon.x_maximo=pokemon.x+pokemon.comprimento;
	pokemon.y_minimo=pokemon.y;
	pokemon.y_maximo=pokemon.y+pokemon.largura;

	glClearColor(1, 1, 1, 1);
}
void inicializa_textura()
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	texturaLogo = SOIL_load_OGL_texture(
		"img/LogoPokemon.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);

	if (texturaLogo == 0)
	{
		printf("0Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	textura_fogos = SOIL_load_OGL_texture(
		"img/fogos.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);

	if (textura_fogos== 0)
	{
		printf("0Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	cursor = SOIL_load_OGL_texture(
		"img/cursor.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);

	if (cursor == 0)
	{
		printf("cursor do SOIL: '%s'\n", SOIL_last_result());
	}


	texturaPokemon1 = SOIL_load_OGL_texture(
		"img/Pokemon0.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);

	if (texturaPokemon1 == 0)
	{
		printf("1Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon2 = SOIL_load_OGL_texture(
		"img/Pokemon1.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);

	if (texturaPokemon2 == 0)
	{
		printf("2Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon3 = SOIL_load_OGL_texture(
		"img/Pokemon2.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);

	if (texturaPokemon3 == 0)
	{
		printf("3Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon4 = SOIL_load_OGL_texture(
		"img/Pokemon3.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);

	if (texturaPokemon4 == 0)
	{
		printf("4Erro do SOIL: '%s'\n", SOIL_last_result());
	}
	texturaPokemon5 = SOIL_load_OGL_texture(
		"img/Pokemon4.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);

	if (texturaPokemon5 == 0)
	{
		printf("5Erro do SOIL: '%s'\n", SOIL_last_result());
	}
	texturaPokemon6 = SOIL_load_OGL_texture(
		"img/Pokemon5.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);

	if (texturaPokemon6 == 0)
	{
		printf("6Erro do SOIL: '%s'\n", SOIL_last_result());
	}
	texturaPokemon7 = SOIL_load_OGL_texture(
		"img/Pokemon6.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);


	if (texturaPokemon7 == 0)
	{
		printf("7Erro do SOIL: '%s'\n", SOIL_last_result());
	}
	texturaPokemon8 = SOIL_load_OGL_texture(
		"img/Pokemon7.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);


	if (texturaPokemon8 == 0)
	{
		printf("8Erro do SOIL: '%s'\n", SOIL_last_result());
	}
	texturaPokemon9 = SOIL_load_OGL_texture(
		"img/Pokemon8.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);

	if (texturaPokemon9 == 0)
	{
		printf("9Erro do SOIL: '%s'\n", SOIL_last_result());
	}
	texturaPokemon10 = SOIL_load_OGL_texture(
		"img/Pokemon9.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon10 == 0)
	{
		printf("10Erro do SOIL: '%s'\n", SOIL_last_result());
	}
	texturaPokemon11 = SOIL_load_OGL_texture(
		"img/Pokemon10.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon11 == 0)
	{
		printf("11Erro do SOIL: '%s'\n", SOIL_last_result());
	}
	texturaPokemon12 = SOIL_load_OGL_texture(
		"img/Pokemon11.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon12 == 0)
	{
		printf("12Erro do SOIL: '%s'\n", SOIL_last_result());
	}
	texturaPokemon13 = SOIL_load_OGL_texture(
		"img/Pokemon12.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon13 == 0)
	{
		printf("13Erro do SOIL: '%s'\n", SOIL_last_result());
	}
	texturaPokemon14 = SOIL_load_OGL_texture(
		"img/Pokemon13.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon14 == 0)
	{
		printf("14Erro do SOIL: '%s'\n", SOIL_last_result());
	}
	texturaPokemon15 = SOIL_load_OGL_texture(
		"img/Pokemon14.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);


	if (texturaPokemon15 == 0)
	{
		printf("15Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon16 = SOIL_load_OGL_texture(
		"img/Pokemon15.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon16 == 0)
	{
		printf("16Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon17 = SOIL_load_OGL_texture(
		"img/Pokemon16.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);

	if (texturaPokemon17 == 0)
	{
		printf("17Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon18 = SOIL_load_OGL_texture(
		"img/Pokemon17.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);

	if (texturaPokemon18 == 0)
	{
		printf("18Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon19 = SOIL_load_OGL_texture(
		"img/Pokemon18.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);

	if (texturaPokemon19 == 0)
	{
		printf("19Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon20 = SOIL_load_OGL_texture(
		"img/Pokemon19.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon20 == 0)
	{
		printf("20Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon21 = SOIL_load_OGL_texture(
		"img/Pokemon20.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon21 == 0)
	{
		printf("21Erro do SOIL: '%s'\n", SOIL_last_result());
	}
	texturaPokemon22 = SOIL_load_OGL_texture(
		"img/Pokemon21.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);

	if (texturaPokemon22 == 0)
	{
		printf("22Erro do SOIL: '%s'\n", SOIL_last_result());
	}
	texturaPokemon23 = SOIL_load_OGL_texture(
		"img/Pokemon22.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);

	if (texturaPokemon23 == 0)
	{
		printf("23Erro do SOIL: '%s'\n", SOIL_last_result());
	}
	texturaPokemon24 = SOIL_load_OGL_texture(
		"img/Pokemon23.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon24 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}
	texturaPokemon25 = SOIL_load_OGL_texture(
		"img/Pokemon24.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon25 == 0)
	{
		printf("25Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon26 = SOIL_load_OGL_texture(
		"img/Pokemon25.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon26 == 0)
	{
		printf("26Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon27 = SOIL_load_OGL_texture(
		"img/Pokemon26.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon27 == 0)
	{
		printf("27Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon28 = SOIL_load_OGL_texture(
		"img/Pokemon27.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon28 == 0)
	{
		printf("28Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon29 = SOIL_load_OGL_texture(
		"img/Pokemon28.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon29 == 0)
	{
		printf("29Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon30 = SOIL_load_OGL_texture(
		"img/Pokemon29.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon30 == 0)
	{
		printf("30Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon31 = SOIL_load_OGL_texture(
		"img/Pokemon30.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon31 == 0)
	{
		printf("21Erro do SOIL: '%s'\n", SOIL_last_result());
	}
	texturaPokemon32 = SOIL_load_OGL_texture(
		"img/Pokemon31.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon32 == 0)
	{
		printf("22Erro do SOIL: '%s'\n", SOIL_last_result());
	}
	texturaPokemon33 = SOIL_load_OGL_texture(
		"img/Pokemon32.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon33 == 0)
	{
		printf("23Erro do SOIL: '%s'\n", SOIL_last_result());
	}
	texturaPokemon34 = SOIL_load_OGL_texture(
		"img/Pokemon33.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon34 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon35 = SOIL_load_OGL_texture(
		"img/Pokemon43.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon35 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon36 = SOIL_load_OGL_texture(
		"img/Pokemon44.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon36 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon37 = SOIL_load_OGL_texture(
		"img/Pokemon45.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon37 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon38 = SOIL_load_OGL_texture(
		"img/Pokemon46.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon38 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon39 = SOIL_load_OGL_texture(
		"img/Pokemon47.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon39 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon40 = SOIL_load_OGL_texture(
		"img/Pokemon48.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon40 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon41 = SOIL_load_OGL_texture(
		"img/Pokemon49.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon41 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon42 = SOIL_load_OGL_texture(
		"img/Pokemon50.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon42 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon43 = SOIL_load_OGL_texture(
		"img/Pokemon51.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon43 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon44 = SOIL_load_OGL_texture(
		"img/Pokemon52.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon44 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon45 = SOIL_load_OGL_texture(
		"img/Pokemon53.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon45 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}
	texturaPokemon46 = SOIL_load_OGL_texture(
		"img/Pokemon54.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon46 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}
	texturaPokemon47 = SOIL_load_OGL_texture(
		"img/Pokemon55.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon47 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon48 = SOIL_load_OGL_texture(
		"img/Pokemon56.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon48== 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon49 = SOIL_load_OGL_texture(
		"img/Pokemon57.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon49== 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon50 = SOIL_load_OGL_texture(
		"img/Pokemon58.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon50== 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon51 = SOIL_load_OGL_texture(
		"img/Pokemon59.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon51 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon52 = SOIL_load_OGL_texture(
		"img/Pokemon60.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon52 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon53 = SOIL_load_OGL_texture(
		"img/Pokemon61.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon53 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon54 = SOIL_load_OGL_texture(
		"img/Pokemon62.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon54 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon55 = SOIL_load_OGL_texture(
		"img/Pokemon63.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon55 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}
	texturaPokemon56 = SOIL_load_OGL_texture(
		"img/Pokemon64.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon56 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}
	texturaPokemon57 = SOIL_load_OGL_texture(
		"img/Pokemon65.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon57 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon58 = SOIL_load_OGL_texture(
		"img/Pokemon66.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon58== 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon59 = SOIL_load_OGL_texture(
		"img/Pokemon67.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon59== 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon60 = SOIL_load_OGL_texture(
		"img/Pokemon68.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon60== 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon61 = SOIL_load_OGL_texture(
		"img/Pokemon69.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon61 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon62 = SOIL_load_OGL_texture(
		"img/Pokemon70.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon62 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon63 = SOIL_load_OGL_texture(
		"img/Pokemon71.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon63 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon64 = SOIL_load_OGL_texture(
		"img/Pokemon72.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon64 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon65 = SOIL_load_OGL_texture(
		"img/Pokemon73.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon65 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}
	texturaPokemon66 = SOIL_load_OGL_texture(
		"img/Pokemon74.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon66 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}
	texturaPokemon67 = SOIL_load_OGL_texture(
		"img/Pokemon75.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon67 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon68 = SOIL_load_OGL_texture(
		"img/Pokemon76.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon68== 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon69 = SOIL_load_OGL_texture(
		"img/Pokemon77.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon69== 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon70 = SOIL_load_OGL_texture(
		"img/Pokemon78.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon70== 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon71 = SOIL_load_OGL_texture(
		"img/Pokemon79.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon71 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon72 = SOIL_load_OGL_texture(
		"img/Pokemon80.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon72 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon73 = SOIL_load_OGL_texture(
		"img/Pokemon81.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon73 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon74 = SOIL_load_OGL_texture(
		"img/Pokemon82.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon74 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon75 = SOIL_load_OGL_texture(
		"img/Pokemon83.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon75 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}
	texturaPokemon76 = SOIL_load_OGL_texture(
		"img/Pokemon84.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon76 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}
	texturaPokemon77 = SOIL_load_OGL_texture(
		"img/Pokemon85.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon77 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon78 = SOIL_load_OGL_texture(
		"img/Pokemon86.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon78== 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon79 = SOIL_load_OGL_texture(
		"img/Pokemon87.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon79== 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon80 = SOIL_load_OGL_texture(
		"img/Pokemon88.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon80== 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon81 = SOIL_load_OGL_texture(
		"img/Pokemon89.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon81 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon82 = SOIL_load_OGL_texture(
		"img/Pokemon90.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon82 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon83 = SOIL_load_OGL_texture(
		"img/Pokemon91.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon83 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon84 = SOIL_load_OGL_texture(
		"img/Pokemon92.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon84 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokemon85 = SOIL_load_OGL_texture(
		"img/Pokemon93.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (texturaPokemon83 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	textura_badges1 = SOIL_load_OGL_texture(
		"img/badges1.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );


	if (textura_badges1 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	textura_badges2 = SOIL_load_OGL_texture(
		"img/badges2.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );


	if (textura_badges2 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	textura_badges3 = SOIL_load_OGL_texture(
		"img/badges3.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );


	if (textura_badges3 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	textura_badges4 = SOIL_load_OGL_texture(
		"img/badges4.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );


	if (textura_badges4 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	textura_badges5 = SOIL_load_OGL_texture(
		"img/badges5.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );


	if (textura_badges5 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	textura_badges6 = SOIL_load_OGL_texture(
		"img/badges6.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );


	if (textura_badges6 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}
	textura_badges7 = SOIL_load_OGL_texture(
		"img/badges7.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );


	if (textura_badges7 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}
	textura_badges8 = SOIL_load_OGL_texture(
		"img/badges8.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );


	if (textura_badges8 == 0)
	{
		printf("24Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	textura_pokebola = SOIL_load_OGL_texture(
		"img/pokebola.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
		);
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );


	if (textura_pokebola == 0)
	{
		printf("1000Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokeball_1 = SOIL_load_OGL_texture
		            (
		"img/pokeball1.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	                    );

	if (texturaPokeball_1 == 0)
	{
		printf("17Erro do SOIL: '%s'\n", SOIL_last_result());
	}
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	menu_principal = SOIL_load_OGL_texture
		         (
		"img/tela_espelho.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	                 );

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	if (menu_principal == 0)
	{
		printf("177Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	tutorial1 = SOIL_load_OGL_texture
		    (
		"img/nitendo1.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	            );

	if (tutorial1 == 0)
	{
		printf("1tutorial17Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	novo_jogo = SOIL_load_OGL_texture
		    (
		"img/tela_poker1.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	            );

	if (novo_jogo == 0)
	{
		printf("1tutorial17Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );



	tutorial2 = SOIL_load_OGL_texture
		    (
		"img/nitendo2.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	            );

	if (tutorial2 == 0)
	{
		printf("17tutorial2Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	premio = SOIL_load_OGL_texture
		 (
		"img/premio.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	         );

	if (premio == 0)
	{
		printf("1premio7Erro do SOIL: '%s'\n", SOIL_last_result());
	}


	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );


	continuar = SOIL_load_OGL_texture
		    (
		"img/tela_melancia.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	            );

	if (continuar == 0)
	{
		printf("1continuar7Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	carregando1 = SOIL_load_OGL_texture
		      (
		"img/tela_sono1.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	              );

	if (carregando1 == 0)
	{
		printf("1carregando7Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	carregando2 = SOIL_load_OGL_texture
		      (
		"img/tela_sono2.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	              );

	if (carregando2 == 0)
	{
		printf("1carregando7Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	carregando3 = SOIL_load_OGL_texture
		      (
		"img/tela_sono3.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	              );

	if (carregando3 == 0)
	{
		printf("1carregando7Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	carregando4 = SOIL_load_OGL_texture
		      (
		"img/tela_sono4.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	              );

	if (carregando4 == 0)
	{
		printf("1carregando7Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	carregando5 = SOIL_load_OGL_texture
		      (
		"img/tela_sono5.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	              );

	if (carregando5 == 0)
	{
		printf("1carregando7Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	botao_nj = SOIL_load_OGL_texture
		   (
		"img/botao1.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	           );

	if (botao_nj == 0)
	{
		printf("botao_nj do SOIL: '%s'\n", SOIL_last_result());
	}

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	botao_t = SOIL_load_OGL_texture
		  (
		"img/botao2.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	          );

	if (botao_t == 0)
	{
		printf("botao_t do SOIL: '%s'\n", SOIL_last_result());
	}

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	botao_s = SOIL_load_OGL_texture
		  (
		"img/botao3.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	          );

	if (botao_s == 0)
	{
		printf("botao_s do SOIL: '%s'\n", SOIL_last_result());
	}

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	botao_v = SOIL_load_OGL_texture
		  (
		"img/botao4.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	          );

	if (botao_v == 0)
	{
		printf("botao_v do SOIL: '%s'\n", SOIL_last_result());
	}

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	botao_c = SOIL_load_OGL_texture
		  (
		"img/botao5.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	          );

	if (botao_c == 0)
	{
		printf("botao_c do SOIL: '%s'\n", SOIL_last_result());
	}

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	botao_n = SOIL_load_OGL_texture
		  (
		"img/botao6.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	          );

	if (botao_n == 0)
	{
		printf("botao_n do SOIL: '%s'\n", SOIL_last_result());
	}

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	botao_m = SOIL_load_OGL_texture
		  (
		"img/botao7.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	          );

	if (botao_m == 0)
	{
		printf("botao_m do SOIL: '%s'\n", SOIL_last_result());
	}

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	botao_p = SOIL_load_OGL_texture
		  (
		"img/botao8.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	          );

	if (botao_p == 0)
	{
		printf("botao_p do SOIL: '%s'\n", SOIL_last_result());
	}

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	botao_f = SOIL_load_OGL_texture
		  (
		"img/botao9.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	          );

	if (botao_f == 0)
	{
		printf("botao_f do SOIL: '%s'\n", SOIL_last_result());
	}

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	facil = SOIL_load_OGL_texture
		(
		"img/facil.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	        );

	if (facil == 0)
	{
		printf("facil do SOIL: '%s'\n", SOIL_last_result());
	}

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	medio = SOIL_load_OGL_texture
		(
		"img/medio.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	        );

	if (medio == 0)
	{
		printf("medio do SOIL: '%s'\n", SOIL_last_result());
	}

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	dificil = SOIL_load_OGL_texture
		  (
		"img/dificil.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	          );

	if (dificil == 0)
	{
		printf("medio do SOIL: '%s'\n", SOIL_last_result());
	}

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );



	botao_d = SOIL_load_OGL_texture
		  (
		"img/botao10.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	          );

	if (botao_d == 0)
	{
		printf("botao_d do SOIL: '%s'\n", SOIL_last_result());
	}

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );


	ambiente1 = SOIL_load_OGL_texture
		    (
		"img/ambiente1.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	            );

	if (ambiente1 == 0)
	{
		printf("170Erro do SOIL: '%s'\n", SOIL_last_result());
	}

	texturaPokeball_2 = SOIL_load_OGL_texture
		            (
		"img/pokeball2.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	                    );

	if (texturaPokeball_2 == 0)
	{
		printf("170Erro do SOIL: '%s'\n", SOIL_last_result());
	}
}
void skybox()
{
	configura_material(2);
	tex=1;
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ambiente1);
	glPushMatrix();
	glTranslatef(0,100,0);
	glRotatef(-90,1,0,0);
	solidSphere(600,60,60);
	glPopMatrix();
	tex=0;
}
void aplica_texturas()
{
	glColor4f(1,1,1,1);
	tex=1;
	configura_material(2);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texturaLogo);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-largura_maquina/2+largura_chapa,altura_maquina/2-largura_chapa,largura_maquina/2);
	glTexCoord2f(1, 0);
	glVertex3f(largura_maquina/2-largura_chapa,altura_maquina/2-largura_chapa,largura_maquina/2);
	glTexCoord2f(1, 1);
	glVertex3f(largura_maquina/2-largura_chapa,altura_maquina/2-4,largura_maquina/2);
	glTexCoord2f(0, 1);
	glVertex3f(-largura_maquina/2+largura_chapa,altura_maquina/2-4,largura_maquina/2);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura_badges1);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-largura_maquina/2,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa),largura_maquina/2);
	glTexCoord2f(1, 0);
	glVertex3f(-largura_maquina/2+35,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa),largura_maquina/2);
	glTexCoord2f(1, 1);
	glVertex3f(-largura_maquina/2+35,altura_maquina/2-largura_chapa,largura_maquina/2);
	glTexCoord2f(0, 1);
	glVertex3f(-largura_maquina/2,altura_maquina/2-largura_chapa,largura_maquina/2);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura_badges2);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(largura_maquina/2-33,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa),largura_maquina/2);
	glTexCoord2f(1, 0);
	glVertex3f(largura_maquina/2,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa),largura_maquina/2);
	glTexCoord2f(1, 1);
	glVertex3f(largura_maquina/2,altura_maquina/2-largura_chapa,largura_maquina/2);
	glTexCoord2f(0, 1);
	glVertex3f(largura_maquina/2-33,altura_maquina/2-largura_chapa,largura_maquina/2);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texturaPokemon1);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-largura_maquina/2,altura_maquina/2-largura_chapa,largura_maquina/2);
	glTexCoord2f(1, 0);
	glVertex3f(-largura_maquina/2+largura_chapa,altura_maquina/2-largura_chapa,largura_maquina/2);
	glTexCoord2f(1, 1);
	glVertex3f(-largura_maquina/2+largura_chapa,altura_maquina/2-4,largura_maquina/2);
	glTexCoord2f(0, 1);
	glVertex3f(-largura_maquina/2,altura_maquina/2-4,largura_maquina/2);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texturaPokemon2);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-largura_maquina/2,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-largura_chapa,largura_maquina/2);
	glTexCoord2f(1, 0);
	glVertex3f(-largura_maquina/2+largura_chapa,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-largura_chapa,largura_maquina/2);
	glTexCoord2f(1, 1);
	glVertex3f(-largura_maquina/2+largura_chapa,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-4,largura_maquina/2);
	glTexCoord2f(0, 1);
	glVertex3f(-largura_maquina/2,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-4,largura_maquina/2);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texturaPokemon6);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(largura_maquina/2-largura_chapa,altura_maquina/2-largura_chapa,largura_maquina/2);
	glTexCoord2f(1, 0);
	glVertex3f(largura_maquina/2,altura_maquina/2-largura_chapa,largura_maquina/2);
	glTexCoord2f(1, 1);
	glVertex3f(largura_maquina/2,altura_maquina/2-4,largura_maquina/2);
	glTexCoord2f(0, 1);
	glVertex3f(largura_maquina/2-largura_chapa,altura_maquina/2-4,largura_maquina/2);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texturaPokemon8);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(largura_maquina/2-largura_chapa,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-largura_chapa,largura_maquina/2);
	glTexCoord2f(1, 0);
	glVertex3f(largura_maquina/2,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-largura_chapa,largura_maquina/2);
	glTexCoord2f(1, 1);
	glVertex3f(largura_maquina/2,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-4,largura_maquina/2);
	glTexCoord2f(0, 1);
	glVertex3f(largura_maquina/2-largura_chapa,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-4,largura_maquina/2);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura_pokebola);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-largura_chapa/2,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-largura_chapa,largura_maquina/2);
	glTexCoord2f(1, 0);
	glVertex3f(largura_chapa/2,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-largura_chapa,largura_maquina/2);
	glTexCoord2f(1, 1);
	glVertex3f(largura_chapa/2,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-4,largura_maquina/2);
	glTexCoord2f(0, 1);
	glVertex3f(-largura_chapa/2,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-4,largura_maquina/2);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texturaLogo);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa,largura_maquina/2-largura_chapa-2);
	glTexCoord2f(1, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa,-largura_maquina/2+largura_chapa+2);
	glTexCoord2f(1, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-4,-largura_maquina/2+largura_chapa+2);
	glTexCoord2f(0, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-4,largura_maquina/2-largura_chapa-2);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texturaPokemon11);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa,largura_maquina/2-4);
	glTexCoord2f(1, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa,largura_maquina/2-largura_chapa-2);
	glTexCoord2f(1, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-4,largura_maquina/2-largura_chapa-2);
	glTexCoord2f(0, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-4,largura_maquina/2-4);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texturaPokemon69);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-largura_chapa,largura_maquina/2-4);
	glTexCoord2f(1, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-largura_chapa,largura_maquina/2-largura_chapa-2);
	glTexCoord2f(1, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-4,largura_maquina/2-largura_chapa-2);
	glTexCoord2f(0, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-4,largura_maquina/2-4);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura_badges3);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa),largura_maquina/2);
	glTexCoord2f(1, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa),largura_maquina/2-35);
	glTexCoord2f(1, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa,largura_maquina/2-35);
	glTexCoord2f(0, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa,largura_maquina/2);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura_badges4);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa),-largura_maquina/2+30);
	glTexCoord2f(1, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa),-largura_maquina/2-2);
	glTexCoord2f(1, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa,-largura_maquina/2-2);
	glTexCoord2f(0, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa,-largura_maquina/2+30);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texturaPokemon3);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa,-largura_maquina/2+largura_chapa-2);
	glTexCoord2f(1, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa,-largura_maquina/2-2);
	glTexCoord2f(1, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-4,-largura_maquina/2-2);
	glTexCoord2f(0, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-4,-largura_maquina/2+largura_chapa-2);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texturaPokemon81);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-largura_chapa,-largura_maquina/2+largura_chapa-2);
	glTexCoord2f(1, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-largura_chapa,-largura_maquina/2-2);
	glTexCoord2f(1, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-4,-largura_maquina/2-2);
	glTexCoord2f(0, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-4,-largura_maquina/2+largura_chapa-2);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura_pokebola);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-largura_chapa,-largura_chapa/2-2);
	glTexCoord2f(0, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-4,-largura_chapa/2-2);
	glTexCoord2f(1, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-4,largura_chapa/2-2);
	glTexCoord2f(1, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-largura_chapa,largura_chapa/2-2);
	glEnd();

	glPushMatrix();
	glRotatef(-180,0,1,0);

	glBindTexture(GL_TEXTURE_2D, texturaLogo);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-largura_maquina/2+largura_chapa,altura_maquina/2-largura_chapa,largura_maquina/2+2.1);
	glTexCoord2f(1, 0);
	glVertex3f(largura_maquina/2-largura_chapa,altura_maquina/2-largura_chapa,largura_maquina/2+2.1);
	glTexCoord2f(1, 1);
	glVertex3f(largura_maquina/2-largura_chapa,altura_maquina/2-4,largura_maquina/2+2.1);
	glTexCoord2f(0, 1);
	glVertex3f(-largura_maquina/2+largura_chapa,altura_maquina/2-4,largura_maquina/2+2.1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texturaLogo);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa,largura_maquina/2-largura_chapa);
	glTexCoord2f(1, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa,-largura_maquina/2+largura_chapa);
	glTexCoord2f(1, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-4,-largura_maquina/2+largura_chapa);
	glTexCoord2f(0, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-4,largura_maquina/2-largura_chapa);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texturaPokemon14);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-largura_maquina/2,altura_maquina/2-largura_chapa,largura_maquina/2+2.1);
	glTexCoord2f(1, 0);
	glVertex3f(-largura_maquina/2+largura_chapa,altura_maquina/2-largura_chapa,largura_maquina/2+2.1);
	glTexCoord2f(1, 1);
	glVertex3f(-largura_maquina/2+largura_chapa,altura_maquina/2-4,largura_maquina/2+2.1);
	glTexCoord2f(0, 1);
	glVertex3f(-largura_maquina/2,altura_maquina/2-4,largura_maquina/2+2.1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texturaPokemon10);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(largura_maquina/2-largura_chapa,altura_maquina/2-largura_chapa,largura_maquina/2+2.1);
	glTexCoord2f(1, 0);
	glVertex3f(largura_maquina/2,altura_maquina/2-largura_chapa,largura_maquina/2+2.1);
	glTexCoord2f(1, 1);
	glVertex3f(largura_maquina/2,altura_maquina/2-4,largura_maquina/2+2.1);
	glTexCoord2f(0, 1);
	glVertex3f(largura_maquina/2-largura_chapa,altura_maquina/2-4,largura_maquina/2+2.1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texturaLogo);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa,largura_maquina/2-largura_chapa);
	glTexCoord2f(1, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa,-largura_maquina/2+largura_chapa);
	glTexCoord2f(1, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-4,-largura_maquina/2+largura_chapa);
	glTexCoord2f(0, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-4,largura_maquina/2-largura_chapa);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texturaPokemon12);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa,largura_maquina/2);
	glTexCoord2f(1, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa,largura_maquina/2-largura_chapa);
	glTexCoord2f(1, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-4,largura_maquina/2-largura_chapa);
	glTexCoord2f(0, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-4,largura_maquina/2);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texturaPokemon9);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa,-largura_maquina/2+largura_chapa);
	glTexCoord2f(1, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa,-largura_maquina/2+4);
	glTexCoord2f(1, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-4,-largura_maquina/2+4);
	glTexCoord2f(0, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-4,-largura_maquina/2+largura_chapa);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, textura_badges5);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-largura_maquina/2-2,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa),largura_maquina/2+2.1);
	glTexCoord2f(1, 0);
	glVertex3f(-largura_maquina/2+35-2,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa),largura_maquina/2+2.1);
	glTexCoord2f(1, 1);
	glVertex3f(-largura_maquina/2+35-2,altura_maquina/2-largura_chapa,largura_maquina/2+2.1);
	glTexCoord2f(0, 1);
	glVertex3f(-largura_maquina/2-2,altura_maquina/2-largura_chapa,largura_maquina/2+2.1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura_badges6);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(largura_maquina/2-33+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa),largura_maquina/2+2.1);
	glTexCoord2f(1, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa),largura_maquina/2+2.1);
	glTexCoord2f(1, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa,largura_maquina/2+2.1);
	glTexCoord2f(0, 1);
	glVertex3f(largura_maquina/2-33+1,altura_maquina/2-largura_chapa,largura_maquina/2+2.1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura_badges7);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa),largura_maquina/2+2);
	glTexCoord2f(1, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa),largura_maquina/2-28);
	glTexCoord2f(1, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa,largura_maquina/2-28);
	glTexCoord2f(0, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa,largura_maquina/2+2);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura_badges8);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa),-largura_maquina/2+30+4);
	glTexCoord2f(1, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa),-largura_maquina/2+4);
	glTexCoord2f(1, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa,-largura_maquina/2+4);
	glTexCoord2f(0, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa,-largura_maquina/2+30+4);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texturaPokemon15);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-largura_chapa,-largura_maquina/2+largura_chapa);
	glTexCoord2f(1, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-largura_chapa,-largura_maquina/2);
	glTexCoord2f(1, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-4,-largura_maquina/2);
	glTexCoord2f(0, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-4,-largura_maquina/2+largura_chapa);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura_pokebola);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-largura_chapa,-largura_chapa/2);
	glTexCoord2f(0, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-4,-largura_chapa/2);
	glTexCoord2f(1, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-4,largura_chapa/2);
	glTexCoord2f(1, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-largura_chapa,largura_chapa/2);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texturaPokemon22);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-largura_chapa,largura_maquina/2);
	glTexCoord2f(1, 0);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-largura_chapa,largura_maquina/2-largura_chapa);
	glTexCoord2f(1, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-4,largura_maquina/2-largura_chapa);
	glTexCoord2f(0, 1);
	glVertex3f(largura_maquina/2+1,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-4,largura_maquina/2);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texturaPokemon41);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-largura_maquina/2,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-largura_chapa,largura_maquina/2+2.1);
	glTexCoord2f(1, 0);
	glVertex3f(-largura_maquina/2+largura_chapa,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-largura_chapa,largura_maquina/2+2.1);
	glTexCoord2f(1, 1);
	glVertex3f(-largura_maquina/2+largura_chapa,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-4,largura_maquina/2+2.1);
	glTexCoord2f(0, 1);
	glVertex3f(-largura_maquina/2,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-4,largura_maquina/2+2.1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texturaPokemon75);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(largura_maquina/2-largura_chapa,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-largura_chapa,largura_maquina/2+2.1);
	glTexCoord2f(1, 0);
	glVertex3f(largura_maquina/2,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-largura_chapa,largura_maquina/2+2.1);
	glTexCoord2f(1, 1);
	glVertex3f(largura_maquina/2,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-4,largura_maquina/2+2.1);
	glTexCoord2f(0, 1);
	glVertex3f(largura_maquina/2-largura_chapa,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-4,largura_maquina/2+2.1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura_pokebola);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-largura_chapa/2,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-largura_chapa,largura_maquina/2+2.1);
	glTexCoord2f(1, 0);
	glVertex3f(largura_chapa/2,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-largura_chapa,largura_maquina/2+2.1);
	glTexCoord2f(1, 1);
	glVertex3f(largura_chapa/2,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-4,largura_maquina/2+2.1);
	glTexCoord2f(0, 1);
	glVertex3f(-largura_chapa/2,altura_maquina/2-largura_chapa-(altura_maquina-2*largura_chapa)-4,largura_maquina/2+2.1);
	glEnd();


	glPopMatrix();



	tex=0;
	glDisable(GL_TEXTURE_2D);
}
void atoa()
{
	if(menu!=3)
	{
		glutPostRedisplay();
	}
}
int verifica_quadrante(double xy, double z)
{
	if(xy>0 && z>0)
	{
		return 1;
	}
	else if(xy<0 && z>0)
	{
		return 4;
	}

	else if(xy>0 && z<0)
	{
		return 2;
	}

	else{
		return 3;
	}
}
ponto camera(ponto mouse,ponto cam)
{
	if(mouse.porcentagem_y<=0.75 && mouse.porcentagem_y>=0.25 && mouse.porcentagem_x>=0 && mouse.porcentagem_x<=0.25)
	{
		if(garra_atras ==0 && garra_frente==0 && garra_esquerda==0 && garra_direita==0) {
			teta-=incremento_anulo_cam;
		}
	}
	else if(mouse.porcentagem_y<=0.75 && mouse.porcentagem_y>=0.25 && mouse.porcentagem_x>=0.75 && mouse.porcentagem_x<=1)
	{
		if(garra_atras ==0 && garra_frente==0 && garra_esquerda==0 && garra_direita==0) {
			teta+=incremento_anulo_cam;
		}
	}
	if(mouse.porcentagem_x<=0.75 && mouse.porcentagem_x>=0.25 && mouse.porcentagem_y>=0.75 && mouse.porcentagem_y<=1 && fi+incremento_anulo_cam<88)
	{
		fi+=incremento_anulo_cam;
	}
	else if(mouse.porcentagem_x<=0.75 && mouse.porcentagem_x>=0.25 && mouse.porcentagem_y<=0.25 && mouse.porcentagem_y>=0 && fi-incremento_anulo_cam>-6)
	{

		fi-=incremento_anulo_cam;
	}
	cam.x=sin(teta*PI/180)*raio_camera;
	cam.y=sin(fi*PI/180)*raio_camera;
	cam.z=cos(teta*PI/180)*raio_camera;
	return cam;
}
void posiciona_camera()
{
	glLoadIdentity();
	double x,y,z;
	cam=camera(cordenada_mouse,cam);
	x=cam.x;
	y=cam.y;
	z=cam.z+incremento;
	gluLookAt(x,y,z,0,0,-2,0,1,0);
}
void atualiza(int i)
{
	contador_frames++;
	if(dificuldade==1)
	{
		raio_alcance=6;
	}
	else if(dificuldade==2)
	{
		raio_alcance=3;
	}
	else if(dificuldade==3)
	{
		raio_alcance=1;
	}
	if(contador_frames%fps==0)
	{
		tempo++;
	}
	if(menu==6)
	{
		configura_material(1);
		inicializa_luz(1);
		movimentacao_garra();
		movimenta_garra();
		move_garra();
		posiciona_camera();
	}
	glutPostRedisplay();
	glutTimerFunc(intervalo_frames,atualiza,0);
}
void redimensiona(int width, int height)
{
	if(menu!=6)
	{
		largura_tela=width;
		altura_tela=height;
		glViewport (0, 0, (GLsizei)largura_tela, (GLsizei)height);
		glMatrixMode (GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-width/2,width/2,-height/2,height/2, -1.0, 10.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	else
	{
		largura_tela=width;
		altura_tela=height;
		glViewport (0, 0, (GLsizei)largura_tela, (GLsizei)height);
		glMatrixMode (GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60.0, (float)largura_tela/(float)altura_tela, 1, 1200);
		glMatrixMode(GL_MODELVIEW);
		posiciona_camera();
	}
}
void solidCylinder(GLdouble base, GLdouble top, GLdouble height, GLint slices,GLint stacks)
{
	GLUquadricObj *quadObj= gluNewQuadric();
	gluQuadricDrawStyle(quadObj, GLU_FILL);
	gluQuadricNormals(quadObj, GLU_SMOOTH);
	if(tex==1)
	{
		gluQuadricTexture(quadObj, GL_TRUE);
	}
	if(tex==0)
	{
		gluQuadricTexture(quadObj, GL_FALSE);
	}
	gluCylinder(quadObj, base,top, height, slices,stacks);
	gluDeleteQuadric(quadObj);
}
void solidSphere(int radius, int stacks, int columns)
{
	GLUquadric* quadObj = gluNewQuadric();
	gluQuadricDrawStyle(quadObj, GLU_FILL);
	gluQuadricNormals(quadObj, GLU_SMOOTH);
	if(tex==1)
	{
		gluQuadricTexture(quadObj, GL_TRUE);
	}
	if(tex==0)
	{
		gluQuadricTexture(quadObj, GL_FALSE);
	}
	gluSphere(quadObj, radius, stacks, columns);
	gluDeleteQuadric(quadObj);
}
void desenha_cilindro()
{
	configura_material(4);
	cilindro.raio=2;
	cilindro.y_minimo=garra.y;
	cilindro.y_maximo=altura_maquina/2-expessura_chapa;
	cilindro.x=garra.x;
	cilindro.y=garra.y;
	cilindro.z=garra.z;
	solidCylinder(cilindro.raio,cilindro.raio,cilindro.y_maximo-cilindro.y_minimo,20,20);

}
void desenha_garra(objeto garra)
{
	tex=0;
	configura_material(4);
	solidSphere(garra.raio,20,20);
	glPushMatrix();
	glTranslatef(garra.raio,-garra.raio/2,0);
	glRotatef(90,0,1,0);
	glRotatef(angulo_cotoco_1,1,0,0);
	solidCylinder(2.5,2.5,10,20,20);
	glTranslatef(0,0,10+3);
	solidSphere(3,20,20);
	glTranslatef(0,-1.5,1.5);
	glPushMatrix();
	glRotatef(90-angulo_cotoco_1,1,0,0);
	solidCylinder(2.5,2.5,8,20,20);
	glPopMatrix();
	glRotatef(-angulo_cotoco_1,1,0,0);
	glTranslatef(0,-8-3,0);
	solidSphere(3,20,20);
	glTranslatef(0,-1.5,0);
	glRotatef(90+angulo_cotoco_2,1,0,0);
	glutSolidCone(2.5,16,20,20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-garra.raio,-garra.raio/2,0);
	glRotatef(270,0,1,0);
	glRotatef(angulo_cotoco_1,1,0,0);
	solidCylinder(2.5,2.5,10,20,20);
	glTranslatef(0,0,13);
	solidSphere(3,20,20);
	glTranslatef(0,-1.5,1.5);
	glPushMatrix();
	glRotatef(90-angulo_cotoco_1,1,0,0);
	solidCylinder(2.5,2.5,8,20,20);
	glPopMatrix();
	glRotatef(-angulo_cotoco_1,1,0,0);
	glTranslatef(0,-8-3,0);
	solidSphere(3,20,20);
	glTranslatef(0,-1.5,0);
	glRotatef(90+angulo_cotoco_2,1,0,0);
	glutSolidCone(2.5,16,20,20);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,-garra.raio/2,-garra.raio);
	glRotatef(180,0,1,0);
	glRotatef(angulo_cotoco_1,1,0,0);
	solidCylinder(2.5,2.5,10,20,20);
	glTranslatef(0,0,13);
	solidSphere(3,20,20);
	glTranslatef(0,-1.5,1.5);
	glPushMatrix();
	glRotatef(90-angulo_cotoco_1,1,0,0);
	solidCylinder(2.5,2.5,8,20,20);
	glPopMatrix();
	glRotatef(-angulo_cotoco_1,1,0,0);
	glTranslatef(0,-8-3,0);
	solidSphere(3,20,20);
	glTranslatef(0,-1.5,0);
	glRotatef(90+angulo_cotoco_2,1,0,0);
	glutSolidCone(2.5,16,20,20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,-garra.raio/2,garra.raio);
	glRotatef(0,0,1,0);
	glRotatef(angulo_cotoco_1,1,0,0);
	solidCylinder(2.5,2.5,10,20,20);
	glTranslatef(0,0,13);
	solidSphere(3,20,20);
	glTranslatef(0,-1.5,1.5);
	glPushMatrix();
	glRotatef(90-angulo_cotoco_1,1,0,0);
	solidCylinder(2.5,2.5,8,20,20);
	glPopMatrix();
	glRotatef(-angulo_cotoco_1,1,0,0);
	glTranslatef(0,-8-3,0);
	solidSphere(3,20,20);
	glTranslatef(0,-1.5,0);
	glRotatef(90+angulo_cotoco_2,1,0,0);
	glutSolidCone(2.5,16,20,20);
	glPopMatrix();

}
void desenha_menu_carregando()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor4f(1,1,1,1);
	glEnable(GL_TEXTURE_2D);
	if(contador_frames%15==0)
	{
		flag_carregando+=1;
		if(flag_carregando==6)
		{
			flag_carregando=1;
		}
	}
	contador++;
	if(contador>300)
	{
		contador=0;
		menu=6;
		menus.stop();
		fundo.play();
		faz3d();
	}
	if(flag_carregando==1)
	{
		glBindTexture(GL_TEXTURE_2D, carregando1);
	}
	else if(flag_carregando==2)
	{
		glBindTexture(GL_TEXTURE_2D, carregando2);
	}
	else if(flag_carregando==3)
	{
		glBindTexture(GL_TEXTURE_2D, carregando3);
	}
	else if(flag_carregando==4)
	{
		glBindTexture(GL_TEXTURE_2D, carregando4);
	}
	else if(flag_carregando==5)
	{
		glBindTexture(GL_TEXTURE_2D, carregando5);
	}

	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-larguraJanela/2,-alturaJanela/2,0);
	glTexCoord2f(1, 0);
	glVertex3f(larguraJanela/2,-alturaJanela/2,0);
	glTexCoord2f(1, 1);
	glVertex3f(larguraJanela/2,alturaJanela/2,0);
	glTexCoord2f(0, 1);
	glVertex3f(-larguraJanela/2,alturaJanela/2,0);
	glEnd();
	glutSwapBuffers();
}
void desenha_menu_principal()
{
	if(controla_menus==0)
	{
		controla_menus=1;
		menus.play();
	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor4f(1,1,1,1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, menu_principal);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-larguraJanela/2,-alturaJanela/2,0);
	glTexCoord2f(1, 0);
	glVertex3f(larguraJanela/2,-alturaJanela/2,0);
	glTexCoord2f(1, 1);
	glVertex3f(larguraJanela/2,alturaJanela/2,0);
	glTexCoord2f(0, 1);
	glVertex3f(-larguraJanela/2,alturaJanela/2,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, botao_nj);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(botao1.x_minimo,botao1.y_minimo,1);
	glTexCoord2f(1, 0);
	glVertex3f(botao1.x_maximo,botao1.y_minimo,1);
	glTexCoord2f(1, 1);
	glVertex3f(botao1.x_maximo,botao1.y_maximo,1);
	glTexCoord2f(0, 1);
	glVertex3f(botao1.x_minimo,botao1.y_maximo,1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, botao_t);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(botao2.x_minimo,botao2.y_minimo,1);
	glTexCoord2f(1, 0);
	glVertex3f(botao2.x_maximo,botao2.y_minimo,1);
	glTexCoord2f(1, 1);
	glVertex3f(botao2.x_maximo,botao2.y_maximo,1);
	glTexCoord2f(0, 1);
	glVertex3f(botao2.x_minimo,botao2.y_maximo,1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, botao_s);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(botao3.x_minimo+400,botao3.y_minimo,1);
	glTexCoord2f(1, 0);
	glVertex3f(botao3.x_maximo+400,botao3.y_minimo,1);
	glTexCoord2f(1, 1);
	glVertex3f(botao3.x_maximo+400,botao3.y_maximo,1);
	glTexCoord2f(0, 1);
	glVertex3f(botao3.x_minimo+400,botao3.y_maximo,1);
	glEnd();
	glutSwapBuffers();
}
void desenha_tutorial1()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor4f(1,1,1,1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tutorial1);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-larguraJanela/2,-alturaJanela/2,0);
	glTexCoord2f(1, 0);
	glVertex3f(larguraJanela/2,-alturaJanela/2,0);
	glTexCoord2f(1, 1);
	glVertex3f(larguraJanela/2,alturaJanela/2,0);
	glTexCoord2f(0, 1);
	glVertex3f(-larguraJanela/2,alturaJanela/2,0);
	glEnd();
	glPushMatrix();
	glTranslatef(-100,-20,0);
	glBindTexture(GL_TEXTURE_2D, botao_v);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(botao3.x_minimo,botao3.y_minimo,1);
	glTexCoord2f(1, 0);
	glVertex3f(botao3.x_maximo,botao3.y_minimo,1);
	glTexCoord2f(1, 1);
	glVertex3f(botao3.x_maximo,botao3.y_maximo,1);
	glTexCoord2f(0, 1);
	glVertex3f(botao3.x_minimo,botao3.y_maximo,1);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(100,-20,0);
	glBindTexture(GL_TEXTURE_2D, botao_p);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(botao6.x_minimo,botao6.y_minimo,1);
	glTexCoord2f(1, 0);
	glVertex3f(botao6.x_maximo,botao6.y_minimo,1);
	glTexCoord2f(1, 1);
	glVertex3f(botao6.x_maximo,botao6.y_maximo,1);
	glTexCoord2f(0, 1);
	glVertex3f(botao6.x_minimo,botao6.y_maximo,1);
	glEnd();
	glPopMatrix();
	glutSwapBuffers();
}
void desenha_tutorial2()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor4f(1,1,1,1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tutorial2);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-larguraJanela/2,-alturaJanela/2,0);
	glTexCoord2f(1, 0);
	glVertex3f(larguraJanela/2,-alturaJanela/2,0);
	glTexCoord2f(1, 1);
	glVertex3f(larguraJanela/2,alturaJanela/2,0);
	glTexCoord2f(0, 1);
	glVertex3f(-larguraJanela/2,alturaJanela/2,0);
	glEnd();
	glPushMatrix();
	glTranslatef(435,0,0);
	glBindTexture(GL_TEXTURE_2D, botao_v);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(botao2.x_minimo,botao2.y_minimo,1);
	glTexCoord2f(1, 0);
	glVertex3f(botao2.x_maximo,botao2.y_minimo,1);
	glTexCoord2f(1, 1);
	glVertex3f(botao2.x_maximo,botao2.y_maximo,1);
	glTexCoord2f(0, 1);
	glVertex3f(botao2.x_minimo,botao2.y_maximo,1);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(95,0,0);
	glBindTexture(GL_TEXTURE_2D, botao_m);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(botao5.x_minimo,botao5.y_minimo,1);
	glTexCoord2f(1, 0);
	glVertex3f(botao5.x_maximo,botao5.y_minimo,1);
	glTexCoord2f(1, 1);
	glVertex3f(botao5.x_maximo,botao5.y_maximo,1);
	glTexCoord2f(0, 1);
	glVertex3f(botao5.x_minimo,botao5.y_maximo,1);
	glEnd();
	glPopMatrix();
	glutSwapBuffers();
}
void desenha_tela_novo_jogo()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor4f(1,1,1,1);
	glEnable(GL_TEXTURE_2D);
	if(tela==0)
		glBindTexture(GL_TEXTURE_2D, novo_jogo);
	if(tela==1)
		glBindTexture(GL_TEXTURE_2D, facil);
	if(tela==2)
		glBindTexture(GL_TEXTURE_2D, medio);
	if(tela==3)
		glBindTexture(GL_TEXTURE_2D, dificil);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-larguraJanela/2,-alturaJanela/2,0);
	glTexCoord2f(1, 0);
	glVertex3f(larguraJanela/2,-alturaJanela/2,0);
	glTexCoord2f(1, 1);
	glVertex3f(larguraJanela/2,alturaJanela/2,0);
	glTexCoord2f(0, 1);
	glVertex3f(-larguraJanela/2,alturaJanela/2,0);
	glEnd();
	glPushMatrix();
	glTranslatef(0,0,0);
	glBindTexture(GL_TEXTURE_2D, botao_v);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(botao3.x_minimo,botao3.y_minimo,1);
	glTexCoord2f(1, 0);
	glVertex3f(botao3.x_maximo,botao3.y_minimo,1);
	glTexCoord2f(1, 1);
	glVertex3f(botao3.x_maximo,botao3.y_maximo,1);
	glTexCoord2f(0, 1);
	glVertex3f(botao3.x_minimo,botao3.y_maximo,1);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,0,0);
	glBindTexture(GL_TEXTURE_2D, botao_f);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(botao4.x_minimo,botao4.y_minimo,1);
	glTexCoord2f(1, 0);
	glVertex3f(botao4.x_maximo,botao4.y_minimo,1);
	glTexCoord2f(1, 1);
	glVertex3f(botao4.x_maximo,botao4.y_maximo,1);
	glTexCoord2f(0, 1);
	glVertex3f(botao4.x_minimo,botao4.y_maximo,1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, botao_n);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(botao5.x_minimo,botao5.y_minimo,1);
	glTexCoord2f(1, 0);
	glVertex3f(botao5.x_maximo,botao5.y_minimo,1);
	glTexCoord2f(1, 1);
	glVertex3f(botao5.x_maximo,botao5.y_maximo,1);
	glTexCoord2f(0, 1);
	glVertex3f(botao5.x_minimo,botao5.y_maximo,1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, botao_d);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(botao6.x_minimo,botao6.y_minimo,1);
	glTexCoord2f(1, 0);
	glVertex3f(botao6.x_maximo,botao6.y_minimo,1);
	glTexCoord2f(1, 1);
	glVertex3f(botao6.x_maximo,botao6.y_maximo,1);
	glTexCoord2f(0, 1);
	glVertex3f(botao6.x_minimo,botao6.y_maximo,1);
	glEnd();

	glPopMatrix();
	glutSwapBuffers();
}
void desenha_menu_continuar()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor4f(1,1,1,1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, continuar);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-larguraJanela/2,-alturaJanela/2,0);
	glTexCoord2f(1, 0);
	glVertex3f(larguraJanela/2,-alturaJanela/2,0);
	glTexCoord2f(1, 1);
	glVertex3f(larguraJanela/2,alturaJanela/2,0);
	glTexCoord2f(0, 1);
	glVertex3f(-larguraJanela/2,alturaJanela/2,0);
	glEnd();
	glPushMatrix();
	glTranslatef(-100,-20,0);
	glBindTexture(GL_TEXTURE_2D, botao_c);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(botao3.x_minimo,botao3.y_minimo,1);
	glTexCoord2f(1, 0);
	glVertex3f(botao3.x_maximo,botao3.y_minimo,1);
	glTexCoord2f(1, 1);
	glVertex3f(botao3.x_maximo,botao3.y_maximo,1);
	glTexCoord2f(0, 1);
	glVertex3f(botao3.x_minimo,botao3.y_maximo,1);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(100,-20,0);
	glBindTexture(GL_TEXTURE_2D, botao_s);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(botao6.x_minimo,botao6.y_minimo,1);
	glTexCoord2f(1, 0);
	glVertex3f(botao6.x_maximo,botao6.y_minimo,1);
	glTexCoord2f(1, 1);
	glVertex3f(botao6.x_maximo,botao6.y_maximo,1);
	glTexCoord2f(0, 1);
	glVertex3f(botao6.x_minimo,botao6.y_maximo,1);
	glEnd();
	glPopMatrix();
	glutSwapBuffers();
}
void desenha_menu_sair()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor4f(1,1,1,1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, continuar);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-larguraJanela/2,-alturaJanela/2,0);
	glTexCoord2f(1, 0);
	glVertex3f(larguraJanela/2,-alturaJanela/2,0);
	glTexCoord2f(1, 1);
	glVertex3f(larguraJanela/2,alturaJanela/2,0);
	glTexCoord2f(0, 1);
	glVertex3f(-larguraJanela/2,alturaJanela/2,0);
	glEnd();
	glPushMatrix();
	glTranslatef(300,500,0);
	glBindTexture(GL_TEXTURE_2D, botao_c);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(botao3.x_minimo,botao3.y_minimo,1);
	glTexCoord2f(1, 0);
	glVertex3f(botao3.x_maximo,botao3.y_minimo,1);
	glTexCoord2f(1, 1);
	glVertex3f(botao3.x_maximo,botao3.y_maximo,1);
	glTexCoord2f(0, 1);
	glVertex3f(botao3.x_minimo,botao3.y_maximo,1);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-300,-20,0);
	glBindTexture(GL_TEXTURE_2D, botao_s);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(botao6.x_minimo,botao6.y_minimo,1);
	glTexCoord2f(1, 0);
	glVertex3f(botao6.x_maximo,botao6.y_minimo,1);
	glTexCoord2f(1, 1);
	glVertex3f(botao6.x_maximo,botao6.y_maximo,1);
	glTexCoord2f(0, 1);
	glVertex3f(botao6.x_minimo,botao6.y_maximo,1);
	glEnd();
	glPopMatrix();
	glutSwapBuffers();
}
void desenha_menu_premio()
{
	if(controla_fogos==0)
	{
		controla_fogos=1;
		fogos.play();
	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor4f(1,1,1,1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, premio);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-larguraJanela/2,-alturaJanela/2,0);
	glTexCoord2f(1, 0);
	glVertex3f(larguraJanela/2,-alturaJanela/2,0);
	glTexCoord2f(1, 1);
	glVertex3f(larguraJanela/2,alturaJanela/2,0);
	glTexCoord2f(0, 1);
	glVertex3f(-larguraJanela/2,alturaJanela/2,0);
	glEnd();
	glPushMatrix();
	glTranslatef(-100,-20,0);
	glBindTexture(GL_TEXTURE_2D, botao_c);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(botao3.x_minimo,botao3.y_minimo,1);
	glTexCoord2f(1, 0);
	glVertex3f(botao3.x_maximo,botao3.y_minimo,1);
	glTexCoord2f(1, 1);
	glVertex3f(botao3.x_maximo,botao3.y_maximo,1);
	glTexCoord2f(0, 1);
	glVertex3f(botao3.x_minimo,botao3.y_maximo,1);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(100,-20,0);
	glBindTexture(GL_TEXTURE_2D, botao_s);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(botao6.x_minimo,botao6.y_minimo,1);
	glTexCoord2f(1, 0);
	glVertex3f(botao6.x_maximo,botao6.y_minimo,1);
	glTexCoord2f(1, 1);
	glVertex3f(botao6.x_maximo,botao6.y_maximo,1);
	glTexCoord2f(0, 1);
	glVertex3f(botao6.x_minimo,botao6.y_maximo,1);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,0,0);
	switch(escolhe)
	{
	case 1:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon1);
		break;
	case 2:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon2);
		break;
	case 3:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon3);
		break;
	case 4:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon4);
		break;
	case 5:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon5);
		break;
	case 6:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon6);
		break;
	case 7:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon7);
		break;
	case 8:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon8);
		break;
	case 9:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon9);
		break;
	case 10:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon10);
		break;
	case 11:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon11);
		break;
	case 12:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon12);
		break;
	case 13:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon13);
		break;
	case 14:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon14);
		break;
	case 15:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon15);
		break;
	case 16:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon16);
		break;
	case 17:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon17);
		break;
	case 18:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon18);
		break;
	case 19:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon19);
		break;
	case 20:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon20);
		break;
	case 21:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon21);
		break;
	case 22:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon22);
		break;
	case 23:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon23);
		break;
	case 24:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon24);
		break;
	case 25:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon25);
		break;
	case 26:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon26);
		break;
	case 27:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon27);
		break;
	case 28:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon28);
		break;
	case 29:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon29);
		break;
	case 30:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon30);
		break;
	case 31:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon31);
		break;
	case 32:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon32);
		break;
	case 33:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon33);
		break;
	case 34:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon34);
		break;
	case 35:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon35);
		break;
	case 36:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon36);
		break;
	case 37:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon37);
		break;
	case 38:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon38);
		break;
	case 39:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon39);
		break;
	case 40:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon40);
		break;
	case 41:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon41);
		break;
	case 42:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon42);
		break;
	case 43:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon43);
		break;
	case 44:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon44);
		break;
	case 45:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon45);
		break;
	case 46:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon46);
		break;
	case 47:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon47);
		break;
	case 48:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon48);
		break;
	case 49:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon49);
		break;
	case 50:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon50);
		break;
	case 51:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon51);
		break;
	case 52:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon52);
		break;
	case 53:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon53);
		break;
	case 54:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon54);
		break;
	case 55:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon55);
		break;
	case 56:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon56);
		break;
	case 57:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon57);
		break;
	case 58:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon58);
		break;
	case 59:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon59);
		break;
	case 60:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon60);
		break;
	case 61:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon61);
		break;
	case 62:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon62);
		break;
	case 63:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon63);
		break;
	case 64:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon64);
		break;
	case 65:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon65);
		break;
	case 66:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon66);
		break;
	case 67:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon67);
		break;
	case 68:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon68);
		break;
	case 69:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon69);
		break;
	case 70:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon70);
		break;
	case 71:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon71);
		break;
	case 72:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon72);
		break;
	case 73:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon73);
		break;
	case 74:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon74);
		break;
	case 75:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon75);
		break;
	case 76:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon76);
		break;
	case 77:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon77);
		break;
	case 78:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon78);
		break;
	case 79:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon79);
		break;
	case 80:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon80);
		break;
	case 81:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon81);
		break;
	case 82:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon82);
		break;
	case 83:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon83);
		break;
	case 84:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon84);
		break;
	case 85:
		glBindTexture(GL_TEXTURE_2D,texturaPokemon85);
		break;
	}
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(pokemon.x_minimo,pokemon.y_minimo,1);
	glTexCoord2f(1, 0);
	glVertex3f(pokemon.x_maximo,pokemon.y_minimo,1);
	glTexCoord2f(1, 1);
	glVertex3f(pokemon.x_maximo,pokemon.y_maximo,1);
	glTexCoord2f(0, 1);
	glVertex3f(pokemon.x_minimo,pokemon.y_maximo,1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,textura_fogos);
	if(contador_frames%5==0)
	{
		if(foto<90)
		{
			foto++;
		}
		else
		{
			foto=1;
		}
		if(foto2<90)
		{
			foto2++;
		}
		else
		{
			foto2=1;
		}
	}
	float *xy;
	float *xy2;
	float *xy3;
	float *xy4;
	xy=coordena_sprite(18,5,1,foto);
	xy2=coordena_sprite(18,5,2,foto);
	xy3=coordena_sprite(18,5,3,foto);
	xy4=coordena_sprite(18,5,4,foto);
	glPushMatrix();
	glTranslatef(-300,0,0);
	glBegin(GL_QUADS);
	glTexCoord2f(xy[0], xy[1]);
	glVertex3f(pokemon.x_minimo-100,botao3.y_minimo,1);
	glTexCoord2f(xy2[0], xy2[1]);
	glVertex3f(pokemon.x_minimo+400,botao3.y_minimo,1);
	glTexCoord2f(xy3[0], xy3[1]);
	glVertex3f(pokemon.x_minimo+400,botao3.y_minimo+500,1);
	glTexCoord2f(xy4[0], xy4[1]);
	glVertex3f(pokemon.x_minimo-100,botao3.y_minimo+500,1);
	glEnd();
	glPopMatrix();
	xy=coordena_sprite(18,5,1,foto2);
	xy2=coordena_sprite(18,5,2,foto2);
	xy3=coordena_sprite(18,5,3,foto2);
	xy4=coordena_sprite(18,5,4,foto2);
	glTranslatef(+450,0,0);
	glBegin(GL_QUADS);
	glTexCoord2f(xy[0], xy[1]);
	glVertex3f(pokemon.x_minimo-100,botao3.y_minimo,1);
	glTexCoord2f(xy2[0], xy2[1]);
	glVertex3f(pokemon.x_minimo+400,botao3.y_minimo,1);
	glTexCoord2f(xy3[0], xy3[1]);
	glVertex3f(pokemon.x_minimo+400,botao3.y_minimo+500,1);
	glTexCoord2f(xy4[0], xy4[1]);
	glVertex3f(pokemon.x_minimo-100,botao3.y_minimo+500,1);
	glEnd();
	glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();
}
void desenha()
{
	switch(menu)
	{
	case 0:
		desenha_menu_principal();
		break;
	case 1:
		desenha_tutorial1();
		break;
	case 2:
		desenha_tutorial2();
		break;
	case 3:
		desenha_menu_carregando();
		break;
	case 4:
		desenha_menu_continuar();
		break;
	case 5:
		if(contador2==0)
		{
			fi=0;
			teta=0;
			cam.x=sin(teta*PI/180)*raio_camera;
			cam.y=sin(fi*PI/180)*raio_camera;
			cam.z=cos(fi*PI/180)*raio_camera;
			cam.w=1;
			posiciona_camera();
			faz2d();
			contador2++;
		}
		desenha_menu_premio();
		break;
	case 6:
		desenha_jogo();
		break;
	case 7:
		desenha_tela_novo_jogo();
		break;
	case 8:
		desenha_menu_sair();
		break;
	}
}
void desenha_jogo()
{
	glEnable(GL_LIGHTING);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	skybox();
	int i;
	for(i=0; i<36; i++)
	{
		if(i!=3 && i!=9 && i!=4 && i!=10)
		{
			faz_pokeball(pokeball[i]);
		}
	}
	desenha_maquina();
	aplica_texturas();
	glPushMatrix();
	glTranslatef(garra.x,garra.y,garra.z);
	desenha_garra(garra);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(cilindro.x,cilindro.y,cilindro.z);
	glRotatef(-90,1,0,0);
	desenha_cilindro();
	glPopMatrix();
	glutSwapBuffers();
	glDisable(GL_LIGHTING);
}

void teclado(unsigned char key, int x, int y)
{
	switch (key)
	{
	case ' ':
		if(garra.status==0 && garra_fechada==1 && verifica_bug(0) && verifica_bug(5) && verifica_bug(30) && verifica_bug(35) )
		{
			desce_garra=1;
			sobe_garra=0;
		}
		break;
	}
}

void teclado2(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		if(menu!=4 && menu!=8)
		{
			if(menu==0)
			{
				menus.stop();
			}
			menu_anterior=menu;
			menu=8;
			faz2d();
		}
		fundo.pause();
		break;
	case 'p':
		if(menu==6)
		{
			menu=4;
			faz2d();
		}
		fundo.pause();
		break;
	case 'P':
		if(menu==6)
		{
			menu=4;
			fundo.pause();
			faz2d();
		}
		break;
	}
}
void specialKeyInput(int key, int x, int y)
{
	if(teta<0)
	{
		teta2=teta;
		teta2-=(floor(teta2/360)*360);
		teta2=360+teta2;
	}
	else
	{
		teta2=teta;
		teta2-=(floor(teta2/360)*360);

	}
	if(315<=teta2 || teta2<45)
	{
		if(key == GLUT_KEY_DOWN)
		{
			garra_frente=1;
			if(controla_movimento1==0 && garra.status==0 )
			{
				controla_movimento1=2;
				frente.play();
			}
		}
		if(key == GLUT_KEY_UP)
		{
			garra_atras=1;
			if(controla_movimento2==0 && garra.status==0)
			{
				controla_movimento2=2;
				atras.play();
			}
		}
		if(key == GLUT_KEY_RIGHT)
		{
			garra_direita=1;
			if(controla_movimento3==0 && garra.status==0)
			{
				controla_movimento3=2;
				direita.play();
			}
		}
		if(key == GLUT_KEY_LEFT)
		{
			garra_esquerda=1;
			if(controla_movimento4==0 && garra.status==0)
			{
				controla_movimento4=2;
				esquerda.play();
			}
		}
	}
	if(45<=teta2 && teta2<135)
	{
		if(key == GLUT_KEY_DOWN)
		{
			garra_direita=1;
			if(controla_movimento3==0 && garra.status==0)
			{
				controla_movimento3=2;
				direita.play();
			}
		}
		if(key == GLUT_KEY_UP)
		{
			garra_esquerda=1;
			if(controla_movimento4==0 && garra.status==0)
			{
				controla_movimento4=2;
				esquerda.play();
			}
		}
		if(key == GLUT_KEY_RIGHT)
		{
			garra_atras=1;
			if(controla_movimento2==0 && garra.status==0)
			{
				controla_movimento2=2;
				atras.play();
			}


		}
		if(key == GLUT_KEY_LEFT)
		{
			garra_frente=1;
			if(controla_movimento1==0 && garra.status==0 )
			{
				controla_movimento1=2;
				frente.play();
			}
		}
	}
	if(135<=teta2 && teta2<225)
	{
		if(key == GLUT_KEY_DOWN)
		{

			garra_atras=1;
			if(controla_movimento2==0 && garra.status==0)
			{
				controla_movimento2=2;
				atras.play();
			}
		}
		if(key == GLUT_KEY_UP)
		{

			garra_frente=1;
			if(controla_movimento1==0 && garra.status==0 )
			{
				controla_movimento1=2;
				frente.play();
			}
		}
		if(key == GLUT_KEY_RIGHT)
		{
			garra_esquerda=1;
			if(controla_movimento4==0 && garra.status==0)
			{
				controla_movimento4=2;
				esquerda.play();
			}
		}
		if(key == GLUT_KEY_LEFT)
		{

			garra_direita=1;
			if(controla_movimento3==0 && garra.status==0)
			{
				controla_movimento3=2;
				direita.play();
			}
		}
	}
	if(225<=teta2 && teta2<315)
	{
		if(key == GLUT_KEY_DOWN)
		{
			garra_esquerda=1;
			if(controla_movimento4==0 && garra.status==0)
			{
				controla_movimento4=2;
				esquerda.play();
			}
		}
		if(key == GLUT_KEY_UP)
		{
			garra_direita=1;
			if(controla_movimento3==0 && garra.status==0)
			{
				controla_movimento3=2;
				direita.play();
			}
		}
		if(key == GLUT_KEY_RIGHT)
		{


			garra_frente=1;
			if(controla_movimento1==0 && garra.status==0 )
			{
				controla_movimento1=2;
				frente.play();
			}
		}
		if(key == GLUT_KEY_LEFT)
		{
			garra_atras=1;
			if(controla_movimento2==0 && garra.status==0)
			{
				controla_movimento2=2;
				atras.play();
			}
		}
	}

	glutPostRedisplay();
}
void specialKeyInput2(int key, int x, int y)
{
	if(teta<0)
	{
		teta2=teta;
		teta2-=(floor(teta2/360)*360);
		teta2=360+teta2;
	}
	else
	{
		teta2=teta;
		teta2-=(floor(teta2/360)*360);
	}
	if(315<=teta2 || teta2<45)
	{
		if(key == GLUT_KEY_DOWN)
		{
			garra_frente=0;
			if(controla_movimento1==1 || controla_movimento1==2)
			{
				controla_movimento1=0;
				frente.stop();
			}
		}
		if(key == GLUT_KEY_UP)
		{
			garra_atras=0;
			if(controla_movimento2==1 || controla_movimento2==2)
			{
				controla_movimento2=0;
				atras.stop();
			}
		}
		if(key == GLUT_KEY_RIGHT)
		{
			garra_direita=0;
			if(controla_movimento3==1 || controla_movimento3==2)
			{
				controla_movimento3=0;
				direita.stop();
			}
		}
		if(key == GLUT_KEY_LEFT)
		{
			garra_esquerda=0;
			if(controla_movimento4==1 || controla_movimento4==2)
			{
				controla_movimento4=0;
				esquerda.stop();
			}
		}
	}
	if(45<=teta2 && teta2<135)
	{
		if(key == GLUT_KEY_DOWN)
		{
			garra_direita=0;
			if(controla_movimento3==1 || controla_movimento3==2)
			{
				controla_movimento3=0;
				direita.stop();
			}
		}
		if(key == GLUT_KEY_UP)
		{
			garra_esquerda=0;
			if(controla_movimento4==1 || controla_movimento4==2)
			{
				controla_movimento4=0;
				esquerda.stop();
			}
		}
		if(key == GLUT_KEY_RIGHT)
		{

			garra_atras=0;
			if(controla_movimento2==1 || controla_movimento2==2)
			{
				controla_movimento2=0;
				atras.stop();
			}

		}
		if(key == GLUT_KEY_LEFT)
		{
			garra_frente=0;
			if(controla_movimento1==1 || controla_movimento1==2)
			{
				controla_movimento1=0;
				frente.stop();
			}
		}
	}
	if(135<=teta2 && teta2<225)
	{
		if(key == GLUT_KEY_DOWN)
		{

			garra_atras=0;
			if(controla_movimento2==1 || controla_movimento2==2)
			{
				controla_movimento2=0;
				atras.stop();
			}
		}
		if(key == GLUT_KEY_UP)
		{
			garra_frente=0;
			if(controla_movimento1==1 || controla_movimento1==2)
			{
				controla_movimento1=0;
				frente.stop();
			}

		}
		if(key == GLUT_KEY_RIGHT)
		{
			garra_esquerda=0;
			if(controla_movimento4==1 || controla_movimento4==2)
			{
				controla_movimento4=0;
				esquerda.stop();
			}

		}
		if(key == GLUT_KEY_LEFT)
		{
			garra_direita=0;
			if(controla_movimento3==1 || controla_movimento3==2)
			{
				controla_movimento3=0;
				direita.stop();
			}
		}
	}
	if(225<=teta2 && teta2<315)
	{
		if(key == GLUT_KEY_DOWN)
		{
			garra_esquerda=0;
			if(controla_movimento4==1 || controla_movimento4==2)
			{
				controla_movimento4=0;
				esquerda.stop();
			}
		}
		if(key == GLUT_KEY_UP)
		{
			garra_direita=0;
			if(controla_movimento3==1 || controla_movimento3==2)
			{
				controla_movimento3=0;
				direita.stop();
			}
		}
		if(key == GLUT_KEY_RIGHT)
		{
			garra_frente=0;
			if(controla_movimento1==1 || controla_movimento1==2)
			{
				controla_movimento1=0;
				frente.stop();
			}

		}
		if(key == GLUT_KEY_LEFT)
		{

			garra_atras=0;
			if(controla_movimento2==1 || controla_movimento2==2)
			{
				controla_movimento2=0;
				atras.stop();
			}
		}
	}
	glutPostRedisplay();
}
void faz2d()
{
	glViewport (0, 0, (GLsizei)largura_tela, (GLsizei)altura_tela);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-largura_tela/2,largura_tela/2,-altura_tela/2,altura_tela/2, -1.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void faz3d()
{
	glViewport (0, 0, (GLsizei)largura_tela, (GLsizei)altura_tela);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (float)largura_tela/(float)altura_tela, 1, 1200);
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char *argv[])
{
	srand(time(0));
	intervalo_frames=(float)1000/fps;
	glutInit(&argc, argv);
	glutInitWindowSize(larguraJanela,alturaJanela);
	glutInitWindowPosition(10,10);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	inicializa();
	inicializa_audio();
	glutCreateWindow("TP2");
	inicializa_textura();
	inicializa_pokeball();
	glutReshapeFunc(redimensiona);
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(desenha);
	glutKeyboardFunc(teclado);
	glutKeyboardUpFunc(teclado2);
	glutSpecialFunc(specialKeyInput);
	glutSetCursor(GLUT_CURSOR_FULL_CROSSHAIR);
	glutSpecialUpFunc(specialKeyInput2);
	glutPassiveMotionFunc(mouse_motion);
	glutMouseFunc(click_mouse);
	glutIdleFunc(atoa);
	glClearColor(1,1,1,1);
	glutTimerFunc(intervalo_frames,atualiza,0);
	glutMainLoop();
	return EXIT_SUCCESS;
}
