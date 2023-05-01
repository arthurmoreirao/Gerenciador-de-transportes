#ifndef _ADMIN_HPP
#define _ADMIN_HPP
#include "mapa.hpp"


void buscaPeloNome(std::string linhaSelecionada);
void listarReclamacoes();
void write();
void deletaOnibus(int linhaSelecionada);
void alteraTerminal(int linhaSelecionada, std::string novoTerminal);
void alteraItininerario(int linhaSelecionada, std::string novoItinerario);

#endif