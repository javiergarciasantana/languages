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

#include "language.h"
#include "chain.h"

Language::Language() {
  workload_.clear();
  alphabet_.getSymbols().clear();
  chains_.clear();
}
Language::Language(std::string& workload) {
  std::string aux; 
  std::vector<Symbol> alphabet;
  
  for (int i = 0; i < workload.size(); ++i) {
    if (workload[i] == '{' && i == 0) {
      for (int j = 2; workload[j] != '}'; ++j) {
        if (workload[j] == ' ') {
          alphabet.push_back(aux);
          aux.clear();
        } else {
          aux += workload[j];
        }
      }
      alphabet_ = alphabet;
    }
    if (workload[i] == '{' && i != 0) {
      for (int j = i + 1; workload[j] != '}'; ++j) {
        if (workload[j] != ' ') {
          aux += workload[j];
 
        } else if (aux.size() != 0) {
          workload_ += aux;
          //std::cout << workload_ << std::endl;
          Chain chain_for(workload_);
          chains_.push_back(chain_for);
          aux.clear();
          workload_.clear();
        }       
      }
    }
  }
}

std::ostream& operator<<(std::ostream& out, const Language& lenguaje) {
  out << "{ " << lenguaje.alphabet_ << "}" << " { ";
  for (int i = 0; i < lenguaje.chains_.size(); ++i) {
    out << lenguaje.chains_.at(i);
  }
  out << "}";
  return out;
}

Language& Language::operator+(const Language& language) {
  std::vector<Chain> chains;
  std::vector<Symbol> alphabet;

  for (int j = 1; j < alphabet_.getSymbols().size(); ++j) {
    alphabet.push_back(alphabet_.getSymbols().at(j).getSymbol());
  }
  for (int j = 1; j < language.alphabet_.getSymbols().size(); ++j) {
    alphabet.push_back(language.alphabet_.getSymbols().at(j).getSymbol());
  }
  for (int i = 0; i <  getChains().size(); ++i) {
    for (int j = 0; j < language.getChains().size(); ++j) {
      chains.push_back(getChains().at(i) + language.getChains().at(j));
    }
  }
  alphabet = NoRepeatingSymbols(alphabet);
  chains_ = chains;
  alphabet_ = alphabet;
  return *this;
 }

Language& Language::operator|(const Language& language) {
  std::vector<Chain> chains;
  std::vector<Symbol> alphabet;
  for (int i = 0; i < getChains().size(); ++i) {
    chains.push_back(getChains().at(i));
  }
  for (int j = 1; j < alphabet_.getSymbols().size(); ++j) {
    alphabet.push_back(alphabet_.getSymbols().at(j).getSymbol());
  }
  for (int i = 0; i < language.getChains().size(); ++i) {
    chains.push_back(language.getChains().at(i));
  }
  for (int j = 1; j < language.alphabet_.getSymbols().size(); ++j) {
    alphabet.push_back(language.alphabet_.getSymbols().at(j).getSymbol());
  }
  chains = NoRepeatingChains(chains);
  alphabet = NoRepeatingSymbols(alphabet);
  chains_ = chains;
  alphabet_ = alphabet;
  return *this;
}

Language& Language::operator^(const Language& language) {
  std::vector<Chain> chains;
  std::vector<Symbol> alphabet;
  for (int i = 0; i < getChains().size(); ++i) {
    chains.push_back(getChains().at(i));
  }
  for (int j = 1; j < alphabet_.getSymbols().size(); ++j) {
    alphabet.push_back(alphabet_.getSymbols().at(j).getSymbol());
  }
  for (int i = 0; i < language.getChains().size(); ++i) {
    chains.push_back(language.getChains().at(i));
  }
  for (int j = 1; j < language.alphabet_.getSymbols().size(); ++j) {
    alphabet.push_back(language.alphabet_.getSymbols().at(j).getSymbol());
  }
  chains = RepeatingChains(chains);
  alphabet = NoRepeatingSymbols(alphabet);
  chains_ = chains;
  alphabet_ = alphabet;
  return *this;
}

std::vector<Chain> NoRepeatingChains(std::vector<Chain> chains){
  for (int i = 0; i < chains.size(); ++i) {
    for (int j = i + 1; j < chains.size(); ++j) {
      if (chains[i] == chains[j]) {
        //std::cout << i << j << std::endl;
        chains.erase(chains.begin() + j);
      }
    }
  } 
  return chains;
}

std::vector<Chain> RepeatingChains(std::vector<Chain>& chains) {
  std::vector<Chain> result;
  bool incidence;
  for (int i = 0; i < chains.size(); ++i) {
    for (int j = i + 1; j < chains.size(); ++j) {
      incidence = false;
      if (chains[i] == chains[j]) {
        //std::cout << i << j << std::endl;
        result.push_back(chains[i]);
        incidence = true;
      } 
    }
  } 
  return NoRepeatingChains(result);
}

Language& Language::Reverse() {
  std::vector<Chain> chains;
  Chain aux;
  for (int i = 0; i < getChains().size(); ++i) {
    Chain aux(backwards(getChains().at(i)));
    chains.push_back(aux);
  }
  chains_ = chains;
  return *this;
}

Language& Language::Power(const int kExponent) {
  assert(kExponent >= 0);
  Language aux;
  if (kExponent == 0) {
    Chain empty_chain;
    chains_.clear();
    chains_.push_back(empty_chain);
    return *this;
  } else if (kExponent == 1) {
    return *this;
  } else {
    aux.chains_ = getChains();
    for (int i = 1; i < kExponent; ++i) {
      *this = (*this + aux);
    }
    return *this;
  }
}

Language& Language::operator-(const Language& language) {
  std::vector<Chain> chains;
  std::vector<Symbol> alphabet;

  for (int j = 1; j < alphabet_.getSymbols().size(); ++j) {
    alphabet.push_back(alphabet_.getSymbols().at(j).getSymbol());
  }
  for (int j = 1; j < language.alphabet_.getSymbols().size(); ++j) {
    alphabet.push_back(language.alphabet_.getSymbols().at(j).getSymbol());
  }
  alphabet = NoRepeatingSymbols(alphabet);
  alphabet_ = alphabet;
  chains = getChains();
  for (int i = 0; i < chains.size(); ++i) {
    for (int j = 0; j < language.getChains().size(); ++j) {
      if (chains.at(i) == language.getChains().at(j)) {
        chains.erase(chains.begin() + i);
      }
    }
  }
  chains_ = chains;
  return *this;
}
Language& Language::Prefixes() {
  Chain result;
  std::vector<Chain> chains;
  Language result_1;
  std::string aux_2;
  chains = getChains();
  for (int i = 0; i < chains.size(); ++i) {
    result.prefixes(chains.at(i));
    chains.at(i) = result;
  }
  chains_ = chains_ ;
  return *this;
}