#include "processor.h"

PROCESSOR_ModeType u8_SVCSwitchValue;

void PROCESSOR_switchMode(PROCESSOR_ModeType Mode)
{
    /* TODO use Svc assembly instruction to switch to handler mode*/
    u8_SVCSwitchValue=Mode;
    SVCALL();

}

/*TODO: Put the following function address in Vector table */
void PROCESSOR_SvcHandler(void)
{
    /*TODO use TMPL bit field in CONTROL Register to switch between
     * privilege and non-privilege modes.See page(88) */
    switch(u8_SVCSwitchValue)
    {
        case PROCESSOR_ModePrivilege:
            __asm(" MOV  R0, #1\n");
            __asm(" MSR  CONTROL, R0\n");
            break;
        case PROCESSOR_ModeNonPrivilege:
            __asm(" MOV  R0, #0\n");
            __asm(" MSR  CONTROL, R0\n");
            break;
        default:
            break;
    }


    return ;
}

void PROCESSOR_enableGlobalInt(void)
{
    PROCESSOR_switchMode(PROCESSOR_ModePrivilege);
    __asm("    cpsie   i\n");
    PROCESSOR_switchMode(PROCESSOR_ModeNonPrivilege);
}

void PROCESSOR_disableGlobalInt(void)
{
    PROCESSOR_switchMode(PROCESSOR_ModePrivilege);
    __asm("    cpsid   i\n");
    PROCESSOR_switchMode(PROCESSOR_ModeNonPrivilege);
}
