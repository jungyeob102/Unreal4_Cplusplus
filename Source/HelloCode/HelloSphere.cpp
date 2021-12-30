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

	//��ü �޽ø� �����ϰ� Root Component�� ����
	UStaticMeshComponent* SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));
	SphereVisual->AttachTo(RootComponent);

	//Construction helper�� ����� �޽ÿ� ����ƽ �޽ø� ����
	ConstructorHelpers::FObjectFinder<UStaticMesh> SphereAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));

	//�޽� ������ �߰ߵƴٸ� �޽��� �Ӽ��� �����Ѵ�.
	if (SphereAsset.Succeeded())
	{
		SphereVisual->SetStaticMesh(SphereAsset.Object);
		SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f, -50.0f));
	}

	//���̾� ��ƼŬ �ý��� ������Ʈ ����
	UParticleSystemComponent* FireParticles = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FireParticles"));

	//ShphereVisual�� ���̱�
	FireParticles->AttachTo(SphereVisual);
	//FireParticle �ڵ� Ȱ��ȭ
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

