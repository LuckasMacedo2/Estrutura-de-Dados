#include "livro.h"

        livro::livro()
        {

        }
        livro::~livro(){

        }
        string livro:: getTitulo ()const
        {
            return titulo;
        }
        string livro:: getAutor()const
        {
            return autor;
        }
        string livro:: getEditora()const
        {
            return editora;
        }
        string livro::getAno()const
        {
            return ano;
        }
        int livro::getEd ()const
        {
            return ed;
        }
        int livro::getNumPags()const
        {
            return numPags;
        }
        int livro::getVol()const
        {
            return vol;
        }

        void livro::setTitulo (string titulo1)
        {
            this->titulo = titulo1;
        }
        void livro::setAutor(string autor1)
        {
            this->autor = autor1;
        }
        void livro::setEditora(string editora1)
        {
            this->editora = editora1;
        }
        bool livro::setAno(bool ano1)
        {
            if (ano1==false)
            {
                this->ano = ano1;
                return true;
            }
            return false;
        }
        void livro::setEd (int ed1)
        {
            this->ed = ed1;
        }
        void livro::setNumPags(int numPags1)
        {
            this->numPags = numPags1;
        }
        void livro::setVol(int vol1)
        {
            this->vol = vol1;
        }
