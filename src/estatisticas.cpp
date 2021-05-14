#include <iostream>
#include <Windows.h>
#include "concurso.h"

using namespace std;

int main()
{
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);

	// Tela de recebimento das entradas de quantida de participantes e questões;
	gerador_traços('*', 53);
	cout << "\nConcurso de Programação\n";

	cout << "\nQual o número de participantes? ";
	short quantidade_participantes;
	cin >> quantidade_participantes;

	cout << "Qual o número de questões? ";
	short quantidade_questões;
	cin >> quantidade_questões;

	cout << '\n';
	gerador_traços('*', 53);
	cout << '\n';
	//
	
	// Tela com loop para entrada de dados dos participantes e das questões;
	participante* participantes = new participante[quantidade_participantes];
	questao* ptr_questões = new questao[quantidade_questões * quantidade_participantes];

	for (int i = 0; i < quantidade_participantes; i++)
	{
		participantes[i].ptr_questoes = &ptr_questões[i * quantidade_questões];

		gerador_traços('-', 13);
		cout << "\nParticipante: ";
		cin >> participantes[i].nome;
		gerador_traços('-', 13);


		for (int j = 0; j < quantidade_questões; j++)
		{
			char caractere_questão = 'A' + j;

			cout << "\nQuestão " << caractere_questão << '\n';
			cout << "	Dificuldade: ";
			cin >> participantes[i].ptr_questoes[j].grau_dificuldade;
			cout << "	Início: ";
			cin >> participantes[i].ptr_questoes[j].tempo_inicio.hora; cin.ignore();
			cin >> participantes[i].ptr_questoes[j].tempo_inicio.minuto;
			cout << "	Fim: ";
			cin >> participantes[i].ptr_questoes[j].tempo_fim.hora; cin.ignore(); 
			cin >> participantes[i].ptr_questoes[j].tempo_fim.minuto;
		}
		gerador_traços('-', 13); cout << "\n\n";
	}

	system("pause");
	system("cls");
	//

	// Tela apresentando o resumo dos participantes;
	gerador_traços('*', 53); cout << '\n';

	gerador_traços('-', 23); cout << '\n';
	cout << "Resumo por Participante\n";
	gerador_traços('-', 23); cout << '\n';

	for (int i = 0; i < quantidade_participantes; i++)
	{
		cout << participantes[i].nome << ":\n";

		resumo_participante(participantes[i].ptr_questoes, quantidade_questões);

		gerador_traços('-', 18); cout << '\n';
	}
	//

	// Tela apresentando o resumo das questões;
	cout << '\n';
	gerador_traços('-', 18);
	cout << "\nResumo por Questão\n";
	gerador_traços('-', 18); cout << '\n';

	for (int j = 0; j < quantidade_questões; j++)
	{
		char caractere_questão = 'A' + j;

		cout << "Questão " << caractere_questão << '\n';
		
		for (int i = 0; i < quantidade_participantes; i++)
		{
			cout << "	" << participantes[i].nome << " (" << participantes[i].ptr_questoes[j].grau_dificuldade
				<< ") ";
			cout_horario(participantes[i].ptr_questoes[j].tempo_inicio);
			cout << " às ";
			cout_horario(participantes[i].ptr_questoes[j].tempo_fim);
			cout << " (" << menos_horario(participantes[i].ptr_questoes[j].tempo_fim, participantes[i].ptr_questoes[j].tempo_inicio) << " min)\n";
		}
	}
	gerador_traços('-', 18); cout << '\n';
	//

	// Tela de estatísticas
	cout << '\n';
	gerador_traços('-', 12); cout << '\n';
	cout << "Estatísticas\n";
	gerador_traços('-', 12); cout << '\n';

	short tamanho_vetor = quantidade_questões * quantidade_participantes;
	for (int j = 0; j < quantidade_questões; j++) // Exibindo estatísticas individuais da cada questão;
	{
		char caractere_questão = 'A' + j;

		medias medias_estatisticas = calculos_media(ptr_questões, tamanho_vetor, j, quantidade_questões); // Para não ter que chamar a função mais vezes
		cout << "Questão " << caractere_questão << ": Dificuldade ("
			<< medias_estatisticas.media_grau_dificuldade << ") - Tempo ("
			<< medias_estatisticas.media_tempo << " minutos)\n";
	}

	medias medias_finais = calculos_media(ptr_questões, tamanho_vetor, 0, 1);

	cout << "Concurso: Dificuldade (" << medias_finais.media_grau_dificuldade << ") - Tempo (" // Exibindo estatísticas finais gerais;
		<< medias_finais.media_tempo << " minutos)\n";
	gerador_traços('*', 53); cout << '\n';
	//

	delete[] participantes; delete[] ptr_questões;

	return 0;
}