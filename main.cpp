#include <iostream>
#include <stdlib.h>
#include <time.h>
#define NADA 0
#define MINA -1

using namespace std;

int main()
{
    int bombas, auxBombas, posL=0, posC=0, Lin, Col, qtlinha, qtcoluna, auxCoord, entradaLinha, entradaColuna, qtdJogadas = 0, fimDeJogo = 0;
    srand(time(NULL));

    // Entrada de dados
    cout << "Insira quantidade de linhas: " ;
    cin >> qtlinha;
    cout << "Insira quantidade de colunas: ";
    cin >> qtcoluna;
    cout << "Insira quantidade de bombas: ";
    cin >> bombas;

    // Verificando se todas as entradas estão corretas
    while(qtlinha < 2){
        cout << "Tamanho incorreto, insira novamente a quantidade de linhas:";
        cin >> qtlinha;
    }
    while(qtcoluna < 2){
        cout << "Tamanho incorreto, insira novamente a quantidade de colunas:";
        cin >> qtcoluna;
    }
    while(bombas < 2 || bombas > (qtlinha * qtcoluna)){
        cout << "Numero insuficiente ou excedente de bombas! Insira novamente a quantidade de bombas: ";
        cin >> bombas;
    }
    // criando o mapa

    int campo_1[qtlinha][qtcoluna];
    char campo_2[qtlinha][qtcoluna];

    for(Lin=0; Lin < qtlinha; Lin++){
        for(Col=0;Col < qtcoluna; Col++){
            campo_1[Lin][Col] = NADA;
            campo_2[Lin][Col] = ' ';
        }
    }

    auxBombas = bombas;
    /// sorteio das bombas rand()
    while(auxBombas>0){
      posL=rand()%qtlinha;
      posC=rand()%qtcoluna;
        // Verifica se posL e posC estão nos limites do campo (linha e coluna)
      if(posL >= 0 && posL < qtlinha && posC >= 0 && posC < qtcoluna) {
        if(campo_1[posL][posC] != MINA){
          campo_1[posL][posC] = MINA;
          // Verifica se posC + 1 está nos limites da coluna e se posC + 1 não é uma mina
          if(posC + 1 < qtcoluna && campo_1[posL][posC + 1] != MINA) {
            campo_1[posL][posC + 1]++;
          }
          // Verifica se o posC - 1 esta nos limites da coluna e se posC - 1 não é uma mina
          if(posC - 1 >= 0 && campo_1[posL][posC - 1] != MINA) {
            campo_1[posL][posC - 1]++;
          }
          // Verfica se o posL + 1 esta nos limites da linha e se posL + 1 não é uma mina
          if(posL + 1 < qtlinha && campo_1[posL + 1][posC] != MINA) {
            campo_1[posL + 1][posC]++;
          }
          // Verifica se o posL - 1 esta nos limites da linha e se posL -1 não é uma mina
          if(posL - 1 >= 0 && campo_1[posL - 1][posC] != MINA) {
            campo_1[posL - 1][posC]++;
          }
          // Verifica se posL - 1 esta nos limites da linha e se posC + 1 esta nos limites da coluna e se posL - 1 e pos C + 1 não é uma mina
          if(posL - 1 >= 0 &&  posC + 1 < qtcoluna && campo_1[posL - 1][posC + 1] != MINA) {
            campo_1[posL - 1][posC + 1]++;
          }
          // Verifica se posL - 1 esta nos limites da linha e se posC - 1 esta nos limites da coluna e se posL -1 e posC - 1 não é uma mina
          if(posL - 1 >= 0 && posC -1 >= 0 && campo_1[posL - 1][posC - 1] != MINA) {
            campo_1[posL - 1][posC - 1]++;
          }
          // Verifica se posL + 1 esta nos limites da linha e se posC + 1 esta nos limites da coluna e se posL + 1 e posC + 1 não é uma mina
          if(posL + 1 < qtlinha && posC + 1 < qtcoluna && campo_1[posL + 1][posC + 1] != MINA) {
            campo_1[posL + 1][posC + 1]++;
          }
          // Verifica se posL + 1 esta nos limites da linha posC - 1  esta nos limites da coluna e se posL + 1 e posC - 1 não é uma mina
          if(posL + 1 < qtlinha && posC - 1 >= 0 && campo_1[posL + 1][posC - 1] != MINA) {
            campo_1[posL + 1][posC - 1]++;
          }
          auxBombas--;
        }
      }
    }
    // enquanto fimDeJogo = 0, continua o while
    while(fimDeJogo == 0) {
        system("CLS");
      cout << "\t";
      // Imprime as coordenadas das colunas
      for(auxCoord=0; auxCoord < qtlinha; auxCoord++) {
        cout << auxCoord + 1 << "\t";
      }
      cout << endl;
      cout << "\t";
      for(auxCoord=0; auxCoord < qtlinha; auxCoord++) {
        cout << "-" << "\t";
      }
      cout << endl;

      for(Lin=0;Lin<qtlinha; Lin++){
        for(Col=0;Col<qtcoluna;Col++){
          // Caso seja a primeira coluna, imprime a coordenada da linha
          if(Col == 0) {
            cout << Lin + 1 << " | " << "\t";
          }
          // Imprime o valor do campo atual
          cout << campo_2[Lin][Col] << "\t";
        }
        cout << endl;
      }
      cout << endl;

      // Leitura da jogada, linha e coluna
      cout << "Informe uma linha: ";
      cin >> entradaLinha;
      cout << "Informe uma coluna: ";
      cin >> entradaColuna;

      // Verifica se a jogada na linha está dentro dos limites do campo
      if(entradaLinha > 0 && entradaLinha <= qtlinha ) {
        // Verifica se a jogada na coluna está dentro dos limites do campo
        if(entradaColuna > 0 && entradaColuna <= qtcoluna) {

          // Salva valor no campo2, somase o char '0' + o valor inteiro para gerar o valor em char
          campo_2[entradaLinha-1][entradaColuna-1] = '0' + campo_1[entradaLinha-1][entradaColuna-1];

          // verifica se a jogada acertou uma mina
          if(campo_1[entradaLinha-1][entradaColuna-1] == MINA) {
            // Define fim de jogo
            fimDeJogo = 1;
            // Imprime mensagem e o numero de jogadas validas
            cout << endl << "Você acertou uma mina, fim de jogo!" << endl;
            cout << "Nr de jogadas validas: " << qtdJogadas;
            // break;
          } else {
            // Soma a quantidade de jogadas válidas
            qtdJogadas++;
          }

          // Verifica se a quantidade de jogadas válidas é igual ao numero de campos livres menos o numero de bombas
          if (qtdJogadas == ((qtlinha * qtcoluna) - bombas)) {
            // Define fim de jogo
            fimDeJogo = 1;
            // Imprime mensagem e o numero de jogadas validas
            cout << endl << "Você venceu !" << endl;
            cout << "Nr de jogadas validas: " << qtdJogadas << endl;
          }
        } else {
          // Imprime aviso de coluna invalida
          cout << endl << "Coluna inválida, informe um valor válido para linha!" << endl << endl;
        }
      } else {
        // Imprime aviso de linha invalida
        cout << endl << "Linha inválida, informe um valor válido para linha!" << endl << endl;
      }
    }

return 0;
}
