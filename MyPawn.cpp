#include "MyPawn.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFrameWork/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputAction.h"

AMyPawn::AMyPawn()
{
	PrimaryActorTick.bCanEverTick = false;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	SetRootComponent(Capsule);
	Capsule->SetSimulatePhysics(false);

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SkeletalMesh->SetupAttachment(Capsule);
	SkeletalMesh->SetSimulatePhysics(false);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(Capsule);
	SpringArm->TargetArmLength = 350.0f;
	SpringArm->bUsePawnControlRotation = false;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

}

void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InputMapping, 0);
		}
	}
}

void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		Input->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyPawn::Move);
		Input->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMyPawn::Look);
	}
}

void AMyPawn::Move(const FInputActionValue& Value)
{
	FVector2D Input = Value.Get<FVector2D>();
	if (!Input.IsNearlyZero())
	{
		FVector Move = GetActorForwardVector() * Input.Y + GetActorRightVector() * Input.X;
		AddActorLocalOffset(Move * 50.f, true);
	}
}

void AMyPawn::Look(const FInputActionValue& Value)
{
	FVector2D Look = Value.Get<FVector2D>();

	ControlRotation.Yaw += Look.X;
	ControlRotation.Pitch = FMath::Clamp(ControlRotation.Pitch - Look.Y, -80.f, 80.f);

	SetActorRotation(FRotator(0.f, ControlRotation.Yaw, 0.f));
	SpringArm->SetRelativeRotation(FRotator(ControlRotation.Pitch, 0.f, 0.f));
}