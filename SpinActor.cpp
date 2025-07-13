#include "SpinActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"

ASpinActor::ASpinActor()
{
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = Scene;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(Scene);

	RotationSpeed = FRotator(0.0f, 100.0f, 0.0f);
}

void ASpinActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASpinActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(RotationSpeed * DeltaTime);
}

