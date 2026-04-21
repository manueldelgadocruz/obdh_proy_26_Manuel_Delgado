#include <public/ut_ccdronemng_iface_v1.h>

// ***********************************************************************

// class EDROOM_CTX_Top_0

// ***********************************************************************



	// CONSTRUCTORS***********************************************

UT_CCDroneMng::EDROOM_CTX_Top_0::EDROOM_CTX_Top_0(UT_CCDroneMng &act,
	 TEDROOMUInt8 & EDROOMpVarVCheckTimes ):

	EDROOMcomponent(act),
	Msg(EDROOMcomponent.Msg),
	MsgBack(EDROOMcomponent.MsgBack),
	TesterCtrl(EDROOMcomponent.TesterCtrl),
	WatchDogTimer(EDROOMcomponent.WatchDogTimer),
	UTTimerCtrl(EDROOMcomponent.UTTimerCtrl),
	CEndTest(11),
	VCheckTimes(EDROOMpVarVCheckTimes)
{
}

UT_CCDroneMng::EDROOM_CTX_Top_0::EDROOM_CTX_Top_0(EDROOM_CTX_Top_0 &context):

	EDROOMcomponent(context.EDROOMcomponent),
	Msg(context.Msg),
	MsgBack(context.MsgBack),
	TesterCtrl(context.TesterCtrl),
	WatchDogTimer(context.WatchDogTimer),
	UTTimerCtrl(context.UTTimerCtrl),
	CEndTest(11),
	VCheckTimes(context.VCheckTimes)
{

}

	// EDROOMSearchContextTrans********************************************

bool UT_CCDroneMng::EDROOM_CTX_Top_0::EDROOMSearchContextTrans(
			TEDROOMTransId &edroomCurrentTrans)
			{

	bool edroomValidMsg=false; 

	 switch(Msg->signal)
	{

		// Check trigger for signal EDROOMSignalTimeout

		 case (EDROOMSignalTimeout): 

				if (*Msg->GetPInterface() == WatchDogTimer)
				{

					//Next transition is  WatchDog
					edroomCurrentTrans.localId= WatchDog;
					edroomCurrentTrans.distanceToContext = 0;
					edroomValidMsg=true;
				 }

			 break;

		 case ( EDROOMSignalDestroy ): 

			 edroomValidMsg=true;
			 edroomCurrentTrans.distanceToContext = 0 ;
			 edroomCurrentTrans.localId = -1 ;
			 break;

	}

	return(edroomValidMsg);

}

	// User-defined Functions   ****************************

void	UT_CCDroneMng::EDROOM_CTX_Top_0::FCheckUTLogs()

{

ut_ccdrone_mng_check_trace();

}



void	UT_CCDroneMng::EDROOM_CTX_Top_0::FNextCheck()

{

VCheckTimes++;

}



void	UT_CCDroneMng::EDROOM_CTX_Top_0::FProgWaitEnd()

{
   //Define interval
  Pr_Time interval;
	 
	//Timing Service useful methods
	 
	interval =  Pr_Time(0,100000);
	printf(".");
   //Program relative timer 
   UTTimerCtrl.InformIn( interval ); 
}



void	UT_CCDroneMng::EDROOM_CTX_Top_0::FProgWatchDog()

{
   //Define interval
  Pr_Time interval;
	 
	//Timing Service useful methods
	 
	interval = Pr_Time(10,0); // interval of X sec + Y microsec
   //Program relative timer 
   WatchDogTimer.InformIn( interval ); 
}



bool	UT_CCDroneMng::EDROOM_CTX_Top_0::GEndTest()

{

return (VCheckTimes>= CEndTest);

}



	//********************************** Pools *************************************



// ***********************************************************************

// class EDROOM_SUB_Top_0

// ***********************************************************************



	// CONSTRUCTOR*************************************************

UT_CCDroneMng::EDROOM_SUB_Top_0::EDROOM_SUB_Top_0 (UT_CCDroneMng&act):
		EDROOM_CTX_Top_0(act,
			VCheckTimes),
		VCheckTimes(0)
{

}

	//***************************** EDROOMBehaviour ********************************

void UT_CCDroneMng::EDROOM_SUB_Top_0::EDROOMBehaviour()
{

	TEDROOMTransId edroomCurrentTrans;

	//Behaviour starts from Init State

	edroomCurrentTrans = EDROOMIArrival();

	do
	{

		//Take next transition

		switch(edroomCurrentTrans.localId)
		{

			//To Choice Point CheckEnd
			case (CheckEnd):

				//Execute Action 
				FNextCheck();
				//Evaluate Branch EndTest
				if( GEndTest() )
				{

					//Branch taken is CheckEnd_EndTest
					edroomCurrentTrans.localId =
						CheckEnd_EndTest;

					//Next State is CheckUTTrace
					edroomNextState = CheckUTTrace;
				 } 
				//Default Branch ProgNextTimer
				else
				{
					//Execute Action 
					FProgWaitEnd();

					//Branch taken is CheckEnd_ProgNextTimer
					edroomCurrentTrans.localId =
						CheckEnd_ProgNextTimer;

					//Next State is WaitEndTest
					edroomNextState = WaitEndTest;
				 } 
				break;
			//Next Transition is WatchDog
			case (WatchDog):
				//Next State is CheckUTTrace
				edroomNextState = CheckUTTrace;
				break;
			//Next Transition is Init
			case (Init):
				//Execute Action 
				FProgWatchDog();
				//Next State is WaitStartFlightPlan
				edroomNextState = WaitStartFlightPlan;
				break;
			//Next Transition is StarFlightPlan
			case (StarFlightPlan):
				//Execute Action 
				FProgWaitEnd();
				//Next State is WaitEndTest
				edroomNextState = WaitEndTest;
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

				//Go to the state WaitEndTest
			case (WaitEndTest):
				//Arrival to state WaitEndTest
				edroomCurrentTrans=EDROOMWaitEndTestArrival();
				break;

				//Go to the state CheckUTTrace
			case (CheckUTTrace):
				//Execute Entry Action 
				FCheckUTLogs();
				//Arrival to state CheckUTTrace
				edroomCurrentTrans=EDROOMCheckUTTraceArrival();
				break;

				//Go to the state WaitStartFlightPlan
			case (WaitStartFlightPlan):
				//Arrival to state WaitStartFlightPlan
				edroomCurrentTrans=EDROOMWaitStartFlightPlanArrival();
				break;

		}

		edroomCurrentState=edroomNextState;

	}while(Msg->signal != EDROOMSignalDestroy);

}



	// Context Init**********************************************

void UT_CCDroneMng::EDROOM_SUB_Top_0::EDROOMInit()
{

edroomCurrentState=I;

}



//	 ***********************************************************************

//	 SubState I

//	 ***********************************************************************



TEDROOMTransId UT_CCDroneMng::EDROOM_SUB_Top_0::EDROOMIArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	//Next transition is  Init
	edroomCurrentTrans.localId = Init;
	edroomCurrentTrans.distanceToContext = 0;
	return(edroomCurrentTrans);

}



	// ***********************************************************************

	// Leaf SubState  WaitEndTest

	// ***********************************************************************



TEDROOMTransId UT_CCDroneMng::EDROOM_SUB_Top_0::EDROOMWaitEndTestArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	bool edroomValidMsg=false;

	do
	{

		EDROOMNewMessage ();

		switch(Msg->signal)
		{

			case (EDROOMSignalTimeout): 

				 if (*Msg->GetPInterface() == UTTimerCtrl)
				{

					//Next transition is  CheckEnd
					edroomCurrentTrans.localId = CheckEnd;
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

	// Leaf SubState  CheckUTTrace

	// ***********************************************************************



TEDROOMTransId UT_CCDroneMng::EDROOM_SUB_Top_0::EDROOMCheckUTTraceArrival()
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

	// Leaf SubState  WaitStartFlightPlan

	// ***********************************************************************



TEDROOMTransId UT_CCDroneMng::EDROOM_SUB_Top_0::EDROOMWaitStartFlightPlanArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	bool edroomValidMsg=false;

	do
	{

		EDROOMNewMessage ();

		switch(Msg->signal)
		{

			case (SStartFlightPlan): 

				 if (*Msg->GetPInterface() == TesterCtrl)
				{

					//Next transition is  StarFlightPlan
					edroomCurrentTrans.localId= StarFlightPlan;
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



