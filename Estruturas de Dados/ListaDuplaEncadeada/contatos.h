#ifndef CONTATOS_H
#define CONTATOS_H
#include <string>
using std::string;
#include <iostream>
using std::cin;
using std::cout;

class Contatos
{
private:
    string nome, email,  telefone;
public:
    void setNome (string);
    void setEmail (string);
    void setTel (std::string);
    string getNome () const;
    string getEmail () const;
    string getTel () const;

};

#endif // CONTATOS_H
