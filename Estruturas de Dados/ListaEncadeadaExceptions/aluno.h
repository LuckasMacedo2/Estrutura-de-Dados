#ifndef ALUNO_H
#define ALUNO_H
#include <string>
using std::string;
class Aluno{
private:
    string nome, mat;
public:
    void setNome (string);
    void setMat (string);
    string getNome () const;
    string getMatricula () const;
};

#endif // ALUNO_H
