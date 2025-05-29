#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Wall.h"
#include "WalkableTile.h"
#include "Door.h"

#ifndef ROOM_H
#define ROOM_H

class Room {
private:
	struct {
		Room* leftDoor = nullptr;
		Room* upDoor = nullptr;
		Room* rightDoor = nullptr;
		Room* downDoor = nullptr;
	} doors; 

	std::vector <GameEntity*> roomEntities;

	bool hasLeftDoor;
	bool hasUpDoor;
	bool hasRightDoor;
	bool hasDownDoor;

public:
	static std::vector <Room*> rooms; //holds all the rooms in the game

	Room();
	~Room() {};

	static void initializeRoom();
	static void linkRooms();
	
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

	Room* getLeftDoor();
	Room* getUpDoor();
	Room* getRightDoor();
	Room* getDownDoor();

	std::vector <GameEntity*>& getRoomEntities();
};

#endif
