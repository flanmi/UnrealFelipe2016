// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject3.h"
#include "PlataformaMovelVertical.h"


// Sets default values
APlataformaMovelVertical::APlataformaMovelVertical()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject < UStaticMeshComponent>(TEXT("MeshComp"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (Mesh.Succeeded()) {
		MeshComp->SetStaticMesh(Mesh.Object);

	}

	MeshComp->SetWorldLocation(FVector(.0f, 0.0f, -30.0f));
	MeshComp->SetWorldScale3D(FVector(3.0f, 2.0f, 1.0f));
	MeshComp->AttachTo(RootComponent);


}

// Called when the game starts or when spawned
void APlataformaMovelVertical::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlataformaMovelVertical::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	FVector LocalizacaoAtual = GetActorLocation();

	float DeltaRange = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	LocalizacaoAtual.Z += DeltaRange * 200.0f;
	RunningTime += DeltaTime;


	SetActorLocation(LocalizacaoAtual);



}

