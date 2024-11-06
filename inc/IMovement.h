#pragma once


class IMovement {

	float movespeed = 200.f;

public: 
	float& getMovespeed();
	void setMovespeed(const float& value);

};