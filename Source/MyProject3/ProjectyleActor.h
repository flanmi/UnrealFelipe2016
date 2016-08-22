// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ProjectyleActor.generated.h"

UCLASS()
class MYPROJECT3_API AProjectyleActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectyleActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
private:

	UBoxComponent* Root;
	UStaticMeshComponent* MeshComp;
	UParticleSystemComponent* Particle;
	UProjectileMovementComponent* ProjectileMovement;


	float DefaultZ;



};
