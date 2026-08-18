#pragma once

namespace config
{
	namespace npc
	{
		inline bool esp{ false };
		inline bool harmless_npcs{ false };
	}

	namespace movement
	{
		inline bool teleport_to_enemies{ false };
		inline bool speed_hack{ false };
		inline bool jump_hack{ false };
		inline bool fast_wallrun{ false };

		inline float speed_hack_factor{ 1.f };
		inline float jump_hack_factor{ 1.f };
		inline float wallrun_factor{ 1.f };
	}

	namespace misc
	{
		inline bool infinite_slowmo{ false };
		inline bool score_hack{ false };

		inline float score_hack_multiplier{ 1.f };
	}
}