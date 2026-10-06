#include <string.h>
#include "paciente.h"

/*
 * Funcao: criar_paciente
 * Autor: Mikael Mateus dos Santos Silva
 * Descricao: Recebe os dados de um paciente e retorna a estrutura Paciente preenchida.
 */
Paciente criar_paciente(char* nome, char* cpf, char* matricula, char* curso) {
    Paciente p;
    strcpy(p.nome, nome);
    strcpy(p.cpf, cpf);
    strcpy(p.matricula, matricula);
    strcpy(p.curso, curso);
    return p;
}
