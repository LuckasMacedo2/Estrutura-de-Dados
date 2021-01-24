#ifndef NO_H
#define NO_H
#include <aluno.h>
class No
{
private:
    No * proximo;
    Aluno dados;
public:
    No();
    No(No * proximo, int dados);
    No *getProximo() const;
    void setProximo(No *value);
    int getDados() const;
    void setDados(int value);

    void montarNo(int dados);
    void desmontarNo(No *no);
};

#endif // NO_H
