// Fill out your copyright notice in the Description page of Project Settings.


#include "SecondSphere.h"
#include "Components/SphereComponent.h"

// Sets default values
ASecondSphere::ASecondSphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Root"));

	RootComponent = SphereComponent;

	SphereComponent->InitSphereRadius(220.0f);
	SphereComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	UStaticMeshComponent* SphereBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	SphereBody->AttachTo(RootComponent);

	ConstructorHelpers::FObjectFinder<UStaticMesh> SphereAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));

	if (SphereAsset.Succeeded())
	{
		SphereBody->SetStaticMesh(SphereAsset.Object);
		SphereBody->SetRelativeLocation(FVector(0.0f, 0.0f, -50.0f));
	}
}

// Called when the game starts or when spawned
void ASecondSphere::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASecondSphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

