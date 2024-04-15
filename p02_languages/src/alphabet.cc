// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia // Curso: 2o
// Practica 2: Operaciones con lenguajes
// Autor: Javier Garcia Santana
// Correo: alu0101391663@ull.edu.es
// Fecha: 10/10/2022
//
// Archivo cya-P02-Languages.cc: programa cliente.
// Contienelafunci ́onmaindelproyectoqueusalasclases
//         X e Y para ... (indicar brevemente el objetivo)
// Descripcion otras funcionalidades //
// Referencias:
// Enlaces de interes
//
// Historial de revisiones
// 10/10/2022 - Creacion (primera version) del codigo

#include <fstream>
#include <vector>

#include "alphabet.h"

Alphabet::Alphabet() {
  std::cout << "Ejecutando el constructor de alfabetos por defecto..." << "\n";
  symbols_.clear();
}

Alphabet::Alphabet(const std::vector<Symbol>& input){
  std::cout << "Ejecutando el constructor de alfabetos por parametro..." << "\n";
  std::string aux, aux_2;
  Symbol empty_symbol("&");
  symbols_.push_back(empty_symbol);
  if (input.size() == 1) {
    aux = input[0].getSymbol();
    for (int i = 0; i < aux.size(); ++i) {
      aux_2 = aux[i];
      symbols_.push_back(aux_2);
      aux_2.clear();
    }

  } else {
    for (int i = 0; i < input.size(); ++i) {
      symbols_.push_back(input[i]);
    }
  }
}

std::ostream& operator<<(std::ostream& out, const Alphabet& alphabet) {
  for (int i = 1; i < alphabet.getSymbols().size(); ++i) {
    out << alphabet.getSymbols()[i] << " ";  
  }
  return out;
}

std::vector<Symbol> NoRepeatingSymbols(std::vector<Symbol> symbols) {
  for (int i = 0; i < symbols.size(); ++i) {
    for (int j = i + 1; j < symbols.size(); ++j) {
      if (symbols[i] == symbols[j]) {
        //std::cout << i << j << std::endl;
        symbols.erase(symbols.begin() + j);
      }
    }
  } 
  return symbols;
}
