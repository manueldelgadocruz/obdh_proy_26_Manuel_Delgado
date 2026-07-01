#include <public/cctcmanager_iface_v1.h>

// ***********************************************************************

// class EDROOM_CTX_Top_0

// ***********************************************************************



	// CONSTRUCTORS***********************************************

CCTCManager::EDROOM_CTX_Top_0::EDROOM_CTX_Top_0(CCTCManager &act,
	 CDTCAcceptReport & EDROOMpVarVAcceptReport,
	 CDTCHandler & EDROOMpVarVCurrentTC,
	 CDTCExecCtrl & EDROOMpVarVTCExecCtrl,
	 CEDROOMPOOLCDTCHandler & EDROOMpPoolCDTCHandler,
	 CEDROOMPOOLCDDroneConfig & EDROOMpPoolCDDroneConfig ):

	EDROOMcomponent(act),
	Msg(EDROOMcomponent.Msg),
	MsgBack(EDROOMcomponent.MsgBack),
	DroneMngCtrl(EDROOMcomponent.DroneMngCtrl),
	BKGExecCtrl(EDROOMcomponent.BKGExecCtrl),
	HK_FDIRCtrl(EDROOMcomponent.HK_FDIRCtrl),
	RxTC(EDROOMcomponent.RxTC),
	VAcceptReport(EDROOMpVarVAcceptReport),
	VCurrentTC(EDROOMpVarVCurrentTC),
	VTCExecCtrl(EDROOMpVarVTCExecCtrl),
	EDROOMPoolCDTCHandler(EDROOMpPoolCDTCHandler),
	EDROOMPoolCDDroneConfig(EDROOMpPoolCDDroneConfig)
{
}

CCTCManager::EDROOM_CTX_Top_0::EDROOM_CTX_Top_0(EDROOM_CTX_Top_0 &context):

	EDROOMcomponent(context.EDROOMcomponent),
	Msg(context.Msg),
	MsgBack(context.MsgBack),
	DroneMngCtrl(context.DroneMngCtrl),
	BKGExecCtrl(context.BKGExecCtrl),
	HK_FDIRCtrl(context.HK_FDIRCtrl),
	RxTC(context.RxTC),
	VAcceptReport(context.VAcceptReport),
	VCurrentTC(context.VCurrentTC),
	VTCExecCtrl(context.VTCExecCtrl),
	EDROOMPoolCDTCHandler(context.EDROOMPoolCDTCHandler ),
	EDROOMPoolCDDroneConfig(context.EDROOMPoolCDDroneConfig )
{

}

	// EDROOMSearchContextTrans********************************************

bool CCTCManager::EDROOM_CTX_Top_0::EDROOMSearchContextTrans(
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

void	CCTCManager::EDROOM_CTX_Top_0::FExecPrioTC()

{

VCurrentTC.ExecPrioTC();

}



void	CCTCManager::EDROOM_CTX_Top_0::FExecRebootTC()

{

VCurrentTC.ExecRebootTC();

}



void	CCTCManager::EDROOM_CTX_Top_0::FFwdBKGTC()

{
   //Allocate data from pool
  CDTCHandler * pSBKGTC_Data = EDROOMPoolCDTCHandler.AllocData();
	
		// Complete Data 
	
	*pSBKGTC_Data=VCurrentTC;
   //Send message 
   BKGExecCtrl.send(SBKGTC,pSBKGTC_Data,&EDROOMPoolCDTCHandler); 
}



void	CCTCManager::EDROOM_CTX_Top_0::FFwdDroneTC()

{
   //Allocate data from pool
  CDTCHandler * pSDroneTC_Data = EDROOMPoolCDTCHandler.AllocData();
*pSDroneTC_Data = VCurrentTC;	
   //Send message 
   DroneMngCtrl.send(SDroneTC,pSDroneTC_Data,&EDROOMPoolCDTCHandler); 
}



void	CCTCManager::EDROOM_CTX_Top_0::FFwdHK_FDIRTC()

{
   //Allocate data from pool
  CDTCHandler * pSHK_FDIR_TC_Data = EDROOMPoolCDTCHandler.AllocData();
	
		// Complete Data 
	
*pSHK_FDIR_TC_Data=VCurrentTC;   
   //Send message 
   HK_FDIRCtrl.send(SHK_FDIR_TC,pSHK_FDIR_TC_Data,&EDROOMPoolCDTCHandler); 
}



void	CCTCManager::EDROOM_CTX_Top_0::FGetEvAction()

{
   //Handle Msg->data
  CDEvAction & varSEvAction = *(CDEvAction *)Msg->data;
VCurrentTC=varSEvAction.GetActionTCHandler();

}



void	CCTCManager::EDROOM_CTX_Top_0::FGetTC()

{
   //Handle Msg->data
  CDTCMemDescriptor & varEDROOMIRQsignal = *(CDTCMemDescriptor *)Msg->data;
		
//Set Descriptor	
VCurrentTC.BuildFromDescriptor(varEDROOMIRQsignal);
 
//Do Acception
VAcceptReport=VCurrentTC.DoAcceptation();

}



void	CCTCManager::EDROOM_CTX_Top_0::FInit()

{

RxTC.MaskIRQ();
 
RxTC.InstallHandler();
 
pus_services_startup(&RxTC);
 
RxTC.UnMaskIRQ();

}



void	CCTCManager::EDROOM_CTX_Top_0::FMngTCAcceptation()

{

 
VCurrentTC.MngTCAcceptation();
 

}



void	CCTCManager::EDROOM_CTX_Top_0::FMngTCRejection()

{

 
 
VCurrentTC.MngTCRejection(VAcceptReport);
 

}



void	CCTCManager::EDROOM_CTX_Top_0::FReboot()

{

pus_services_mng_reboot();

}



void	CCTCManager::EDROOM_CTX_Top_0::FTCExecCtrl()

{

VTCExecCtrl=VCurrentTC.GetExecCtrl();

}



bool	CCTCManager::EDROOM_CTX_Top_0::GAcceptTC()

{

return VAcceptReport.IsAccepted();

}



bool	CCTCManager::EDROOM_CTX_Top_0::GFwdBKGTC()

{

return VTCExecCtrl.IsBKGTC();
 

}



bool	CCTCManager::EDROOM_CTX_Top_0::GFwdDroneTC()

{

return VTCExecCtrl.IsDroneTC();

}



bool	CCTCManager::EDROOM_CTX_Top_0::GFwdToHK_FDIR()

{

return VTCExecCtrl.IsHK_FDIRTC();

}



bool	CCTCManager::EDROOM_CTX_Top_0::GToReboot()

{

return VTCExecCtrl.IsRebootTC();

}



// ***********************************************************************

// class EDROOM_CTX_Ready_1

// ***********************************************************************



	// CONSTRUCTORS***********************************************

CCTCManager::EDROOM_CTX_Ready_1::EDROOM_CTX_Ready_1(EDROOM_CTX_Top_0 &context):
	EDROOM_CTX_Top_0(context)
{

}

CCTCManager::EDROOM_CTX_Ready_1::EDROOM_CTX_Ready_1(
	EDROOM_CTX_Ready_1 &context ):
		EDROOM_CTX_Top_0(context)
{

}

	// EDROOMSearchContextTrans********************************************

bool CCTCManager::EDROOM_CTX_Ready_1::EDROOMSearchContextTrans(
			TEDROOMTransId &edroomCurrentTrans)
			{

	bool edroomValidMsg = false; 

	 switch(Msg->signal)
	 {

		// Check trigger for signal EDROOMIRQsignal

		 case (EDROOMIRQsignal): 

				if (*Msg->GetPInterface() == RxTC)
				{

					 edroomValidMsg=true;
					edroomCurrentTrans.localId = EDROOM_CTX_Top_0::NewRxTC;
					edroomCurrentTrans.distanceToContext = 1 ;
				 }

			 break;

		// Check trigger for signal SEvAction

		 case (SEvAction): 

				if (*Msg->GetPInterface() == HK_FDIRCtrl)
				{

					 edroomValidMsg=true;
					edroomCurrentTrans.localId = EDROOM_CTX_Top_0::NewEvAction;
					edroomCurrentTrans.distanceToContext = 1 ;
				 }

			 break;

	}

	if (false == edroomValidMsg)
	{

		 edroomValidMsg = 
			EDROOM_CTX_Top_0::EDROOMSearchContextTrans(edroomCurrentTrans);
		 if (edroomValidMsg)
		 {
			edroomCurrentTrans.distanceToContext++;
		 }

	}

	return(edroomValidMsg);

}

	// User-defined Functions   ****************************

void	CCTCManager::EDROOM_CTX_Ready_1::FInvokeDroneSetUp()

{
   //Allocate data from pool
  CDDroneConfig * pSDroneSetUp_Data = EDROOMPoolCDDroneConfig.AllocData();
pSDroneSetUp_Data->ZMinBeforeAdvance=10;
pSDroneSetUp_Data->DefaultKp=0.2;
pSDroneSetUp_Data->DefaultKi=0.15;
pSDroneSetUp_Data->DefaultKd=0.05;
   //Invoke synchronous communication 
   MsgBack=DroneMngCtrl.invoke(SDroneSetUp,pSDroneSetUp_Data,
                                                     &EDROOMPoolCDDroneConfig); 
}



	//********************************** Pools *************************************

	//CEDROOMPOOLCDTCHandler

CCTCManager::EDROOM_CTX_Top_0::CEDROOMPOOLCDTCHandler::CEDROOMPOOLCDTCHandler(
			TEDROOMUInt32 elemCount,CDTCHandler* pMem,bool * pMemMarks):
				CEDROOMProtectedMemoryPool(elemCount, pMem, pMemMarks,
					sizeof(CDTCHandler))
{
}

CDTCHandler *	CCTCManager::EDROOM_CTX_Top_0::CEDROOMPOOLCDTCHandler::AllocData()
{
	return(CDTCHandler*)CEDROOMProtectedMemoryPool::AllocData();
}

	//CEDROOMPOOLCDDroneConfig

CCTCManager::EDROOM_CTX_Top_0::CEDROOMPOOLCDDroneConfig::CEDROOMPOOLCDDroneConfig(
			TEDROOMUInt32 elemCount,CDDroneConfig* pMem,bool * pMemMarks):
				CEDROOMProtectedMemoryPool(elemCount, pMem, pMemMarks,
					sizeof(CDDroneConfig))
{
}

CDDroneConfig *	CCTCManager::EDROOM_CTX_Top_0::CEDROOMPOOLCDDroneConfig::AllocData()
{
	return(CDDroneConfig*)CEDROOMProtectedMemoryPool::AllocData();
}



// ***********************************************************************

// class EDROOM_SUB_Top_0

// ***********************************************************************



	// CONSTRUCTOR*************************************************

CCTCManager::EDROOM_SUB_Top_0::EDROOM_SUB_Top_0 (CCTCManager&act
	,CEDROOMMemory *pEDROOMMemory):
		EDROOM_CTX_Top_0(act,
			VAcceptReport,
			VCurrentTC,
			VTCExecCtrl,
			EDROOMPoolCDTCHandler,
			EDROOMPoolCDDroneConfig),
		EDROOMReady(Ready , *this),
		EDROOMPoolCDTCHandler(
			10, pEDROOMMemory->poolCDTCHandler,
			pEDROOMMemory->poolMarkCDTCHandler),
		EDROOMPoolCDDroneConfig(
			2, pEDROOMMemory->poolCDDroneConfig,
			pEDROOMMemory->poolMarkCDDroneConfig)
{

}

	//***************************** EDROOMBehaviour ********************************

void CCTCManager::EDROOM_SUB_Top_0::EDROOMBehaviour()
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
				//Execute Action 
				FInit();
				//Next State is Ready
				edroomNextState = Ready;
				break;
			//To Choice Point NewRxTC
			case (NewRxTC):

				//Msg->Data Handling 
				FGetTC();
				//Evaluate Branch Accepted
				if( GAcceptTC() )
				{
					//Execute Action 
					FMngTCAcceptation();

					//Branch taken is NewRxTC_Accepted
					edroomCurrentTrans.localId =
						NewRxTC_Accepted;

					//Next State is ValidTC
					edroomNextState = ValidTC;
				 } 
				//Default Branch NotAccepted
				else
				{
					//Execute Action 
					FMngTCRejection();

					//Branch taken is NewRxTC_NotAccepted
					edroomCurrentTrans.localId =
						NewRxTC_NotAccepted;

					//Next State is Ready
					edroomNextState = Ready;
				 } 
				break;
			//Next Transition is NewEvAction
			case (NewEvAction):
				//Msg->Data Handling 
				FGetEvAction();
				//Next State is ValidTC
				edroomNextState = ValidTC;
				break;
			//To Choice Point HandleTC
			case (HandleTC):

				//Execute Action 
				FTCExecCtrl();
				//Evaluate Branch ToReboot
				if( GToReboot() )
				{
					//Execute Action 
					FExecRebootTC();

					//Branch taken is HandleTC_ToReboot
					edroomCurrentTrans.localId =
						HandleTC_ToReboot;

					//Next State is Reboot
					edroomNextState = Reboot;
				 } 
				//Evaluate Branch FwdHK_FDIRTC
				else if( GFwdToHK_FDIR() )
				{
					//Send Asynchronous Message 
					FFwdHK_FDIRTC();

					//Branch taken is HandleTC_FwdHK_FDIRTC
					edroomCurrentTrans.localId =
						HandleTC_FwdHK_FDIRTC;

					//Next State is Ready
					edroomNextState = Ready;
				 } 
				//Evaluate Branch FwdBKGTC
				else if( GFwdBKGTC() )
				{
					//Send Asynchronous Message 
					FFwdBKGTC();

					//Branch taken is HandleTC_FwdBKGTC
					edroomCurrentTrans.localId =
						HandleTC_FwdBKGTC;

					//Next State is Ready
					edroomNextState = Ready;
				 } 
				//Evaluate Branch FwdDroneTC
				else if( GFwdDroneTC() )
				{
					//Send Asynchronous Message 
					FFwdDroneTC();

					//Branch taken is HandleTC_FwdDroneTC
					edroomCurrentTrans.localId =
						HandleTC_FwdDroneTC;

					//Next State is Ready
					edroomNextState = Ready;
				 } 
				//Default Branch ExecPrioTC
				else
				{
					//Execute Action 
					FExecPrioTC();

					//Branch taken is HandleTC_ExecPrioTC
					edroomCurrentTrans.localId =
						HandleTC_ExecPrioTC;

					//Next State is Ready
					edroomNextState = Ready;
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

				//Go to the state Ready
			case (Ready):
				//Arrival to state Ready
				edroomCurrentTrans=EDROOMReady.Arrival(
				(TEDROOMTransitionID) edroomCurrentTrans.localId);
				break;

				//Go to the state Reboot
			case (Reboot):
				//Execute Entry Action 
				FReboot();
				//Arrival to state Reboot
				edroomCurrentTrans=EDROOMRebootArrival();
				break;

				//Go to the join point ValidTC
			case (ValidTC):
				//Arrival to join point ValidTC
				edroomCurrentTrans=EDROOMValidTCArrival();
				break;

		}

		edroomCurrentState=edroomNextState;

	}while(Msg->signal != EDROOMSignalDestroy);

}



	// Context Init**********************************************

void CCTCManager::EDROOM_SUB_Top_0::EDROOMInit()
{

EDROOMReady.EDROOMInit();
edroomCurrentState=I;

}



//	 ***********************************************************************

//	 SubState I

//	 ***********************************************************************



TEDROOMTransId CCTCManager::EDROOM_SUB_Top_0::EDROOMIArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	//Next transition is  Init
	edroomCurrentTrans.localId = Init;
	edroomCurrentTrans.distanceToContext = 0;
	return(edroomCurrentTrans);

}



//	 ***********************************************************************

//	 JoinPoint ValidTC

//	 ***********************************************************************



TEDROOMTransId CCTCManager::EDROOM_SUB_Top_0::EDROOMValidTCArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	//Next transition is  HandleTC
	edroomCurrentTrans.localId = HandleTC;
	edroomCurrentTrans.distanceToContext = 0 ;
	return(edroomCurrentTrans);

}



	// ***********************************************************************

	// Leaf SubState  Reboot

	// ***********************************************************************



TEDROOMTransId CCTCManager::EDROOM_SUB_Top_0::EDROOMRebootArrival()
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

// class EDROOM_SUB_Ready_1

// ***********************************************************************



	// CONSTRUCTOR*************************************************

CCTCManager::EDROOM_SUB_Ready_1::EDROOM_SUB_Ready_1(
	EDROOM_CTX_Top_0::TEDROOMStateID stateID, 
	EDROOM_CTX_Top_0 &context):
		EDROOM_CTX_Ready_1(context)
{
	edroomStateID =stateID; 
}

	// llegada**********************************************

TEDROOMTransId CCTCManager::EDROOM_SUB_Ready_1::Arrival(
	EDROOM_CTX_Top_0::TEDROOMTransitionID arrivingTrans)
{

	TEDROOMTransId edroomCurrentTrans;

	//Transition at Context Entry
	switch (arrivingTrans)
	{

		case (EDROOM_CTX_Top_0::NewRxTC_NotAccepted):
			//Memory Entry 
			edroomCurrentTrans.localId = EDROOMMemoryTrans ;
			edroomNextState = edroomCurrentState;
			break;
		case (EDROOM_CTX_Top_0::HandleTC_ExecPrioTC):
			//Memory Entry 
			edroomCurrentTrans.localId = EDROOMMemoryTrans ;
			edroomNextState = edroomCurrentState;
			break;
		case (EDROOM_CTX_Top_0::HandleTC_FwdHK_FDIRTC):
			//Memory Entry 
			edroomCurrentTrans.localId = EDROOMMemoryTrans ;
			edroomNextState = edroomCurrentState;
			break;
		case (EDROOM_CTX_Top_0::HandleTC_FwdBKGTC):
			//Memory Entry 
			edroomCurrentTrans.localId = EDROOMMemoryTrans ;
			edroomNextState = edroomCurrentState;
			break;
		case (EDROOM_CTX_Top_0::HandleTC_FwdDroneTC):
			//Memory Entry 
			edroomCurrentTrans.localId = EDROOMMemoryTrans ;
			edroomNextState = edroomCurrentState;
			break;
		//From entry point Init
		case (EDROOM_CTX_Top_0::Init):
			edroomCurrentTrans.localId=  Init;
			edroomNextState = StandBy;
		//Invoke Synchronous Message 
		FInvokeDroneSetUp();
			break;
		case (EDROOM_CTX_Top_0::EDROOMMemoryTrans):
			//Memory Entry added
			edroomCurrentTrans.localId = EDROOMMemoryTrans ;
			edroomNextState = edroomCurrentState;
			break;
		default:
			//Default is memory entry
			edroomCurrentTrans.localId = EDROOMMemoryTrans ;
			edroomNextState = edroomCurrentState;
			break;
	}

		//Entry into the Next State 
		switch(edroomNextState)
		{

				//Go to the state StandBy
			case (StandBy):
				//Arrival to state StandBy
				edroomCurrentTrans=EDROOMStandByArrival();
				break;

		}

		edroomCurrentState=edroomNextState;

	edroomCurrentTrans.distanceToContext--;

	return(edroomCurrentTrans);

}



	// Context Init**********************************************

void CCTCManager::EDROOM_SUB_Ready_1::EDROOMInit()
{

}



	// ***********************************************************************

	// Leaf SubState  StandBy

	// ***********************************************************************



TEDROOMTransId CCTCManager::EDROOM_SUB_Ready_1::EDROOMStandByArrival()
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



