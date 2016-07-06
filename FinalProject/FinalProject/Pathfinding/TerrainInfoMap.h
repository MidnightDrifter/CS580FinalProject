#pragma once
#include "Source/global.h"
#include "Source/terrain.h"
#include "TerrainNode.h"
#include "Source/singleton.h"
#define SIZE_OF_MAP 40
class TerrainInfoMap : public Singleton<TerrainInfoMap>
{
	enum PLAYER_AREA_SIZE { sPAS = 3, lPAS };
	enum RESOURCE_AMOUNTS {sRA=6, mRA = 12, lRA = 20};
	const int STARTING_RESOURCE_AMOUNT = 5;

public:
	TerrainInfoMap();
	TerrainInfoMap(int p);
	TerrainInfoMap(int p, int fp);
	TerrainInfoMap(int p, int fp, int max);
	TerrainInfoMap(int p, int fp, int max, int pr);
	TerrainInfoMap(int p, int fp, int max, int pr, int pas);
	~TerrainInfoMap();

	int getNumPlayers() const;
	int getFavoredPlayer() const;
	int getMaxAmountOfResource() const;
	int getPreferredResource() const;
	int getPlayerAreaSize() const;

	void setNumPlayers(int x);
	void setFavoredPlayer(int x);
	void setMaxAmountOfResource(int x);
	void setPreferredResource(int x);  //Note:  this is the ONLY method that can break the limit on the resource amounts
	void setPlayerAreaSize(int x);

	void generateTerrain(); //Generates the terrain values via weighted randoms

	bool isInPlayerArea(int i, int x, int y);

	int chooseResource();  //Randomly chooses A. to place a resource or not and B. what resource to place
	void placeResource(int x, int i, int j);  //Places a resource at a given node & sets the appropriate color

	int rangeRand(int upper, int lower);  //Generate a number within the specified range, inclusive
	int selectResource();  //Generate a number between 0-3, corresponds to which resource to place


	void clear();  //Kills resources & colors

private:
	TerrainNode map[SIZE_OF_MAP][SIZE_OF_MAP];
	int numPlayers;
	int favoredPlayer;  //Player to favor--read: spawn more resources near--corresponds to OWNER_INFO enum
	int maxAmountOfResource;  //Maximum amount of a resource that can spawn--will be the same for all resources
	int preferredResource;  //Weight map to spawn more of a given resource, corresponds to the RESOURCE_INFO enum
	int playerAreaSize;

};

