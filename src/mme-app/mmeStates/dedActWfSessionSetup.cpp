
/*
 * Copyright 2020-present Infosys Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */
 
/**************************************
 * dedActWfSessionSetup.cpp
 * This is an auto generated file.
 * Please do not edit this file.
 * All edits to be made through template source file
 * <TOP-DIR/scripts/SMCodeGen/templates/stateMachineTmpls/state.cpp.tt>
 **************************************/


#include "actionTable.h"
#include "actionHandlers/actionHandlers.h"
#include "mmeSmDefs.h"
#include "utils/mmeStatesUtils.h"
#include "utils/mmeTimerTypes.h"

#include "mmeStates/dedActWfSessionSetup.h"

using namespace mme;
using namespace SM;

/******************************************************************************
* Constructor
******************************************************************************/
DedActWfSessionSetup::DedActWfSessionSetup():State(ded_act_wf_session_setup, defaultStateGuardTimerDuration_c)
{
        stateEntryAction = &MmeStatesUtils::on_state_entry;
        stateExitAction = &MmeStatesUtils::on_state_exit;
        eventValidator = &MmeStatesUtils::validate_event;
}

/******************************************************************************
* Destructor
******************************************************************************/
DedActWfSessionSetup::~DedActWfSessionSetup()
{
}

/******************************************************************************
* creates and returns static instance
******************************************************************************/
DedActWfSessionSetup* DedActWfSessionSetup::Instance()
{
        static DedActWfSessionSetup state;
        return &state;
}

/******************************************************************************
* initializes eventToActionsMap
******************************************************************************/
void DedActWfSessionSetup::initialize()
{
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::process_act_ded_bearer_accept);
                actionTable.addAction(&ActionHandlers::ded_act_complete);
                eventToActionsMap.insert(pair<uint16_t, ActionTable>(ACT_DED_BEARER_ACCEPT_FROM_UE, actionTable));
        }
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::handle_state_guard_timeouts);
                eventToActionsMap.insert(pair<uint16_t, ActionTable>(STATE_GUARD_TIMEOUT, actionTable));
        }
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::process_act_ded_bearer_reject);
                actionTable.addAction(&ActionHandlers::abort_ded_activation);
                eventToActionsMap.insert(pair<uint16_t, ActionTable>(ACT_DED_BEARER_REJECT_FROM_UE, actionTable));
        }
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::abort_ded_activation);
                eventToActionsMap.insert(pair<uint16_t, ActionTable>(ABORT_EVENT, actionTable));
        }
}