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
#include <cassert>

#include "chain.h"

Chain::Chain() {
  std::cout << "Ejecutando el constructor de cadenas por defecto..." << "\n";
  workload_.clear();
  chain_.clear();
  alphabet_.getSymbols().clear();
  Symbol empty_symbol{"&"};
  chain_.push_back(empty_symbol);
}

Chain::Chain(std::string workload) {
  std::cout << "Ejecutando el constructor de cadenas por parametro..." << std::endl;
  std::string aux, aux_2;

  for (int i = 0; i < workload.size(); ++i) {
    if (workload[i] == ' ') {  //dos casos rey
      workload_.push_back(aux);
      aux.clear(); 
    } else if (i == workload.size() - 1) {
      aux += workload[i];
      workload_.push_back(aux);
      aux.clear();
    } else {
      aux += workload[i]; 
    }
  }
  aux.clear();
  aux += workload_[workload_.size() - 1].getSymbol();

  if (workload_.size() > 1) {
    workload_.erase(workload_.end() - 1);
  }

  alphabet_ = workload_;

  for (int i = 0; i < aux.size(); ++i) {
    aux_2 += aux[i];
    for (int j = 0; j < alphabet_.getSymbols().size(); ++j) {
      if (aux_2 == alphabet_.getSymbols().at(j).getSymbol()) {
        chain_.push_back(aux_2);
        aux_2.clear();
      }
    }
  }
  
}

std::ostream& operator<<(std::ostream& out, const Chain& desired_chain) {
  for (int i = 0; i < desired_chain.getChain().size(); ++i) {
    out << desired_chain.getChain().at(i).getSymbol();
  }
  out << " ";
  return out;
}
bool Chain::operator==(const Chain& other_chain) {
  bool result;
  if (getChain().size() != other_chain.getChain().size()) {
    return false;
  } else {
    result = true;
    for (int i = 0; i < getChain().size(); ++i) {
      if (getChain().at(i).getSymbol() != other_chain.getChain().at(i).getSymbol()) {
        result = false;
      }
    }
  }
  return result;
}

bool Chain::operator!=(const Chain& other_chain) {
  bool result;
  if (getChain().size() != other_chain.getChain().size()) {
    return true;
  } else {
    result = false;
    for (int i = 0; i < getChain().size(); ++i) {
      if (getChain().at(i).getSymbol() != other_chain.getChain().at(i).getSymbol()) {
        result = true;
      }
    }
  }
  return result;
}

int length(const Chain& chain) {
  return chain.getChain().size();
}

std::string backwards(const Chain& desired_chain) {
  std::string result;
  for (int i = desired_chain.getChain().size() - 1; i >= 0; --i) {
    result += desired_chain.getChain().at(i).getSymbol();
  }
  return result;
}

Chain& Chain::prefixes(const Chain& chain) {
  std::string result_1;
  
  for (int i = 0; i < chain.getChain().size(); ++i) {      
    for (int j = 0; j < i; ++j) {
    result_1 += chain.getChain().at(j).getSymbol();
   }
  }
  Chain result_2(result_1);
  return result_2;
}

std::string suffixes(const Chain& chain, const int kSize) {
  std::string result;
  for (int i = (chain.getChain().size() - kSize), k = 0; i < chain.getChain().size(); ++i) {
    result += chain.getChain().at(i).getSymbol();
  }
  return result;
}

std::string subchains(Chain& chain, int size) {
  std::string result;
  for (int length = 1; length <= size; length++) {   
    for (int i = 0; i <= size - length; i++) {
      int j = i + length - 1;           
      for (int k = i; k <= j; k++) {
        result += chain.getChain().at(k).getSymbol();
      }
      result += " ";
    }
  }
  return result;
}

std::string number_of_symbols(const Chain& chain) {
  std::string result;
  std::vector<int> counter;
  counter.resize(chain.getAlphabet().getSymbols().size());
  for (int i = 0; i < counter.size(); ++i) {
    counter[i] = 0;
  }
  for (int i = 0; i < chain.getChain().size(); ++i) {
    for (int j = 0; j < chain.getAlphabet().getSymbols().size(); ++j) {
      if (chain.getChain().at(i).getSymbol() == chain.getAlphabet().getSymbols().at(j).getSymbol()) {
        ++counter[j];
      }
    }
  }
  for (int i = 0; i < chain.getAlphabet().getSymbols().size(); ++i) {
    result += chain.getAlphabet().getSymbols().at(i).getSymbol();
    result += "-> ";
    result += std::to_string(counter[i]);
    result += " ";
  }
  return result;
}

Chain& Chain::operator+(const Chain& chain) {
  for (int i = 0; i < chain.chain_.size(); ++i) {
    chain_.push_back(chain.chain_.at(i));
  }
  return *this;
}