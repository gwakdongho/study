#include "Actor1.h"

AActor1::AActor1()
{
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = Scene;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(Scene);
}

void AActor1::BeginPlay()
{
	Super::BeginPlay();

}

void AActor1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector MoveStep = MoveDirection * MoveSpeed * DeltaTime;
	AddActorWorldOffset(MoveStep);
	TraveledDistance += MoveStep.Size();

	if (TraveledDistance >= MaxRange)
	{
		MoveDirection *= -1.0f;
		TraveledDistance = 0.0f;
	}
}

