#include "concurso.h"
#include <iostream>

using namespace std;

// Exibe o resumo de um partipante; // OK
void resumo_participante(questao* vetor_questões, short quantidade_questões)
{
	for (int i = 0; i < quantidade_questões; i++)
	{
		char caractere_questão = 'A' + i;
		cout << "	";
		cout << caractere_questão << "(" << vetor_questões[i].grau_dificuldade << ") ";
		cout_horario(vetor_questões[i].tempo_inicio);
		cout << " às "; 
		cout_horario(vetor_questões[i].tempo_fim);
		cout << " (" << menos_horario(vetor_questões[i].tempo_fim, vetor_questões[i].tempo_inicio) << " min)\n";
	}
}

// Função que calcula e retorna a média de dificuldade e de tempo de cada questão; // OK
medias calculos_media(questao* vetor_dinamico_questao, short tamanho_vetor, short indice_inicial, short tamanho_passo_prox_indice)
{
	medias retorno;
	retorno.media_grau_dificuldade = 0; retorno.media_tempo = 0;

	float contador = 0;
	for (contador; indice_inicial < tamanho_vetor; indice_inicial += tamanho_passo_prox_indice, contador += 1)
	{
		retorno.media_grau_dificuldade += vetor_dinamico_questao[indice_inicial].grau_dificuldade;

		retorno.media_tempo += menos_horario(vetor_dinamico_questao[indice_inicial].tempo_fim, vetor_dinamico_questao[indice_inicial].tempo_inicio);
	}

	retorno.media_grau_dificuldade = retorno.media_grau_dificuldade / contador;
	retorno.media_tempo = retorno.media_tempo / contador;

	return retorno;
}

// Recebe um caractere e o tamanho que a linha terá. Retorna uma linha do tamanho recebido preenchida com o caractere recebido; // OK
void gerador_traços(char ch, short tamanho_linha)
{
	for (int i = 0; i < tamanho_linha; i++)
	{
		cout << ch;
	}
}

// Função para ler variáveis do tipo horario; // OK
void cin_horario(horario horario_lido)
{
	cin >> horario_lido.hora; cin.get(); cin >> horario_lido.minuto;
}

// Função para imprimir variáveis do tipo horário; // OK
void cout_horario(horario horario_impresso)
{
	cout << horario_impresso.hora << ":" << horario_impresso.minuto;
}

// Função para realizar operação de subtração de variáveis do tipo horário e retornar a diferença em minutos;
int menos_horario(horario horario_fim, horario horario_inicio)
{
	int diferença_hora = horario_fim.hora - horario_inicio.hora;
	diferença_hora = diferença_hora * 60;

	int diferença_minuto = horario_fim.minuto - horario_inicio.minuto;

	return diferença_hora + diferença_minuto;
}