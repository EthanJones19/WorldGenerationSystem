// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldGeneration.h"

// Sets default values
AWorldGeneration::AWorldGeneration()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Floor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorComponent"));
	SetRootComponent(Floor);
}

// Called when the game starts or when spawned
void AWorldGeneration::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnItem(CubeClass);
	SpawnItem(CubeClass);
	SpawnItem(CubeClass);
	SpawnItem(CubeClass);
	SpawnItem(CubeClass);
	SpawnItem(CubeClass);
	SpawnItem(CubeClass);
	SpawnItem(CubeClass);
	SpawnItem(TreeClass);
	SpawnItem(TreeClass);
	SpawnItem(TreeClass);
}

// Called every frame
void AWorldGeneration::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWorldGeneration::SpawnItem(UClass* ItemToSpawn)
{
	float XCoordinate = FMath::FRandRange(-500.0f, 500.0f);
	float YCoordinate = FMath::FRandRange(-500.0f, 500.0f);
	float ZCoordiante = FMath::FRandRange(-50.0f, 50.0f);

	float Yaw = FMath::FRandRange(0.0f, 360.f);

	FVector Location(XCoordinate, YCoordinate, ZCoordiante);
	FRotator Rotation(0.0f, 0.0f, 0.0f);

	GetWorld()->SpawnActor<AActor>(ItemToSpawn, Location, Rotation);

}

