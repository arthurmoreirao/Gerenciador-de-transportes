#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "mapa.hpp"

using namespace std;

extern std::map<int, modeloOnibus> onibus;

//Faz a busca do ônibus pelo seu nome
void buscaPeloNome(string linhaSelecionada) {

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

  // Imprime os dados da linha selecionada pelo usuário
  for (int i = 0; i < vetor.size(); i++) {
    if (vetor[i] == linhaSelecionada) {
      cout << vetor[i] << endl;
      cout << vetor[i+1] << endl;
      cout << vetor[i+2] << endl;
      return;
    }
  }
  cout << "Itinerário não encontrado, essa linha não existe" << endl;
} 

//Lista as reclamações
void listarReclamacoes(){
    // Abra o arquivo para leitura
    ifstream arquivo("reclamacoes.txt");

    // Verifica se há alguma reclamação
    if (!arquivo) {
        cout << "Não há reclamacoes" << endl;
        return;
    } 

    // Faz a leitura e imprime o conteúdo do arquivo
    string linha;
    while (getline(arquivo, linha)) {
        cout << linha << endl;
    }

    // Fecha o arquivo
    arquivo.close();

    return;
};

//Faz a escrita do map alterado pelas funções de atualizações e de pela de apagar um ônibus
void write(){
  ofstream novoArquivo("onibus.txt");
  for (auto i : onibus) {
    novoArquivo << i.first << endl;
    novoArquivo << i.second.terminal << endl;
    novoArquivo << i.second.itinerario << endl;
  }
  novoArquivo.close();
}

//Deleta um ônibus de acordo com a linha de ônibus selecionada pelo usuário
void deletaOnibus(int linhaSelecionada) {
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

  //apaga o antigo arquivo dos ônibus
  remove("onibus.txt");

  // Percorre o vetor e apaga o ônibus de acordo com a linha selecionada
  for (int i = 0; i < vetor.size(); i += 3) {
    // stoi converte uma string para um inteiro longo
    int numeroDaLinha = stoi(vetor[i]);
    if(numeroDaLinha == linhaSelecionada){
      onibus.erase(numeroDaLinha);
    }
  }
  
  write();
}

//Altera o terminal de uma linha, recebendo como parâmetros o número do ônibus e o novo terminal
void alteraTerminal(int linhaSelecionada, string novoTerminal) {
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

  //apaga o antigo arquivo dos ônibus
  remove("onibus.txt");

  // Percorre o vetor e faz a alteração no terminal do ônibus escolhido
  for (int i = 0; i < vetor.size(); i += 3) {
    // stoi converte uma string para um inteiro
    int numeroDaLinha = stoi(vetor[i]);
    if(numeroDaLinha == linhaSelecionada){
      onibus[numeroDaLinha].terminal = novoTerminal;
    }
  }
  
  write();
}

//Altera o itinerário de uma linha, recebendo como parâmetros o número do ônibus e o novo itinerário
void alteraItininerario(int linhaSelecionada, string novoItinerario) {
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

  //apaga o antigo arquivo dos ônibus
  remove("onibus.txt");

  // Percorre o vetor e faz a alteração no itinerário do ônibus escolhido
  for (int i = 0; i < vetor.size(); i += 3) {
    // stoi converte uma string para um inteiro
    int numeroDaLinha = stoi(vetor[i]);
    if(numeroDaLinha == linhaSelecionada){
      onibus[numeroDaLinha].itinerario = novoItinerario;
    }
  }
  
  write();
}
