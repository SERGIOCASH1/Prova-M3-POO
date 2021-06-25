#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include "pessoafisica.h"

class Funcionario: public PessoaFisica
{
private:
    std::string funcao;
    float salario;
public:
    Funcionario();

    std::string getFuncao() const;
    void setFuncao(const std::string &value);
    float getSalario() const;
    void setSalario(float value);
};

#endif // FUNCIONARIO_H
