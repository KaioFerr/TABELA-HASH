#include <iostream>
#include "hash.h"
using namespace std;

int main() {
    Hash tabelaAlunos(10);
    int ras[7] = {12704, 31300, 1234, 49001, 52202, 65606, 91234};
    string nomes[7] = {"Pedro", "Raul", "Paulo", "Carlos", "Lucas", "Maria", "Samanta"};


    int opcao = 0;

    switch (opcao) {
        //TESTE LINEAR
        case 1:{
            for (int i = 0; i < 7; i++) {
                Aluno aluno = Aluno(ras[i], nomes[i]);
                tabelaAlunos.insertItemTesteLinear(aluno);
            }

            cout << "Tabela apos insercoes iniciais:" << endl;
            tabelaAlunos.print();

            Aluno alunoTeste = Aluno(ras[2], nomes[2]);
            bool encontrou = false;

            tabelaAlunos.retriveItemTesteLinear(alunoTeste, encontrou);

            if (encontrou) {
                cout << "Aluno encontrado: ID = " << alunoTeste.getId()
                          << ", Nome = " << alunoTeste.getNome() << endl;
            } else {
                cout << "Aluno com ID = " << alunoTeste.getId() << " nao encontrado." << endl;
            }

            cout << "Deletando o aluno com ID = " << alunoTeste.getId() << endl;
            tabelaAlunos.deleteItemTesteLinear(alunoTeste);

            cout << "Tabela apos exclusao:" << endl;
            tabelaAlunos.print();

            break;
        }

        //SONDAGEM QUADRÁTICO
        case 2: {
            for (int i = 0; i < 7; i++) {
                Aluno aluno = Aluno(ras[i], nomes[i]);
                tabelaAlunos.insertItemTesteQuadratico(aluno);
            }

            cout << "Tabela apos insercoes iniciais:" << endl;
            tabelaAlunos.print();

            Aluno alunoTeste = Aluno(ras[2], nomes[2]);
            bool encontrou = false;

            tabelaAlunos.retriveItemTesteQuadratico(alunoTeste, encontrou);

            if (encontrou) {
                cout << "Aluno encontrado: ID = " << alunoTeste.getId()
                          << ", Nome = " << alunoTeste.getNome() << endl;
            } else {
                cout << "Aluno com ID = " << alunoTeste.getId() << " nao encontrado." << endl;
            }

            cout << "Deletando o aluno com ID = " << alunoTeste.getId() << endl;
            tabelaAlunos.deleteItemTesteQuadratico(alunoTeste);

            cout << "Tabela apos exclusao:" << endl;
            tabelaAlunos.print();

            break;
        }

    }
}
