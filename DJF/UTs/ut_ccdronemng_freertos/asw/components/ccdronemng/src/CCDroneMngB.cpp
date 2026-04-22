#include <public/ccdronemng_iface_v1.h>

// ***********************************************************************

// class EDROOM_CTX_Top_0

// ***********************************************************************



	// CONSTRUCTORS***********************************************

CCDroneMng::EDROOM_CTX_Top_0::EDROOM_CTX_Top_0(CCDroneMng &act,
	 Pr_Time & EDROOMpVarVNextCtrl ):

	EDROOMcomponent(act),
	Msg(EDROOMcomponent.Msg),
	MsgBack(EDROOMcomponent.MsgBack),
	DroneMngCtrl(EDROOMcomponent.DroneMngCtrl),
	DroneTimer(EDROOMcomponent.DroneTimer),
	VNextCtrl(EDROOMpVarVNextCtrl)
{
}

CCDroneMng::EDROOM_CTX_Top_0::EDROOM_CTX_Top_0(EDROOM_CTX_Top_0 &context):

	EDROOMcomponent(context.EDROOMcomponent),
	Msg(context.Msg),
	MsgBack(context.MsgBack),
	DroneMngCtrl(context.DroneMngCtrl),
	DroneTimer(context.DroneTimer),
	VNextCtrl(context.VNextCtrl)
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

	// User-defined Functions   ****************************

void	CCDroneMng::EDROOM_CTX_Top_0::FDroneSelfTest()

{

 
 
pus_service129_drone_selftest();
 
//comentario de comprobacion
 
 

}



void	CCDroneMng::EDROOM_CTX_Top_0::FExecDroneTC()

{
   //Handle Msg->data
  CDTCHandler & varSDroneTC = *(CDTCHandler *)Msg->data;
	
varSDroneTC.ExecDroneTC();

}



void	CCDroneMng::EDROOM_CTX_Top_0::FFlightCtrlAlgorithm()

{

pus_service129_flight_ctrl_algorithm();

}



void	CCDroneMng::EDROOM_CTX_Top_0::FGetConfig()

{
   //Handle Msg->data
  CDDroneConfig & varSDroneSetUp = *(CDDroneConfig *)Msg->data;
 
 
 
pus_service129_setup(varSDroneSetUp);

}



void	CCDroneMng::EDROOM_CTX_Top_0::FInitFlightPlan()

{

Pr_Time time;
time.GetTime();
time += Pr_Time(0,100000);
VNextCtrl=time;
pus_service129_init_flight_plan();
DroneTimer.InformAt(time);

}



void	CCDroneMng::EDROOM_CTX_Top_0::FProgNextCtrl()

{

Pr_Time time;
VNextCtrl += Pr_Time(0,100000);
time=VNextCtrl;
DroneTimer.InformAt(time);

}



void	CCDroneMng::EDROOM_CTX_Top_0::FReplyDroneReady()

{

pus_service129_drone_ready();
   //Reply synchronous communication
   Msg->reply(SDroneReady); 
}



void	CCDroneMng::EDROOM_CTX_Top_0::FToReady()

{

 pus_service129_drone_ready();

}



bool	CCDroneMng::EDROOM_CTX_Top_0::GExecFlightPlan()

{

return pus_service129_flight_plan_ready();

}



bool	CCDroneMng::EDROOM_CTX_Top_0::GFlightPlanDone()

{

return pus_service129_flight_plan_done();

}



	//********************************** Pools *************************************



// ***********************************************************************

// class EDROOM_SUB_Top_0

// ***********************************************************************



	// CONSTRUCTOR*************************************************

CCDroneMng::EDROOM_SUB_Top_0::EDROOM_SUB_Top_0 (CCDroneMng&act):
		EDROOM_CTX_Top_0(act,
			VNextCtrl)
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
			//Next Transition is ToReady
			case (ToReady):
				//Msg->Data Handling 
				FGetConfig();
				//Reply Synchronous Message 
				FReplyDroneReady();
				//Next State is Ready
				edroomNextState = Ready;
				break;
			//To Choice Point ExecTC
			case (ExecTC):

				//Msg->Data Handling 
				FExecDroneTC();
				//Evaluate Branch InitFlightPlan
				if( GExecFlightPlan() )
				{
					//Execute Action 
					FInitFlightPlan();

					//Branch taken is ExecTC_InitFlightPlan
					edroomCurrentTrans.localId =
						ExecTC_InitFlightPlan;

					//Next State is FlightPlan
					edroomNextState = FlightPlan;
				 } 
				//Default Branch WaitFP
				else
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

				//Execute Action 
				FFlightCtrlAlgorithm();
				//Evaluate Branch PlanDone
				if( GFlightPlanDone() )
				{
					//Execute Action 
					FToReady();

					//Branch taken is CtrlAlgorithm_PlanDone
					edroomCurrentTrans.localId =
						CtrlAlgorithm_PlanDone;

					//Next State is Ready
					edroomNextState = Ready;
				 } 
				//Default Branch ProgNextCtrl
				else
				{
					//Execute Action 
					FProgNextCtrl();

					//Branch taken is CtrlAlgorithm_ProgNextCtrl
					edroomCurrentTrans.localId =
						CtrlAlgorithm_ProgNextCtrl;

					//Next State is FlightPlan
					edroomNextState = FlightPlan;
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
				//Execute Exit Action 
				FDroneSelfTest();
				break;

				//Go to the state Ready
			case (Ready):
				//Arrival to state Ready
				edroomCurrentTrans=EDROOMReadyArrival();
				break;

				//Go to the state FlightPlan
			case (FlightPlan):
				//Arrival to state FlightPlan
				edroomCurrentTrans=EDROOMFlightPlanArrival();
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

					//Next transition is  ToReady
					edroomCurrentTrans.localId= ToReady;
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

	// Leaf SubState  Ready

	// ***********************************************************************



TEDROOMTransId CCDroneMng::EDROOM_SUB_Top_0::EDROOMReadyArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	bool edroomValidMsg=false;

	do
	{

		EDROOMNewMessage ();

		switch(Msg->signal)
		{

			case (SDroneTC): 

				 if (*Msg->GetPInterface() == DroneMngCtrl)
				{

					//Next transition is  ExecTC
					edroomCurrentTrans.localId = ExecTC;
					edroomCurrentTrans.distanceToContext = 0 ;
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

	// Leaf SubState  FlightPlan

	// ***********************************************************************



TEDROOMTransId CCDroneMng::EDROOM_SUB_Top_0::EDROOMFlightPlanArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	bool edroomValidMsg=false;

	do
	{

		EDROOMNewMessage ();

		switch(Msg->signal)
		{

			case (EDROOMSignalTimeout): 

				 if (*Msg->GetPInterface() == DroneTimer)
				{

					//Next transition is  CtrlAlgorithm
					edroomCurrentTrans.localId = CtrlAlgorithm;
					edroomCurrentTrans.distanceToContext = 0 ;
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



