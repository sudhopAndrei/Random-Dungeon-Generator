#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef MOVEMENTBLOCKER_H
#define MOVEMENTBLOCKER_H

class MovementBlocker {
public:
	virtual void blockMovementUp() = 0;
	virtual void blockMovementDown() = 0;
	virtual void blockMovementLeft() = 0;
	virtual void blockMovementRight() = 0;
};

#endif

