#include "evento.h"
#include "windows.h"
#include <fstream>
#include <cstdlib>

std::string Evento::getNomeEvento() const
{
    return nomeEvento;
}

void Evento::setNomeEvento(const std::string &value)
{
    nomeEvento = value;
}

std::string Evento::getDataEvento() const
{
    return dataEvento;
}

void Evento::setDataEvento(const std::string &value)
{
    dataEvento = value;
}

std::string Evento::getConvidados() const
{
    return convidados;
}

void Evento::setConvidados(const std::string &value)
{
    convidados = value;
}

int Evento::getQuantidadeConvidados() const
{
    return quantidadeConvidados;
}

void Evento::setQuantidadeConvidados(int value)
{
    quantidadeConvidados = value;
}

Evento Evento::setDadosEvento()
{
    std::string nomeEvento;
    std::string dataEvento;
    std::string nomeConvidados;
    std::string nomeConvidadoFinalizado;
    int totalConvidados;

    Evento evento;

    std::fstream arquivoEvento;
    std::string linha;

    do{
        arquivoEvento.open("D:/Projetos/Qt/Repositorio Git/Prova-M3/arquivos_txt/nomesEventos.txt", std::ios::in);
        if(arquivoEvento.is_open()){
            std::cout << "Insira o nome do evento: ";
            std::cin >> nomeEvento;
            while(getline(arquivoEvento, linha)){
                if (linha == nomeEvento){
                    std::cout << "Nome de evento ja existente, por favor insira outro!" << std::endl;
                    break;
                }
            }
        }else{
            arquivoEvento.open("D:/Projetos/Qt/Repositorio Git/Prova-M3/arquivos_txt/nomesEventos.txt", std::ios::out | std::ios::app);
            arquivoEvento.close();
        }

     } while((!arquivoEvento.is_open()) or (linha == nomeEvento));
    arquivoEvento.close();

    std::cout << "Insira a data do evento: ";
    std::cin >> dataEvento;
    std::cout << "Insira o total de convidados do evento: ";
    std::cin >> totalConvidados;

    for (int i = 0; i < totalConvidados; i++){
        std::cout << "Insira o nome do " << i+1 << " convidado do evento: ";
        std::cin >> nomeConvidados;
        nomeConvidadoFinalizado.append(nomeConvidados);
        if(i+1 != totalConvidados){
            nomeConvidadoFinalizado.append("\n");
        }
        else{
        }
    }
    std::cout << nomeConvidadoFinalizado;

    evento.setNomeEvento(nomeEvento);
    evento.setDataEvento(dataEvento);
    evento.setConvidados(nomeConvidadoFinalizado);
    evento.setQuantidadeConvidados(totalConvidados);
    return evento;
}




Evento::Evento()
{

}
