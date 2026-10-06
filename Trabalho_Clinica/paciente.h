#ifndef PACIENTE_H
#define PACIENTE_H

typedef struct {
    char nome[50];
    char cpf[15];
    char matricula[20];
    char curso[50];
} Paciente;

Paciente criar_paciente(char* nome, char* cpf, char* matricula, char* curso);

#endif
