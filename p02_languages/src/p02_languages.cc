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
#include <fstream>

#include "language.h"
#include "usage.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv); 
  std::ifstream input_1, input_2;
  input_1.open(argv[1], std::ios_base::in);
  input_2.open(argv[2], std::ios_base::in);
  if (input_1.is_open() && input_2.is_open()) {
    std::string line_1, line_2;
    std::ofstream output_file{argv[3]};
    while (getline(input_1, line_1)) { 
      getline(input_2, line_2);
      Language desired_language_1(line_1);
      Language desired_language_2(line_2);    
      Chain empty_chain;
      switch(atoi(argv[4])) {

        case 1:
          output_file << desired_language_1 + desired_language_2 << std::endl;
          break;

        case 2:
          output_file << (desired_language_1 | desired_language_2) << std::endl;
          break;

        case 3:
          output_file << (desired_language_1 ^ desired_language_2) << std::endl;
          break;

        case 4:
          output_file << desired_language_1 - desired_language_2 << std::endl;
          break; 

        case 5:
          output_file << desired_language_1.Reverse() << std::endl; 
          break;
      
        case 6:
          output_file <<  desired_language_1.Power(atoi(argv[5])) << std::endl; 
          break;
        case 7:
          output_file <<  desired_language_1.Prefixes() << std::endl; 
          break;

        default:
          break;
      }
    }
    std::cout << "El fichero de salida se ha creado con exito" << std::endl;
  } else {
    std::cerr << "An error was produced opening the file" << std::endl;
    exit(EXIT_SUCCESS);
  }
  
  return 0;
}