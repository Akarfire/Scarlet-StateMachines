// Fill out your copyright notice in the Description page of Project Settings.


#include "ScarletStateMachines_Utilities.h"

// Creates a new state machine of a given class
USSM_StateMachine* UScarletStateMachines_Utilities::CreateStateMachine(TSubclassOf<USSM_StateMachine> StateMachineClass, UObject* Owner, bool AutoInit)
{
    USSM_StateMachine* NewStateMachine = NewObject<USSM_StateMachine>(Owner, StateMachineClass);

    if (NewStateMachine && AutoInit)
        NewStateMachine->InitStateMachine();

    return NewStateMachine;
}

// Constructs a nested state machine state with EmbeddedStateMachineClass inside of it and then adds this state to the StateMachine
USSM_StateMachine* UScarletStateMachines_Utilities::AddNestedStateMachineState(USSM_StateMachine* StateMachine, uint8 InNewStateID, 
    TSubclassOf<USSM_StateMachine> EmbeddedStateMachineClass, TSubclassOf<USSM_NestedStateMachineState> NestedStateMachineStateClass, bool AutoInit)
{
    if (!StateMachine) return nullptr;
    if (!EmbeddedStateMachineClass) return nullptr;

    // Creating a nested state with it's embedded state machine
    
    USSM_NestedStateMachineState* NewState = NewObject<USSM_NestedStateMachineState>(StateMachine, NestedStateMachineStateClass);
    
    USSM_StateMachine* NewStateMachine = NewObject<USSM_StateMachine>(NewState, EmbeddedStateMachineClass);

    if (AutoInit)
        NewStateMachine->InitStateMachine();

    NewState->SetEmbeddedStateMachine(NewStateMachine);

    // Adding nested state to the specified state machine
    StateMachine->AddNewStateExisting(InNewStateID, NewState);

    return NewStateMachine;
}
