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

#ifndef USAGE_H
#define USAGE_H
//Funcion para ayudar al usuario a entender la manera de usar el programa
void Usage(int argc, char* argv[]);
//variables constantes
const std::string kDefaultMessage = {"Ha intoducido erroneamente los parametros requeridos por el programa,\n\
por favor, siga el siguiente esquema: ./p02_languages filein_1.txt filein_2.txt fileout.txt option\n\
para mas informacion ejecute lo siguiente: ./p02_languges --help"};
const std::string kHelpMessage = {"      DIVERSAS FUNCIONES DEL PROGRAMA P01_STRINGS\n\
1: Retorna la concatenacion de dos lenguajes\n\
2: Retorna la union de dos lenguajes\n\
3: Retorna la interseccion de dos lenguajes\n\
4: Retorna la diferencia de dos lenguajes \n\
5: Retorna la inversa de un lenguaje\n\
6: Retorna la potencia de un lenguaje, para este hay q pasar el exponente por linea de comandos"};

#endif //USAGE_H

// 1. Concatenaci´on
// 2. Uni´on
// 3. Intersecci´on
// 4. Diferencia
// 5. Inversa
// 6. Potencia