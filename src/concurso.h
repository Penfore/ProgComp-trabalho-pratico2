#pragma once

struct horario // OK
{
	short hora;
	short minuto;
};

// Salva o grau de dificuldade das quest�es, o tempo de in�cio e o tempo em que foi finalizada; // OK
struct questao
{
	short grau_dificuldade;
	horario tempo_inicio;
	horario tempo_fim;
};

// Calcula m�dias de grau de dificuldade e de tempo; // OK
struct medias
{
	float media_grau_dificuldade;
	float media_tempo;
};

// Guarda o nome do participante e um ponteiro para guardar mem�ria alocada dinamicamente relacionado �s quest�es que o participante ir� responder; // OK
struct participante
{
	char nome[20];
	questao* ptr_questoes;
};

void resumo_participante(questao*, short); // OK

medias calculos_media(questao*, short, short, short); // OK

void gerador_tra�os(char, short); // OK

void cin_horario(horario);

void cout_horario(horario); // OK

int menos_horario(horario, horario);