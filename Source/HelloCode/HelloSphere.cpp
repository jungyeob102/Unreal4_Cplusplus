// Fill out your copyright notice in the Description page of Project Settings.


#include "HelloSphere.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"


// Sets default values
AHelloSphere::AHelloSphere()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));

	RootComponent = SphereComponent;

	SphereComponent->InitSphereRadius(220.0f);
	SphereComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	//구체 메시를 생성하고 Root Component에 연결
	UStaticMeshComponent* SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));
	SphereVisual->AttachTo(RootComponent);

	//Construction helper를 사용해 메시에 스태틱 메시를 적용
	ConstructorHelpers::FObjectFinder<UStaticMesh> SphereAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));

	//메시 에셋이 발견됐다면 메시의 속성을 조절한다.
	if (SphereAsset.Succeeded())
	{
		SphereVisual->SetStaticMesh(SphereAsset.Object);
		SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f, -50.0f));
	}

	//파이어 파티클 시스템 컴포넌트 생성
	UParticleSystemComponent* FireParticles = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FireParticles"));

	//ShphereVisual에 붙이기
	FireParticles->AttachTo(SphereVisual);
	//FireParticle 자동 활성화
	FireParticles->bAutoActivate = true;

	ConstructorHelpers::FObjectFinder<UParticleSystem> FireVisual(TEXT("/Game/StarterContent/Particles/P_Fire.P_Fire"));

	if (FireVisual.Succeeded())
	{
		FireParticles->SetTemplate(FireVisual.Object);
		FireParticles->SetRelativeLocation(FVector(0.0f, 0.0f, 150.0f));
	}

	TextRenderComponent = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Text"));

	TextRenderComponent->AttachTo(SphereVisual);
	TextRenderComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 110.0f));

	TextRenderComponent->SetHorizontalAlignment(EHTA_Center);
	TextRenderComponent->SetYScale(2.0f);
	TextRenderComponent->SetXScale(2.0f);
	TextRenderComponent->SetVisibility(true);
	TextRenderComponent->SetText(NSLOCTEXT("AnyNs", "Any", "HelloWorld"));
}

// Called when the game starts or when spawned
void AHelloSphere::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AHelloSphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

