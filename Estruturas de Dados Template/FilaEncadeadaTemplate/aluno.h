#ifndef ALUNO_H
#define ALUNO_H
#include <string>
using std::string;
class Aluno{
private:
    string nome, mat;
    Aluno * proximo;//A fila quem manipula
public:
    void setNome(string);
    void setMat (string);
    void setProximo (Aluno *);
    string getNome ()const;
    string getMat ()const;
    Aluno * getProximo () const;
};

#endif // ALUNO_H
