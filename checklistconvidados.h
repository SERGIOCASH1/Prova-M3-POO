#ifndef CHECKLISTCONVIDADOS_H
#define CHECKLISTCONVIDADOS_H
#include "convidados.h"

class CheckListConvidados: public Convidados
{
public:
    CheckListConvidados();

    static void adicionarConvidado();
    static void removerConvidado();
    static void listarConvidado();

};

#endif // CHECKLISTCONVIDADOS_H
