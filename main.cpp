#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "admin.hpp"
#include "cliente.hpp"
#include "mapa.hpp"

using namespace std;

int main() {

  // Opções de perfil
  cout << "Escolha seu perfil no sistema:\n";
  cout << "1 - Cliente\n";
  cout << "2 - Admin\n";
  cout << " ";

  // Carrega o arquivo dos ônibus
  carregarOnibus();

  int perfil;
  cin >> perfil;

  // Criar os ifs para cada perfil
  // Cliente
  if (perfil == 1) {

    int acaoCliente;

    // Ação que o cliente deseja
    cout << "Qual ação quer realizar?\n";
    cout << "1 - Listar os ônibus cadastrados\n";
    cout << "2 - Buscar um ônibus por seu bairro\n";
    cout << "3 - Ver o itinerário de um ônibus\n";
    cout << "4 - Fazer uma reclamação\n";
    cout << " ";

    cin >> acaoCliente;

    // Switch case para para cada ação

    switch (acaoCliente) {
    case 1:
      listarOnibus();
      break;
    case 2:{
        string terminal;
        cout << "Digite o terminal" << endl;
        cin >> terminal;
        buscaOnibusTerminal(terminal);
        break;
    }
    case 3:{
      string linhaSelecionada;
      cout << "Digite o nome da linha" << endl;
      cin >> linhaSelecionada;
      buscaItinerario(linhaSelecionada);
      break;
    }
    case 4:
      reclamacoes();
      break;
      
    default:
      cout << "Opção inválida!\n";
      break;
    }
  }

  // Admin
  if (perfil == 2) {
    // Verificação da senha
    int senha = 1234;
    int senhaDigitada;
    cout << "Digite a senha de Admin\n";
    cin >> senhaDigitada;

    if (senhaDigitada == senha) {

      int acaoAdmin;

      // Ação que o admin deseja
      cout << "Qual ação quer realizar?\n";
      cout << "1 - Listar os ônibus cadastrados\n";
      cout << "2 - Buscar um ônibus por seu nome;\n";
      cout << "3 - Buscar um ônibus por seu bairro\n";
      cout << "4 - Atualizar o bairro (terminal) de um determinado ônibus\n";
      cout << "5 - Atualizar o itinerário de um determinado ônibus\n";
      cout << "6 - Excluir um ônibus \n";
      cout << "7 - Listar reclamações\n";
      cout << " ";

      cin >> acaoAdmin;

      // Switch case para para cada ação

      switch (acaoAdmin) {
      case 1:
        listarOnibus();
        break;

      case 2: {
        string linhaSelecionada;
        cout << "Digite o nome" << endl;
        cin >> linhaSelecionada;
        buscaPeloNome(linhaSelecionada);
        break;
        }

      case 3: {
        string terminal;
        cout << "Digite o terminal" << endl;
        cin >> terminal;
        buscaOnibusTerminal(terminal);
        break;
        }

      case 4: {
        int numeroDaLinha;
        cout << "Digite o numero do onibus que deseja alterar o terminal: " << endl;
        cin >> numeroDaLinha;
        string novoTerminal;
        cin.ignore();
        cout << "Digite o novo terminal" << endl;
        getline(cin, novoTerminal);
        //cout << novoTerminal << endl;
        alteraTerminal(numeroDaLinha, novoTerminal);
        break;
        }

      case 5:{
        int numeroDaLinha;
        cout << "Digite o numero do onibus que deseja alterar o itinerario: " << endl;
        cin >> numeroDaLinha;
        string novoItinerario;
        cin.ignore();
        cout << "Digite o novo itinerário" << endl;
        getline(cin, novoItinerario);
        alteraItininerario(numeroDaLinha, novoItinerario);
        break;
        }

      case 6:{
        int numeroDaLinha;
        cout << "Digite o numero da linha que deseja excluir" << endl;
        cin >> numeroDaLinha;
        deletaOnibus(numeroDaLinha);
        break;
        }

      case 7:
        listarReclamacoes();
        break;

      default:
        cout << "Opção inválida\n";
        break;
      }
    }
  }
}
