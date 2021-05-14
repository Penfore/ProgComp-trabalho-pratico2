#include "concurso.h"
#include <iostream>

using namespace std;

// Exibe o resumo de um partipante; // OK
void resumo_participante(questao* vetor_quest�es, short quantidade_quest�es)
{
	for (int i = 0; i < quantidade_quest�es; i++)
	{
		char caractere_quest�o = 'A' + i;
		cout << "	";
		cout << caractere_quest�o << "(" << vetor_quest�es[i].grau_dificuldade << ") ";
		cout_horario(vetor_quest�es[i].tempo_inicio);
		cout << " �s "; 
		cout_horario(vetor_quest�es[i].tempo_fim);
		cout << " (" << menos_horario(vetor_quest�es[i].tempo_fim, vetor_quest�es[i].tempo_inicio) << " min)\n";
	}
}

// Fun��o que calcula e retorna a m�dia de dificuldade e de tempo de cada quest�o; // OK
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

// Recebe um caractere e o tamanho que a linha ter�. Retorna uma linha do tamanho recebido preenchida com o caractere recebido; // OK
void gerador_tra�os(char ch, short tamanho_linha)
{
	for (int i = 0; i < tamanho_linha; i++)
	{
		cout << ch;
	}
}

// Fun��o para ler vari�veis do tipo horario; // OK
void cin_horario(horario horario_lido)
{
	cin >> horario_lido.hora; cin.get(); cin >> horario_lido.minuto;
}

// Fun��o para imprimir vari�veis do tipo hor�rio; // OK
void cout_horario(horario horario_impresso)
{
	cout << horario_impresso.hora << ":" << horario_impresso.minuto;
}

// Fun��o para realizar opera��o de subtra��o de vari�veis do tipo hor�rio e retornar a diferen�a em minutos;
int menos_horario(horario horario_fim, horario horario_inicio)
{
	int diferen�a_hora = horario_fim.hora - horario_inicio.hora;
	diferen�a_hora = diferen�a_hora * 60;

	int diferen�a_minuto = horario_fim.minuto - horario_inicio.minuto;

	return diferen�a_hora + diferen�a_minuto;
}