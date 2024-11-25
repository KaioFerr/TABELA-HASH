#include "Aluno.h"
#include <string>
using namespace std;

Aluno::Aluno () {
    this->id = -1;
    this->nome = "";
};

Aluno::Aluno(int id, string nome) {
    this->id = id;
    this->nome = nome;
}

string Aluno::getNome() {
    return nome;
}

int Aluno::getId() const{
    return id;
}


