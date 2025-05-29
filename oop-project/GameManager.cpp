#include <SFML/Graphics.hpp>
#include <algorithm>
#include <chrono>
#include <time.h>

#include "GameManager.h"

//"<<" overloading so it prints the vector2f
std::ostream& operator<<(std::ostream& os, const sf::Vector2f& vector) {
	return os << "(" << vector.x << ", " << vector.y << ")";
}

//manager clock initializer
sf::Clock GameManager::clock;

//singleton instance of GameManager (private constructor)
GameManager GameManager::managerInstance;

Room* GameManager::activeRoom = nullptr;

//function called in main.cpp
void GameManager::startGame() {
	initializeEntities();

	for (int i = 0; i < Room::rooms.size(); i++) {
		GameManager::activeRoom = Room::rooms[0]; //set the active room to the first room
		break;
	}

	GameManager::activeRoom->getRoomEntities().push_back(MovingEntities::initializePlayer()); //add the player to the active room
}

//game initializer
void GameManager::initializeEntities() {

	srand(time(NULL));

	//random number of rooms between 10 and 20
	for (int i = 0; i < rand() % 10 + 10; i++) {
		Room::initializeRoom();
	}

	Room::linkRooms();

	for (int i = 0; i < Room::rooms.size(); i++) {

		if (i != 0) {

			std::cout << "Room " << i << ": " << std::endl;

			//initialize the entities in the room
			for (int j = 0; j < rand() % 5 + 7; j++) {
				Room::rooms[i]->getRoomEntities().push_back(MovingEntities::initializeEnemy());
				std::cout << "Enemy spawned at: " << Room::rooms[i]->getRoomEntities().back()->getSprite().getPosition() << std::endl;

			}
			std::cout << std::endl;
		}
	}
}

//initialize steady clock
std::chrono::steady_clock::time_point GameManager::lastTime = std::chrono::steady_clock::now();

void GameManager::handleGame() {
	
	float deltaTime = GameManager::clock.restart().asSeconds();

	//handle the movement of the entities
	for (auto& entity : GameManager::activeRoom->getRoomEntities()) {
		EntityType type = entity->getEntityType();
		if (type == EntityType::Player || type == EntityType::Enemy) {
			entity->handleMovement(deltaTime);
		}
	}

	//change the direction of the enemies every 3 seconds
    auto currentTime = std::chrono::steady_clock::now();
    const std::chrono::seconds changeInterval(3);

    if (currentTime - lastTime >= changeInterval) {
		for (auto& entity : GameManager::activeRoom->getRoomEntities()) {
			EntityType type = entity->getEntityType();
			if (type == EntityType::Enemy) {
				entity->changeDirection();
			}
		}
        lastTime = currentTime;
    }

	//handle the collision between entities
	collisionManager();
}

//move the player from one room to another (called in collision manager)
void GameManager::changePlayerRoom(GameEntity* player, Room* oldRoom, Room* newRoom, DoorPosition position) {
	oldRoom = GameManager::activeRoom;
	oldRoom->getRoomEntities().erase(std::remove(oldRoom->getRoomEntities().begin(), oldRoom->getRoomEntities().end(), player), oldRoom->getRoomEntities().end());
	
	switch (position) {
	case DoorPosition::Left:
		GameManager::activeRoom = GameManager::activeRoom->getLeftDoor(); //left room
		GameManager::activeRoom->getRoomEntities().push_back(player);
		player->getSpriteRef().setPosition({ 1750.f, 540.f });
		break;
	
	case DoorPosition::Up:
		GameManager::activeRoom = GameManager::activeRoom->getUpDoor(); //up room
		GameManager::activeRoom->getRoomEntities().push_back(player);
		player->getSpriteRef().setPosition({ 960.f, 910.f });
		break;
	
	case DoorPosition::Right:
		GameManager::activeRoom = GameManager::activeRoom->getRightDoor(); //right room
		GameManager::activeRoom->getRoomEntities().push_back(player);
		player->getSpriteRef().setPosition({ 150.f, 540.f });
		break;

	case DoorPosition::Down:
		GameManager::activeRoom = GameManager::activeRoom->getDownDoor(); //down room
		GameManager::activeRoom->getRoomEntities().push_back(player);
		player->getSpriteRef().setPosition({ 960.f, 150.f });
		break;

	}
	
}

//handle the actor collision with the collidable instances
void GameManager::collisionManager() {

	//actor-wall collision handling
	for (int i = 0; i < GameManager::activeRoom->getRoomEntities().size(); i++) {
		if (GameManager::activeRoom->getRoomEntities()[i]->getEntityType() == EntityType::Player || GameManager::activeRoom->getRoomEntities()[i]->getEntityType() == EntityType::Enemy) {

			for (int j = 0; j < GameManager::activeRoom->getRoomEntities().size(); j++) {
				if (GameManager::activeRoom->getRoomEntities()[j]->getEntityType() == EntityType::Wall) {

					//if there is collision, set the collision type for the wall
					if (managerInstance.isColliding(GameManager::activeRoom->getRoomEntities()[i]->getSprite(), GameManager::activeRoom->getRoomEntities()[j]->getSprite())) {

						//calculates if the player is above or below the wall
						if (Collision::isHorizontalCollision(GameManager::activeRoom->getRoomEntities()[i]->getSprite(), GameManager::activeRoom->getRoomEntities()[j]->getSprite()) == false) {
							if (GameManager::activeRoom->getRoomEntities()[i]->getSprite().getGlobalBounds().position.y > GameManager::activeRoom->getRoomEntities()[j]->getSprite().getGlobalBounds().position.y) {
								GameManager::activeRoom->getRoomEntities()[i]->blockMovementUp();
							}
							else if (GameManager::activeRoom->getRoomEntities()[i]->getSprite().getGlobalBounds().position.y < GameManager::activeRoom->getRoomEntities()[j]->getSprite().getGlobalBounds().position.y) {
								GameManager::activeRoom->getRoomEntities()[i]->blockMovementDown();
							}
						}

						//calculates if the player is left or right of the wall
						if (Collision::isHorizontalCollision(GameManager::activeRoom->getRoomEntities()[i]->getSprite(), GameManager::activeRoom->getRoomEntities()[j]->getSprite()) == true) {
							if (GameManager::activeRoom->getRoomEntities()[i]->getSprite().getGlobalBounds().position.x < GameManager::activeRoom->getRoomEntities()[j]->getSprite().getGlobalBounds().position.x) {
								GameManager::activeRoom->getRoomEntities()[i]->blockMovementRight();
							}
							else if (GameManager::activeRoom->getRoomEntities()[i]->getSprite().getGlobalBounds().position.x > GameManager::activeRoom->getRoomEntities()[j]->getSprite().getGlobalBounds().position.x) {
								GameManager::activeRoom->getRoomEntities()[i]->blockMovementLeft();
							}
						}
					}
				}
			}
		}
	}

	Room* oldRoom = nullptr;
	GameEntity* player = nullptr;

	//player-door collision handling
	for (int i = 0; i < GameManager::activeRoom->getRoomEntities().size(); i++) {
		if (GameManager::activeRoom->getRoomEntities()[i]->getEntityType() == EntityType::Player) {

			player = GameManager::activeRoom->getRoomEntities()[i];

			for (int j = 0; j < GameManager::activeRoom->getRoomEntities().size(); j++) {

				if (GameManager::activeRoom->getRoomEntities()[j]->getEntityType() == EntityType::Door) {

					if (managerInstance.isColliding(GameManager::activeRoom->getRoomEntities()[i]->getSprite(), GameManager::activeRoom->getRoomEntities()[j]->getSprite())) {

						if (GameManager::activeRoom->getRoomEntities()[j]->getSprite().getPosition().x < 100.f) {
							
							changePlayerRoom(player, activeRoom, activeRoom->getLeftDoor(), DoorPosition::Left);
							break;
						}

						else if (GameManager::activeRoom->getRoomEntities()[j]->getSprite().getPosition().y < 100.f) {
							
							changePlayerRoom(player, activeRoom, activeRoom->getUpDoor(), DoorPosition::Up);
							break;
						}

						else if (GameManager::activeRoom->getRoomEntities()[j]->getSprite().getPosition().x > 1690.f) {
							
							changePlayerRoom(player, activeRoom, activeRoom->getRightDoor(), DoorPosition::Right);
							break;
						}

						else if (GameManager::activeRoom->getRoomEntities()[j]->getSprite().getPosition().y > 850.f) {
							
							changePlayerRoom(player, activeRoom, activeRoom->getDownDoor(), DoorPosition::Down);
							break;
						}
					}
				}
			}

			break;
		}
	}
}

//getter
Room* GameManager::getActiveRoom() {
	return GameManager::activeRoom;
}

