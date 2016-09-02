// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject3.h"
#include "CanhaoActor.h"
#include "TiroCanhao.h"


// Sets default values
ACanhaoActor::ACanhaoActor()
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

	MeshComp->SetWorldLocation(FVector(.0f, 0.0f, 0.0f));
	MeshComp->SetWorldScale3D(FVector(2.0f, 0.6f, 0.6f));
	MeshComp->AttachTo(RootComponent);



}

// Called when the game starts or when spawned
void ACanhaoActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACanhaoActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	if (ContadorTiro == 90.0f) {
		DropProjectile();
		ContadorTiro = 0;
	}


	ContadorTiro++;




}

void ACanhaoActor::DropProjectile() {
	FActorSpawnParameters SpawnParameters;
	UWorld* World = GetWorld();
	if (World != nullptr) {
		FRotator Rotation = MeshComp->GetComponentRotation();
		ATiroCanhao* Proj = World->SpawnActor<ATiroCanhao>(GetActorLocation(), Rotation, SpawnParameters);
		if (Proj != nullptr) {
			//UE_LOG(LogTemp, Warning, TEXT("Spawn OK!"));
		}
	}

}