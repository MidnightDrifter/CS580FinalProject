#include "DXUT.h"
#include "TerrainNode.h"


TerrainNode::TerrainNode() : resource(NO_RESOURCE), owner(NO_OWNER)
{
}

TerrainNode::TerrainNode(int i, int j) : myX(i), myY(j), resource(-1), owner(-1) {}
TerrainNode::TerrainNode(int x, int y, int i, int j) : myX(x), myY(y), resource(i), owner(j){}
TerrainNode::TerrainNode(const TerrainNode& a) : resource(a.getResource()), owner(a.getOwner()), myX(a.getX()), myY(a.getY()) {}

const TerrainNode& TerrainNode::operator=(const TerrainNode& a)
{
	if (this != &a) 

	{
		this->setResource(a.getResource());  
		this->setOwner(a.getOwner());
		this->setX(a.getX());
		this->setY(a.getY());
	}
	return *this;
}

int TerrainNode::getResource() const { return resource; }
int TerrainNode::getOwner() const { return owner; }
int TerrainNode::getX() const { return myX; }
int TerrainNode::getY() const { return myY; }
void TerrainNode::setOwner(int x) { owner = x; }
void TerrainNode::setX(int x) { myX = x; }
void TerrainNode::setY(int x) { myY = x; }


void TerrainNode::setResource(int x) 
{
	resource = x;  
	if (x == MINERALS)
	{
		g_terrain.SetColor(myX, myY, DEBUG_COLOR_RED);
	}
	
	else if(x==GOLD)
	{
		g_terrain.SetColor(myX, myY, DEBUG_COLOR_YELLOW);
	}
	else if (x == FOOD)
	{
		g_terrain.SetColor(myX, myY, DEBUG_COLOR_GREEN);
	}
	else if (x == SCIENCE)
	{
		g_terrain.SetColor(myX, myY, DEBUG_COLOR_BLUE);
	}
}





void TerrainNode::clear()
{
	setOwner(-1);
	setResource(-1);
	g_terrain.SetColor(myX, myY, DEBUG_COLOR_WHITE);
}

TerrainNode::~TerrainNode()
{
}
