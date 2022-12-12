// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EntityPhysicsModifier.generated.h"

UENUM(BlueprintType)
enum class EColorLights : uint8 {
	CL_Red UMETA(DisplayName = "Red"), CL_Green UMETA(DisplayName = "Green"), CL_Blue UMETA(DisplayName = "Blue"),
	CL_Cyan UMETA(DisplayName = "Cyan"), CL_Magenta UMETA(DisplayName = "Magenta"), CL_Yellow UMETA(DisplayName = "Yellow"), CL_Nothing UMETA(DisplayName = "Nothing")
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPSGAMEJAM2022_API UEntityPhysicsModifier : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEntityPhysicsModifier();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY()
	UCharacterMovementComponent* MovementComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = " Modifiers ")
	float LowGravityScale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = " Modifiers ")
	float MaxSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = " Modifiers ")
	float FrictionCoef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = " Color ")
	EColorLights Color1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = " Color ")
	EColorLights Color2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = " Color ")
	EColorLights MixedColor;

	UFUNCTION(BlueprintCallable)
	void SetColor(EColorLights NewColor);

	UFUNCTION(BlueprintCallable)
	void RemoveColor(EColorLights ColorToRemove);

	UFUNCTION(BlueprintCallable)
	EColorLights GetMixedColorStage();

	UFUNCTION(BlueprintCallable)
	void ActivateLowGravity();

	UFUNCTION(BlueprintCallable)
	void ActivateFastAsFuckBoi();

	UFUNCTION(BlueprintCallable)
	void ActivateSlowMotion();

	UFUNCTION(BlueprintCallable)
	void ResetPhysics();
	

	UFUNCTION(BlueprintCallable)
	void MultiplyVelocity(float ratio);
};
