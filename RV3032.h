#ifndef RV3032_h
#define RV3032_h

#include <inttypes.h>

const uint8_t RV3032_ADDRESS = 0x51;


// Flags Masks to clear a specific flag with an AND logic operation
const uint8_t STOP  = 0b00000001;   // Mask to execute bit operations on Stop bit (STOP)
const uint8_t TE    = 0b00001000;   // Mask to execute bit operations on Periodic Countdown Timer bit (TE)
const uint8_t TIE   = 0b00010000;   // Mask to execute bit operations Timer Interrupt Enable bit (TIE)
const uint8_t AIE   = 0b00001000;   // Mask to execute bit operations Alarm Interrupt Enable bit (TIE)
const uint8_t AF    = 0b00001000;   // Mask to execute bit operations on bit Alarm Flag (AF)
const uint8_t TF    = 0b00010000;   // Mask to execute bit operations on periodic countdown Timer Flag (TF)
const uint8_t AE_M  = 0b10000000;   // Mask to execute bit operations on Minutes Alarm Enable bit (AE_M) 
const uint8_t AE_H  = 0b10000000;   // Mask to execute bit operations on Minutes Alarm Enable bit (AE_H) 
const uint8_t AE_D  = 0b10000000;   // Mask to execute bit operations on Minutes Alarm Enable bit (AE_D) 

// EEPROM Configuration Bits
const uint8_t EERD    = 0b00000100;   // Memory refresh disable bit
const uint8_t EEBusy  = 0b00000100;   // Memory busy status bit
const uint8_t EEF     = 0b00001000;   // Previous write access was succesful

// EEPROM Commands
const uint8_t EEPROM_updateAll      = 0x11;   // Write "RTCC-RAM-mirrored-EEPROM" into "RTCC-EEPROM"
const uint8_t EEPROM_refreshAll     = 0x12;   // Mirror "RTCC-EEPROM" into "RTCC-RAM-mirrored-EEPROM"
const uint8_t EEPROM_writeRegister  = 0x21;   // Write one single "RTCC-EEPROM" Register (EEDATA --> "RTCC-EEPROM" register)
const uint8_t EEPROM_readRegister   = 0x22;   // Read one single "RTCC-EEPROM" Register ("RTCC-EEPROM" register --> EEDATA )

// RAM Registers
const uint8_t _100th_Seconds    = 0x00;
const uint8_t Seconds           = 0x01;
const uint8_t Minutes           = 0x02;
const uint8_t Hours             = 0x03;
const uint8_t Weekday           = 0x04;
const uint8_t Date              = 0x05;
const uint8_t Month             = 0x06;
const uint8_t Year              = 0x07;
const uint8_t MinutesAlarm      = 0x08;
const uint8_t HoursAlarm        = 0x09;
const uint8_t DateAlarm         = 0x0A;
const uint8_t TimerValue_0      = 0x0B;
const uint8_t TimerValue_1      = 0x0C;
const uint8_t Status            = 0x0D;
const uint8_t Temperature_LSBs  = 0x0E;
const uint8_t Temperature_MSBs  = 0x0F;
const uint8_t Control_1         = 0x10;
const uint8_t Control_2         = 0x11;
const uint8_t Control_3         = 0x12;
const uint8_t TimeStampCtrl     = 0x13;
const uint8_t ClockIntMask      = 0x14;
const uint8_t EVI_Control       = 0x15;
const uint8_t TLow_Threshold    = 0x16;
const uint8_t THigh_Threshold   = 0x17;
const uint8_t TS_TLow_Count     = 0x18;
const uint8_t TS_TLow_Seconds   = 0x19;
const uint8_t TS_TLow_Minutes   = 0x1A;
const uint8_t TS_TLow_Hours     = 0x1B;
const uint8_t TS_TLow_Date      = 0x1C;
const uint8_t TS_TLow_Month     = 0x1D;
const uint8_t TS_TLow_Year      = 0x1E;
const uint8_t TS_THigh_Count    = 0x1F;
const uint8_t TS_THigh_Seconds  = 0x20;
const uint8_t TS_THigh_Minutes  = 0x21;
const uint8_t TS_THigh_Hours    = 0x22;
const uint8_t TS_THigh_Date     = 0x23;
const uint8_t TS_THigh_Month    = 0x24;
const uint8_t TS_THigh_Year     = 0x25;
const uint8_t TS_EVI_Count      = 0x26;
const uint8_t TS_EVI_100th_Sec  = 0x27;
const uint8_t TS_EVI_Seconds    = 0x28;
const uint8_t TS_EVI_Minutes    = 0x29;
const uint8_t TS_EVI_Hours      = 0x2A;
const uint8_t TS_EVI_Date       = 0x2B;
const uint8_t TS_EVI_Month      = 0x2C;
const uint8_t TS_EVI_Year       = 0x2D;
const uint8_t Password_0        = 0x39;
const uint8_t Password_1        = 0x3A;
const uint8_t Password_2        = 0x3B;
const uint8_t Password_3        = 0x3C;
const uint8_t EE_Address        = 0x3D;
const uint8_t EE_Data           = 0x3E;
const uint8_t EE_Command        = 0x3F;

// EEPROM Mirrored Registers
const uint8_t EEPROM_PMU          = 0xC0;
const uint8_t EEPROM_Offset       = 0xC1;
const uint8_t EEPROM_CLKout_1     = 0xC2;
const uint8_t EEPROM_CLKout_2     = 0xC3;
const uint8_t EEPROM_TReference_0 = 0xC4;
const uint8_t EEPROM_TReference_1 = 0xC5;
const uint8_t EEPROM_Password_0   = 0xC6;
const uint8_t EEPROM_Password_1   = 0xC7;
const uint8_t EEPROM_Password_2   = 0xC8;
const uint8_t EEPROM_Password_3   = 0xC9;
const uint8_t EEPROM_PW_Enable    = 0xCA;

class RV3032
{
  public:
    struct time
    {
      uint8_t Sec, Min, Hour, Weekday, Day, Month;
      uint16_t Year;
    };
    
  public:
    RV3032();                                                                                           // Constructor

    void begin (void);                                                                                  // Prepares on the uC the I2C communication with the RV3032
    uint8_t stopRTCC (uint8_t RTCaddress);                                                              // Freezes RTCC time circuits
    uint8_t restartRTCC (uint8_t RTCaddress);                                                           // Resumes RTCC time circuits
    uint8_t readRTCCRegister (uint8_t RTCCaddress, uint8_t RTCCregister, uint8_t *RTCCRegisterContent);  // Read a single RTCC register
    uint8_t writeRTCCRegister (uint8_t RTCaddress, uint8_t RTCregister, uint8_t Data);                   // Write a single RTCC register
    uint8_t clearFlag (uint8_t RTCaddress, uint8_t Register, uint8_t flag);                             // Clear a specific flag in a register
    uint8_t setDate (uint8_t RTCaddress, uint16_t Year, uint8_t Month, uint8_t Day);                    // Set the RTCC's date
    uint8_t setTime (uint8_t RTCaddress, uint8_t Hour, uint8_t Min, uint8_t Sec);                       // Set the RTCC's time
    uint8_t getTimeDate (uint8_t RTCaddress, time *);                                                   // Reads RTC's time and date
    uint8_t setTimerNsec (uint8_t RTCCaddress, uint16_t Nsec);                                          // Countdown 'Nsec' (up to 4096 seconds --> ~68 min)
    uint8_t updateTimerNsec (uint8_t RTCCaddress, uint16_t Nsec);
    uint8_t setTimerNmin (uint8_t RTCCaddress, uint16_t Nmin);                                          // Countdown 'Nsec' (up to 4096 minutes --> ~68 hours)
    uint8_t updateTimerNmin (uint8_t RTCCaddress, uint16_t Nsec);
    uint8_t setAlarm (uint8_t RTCCaddress, uint8_t Hour, uint8_t Minute);                               // Set an alarm at a specific hour and minute
    uint8_t resetAlarm (uint8_t RTCCaddress);                                                           // Stop and Reset RTCC alarm
    uint8_t resetTimer (uint8_t RTCCaddress);                                                           // Stop and Reset RTCC counter

    uint8_t WriteAllRAMmirrorToEEPROM (uint8_t RTCCaddress);                                            // Writes all "local RAM-mirrored-EEPROM" to RTCC EEPROM 
    bool SetLocalEEPROMmirrorRegister (uint8_t RegisterName, uint8_t Value);                             // Writes Value in a specific "local RAM-mirrored-EEPROM" register

//    void EnableBatterySwitchover(void);                         // Activates battery switchover


  private:
    uint8_t EEPROMBuffer[11];  // Buffer for "local RAM-mirrored-EEPROM" registers (RTCC RAM Addresses from C0h to CAh)
    
    void parseTime(const char* timeStr, uint8_t &hour, uint8_t &minute);
    
    uint8_t bin2bcd(uint8_t val);                               // Transforms a number from binary to BCD format
    uint8_t bcd2bin(uint8_t val);                               // Transforms a number from BCD to binary format

  
};

#endif
