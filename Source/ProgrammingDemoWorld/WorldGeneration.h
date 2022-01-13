// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldGeneration.generated.h"

UCLASS()
class PROGRAMMINGDEMOWORLD_API AWorldGeneration : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWorldGeneration();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Room, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Floor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Room, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> CubeClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Room, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> TreeClass;

	//void SpawnItem(UClass* ItemToSpawn);

	float SquareWidth;
	float GridHeight;
	float WorldLength;
	float WorldWidth;

	FVector TopLeftCorner;
	FVector BottomRightCorner;

	int32 GridXSize;
	int32 GridYSize;

	float Radius;


	void CreateFloorGrid();

	FVector GetRandomPoints(const FVector& TopLeft, const FVector& BottomRight);

	void PlacePointsOnGrid();

};
