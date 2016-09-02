// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Boss.generated.h"

UCLASS()
class MYPROJECT3_API ABoss : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoss();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;




	void SetBossLife(int NewBossLife);
	int GetBossLife();
	void BossDerrotado();



private:

	UBoxComponent* Root;
	UStaticMeshComponent* MeshComp;


	UPROPERTY(VisibleAnywhere, Category = Tick)
		float RunningTime;


	UPROPERTY(EditAnywhere)
		int BossLife = 20;


	float ContadorDistancia = 0.0f;

	void DropProjectile();

	float ContadorTiro = 0.0f;
};
