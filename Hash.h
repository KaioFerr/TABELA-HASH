//
// Created by Kaio on 25/11/2024.
//

#ifndef HASH_H
#define HASH_H
#include "Aluno.h"


class Hash {
public:
    Hash(int max_items = 100);

    ~Hash();

    bool isFull() const;
    int getLength() const;

    void retriveItemTesteLinear( Aluno& aluno, bool& found);
    void retriveItemTesteQuadratico(Aluno &aluno, bool &found);
    void insertItemTesteLinear( Aluno aluno);
    void insertItemTesteQuadratico(Aluno aluno);
    void deleteItemTesteLinear( Aluno aluno);
    void deleteItemTesteQuadratico(Aluno aluno);

    void print();

private:
    int getHash( Aluno aluno);
    int max_items;
    int length;
    Aluno* structure;
};



#endif //HASH_H
