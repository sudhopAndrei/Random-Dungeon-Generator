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

void Room::linkRooms() {
	int usedRoomsCounter = 1;

	for (int i = 0; i < Room::rooms.size(); i++) {

		//the initial room has all 4 doors
		if (i == 0) {
			Room::rooms[i]->roomEntities.push_back(new Door("images/grassTile.png", 0.f, 480.f, 120, 120, "sounds/floorTileWalk.wav"));
			
			Room::rooms[i]->doors[0] = Room::rooms[i + 1];
			Room::rooms[i + 1]->doors[2] = Room::rooms[i];
			Room::rooms[i + 1]->setHasRightDoor(true);

			Room::rooms[i]->setHasLeftDoor(true);
			
			usedRoomsCounter++;
			
			///

			Room::rooms[i]->roomEntities.push_back(new Door("images/grassTile.png", 900.f, 0.f, 120, 120, "sounds/floorTileWalk.wav"));
			
			Room::rooms[i]->doors[1] = Room::rooms[i + 2];
			Room::rooms[i + 2]->doors[3] = Room::rooms[i];
			Room::rooms[i + 2]->setHasDownDoor(true);

			Room::rooms[i]->setHasUpDoor(true);

			usedRoomsCounter++;
			
			///

			Room::rooms[i]->roomEntities.push_back(new Door("images/grassTile.png", 1800.f, 480.f, 120, 120, "sounds/floorTileWalk.wav"));

			Room::rooms[i]->doors[2] = Room::rooms[i + 3];
			Room::rooms[i + 3]->doors[0] = Room::rooms[i];
			Room::rooms[i + 3]->setHasLeftDoor(true);

			Room::rooms[i]->setHasRightDoor(true);

			usedRoomsCounter++;
			
			///

			Room::rooms[i]->roomEntities.push_back(new Door("images/grassTile.png", 900.f, 960.f, 120, 120, "sounds/floorTileWalk.wav"));

			Room::rooms[i]->doors[3] = Room::rooms[i + 4];
			Room::rooms[i + 4]->doors[1] = Room::rooms[i];
			Room::rooms[i + 4]->setHasUpDoor(true);

			Room::rooms[i]->setHasDownDoor(true);

			usedRoomsCounter++;
		}

		//for every door in the room there is a 50% it will spawn
		else {
			if (rand() % 100 % 2 == 0 && Room::rooms[i]->getHasLeftDoor() == false && usedRoomsCounter < Room::rooms.size()) {
				Room::rooms[i]->roomEntities.push_back(new Door("images/grassTile.png", 0.f, 480.f, 120, 120, "sounds/floorTileWalk.wav"));

				Room::rooms[i]->doors[0] = Room::rooms[i + 1];
				Room::rooms[i + 1]->doors[2] = Room::rooms[i];
				Room::rooms[i + 1]->setHasRightDoor(true);

				Room::rooms[i]->setHasLeftDoor(true);

				usedRoomsCounter++;
			}

			if (rand() % 100 % 2 == 0 && Room::rooms[i]->getHasUpDoor() == false && usedRoomsCounter < Room::rooms.size()) {
				Room::rooms[i]->roomEntities.push_back(new Door("images/grassTile.png", 900.f, 0.f, 120, 120, "sounds/floorTileWalk.wav"));

				Room::rooms[i]->doors[1] = Room::rooms[i + 2];
				Room::rooms[i + 2]->doors[3] = Room::rooms[i];
				Room::rooms[i + 2]->setHasDownDoor(true);

				Room::rooms[i]->setHasUpDoor(true);

				usedRoomsCounter++;
			}

			if (rand() % 100 % 2 == 0 && Room::rooms[i]->getHasRightDoor() == false && usedRoomsCounter < Room::rooms.size()) {
				Room::rooms[i]->roomEntities.push_back(new Door("images/grassTile.png", 1800.f, 480.f, 120, 120, "sounds/floorTileWalk.wav"));

				Room::rooms[i]->doors[2] = Room::rooms[i + 3];
				Room::rooms[i + 3]->doors[0] = Room::rooms[i];
				Room::rooms[i + 3]->setHasLeftDoor(true);

				Room::rooms[i]->setHasRightDoor(true);

				usedRoomsCounter++;
			}

			if (rand() % 100 % 2 == 0 && Room::rooms[i]->getHasDownDoor() == false && usedRoomsCounter < Room::rooms.size()) {
				Room::rooms[i]->roomEntities.push_back(new Door("images/grassTile.png", 900.f, 960.f, 120, 120, "sounds/floorTileWalk.wav"));

				Room::rooms[i]->doors[3] = Room::rooms[i + 4];
				Room::rooms[i + 4]->doors[1] = Room::rooms[i];
				Room::rooms[i + 4]->setHasUpDoor(true);

				Room::rooms[i]->setHasDownDoor(true);

				usedRoomsCounter++;
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


