#ifndef CCDRONEMNGTESTER_H_
#define CCDRONEMNGTESTER_H_

//******************************************************************************
// EDROOM Service Library

#define _EDROOM_IS_EMBEDDED_

#include <public/edroomsl_iface_v1.h>

//******************************************************************************
// Data Classes

#include <public/cdtchandler_iface_v1.h>
#include <public/cddroneconfig_iface_v1.h>


/**
 * \class   CCDroneMngTester
 *
 */
class CCDroneMngTester: public CEDROOMComponent {

public:

	/**
	 * \enum TEDROOMCCDroneMngTesterSignal
	 * \brief Component Signal Enum Type
	 *
	 */
	 enum TEDROOMCCDroneMngTesterSignal { EDROOMSignalTimeout, 
							EDROOMSignalDestroy, 
							SStartFlightPlan, 
							SDroneSetUp, 
							SDroneTC, 
							SDroneReady };

	/**
	 * \class CCDroneMngTester::CEDROOMMemory
	 * \brief Component Memory
	 *
	 */
	class CEDROOMMemory: public CEDROOMComponentMemory{

		private:

			//!Array of Message Queue Heads, one for each priority
			CEDROOMQueue::CQueueHead QueueHeads[EDROOMprioMINIMUM+1];

			//************ Component Timing Service Memory************

			//!Component Timing Service Timer Info Memory
			CEDROOMTimerInfo TimerInf[3];
			//!Component Timing Service Timer Info Marks Memory
			bool TimerInfMarks[3];
			//!Component Timing Service TimeOut Messages Memory
			CEDROOMTimeOutMessage TimeOutMsgs[3];
			//!Component Timing Service TimeOut Messages Marks Memory
			bool TimeOutMsgsMarks[3];

		public: 

			//!Component Timing Service Memory Object
			CEDROOMTimingMemory TimingMemory;

	// ********************************************************************
	// ******************* Component Message Data Pools *******************
	// ********************************************************************

			//! CDDroneConfig Data Pool Memory
			CDDroneConfig	poolCDDroneConfig[10+1];
			//! CDDroneConfig Data Pool Marks Memory
			bool	poolMarkCDDroneConfig[10];
			//! CDTCHandler Data Pool Memory
			CDTCHandler	poolCDTCHandler[10+1];
			//! CDTCHandler Data Pool Marks Memory
			bool	poolMarkCDTCHandler[10];


			/** \brief This function is used for setting the Component Memory
			 * 
			 * \param numberOfMsgs number of messages that the component can store
			 * \param msgsMemory memory for the messages that the component can store
			 * \param msgsMemoryMarks memory marks for the messages that the component can store
			 * \param numberOfNodes number of nodes that the component needs
			 * \param queueNodesMemory memory for the component message queues 
			 * \param queueNodesMemoryMarks memory marks for the component message queues 
			 */
			void SetMemory(TEDROOMUInt32 numberOfMsgs
						, CEDROOMMessage * msgsMemory
						, bool * msgsMemoryMarks
						, TEDROOMUInt32 numberOfNodes
						, CEDROOMQueue::CQueueNode * queueNodesMemory
						, bool * queueNodesMemoryMarks);

	};


	// ********************************************************************
	//******************  Component Communication Ports *******************
	// ********************************************************************

	//! TesterCtrl Component Port
	CEDROOMInterface	TesterCtrl;
	//! DroneCtrl Component Port
	CEDROOMInterface	DroneCtrl;


	// ********************************************************************
	// ********************  Timing Service Interface *********************
	// ********************************************************************

	//! Timing Service Access Point. It is common to all timing ports.
	CEDROOMTimingSAP	 EDROOMtimingSAP;


	//! Timer Timing Port
	CEDROOMTimingInterface	Timer;




	// *************************************************************************
	// **************************** Frame Service Methods	********************
	// *************************************************************************



	//! Constructor
	CCDroneMngTester(TEDROOMComponentID id, TEDROOMUInt32 roomNumMaxMens, TEDROOMPriority roomtaskPrio, 
		TEDROOMStackSizeType roomStack, CEDROOMMemory * pActorMemory );




	//! Component Configuration 
	 int EDROOMConfig();


	//! Component Start 
	 int EDROOMStart();




	#ifdef _EDROOM_SYSTEM_CLOSE

	//! Method that returns true if component is finished 
	bool EDROOMIsComponentFinished();


	#endif

protected:



	//! Component behaviour 
	virtual void EDROOMBehaviour();




public:

	// *****************************	Behaviour  *************************

	// ***********************************************************************

	// class EDROOM_CTX_Top_0

	// ***********************************************************************



	class EDROOM_CTX_Top_0 {

	protected:

	/**
	 * \enum TEDROOMCCDroneMngTesterSignal
	 * \brief Component Signal Enum Type
	 *
	 */
	enum TEDROOMCCDroneMngTesterSignal { EDROOMSignalTimeout,
		EDROOMSignalDestroy,
		SStartFlightPlan,
		SDroneSetUp,
		SDroneTC,
		SDroneReady };


		friend class CCDroneMngTester;

		//!component reference
		CCDroneMngTester &EDROOMcomponent;

		//!Current message pointer reference
		CEDROOMMessage * &Msg;

		//!Synchronous message back pointer reference
		CEDROOMMessage * &MsgBack;

		//!Component ports
		CEDROOMInterface & TesterCtrl;
		CEDROOMInterface & DroneCtrl;
		CEDROOMTimingInterface & Timer;


		//! State Identifiers
		enum TEDROOMStateID{I,
			DroneReady,
			DroneInFlightPlan};

		//!Transition Identifiers
		enum TEDROOMTransitionID{Init,
			SendTC,
			SendTC_ProgNextTC,
			SendTC_StartFlightPlan,
			EDROOMMemoryTrans };

		//!Constants
		const TEDROOMUInt8 CTestTCs;


		//!Variables
		TEDROOMUInt8 &VTCCounter;


		// Pools *************************************************

		class CEDROOMPOOLCDDroneConfig:public CEDROOMProtectedMemoryPool {
			public:
			CEDROOMPOOLCDDroneConfig(TEDROOMUInt32 elemCount,CDDroneConfig *pMem, bool *pMarks);
			CDDroneConfig	* AllocData();
		};
		CEDROOMPOOLCDDroneConfig	& EDROOMPoolCDDroneConfig;
		class CEDROOMPOOLCDTCHandler:public CEDROOMProtectedMemoryPool {
			public:
			CEDROOMPOOLCDTCHandler(TEDROOMUInt32 elemCount,CDTCHandler *pMem, bool *pMarks);
			CDTCHandler	* AllocData();
		};
		CEDROOMPOOLCDTCHandler	& EDROOMPoolCDTCHandler;


		//!Constructor
		EDROOM_CTX_Top_0 (CCDroneMngTester &act,
				TEDROOMUInt8 & EDROOMpVarVTCCounter,
				CEDROOMPOOLCDDroneConfig & EDROOMpPoolCDDroneConfig,
				CEDROOMPOOLCDTCHandler & EDROOMpPoolCDTCHandler );

		//!Copy constructor
		EDROOM_CTX_Top_0 (EDROOM_CTX_Top_0 &context);

	public:

		/**
		 * \brief Search Context transition 
		 * \param edroomCurrentTrans returns the context transition 

		 * \return true if context transition is found 

		 */
		bool EDROOMSearchContextTrans(TEDROOMTransId &edroomCurrentTrans);

		//! \brief Get new message from the Queue

		void EDROOMNewMessage()
		{ EDROOMcomponent.EDROOMNewMsg(); }

		/**
		 * \brief Get and Clear the Error Flags 
		 * \return the error flags  

		 */
		 TEDROOMUInt32 GetAndClearErrorFlags(){ return EDROOMcomponent.GetAndClearErrorFlags();}

		// User-defined Functions

		/**
		 * \brief  
		 */
		void	FProgNextTCExec();

		/**
		 * \brief  
		 */
		void	FSendDroneTC();

		/**
		 * \brief  
		 */
		void	FStartFlightPlan();

		/**
		 * \brief  
		 */
		void	FStartFligthPlan();

		/**
		 * \brief  
		 */
		void	FUTInvokeSetUp();

		/**
		 * \brief  
		 */
		bool	GPendingTCs();

	};

	// ***********************************************************************

	// class EDROOM_SUB_Top_0

	// ***********************************************************************



	class EDROOM_SUB_Top_0 : public EDROOM_CTX_Top_0 {

	protected:



		//!current state identifier
		EDROOM_CTX_Top_0::TEDROOMStateID edroomCurrentState;

		//!next state identifier
		EDROOM_CTX_Top_0::TEDROOMStateID edroomNextState;

		//!Variables
		TEDROOMUInt8 VTCCounter;


		// Pools**************************************************
		CEDROOMPOOLCDDroneConfig	EDROOMPoolCDDroneConfig;
		CEDROOMPOOLCDTCHandler	EDROOMPoolCDTCHandler;


	public:

		//! Constructor
		EDROOM_SUB_Top_0 (CCDroneMngTester &act, CEDROOMMemory *pEDROOMMemory  );


		//! Top Context Behaviour 

		void EDROOMBehaviour();

		//!Top Context Init
		void EDROOMInit();

		//! Initial substate arrival
		TEDROOMTransId EDROOMIArrival();

		// ***********************************************************************

		// Leaf SubState DroneReady

		// ***********************************************************************



		TEDROOMTransId EDROOMDroneReadyArrival();

		// ***********************************************************************

		// Leaf SubState DroneInFlightPlan

		// ***********************************************************************



		TEDROOMTransId EDROOMDroneInFlightPlanArrival();

	};

protected:

	//!Top State
	EDROOM_SUB_Top_0 edroomTopState;



};
#endif
