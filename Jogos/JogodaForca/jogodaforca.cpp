#include <stdio.h>
#include <iostream>
#include <time.h>
#include <string>

using namespace std;

void limpaTela(){
    system("CLS");
}

string retornaPalavra(){

    string palavrasVetor[10] = {"carro", "abacaxi", "macaco", "brasil", "teclado", "celular", "morango", "mouse", "pincel", "crianca"};

    return palavrasVetor[rand() % 9];
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

int jogar(int numeroDeJogadores){

    string palavra;

    if(numeroDeJogadores == 1){

        palavra = retornaPalavra();

    }else{

        cout << "\nDigite uma palavra: ";
        cin >> palavra;

    }


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
            if(letrasArriscadas[cont] == tolower(letra)){

                mensagem =  "ATENCAO: essa letra ja foi digitada!!";

                verificaLetra = true;
            }
        }

        if(verificaLetra == false){

            letrasArriscadas += tolower(letra);


            for(cont = 0; cont < tamanhoPalavra; cont++){

                if(palavra[cont] == tolower(letra)){

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

    while(opcao < 1 || opcao > 3){

        limpaTela();
        cout << "Bem-vindo ao jogo\n";
        cout << "1- Jogar Sozinho\n";
        cout << "2- Jogar em dupla\n";
        cout << "3- Sobre\n";
        cout << "4- Sair\n";
        cout << "Digite o que voce deseja fazer e pressione ENTER: ";
        cin >> opcao;

        switch(opcao){
            case 1:
                if(jogar(1) == 1){
                    menuInicial();
                }

                break;

            case 2:
                if(jogar(2) == 1){
                    menuInicial();
                }
                break;

            case 3:

                limpaTela();
                cout << "Sobre:\nJogo feito por Julio Cesar, em abril de 2021\n\n";
                cout << "\n1 - Voltar";
                cout << "\n2 - Sair\n";
                cout << "Digite um numero e pressione ENTER: ";
                cin >> opcao;
                if(opcao == 1){
                    menuInicial();
                }

                break;

            case 4:
                limpaTela();
                cout << "Saindo do jogo da forca...\n";
                break;

        }

    }

}

int main (){

    srand((unsigned)time(NULL));

    menuInicial();

}
