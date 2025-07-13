#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpinActor.generated.h"

UCLASS()
class SIX_API ASpinActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpinActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Scene;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "RotationSpeed")
	FRotator RotationSpeed;
};
