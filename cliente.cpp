#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "mapa.hpp"

using namespace std;


extern std::map<int, modeloOnibus> onibus;

//Carrega os dados dos ônibus ao iniciar o programa
void carregarOnibus() {
  fstream arquivo;

  // cria o arquivo onibus.txt caso não exista
  arquivo.open("onibus.txt", ios::out | ios::app);
  arquivo.close();

  // Abre o arquivo onibus.txt para leitura
  fstream arquivoDeLeitura;

  arquivoDeLeitura.open("onibus.txt", ios::in);

  string linha;
  vector<string> vetor;

  // Lê todas as linhas do arquivo e salva cada linha em um vector
  while (getline(arquivoDeLeitura, linha)) {
    vetor.push_back(linha);
  }
  // fecha o arquivo lido.
  arquivoDeLeitura.close(); 

  // Transfere as linhas do vector para dentro do map
  for (int i = 0; i < vetor.size(); i += 3) {
    // stoi converte uma string para um inteiro 
    int numeroDaLinha = stoi(vetor[i]);
    onibus[numeroDaLinha].terminal = vetor[i + 1];
    onibus[numeroDaLinha].itinerario = vetor[i + 2];
   
  }
};

//Imprime a lista de todos os ônibus e seus respectivos terminais e itinerários
void listarOnibus() {
  cout << "\n####  Lista de onibus   ####\n\n";
  cout << "*************************\n";
  for (auto i : onibus) {
    cout << "Número da linha " << i.first << endl;
    cout << "Terminal: " << i.second.terminal << endl;
    cout << "Itinerario: " << i.second.itinerario << endl;
    cout << "*************************\n";
  }
};

//Busca um ônibus pelo seu terminal 
void buscaOnibusTerminal(string terminal) {

  // Abre o arquivo onibus.txt para leitura
  fstream arquivoDeLeitura;

  arquivoDeLeitura.open("onibus.txt", ios::in);

  string linha;
  vector<string> vetor;

  // Lê todas as linhas do arquivo e salva cada linha em um vector
  while (getline(arquivoDeLeitura, linha)) {
    vetor.push_back(linha);
  }
  arquivoDeLeitura.close(); // fecha o arquivo lido.

  // Imprime a linha e itinerário referente ao terminal
  for (int i = 0; i < vetor.size(); i++) {
    if (vetor[i].find(terminal) != string::npos) {
    cout << vetor[i - 1] << endl;
    cout << vetor[i + 1] << endl;
    return;
}
  }
  cout << "Linha não encontrada" << endl;
};

//Imprime um itineário de acordo com o ônibus pesquisado
void buscaItinerario(string linhaSelecionada) {

  // Abre o arquivo onibus.txt para leitura
  fstream arquivoDeLeitura;

  arquivoDeLeitura.open("onibus.txt", ios::in);

  string linha;
  vector<string> vetor;

  // Lê todas as linhas do arquivo e salva cada linha em um vector
  while (getline(arquivoDeLeitura, linha)) {
    vetor.push_back(linha);
  }
  arquivoDeLeitura.close(); // fecha o arquivo lido.

  // Transfere as linhas do vector para dentro do map
  for (int i = 0; i < vetor.size(); i++) {
    if (vetor[i] == linhaSelecionada) {
      cout << vetor[i + 2] << endl;
      return;
    }
  }
  cout << "Itinerário não encontrado, essa linha não existe" << endl;
};

//Escreve a reclamação no arquivo
void write(string reclamacoes_txt, string reclamacaoCompleta) {
  fstream txt;
  txt.open(reclamacoes_txt, ios::in | ios::app);
  txt << reclamacaoCompleta;
  txt.close();
};

//Responsável por capturar as reclamações e sua data
void reclamacoes() {

  string data, reclamacao, reclamacaoCompleta;
  cout << "Digite a data de hoje: [dd/mm/aaaa]" << endl;
  cin >> data;
  cin.ignore();
  cout << "Digite sua reclamação" << endl;
  
  getline(cin, reclamacao);

  reclamacaoCompleta = data + "\n" + reclamacao + "\n";

  write("reclamacoes.txt",reclamacaoCompleta);
};




