#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Builder_pattern.h"



int main(){
	Team* team1, *team2;
	Director director;
	BuilderforNormalTeam builder;
	string team_name[] = { "Team 1", "Team 2" };
	director.setBuilder(&builder);
	team1 = director.make_team(2, 2, 2, 2);
	team2 = director.make_team(1, 3, 3, 1);
	cout << *team1 << endl;
	cout << *team2 << endl;
	//cout << team_name[0] << " it's your turn!" << endl;
	//cout << "Member from " << team_name[0] << " named: ";
	//team1->make_damage(team2);
	int i = 0;
	while (team1->AnyAlive() && team2->AnyAlive())
	{
		cout <<  "Round: " << i + 1 << "\n";
		int j = i % 2;
		cout << team_name[j] << " it's your turn!" << endl;
		cout << "Member from " << team_name[j] << " named: ";
		team1->make_damage(team2);
		i++;
		cout << endl;
	}
	if (team1->AnyAlive()) {
		cout << team_name[0] << " lost!" << endl;
	}
	if (team2->AnyAlive()) {
		cout << team_name[1] << " lost!" << endl;
	}
	return 0;
}