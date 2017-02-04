#include <Subsystems/Collector.h>

Collector::Collector() :

Subsystem("CollectorSubsystem")
{
	collectorCIM = new CANTalon(1);
}

void Collector::InitDefaultCommand()
{

}

void Collector::CollectBallIntoStorage() //This function makes the collector collect the balls into the storage.
{
	collectorCIM->Set(KCollectorSpeedForward);
}

void Collector::DispenseBallOutOfStorage() //This function makes the collector dispense the balls out of the storage.
{
	collectorCIM->Set(KCollectorSpeedForward);
}

void Collector::StopCollector() //This function makes the collector stop moving
{
	collectorCIM->Set(KCollectorSpeedStop);
}