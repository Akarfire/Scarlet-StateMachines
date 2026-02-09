// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SSM_StateBase.h"
#include "SSM_NestedStateMachineState.generated.h"

/**
 * 
 */
UCLASS()
class SCARLETSTATEMACHINES_API USSM_NestedStateMachineState : public USSM_StateBase
{
	GENERATED_BODY()
	
protected:

	// A pointer to the state machine embedded in this state
	class USSM_StateMachine* EmbeddedStateMachine = nullptr;

public:

	// Constructor
	USSM_NestedStateMachineState() {}

	// Called when the state is made active
	virtual void EnterState_Implementation() override;

	// Called once the active state is changed to a different one
	virtual void ExitState_Implementation() override;

	// Called every state machine update when the state is active
	virtual void UpdateState_Implementation(float DeltaTime) override;

	// Sets the embedded state machine of this state
	UFUNCTION(BlueprintCallable, Category="ScarletStateMachines|NestedStateMachines")
	void SetEmbeddedStateMachine(class USSM_StateMachine* InEmbeddedStateMachine) { EmbeddedStateMachine = InEmbeddedStateMachine; }

	// Returns a pointer to the embedded state machine of this state
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "ScarletStateMachines|NestedStateMachines")
	class USSM_StateMachine* GetEmbeddedStateMachine() { return EmbeddedStateMachine; }
};
