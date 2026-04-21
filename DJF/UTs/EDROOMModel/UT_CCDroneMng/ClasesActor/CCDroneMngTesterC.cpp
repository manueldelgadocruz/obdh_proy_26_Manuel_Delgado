#include <public/ccdronemngtester_iface_v1.h>

// ***********************************************************************

// class EDROOM_CTX_Top_0

// ***********************************************************************



	// CONSTRUCTORS***********************************************

CCDroneMngTester::EDROOM_CTX_Top_0::EDROOM_CTX_Top_0(CCDroneMngTester &act,
	 TEDROOMUInt8 & EDROOMpVarVTCCounter,
	 CEDROOMPOOLCDDroneConfig & EDROOMpPoolCDDroneConfig,
	 CEDROOMPOOLCDTCHandler & EDROOMpPoolCDTCHandler ):

	EDROOMcomponent(act),
	Msg(EDROOMcomponent.Msg),
	MsgBack(EDROOMcomponent.MsgBack),
	TesterCtrl(EDROOMcomponent.TesterCtrl),
	DroneCtrl(EDROOMcomponent.DroneCtrl),
	Timer(EDROOMcomponent.Timer),
	CTestTCs(3),
	VTCCounter(EDROOMpVarVTCCounter),
	EDROOMPoolCDDroneConfig(EDROOMpPoolCDDroneConfig),
	EDROOMPoolCDTCHandler(EDROOMpPoolCDTCHandler)
{
}

CCDroneMngTester::EDROOM_CTX_Top_0::EDROOM_CTX_Top_0(EDROOM_CTX_Top_0 &context):

	EDROOMcomponent(context.EDROOMcomponent),
	Msg(context.Msg),
	MsgBack(context.MsgBack),
	TesterCtrl(context.TesterCtrl),
	DroneCtrl(context.DroneCtrl),
	Timer(context.Timer),
	CTestTCs(3),
	VTCCounter(context.VTCCounter),
	EDROOMPoolCDDroneConfig(context.EDROOMPoolCDDroneConfig ),
	EDROOMPoolCDTCHandler(context.EDROOMPoolCDTCHandler )
{

}

	// EDROOMSearchContextTrans********************************************

bool CCDroneMngTester::EDROOM_CTX_Top_0::EDROOMSearchContextTrans(
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

void	CCDroneMngTester::EDROOM_CTX_Top_0::FProgNextTCExec()

{
   //Define interval
  Pr_Time interval;
	 
	//Timing Service useful methods
	 
	
	interval = Pr_Time(1,0); // interval of X sec + Y microsec
   //Program relative timer 
   Timer.InformIn( interval ); 
}



void	CCDroneMngTester::EDROOM_CTX_Top_0::FSendDroneTC()

{
   //Allocate data from pool
  CDTCHandler * pSDroneTC_Data = EDROOMPoolCDTCHandler.AllocData();
	
		// Complete Data 
	
	//*pSDroneTC_Data= //Dummy Data
 
printf("SendDrone TC \n");
 
VTCCounter++;
   //Send message 
   DroneCtrl.send(SDroneTC,pSDroneTC_Data,&EDROOMPoolCDTCHandler); 
}



void	CCDroneMngTester::EDROOM_CTX_Top_0::FStartFlightPlan()

{

printf("Drone In Flight Plan  \n");

}



void	CCDroneMngTester::EDROOM_CTX_Top_0::FStartFligthPlan()

{

   //Send message 
   TesterCtrl.send(SStartFlightPlan); 
}



void	CCDroneMngTester::EDROOM_CTX_Top_0::FUTInvokeSetUp()

{
   //Allocate data from pool
  CDDroneConfig * pSDroneSetUp_Data = EDROOMPoolCDDroneConfig.AllocData();
	
		// Complete Data 
	
	//*pSDroneSetUp_Data= //Data is Dummy
   //Invoke synchronous communication 
   MsgBack=DroneCtrl.invoke(SDroneSetUp,pSDroneSetUp_Data,
                                                     &EDROOMPoolCDDroneConfig); 
}



bool	CCDroneMngTester::EDROOM_CTX_Top_0::GPendingTCs()

{

return (VTCCounter<CTestTCs);

}



	//********************************** Pools *************************************

	//CEDROOMPOOLCDDroneConfig

CCDroneMngTester::EDROOM_CTX_Top_0::CEDROOMPOOLCDDroneConfig::CEDROOMPOOLCDDroneConfig(
			TEDROOMUInt32 elemCount,CDDroneConfig* pMem,bool * pMemMarks):
				CEDROOMProtectedMemoryPool(elemCount, pMem, pMemMarks,
					sizeof(CDDroneConfig))
{
}

CDDroneConfig *	CCDroneMngTester::EDROOM_CTX_Top_0::CEDROOMPOOLCDDroneConfig::AllocData()
{
	return(CDDroneConfig*)CEDROOMProtectedMemoryPool::AllocData();
}

	//CEDROOMPOOLCDTCHandler

CCDroneMngTester::EDROOM_CTX_Top_0::CEDROOMPOOLCDTCHandler::CEDROOMPOOLCDTCHandler(
			TEDROOMUInt32 elemCount,CDTCHandler* pMem,bool * pMemMarks):
				CEDROOMProtectedMemoryPool(elemCount, pMem, pMemMarks,
					sizeof(CDTCHandler))
{
}

CDTCHandler *	CCDroneMngTester::EDROOM_CTX_Top_0::CEDROOMPOOLCDTCHandler::AllocData()
{
	return(CDTCHandler*)CEDROOMProtectedMemoryPool::AllocData();
}



// ***********************************************************************

// class EDROOM_SUB_Top_0

// ***********************************************************************



	// CONSTRUCTOR*************************************************

CCDroneMngTester::EDROOM_SUB_Top_0::EDROOM_SUB_Top_0 (CCDroneMngTester&act
	,CEDROOMMemory *pEDROOMMemory):
		EDROOM_CTX_Top_0(act,
			VTCCounter,
			EDROOMPoolCDDroneConfig,
			EDROOMPoolCDTCHandler),
		VTCCounter(0),
		EDROOMPoolCDDroneConfig(
			10, pEDROOMMemory->poolCDDroneConfig,
			pEDROOMMemory->poolMarkCDDroneConfig),
		EDROOMPoolCDTCHandler(
			10, pEDROOMMemory->poolCDTCHandler,
			pEDROOMMemory->poolMarkCDTCHandler)
{

}

	//***************************** EDROOMBehaviour ********************************

void CCDroneMngTester::EDROOM_SUB_Top_0::EDROOMBehaviour()
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
				//Invoke Synchronous Message 
				FUTInvokeSetUp();
				//Next State is DroneReady
				edroomNextState = DroneReady;
				break;
			//To Choice Point SendTC
			case (SendTC):

				//Send Asynchronous Message 
				FSendDroneTC();
				//Evaluate Branch ProgNextTC
				if( GPendingTCs() )
				{
					//Execute Action 
					FProgNextTCExec();

					//Branch taken is SendTC_ProgNextTC
					edroomCurrentTrans.localId =
						SendTC_ProgNextTC;

					//Next State is DroneReady
					edroomNextState = DroneReady;
				 } 
				//Default Branch StartFlightPlan
				else
				{
					//Execute Action 
					FStartFlightPlan();
					//Send Asynchronous Message 
					FStartFligthPlan();

					//Branch taken is SendTC_StartFlightPlan
					edroomCurrentTrans.localId =
						SendTC_StartFlightPlan;

					//Next State is DroneInFlightPlan
					edroomNextState = DroneInFlightPlan;
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

				//Go to the state DroneReady
			case (DroneReady):
				//Execute Entry Action 
				FProgNextTCExec();
				//Arrival to state DroneReady
				edroomCurrentTrans=EDROOMDroneReadyArrival();
				break;

				//Go to the state DroneInFlightPlan
			case (DroneInFlightPlan):
				//Arrival to state DroneInFlightPlan
				edroomCurrentTrans=EDROOMDroneInFlightPlanArrival();
				break;

		}

		edroomCurrentState=edroomNextState;

	}while(Msg->signal != EDROOMSignalDestroy);

}



	// Context Init**********************************************

void CCDroneMngTester::EDROOM_SUB_Top_0::EDROOMInit()
{

edroomCurrentState=I;

}



//	 ***********************************************************************

//	 SubState I

//	 ***********************************************************************



TEDROOMTransId CCDroneMngTester::EDROOM_SUB_Top_0::EDROOMIArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	//Next transition is  Init
	edroomCurrentTrans.localId = Init;
	edroomCurrentTrans.distanceToContext = 0;
	return(edroomCurrentTrans);

}



	// ***********************************************************************

	// Leaf SubState  DroneReady

	// ***********************************************************************



TEDROOMTransId CCDroneMngTester::EDROOM_SUB_Top_0::EDROOMDroneReadyArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	bool edroomValidMsg=false;

	do
	{

		EDROOMNewMessage ();

		switch(Msg->signal)
		{

			case (EDROOMSignalTimeout): 

				 if (*Msg->GetPInterface() == Timer)
				{

					//Next transition is  SendTC
					edroomCurrentTrans.localId = SendTC;
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

	// Leaf SubState  DroneInFlightPlan

	// ***********************************************************************



TEDROOMTransId CCDroneMngTester::EDROOM_SUB_Top_0::EDROOMDroneInFlightPlanArrival()
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



