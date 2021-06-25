#include "funcionario.h"

std::string Funcionario::getFuncao() const
{
    return funcao;
}

void Funcionario::setFuncao(const std::string &value)
{
    funcao = value;
}

float Funcionario::getSalario() const
{
    return salario;
}

void Funcionario::setSalario(float value)
{
    salario = value;
}

Funcionario::Funcionario()
{

}
