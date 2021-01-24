#include "testaordenado.h"

void TestaOrdenado::menu(){
    int opc;
    Contatos * ptrContato;
    ListaDuplaEncadedada *acesso=new ListaDuplaEncadedada;
    string buscar;
    do{
        cout<<"\nInforme \n[1]Para inserir o Contato ordenadamente \n[2]Para mostrar a lista de contato \n[3]Para retirar o Contato\n[4]Para buscar contato \n[5]Para sair\nOPCÃO: ";
        cin>>opc;
        switch (opc){
            case 1:
                try {
                    ptrContato = criaContato();
                    if (ptrContato){
                        acesso->inserirOrdenado(ptrContato);
                        cout<<"\nContato adicionado com sucesso!\n";
                        mostraContato(ptrContato);
                    }
                    else
                        throw string ("\nERRO, Contato não criado\n");
                } catch (string erro) {
                    cout<<erro;
                }
                catch (std::bad_alloc &){
                    cout<<"\nFalta de memoria, verificar sua maquina\n";
                }

            break;

            case 2:
                try{
                 cout<<"\n"<<acesso->listar()<<"\n";
                }catch (string erro)
                {
                    cout<<erro;
                }

            break;

            case 3:
                try {
                    cout<<"\nInforme o nome do contato, á ser removido: ";
                    cin>>buscar;

                    ptrContato=acesso->retirar(buscar);

                    if (ptrContato==NULL)
                        throw string ("ERRO, Contato não encontrado");

                    else {
                        cout<<"\nContato removido com sucesso";
                        mostraContato(ptrContato);
                    }

                } catch (string erro) {
                    cout<<erro;
                }
            break;

            case 4:
                try{
                cout<<"\nInforme o nome do contato a ser mostrado ";
                cin>>buscar;
                ptrContato = acesso->buscar(buscar);

                if (ptrContato==NULL)
                    throw string ("\nERRO, Contato não encontrado");

                else{
                    mostraContato(ptrContato);
                }
                }catch (string erro){
                    cout<<erro<<"\n";
                }
                break;
                case 5:
                    acesso=NULL;
                    delete acesso;
                break;
                default:
                    cout<<"a opção não se encontra no menu\n";
          break;

        }
    }while (opc!=5);

}
//usa ela de forma desordeanda
void TestaOrdenado::menu2(){
    int opc;
    Contatos * ptrContato;
    ListaDuplaEncadedada *acesso=new ListaDuplaEncadedada;
    string buscar;
    do{
        cout<<"\nInforme \n[1]Para inserir no inicio\n[2]Para inserir no final \n[3]Para retirar do inicio \n"
              "[4]Para retirar do final \n[5]Para retirar o Contato\n[6]Para buscar contato\n[7]Para mostar lista  \n[8]Para sair\nOPCÃO: ";
        cin>>opc;
        switch (opc){
            case 1:
                try {
                    ptrContato = criaContato();
                    if (ptrContato){
                        acesso->inserirInicio(ptrContato);
                        cout<<"\nContato adicionado com sucesso!\n";
                        mostraContato(ptrContato);
                    }
                    else
                        throw string ("\nERRO. Contato não criado\n");
                } catch (string erro) {
                    cout<<erro;
                }
                catch (std::bad_alloc &){
                    cout<<"\nFalta de memoria, verifique sua maquina";
                }

            break;

            case 2:
            try {
                ptrContato = criaContato();
                if (ptrContato){
                    acesso->inserirFinal(ptrContato);
                    cout<<"\nContato adicionado com sucesso!\n";

                }
                else
                    throw string ("\nERRO. Contato não criado\n");
                } catch (string erro) {
                    cout<<erro;
                }
                catch (std::bad_alloc &){
                    cout<<"\nFalta de memoria, verifique sua maquina\n";
                }

            break;

            case 3:
                try{
                    ptrContato=acesso->retirarInicio();
                    if (ptrContato!=NULL){
                       mostraContato(ptrContato);
                    }
                    else
                        throw string ("\nERRO. Impossivel remover o contato informado\n");
                }catch (string erro) {
                    cout<<erro;
                }
            break;

            case 4:
                try{
                    ptrContato=acesso->retirarFinal();
                    if (ptrContato!=NULL){
                       mostraContato(ptrContato);
                    }
                    else
                       throw string ("\nERRO. Impossivel remover o contato informado\n");
                }catch (string erro) {
                    cout<<erro;
                }
            break;
            case 5:
                try {
                    cout<<"\nInforme o nome do contato, á ser removido: ";
                    cin>>buscar;

                    ptrContato=acesso->retirar(buscar);
                    if (ptrContato==NULL)
                        throw string ("\nERRO. Contato não encontrado\n");

                    else {
                    cout<<"\nContato removido com sucesso\n";
                        mostraContato(ptrContato);
                    }

                } catch (string erro) {
                    cout<<erro;
                }
           break;

            case 6:
            try{
                cout<<"\nInforme o nome do contato a ser mostrado ";
                cin>>buscar;
                ptrContato = acesso->buscar(buscar);

                if (ptrContato==NULL)
                    throw string ("\nERRO. Contato não encontrado\n");

                else{
                    mostraContato(ptrContato);
                }
            }catch (string erro){
                cout<<erro;
            }
            break;

            case 7:
               try{
                    cout<<acesso->listar();
               }catch (string erro)
               {
                    cout<<erro;
               }

            break;

            case 8:
                acesso=NULL;
                delete acesso;
            break;

            default:
                cout<<"\nA opção não se encontra no menu\n";
            break;

        }
    }while (opc!=8);

}
Contatos * TestaOrdenado::criaContato(){
    Contatos *aux=new Contatos ;
    No * no = new No;
    string nome,email;
    string tel;
    cin.ignore();
    cout<<"\ninsira o nome do contato: ";
    getline(cin,nome);
    cout<<"\ninsira o telefone do contato: ";
    cin>>tel;
    cout<<"\ninsira o email do contato, caso não tenha email insira 0: ";
    cin>>email;
    if(email=="0") email="sem email";
    aux->setNome(nome);
    aux->setTel(tel);
    aux->setEmail(email);

    no->setDados(aux);
    no->montarNo(aux);

    return aux;
}

void TestaOrdenado::mostraContato(Contatos *aux) const{
    cout<<"Nome\tTelefone\tEmail\n";
    cout<<aux->getNome()<<"\t"<<aux->getTel()<<"\t"<<aux->getEmail()<<'\n';
}
