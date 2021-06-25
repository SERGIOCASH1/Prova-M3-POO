#ifndef EVENTO_H
#define EVENTO_H
#include <iostream>

class Evento
{
private:
    std::string nomeEvento;
    std::string dataEvento;
    std::string convidados;
    int quantidadeConvidados;

public:
    Evento();

    std::string getNomeEvento() const;
    void setNomeEvento(const std::string &value);
    std::string getDataEvento() const;
    void setDataEvento(const std::string &value);
    std::string getConvidados() const;
    void setConvidados(const std::string &value);
    int getQuantidadeConvidados() const;
    void setQuantidadeConvidados(int value);

    static Evento setDadosEvento();

};

#endif // EVENTO_H
