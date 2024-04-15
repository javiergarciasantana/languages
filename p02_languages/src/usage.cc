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
#include "usage.h"

void Usage(int argc, char* argv[]) {
    
  if (argc > 6 || argc < 5 || argc == 1 ) {
    std::string parameter{argv[1]};
    if (parameter == "--help") {
      std::cerr << kHelpMessage << std::endl;
      exit(EXIT_SUCCESS);
    } else {
      std::cerr << kDefaultMessage << std::endl;
      exit(EXIT_SUCCESS);
    }
  }
}