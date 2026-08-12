#include "hooked.h"

using PostRender_t = void( __thiscall* )( SDK::UObject*, SDK::UObject* );
PostRender_t o_PostRender;

void hk_PostRender( SDK::UObject* ViewportClient, SDK::UCanvas* Canvas )
{
	MonkeGUI::SetWhiteTexture( SDK::UEngine::GetEngine( )->BlueNoiseTexture );
	MonkeGUI::SetFont( SDK::UEngine::GetEngine( )->TinyFont );
	MonkeGUI::SetupCanvas( Canvas, SDK::UGameplayStatics::GetWorldDeltaSeconds( SDK::UWorld::GetWorld( ) ) );

	static SDK::FVector2D pos = { 200.f, 150.f };
	static SDK::FVector2D size = { 400.f, 300.f };

	static bool pressed = false;
	static bool open = false;

	if ( GetAsyncKeyState( VK_INSERT ) & 0x8000 )
		pressed = true;
	else if ( pressed )
	{
		pressed = false;
		open = !open;
	}

	if ( open )
	{
		if ( MonkeGUI::Begin( "My Window", &pos, &size, true ) )
		{
			static bool enabled = false;
			MonkeGUI::Checkbox( "Enable Feature", &enabled );

			if ( MonkeGUI::Button( "Execute" ) )
			{
				// handle click
			}

			MonkeGUI::End( );
		}
	}
	MonkeGUI::Render( );
}

void game::c_hooked::apply( )
{
	MH_Initialize( );
	
	const SDK::UGameViewportClient* local_viewport_client = SDK::UWorld::GetWorld( )->OwningGameInstance->LocalPlayers[ 0 ]->ViewportClient;
	void* const postrender = reinterpret_cast< void** >( local_viewport_client->VTable )[ 99 ];
	MH_CreateHook( postrender, &hk_PostRender, reinterpret_cast< void** >( &o_PostRender ) );

	MH_EnableHook( MH_ALL_HOOKS );
}