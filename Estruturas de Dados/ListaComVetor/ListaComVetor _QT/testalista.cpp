#include"testalista.h"
Aluno * TestaLista:: criarAluno (){
    Aluno *obj = new Aluno;
    string aux;
    cout<<"\nInforme o nome do aluno: ";
    cin>>aux;
    obj->setNome(aux);
    cout<<"\nInforme o número de matricula do mesmo: ";
    cin>>aux;
    obj->setMat(aux);
    cout<<"\nInforme o número de telefone do aluno: ";
    cin>>aux;
    obj->setTel(aux);
    return obj;
}

void TestaLista::mostraAluno (Aluno *obj){
    Aluno *aux = new Aluno;
    aux = obj;
    cout<<"\n\n\n";
    cout<<"\nAluno: "<<aux->getNome();
    cout<<"\nMatricula número: "<<aux->getMat();
    cout<<"\nTelefone: "<<aux->getTel();
    cout<<"\n\n\n";
}

void TestaLista::menu(){
    int tamanho, opc, i;
    string busca;
    Aluno *pontAluno = new Aluno;

    cout<<"\nInforme o tamanho da fila: ";
    cin>>tamanho;
    while (tamanho<2){
        cout<<"\nInforme novamente! Valor informado inválido.\nTamanho: ";
        cin>>tamanho;
    }

    obj.setTam(tamanho);

    do{
        cout<<"\nInforme \n(1)Colocar Aluno na Lista \n(2)Retirar Aluno da Lista \n(3)Exibir a Lista de Alunos \n(4)Para sair \nOpção: ";
        cin>>opc;
        switch (opc) {
        case 1:
        	if (!obj.listaCheia())
			{
            	pontAluno = criarAluno();
           	 	obj.inserirOrdenado(pontAluno);
           		 if (pontAluno)
            	{
                	cout<<"\nAluno adicionado com sucesso!";
            	}
        	}
            else
            {
                cout<<"\nImpossivel adicionar aluno na fila\n";
            }
        break;
        case 2:
            if (!(obj.listaVazia())){
                cout<<"\nInforme o nome do aluno: ";
                cin>>busca;
                i = obj.buscar(busca);
                if (i<0)
                {
                    cout<<"\nAluno não Encontrado!";
                }
                else{
                    pontAluno = obj.retirarAluno(i);
                    if (pontAluno)
                    {
                        cout<<"\nAluno removido com sucesso: ";
                        mostraAluno(pontAluno);
                    }
                    else
                    {
                        cout<<"\nERRO";
                    }
                }
            }
            else
            {
                cout<<"\nLista Vazia. Impossivel remover aluno\n";
            }
        break;
        case 3:
            if (obj.listaVazia()){
                cout<<"\nImpossivel exibir Lista não criada";
            }
            else{
                cout<<"\n--------LISTA------";
                obj.exibirLista();
            }
        break;
        case 4:
            exit (1);
        break;
        default:
            cout<<"\nOpção inválida! Informe novamente";
            cout<<"\nInforme \n(1)Enfilheirar \n(2)Desenfilheirar \n(3)Exibir a Lista de Alunos \n(4)Para sair \nOpção: ";
            cin>>opc;
        break;
        }

    }while (opc!=4);
}
