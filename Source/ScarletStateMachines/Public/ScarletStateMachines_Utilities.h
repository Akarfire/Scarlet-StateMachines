// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SSM_StateMachine.h"
#include "SSM_NestedStateMachineState.h"
#include "ScarletStateMachines_Utilities.generated.h"

/**
 * 
 */
UCLASS()
class SCARLETSTATEMACHINES_API UScarletStateMachines_Utilities : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	// Creates a new state machine of a given class
	UFUNCTION(BlueprintCallable, Category="ScarletStateMachines")
	static USSM_StateMachine* CreateStateMachine(TSubclassOf<USSM_StateMachine> StateMachineClass, UObject* Owner, bool AutoInit = true);

	// Constructs a nested state machine state with EmbeddedStateMachineClass inside of it and then adds this state to the StateMachine
	// Returns a pointer to the embedded state machine
	UFUNCTION(BlueprintCallable, Category = "ScarletStateMachines")
	static USSM_StateMachine* AddNestedStateMachineState(	USSM_StateMachine* StateMachine, uint8 InNewStateID,
															TSubclassOf<USSM_StateMachine> EmbeddedStateMachineClass,
															TSubclassOf<USSM_NestedStateMachineState> NestedStateMachineStateClass,
															bool AutoInit = true);
};
