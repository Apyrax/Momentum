#include <Subsystems/DriveBase.h>
//Drive Base Team: Gioia, Peter, and Kyle
DriveBase::DriveBase() :
 	 Subsystem("DriveBase")
{
	//Sets up Right Motors
	RightRearBaseMotor = new CANTalon(KRightMaster); //RightRearBase is the master Talon for the right side
	RightRearBaseMotor->SetSafetyEnabled(true);

	RightFrontBaseMotor = new CANTalon(2);
	RightFrontBaseMotor->SetControlMode(CANTalon::kFollower); //RightFrontBase is the follower to RightRearBase
	RightFrontBaseMotor->Set(KRightMaster);

	//Sets up Left motors
	//Left base motors are inverted
	LeftRearBaseMotor = new CANTalon(KLeftMaster); //LeftRearBase is the master Talon on the Left side
	LeftRearBaseMotor->SetSafetyEnabled(true);
	LeftRearBaseMotor->SetInverted(true);

	LeftFrontBaseMotor = new CANTalon(4);
	LeftFrontBaseMotor->SetControlMode(CANTalon::kFollower); //LeftFrontBase is the follower to the LeftRearBase
	LeftFrontBaseMotor->Set(KLeftMaster);
	LeftFrontBaseMotor->SetInverted(true);

	//Solenoids
	LeftBaseSolenoid = new DoubleSolenoid(0, 1);
	RightBaseSolenoid = new DoubleSolenoid(2, 3);
	RightCollectorSolenoid = new Solenoid(7);
	LeftCollectorSolenoid = new Solenoid (6);
	RatchetSolenoid = new Solenoid(5);

	//Ultrasonic
	BaseUltrasonic = new Ultrasonic(1,1);
	BaseUltrasonic->SetAutomaticMode(true);
}

void DriveBase::InitDefaultCommand()
{
	//SetDefaultCommand(new DriveWithJoysticks());
	//Sets the default to drive with joysticks when robot is turned on
}
void DriveBase::TankDrive()
{

}
void DriveBase::DriveForward(float distance, float speed)
{

}
void DriveBase::DriveBackward()
{

}
void DriveBase::BaseTurnLeft()
{

}
void DriveBase::BaseTurnRight()
{

}
void DriveBase::StopBase()
{
	RightRearBaseMotor->Set(0);
	LeftRearBaseMotor->Set(0);
}
void DriveBase::UpShiftBase()
{
	LeftBaseSolenoid->Set(DoubleSolenoid::kReverse);
	RightBaseSolenoid->Set(DoubleSolenoid::kReverse);
}
void DriveBase::DownShiftBase()
{
	LeftBaseSolenoid->Set(DoubleSolenoid::kForward);
	RightBaseSolenoid->Set(DoubleSolenoid::kForward);
}
void DriveBase::ToggleShift()
{
	if(LeftBaseSolenoid->Get() != DoubleSolenoid::kForward && RightBaseSolenoid->Get() != DoubleSolenoid::kForward)
	{
		UpShiftBase();
	}
	else
	{
		DownShiftBase();
	}
}
void DriveBase::ShiftBaseToCollector()
{
	LeftCollectorSolenoid->Set(DoubleSolenoid::kForward);
	RightCollectorSolenoid->Set(DoubleSolenoid::kForward);
}
void DriveBase::ShiftCollectorToBase()
{
	LeftCollectorSolenoid->Set(DoubleSolenoid::kReverse);
	RightCollectorSolenoid->Set(DoubleSolenoid::kReverse);
}
void DriveBase::EngageRatchet()
{
	RatchetSolenoid->Set(DoubleSolenoid::kForward);
}
void DriveBase::DisengageRatchet()
{
	RatchetSolenoid->Set(DoubleSolenoid::kReverse);
}

void DriveBase::InitDefaultCommandForUltrasonic()
{
	bool IsEnabled = true;
}

void DriveBase::GetDistance()
{
	DistanceToGearCollector = BaseUltrasonic->GetRangeMM();
}


bool DriveBase::IsUltrasonicRangeValid()
{
	whatIsRange = BaseUltrasonic->IsRangeValid();
	SmartDashboard::PutNumber("UltrasonicInRange", (bool) whatIsRange);
}
