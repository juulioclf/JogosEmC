#include <stdio.h>
#include <iostream>
#include <time.h>
#include <string>

using namespace std;

void limpaTela(){
    system("CLS");
}

string retornaPalavra(){

    string palavrasVetor[5] = {"carro", "abacaxi", "macaco", "brasil", "teclado"};

    return palavrasVetor[rand() % 5];
}



string retornaMascara(string palavra, int tamanhoPalavra){

    int i = 0;
    string mascara;

    while(i < tamanhoPalavra){

        mascara += "_";
        i++;
    }

    return mascara;

}

void exibeStatus(string palavra, int tamanhoPalavra, int tentativas){

    cout << "palavra: " << palavra << " (tamanho: " << tamanhoPalavra << ")\n";
    cout << "voce tem " << tentativas << " tentativas\n";
}

void jogarSozinho(){

    string palavra = retornaPalavra();
    int tamanhoPalavra = palavra.size();
    string palavraMascara= retornaMascara(palavra, tamanhoPalavra);
    int tentativas = 0, maxTentativas = (tamanhoPalavra*2);
    int cont;
    char letra;

    while(maxTentativas - tentativas > 0){

        limpaTela();
        exibeStatus(palavraMascara, tamanhoPalavra, (maxTentativas - tentativas));

        cout << "digite uma letra: ";
        cin >> letra;
        char letraMin = tolower(letra);

        for(cont = 0; cont < tamanhoPalavra; cont++){

            if(palavra[cont] == letraMin){

                palavraMascara[cont] = palavra[cont];
            }
        }

        tentativas++;
    }



}

void menuInicial(){

    int opcao;

    while(opcao != 3){

        cout << "Jogo da Forca\n";
        cout << "1- Jogar\n";
        cout << "2- Sobre\n";
        cout << "3- Sair\n";
        cout << "Digite o que voce deseja fazer e pressione ENTER: ";
        cin >> opcao;
        limpaTela();

        switch(opcao){
            case 1:

                jogarSozinho();

                break;

            case 2:

                cout << "Sobre:\nJogo feito por Julio Cesar, em abril de 2021\n\n";
                break;

            case 3:

                cout << "Saindo do jogo da forca...\n";
                break;

            default:

                cout << "Por favor, digite um numero valido\n\n";
                break;

        }

    }

}

int main (){

    srand((unsigned)time(NULL));

    menuInicial();

}
