/*
 * Copyright 2020-present Infosys Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */
 
 /******************************************************
 * attachWfMbResp.h
 * This is an auto generated file.
 * Please do not edit this file.
 * All edits to be made through template source file
 * <TOP-DIR/scripts/SMCodeGen/templates/stateMachineTmpls/state.h.tt>
 ******************************************************/
 
#ifndef __AttachWfMbResp__
#define __AttachWfMbResp__

#include "state.h"

namespace mme {

	class AttachWfMbResp : public SM::State
	{
		public:
			/******************************************
			* Instance 
			*    Creates static instance for the state
			*******************************************/
			static AttachWfMbResp* Instance();

			/****************************************
			* AttachWfMbResp
			*    Destructor
			****************************************/
			~AttachWfMbResp();			
			
			/******************************************
			* initialize
			*  Initializes action handlers for the state
			* and next state
			******************************************/
			void initialize();
	
		private:
			/****************************************
			* AttachWfMbResp
			*    Private constructor
			****************************************/
			AttachWfMbResp();  
	};
};
#endif // __AttachWfMbResp__
