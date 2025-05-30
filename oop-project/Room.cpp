#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Room.h"

//initialize the static vector of rooms
std::vector<Room*> Room::rooms;

Room::Room() : hasLeftDoor(false), hasUpDoor(false), hasRightDoor(false), hasDownDoor(false) {}

//initialize the grass tiles
void Room::initializeRoom() {
	Room* currentRoom = new Room();

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 9; j++) {
			if (i == 0) {
				// Create walls around the edges
				currentRoom->roomEntities.push_back(new Wall("images/wallTile90.png", i * 120.f, j * 120.f, 120, 120));
			}
			else if (i == 15) {
				currentRoom->roomEntities.push_back(new Wall("images/wallTile270.png", i * 120.f, j * 120.f, 120, 120));
			}
			else if (j == 0) {
				currentRoom->roomEntities.push_back(new Wall("images/wallTile.png", i * 120.f, j * 120.f, 120, 120));
			}
			else if (j == 8) {
				currentRoom->roomEntities.push_back(new Wall("images/wallTile180.png", i * 120.f, j * 120.f, 120, 120));
			}
			else {
				currentRoom->roomEntities.push_back(new WalkableTile("images/floorTile.png", i * 120.f, j * 120.f, 120, 120, "sounds/floorTileWalk.wav"));
			}

			//corners
			if (i == 0 && j == 0) {
				currentRoom->roomEntities.push_back(new Wall("images/cornerTile.png", i * 120.f, j * 120.f, 120, 120));
			}
			else if (i == 15 && j == 0) {
				currentRoom->roomEntities.push_back(new Wall("images/cornerTile90.png", i * 120.f, j * 120.f, 120, 120));
			}
			else if (i == 0 && j == 8) {
				currentRoom->roomEntities.push_back(new Wall("images/cornerTile270.png", i * 120.f, j * 120.f, 120, 120));
			}
			else if (i == 15 && j == 8) {
				currentRoom->roomEntities.push_back(new Wall("images/cornerTile180.png", i * 120.f, j * 120.f, 120, 120));
			}
		}
	}

	Room::rooms.push_back(currentRoom);
}

void Room::linkRooms() {

	int roomsUsedCounter = 1;

	srand(unsigned int(time(NULL)));

	for (int i = 0; i < Room::rooms.size(); i++) {

		//the initial room has all 4 doors
		if (i == 0 && (i + 4) < Room::rooms.size()) {
			Room::rooms[i]->roomEntities.push_back(new Door("images/doorTile90.png", 5.f, 480.f, 120, 120, "sounds/floorTileWalk.wav"));
			Room::rooms[i]->doors.leftDoor = Room::rooms[i + 1];
			
			Room::rooms[i + 1]->roomEntities.push_back(new Door("images/doorTile270.png", 1795.f, 480.f, 120, 120, "sounds/floorTileWalk.wav"));
			Room::rooms[i + 1]->doors.rightDoor = Room::rooms[i];
			
			Room::rooms[i + 1]->setHasRightDoor(true);
			Room::rooms[i]->setHasLeftDoor(true);
			
			roomsUsedCounter++;
					
			///

			Room::rooms[i]->roomEntities.push_back(new Door("images/doorTile.png", 900.f, 5.f, 120, 120, "sounds/floorTileWalk.wav"));
			Room::rooms[i]->doors.upDoor = Room::rooms[i + 2];
			
			Room::rooms[i + 2]->roomEntities.push_back(new Door("images/doorTile180.png", 900.f, 955.f, 120, 120, "sounds/floorTileWalk.wav"));
			Room::rooms[i + 2]->doors.downDoor = Room::rooms[i];
			
			Room::rooms[i + 2]->setHasDownDoor(true);
			Room::rooms[i]->setHasUpDoor(true);

			roomsUsedCounter++;
			
			///

			Room::rooms[i]->roomEntities.push_back(new Door("images/doorTile270.png", 1795.f, 480.f, 120, 120, "sounds/floorTileWalk.wav"));
			Room::rooms[i]->doors.rightDoor = Room::rooms[i + 3];
			
			Room::rooms[i + 3]->roomEntities.push_back(new Door("images/doorTile90.png", 5.f, 480.f, 120, 120, "sounds/floorTileWalk.wav"));
			Room::rooms[i + 3]->doors.leftDoor = Room::rooms[i];
			
			Room::rooms[i + 3]->setHasLeftDoor(true);
			Room::rooms[i]->setHasRightDoor(true);
			
			roomsUsedCounter++;

			///

			Room::rooms[i]->roomEntities.push_back(new Door("images/doorTile180.png", 900.f, 955.f, 120, 120, "sounds/floorTileWalk.wav"));
			Room::rooms[i]->doors.downDoor = Room::rooms[i + 4];
			
			Room::rooms[i + 4]->roomEntities.push_back(new Door("images/doorTile.png", 900.f, 5.f, 120, 120, "sounds/floorTileWalk.wav"));
			Room::rooms[i + 4]->doors.upDoor = Room::rooms[i];
			
			Room::rooms[i + 4]->setHasUpDoor(true);
			Room::rooms[i]->setHasDownDoor(true);

			roomsUsedCounter++;
		}

		//for every door in the room there is a 50% it will spawn
		else if (i != 0) {
			if (rand() % 2 == 0 && Room::rooms[i]->getHasLeftDoor() == false && (roomsUsedCounter) < Room::rooms.size()) {
				Room::rooms[i]->roomEntities.push_back(new Door("images/doorTile90.png", 5.f, 480.f, 120, 120, "sounds/floorTileWalk.wav"));
				Room::rooms[i]->doors.leftDoor = Room::rooms[roomsUsedCounter];
				
				Room::rooms[roomsUsedCounter]->roomEntities.push_back(new Door("images/doorTile270.png", 1795.f, 480.f, 120, 120, "sounds/floorTileWalk.wav"));
				Room::rooms[roomsUsedCounter]->doors.rightDoor = Room::rooms[i];
				
				Room::rooms[roomsUsedCounter]->setHasRightDoor(true);
				Room::rooms[i]->setHasLeftDoor(true);

				roomsUsedCounter++;
			}

			if (rand() % 2 == 0 && Room::rooms[i]->getHasUpDoor() == false && (roomsUsedCounter) < Room::rooms.size()) {
				Room::rooms[i]->roomEntities.push_back(new Door("images/doorTile.png", 900.f, 5.f, 120, 120, "sounds/floorTileWalk.wav"));
				Room::rooms[i]->doors.upDoor = Room::rooms[roomsUsedCounter];
				
				Room::rooms[roomsUsedCounter]->roomEntities.push_back(new Door("images/doorTile180.png", 900.f, 955.f, 120, 120, "sounds/floorTileWalk.wav"));
				Room::rooms[roomsUsedCounter]->doors.downDoor = Room::rooms[i];
				
				Room::rooms[roomsUsedCounter]->setHasDownDoor(true);
				Room::rooms[i]->setHasUpDoor(true);

				roomsUsedCounter++;
			}

			if (rand() % 2 == 0 && Room::rooms[i]->getHasRightDoor() == false && (roomsUsedCounter) < Room::rooms.size()) {
				Room::rooms[i]->roomEntities.push_back(new Door("images/doorTile270.png", 1795.f, 480.f, 120, 120, "sounds/floorTileWalk.wav"));
				Room::rooms[i]->doors.rightDoor = Room::rooms[roomsUsedCounter];
				
				Room::rooms[roomsUsedCounter]->roomEntities.push_back(new Door("images/doorTile90.png", 5.f, 480.f, 120, 120, "sounds/floorTileWalk.wav"));
				Room::rooms[roomsUsedCounter]->doors.leftDoor = Room::rooms[i];
				
				Room::rooms[roomsUsedCounter]->setHasLeftDoor(true);
				Room::rooms[i]->setHasRightDoor(true);

				roomsUsedCounter++;
			}

			if (rand() % 2 == 0 && Room::rooms[i]->getHasDownDoor() == false && (roomsUsedCounter) < Room::rooms.size()) {
				Room::rooms[i]->roomEntities.push_back(new Door("images/doorTile180.png", 900.f, 955.f, 120, 120, "sounds/floorTileWalk.wav"));
				Room::rooms[i]->doors.downDoor = Room::rooms[roomsUsedCounter];
				
				Room::rooms[roomsUsedCounter]->roomEntities.push_back(new Door("images/doorTile.png", 900.f, 5.f, 120, 120, "sounds/floorTileWalk.wav"));
				Room::rooms[roomsUsedCounter]->doors.upDoor = Room::rooms[i];
				
				Room::rooms[roomsUsedCounter]->setHasUpDoor(true);
				Room::rooms[i]->setHasDownDoor(true);

				roomsUsedCounter++;
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

Room* Room::getLeftDoor() {
	return doors.leftDoor;
}
Room* Room::getUpDoor() {
	return doors.upDoor;
}
Room* Room::getRightDoor() {
	return doors.rightDoor;
}
Room* Room::getDownDoor() {
	return doors.downDoor;
}

std::vector <GameEntity*>& Room::getRoomEntities() {
	return roomEntities;
}