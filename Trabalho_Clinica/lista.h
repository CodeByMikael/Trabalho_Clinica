#ifndef LISTA_H
#define LISTA_H

#include "paciente.h"
#include "agendamento.h"

/* Lista Simplesmente Encadeada para Pacientes */
typedef struct NoPaciente {
    Paciente paciente;
    struct NoPaciente* prox;
} NoPaciente;

/* Lista com Cabecalho (Header Node) para Agendamentos */
typedef struct NoAgendamento {
    Agendamento agendamento;
    struct NoAgendamento* prox;
} NoAgendamento;

typedef struct {
    NoAgendamento* cabecalho;
} ListaAgendamentos;

NoPaciente* inicializar_pacientes();
NoPaciente* inserir_paciente(NoPaciente* lista, Paciente p);

ListaAgendamentos* inicializar_agendamentos();
void inserir_agendamento(ListaAgendamentos* lista, Agendamento a);
void listar_por_cpf(ListaAgendamentos* lista, char* cpf);
void listar_por_sala(ListaAgendamentos* lista, char* sala);
void remover_agendamento(ListaAgendamentos* lista, char* cpf, char* data);
void apresentar_historico(ListaAgendamentos* lista);

#endif
