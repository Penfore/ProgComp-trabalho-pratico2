#pragma once

struct horario // OK
{
	short hora;
	short minuto;
};

// Salva o grau de dificuldade das questões, o tempo de início e o tempo em que foi finalizada; // OK
struct questao
{
	short grau_dificuldade;
	horario tempo_inicio;
	horario tempo_fim;
};

// Calcula médias de grau de dificuldade e de tempo; // OK
struct medias
{
	float media_grau_dificuldade;
	float media_tempo;
};

// Guarda o nome do participante e um ponteiro para guardar memória alocada dinamicamente relacionado às questões que o participante irá responder; // OK
struct participante
{
	char nome[20];
	questao* ptr_questoes;
};

void resumo_participante(questao*, short); // OK

medias calculos_media(questao*, short, short, short); // OK

void gerador_traços(char, short); // OK

void cin_horario(horario);

void cout_horario(horario); // OK

int menos_horario(horario, horario);