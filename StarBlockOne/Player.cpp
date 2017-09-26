#include "Player.h"


#include "sfwdraw.h"

#include "Box.h"



Player::Player()
{
	body.height = 16;
	body.width = 8;
}


Player::~Player()
{
}



void Player::update()
{
	if (enabled)
	{
		if (sfw::getKey('W'))
		{
			body.y += 2;
		}
		if (sfw::getKey('S'))
		{
			body.y -= 2;
		}
		if (sfw::getKey('A'))
		{
			body.x -= 2;
		}
		if (sfw::getKey('D'))
		{
			body.x += 2;
		}


		if (body.y + body.height < 0)
		{
			body.y = 600 + body.height;
		}
		else if (body.y - body.height > 600)
		{
			body.y = body.height - body.height;
		}

		if (body.x + body.width < 0)
		{
			body.x = 800 + body.width;
		}
		else if (body.x - body.width > 800)
		{
			body.x = body.width - body.width;
		}



		body.vely -= 0.1;

		body.y += body.vely;
		body.x += body.velx;
	}
}

void Player::draw()
{
	if (enabled)
	{
		Box::draw(body.x, body.y, body.width, body.height);
	}
}
