#ifndef TEAM_H_
#define TEAM_H_

#include "AVLTree.h"
#include "Player.h"

class Team
{
private:

	AVLTree<Player> teamTree;
	int teamId;
	int points;
	int goalKeepers[2];
	int totalGoals;
	int totalCards;
	int totalPlayers;
	int topScorerId;
	int* totalGamesPlayed;

public:
	Team(int teamId, int points);
	~Team() = default;
	Team(const Team& other) = default;
	Team& operator=(const Team& other) = default;
	
	bool insertPlayer(int playerId, int gamesPlayed, int goals, int cards, bool gk);
	bool removePlayer(int playerId);
	int getTeamPoints() const;
	int getTopScorer() const;
	int getTeamPower() const;
	int getPlayersCount() const;
	void getPlayerDetails(Player* const out);
	bool operator<(const Team& other) const;
	bool operator>(const Team& other) const;
	bool operator==(const Team& other) const;
};

#endif