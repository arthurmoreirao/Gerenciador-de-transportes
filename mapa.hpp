#ifndef _MAPA_HPP
#define _MAPA_HPP
#include <map>
#include <string>

struct modeloOnibus {
  int numero;
  std::string terminal;
  std::string itinerario;
};

extern std::map<int, modeloOnibus> onibus;



#endif