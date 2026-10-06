#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/*
 * Funcao: main
 * Autor: Mikael Mateus dos Santos Silva
 * Descricao: Menu interativo principal integrando todas as funcionalidades minimas obrigatorias.
 */
int main() {
    NoPaciente* pacientes = inicializar_pacientes();
    ListaAgendamentos* agendamentos = inicializar_agendamentos();
    int opcao;
    
    do {
        printf("\n=== SISTEMA DA CLINICA UNIVERSITARIA ===\n");
        printf("1. Cadastrar paciente\n");
        printf("2. Cadastrar agendamento\n");
        printf("3. Listar agendamentos por CPF\n");
        printf("4. Listar agendamentos por sala\n");
        printf("5. Remover agendamento (por CPF + data)\n");
        printf("6. Apresentar historico completo\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        if(opcao == 1) {
            char n[50], cpf[15], mat[20], c[50];
            printf("Nome: "); scanf(" %[^\n]", n);
            printf("CPF: "); scanf(" %s", cpf);
            printf("Matricula: "); scanf(" %s", mat);
            printf("Curso: "); scanf(" %[^\n]", c);
            pacientes = inserir_paciente(pacientes, criar_paciente(n, cpf, mat, c));
            printf("Paciente cadastrado!\n");
        } 
        else if(opcao == 2) {
            char cpf[15], s[10], d[11], h[6];
            printf("CPF do Paciente: "); scanf(" %s", cpf);
            printf("Sala: "); scanf(" %s", s);
            printf("Data (DD/MM/AAAA): "); scanf(" %s", d);
            printf("Hora (HH:MM): "); scanf(" %s", h);
            inserir_agendamento(agendamentos, criar_agendamento(cpf, s, d, h));
            printf("Agendamento cadastrado!\n");
        }
        else if(opcao == 3) {
            char cpf[15];
            printf("Digite o CPF para busca: "); scanf(" %s", cpf);
            listar_por_cpf(agendamentos, cpf);
        }
        else if(opcao == 4) {
            char s[10];
            printf("Digite a Sala para busca: "); scanf(" %s", s);
            listar_por_sala(agendamentos, s);
        }
        else if(opcao == 5) {
            char cpf[15], d[11];
            printf("CPF do Agendamento: "); scanf(" %s", cpf);
            printf("Data (DD/MM/AAAA): "); scanf(" %s", d);
            remover_agendamento(agendamentos, cpf, d);
        }
        else if(opcao == 6) {
            apresentar_historico(agendamentos);
        }
        
    } while(opcao != 0);

    return 0;
}
