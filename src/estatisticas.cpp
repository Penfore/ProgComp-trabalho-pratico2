#include <iostream>
#include <Windows.h>
#include "concurso.h"

using namespace std;

int main()
{
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);

	// Tela de recebimento das entradas de quantida de participantes e quest�es;
	gerador_tra�os('*', 53);
	cout << "\nConcurso de Programa��o\n";

	cout << "\nQual o n�mero de participantes? ";
	short quantidade_participantes;
	cin >> quantidade_participantes;

	cout << "Qual o n�mero de quest�es? ";
	short quantidade_quest�es;
	cin >> quantidade_quest�es;

	cout << '\n';
	gerador_tra�os('*', 53);
	cout << '\n';
	//
	
	// Tela com loop para entrada de dados dos participantes e das quest�es;
	participante* participantes = new participante[quantidade_participantes];
	questao* ptr_quest�es = new questao[quantidade_quest�es * quantidade_participantes];

	for (int i = 0; i < quantidade_participantes; i++)
	{
		participantes[i].ptr_questoes = &ptr_quest�es[i * quantidade_quest�es];

		gerador_tra�os('-', 13);
		cout << "\nParticipante: ";
		cin >> participantes[i].nome;
		gerador_tra�os('-', 13);


		for (int j = 0; j < quantidade_quest�es; j++)
		{
			char caractere_quest�o = 'A' + j;

			cout << "\nQuest�o " << caractere_quest�o << '\n';
			cout << "	Dificuldade: ";
			cin >> participantes[i].ptr_questoes[j].grau_dificuldade;
			cout << "	In�cio: ";
			cin >> participantes[i].ptr_questoes[j].tempo_inicio.hora; cin.ignore();
			cin >> participantes[i].ptr_questoes[j].tempo_inicio.minuto;
			cout << "	Fim: ";
			cin >> participantes[i].ptr_questoes[j].tempo_fim.hora; cin.ignore(); 
			cin >> participantes[i].ptr_questoes[j].tempo_fim.minuto;
		}
		gerador_tra�os('-', 13); cout << "\n\n";
	}

	system("pause");
	system("cls");
	//

	// Tela apresentando o resumo dos participantes;
	gerador_tra�os('*', 53); cout << '\n';

	gerador_tra�os('-', 23); cout << '\n';
	cout << "Resumo por Participante\n";
	gerador_tra�os('-', 23); cout << '\n';

	for (int i = 0; i < quantidade_participantes; i++)
	{
		cout << participantes[i].nome << ":\n";

		resumo_participante(participantes[i].ptr_questoes, quantidade_quest�es);

		gerador_tra�os('-', 18); cout << '\n';
	}
	//

	// Tela apresentando o resumo das quest�es;
	cout << '\n';
	gerador_tra�os('-', 18);
	cout << "\nResumo por Quest�o\n";
	gerador_tra�os('-', 18); cout << '\n';

	for (int j = 0; j < quantidade_quest�es; j++)
	{
		char caractere_quest�o = 'A' + j;

		cout << "Quest�o " << caractere_quest�o << '\n';
		
		for (int i = 0; i < quantidade_participantes; i++)
		{
			cout << "	" << participantes[i].nome << " (" << participantes[i].ptr_questoes[j].grau_dificuldade
				<< ") ";
			cout_horario(participantes[i].ptr_questoes[j].tempo_inicio);
			cout << " �s ";
			cout_horario(participantes[i].ptr_questoes[j].tempo_fim);
			cout << " (" << menos_horario(participantes[i].ptr_questoes[j].tempo_fim, participantes[i].ptr_questoes[j].tempo_inicio) << " min)\n";
		}
	}
	gerador_tra�os('-', 18); cout << '\n';
	//

	// Tela de estat�sticas
	cout << '\n';
	gerador_tra�os('-', 12); cout << '\n';
	cout << "Estat�sticas\n";
	gerador_tra�os('-', 12); cout << '\n';

	short tamanho_vetor = quantidade_quest�es * quantidade_participantes;
	for (int j = 0; j < quantidade_quest�es; j++) // Exibindo estat�sticas individuais da cada quest�o;
	{
		char caractere_quest�o = 'A' + j;

		medias medias_estatisticas = calculos_media(ptr_quest�es, tamanho_vetor, j, quantidade_quest�es); // Para n�o ter que chamar a fun��o mais vezes
		cout << "Quest�o " << caractere_quest�o << ": Dificuldade ("
			<< medias_estatisticas.media_grau_dificuldade << ") - Tempo ("
			<< medias_estatisticas.media_tempo << " minutos)\n";
	}

	medias medias_finais = calculos_media(ptr_quest�es, tamanho_vetor, 0, 1);

	cout << "Concurso: Dificuldade (" << medias_finais.media_grau_dificuldade << ") - Tempo (" // Exibindo estat�sticas finais gerais;
		<< medias_finais.media_tempo << " minutos)\n";
	gerador_tra�os('*', 53); cout << '\n';
	//

	delete[] participantes; delete[] ptr_quest�es;

	return 0;
}