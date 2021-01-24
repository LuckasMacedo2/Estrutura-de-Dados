#ifndef ALUNO_H
#define ALUNO_H
#include<string>
using std::string;

#include <string.h>

#include<iostream>
using std::cout;
using std::cin;

class Aluno{
private:
    string nome, mat, tel;
public:
    void setNome (string aux);
    void setMat (string aux);
    void setTel (string aux);
    string getNome ()const;
    string getMat () const;
    string getTel () const;
};

#endif // ALUNO_H
