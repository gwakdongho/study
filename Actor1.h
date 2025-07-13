#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actor1.generated.h"

//- `Tick(float DeltaTime)`에서 위치를 변경하여** 왕복 이동** 구현
//- `MoveSpeed`, `MaxRange`, `StartLocation` 등을 고려해 일정 범위를 벗어나면 이동 방향을 반전시키는 로직 구성

UCLASS()
class SIX_API AActor1 : public AActor
{
	GENERATED_BODY()
	
public:	
	AActor1();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(Visibleanywhere)
	USceneComponent* Scene;
	UPROPERTY(Visibleanywhere)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	float MoveSpeed = 200.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	float MaxRange = 500.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	FVector MoveDirection = FVector(1.0f, 0.0f, 0.0f);

	float TraveledDistance = 0.0f;
};
