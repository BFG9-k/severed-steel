#include "gui.h"

void features::c_gui::render( SDK::UCanvas* canvas )
{
	MonkeGUI::SetWhiteTexture( SDK::UEngine::GetEngine( )->BlueNoiseTexture );
	MonkeGUI::SetFont( SDK::UEngine::GetEngine( )->TinyFont );
	MonkeGUI::SetupCanvas( canvas, SDK::UGameplayStatics::GetWorldDeltaSeconds( SDK::UWorld::GetWorld( ) ) );

	static bool pressed = false;
	static bool open = true;

	if ( GetAsyncKeyState( VK_INSERT ) & 0x8000 )
		pressed = true;
	else if ( pressed )
	{
		pressed = false;
		open = !open;
	}

	if ( open )
	{
		if ( MonkeGUI::Begin( "severed-steel", &gui_pos, &gui_size, true ) )
		{
			static int tab = 0;

			MonkeGUI::BeginTabs( );
			MonkeGUI::TabItem( "NPC", 0, &tab );
			MonkeGUI::TabItem( "Movement", 1, &tab );
			MonkeGUI::TabItem( "Misc", 2, &tab );
			MonkeGUI::EndTabs( );

			if ( tab == 0 )
			{
				MonkeGUI::Checkbox( "NPC ESP", &config::npc::esp );
				MonkeGUI::Checkbox( "Harmless NPCs", &config::npc::harmless_npcs );
			}
			else if ( tab == 1 )
			{
				MonkeGUI::Checkbox( "Teleport To NPCs", &config::movement::teleport_to_enemies );
				MonkeGUI::Checkbox( "Speedhack", &config::movement::speed_hack );
				MonkeGUI::SliderFloat( "Speedhack Factor", &config::movement::speed_hack_factor, 1.0f, 10000.0f );
				MonkeGUI::Checkbox( "Jumphack", &config::movement::jump_hack );
				MonkeGUI::SliderFloat( "Jump Height", &config::movement::jump_hack_factor, 1.0f, 1000.0f );
				MonkeGUI::Checkbox( "Fast Wallrun", &config::movement::fast_wallrun );
				MonkeGUI::SliderFloat( "Wallrun Speed", &config::movement::wallrun_factor, 1.0f, 1000.0f );
			}
			else if ( tab == 2 )
			{
				MonkeGUI::Checkbox( "Infinite Slowmo", &config::misc::infinite_slowmo );
				MonkeGUI::Checkbox( "Score Hack", &config::misc::score_hack );
				MonkeGUI::SliderFloat( "Score Multiplier", &config::misc::score_hack_multiplier, 1.0f, 1000.0f );
			}
			MonkeGUI::End( );
		}
	}
	MonkeGUI::Render( );
}