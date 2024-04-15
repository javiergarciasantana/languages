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

#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <iostream>
#include <vector>
#include <string>

#include "chain.h"

class Language {
 public:
  Language();//constructor por defecto
  Language(std::string& workload); //constructor por parametros

  std::vector<Chain> getChains() const { return chains_; } //getter de chains
  Alphabet getAlphabet() const { return alphabet_; } //getter de alfabeto

  friend std::ostream& operator<<(std::ostream& out, const Language& language); //sobrecarga del operador de extraccion
  Language& operator+(const Language& language);//sobrecarga del operador + para la conscatenacion de lenguajes
  Language& operator|(const Language& language); //sobrecarga del operador | para la union de lenguajes
  Language& operator^(const Language& language);//sobrecarga del operator ^ para la interseccion de lenguajes
  Language& operator-(const Language& language);//sobrecarga del operador - para la diferencia de lenguajes
  Language& Reverse();// Hace el inverso del lenguaje deseado
  Language& Power(const int kExponent); //Potencia del lenguaje deseado con el exponente como parametro
  Language& Prefixes();
 private:
  std::string workload_;
  std::vector<Chain> chains_;
  Alphabet alphabet_;
};  

std::vector<Chain> NoRepeatingChains(std::vector<Chain> chains);//funcion para que no se repitan elementos dentro de las cadenas del lenguaje
std::vector<Chain> RepeatingChains(std::vector<Chain>& chains);//funcion para saber que cadenas son las que se repiten en un lenguaje

#endif