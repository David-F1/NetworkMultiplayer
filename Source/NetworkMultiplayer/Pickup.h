// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Pickup.generated.h"

/**
 * 
 */
UCLASS()
class NETWORKMULTIPLAYER_API APickup : public AStaticMeshActor
{
	GENERATED_BODY()

	public:
		//Set defaut values
		APickup();

		// Required network scaffoldong
		void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimePropps) const override;

		//getter and setter for the protected var
		UFUNCTION(BlueprintPure, Category = "Pickup")
		bool IsActive();

		UFUNCTION(BlueprintCallable, Category = "Pickup")
		void SetIsActive(bool NewPickupState);

	
	protected:
		//True when the pickup can be used, false when the pickups is deactivated
		UPROPERTY(ReplicatedUsing = OnRep_IsActive)
		bool bIsActive;


		//will be called each time bIsActive get updated
		UFUNCTION()
		virtual void OnRep_IsActive();

};
