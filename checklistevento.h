#ifndef CHECKLISTEVENTO_H
#define CHECKLISTEVENTO_H
#include "evento.h"

class CheckListEvento: public Evento
{
public:
    CheckListEvento();

    void adcEvento(Evento evento);
    void pesquisarEvento(std::string nome);
    void editarEvento(std::string nome);
    void removerEvento(std::string nome);
    void listarEventos();

};

#endif // CHECKLISTEVENTO_H
