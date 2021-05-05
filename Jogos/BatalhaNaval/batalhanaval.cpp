#include <iostream>
#include <string>


using namespace std;

void limpaTela(){
    system("CLS");
}

int main(){

    int opcao = 0;

    while(opcao != 3){\

        cout << "1: Jogar\n";
        cout << "2: Sobre\n";
        cout << "3: Sair\n";
        cout << "Digite um valor e aperte ENTER: ";
        cin >> opcao;

        switch (opcao){
            case 1:

                cout << "Jogo iniciado\n";
                break;

            case 2:

                cout << "Sobre\n";
                break;

            case 3:

                cout << "Saindo do jogo ...\n";
                break;
        }
    }

    return 0;
}
