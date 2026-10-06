#ifndef AGENDAMENTO_H
#define AGENDAMENTO_H

typedef struct {
    char cpf[15];
    char sala[10];
    char data[11];
    char hora[6];
} Agendamento;

Agendamento criar_agendamento(char* cpf, char* sala, char* data, char* hora);

#endif
