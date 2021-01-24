#ifndef ALUNO_H_
    #define ALUNO_H_
 #include <string>
 using std::string;
class Aluno{
    private:
        string nome, telefone, matricula;
    public:
        void setNome (string);
        void setTel (string);
        void setMat (string);
        string getNome () const;
        string getTel () const;
        string getMat () const;
};

#endif
