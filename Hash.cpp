#include "Hash.h"
#include <string>
#include <iostream>
using namespace std;

Hash::Hash (int max) {
    length = 0;
    max_items = max;
    structure = new Aluno[max_items];
}

Hash::~Hash() {
    delete[] structure;
}

bool Hash::isFull() const {
    return length == max_items;
}

int Hash::getLength() const {
    return length;
}

void Hash::print() {
    for (int i = 0; i < max_items; i++) {
        cout << i << ": " <<
        structure[i].getId()<<","<<
        structure[i].getNome()<<endl;
    }
}

int Hash::getHash(Aluno aluno) {
    return aluno.getId() % max_items;
}

void Hash::retriveItemTesteLinear(Aluno &aluno, bool &found) {
    int locInicial = getHash(aluno);
    bool continuarBuscando = true;
    int location = locInicial;
    do {
        if(structure[location].getId() == aluno.getId() || structure[location].getId() == -1) {
            continuarBuscando = false;
        }else
            location = (location + 1) % max_items;

    }while (location != locInicial && continuarBuscando);

    found = (structure[location].getId() == aluno.getId());
    if (found) {
        aluno = structure[location];
    }
}

void Hash::retriveItemTesteQuadratico(Aluno &aluno, bool &found) {
    int locInicial = getHash(aluno); // Localização inicial (hash do aluno)
    bool continuarBuscando = true;
    int location = locInicial;
    int i = 1; // Tentativa de sondagem
    do {
        if (structure[location].getId() == aluno.getId() || structure[location].getId() == -1) {
            continuarBuscando = false;
        } else {
            location = (locInicial + i * i) % max_items; // Sondagem quadrática
            i++; // Incrementa o deslocamento
        }
    } while (location != locInicial && continuarBuscando && i < max_items); // Evita laço infinito

    found = (structure[location].getId() == aluno.getId());
    if (found) {
        aluno = structure[location];
    }
}


void Hash::insertItemTesteLinear(Aluno aluno) {
    int location;
    location = getHash(aluno);
    while (structure[location].getId() > 0) location = (location + 1) % max_items;
    structure[location] = aluno;
    length++;
}

void Hash::insertItemTesteQuadratico(Aluno aluno) {
    int location = getHash(aluno);
    int attempt = 0;

    while (structure[(location + attempt * attempt) % max_items].getId() > 0) {
        attempt++;
        if (attempt == max_items) {
            throw std::overflow_error("Tabela Hash cheia");
        }
    }

    location = (location + attempt * attempt) % max_items;
    structure[location] = aluno;
    length++;
}


void Hash::deleteItemTesteLinear(Aluno aluno) {
    int locInicial = getHash(aluno);
    bool continuarBuscando = true;
    int location = locInicial;
    do {
        if(structure[location].getId() == aluno.getId() || structure[location].getId() == -1) {
            continuarBuscando = false;
        }else
            location = (location + 1) % max_items;

    }while (location != locInicial && continuarBuscando);

    if (structure[location].getId() == aluno.getId()) {
        structure[location] = Aluno(-2, "");
        length--;
    }
}

void Hash::deleteItemTesteQuadratico(Aluno aluno) {
    int locInicial = getHash(aluno);
    int i = 0; //
    int location = locInicial;
    bool encontrou = false;

    do {
        int probe = (locInicial + i * i) % max_items;
        if (structure[probe].getId() == aluno.getId()) {
            structure[probe] = Aluno(-2, "");
            length--;
            encontrou = true;
            break;
        }
        if (structure[probe].getId() == -1) {
            break;
        }
        i++;
    } while (i < max_items);

    if (encontrou) {
        std::cout << "Aluno com ID = " << aluno.getId() << " foi deletado." << std::endl;
    } else {
        std::cout << "Aluno com ID = " << aluno.getId() << " não encontrado para exclusão." << std::endl;
    }
}


