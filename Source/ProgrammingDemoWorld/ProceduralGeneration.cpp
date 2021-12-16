// Fill out your copyright notice in the Description page of Project Settings.


#include "ProceduralGeneration.h"

// Sets default values
AProceduralGeneration::AProceduralGeneration()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Floor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorComponent"));
	SetRootComponent(Floor);
}

// Called when the game starts or when spawned
void AProceduralGeneration::BeginPlay()
{
	Super::BeginPlay();

	SpawnItem(CubeClass);
}

// Called every frame
void AProceduralGeneration::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void AProceduralGeneration::SpawnItem(UClass* ItemToSpawn)
{
	float XCoordinate = FMath::FRandRange(-500.0f, 500.0f);
	float YCoordinate = FMath::FRandRange(-500.0f, 500.0f);

	FVector Location(0.f, 0.f, 0.f);
	FRotator Rotation(0.f, 0.f, 0.f);

	GetWorld()->SpawnActor<AActor>(ItemToSpawn, FVector(0.0f), FRotator(0.0f));
}

