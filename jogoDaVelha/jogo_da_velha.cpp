#include <bits/stdc++.h>

using namespace std;


#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f

typedef long long ll;

char verifica(string tabela[]){
    char c = 'c';
    for(int i = 0 ; i < 3 ; i++){
        if((tabela[2*i][1] == tabela[2*i][5]) && (tabela[2*i][5] == tabela[2*i][9])){
            c = tabela[2*i][1];
            return c;
        }
        if((tabela[0][1+4*i] == tabela[2][1+4*i])&&(tabela[2][1+4*i] == tabela[4][1+4*i])){
            c = tabela[0][1+4*i];
            return c;
        }
    }
    if((tabela[0][1] == tabela[2][5])&&(tabela[4][9] == tabela[2][5])) return tabela[0][1];
    if((tabela[4][1] == tabela[2][5])&&(tabela[0][9] == tabela[2][5])) return tabela[4][1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    char c, resultado, vez = 'x';
    int linha = 0, coluna = 1,cont = 0;
    string matriz[5] = {{"[ ]|   |   "},{"-----------"},{"   |   |   "},{"-----------"},{"   |   |   "}};
    cout << "\nBem vindo ao jogo da velha de Rafael Pontes\n\nUtilize \"w\", \"a\", \"s\" e \"d\" + enter para se movimentar" <<endl;
    cout<<"caso deseje sair digite \"e\" \n"<<endl;

    do{ 
        cout << "Vez do jogador \"" << vez << "\"\n" <<endl; 
        for(int i = 0 ; i < 5 ; i++){
            cout<< matriz[i]<< endl;
        }
        
        cin >> c;

        matriz[linha][coluna-1] = ' ';
        matriz[linha][coluna+1] = ' ';
        if(1){
            switch (c)
            {
                case 'a': 
                        coluna == 1 ? coluna = 9 : coluna = coluna - 4;
                    break;
                case 'd': 
                        coluna == 9 ? coluna = 1 : coluna = coluna + 4;
                    break;
                case 'w': 
                        linha == 0 ? linha = 4 : linha -= 2;
                    break;
                case 's': 
                         linha == 4 ? linha = 0 : linha += 2;
                    break;
                case 'x': 
                         if((matriz[linha][coluna] == ' ')&&(vez == 'x')){
                              matriz[linha][coluna] = c;
                              vez = 'o';
                              cont++;
                         }
                         else cout << "opcao invalida, jogue novamente" << endl << endl;
                    break;
                case 'o': 
                         if((matriz[linha][coluna] == ' ')&&(vez == 'o')){
                             matriz[linha][coluna] = c;
                             vez = 'x';
                             cont++;
                         }
                         else cout << "opcao invalida, jogue novamente\n" << endl << endl;
                    break;
                case 'e': return 2;
                    break;
                default: 
                         cout << "Escolha um digito valido"<< endl <<endl;
                    break;
            }
        }
            matriz[linha][coluna-1] = '[';
            matriz[linha][coluna+1] = ']';
        resultado = verifica(matriz);
        if((resultado == 'x')||(resultado == 'o')){
            cout << "O jogador do " << resultado<< " ganhou o jogo!";
            break;
        } 
    }while(cont < 9);
    if(cont == 9) cout << "o Jogo empatou"<<endl;

    return 0;
}