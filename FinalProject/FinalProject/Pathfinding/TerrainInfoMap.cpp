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
	int playerCounts[4] = { 0,0,0,0 };  //Amount of resources in each player's zone
	int resourceCounts[4] = { 0,0,0,0 };  //Amount of each type of resource placed
	int resourcesPlaced = 0;  //Total number of resources placed

	for (int i = 0; i < g_terrain.GetWidth(); i++)
	{
		for (int j = 0; j < g_terrain.GetWidth(); j++)
		{

		}
	}

}




TerrainInfoMap::~TerrainInfoMap()
{
}
