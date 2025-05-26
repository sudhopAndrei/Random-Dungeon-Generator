#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Wall.h"
#include "WalkableTile.h"
#include "Door.h"

#ifndef ROOM_H
#define ROOM_H

class Room {
	std::vector <GameEntity*> roomEntities;

	bool hasLeftDoor;
	bool hasUpDoor;
	bool hasRightDoor;
	bool hasDownDoor;

public:
	static int usedRoomsCounter;
	static std::vector <Room*> rooms; //holds all the rooms in the game

	//std::vector<Room*> doors = { nullptr, nullptr, Room*, Room*}

	Room();
	~Room() {};

	static void initializeRoom();
	static void generateDoors();
	//static void generateRooms();
	
	//setters
	void setHasLeftDoor(bool hasLeftDoor);
	void setHasUpDoor(bool hasUpDoor);
	void setHasRightDoor(bool hasRightDoor);
	void setHasDownDoor(bool hasDownDoor);

	//getters
	bool getHasLeftDoor();
	bool getHasUpDoor();
	bool getHasRightDoor();
	bool getHasDownDoor();
};

#endif
