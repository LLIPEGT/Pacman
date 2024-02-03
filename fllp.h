#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define COR_PRETO printf("\33[30m");
#define COR_VERMELHO printf("\33[31m");
#define COR_VERDE printf("\33[32m");
#define COR_LARANJA printf("\33[33m");
#define COR_AZUL printf("\33[34m");
#define COR_ROXO printf("\33[35m");
#define COR_AGUA printf("\33[36m");
#define COR_BRANCO printf("\33[37m");
#define EMOJI_PAC printf("🙂");
#define EMOJI_PAC2 printf("😝");
#define EMOJI_MON printf("👻");
#define EMOJI_PAL printf("🤡");
#define EMOJI_VIDA printf("💎");
#define EMOJI_PAR printf("⬛");
#define CONSTRU_MAPA printf("__");
#define EMOJI_CAM printf("  ");

// https://www.assuntoscriativos.com.br/2013/08/simbolos-da-tecla-alt-que-voce-ainda.html
#define larg 48
#define alt 32
#define CAMINHO 0
#define PAREDE 1
#define PACMAN 2
#define FANTASMA 3
#define TEMPF 4
#define PALHACO 5
#define TEMPP 6
#define VIDA 7
#define PACMAN2 8

int mat[alt][larg] = {
    {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    },
    {
        1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 1,
    },
    {
        1, 0, 1, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1,
    },
    {
        1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0,
        0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1,
    },
    {
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 7, 0, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 7, 1, 0, 0, 0, 0, 0, 0, 0, 1,
    },
    {
        1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1,
    },
    {
        1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0,
        1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 3, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1,
    },
    {
        1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0,
        1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
    },
    {
        1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0,
        1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1,
    },
    {
        1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1,
    },
    {
        1, 1, 0, 0, 7, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1,
        1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1,
    },
    {
        1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1,
        1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1,
    },
    {
        1, 1, 0, 0, 1, 0, 0, 3, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1,
    },
    {
        1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    },
    {
        1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1,
    },
    {
        1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1,
    },
    {
        1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,
    },
    {
        1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0,
        0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,
    },
    {
        1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 5, 1, 1, 1, 0, 1, 0,
        1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1,
    },
    {
        1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0,
        1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 5, 1, 1, 1, 1, 0, 1, 1,
    },
    {
        1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0,
        1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1,
    },
    {
        1, 1, 5, 0, 0, 0, 0, 0, 0, 7, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0,
        0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1,
    },
    {
        1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,
        1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1,
    },
    {
        1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 3, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,
        1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 7, 1, 0, 1, 1,
    },
    {
        1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
        1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1,
    },
    {
        1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1,
    },
    {
        1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
        7, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 7, 1, 0, 0, 0, 0, 0, 0, 1, 1,
    },
    {
        1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1,
        1, 1, 1, 1, 7, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1,
    },
    {
        1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0,
        0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1,
    },
    {
        1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1,
        1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1,
    },
    {
         0, 1, 1, 1, 1, 1, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 0, 0, 1, 1,
    },
    {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    },
};

int px = 1, py = 1, vidas = 0;
int ok, pacx = 1, pacy = 1, frame = 0, tentativas_pac = 3;
int flag, cont = 0;
int fantx, fanty;
int palhax, palhay;

void iniciarmap(int mapa[alt][larg]);
void desenharmap(int mapa[alt][larg]);
int atualizarmap(int mapa[alt][larg], char jogada);
int efetuarjogada(int mapa[alt][larg], char jogada);
int vidas_cap(int mapa[alt][larg]);
int morte_pac(int mapa[alt][larg]);
void movfantasma(int mapa[alt][larg]);
void movpalhaco(int mapa[alt][larg]);
int fim();

// edicao do mapa
void iniciarmap(int mapa[alt][larg]) {

  int lin, col;
  puts("\t\t\t\t\t|----------------|");
  puts("\t\t\t\t|------------------------|");
  puts("\t\t\t|--------------------------------|");
  puts("\t\t|----------------------------------------|");
  COR_LARANJA
  printf("\t\t\t\t\tESCOLHA ENTRE");
  printf("\n\t\t\t\t\tAS DUAS OPÇÕES");
  COR_BRANCO
  puts("\n\t\t|----------------------------------------|");
  printf("\t\t\t\tMAPA PRONTO  (");
  COR_AGUA
  printf("0");
  COR_BRANCO
  printf(")");
  printf("\n\t\t\t\tCRIAR MAPA   ");
  printf("(");
  COR_AGUA
  printf("1");
  COR_BRANCO
  printf(")");
  printf("\n\t\t\t\t===>\t\t  ");
  COR_AZUL
  scanf("%i", &flag);
  COR_BRANCO
  puts("\t\t|----------------------------------------|");
  puts("\t\t\t|--------------------------------|");
  puts("\t\t\t\t|------------------------|");
  puts("\t\t\t\t\t|----------------|");
  sleep(5);
  for (lin = 0; lin < alt; lin++) {
    for (col = 0; col < larg; col++) {
      fflush(stdin);
      if (flag == 1) {
        mapa[lin][col] = PAREDE;
      } else if (flag == 0) {
        mapa[lin][col] = mat[lin][col];
      }
    }
  }
}

void desenharmap(int mapa[alt][larg]) {

  int lin, col, cont = 0;

  for (lin = 0; lin < alt; lin++) {
    for (col = 0; col < larg; col++) {
      fflush(stdin);
      if (lin == px && col == py) {
        if(flag == 1){
          CONSTRU_MAPA
        }
        else{
          EMOJI_CAM
        }
      } else if (mapa[lin][col] == CAMINHO) {
        EMOJI_CAM  
      } else if (mapa[lin][col] == PAREDE) {
        EMOJI_PAR
      } else if (mapa[lin][col] == PACMAN) {
        if (frame == 0) {
          EMOJI_PAC
          frame = 1;
        }
        else {
          EMOJI_PAC2
          frame = 0;
        }
      } else if (mapa[lin][col] == FANTASMA) {
        EMOJI_MON
      } else if (mapa[lin][col] == PALHACO) {
        EMOJI_PAL
      } else if (mapa[lin][col] == VIDA) {
        EMOJI_VIDA
      }
    }
    printf("\n");
  }
  if (flag == 1) {
    printf("(C): caminho🛣️ \t(P): Parede🧱\t(V): vidaa💛\t(F): fantasma\t👻\t(O): ok  (i)pacman");
  }
  
  else {
    printf("\ntentativas: ");
    COR_AZUL
    printf("%i", tentativas_pac);
    COR_BRANCO
    printf("\t//\t");
    COR_BRANCO
    printf("Vidas capturadas: ");
    COR_AGUA
    printf("%i", vidas);
    COR_BRANCO
    printf("\t\t\t\t\t\t\t\t\tpos X = ");
    COR_VERMELHO
    printf("%i ", pacx);
    COR_BRANCO
    printf("// POS Y = ");
    COR_VERMELHO
    printf("%i", pacy);
    COR_BRANCO
  }
}

int atualizarmap(int mapa[alt][larg], char jogada)
{
  // cima
  if (jogada == '^') {
    if (px > 1) {
      px--;
    }
  }
  // baixo
  else if (jogada == '|') {
    if (px < alt - 2) {
      px++;
    }
  }
  // direita
  else if (jogada == '>') {
    if (py < larg - 2) {
      py++;
    }
  }
  // esquerda
  else if (jogada == '<') {
    if (py > 1) {
      py--;
    }
  }
  if (flag == 1) {
    // caminho
    if (jogada == 'c' || jogada == 'C') {
      mapa[px][py] = CAMINHO;
    }
    // vida
    else if (jogada == 'v' || jogada == 'V') {
      mapa[px][py] = VIDA;
    }
    // parede
    else if (jogada == 'p' || jogada == 'P') {
      mapa[px][py] = PAREDE;
    }
    // monstro
    else if (jogada == 'f' || jogada == 'F') {
      mapa[px][py] = FANTASMA;
    } else if (jogada == 'P' || jogada == 'p') {
      mapa[px][py] = PALHACO;
    }
    // ok
    else if (jogada == 'o' || jogada == 'O') {
      flag++;
      return 1;
    }
    else if (jogada == 'i' || jogada == 'I') {
      cont++;
        if(cont == 1){
          mapa[px][py] = PACMAN;
          pacx = px;
          pacy = py;
        }
      else{
        
      }
    }
  } 
  else {
    mapa[px][py] = PACMAN;
    pacx = px;
    pacy = py;
    return 1;
  }
  return 0;
}

int efetuarjogada(int mapa[alt][larg], char jogada) {

  // cima
  if (jogada == '^') {
    if (pacx > 1 && mapa[pacx - 1][pacy] != PAREDE) {
      mapa[pacx][pacy] = CAMINHO;
      pacx--;
      vidas_cap(mapa);
      morte_pac(mapa);
      mapa[pacx][pacy] = PACMAN;
    }
  }
  // baixo
  else if (jogada == '|') {
    if (pacx < alt - 2 && mapa[pacx + 1][pacy] != PAREDE) {
      mapa[pacx][pacy] = CAMINHO;
      pacx++;
      vidas_cap(mapa);
      morte_pac(mapa);
      mapa[pacx][pacy] = PACMAN;
    }
  }
  // direita
  else if (jogada == '>') {
    if (pacy < larg - 2 && mapa[pacx][pacy + 1] != PAREDE) {
      mapa[pacx][pacy] = CAMINHO;
      pacy++;
      vidas_cap(mapa);
      morte_pac(mapa);
      mapa[pacx][pacy] = PACMAN;
    }
  }
  // esquerda
  else if (jogada == '<') {
    if (pacy > 1 && mapa[pacx][pacy - 1] != PAREDE)    {
      mapa[pacx][pacy] = CAMINHO;
      pacy--;
      morte_pac(mapa);
      vidas_cap(mapa);
      mapa[pacx][pacy] = PACMAN;
    }
  }
  return 0;
}

int vidas_cap(int mapa[alt][larg]) {
  
  if(mapa[pacx][pacy]==VIDA){
     return vidas++;
  }
  else{
    return 0;
  }
}

int morte_pac(int mapa[alt][larg]){
  if(tentativas_pac==0 && vidas !=10){
      return 2;
  }
  else if(tentativas_pac!=0 && vidas == 10){
        return 3;
  }
  else{
    if(mapa[pacx][pacy] == FANTASMA){
      tentativas_pac --;
      mapa[pacx][pacy] = FANTASMA;
      pacx = 2;
      pacy = 1;
    }
    else if(mapa[pacx][pacy] == PALHACO ){
      tentativas_pac --;
      mapa[pacx][pacy] = PALHACO;
      pacx = 2;
      pacy = 1;
    }
    return 0;
  }
}
void movfantasma(int mapa[alt][larg]){

  char jogada;
  srand ( time ( NULL ));
  
  for(fantx=0;fantx<alt;fantx++){
    for(fanty=0;fanty<larg;fanty++){
      if(mapa[fantx][fanty]==FANTASMA){
        mapa[fantx][fanty] = FANTASMA;
        jogada = 65 + (rand()%4);
        if(jogada == 'A'){
          if (fantx > 1 && mapa[fantx - 1][fanty] != PAREDE && mapa[fantx - 1][fanty] != VIDA) 
          {
            morte_pac(mapa);
            mapa[fantx][fanty] = CAMINHO;
            fantx--;
            mapa[fantx][fanty] = FANTASMA;
          }
          else{
            fanty--;
          }
        }
        else if(jogada == 'B'){
          if (fantx < alt - 2 && mapa[fantx + 1][fanty] != PAREDE && mapa[fantx + 1][fanty] != VIDA) {
            morte_pac(mapa);
            mapa[fantx][fanty] = CAMINHO;
            fantx++;
            mapa[fantx][fanty] = FANTASMA;
          }
          else{
            fanty--;
          }
        }
        else if (jogada == 'C') {
          if (fanty < larg - 2 && mapa[fantx][fanty + 1] != PAREDE && mapa[fantx][fanty + 1] != VIDA) {
            morte_pac(mapa);
            mapa[fantx][fanty] = CAMINHO;
            fanty++;
            mapa[fantx][fanty] = FANTASMA;
          }
          else{
            fanty --;
          }
        }
        else if (jogada == 'D') {
          if (fanty > 1 && mapa[fantx][fanty - 1] != PAREDE && mapa[fantx][fanty - 1] != VIDA)    {
            morte_pac(mapa);
            mapa[fantx][fanty] = CAMINHO;
            fanty--;
            mapa[fantx][fanty] = FANTASMA;
          }
          else{
            fanty--;
          }
        }
      }
    }
  }
}

void movpalhaco(int mapa[alt][larg]){

  int detec_parede;
  char jogada;
  srand ( time ( NULL ));
  
  for(palhax=0;palhax<alt;palhax++){
    for(palhay=0;palhay<larg;palhay++){
      if(mapa[palhax][palhay]==PALHACO){
        mapa[palhax][palhay] = PALHACO;
        jogada = 65 + (rand()%4);
        if(jogada == 'A'){
          if (palhax > 1 && mapa[palhax - 1][palhay] != PAREDE && mapa[palhax - 1][palhay] != VIDA) 
          {
            morte_pac(mapa);
            mapa[palhax][palhay] = CAMINHO;
            palhax--;
            mapa[palhax][palhay] = PALHACO;
          }
          else{
            palhay --;
          }
        }
        else if(jogada == 'B'){
          if (palhax < alt - 2 && mapa[palhax + 1][palhay] != PAREDE && mapa[palhax + 1][palhay] != VIDA) {
            morte_pac(mapa);
            mapa[palhax][palhay] = CAMINHO;
            palhax++;
            mapa[palhax][palhay] = PALHACO;
          }
          else{
            palhay--;
          }
        }
        else if (jogada == 'C') {
          if (palhay < larg - 2 && mapa[palhax][palhay + 1] != PAREDE && mapa[palhax][palhay + 1] != VIDA) {
            morte_pac(mapa);
            mapa[palhax][palhay] = CAMINHO;
            palhay++;
            mapa[palhax][palhay] = PALHACO;
          }
          else{
            palhay --;
          }
        }
        else if (jogada == 'D') {
          if (palhay > 1 && mapa[palhax][palhay - 1] != PAREDE && mapa[palhax][palhay - 1] != VIDA)    {
            morte_pac(mapa);
            mapa[palhax][palhay] = CAMINHO;
            palhay--;
            mapa[palhax][palhay] = PALHACO;
          }
          else{
            palhay--;
          }
          if(mapa[palhax][palhay]==VIDA){
          }
        }
      }
    }
  }
}

int paredes_detec(int mapa[alt][larg]){
  if(mapa[fantx][fanty]==VIDA||mapa[palhax][palhay]==VIDA){
    return 1;    
  } 
  else{
    return 0;
  }
}

int fim(){
  int fim = 0;
  fim = morte_pac(mat);
  if(fim == 3){
    system("clear");
    puts("\n-------------------------------------------");
    COR_VERDE
    printf("\t\tVOCÊ GANHOUUUU 🤑 ");
    COR_BRANCO
    puts("\n-------------------------------------------");
    return 1;
  }
  else if(fim == 2){
    system("clear");
    puts("\n-------------------------------------------");
    COR_VERMELHO
    printf("\t\tPERDEU 🤮");
    COR_BRANCO
    puts("\n-------------------------------------------");
    return 1;
  }
  else{
    return 0;
  }
}