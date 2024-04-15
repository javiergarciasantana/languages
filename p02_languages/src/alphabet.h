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

#ifndef ALPHABET_H
#define ALPHABET_H

#include <vector>
#include <fstream>

#include "symbol.h"

class Alphabet{
 public:
  Alphabet(); //Constructor por defecto
  Alphabet(const std::vector<Symbol>& input); //Constructor por parametro
  //Sobrecarga del operador de extraccion
  friend std::ostream& operator<<(std::ostream& out, const Alphabet& alphabet);

  //Getter
  std::vector<Symbol> getSymbols() const { return symbols_; }


 private:
  std::vector<Symbol> symbols_;
};

std::vector<Symbol> NoRepeatingSymbols(std::vector<Symbol> symbols);

#endif  //ALPHABET_H