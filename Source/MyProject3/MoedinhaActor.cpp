// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject3.h"
#include "MoedinhaActor.h"
#include "MyCharacter.h"

// Sets default values
AMoedinhaActor::AMoedinhaActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	Root->bGenerateOverlapEvents = true;
	Root->SetCollisionProfileName("OverlapAllDynamic");
	Root->OnComponentBeginOverlap.AddDynamic(this, &AMoedinhaActor::OnOverlapBegin);
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject < UStaticMeshComponent>(TEXT("MeshComp"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	if (Mesh.Succeeded()) {
		MeshComp->SetStaticMesh(Mesh.Object);

	}

	MeshComp->SetWorldLocation(FVector(.0f, 0.0f, -30.0f));
	MeshComp->SetWorldScale3D(FVector(0.6f, 0.6f, 0.1f));
	MeshComp->SetWorldRotation(FRotator(0.0f, 0.0f, 90.0f));

	MeshComp->SetCollisionProfileName("NoCollision");



	MeshComp->AttachTo(RootComponent);



}

// Called when the game starts or when spawned
void AMoedinhaActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMoedinhaActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AMoedinhaActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherActor->IsA(AMyCharacter::StaticClass())) && (OtherComp != nullptr)) {


		UE_LOG(LogTemp, Warning, TEXT("OverlapBegin"));
		AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
		MyCharacter->SetContadorMoedinha(MyCharacter->GetContadorMoedinha() + 1);
		Destroy();
		MyCharacter->DezMoedinhas();
	}

}