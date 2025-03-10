// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup.h"
#include "Net/UnrealNetwork.h"

APickup::APickup()
{
    // Tell UE to replicate this Actor
    bReplicates = true;
    

    //pickup do not need to tick every frame
    PrimaryActorTick.bCanEverTick = false;
    if(GetLocalRole() == ROLE_Authority)
    {
        bIsActive = true;
    }

}

void APickup::GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimePropps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimePropps);

   // DOREPLIFETIME(APickup, bIsActive);
}

bool APickup::IsActive()
{
    return bIsActive;
}

void APickup::SetIsActive(bool NewPickupState)
{
    if(GetLocalRole() == ROLE_Authority)
    {
        bIsActive = NewPickupState;
    }

}

//Rep Notify will be called when BIsActive variable changes
void APickup::OnRep_IsActive()
{
}
