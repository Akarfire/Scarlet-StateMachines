// Fill out your copyright notice in the Description page of Project Settings.


#include "ScarletStateMachines_Utilities.h"
#include "SSM_NestedStateMachineState.h"

// Creates a new state machine of a given class
USSM_StateMachine* UScarletStateMachines_Utilities::CreateStateMachine(TSubclassOf<USSM_StateMachine> StateMachineClass, UObject* Owner, bool AutoInit)
{
    USSM_StateMachine* NewStateMachine = NewObject<USSM_StateMachine>(Owner, StateMachineClass);

    if (NewStateMachine && AutoInit)
        NewStateMachine->InitStateMachine();

    return NewStateMachine;
}

// Constructs a nested state machine state with EmbeddedStateMachineClass inside of it and then adds this state to the StateMachine
void UScarletStateMachines_Utilities::AddNestedStateMachineState(USSM_StateMachine* StateMachine, uint8 InNewStateID, TSubclassOf<USSM_StateMachine> EmbeddedStateMachineClass)
{
    if (!StateMachine) return;
    if (!EmbeddedStateMachineClass) return;

    // Creating a nested state with it's embedded state machine
    
    USSM_NestedStateMachineState* NewState = NewObject<USSM_NestedStateMachineState>(StateMachine, USSM_NestedStateMachineState::StaticClass());
    
    USSM_StateMachine* NewStateMachine = NewObject<USSM_StateMachine>(NewState, EmbeddedStateMachineClass);
    NewStateMachine->InitStateMachine();

    NewState->SetEmbeddedStateMachine(NewStateMachine);

    // Adding nested state to the specified state machine
    StateMachine->AddNewStateExisting(InNewStateID, NewState);
}
