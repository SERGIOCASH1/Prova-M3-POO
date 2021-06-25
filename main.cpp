#include <QCoreApplication>
#include "checklistevento.h"
#include "checklistfuncionario.h"
#include "checklistconvidados.h"
int opcao;

void opcaoConvidados(CheckListConvidados CLC){
    while(true){
        std::cout << "Adicionar Convidado         (0)" << std::endl;
        std::cout << "Remover   Convidado         (1)" << std::endl;
        std::cout << "Listar    Convidados        (2)" << std::endl;
        std::cout << "Voltar                     (any)" << std::endl;

        std::cin >> opcao;

        if(opcao == 0){
            CLC.adicionarConvidado();
        }
        else if(opcao == 1){
            CLC.removerConvidado();
        }
        else if(opcao == 2){
            CLC.listarConvidado();
        }
        else{
            system("CLS");
            break;
        }
    }
}
void opcaoEvento(CheckListEvento CLE){
    while(true){
        std::cout << "Cadastrar Evento        (1)" << std::endl;
        std::cout << "Pesquisar Evento        (2)" << std::endl;
        std::cout << "Remover   Evento        (3)" << std::endl;
        std::cout << "Listar    Eventos       (4)" << std::endl;
        std::cout << "Editar    Evento        (5)" << std::endl;
        std::cout << "Voltar                (any)" << std::endl;

        std::cin >> opcao;

        if(opcao == 1){
            CLE.adcEvento(Evento::setDadosEvento());
        }
        else if(opcao == 2){
            std::string nome;
            std::cout << "Insira o nome do evento para pesquisa: ";
            std::cin >> nome;
            CLE.pesquisarEvento(nome);
        }
        else if(opcao == 3){
            std::string nome;
            std::cout << "Insira o nome do evento para remocao: ";
            std::cin >> nome;
            CLE.removerEvento(nome);
        }
        else if(opcao == 4){
            CLE.listarEventos();
        }
        else if(opcao == 5){
            //editarEquipe(CLE);
        }
        else{
            system("CLS");
            break;
        }
    }
}
void opcaoFuncionario(CheckListFuncionario CLF){
    while(true){
        std::cout << "Cadastrar Funcionario        (0)" << std::endl;
        std::cout << "Pesquisar Funcionario        (1)" << std::endl;
        std::cout << "Remover   Funcionario        (2)" << std::endl;
        std::cout << "Listar    Funcionario        (3)" << std::endl;
        std::cout << "Editar    Funcionario        (4)" << std::endl;
        std::cout << "Voltar                     (any)" << std::endl;

        std::cin >> opcao;

        if(opcao == 0){
            //setDadosEquipe(CLE);
        }
        else if(opcao == 1){
            //pesquisarEquipe(CLE);
        }
        else if(opcao == 2){
            //removerDadosEquipe(CLE);
        }
        else if(opcao == 3){
            //listarEquipe(CLE);
        }
        else if(opcao == 4){
            //editarEquipe(CLE);
        }
        else{
            system("CLS");
            break;
        }
    }
}

void principaisOpcoes(CheckListEvento CLE, CheckListFuncionario CLF, CheckListConvidados CLC){
    while (true){
        std::cout << "Selecione uma das opcoes:        " << std::endl;
        std::cout << "Evento                        (1)" << std::endl;
        std::cout << "Funcionarios                  (2)" << std::endl;
        std::cout << "Convidados                    (3)" << std::endl;
        std::cout << "Sair                        (any)" << std::endl;

        std::cin >> opcao;

        if(opcao == 1){
            opcaoEvento(CLE);
        }
        else if(opcao == 2){
            opcaoFuncionario(CLF);
        }
        else if(opcao == 3){
            opcaoConvidados(CLC);

        }
        else{
           system("CLS");
           exit(1);
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CheckListEvento CLE;
    CheckListConvidados CLC;
    CheckListFuncionario CLF;


    principaisOpcoes(CLE, CLF, CLC);

    return a.exec();
}
