#include "checklistconvidados.h"
#include "windows.h"
#include <fstream>
#include <cstdlib>

CheckListConvidados::CheckListConvidados()
{

}

void CheckListConvidados::adicionarConvidado()
{
    system("CLS");

    std::fstream arquivoAuxiliar;
    std::string linha, nomeEvento, nomeConvidado, local = "D:/Projetos/Qt/Repositorio Git/Prova-M3/arquivos_txt/";

    std::string nome;
    std::cout << "Insira o nome do evento para adicionar o convidado: ";
    std::cin >> nomeEvento;

    arquivoAuxiliar.open(local+nomeEvento+"NomesConvidados.txt", std::ios::out | std::ios::app);
    if(arquivoAuxiliar.is_open()){
        std::cout << "Insira o nome do convidado: ";
        std::cin >> nomeConvidado;

        arquivoAuxiliar << nomeConvidado << std::endl;
        arquivoAuxiliar.close();
    }else{
        std::cout << "Nao foi possivel abrir o arquivo" << std::endl;
        exit(1);
    }

    system("CLS");
    std::cout << "Convidado inserido com sucesso!" << std::endl;
}

void CheckListConvidados::removerConvidado()
{
    system("CLS");

    std::fstream arquivoEvento, arquivoAuxiliar;
    std::string linha, nomeEvento, nomeConvidado, local = "D:/Projetos/Qt/Repositorio Git/Prova-M3/arquivos_txt/";

    std::cout << "Insira o nome do evento para remover o convidado: ";
    std::cin >> nomeEvento;
    system("CLS");
    std::cout << "Insira o nome do convidado que deseja remover: ";
    std::cin >> nomeConvidado;

    arquivoEvento.open(local+nomeEvento+"NomesConvidados.txt", std::ios_base::in);
    arquivoAuxiliar.open(local+"auxiliar.txt", std::ios_base::in | std::ios_base::app);

    if(arquivoEvento.is_open() and arquivoAuxiliar.is_open()){
        while(getline(arquivoEvento, linha)){
            if (linha != nomeConvidado){
                arquivoAuxiliar << linha +"\n";
            }
        }
    arquivoEvento.close();
    }else{
        std::cout << "Nao foi possivel abrir o arquivo ou não existe evento com este nome!" << std::endl;
        return;
    }
    arquivoAuxiliar.close();
    std::string local2 = local+nomeEvento+"NomesConvidados.txt";
    const char * local3 = local2.c_str();
    DeleteFileA(local3);

    /*------------------------------------------------------------------------------------*/

    arquivoAuxiliar.open(local+"auxiliar.txt", std::ios_base::in);
    arquivoEvento.open(local+nomeEvento+"NomesConvidados.txt", std::ios::out | std::ios::app);
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






}

void CheckListConvidados::listarConvidado()
{
    system("CLS");

    std::ifstream arquivoAuxiliar;
    std::string linha, nomeEvento, local = "D:/Projetos/Qt/Repositorio Git/Prova-M3/arquivos_txt/";

    std::string nome;
    std::cout << "Insira o nome do evento para listar os convidados: ";
    std::cin >> nomeEvento;

    arquivoAuxiliar.open(local+nomeEvento+"NomesConvidados.txt");
    if(arquivoAuxiliar.is_open()){
        std::cout << "Os convidados do evento " << nomeEvento << " sao: " << std::endl;
        int i = 1;
        while(getline(arquivoAuxiliar, linha)){
            std::cout << i << " convidado: "<< linha << std::endl;
            i++;
        }
        arquivoAuxiliar.close();
        std::cout << std::endl;
    }else{
        std::cout << "Nao foi possivel abrir o arquivo ou nao existe um evento com este nome.\n" << std::endl;
        return;
    }
}
