// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PlataformaFixa.generated.h"

UCLASS()
class MYPROJECT3_API APlataformaFixa : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlataformaFixa();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
private:

	UBoxComponent* Root;
	UStaticMeshComponent* MeshComp;
	
};
