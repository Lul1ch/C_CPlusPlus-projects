#pragma once
#include <string>
using namespace std;

struct team {
	string name;
	int difference_of_goals;
	int score;
	int goals_of_cur_match;

	team() {
		goals_of_cur_match = 0;
		name = "";
		difference_of_goals = 0;
		score = 0;
	}

	team(unsigned int goals_of_current_match, string name, int difference_of_goals = 0, int score = 0) {
		this->goals_of_cur_match = goals_of_cur_match;
		this->name = name;
		this->difference_of_goals = difference_of_goals;
		this->score = score;
	} 
};