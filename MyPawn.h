#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "MyPawn.generated.h"

class UCapsuleComponent;
class USkeletalMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;

UCLASS()
class SEVEN_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	AMyPawn();

protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UCapsuleComponent* Capsule;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* SkeletalMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* InputMapping;
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* LookAction;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	FRotator ControlRotation;
};
