#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

/*
 * Funcao: inicializar_pacientes
 * Autor: Mikael Mateus dos Santos Silva
 * Descricao: Inicia a lista de pacientes apontando para NULL.
 */
NoPaciente* inicializar_pacientes() {
    return NULL;
}

/*
 * Funcao: inserir_paciente
 * Autor: Mikael Mateus dos Santos Silva
 * Descricao: Insere um novo paciente no inicio da lista linear simples.
 */
NoPaciente* inserir_paciente(NoPaciente* lista, Paciente p) {
    NoPaciente* novo = (NoPaciente*)malloc(sizeof(NoPaciente));
    novo->paciente = p;
    novo->prox = lista;
    return novo;
}

/*
 * Funcao: inicializar_agendamentos
 * Autor: Mikael Mateus dos Santos Silva
 * Descricao: Aloca a lista e cria o NO CABECALHO (exigencia do trabalho).
 */
ListaAgendamentos* inicializar_agendamentos() {
    ListaAgendamentos* lista = (ListaAgendamentos*)malloc(sizeof(ListaAgendamentos));
    lista->cabecalho = (NoAgendamento*)malloc(sizeof(NoAgendamento));
    lista->cabecalho->prox = NULL;
    return lista;
}

/*
 * Funcao: inserir_agendamento
 * Autor: Mikael Mateus dos Santos Silva
 * Descricao: Insere um agendamento no final da lista com cabecalho.
 */
void inserir_agendamento(ListaAgendamentos* lista, Agendamento a) {
    NoAgendamento* novo = (NoAgendamento*)malloc(sizeof(NoAgendamento));
    novo->agendamento = a;
    novo->prox = NULL;
    
    NoAgendamento* aux = lista->cabecalho;
    while(aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = novo;
}

/*
 * Funcao: listar_por_cpf
 * Autor: Mikael Mateus dos Santos Silva
 * Descricao: Busca agendamentos que coincidam com o CPF.
 */
void listar_por_cpf(ListaAgendamentos* lista, char* cpf) {
    NoAgendamento* aux = lista->cabecalho->prox;
    int achou = 0;
    printf("\n--- Agendamentos do CPF %s ---\n", cpf);
    while(aux != NULL) {
        if(strcmp(aux->agendamento.cpf, cpf) == 0) {
            printf("Sala: %s | Data: %s | Hora: %s\n", aux->agendamento.sala, aux->agendamento.data, aux->agendamento.hora);
            achou = 1;
        }
        aux = aux->prox;
    }
    if(!achou) printf("Nenhum agendamento encontrado para este CPF.\n");
}

/*
 * Funcao: listar_por_sala
 * Autor: Mikael Mateus dos Santos Silva
 * Descricao: Busca todos os agendamentos registrados em uma sala especifica.
 */
void listar_por_sala(ListaAgendamentos* lista, char* sala) {
    NoAgendamento* aux = lista->cabecalho->prox;
    int achou = 0;
    printf("\n--- Agendamentos na Sala %s ---\n", sala);
    while(aux != NULL) {
        if(strcmp(aux->agendamento.sala, sala) == 0) {
            printf("CPF: %s | Data: %s | Hora: %s\n", aux->agendamento.cpf, aux->agendamento.data, aux->agendamento.hora);
            achou = 1;
        }
        aux = aux->prox;
    }
    if(!achou) printf("Nenhum agendamento encontrado para esta Sala.\n");
}

/*
 * Funcao: remover_agendamento
 * Autor: Mikael Mateus dos Santos Silva
 * Descricao: Remove da lista com cabecalho um agendamento baseado no CPF e na Data.
 */
void remover_agendamento(ListaAgendamentos* lista, char* cpf, char* data) {
    NoAgendamento* ant = lista->cabecalho;
    NoAgendamento* aux = ant->prox;
    
    while(aux != NULL) {
        if(strcmp(aux->agendamento.cpf, cpf) == 0 && strcmp(aux->agendamento.data, data) == 0) {
            ant->prox = aux->prox;
            free(aux);
            printf("Agendamento removido com sucesso.\n");
            return;
        }
        ant = aux;
        aux = aux->prox;
    }
    printf("Erro: Agendamento com este CPF e Data nao encontrado.\n");
}

/*
 * Funcao: apresentar_historico
 * Autor: Mikael Mateus dos Santos Silva
 * Descricao: Imprime todo o historico de agendamentos a partir do cabecalho.
 */
void apresentar_historico(ListaAgendamentos* lista) {
    NoAgendamento* aux = lista->cabecalho->prox;
    if(aux == NULL) {
        printf("\nNenhum agendamento registrado.\n");
        return;
    }
    printf("\n=== Historico Completo de Agendamentos ===\n");
    while(aux != NULL) {
        printf("CPF: %s | Sala: %s | Data: %s | Hora: %s\n", 
            aux->agendamento.cpf, aux->agendamento.sala, aux->agendamento.data, aux->agendamento.hora);
        aux = aux->prox;
    }
}
