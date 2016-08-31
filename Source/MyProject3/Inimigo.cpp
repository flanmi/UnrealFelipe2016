// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject3.h"
#include "Inimigo.h"


// Sets default values
AInimigo::AInimigo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



	Root = CreateDefaultSubobject<USphereComponent>(TEXT("Root"));
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject <UStaticMeshComponent>(TEXT("MeshComp"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (Mesh.Succeeded()) {
		MeshComp->SetStaticMesh(Mesh.Object);

	}

	MeshComp->SetWorldLocation(FVector(.0f, 0.0f, -30.0f));
	MeshComp->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	MeshComp->AttachTo(RootComponent);



}

// Called when the game starts or when spawned
void AInimigo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInimigo::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );



	FVector LocalizacaoAtual = GetActorLocation();

	float DeltaRange = 6.0f;

	if (ContadorDistancia >= 0 && ContadorDistancia < 80) {

		LocalizacaoAtual.X -= DeltaRange;

	}
	else if (ContadorDistancia >= 80 && ContadorDistancia < 160) {
		LocalizacaoAtual.X += DeltaRange;
	}

	else if (ContadorDistancia == 160) {
		ContadorDistancia = 0.0f;

	}

	ContadorDistancia++;


	RunningTime += DeltaTime;

	SetActorLocation(LocalizacaoAtual);




}

