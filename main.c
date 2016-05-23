/*
 * main.c
 */

#include <stdbool.h>
#include <stdint.h>

#include "datetime/datetime.h"
#include "scheduling/scheduling.h"

#include "driverlib/sysctl.h"
#include "driverlib/systick.h"

uint64_t millis;

uint32_t _year, _month, _day, _hour, _minute, _second;
uint16_t percent;

void SysTickIntHandler()
{
	millis++;
}

void SysTickBegin()
{
    //
    // Set up the period for the SysTick timer.  The SysTick timer period will
    // be equal to the system clock / 10, resulting in a period of 100 ms.
    //
    SysTickPeriodSet(SysCtlClockGet() / 1000);

    //
    // Enable the SysTick Interrupt.
    //
    SysTickIntEnable();

    //
    // Enable SysTick.
    //
    SysTickEnable();
}

void main(void) {
	
	//
	// Set the clocking to run from the PLL at 80MHz
	//
	SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN |
			SYSCTL_XTAL_16MHZ);

	SysTickBegin();

	Schedule s;
	tmElements_t tm;


	setTimeFromParts(2016,5,22,05,00,00);


	s.StartTime = getTimeFromParts(2016,5,22,01,00,00);


	createScheduleFromComponents(&s, schID1st, schIRlast, schIWsunday, schIMofThisMonth, 00, 00, schAPnull, 0, schRFnull);
	breakTime(s.EndTime, &tm);

	createScheduleFromComponents(&s, schID1st, schIRlast, schIWmonday, schIMofThisMonth, 00, 00, schAPnull, 0, schRFnull);
	breakTime(s.EndTime, &tm);

	createScheduleFromComponents(&s, schID1st, schIRlast, schIWwednesday, schIMofThisMonth, 00, 00, schAPnull, 0, schRFnull);
	breakTime(s.EndTime, &tm);

	createScheduleFromComponents(&s, schID2nd, schIRlast, schIWsunday, schIMofThisMonth, 00, 00, schAPnull, 0, schRFnull);
	breakTime(s.EndTime, &tm);

	createScheduleFromComponents(&s, schID2nd, schIRlast, schIWmonday, schIMofThisMonth, 00, 00, schAPnull, 0, schRFnull);
	breakTime(s.EndTime, &tm);

	createScheduleFromComponents(&s, schID2nd, schIRlast, schIWwednesday, schIMofThisMonth, 00, 00, schAPnull, 0, schRFnull);
	breakTime(s.EndTime, &tm);

	createScheduleFromComponents(&s, schID4th, schIRlast, schIWsunday, schIMofThisMonth, 00, 00, schAPnull, 0, schRFnull);
	breakTime(s.EndTime, &tm);

	createScheduleFromComponents(&s, schID4th, schIRlast, schIWmonday, schIMofThisMonth, 00, 00, schAPnull, 0, schRFnull);
	breakTime(s.EndTime, &tm);

	createScheduleFromComponents(&s, schID4th, schIRlast, schIWwednesday, schIMofThisMonth, 00, 00, schAPnull, 0, schRFnull);
	breakTime(s.EndTime, &tm);

	createScheduleFromComponents(&s, schID5th, schIRlast, schIWsunday, schIMofThisMonth, 00, 00, schAPnull, 0, schRFnull);
	breakTime(s.EndTime, &tm);

	createScheduleFromComponents(&s, schID5th, schIRlast, schIWmonday, schIMofThisMonth, 00, 00, schAPnull, 0, schRFnull);
	breakTime(s.EndTime, &tm);

	createScheduleFromComponents(&s, schID5th, schIRlast, schIWwednesday, schIMofThisMonth, 00, 00, schAPnull, 0, schRFnull);
	breakTime(s.EndTime, &tm);

	while(1)
	{
	}
}
