#include "misc.h"

void features::c_misc::handle_misc( )
{
	SDK::APlayerCharacter_BP_Manny_C* Steel = reinterpret_cast< SDK::APlayerCharacter_BP_Manny_C* >( SDK::UWorld::GetWorld( )->OwningGameInstance->LocalPlayers[ 0 ]->PlayerController->Character );
	if ( Steel )
	{
		SDK::AWeaponBase* Weapon = Steel->CurrentlyEquippedWeapon;
		if ( Weapon )
		{
			if ( config::movement::speed_hack )
				Steel->CharacterMovement->MaxWalkSpeed = config::movement::speed_hack_factor;

			if ( config::movement::jump_hack )
				Steel->CharacterMovement->JumpZVelocity = config::movement::jump_hack_factor;

			if ( config::movement::jump_hack )
			{
				Steel->WallRunSpeed = config::movement::wallrun_factor;
				Steel->WallRunGravityScale = 0.f;
			}

			if ( config::misc::infinite_slowmo )
				Steel->SloMoBurnRate = 0.f;

			if ( config::misc::score_hack )
				Steel->CurrentMultiMeter = config::misc::score_hack_multiplier;
		}
	}
}