#pragma once
#include "team.h"

#define WIN_SCORE 3
#define LOSE_SCORE 0
#define DRAW_SCORE 1

struct match
{
	team first_team;
	team second_team;

	match(team first, team second) {
		first_team = first;
		second_team = second;
	}

	void determine_res()
	{
		first_team.difference_of_goals = first_team.goals_of_cur_match - second_team.goals_of_cur_match;
		second_team.difference_of_goals = second_team.goals_of_cur_match - first_team.goals_of_cur_match;
		if (first_team.difference_of_goals > 0)
		{
			first_team.score = WIN_SCORE;
			second_team.score = LOSE_SCORE;
		}
		else if (first_team.difference_of_goals == 0)
		{
			first_team.score = DRAW_SCORE;
			second_team.score = DRAW_SCORE;
		}
		else
		{
			second_team.score = WIN_SCORE;
			first_team.score = LOSE_SCORE;
		}
	}
};