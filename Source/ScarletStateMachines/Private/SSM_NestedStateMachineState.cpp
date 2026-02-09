// Fill out your copyright notice in the Description page of Project Settings.


#include "SSM_NestedStateMachineState.h"
#include "SSM_StateMachine.h"


// Called when the state is made active
void USSM_NestedStateMachineState::EnterState_Implementation()
{
	if (!EmbeddedStateMachine) return;

	USSM_StateBase* ActiveState = EmbeddedStateMachine->GetState(EmbeddedStateMachine->GetActiveState());
	if (ActiveState)
		ActiveState->EnterState();
}

// Called once the active state is changed to a different one
void USSM_NestedStateMachineState::ExitState_Implementation()
{
	if (!EmbeddedStateMachine) return;

	USSM_StateBase* ActiveState = EmbeddedStateMachine->GetState(EmbeddedStateMachine->GetActiveState());
	if (ActiveState)
		ActiveState->ExitState();
}

// Called every state machine update when the state is active
void USSM_NestedStateMachineState::UpdateState_Implementation(float DeltaTime)
{
	if (!EmbeddedStateMachine) return;

	EmbeddedStateMachine->UpdateStateMachine(DeltaTime);
}
