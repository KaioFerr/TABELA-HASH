#ifndef ALUNO_H
#define ALUNO_H
#include <string>
using namespace std;



using namespace std;
class Aluno {
private:
    int id;
    string nome;

public:
    Aluno();
    Aluno(int id, string nome);
    string getNome();
    int getId() const;
};


#endif //ALUNO_H
