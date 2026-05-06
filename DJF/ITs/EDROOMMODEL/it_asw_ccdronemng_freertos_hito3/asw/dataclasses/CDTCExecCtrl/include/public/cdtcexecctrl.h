#ifndef FCDTCExecCtrlH
#define FCDTCExecCtrlH


//TODO 11 Part 1 Add ExecCtrlDroneTC as a new type of TC in the enum TTCExecCtrl
enum TTCExecCtrl {
	ExecCtrlPrioTC, ExecCtrlReboot, ExecCtrlHK_FDIRTC, ExecCtrlBKGTC, ExecCtrlDroneTC
};

class CDTCExecCtrl{
	
	friend class CDTCHandler;

	protected:
	
		enum TTCExecCtrl mExecCtrl;

	public:

	/**
	 * \brief Check if it is a reboot telecommand
	 *
	 * \return true if it is a reboot telecommand
	 *
	 */
	bool IsRebootTC(){return (ExecCtrlReboot==mExecCtrl);}

	/**
	 * \brief Check if it is a priority telecommand
	 *
	 * \return true if it is a priority telecommand
	 *
	 */

	bool IsPrioTC(){return (ExecCtrlPrioTC==mExecCtrl);}

	/**
	 * \brief Check if is a HK_FDIR telecommand
	 *
	 * \return true if it is a HK_FDIR telecommand
	 *
	 */
	bool IsHK_FDIRTC(){return (ExecCtrlHK_FDIRTC==mExecCtrl);}


	/**
	 * \brief Check if is a Background telecommand
	 *
	 * \return true if it is a Background telecommand
	 *
	 */
	bool IsBKGTC() {return (ExecCtrlBKGTC==mExecCtrl);};

	//TODO 11 Part 2 Define the codeo of IsDroneTC() to TTCExecCtrl

	/**
	 * \brief Check if is a Drone telecommand
	 *
	 * \return true if it is a Drone telecommand
	 *
	 */
	bool IsDroneTC() {  };
	
};

//TODO 11 Part 3 Copy this file in the EDROOM Model Data Class CDTCExecCtrl

#endif
