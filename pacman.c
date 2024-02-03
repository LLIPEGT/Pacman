#include "fllp.h"
#include "keyboard.h"

int main() {

  int mapa[alt][larg], final = 0;
  char jogada, jogadafant;
  iniciarmap(mapa);
  // edição do mapa
  while (final == 0) {
    system("clear");
    desenharmap(mapa);
    jogada = getTecla();
    final = atualizarmap(mapa, jogada);
  }
  // jogo
  final = 0;
  while (final == 0) {
    system("clear");
    desenharmap(mapa);
    jogada = getTecla();
    movfantasma(mapa);
    movpalhaco(mapa);
    efetuarjogada(mapa, jogada);
    final = fim();
  }

  return 0;
}