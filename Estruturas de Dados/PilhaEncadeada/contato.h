#ifndef CONTATO_H
#define CONTATO_H
#include <string>
using std:: string;
class Contato{
private:
    string nome, telefone;
    Contato * proximo;
public:
    void setNome (string);
    void setTel (string);
    string getNome () const;
    string getTel () const;
    void setProximo (Contato *);
    Contato * getProximo () const;
    Contato ();
};

#endif // CONTATO_H
