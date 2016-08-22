// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject3.h"
#include "CuboCor.h"
#include "MyCharacter.h"

// Sets default values
ACuboCor::ACuboCor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	Root->bGenerateOverlapEvents = true;
	Root->SetCollisionProfileName("OverlapAllDynamic");
	Root->OnComponentBeginOverlap.AddDynamic(this, &ACuboCor::OnOverlapBegin);
	RootComponent = Root;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionProfileName("NoCollision");
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (Mesh.Succeeded()) {
		MeshComp->SetStaticMesh(Mesh.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/Materials/YellowMaterial.YellowMaterial'"));
	if (Material.Succeeded()) {
		MeshComp->SetMaterial(0, Material.Object);
	}

	MeshComp->SetWorldLocation(FVector(0.0f, 0.0f, -30.0f));
	MeshComp->SetWorldScale3D(FVector(0.6f, 0.6f, 0.6f));
	MeshComp->AttachTo(RootComponent);




}

// Called when the game starts or when spawned
void ACuboCor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACuboCor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ACuboCor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherActor->IsA(AMyCharacter::StaticClass())) && (OtherComp != nullptr)) {
		UE_LOG(LogTemp, Warning, TEXT("OverlapBegin %s"), *MeshComp->GetMaterial(0)->GetName());
		if (MeshComp->GetMaterial(0)->GetName() == "YellowMaterial") {
	
			UMaterial* NewMaterial = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), NULL, TEXT("Material'/Game/Materials/BlueMaterial.BlueMaterial'")));
			if (NewMaterial != nullptr) {
				MeshComp->SetMaterial(0, NewMaterial);
			}
			AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
			MyCharacter->SetContadorCubo(MyCharacter->GetContadorCubo() + 1);
			UE_LOG(LogTemp, Warning, TEXT("ContadorCubo = %d"), MyCharacter->GetContadorCubo());
			MyCharacter->SeisCubos();
			
		}
		else {
			UMaterial* NewMaterial = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), NULL, TEXT("Material'/Game/Materials/YellowMaterial.YellowMaterial'")));
			if (NewMaterial != nullptr) {
				MeshComp->SetMaterial(0, NewMaterial);
			}
			AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
			MyCharacter->SetContadorCubo(MyCharacter->GetContadorCubo() - 1);
			UE_LOG(LogTemp, Warning, TEXT("ContadorCubo = %d"), MyCharacter->GetContadorCubo());
		}


		
	}

}
