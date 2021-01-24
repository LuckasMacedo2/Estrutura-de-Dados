#ifndef LIVRO_H
    #define LIVRO_H
#include <string>
using std::string;


class livro
{
private :
     string titulo, autor, editora, ano;
     int ed, numPags, vol;
 public :
     livro ();
     ~livro();
     string getTitulo ()const;
     string getAutor()const;
     string getEditora()const;
     string getAno()const;
     int getEd ()const;
     int getNumPags()const;
     int getVol()const;

     void setTitulo (string);
     void setAutor(string);
     void setEditora(string);
     bool setAno(bool);
     void setEd (int);
     void setNumPags(int);
     void setVol(int);
};

#endif // LIVRO_H
