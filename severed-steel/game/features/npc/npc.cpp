#include "npc.h"

void features::c_npc::handle_npc( SDK::UCanvas* canvas )
{
	for ( const auto& current_actor : SDK::UWorld::GetWorld( )->PersistentLevel->Actors )
	{
		if ( !current_actor )
			continue;

		if ( !current_actor->IsA( SDK::ANPC::StaticClass( ) ) )
			continue;

		SDK::ANPC* const NPC  = static_cast< SDK::ANPC* >( current_actor );
		if ( !NPC )
			continue;
		 
		if ( NPC->bIsDead )
			continue;

		if ( config::npc::harmless_npcs )
			NPC->bShouldShoot = false;

		if ( config::movement::teleport_to_enemies )
			SDK::UWorld::GetWorld( )->OwningGameInstance->LocalPlayers[ 0 ]->PlayerController->AcknowledgedPawn->K2_TeleportTo( current_actor->RootComponent->RelativeLocation, current_actor->RootComponent->RelativeRotation );

		if ( !config::npc::esp )
			continue;

		SDK::FVector2D top_screen, bottom_screen;
		const SDK::FVector top_world = { current_actor->RootComponent->RelativeLocation.X, current_actor->RootComponent->RelativeLocation.Y, current_actor->RootComponent->RelativeLocation.Z + 90.f };
		const SDK::FVector bottom_world = { current_actor->RootComponent->RelativeLocation.X, current_actor->RootComponent->RelativeLocation.Y, current_actor->RootComponent->RelativeLocation.Z - 90.f };

		if ( SDK::UWorld::GetWorld( )->OwningGameInstance->LocalPlayers[ 0 ]->PlayerController->ProjectWorldLocationToScreen( top_world, &top_screen, false ) && SDK::UWorld::GetWorld( )->OwningGameInstance->LocalPlayers[ 0 ]->PlayerController->ProjectWorldLocationToScreen( bottom_world, &bottom_screen, false ) )
		{
			const float height = bottom_screen.Y - top_screen.Y;
			const float width = height / 1.8f;

			const SDK::FVector2D box_position = { top_screen.X - ( width / 2.0f ), top_screen.Y };
			const SDK::FVector2D box_size = { width, height };
			canvas->K2_DrawBox( box_position, box_size, 1.5f, SDK::FLinearColor{ 1.f, 1.f, 1.f, 1.f } );
		}
	}
}