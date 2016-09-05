// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BombaBoss.generated.h"

UCLASS()
class MYPROJECT3_API ABombaBoss : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABombaBoss();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;


	void SetExplodir(int NewExplodir);
	int GetExplodir();


private:

	USphereComponent* Root;
	UStaticMeshComponent* MeshComp;
	UProjectileMovementComponent* ProjectileMovement;


	float DefaultZ;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	
	UPROPERTY(EditAnywhere)
		float Explodir = 0.0f;
	UPROPERTY(EditAnywhere)
		float DamageAmount = 3;
	
	
};
