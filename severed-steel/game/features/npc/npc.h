#pragma once
#include "../features.h"

namespace features
{
	class c_npc
	{
	public:
		void handle_npc( SDK::UCanvas* canvas );
	};
	inline const std::unique_ptr< c_npc > npc = std::make_unique< c_npc >( );
}