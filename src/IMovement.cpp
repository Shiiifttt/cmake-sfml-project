
#include "IMovement.h"

float& IMovement::getMovespeed() {
	return movespeed;
}

void IMovement::setMovespeed(const float& value) {
	movespeed = value;
}
