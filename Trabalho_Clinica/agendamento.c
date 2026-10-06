#include <string.h>
#include "agendamento.h"

/*
 * Funcao: criar_agendamento
 * Autor: Mikael Mateus dos Santos Silva
 * Descricao: Recebe os dados e retorna a estrutura Agendamento instanciada.
 */
Agendamento criar_agendamento(char* cpf, char* sala, char* data, char* hora) {
    Agendamento a;
    strcpy(a.cpf, cpf);
    strcpy(a.sala, sala);
    strcpy(a.data, data);
    strcpy(a.hora, hora);
    return a;
}
