
#include "ObjectPhysicsModifier.h"
#include "EntityPhysicsModifier.h"

// Sets default values for this component's properties
UObjectPhysicsModifier::UObjectPhysicsModifier()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UObjectPhysicsModifier::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UObjectPhysicsModifier::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UObjectPhysicsModifier::SetColor(EColorLights NewColor)
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

void UObjectPhysicsModifier::RemoveColor(EColorLights ColorToRemove)
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

EColorLights UObjectPhysicsModifier::GetMixedColorStage()
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

