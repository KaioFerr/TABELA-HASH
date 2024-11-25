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

    void retriveItem( Aluno& aluno, bool& found);
    void insertItem( Aluno aluno);
    void deleteItem( Aluno aluno);
    void print();

private:
    int getHash( Aluno aluno);
    int max_items;
    int length;
    Aluno* structure;
};



#endif //HASH_H
