// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ObstaculoBolaActor.generated.h"

UCLASS()
class MYPROJECT3_API AObstaculoBolaActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstaculoBolaActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;



private:

	USphereComponent* Root;
	UStaticMeshComponent* MeshComp;


	UPROPERTY(VisibleAnywhere, Category = Tick)
		float RunningTime;

	
	
};
