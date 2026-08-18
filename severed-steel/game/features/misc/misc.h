#pragma once
#include "../features.h"

namespace features
{
	class c_misc
	{
	public:
		void handle_misc( );
	};
	inline const std::unique_ptr< c_misc > misc = std::make_unique< c_misc >( );
}