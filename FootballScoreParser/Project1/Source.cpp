#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

#include "team.h"
#include "list.h"
#include "Match.h"
using namespace std;
#define SIZE 1000

// "змейка" змейка_нотация
// "верблюжья нотация" верблюжьяНотация

// Стараемся не писать комментарии к коду, а организовать код таким образом, чтобы он сам себя комментировал (чаще всего достаточно тщательно подобрать названия)
// Переменные - существительные
// Функции - глаголы
// Если переменная типа данных bool, или функция возращает bool, то название - это вопрос. обычно начинается с is..., has..., can... и тд
// Функция должна в идеале выполнять лишь одно действие.
// В идеале функция должна принимать небольшое количество аргументов. Скорее всего, если аргументов много - функция выполнят множество задач
// Функция должна состоять из малого количетсва строк. Если функция состоит из множества строк - скорее всего выполняет много действий.
// Если в коде встречается цифра - чаще всего эта цифра - магическая константа. Лучше давать названия там цифрам, путем создания констант.
// Разбивает отдельные задачи на функции, даже если не вызыаем их много раз 
// Переменные создаем только в том месте, где они используются (с поправкой на область видимости)
// НЕЛЬЗЯ использовать break и continue. break только в switch. Если используются break или continue - скорее всего мысль выражена неверно и ее можно выразить рациональней. 

// Про функции
// Правило №1: пиши функции коротко
// Правило №2: пиши функции еще короче


list* detirmine_winner_of_match(team first_team, team second_team, List head)
{
	match cur_match = match(first_team, second_team);
	cur_match.determine_res();

	head = change_list(head, cur_match.first_team);
	head = change_list(head, cur_match.second_team);

	return head.element;
}


int main(int argc, char* argv[])
{
	FILE* fr = fopen("input.txt", "rt");

	FILE* fw = fopen("output.txt", "wt");

	List head;
	head.element = NULL;
	fseek(fw, 0L, SEEK_SET);
	char str[SIZE] = { 0 };
	int row = 0;
	list* temp_head;
	while (!feof(fr))
	{
		fgets(str, SIZE, fr);
		row++;
	}
	row = row - 1;
	fseek(fr, 0L, SEEK_SET);
	char team1[SIZE] = { 0 };
	char team2[SIZE] = { 0 };
	int score_of_team1 = 0;
	int score_of_team2 = 0;
	while (row != 0)
	{
		fscanf(fr, "%s - %s ", team1, team2);
		fscanf(fr, "%d:%d", &score_of_team1, &score_of_team2);
		cout << score_of_team1 << " " << score_of_team2 << "\n";
		string name1 = (string)team1;
		string name2 = (string)team2;

		team first_team = team(score_of_team1, name1);
		team second_team = team(score_of_team2, name2);

		cout << first_team.goals_of_cur_match << " " << second_team.goals_of_cur_match << "\n\n";
		head.element = detirmine_winner_of_match(first_team, second_team, head);
		row = row - 1;
	}
	int win = 0;
	int max_dif = 0;
	int old = 0;
	temp_head = head.element;
	while (temp_head != NULL)
	{
		if (temp_head->element.score >= win)
		{
			old = win;
			win = temp_head->element.score;
			if (old < win)
				max_dif = temp_head->element.difference_of_goals;
			win = temp_head->element.score;
			if (temp_head->element.difference_of_goals > max_dif)
			{
				max_dif = temp_head->element.difference_of_goals;
			}
		}
		temp_head = temp_head->next;
	}
	temp_head = head.element;
	print_list(temp_head, fw, win, max_dif);
	fclose(fr);
	fclose(fw);

	free_list(head.element);
	return 0;
}