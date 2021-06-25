#include "checklistevento.h"
#include "windows.h"
#include <fstream>
#include <cstdlib>

int eventosCadastrados;

CheckListEvento::CheckListEvento()
{

}


void CheckListEvento::adcEvento(Evento evento)
{

    std::fstream arquivoEvento;
    std::string linha, local = "D:/Projetos/Qt/Repositorio Git/Prova-M3/arquivos_txt/";

    arquivoEvento.open(local+"nomesEventos.txt", std::ios::out | std::ios::app);
    if(arquivoEvento.is_open()){
        arquivoEvento << evento.getNomeEvento() << std::endl;
        arquivoEvento.close();
    }else{
        std::cout << "Nao foi possivel abrir o arquivo" << std::endl;
    }

    arquivoEvento.open(local+evento.getNomeEvento()+"NomesConvidados.txt", std::ios::out | std::ios::app);
    if(arquivoEvento.is_open()){
        arquivoEvento << evento.getConvidados() << std::endl;
        arquivoEvento.close();
    }else{
        std::cout << "Nao foi possivel abrir o arquivo" << std::endl;
    }

    arquivoEvento.open(local+evento.getNomeEvento()+"DataEvento.txt", std::ios::out | std::ios::app);
    if(arquivoEvento.is_open()){
        arquivoEvento << evento.getDataEvento() << std::endl;
        arquivoEvento.close();
    }else{
        std::cout << "Nao foi possivel abrir o arquivo" << std::endl;
    }

    do{
        arquivoEvento.open(local+"QuantidadeEventos.txt", std::ios::in);
        if(arquivoEvento.is_open()){
            getline(arquivoEvento, linha);
            eventosCadastrados = stoi(linha);
            arquivoEvento.close();

            arquivoEvento.open(local+"QuantidadeEventos.txt", std::ios::out);
            arquivoEvento << eventosCadastrados + 1;
            break;

        }else{
            arquivoEvento.open(local+"QuantidadeEventos.txt", std::ios::out | std::ios::app);
            arquivoEvento << 0;
            arquivoEvento.close();
        }

     } while((!arquivoEvento.is_open()));
    arquivoEvento.close();

    system("CLS");
}

void CheckListEvento::pesquisarEvento(std::string nome)
{
    system("CLS");

    std::fstream arquivoEvento;
    std::string linha, local = "D:/Projetos/Qt/Repositorio Git/Prova-M3/arquivos_txt/";
    local += nome;

    arquivoEvento.open(local+="nomesConvidados.txt", std::ios::in);

    if(arquivoEvento.is_open()){
        std::cout << "Os convidados do evento " << nome << " sao: " << std::endl;
        while(getline(arquivoEvento, linha)){
        std::cout << linha << std::endl;
    }
        arquivoEvento.close();
    }else{
        std::cout << "Nao foi possivel abrir o arquivo ou nao existe um evento com este nome.\n" << std::endl;
        return;
    }

    std::string local2 = "D:/Projetos/Qt/Repositorio Git/Prova-M3/arquivos_txt/";
    local2 += nome;

    arquivoEvento.open(local2+="DataEvento.txt", std::ios::in);

    if(arquivoEvento.is_open()){
        std::cout << "A data do evento e: ";
        while(getline(arquivoEvento, linha)){
        std::cout << linha << std::endl;
    }
        arquivoEvento.close();
    }else{
        std::cout << "Nao foi possivel abrir o arquivo" << std::endl;
        return;
    }
}

void CheckListEvento::editarEvento(std::string nome)
{
    std::fstream arquivoEvento, arquivoAuxiliar;
    std::string linha, local = "D:/Projetos/Qt/Repositorio Git/Prova-M3/arquivos_txt/";

    arquivoEvento.open(local+"nomesEventos.txt", std::ios::in);
    arquivoAuxiliar.open(local+"auxiliar.txt", std::ios_base::in | std::ios_base::app);

    if(arquivoEvento.is_open() and arquivoAuxiliar.is_open()){
        while(getline(arquivoEvento, linha)){
            if (linha != nome){
                arquivoAuxiliar << linha +"\n";
            }
            else{
                std::cout << "Insira o novo nome do evento: ";
                arquivoAuxiliar << linha +"\n";
            }
        }
    arquivoEvento.close();
    DeleteFileA("D:/Projetos/Qt/Repositorio Git/Prova-M3/arquivos_txt/nomesEventos.txt");
    }else{
        std::cout << "Nao foi possivel abrir o arquivo" << std::endl;
        exit(1);
    }
    arquivoAuxiliar.close();

}

void CheckListEvento::removerEvento(std::string nome)
{
    std::fstream arquivoEvento, arquivoAuxiliar;
    std::string linha;
    std::string local2, local1, local = "D:/Projetos/Qt/Repositorio Git/Prova-M3/arquivos_txt/";

    arquivoEvento.open(local+"nomesEventos.txt", std::ios_base::in);
    arquivoAuxiliar.open(local+"auxiliar.txt", std::ios_base::in | std::ios_base::app);

    if(arquivoEvento.is_open() and arquivoAuxiliar.is_open()){
        while(getline(arquivoEvento, linha)){
            if (linha != nome){
                arquivoAuxiliar << linha +"\n";
            }
        }
    arquivoEvento.close();
    DeleteFileA("D:/Projetos/Qt/Repositorio Git/Prova-M3/arquivos_txt/nomesEventos.txt");
    }else{
        std::cout << "Nao foi possivel abrir o arquivo" << std::endl;
        exit(1);
    }
    arquivoAuxiliar.close();

    /*------------------------------------------------------------------------------------*/

    arquivoAuxiliar.open(local+"auxiliar.txt", std::ios_base::in);
    arquivoEvento.open(local+"nomesEventos.txt", std::ios::out | std::ios::app);
    if(arquivoEvento.is_open() and arquivoAuxiliar.is_open()){
        while(getline(arquivoAuxiliar, linha)){
                arquivoEvento << linha << std::endl;
            }

    arquivoEvento.close();
    arquivoAuxiliar.close();
    DeleteFileA("D:/Projetos/Qt/Repositorio Git/Prova-M3/arquivos_txt/auxiliar.txt");

    }else{
        std::cout << "Nao foi possivel abrir o arquivo" << std::endl;
        exit(1);
    }

    local+=nome;
    local1 = local + "DataEvento.txt";
    local2 = local + "NomesConvidados.txt";

    const char * local3 = local1.c_str();
    DeleteFileA(local3);
    local3 = local2.c_str();
    DeleteFileA(local3);

    local = "D:/Projetos/Qt/Repositorio Git/Prova-M3/arquivos_txt/QuantidadeEventos.txt";
    do{
        arquivoEvento.open(local, std::ios::in);
        if(arquivoEvento.is_open()){
            getline(arquivoEvento, linha);
            eventosCadastrados = stoi(linha);
            arquivoEvento.close();

            arquivoEvento.open(local, std::ios::out);
            arquivoEvento << eventosCadastrados - 1;
            break;

        }else{
            arquivoEvento.open(local, std::ios::out | std::ios::app);
            arquivoEvento << 0;
            arquivoEvento.close();
        }

     } while((!arquivoEvento.is_open()));
    arquivoEvento.close();

    system("CLS");

    std::cout << "Evento excluido com sucesso!\n";

}

void CheckListEvento::listarEventos()
{
    system("CLS");

    std::fstream arquivoEvento, arquivoAuxiliar;
    std::string nomeEvento, linha, local = "D:/Projetos/Qt/Repositorio Git/Prova-M3/arquivos_txt/";

    arquivoEvento.open(local+"nomesEventos.txt", std::ios::in);

    if(arquivoEvento.is_open()){
        while(getline(arquivoEvento, nomeEvento)){
        std::cout << "Evento: " << nomeEvento << std::endl;
        arquivoAuxiliar.open(local+nomeEvento+"DataEvento.txt");
        if(arquivoAuxiliar.is_open()){
            getline(arquivoAuxiliar, linha);
            std::cout << "Data de realizacao: " << linha << std::endl;
            arquivoAuxiliar.close();
        }else{
            std::cout << "Arquivo data não está sendo aberto";
            exit(1);
        }
        std::cout << "Os convidados sao: " << std::endl;
        arquivoAuxiliar.open(local+nomeEvento+"NomesConvidados.txt");
        if(arquivoAuxiliar.is_open()){
            int i = 1;
            while(getline(arquivoAuxiliar, linha)){
                std::cout << i << " convidado: "<< linha << std::endl;
                i++;
            }
            arquivoAuxiliar.close();
            std::cout << std::endl;
        }else{
            std::cout << "Arquivo convidados não está sendo aberto ou não existem convidados para o evento." << std::endl;
            exit(1);
        }
    }
        arquivoEvento.close();
    }else{
        std::cout << "Nao foi possivel abrir o arquivo ou nao existe um evento com este nome.\n" << std::endl;
        return;
    }

    arquivoEvento.open(local+"QuantidadeEventos.txt", std::ios::in);
    if(arquivoEvento.is_open()){
        getline(arquivoEvento, linha);
        std::cout << "Total de eventos: " << linha << "\n\n" << std::endl;
        arquivoEvento.close();
    }else{
        std::cout << "Nao foi possivel abrir o arquivo ou nao existe eventos cadastrados.\n" << std::endl;
    }

}
