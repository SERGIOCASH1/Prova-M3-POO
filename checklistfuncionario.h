#ifndef CHECKLISTFUNCIONARIO_H
#define CHECKLISTFUNCIONARIO_H
#include "funcionario.h"

class CheckListFuncionario:public Funcionario
{
public:
    CheckListFuncionario();

    void adcFuncionario(Funcionario funcionario);
    void pesquisarFuncionario(std::string nome);
    void editarFuncionario(std::string nome);
    void removerFuncionario(std::string nome);
    void listarFuncionario();
};

#endif // CHECKLISTFUNCIONARIO_H
