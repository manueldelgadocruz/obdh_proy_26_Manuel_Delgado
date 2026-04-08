#include <public/ccdronemng_iface_v1.h>

// ***********************************************************************

// class EDROOM_CTX_Top_0

// ***********************************************************************



	// CONSTRUCTORS***********************************************

CCDroneMng::EDROOM_CTX_Top_0::EDROOM_CTX_Top_0(CCDroneMng &act ):

	EDROOMcomponent(act),
	Msg(EDROOMcomponent.Msg),
	MsgBack(EDROOMcomponent.MsgBack),
	DroneMngCtrl(EDROOMcomponent.DroneMngCtrl)
{
}

CCDroneMng::EDROOM_CTX_Top_0::EDROOM_CTX_Top_0(EDROOM_CTX_Top_0 &context):

	EDROOMcomponent(context.EDROOMcomponent),
	Msg(context.Msg),
	MsgBack(context.MsgBack),
	DroneMngCtrl(context.DroneMngCtrl)
{

}

	// EDROOMSearchContextTrans********************************************

bool CCDroneMng::EDROOM_CTX_Top_0::EDROOMSearchContextTrans(
			TEDROOMTransId &edroomCurrentTrans)
			{

	bool edroomValidMsg=false; 

	 switch(Msg->signal)
	{

		 case ( EDROOMSignalDestroy ): 

			 edroomValidMsg=true;
			 edroomCurrentTrans.distanceToContext = 0 ;
			 edroomCurrentTrans.localId = -1 ;
			 break;

	}

	return(edroomValidMsg);

}

	//********************************** Pools *************************************



// ***********************************************************************

// class EDROOM_SUB_Top_0

// ***********************************************************************



	// CONSTRUCTOR*************************************************

CCDroneMng::EDROOM_SUB_Top_0::EDROOM_SUB_Top_0 (CCDroneMng&act):
		EDROOM_CTX_Top_0(act)
{

}

	//***************************** EDROOMBehaviour ********************************

void CCDroneMng::EDROOM_SUB_Top_0::EDROOMBehaviour()
{

	TEDROOMTransId edroomCurrentTrans;

	//Behaviour starts from Init State

	edroomCurrentTrans = EDROOMIArrival();

	do
	{

		//Take next transition

		switch(edroomCurrentTrans.localId)
		{

			//Next Transition is Init
			case (Init):
				//Next State is SelfTest
				edroomNextState = SelfTest;
				break;
			//Next Transition is  
			case ( ):
				//Next State is Ready
				edroomNextState = Ready;
				break;
			//To Choice Point ExecTC
			case (ExecTC):

				//Default Branch InitFlightPlan
				
				{

					//Branch taken is ExecTC_InitFlightPlan
					edroomCurrentTrans.localId =
						ExecTC_InitFlightPlan;

					//Next State is Flight Plan
					edroomNextState = Flight Plan;
				 } 
				//Default Branch WaitFP
				
				{

					//Branch taken is ExecTC_WaitFP
					edroomCurrentTrans.localId =
						ExecTC_WaitFP;

					//Next State is Ready
					edroomNextState = Ready;
				 } 
				break;
			//To Choice Point CtrlAlgorithm
			case (CtrlAlgorithm):

				//Default Branch PlanDone
				
				{

					//Branch taken is CtrlAlgorithm_PlanDone
					edroomCurrentTrans.localId =
						CtrlAlgorithm_PlanDone;

					//Next State is Ready
					edroomNextState = Ready;
				 } 
				//Default Branch ProgNextCtrl
				
				{

					//Branch taken is CtrlAlgorithm_ProgNextCtrl
					edroomCurrentTrans.localId =
						CtrlAlgorithm_ProgNextCtrl;

					//Next State is Flight Plan
					edroomNextState = Flight Plan;
				 } 
				break;
		}

		//Entry into the Next State 
		switch(edroomNextState)
		{

				//Go to the state I
			case (I):
				//Arrival to state I
				edroomCurrentTrans=EDROOMIArrival();
				break;

				//Go to the state SelfTest
			case (SelfTest):
				//Arrival to state SelfTest
				edroomCurrentTrans=EDROOMSelfTestArrival();
				break;

				//Go to the state Flight Plan
			case (Flight Plan):
				//Arrival to state Flight Plan
				edroomCurrentTrans=EDROOMFlight PlanArrival();
				break;

				//Go to the state Ready
			case (Ready):
				//Arrival to state Ready
				edroomCurrentTrans=EDROOMReadyArrival();
				break;

		}

		edroomCurrentState=edroomNextState;

	}while(Msg->signal != EDROOMSignalDestroy);

}



	// Context Init**********************************************

void CCDroneMng::EDROOM_SUB_Top_0::EDROOMInit()
{

edroomCurrentState=I;

}



//	 ***********************************************************************

//	 SubState I

//	 ***********************************************************************



TEDROOMTransId CCDroneMng::EDROOM_SUB_Top_0::EDROOMIArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	//Next transition is  Init
	edroomCurrentTrans.localId = Init;
	edroomCurrentTrans.distanceToContext = 0;
	return(edroomCurrentTrans);

}



	// ***********************************************************************

	// Leaf SubState  SelfTest

	// ***********************************************************************



TEDROOMTransId CCDroneMng::EDROOM_SUB_Top_0::EDROOMSelfTestArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	bool edroomValidMsg=false;

	do
	{

		EDROOMNewMessage ();

		switch(Msg->signal)
		{

			case (SDroneSetUp): 

				 if (*Msg->GetPInterface() == DroneMngCtrl)
				{

					//Next transition is   
					edroomCurrentTrans.localId=  ;
					edroomCurrentTrans.distanceToContext = 0;
					edroomValidMsg=true;
				 }

				break;

		};

		if (false == edroomValidMsg)
		{
			 edroomValidMsg = EDROOMSearchContextTrans(edroomCurrentTrans);

		}

	} while (false == edroomValidMsg);

	return(edroomCurrentTrans);

}



	// ***********************************************************************

	// Leaf SubState  Flight Plan

	// ***********************************************************************



TEDROOMTransId CCDroneMng::EDROOM_SUB_Top_0::EDROOMFlight PlanArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	bool edroomValidMsg=false;

	do
	{

		EDROOMNewMessage ();

		if (false == edroomValidMsg)
		{
			 edroomValidMsg = EDROOMSearchContextTrans(edroomCurrentTrans);

		}

	} while (false == edroomValidMsg);

	return(edroomCurrentTrans);

}



	// ***********************************************************************

	// Leaf SubState  Ready

	// ***********************************************************************



TEDROOMTransId CCDroneMng::EDROOM_SUB_Top_0::EDROOMReadyArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	bool edroomValidMsg=false;

	do
	{

		EDROOMNewMessage ();

		if (false == edroomValidMsg)
		{
			 edroomValidMsg = EDROOMSearchContextTrans(edroomCurrentTrans);

		}

	} while (false == edroomValidMsg);

	return(edroomCurrentTrans);

}



