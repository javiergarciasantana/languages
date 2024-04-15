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

#include <iostream>
#include <string>
#include <vector>

#include "alphabet.h"

#ifndef CHAIN_H
#define CHAIN_H

class Chain {
 public:
  Chain();    //Constructor por defecto(cadena vacia)
  Chain(std::string workload);  //Constructor por parametro
  //Getters
  Alphabet getAlphabet() const { return alphabet_; }
  std::vector<Symbol> getChain() const { return chain_; }
  //Sobrecarga del operador de extraccion
  friend std::ostream& operator<<(std::ostream& out, const Chain& desired_chain);
  bool operator==(const Chain& other_chain);
  bool operator!=(const Chain& other_chain);
  Chain& operator+(const Chain& chain);
  Chain& prefixes(const Chain& chain);//Prefijos de la cadena

 private:
  std::vector<Symbol> workload_;
  Alphabet alphabet_;
  std::vector<Symbol> chain_;
};
//Metodos declarado fuera de la clase para favorecer la encapsulacion
int length(const Chain& chain);//Longitud de cadena
std::string backwards(const Chain& chain);//Cadena al reves

std::string suffixes(const Chain& chain, const int kSize);//Sufijos de la cadena
std::string subchains(Chain& chain, int size);//Subcadenas de la cadena
std::string number_of_symbols(const Chain& chain); //numero de simbolos de una cadena

#endif  //CHAIN_H