#ifndef UT_CCDRONEMNG_H_
#define UT_CCDRONEMNG_H_

//******************************************************************************
// EDROOM Service Library

#define _EDROOM_IS_EMBEDDED_

#include <public/edroomsl_iface_v1.h>

//******************************************************************************
// Required software interfaces

#include <public/pus_services_iface_v1.h>


/**
 * \class   UT_CCDroneMng
 *
 */
class UT_CCDroneMng: public CEDROOMComponent {

public:

	/**
	 * \enum TEDROOMUT_CCDroneMngSignal
	 * \brief Component Signal Enum Type
	 *
	 */
	 enum TEDROOMUT_CCDroneMngSignal { EDROOMSignalTimeout, 
							EDROOMSignalDestroy, 
							SStartFlightPlan };

	/**
	 * \class UT_CCDroneMng::CEDROOMMemory
	 * \brief Component Memory
	 *
	 */
	class CEDROOMMemory: public CEDROOMComponentMemory{

		private:

			//!Array of Message Queue Heads, one for each priority
			CEDROOMQueue::CQueueHead QueueHeads[EDROOMprioMINIMUM+1];

			//************ Component Timing Service Memory************

			//!Component Timing Service Timer Info Memory
			CEDROOMTimerInfo TimerInf[5];
			//!Component Timing Service Timer Info Marks Memory
			bool TimerInfMarks[5];
			//!Component Timing Service TimeOut Messages Memory
			CEDROOMTimeOutMessage TimeOutMsgs[5];
			//!Component Timing Service TimeOut Messages Marks Memory
			bool TimeOutMsgsMarks[5];

		public: 

			//!Component Timing Service Memory Object
			CEDROOMTimingMemory TimingMemory;



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


	// ********************************************************************
	// ********************  Timing Service Interface *********************
	// ********************************************************************

	//! Timing Service Access Point. It is common to all timing ports.
	CEDROOMTimingSAP	 EDROOMtimingSAP;


	//! WatchDogTimer Timing Port
	CEDROOMTimingInterface	WatchDogTimer;
	//! UTTimerCtrl Timing Port
	CEDROOMTimingInterface	UTTimerCtrl;




	// *************************************************************************
	// **************************** Frame Service Methods	********************
	// *************************************************************************



	//! Constructor
	UT_CCDroneMng(TEDROOMComponentID id, TEDROOMUInt32 roomNumMaxMens, TEDROOMPriority roomtaskPrio, 
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
	 * \enum TEDROOMUT_CCDroneMngSignal
	 * \brief Component Signal Enum Type
	 *
	 */
	enum TEDROOMUT_CCDroneMngSignal { EDROOMSignalTimeout,
		EDROOMSignalDestroy,
		SStartFlightPlan };


		friend class UT_CCDroneMng;

		//!component reference
		UT_CCDroneMng &EDROOMcomponent;

		//!Current message pointer reference
		CEDROOMMessage * &Msg;

		//!Synchronous message back pointer reference
		CEDROOMMessage * &MsgBack;

		//!Component ports
		CEDROOMInterface & TesterCtrl;
		CEDROOMTimingInterface & WatchDogTimer;
		CEDROOMTimingInterface & UTTimerCtrl;


		//! State Identifiers
		enum TEDROOMStateID{I,
			WaitEndTest,
			CheckUTTrace,
			WaitStartFlightPlan};

		//!Transition Identifiers
		enum TEDROOMTransitionID{CheckEnd,
			CheckEnd_EndTest,
			CheckEnd_ProgNextTimer,
			WatchDog,
			Init,
			StarFlightPlan,
			EDROOMMemoryTrans };

		//!Constants
		const TEDROOMUInt16 CEndTest;


		//!Variables
		TEDROOMUInt8 &VCheckTimes;




		//!Constructor
		EDROOM_CTX_Top_0 (UT_CCDroneMng &act,
				TEDROOMUInt8 & EDROOMpVarVCheckTimes );

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
		void	FCheckUTLogs();

		/**
		 * \brief  
		 */
		void	FNextCheck();

		/**
		 * \brief  
		 */
		void	FProgWaitEnd();

		/**
		 * \brief  
		 */
		void	FProgWatchDog();

		/**
		 * \brief  
		 */
		bool	GEndTest();

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
		TEDROOMUInt8 VCheckTimes;




	public:

		//! Constructor
		EDROOM_SUB_Top_0 (UT_CCDroneMng &act );


		//! Top Context Behaviour 

		void EDROOMBehaviour();

		//!Top Context Init
		void EDROOMInit();

		//! Initial substate arrival
		TEDROOMTransId EDROOMIArrival();

		// ***********************************************************************

		// Leaf SubState WaitEndTest

		// ***********************************************************************



		TEDROOMTransId EDROOMWaitEndTestArrival();

		// ***********************************************************************

		// Leaf SubState CheckUTTrace

		// ***********************************************************************



		TEDROOMTransId EDROOMCheckUTTraceArrival();

		// ***********************************************************************

		// Leaf SubState WaitStartFlightPlan

		// ***********************************************************************



		TEDROOMTransId EDROOMWaitStartFlightPlanArrival();

	};

protected:

	//!Top State
	EDROOM_SUB_Top_0 edroomTopState;



};
#endif
