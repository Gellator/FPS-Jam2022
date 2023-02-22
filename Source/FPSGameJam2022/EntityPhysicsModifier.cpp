// Fill out your copyright notice in the Description page of Project Settings.


#include "EntityPhysicsModifier.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values for this component's properties
UEntityPhysicsModifier::UEntityPhysicsModifier()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	IsPlayer = false;
	LowGravityScale = 0.3f;
	FrictionCoef = 8;
	MaxSpeed = 2000;
	MinSpeed = 300;
	AirControlReduced = 0.5;
	SpeedMultiplier = 1.1;
	SlowMultiplier = 0.8;

	MixedColor = EColorLights::CL_Nothing;
	// ...
}


// Called when the game starts
void UEntityPhysicsModifier::BeginPlay()
{
	Super::BeginPlay();

	if (IsPlayer)
		MovementComponent = GetOwner()->FindComponentByClass<UCharacterMovementComponent>();
	else
		MovementComponent = null;
	// ...
	
}


// Called every frame
void UEntityPhysicsModifier::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	// ...
}

void UEntityPhysicsModifier::SetColor(EColorLights NewColor)
{
	if (Color1 == EColorLights::CL_Nothing)
	{
		Color1 = NewColor;
	}
	else if (Color2 == EColorLights::CL_Nothing)
	{
		Color2 = NewColor;
	}
	MixedColor = GetMixedColorStage();
}

void UEntityPhysicsModifier::RemoveColor(EColorLights ColorToRemove)
{
	if (Color1 == ColorToRemove)
	{
		Color1 = EColorLights::CL_Nothing;
	}
	else if (Color2 == ColorToRemove)
	{
		Color2 = EColorLights::CL_Nothing;
	}
	MixedColor = GetMixedColorStage();
}

EColorLights UEntityPhysicsModifier::GetMixedColorStage()
{
	bool isCyanA = Color1 == EColorLights::CL_Blue || Color1 == EColorLights::CL_Green;
	bool isCyanB = Color2 == EColorLights::CL_Blue || Color2 == EColorLights::CL_Green;
	bool isYellowA = Color1 == EColorLights::CL_Red || Color1 == EColorLights::CL_Green;
	bool isYellowB = Color2 == EColorLights::CL_Red || Color2 == EColorLights::CL_Green;
	bool isMagentaA = Color1 == EColorLights::CL_Blue || Color1 == EColorLights::CL_Red;
	bool isMagentaB = Color2 == EColorLights::CL_Blue || Color2 == EColorLights::CL_Red;
	if (Color1 != EColorLights::CL_Nothing && Color2 != EColorLights::CL_Nothing)
	{
		if (isCyanA && isCyanB)
		{
			return EColorLights::CL_Cyan;
		}
		if (isYellowA && isYellowB)
		{
			return EColorLights::CL_Yellow;
		}
		if (isMagentaA && isMagentaB)
		{
			return EColorLights::CL_Magenta;
		}
	}


	return EColorLights::CL_Nothing;
}

void UEntityPhysicsModifier::ActivateAntiGravity()
{
	MovementComponent->GravityScale = LowGravityScale;
}

void UEntityPhysicsModifier::ActivateFastAsFuckBoi()
{
	MultiplyVelocity(SpeedMultiplier);
	//MovementComponent->MaxWalkSpeed = MaxSpeed;
}

void UEntityPhysicsModifier::ActivateSlowMotion()
{
	//MovementComponent->BrakingFrictionFactor = FrictionCoef;
	MovementComponent->MaxWalkSpeed = MinSpeed;
	MovementComponent->AirControl = AirControlReduced;
	//MultiplyVelocity(SlowMultiplier);
	//MovementComponent->GravityScale = .05;
}

void UEntityPhysicsModifier::ActivateSlowMotionAlt()
{
	MovementComponent->BrakingFrictionFactor = FrictionCoef;
	MovementComponent->MaxWalkSpeed = MinSpeed;
	//MovementComponent->AirControl = 0.5;
	MultiplyVelocity(SlowMultiplier);
	//MovementComponent->GravityScale = .05;
}

//BACKUP OF ORIGINAL ActivateSlowMotion()

/*void UEntityPhysicsModifier::ActivateSlowMotion()
{
	MovementComponent->BrakingFrictionFactor = FrictionCoef;
	MovementComponent->MaxWalkSpeed = MinSpeed;
	MovementComponent->AirControl = 0.5;
	MultiplyVelocity(SlowMultiplier);
	//MovementComponent->GravityScale = .05;
}*/

void UEntityPhysicsModifier::ResetPhysics()
{
	MovementComponent->GravityScale = 1;
	MovementComponent->AirControl = 1;
	MovementComponent->MaxWalkSpeed = 600;
	MovementComponent->BrakingFrictionFactor = 1;
}

void UEntityPhysicsModifier::MultiplyVelocity(float ratio)
{
	FVector PriorVelocity = MovementComponent->Velocity;
	MovementComponent->Velocity = PriorVelocity * /*2*/ ratio;
}

