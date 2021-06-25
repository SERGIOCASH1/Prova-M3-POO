#ifndef PESSOAFISICA_H
#define PESSOAFISICA_H
#include <iostream>


class PessoaFisica
{
private:
    std::string nome;
    std::string cpf;
    int idade;
    int codigo;
public:
    PessoaFisica();

    std::string getNome() const;
    void setNome(const std::string &value);
    std::string getCpf() const;
    void setCpf(const std::string &value);
    int getIdade() const;
    void setIdade(int value);
    int getCodigo() const;
    void setCodigo(int value);
};

#endif // PESSOAFISICA_H
