#pragma once

#include <iostream>

struct Vector2f
{
	Vector2f()
	:x(0.0f) ,y(0.0f)
	{}

	Vector2f(float m_x,float m_y)
	:x(m_x) ,y(m_y)
	{}
	
	void print()
	{
		std::cout << x << ", " << y << std::endl;
	}

	float x, y;
};