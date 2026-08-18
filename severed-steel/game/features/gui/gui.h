#pragma once
#include "../features.h"

namespace features
{
	class c_gui
	{
	public:
		void render( SDK::UCanvas* canvas );
	private:
		SDK::FVector2D gui_pos = { 200.f, 150.f };
		SDK::FVector2D gui_size = { 400.f, 300.f };
	};
	inline const std::unique_ptr< c_gui > gui = std::make_unique< c_gui >( );
}