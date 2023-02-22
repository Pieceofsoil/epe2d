#pragma once

#include<src/bodies/Body.h>

namespace epe {
	class StaticBody : public Body
	{
	public:
		StaticBody(Vec2 _position);
	};
}

