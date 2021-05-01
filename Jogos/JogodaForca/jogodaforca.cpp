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

void exibeStatus(string palavraMascara, int tamanhoPalavra, int tentativasRestantes, string letrasArricadas, string mensagem){

    cout << mensagem;
    cout << "\npalavra: " << palavraMascara << " (tamanho: " << tamanhoPalavra << ")\n";
    cout << "\ntentativas restantes: " << tentativasRestantes;

    int cont;
    cout << "\nletras arriscadas:";
    for(cont = 0; cont < letrasArricadas.size(); cont++){
        cout << letrasArricadas[cont] << ", ";
    }

}

int jogarSozinho(){

    string palavra = retornaPalavra();

    int tamanhoPalavra = palavra.size();

    string palavraMascara= retornaMascara(palavra, tamanhoPalavra);

    int tentativas = 0, maxTentativas = (tamanhoPalavra*2);
    string letrasArriscadas;

    string mensagem = "Bem-vindo ao jogo!\n";

    int cont, opcaoJogo;
    char letra;
    bool verificaLetra = false, acertouLetra = false;


    while((palavraMascara != palavra) && (maxTentativas - tentativas > 0)){

        limpaTela();
        exibeStatus(palavraMascara, tamanhoPalavra, (maxTentativas - tentativas), letrasArriscadas, mensagem);

        cout << "\ndigite uma letra: ";
        cin >> letra;


        for(cont = 0; cont < tentativas; cont++){
            if(letrasArriscadas[cont] == letra){

                mensagem =  "ATENCAO: essa letra ja foi digitada!!";

                verificaLetra = true;
            }
        }

        if(verificaLetra == false){

            letrasArriscadas += letra;


            for(cont = 0; cont < tamanhoPalavra; cont++){

                if(palavra[cont] == letra){

                    palavraMascara[cont] = palavra[cont];

                    acertouLetra = true;
                }
            }


            if(acertouLetra == false){

                mensagem = "voce errou uma letra";
            }else{

                mensagem = "Voce acertou uma letra! \n";

            }

        tentativas++;

        }
        acertouLetra = false;
        verificaLetra = false;

    }

    if(palavra == palavraMascara){

        limpaTela();
        cout << "Parabens! Voce venceu!!\n\n";
        cout << "Digite UM (1) e aperte ENTER se deseja continuar: ";
        cin >> opcaoJogo;
        return opcaoJogo;

    }else{

        limpaTela();
        cout << "Voce Perdeu!!\n\n";
        cout << "Digite UM (1) e aperte ENTER se deseja continuar: ";
        cin >> opcaoJogo;
        return opcaoJogo;

    }

}

void menuInicial(){

    int opcao;

    while(opcao != 3){

        limpaTela();
        cout << "Bem-vindo ao jogo\n";
        cout << "1- Jogar\n";
        cout << "2- Sobre\n";
        cout << "3- Sair\n";
        cout << "Digite o que voce deseja fazer e pressione ENTER: ";
        cin >> opcao;

        switch(opcao){
            case 1:
                if(jogarSozinho() == 1){
                    menuInicial();
                }

                break;

            case 2:

                limpaTela();
                cout << "Sobre:\nJogo feito por Julio Cesar, em abril de 2021\n\n";
                cout << "\n1 - Voltar";
                cout << "\n2 - Sair\n";
                cin >> opcao;
                if(opcao == 1){
                    menuInicial();
                }
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
