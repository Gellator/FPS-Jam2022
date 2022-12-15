

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ObjectPhysicsModifier.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPSGAMEJAM2022_API UObjectPhysicsModifier : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UObjectPhysicsModifier();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

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
};
