#include "DXUT.h"
#include "TerrainInfoMap.h"



TerrainInfoMap::TerrainInfoMap() : map(), numPlayers(-1), favoredPlayer(-1), maxAmountOfResource(sRA), preferredResource(-1), playerAreaSize(sPAS)
{
	for (int i = 0; i < g_terrain.GetWidth();++i)
	{
		for (int j = 0; j < g_terrain.GetWidth(); ++j)
		{
			map[i][j] = TerrainNode(i, j);
		}
	}
}

TerrainInfoMap::TerrainInfoMap(int p) : map(), numPlayers(p), favoredPlayer(-1), maxAmountOfResource(sRA), preferredResource(-1), playerAreaSize(sPAS)
{
	for (int i = 0; i < g_terrain.GetWidth(); ++i)
	{
		for (int j = 0; j < g_terrain.GetWidth(); ++j)
		{
			map[i][j] = TerrainNode(i, j);
		}
	}
}

TerrainInfoMap::TerrainInfoMap(int p, int fp) : map(), numPlayers(p), favoredPlayer(fp), maxAmountOfResource(sRA), preferredResource(-1), playerAreaSize(sPAS)
{
	for (int i = 0; i < g_terrain.GetWidth(); ++i)
	{
		for (int j = 0; j < g_terrain.GetWidth(); ++j)
		{
			map[i][j] = TerrainNode(i, j);
		}
	}
}

TerrainInfoMap::TerrainInfoMap(int p, int fp, int max) : map(), numPlayers(p), favoredPlayer(fp), maxAmountOfResource(max), preferredResource(-1), playerAreaSize(sPAS)
{
	for (int i = 0; i < g_terrain.GetWidth(); ++i)
	{
		for (int j = 0; j < g_terrain.GetWidth(); ++j)
		{
			map[i][j] = TerrainNode(i, j);
		}
	}
}


TerrainInfoMap::TerrainInfoMap(int p, int fp, int max, int pr) : map(), numPlayers(p), favoredPlayer(fp), maxAmountOfResource(max), preferredResource(pr), playerAreaSize(sPAS)
{
	for (int i = 0; i < g_terrain.GetWidth(); ++i)
	{
		for (int j = 0; j < g_terrain.GetWidth(); ++j)
		{
			map[i][j] = TerrainNode(i, j);
		}
	}
}

TerrainInfoMap::TerrainInfoMap(int p, int fp, int max, int pr, int pas) : map(), numPlayers(p), favoredPlayer(fp), maxAmountOfResource(max), preferredResource(pr), playerAreaSize(pas)
{
	for (int i = 0; i < g_terrain.GetWidth(); ++i)
	{
		for (int j = 0; j < g_terrain.GetWidth(); ++j)
		{
			map[i][j] = TerrainNode(i, j);
		}
	}
}

inline int TerrainInfoMap::rangeRand(int u, int l) { return rand() % u + (u - l); }
inline int TerrainInfoMap::selectResource() { return rand() % 4; }
int TerrainInfoMap::getNumPlayers() const { return numPlayers; }
int TerrainInfoMap::getFavoredPlayer() const { return favoredPlayer; }
int TerrainInfoMap::getMaxAmountOfResource() const { return maxAmountOfResource; }
int TerrainInfoMap::getPreferredResource() const { return preferredResource; }
int TerrainInfoMap::getPlayerAreaSize() const { return playerAreaSize; }

void TerrainInfoMap::setNumPlayers(int x) { numPlayers = x; }
void TerrainInfoMap::setFavoredPlayer(int x) { favoredPlayer = x; }
void TerrainInfoMap::setMaxAmountOfResource(int x) { maxAmountOfResource = x; }
void TerrainInfoMap::setPreferredResource(int x) { preferredResource = x; }
void TerrainInfoMap::setPlayerAreaSize(int x) { numPlayers = x; }

bool TerrainInfoMap::isInPlayerArea(int i, int x, int y)
{
	if (i == 0)
	{
		return !(x > 3 || y > 3 || x < 0 || y < 0);
	}

	else if (i == 1)
	{
		return !(x > 3 || x < 0 || y >= g_terrain.GetWidth() || y < g_terrain.GetWidth() - 4);
	}

	else if (i == 2)
	{
		return !(y > 3 || y < 0 || x >= g_terrain.GetWidth() || x < g_terrain.GetWidth() - 4);
	}

	else if (i == 3)
	{
		return !( y >= g_terrain.GetWidth() || y < g_terrain.GetWidth() - 4 || x >= g_terrain.GetWidth() || x < g_terrain.GetWidth() - 4);
	}

	else
	{
		return false;
	}
}

void TerrainInfoMap::generateTerrain()
{
	//(0-3)x  (0-3)y  = P1 's zone
	//(0-3)x  (size-1 - size-4)y = p2's zone
	//(size-1 - size-4)x  (0-3)y = p3's zone
	//(size-1 - size-4)x  (size-1 - size-4)y p4's zone

	//Resources are in the following order:  Minerals, Gold, Food, Science

	int playerCounts[4] = { 0,0,0,0 };  //Amount of resources in each player's zone
	int player1Counts[4] = { 0,0,0,0 };  //Count of number of resources in P1's zone
	int player2Counts[4] = { 0,0,0,0 };	// ""  P2
	int player3Counts[4] = { 0,0,0,0 }; //  "" P3
	int player4Counts[4] = { 0,0,0,0 }; // ""P4
	int resourceCounts[4] = { 0,0,0,0 };  //Amount of each type of resource placed
	int resourcesPlaced=0;  //Total number of resources placed
	int x = this->rangeRand(3, 0);  //P1's zone
	int y = this->rangeRand(3, 0); //P1's zone
	int res = this->chooseResource();  //Choose starting resource
	do
	{
		if (map[x][y].getResource() != -1)
		{
			res = this->chooseResource();
			//P1's fav resource is:  Minerals
			if (res == TerrainNode::MINERALS)
			{
				if (player1Counts[0] < 2)
				{
					map[x][y].setResource(TerrainNode::MINERALS);
					player1Counts[0]++;
					playerCounts[0]++;
				}
			}
				else
				{
					if (player1Counts[res] < 1)
					{
						map[x][y].setResource(res);
						player1Counts[res]++;
						playerCounts[0]++;
					}
				}
			}


		

		x = this->rangeRand(3, 0);
		y = this->rangeRand(3, 0);

	
	}while (playerCounts[0] < 5);
	
	//P2's zone
	x = this->rangeRand(3, 0);
	y = this->rangeRand(g_terrain.GetWidth() - 1, g_terrain.GetWidth() - 4);

	do
	{
		if (map[x][y].getResource() != -1)
		{
			res = this->chooseResource();
			//P2's fav resource is:  Gold
			if (res == TerrainNode::MINERALS)
			{
				if (player2Counts[1] < 2)
				{
					map[x][y].setResource(TerrainNode::GOLD);
					player2Counts[1]++;
					playerCounts[1]++;
				}
			}
			else
			{
				if (player2Counts[res] < 1)
				{
					map[x][y].setResource(res);
					player2Counts[res]++;
					playerCounts[1]++;
				}
			}
		}




		x = this->rangeRand(3, 0);
		y = this->rangeRand(g_terrain.GetWidth() - 1, g_terrain.GetWidth() - 4);


	} while (playerCounts[1] < 5);


	y = this->rangeRand(3, 0);
	x = this->rangeRand(g_terrain.GetWidth() - 1, g_terrain.GetWidth() - 4);


	//P3
	do
	{
		if (map[x][y].getResource() != -1)
		{
			res = this->chooseResource();
			if (res == TerrainNode::FOOD)
			{
				if (player3Counts[0] < 2)
				{
					map[x][y].setResource(TerrainNode::FOOD);
					player3Counts[2]++;
					playerCounts[2]++;
				}
			}
			else
			{
				if (player3Counts[res] < 1)
				{
					map[x][y].setResource(res);
					player3Counts[res]++;
					playerCounts[2]++;
				}
			}
		}



		y = this->rangeRand(3, 0);
		x = this->rangeRand(g_terrain.GetWidth() - 1, g_terrain.GetWidth() - 4);


	} while (playerCounts[2] < 5);


	
	y = this->rangeRand(g_terrain.GetWidth() - 1, g_terrain.GetWidth() - 4);
	x = this->rangeRand(g_terrain.GetWidth() - 1, g_terrain.GetWidth() - 4);



	//P4
	do
	{
		if (map[x][y].getResource() != -1)
		{
			res = this->chooseResource();
			if (res == TerrainNode::SCIENCE)
			{
				if (player4Counts[0] < 2)
				{
					map[x][y].setResource(TerrainNode::SCIENCE);
					player4Counts[0]++;
					playerCounts[3]++;
				}
			}
			else
			{
				if (player4Counts[res] < 1)
				{
					map[x][y].setResource(res);
					player4Counts[res]++;
					playerCounts[3]++;
				}
			}
		}





		y = this->rangeRand(g_terrain.GetWidth() - 1, g_terrain.GetWidth() - 4);
		x = this->rangeRand(g_terrain.GetWidth() - 1, g_terrain.GetWidth() - 4);


	} while (playerCounts[0] < 5);
	


	// MAIN MAP
	x = this->rangeRand(g_terrain.GetWidth() - 1, 0);
	y = this->rangeRand(g_terrain.GetWidth() - 1, 0);


	do {
		if (!this->isInPlayerArea(0, x, y) && !this->isInPlayerArea(1, x, y) && !this->isInPlayerArea(2, x, y) && !this->isInPlayerArea(3, x, y) && map[x][y].getResource == -1)
		{
			res = this->chooseResource();
			
			if (preferredResource > 0)
			{
				if (res == preferredResource)
				{
					if (resourceCounts[res] < maxAmountOfResource + 3)
					{
						map[x][y].setResource(res);
						resourceCounts[res]++;
						resourcesPlaced++;
					}

				

				
				}
				else
				{
					if (resourceCounts[res] < maxAmountOfResource - 1)
					{
						map[x][y].setResource(res);
						resourceCounts[res]++;
						resourcesPlaced++;
					} 
				}
			}

			else
			{
				if (resourceCounts[res] < maxAmountOfResource)
				{
					map[x][y].setResource(res);
					resourceCounts[res]++;
					resourcesPlaced++;
				}
			}


		}

		x = this->rangeRand(g_terrain.GetWidth() - 1, 0);
		y = this->rangeRand(g_terrain.GetWidth() - 1, 0);
		

	} while (resourcesPlaced < (maxAmountOfResource * 4));


}


void TerrainInfoMap::clear()
{
	for (int i = 0; i < g_terrain.GetWidth(); i++)
	{
		for (int j = 0; j < g_terrain.GetWidth(); j++)
		{
			map[i][j].clear();
		}
	}
}

TerrainInfoMap::~TerrainInfoMap()
{
}
