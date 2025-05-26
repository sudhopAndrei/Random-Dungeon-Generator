#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Room.h"

//initialize the static vector of rooms
std::vector<Room*> Room::rooms;

//initialize the static counter for used rooms
int Room::usedRoomsCounter = 0;

Room::Room() : hasLeftDoor(false), hasUpDoor(false), hasRightDoor(false), hasDownDoor(false) {}

//initialize the grass tiles
void Room::initializeRoom() {
	Room* currentRoom = new Room();

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 9; j++) {
			if (i == 0 || i == 15 || j == 0 || j == 8) {
				// Create walls around the edges
				currentRoom->roomEntities.push_back(new Wall("images/wall.png", i * 120.f, j * 120.f, 120, 120));
			}
			else {
				currentRoom->roomEntities.push_back(new WalkableTile("images/floorTile.png", i * 120.f, j * 120.f, 120, 120, "sounds/floorTileWalk.wav"));
			}
		}
	}

	Room::rooms.push_back(currentRoom);
}

void Room::generateDoors() {
	for (int i = 0; i < Room::rooms.size(); i++) {

		//the initial room has all 4 doors
		if (i == 0) {
			Room::rooms[i]->roomEntities.push_back(new Door("images/grassTile.png", 0.f, 480.f, 120, 120, "sounds/doorOpen.wav"));
			Room::rooms[i]->setHasLeftDoor(true);
			
			Room::rooms[i]->roomEntities.push_back(new Door("images/grassTile.png", 900.f, 0.f, 120, 120, "sounds/doorOpen.wav"));
			Room::rooms[i]->setHasUpDoor(true);
			
			Room::rooms[i]->roomEntities.push_back(new Door("images/grassTile.png", 1800.f, 480.f, 120, 120, "sounds/doorOpen.wav"));
			Room::rooms[i]->setHasRightDoor(true);
			
			Room::rooms[i]->roomEntities.push_back(new Door("images/grassTile.png", 900.f, 960.f, 120, 120, "sounds/doorOpen.wav"));
			Room::rooms[i]->setHasDownDoor(true);
		}

		//for every door in the room there is a 50% it will spawn
		else {
			if (rand() % 100 % 2 == 0 && Room::rooms[i]->getHasLeftDoor() == false) {
				Room::rooms[i]->roomEntities.push_back(new Door("images/grassTile.png", 0.f, 480.f, 120, 120, "sounds/doorOpen.wav"));
				Room::rooms[i]->setHasLeftDoor(true);
			}
			if (rand() % 100 % 2 == 0 && Room::rooms[i]->getHasUpDoor() == false) {
				Room::rooms[i]->roomEntities.push_back(new Door("images/grassTile.png", 900.f, 0.f, 120, 120, "sounds/doorOpen.wav"));
				Room::rooms[i]->setHasUpDoor(true);
			}
			if (rand() % 100 % 2 == 0 && Room::rooms[i]->getHasRightDoor() == false) {
				Room::rooms[i]->roomEntities.push_back(new Door("images/grassTile.png", 1800.f, 480.f, 120, 120, "sounds/doorOpen.wav"));
				Room::rooms[i]->setHasRightDoor(true);
			}
			if (rand() % 100 % 2 == 0 && Room::rooms[i]->getHasDownDoor() == false) {
				Room::rooms[i]->roomEntities.push_back(new Door("images/grassTile.png", 900.f, 960.f, 120, 120, "sounds/doorOpen.wav"));
				Room::rooms[i]->setHasDownDoor(true);
			}
		}
	}
}

//setters
void Room::setHasLeftDoor(bool hasLeftDoor) {
	this->hasLeftDoor = hasLeftDoor;
}
void Room::setHasUpDoor(bool hasUpDoor) {
	this->hasUpDoor = hasUpDoor;
}
void Room::setHasRightDoor(bool hasRightDoor) {
	this->hasRightDoor = hasRightDoor;
}
void Room::setHasDownDoor(bool hasDownDoor) {
	this->hasDownDoor = hasDownDoor;
}

//getters
bool Room::getHasLeftDoor() {
	return hasLeftDoor;
}
bool Room::getHasUpDoor() {
	return hasUpDoor;
}
bool Room::getHasRightDoor() {
	return hasRightDoor;
}
bool Room::getHasDownDoor() {
	return hasDownDoor;
}


