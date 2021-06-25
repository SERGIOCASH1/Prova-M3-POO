#include "pessoafisica.h"

std::string PessoaFisica::getNome() const
{
    return nome;
}

void PessoaFisica::setNome(const std::string &value)
{
    nome = value;
}

std::string PessoaFisica::getCpf() const
{
    return cpf;
}

void PessoaFisica::setCpf(const std::string &value)
{
    cpf = value;
}

int PessoaFisica::getIdade() const
{
    return idade;
}

void PessoaFisica::setIdade(int value)
{
    idade = value;
}

int PessoaFisica::getCodigo() const
{
    return codigo;
}

void PessoaFisica::setCodigo(int value)
{
    codigo = value;
}

PessoaFisica::PessoaFisica()
{

}
