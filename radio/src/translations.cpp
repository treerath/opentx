/*
 * Copyright (C) OpenTX
 *
 * Based on code named
 *   th9x - http://code.google.com/p/th9x
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "opentx.h"

#define ISTR(x) LEN_##x TR_##x

// The non-0-terminated-strings
const char STR_OPEN9X[]  =
    ISTR(OFFON)
    ISTR(MMMINV)
    ISTR(NCHANNELS)
#if !defined(GRAPHICS)
    ISTR(VBEEPLEN)
#endif
    ISTR(VBEEPMODE)
#if defined(ROTARY_ENCODERS)
    ISTR(VRENAVIG)
#endif
#if defined(ROTARY_ENCODER_NAVIGATION)
    ISTR(VRENCODERS)
#endif
    ISTR(TRNMODE)
    ISTR(TRNCHN)
#if defined(PCBFRSKY)
    ISTR(UART3MODES)
    ISTR(SWTYPES)
    ISTR(POTTYPES)
    ISTR(SLIDERTYPES)
#endif
    ISTR(VTRIMINC)
    ISTR(VDISPLAYTRIMS)
    ISTR(RETA123)
    ISTR(VPROTOS)
    ISTR(POSNEG)
#if defined(PCBSKY9X) && defined(REVX)
    ISTR(VOUTPUT_TYPE)
#endif
    ISTR(VBLMODE)
    ISTR(VCURVEFUNC)
    ISTR(VMLTPX)
    ISTR(VMLTPX2)
    ISTR(VMIXTRIMS)
    ISTR(VCSWFUNC)
    ISTR(VFSWFUNC)
    ISTR(VFSWRESET)
    ISTR(FUNCSOUNDS)
    ISTR(VTELEMUNIT)
    ISTR(VALARM)
    ISTR(VALARMFN)
    ISTR(VTELPROTO)
    ISTR(GPSFORMAT)
    ISTR(AMPSRC)
    ISTR(VARIOSRC)
    ISTR(VTELEMSCREENTYPE)
#if defined(HELI)
    ISTR(VSWASHTYPE)
#endif
    ISTR(VKEYS)
    ISTR(VSWITCHES)
    ISTR(VSRCRAW)
#if defined(TRANSLATIONS_CZ)
    ISTR(INPUTNAMES)
#endif
    ISTR(VTMRMODES)
    ISTR(DATETIME)
    ISTR(VPERSISTENT)
    ISTR(VLCD)
    ISTR(VUNITSSYSTEM)
    ISTR(VBEEPCOUNTDOWN)
    ISTR(COUNTDOWNVALUES)
    ISTR(VVARIOCENTER)
    ISTR(COUNTRYCODES)
    ISTR(USBMODES)
    ISTR(JACKMODES)
    ISTR(VFAILSAFE)
    ISTR(VTRAINERMODES)
    ISTR(MODULE_PROTOCOLS)
    ISTR(R9M_REGION)
    ISTR(R9MFLEX_FREQ)
    ISTR(R9M_FCC_POWER_VALUES)
    ISTR(R9M_LBT_POWER_VALUES)
    ISTR(TELEMETRY_PROTOCOLS)
    ISTR(XJT_PROTOCOLS)
    ISTR(DSM_PROTOCOLS)
#if defined(MULTIMODULE)
    ISTR(MULTI_PROTOCOLS)
#endif
    ISTR(VOLTSRC)
    ISTR(CURVE_TYPES)
    ISTR(VSENSORTYPES)
    ISTR(VFORMULAS)
    ISTR(VPREC)
    ISTR(VCELLINDEX)
#if defined(BLUETOOTH)
    ISTR(BLUETOOTH_MODES)
#endif
    ISTR(VANTENNATYPES)
    ;

// The 0-terminated-strings
const char STR_POPUPS_ENTER_EXIT[]  = TR_POPUPS_ENTER_EXIT;
const char STR_OK[]  = TR_OK;
#if !defined(OFS_EXIT)
  const char STR_EXIT[]  = TR_EXIT;
#endif
#if !defined(PCBHORUS)
  const char STR_MENUWHENDONE[]  = TR_MENUWHENDONE;
#endif
const char STR_FREE[]  = TR_FREE;
const char STR_DELETEMODEL[]  = TR_DELETEMODEL;
const char STR_COPYINGMODEL[]  = TR_COPYINGMODEL;
const char STR_MOVINGMODEL[]  = TR_MOVINGMODEL;
const char STR_LOADINGMODEL[]  = TR_LOADINGMODEL;
const char STR_BITMAP[]  = TR_BITMAP;
const char STR_TIMER[]  = TR_TIMER;
const char STR_ELIMITS[]  = TR_ELIMITS;
const char STR_ETRIMS[]  = TR_ETRIMS;
const char STR_TRIMINC[]  = TR_TRIMINC;
const char STR_DISPLAY_TRIMS[]  = TR_DISPLAY_TRIMS;
const char STR_TTRACE[]  = TR_TTRACE;
const char STR_TTRIM[]  = TR_TTRIM;
const char STR_BEEPCTR[]  = TR_BEEPCTR;
const char STR_USE_GLOBAL_FUNCS[]  = TR_USE_GLOBAL_FUNCS;
#if defined(PCBSKY9X) && defined(REVX)
  const char STR_OUTPUT_TYPE[]  = TR_OUTPUT_TYPE;
#endif
const char STR_PROTO[]  = TR_PROTO;
const char STR_PPMFRAME[]  = TR_PPMFRAME;
const char STR_REFRESHRATE[]  = TR_REFRESHRATE;
const char SSTR_WARN_BATTVOLTAGE[]  = STR_WARN_BATTVOLTAGE;
const char STR_MS[]  = TR_MS;
const char STR_FREQUENCY[]  = TR_FREQUENCY;
const char STR_SWITCH[]  = TR_SWITCH;
const char STR_TRIMS[]  = TR_TRIMS;
const char STR_FADEIN[]  = TR_FADEIN;
const char STR_FADEOUT[]  = TR_FADEOUT;
const char STR_DEFAULT[]  = TR_DEFAULT;
const char STR_CHECKTRIMS[]  = TR_CHECKTRIMS;
#ifdef HELI
const char STR_SWASHTYPE[]  = TR_SWASHTYPE;
const char STR_COLLECTIVE[]  = TR_COLLECTIVE;
const char STR_AILERON[]  = TR_AILERON;
const char STR_ELEVATOR[]  = TR_ELEVATOR;
const char STR_SWASHRING[]  = TR_SWASHRING;
const char STR_ELEDIRECTION[]  = TR_ELEDIRECTION;
const char STR_AILDIRECTION[]  = TR_AILDIRECTION;
const char STR_COLDIRECTION[]  = TR_COLDIRECTION;
#endif

#if defined(AUDIO) && defined(BUZZER)
const char STR_SPEAKER[]  = TR_SPEAKER;
const char STR_BUZZER[]  = TR_BUZZER;
#endif
const char STR_NOFREEEXPO[]  = TR_NOFREEEXPO;
const char STR_NOFREEMIXER[]  = TR_NOFREEMIXER;
const char STR_SOURCE[]  = TR_SOURCE;
const char STR_WEIGHT[]  = TR_WEIGHT;
const char STR_EXPO[]  = TR_EXPO;
const char STR_SIDE[]  = TR_SIDE;
const char STR_DIFFERENTIAL[]  = TR_DIFFERENTIAL;
const char STR_OFFSET[]  = TR_OFFSET;
const char STR_TRIM[]  = TR_TRIM;
const char STR_DREX[]  = TR_DREX;
const char STR_CURVE[]  = TR_CURVE;
const char STR_FLMODE[]  = TR_FLMODE;
const char STR_MIXWARNING[]  = TR_MIXWARNING;
const char STR_OFF[]  = TR_OFF;
const char STR_MULTPX[]  = TR_MULTPX;
const char STR_DELAYDOWN[]  = TR_DELAYDOWN;
const char STR_DELAYUP[]  = TR_DELAYUP;
const char STR_SLOWDOWN[]  = TR_SLOWDOWN;
const char STR_SLOWUP[]  = TR_SLOWUP;
const char STR_MIXER[]  = TR_MIXER;
const char STR_CV[]  = TR_CV;
const char STR_GV[]  = TR_GV;
const char STR_ACHANNEL[]  = TR_ACHANNEL;
const char STR_RANGE[]  = TR_RANGE;
const char STR_CENTER[]  = TR_CENTER;
const char STR_BAR[]  = TR_BAR;
const char STR_ALARM[]  = TR_ALARM;
const char STR_USRDATA[]  = TR_USRDATA;
const char STR_BLADES[]  = TR_BLADES;
const char STR_SCREEN[]  = TR_SCREEN;
const char STR_SOUND_LABEL[]  = TR_SOUND_LABEL;
const char STR_LENGTH[]  = TR_LENGTH;
const char STR_BEEP_LENGTH[]  = TR_BEEP_LENGTH;
#if defined(AUDIO)
const char STR_SPKRPITCH[]  = TR_SPKRPITCH;
#endif
#if defined(HAPTIC)
const char STR_HAPTIC_LABEL[]  = TR_HAPTIC_LABEL;
const char STR_HAPTICSTRENGTH[]  = TR_HAPTICSTRENGTH;
const char STR_GYRO_LABEL[]  = TR_GYRO_LABEL;
const char STR_GYRO_OFFSET[]  = TR_GYRO_OFFSET;
const char STR_GYRO_MAX[]  = TR_GYRO_MAX;
#endif
const char STR_CONTRAST[]  = TR_CONTRAST;
const char STR_ALARMS_LABEL[]  = TR_ALARMS_LABEL;
const char STR_BATTERY_RANGE[]  = TR_BATTERY_RANGE;
const char STR_BATTERYWARNING[]  = TR_BATTERYWARNING;
const char STR_INACTIVITYALARM[]  = TR_INACTIVITYALARM;
const char STR_MEMORYWARNING[]  = TR_MEMORYWARNING;
const char STR_ALARMWARNING[]  = TR_ALARMWARNING;
const char STR_RSSISHUTDOWNALARM[]  = TR_RSSISHUTDOWNALARM;
const char STR_MODEL_STILL_POWERED[]  = TR_MODEL_STILL_POWERED;
const char STR_MODEL_SHUTDOWN[]  = TR_MODEL_SHUTDOWN;
const char STR_PRESS_ENTER_TO_CONFIRM[]  = TR_PRESS_ENTER_TO_CONFIRM;
#if defined(ROTARY_ENCODERS)
const char STR_RENAVIG[]  = TR_RENAVIG;
#endif
const char STR_THROTTLEREVERSE[]  = TR_THROTTLEREVERSE;
const char STR_BEEPCOUNTDOWN[]  = TR_BEEPCOUNTDOWN;
const char STR_PERSISTENT[]  = TR_PERSISTENT;
const char STR_BACKLIGHT_LABEL[]  = TR_BACKLIGHT_LABEL;
const char STR_BLDELAY[]  = TR_BLDELAY;
const char STR_BL_MODE_DUR[]  = TR_BL_MODE_DUR;

#if defined(PWM_BACKLIGHT) || defined(COLORLCD)
const char STR_BLONBRIGHTNESS[]  = TR_BLONBRIGHTNESS;
const char STR_BLOFFBRIGHTNESS[]  = TR_BLOFFBRIGHTNESS;
#endif

const char STR_SPLASHSCREEN[]  = TR_SPLASHSCREEN;
const char STR_THROTTLEWARNING[]  = TR_THROTTLEWARNING;
const char STR_SWITCHWARNING[]  = TR_SWITCHWARNING;
const char STR_POTWARNINGSTATE[]  = TR_POTWARNINGSTATE;
const char STR_POTWARNING[]  = TR_POTWARNING;
const char STR_SLIDERWARNING[]  = TR_SLIDERWARNING;
#ifdef TELEMETRY_FRSKY
const char STR_TIMEZONE[]  = TR_TIMEZONE;
const char STR_ADJUST_RTC[]  = TR_ADJUST_RTC;
const char STR_GPS[]  = TR_GPS;
const char STR_GPSCOORD[]  = TR_GPSCOORD;
const char STR_VARIO[]  = TR_VARIO;
const char STR_PITCH_AT_ZERO[]  = TR_PITCH_AT_ZERO;
const char STR_PITCH_AT_MAX[]  = TR_PITCH_AT_MAX;
const char STR_REPEAT_AT_ZERO[]  = TR_REPEAT_AT_ZERO;
#endif
const char STR_RXCHANNELORD[]  = TR_RXCHANNELORD;
const char STR_STICKS[]  = TR_STICKS;
const char STR_POTS[]  = TR_POTS;
const char STR_SWITCHES[]  = TR_SWITCHES;
const char STR_SWITCHES_DELAY[]  = TR_SWITCHES_DELAY;
const char STR_SLAVE[]  = TR_SLAVE;
const char STR_MODESRC[]  = TR_MODESRC;
const char STR_MULTIPLIER[]  = TR_MULTIPLIER;
const char STR_CAL[]  = TR_CAL;
const char STR_CALIBRATION[]  = TR_CALIBRATION;
const char STR_VTRIM[]  = TR_VTRIM;
const char STR_BG[]  = TR_BG;
const char STR_MENUTOSTART[]  = TR_MENUTOSTART;
const char STR_SETMIDPOINT[]  = TR_SETMIDPOINT;
const char STR_MOVESTICKSPOTS[]  = TR_MOVESTICKSPOTS;
#if defined(PCBHORUS)
const char STR_CALIB_DONE[]  = TR_CALIB_DONE;
#endif
const char STR_RXBATT[]  = TR_RXBATT;
const char STR_TX[]  = TR_TXnRX;
const char STR_ACCEL[]  = TR_ACCEL;
const char STR_NODATA[]  = TR_NODATA;
const char STR_TOTTM1TM2THRTHP[]  = TR_TOTTM1TM2THRTHP;
const char STR_TMR1LATMAXUS[]  = TR_TMR1LATMAXUS;
const char STR_TMR1LATMINUS[]  = TR_TMR1LATMINUS;
const char STR_TMR1JITTERUS[]  = TR_TMR1JITTERUS;
const char STR_TMIXMAXMS[]  = TR_TMIXMAXMS;
const char STR_FREESTACKMINB[]  = TR_FREESTACKMINB;
const char STR_MENUTORESET[]  = TR_MENUTORESET;
const char STR_PPM_TRAINER[]  = TR_PPM_TRAINER;
const char STR_CH[]  = TR_CH;
const char STR_MODEL[]  = TR_MODEL;
const char STR_FM[]  = TR_FM;
const char STR_MIX[]  = TR_MIX;
const char STR_ALERT[]  = TR_ALERT;
const char STR_PRESSANYKEYTOSKIP[]  = TR_PRESSANYKEYTOSKIP;
const char STR_THROTTLENOTIDLE[]  = TR_THROTTLENOTIDLE;
const char STR_ALARMSDISABLED[]  = TR_ALARMSDISABLED;
const char STR_PRESSANYKEY[]  = TR_PRESSANYKEY;
const char STR_TRIMS2OFFSETS[]  = TR_TRIMS2OFFSETS;
const char STR_OUTPUTS2FAILSAFE[]  = TR_OUTPUTS2FAILSAFE;
const char STR_MENURADIOSETUP[]  = TR_MENURADIOSETUP;

#if defined(EEPROM)
const char STR_BAD_RADIO_DATA[]  = TR_BADEEPROMDATA;
const char STR_STORAGE_FORMAT[]  = TR_EEPROMFORMATTING;
const char STR_STORAGE_WARNING[]  = TR_EEPROMWARN;
const char STR_EEPROM_CONVERTING[]  = TR_EEPROM_CONVERTING;
const char STR_EEPROMLOWMEM[]  = TR_EEPROMLOWMEM;
const char STR_EEPROMOVERFLOW[]  = TR_EEPROMOVERFLOW;
#else
const char STR_BAD_RADIO_DATA[]  = TR_BAD_RADIO_DATA;
const char STR_STORAGE_WARNING[]  = TR_STORAGE_WARNING;
const char STR_STORAGE_FORMAT[]  = TR_STORAGE_FORMAT;
#endif

const char STR_FAS_OFFSET[]  = TR_FAS_OFFSET;

const char STR_MENUDATEANDTIME[]  = TR_MENUDATEANDTIME;

const char STR_MENUTRAINER[]  = TR_MENUTRAINER;
const char STR_MENUSPECIALFUNCS[]  = TR_MENUSPECIALFUNCS;
const char STR_MENUVERSION[]  = TR_MENUVERSION;
const char STR_MENU_RADIO_SWITCHES[]  = TR_MENU_RADIO_SWITCHES;
const char STR_MENU_RADIO_ANALOGS[]  = TR_MENU_RADIO_ANALOGS;
const char STR_MENUCALIBRATION[]  = TR_MENUCALIBRATION;

const char STR_MENUMODELSEL[]  = TR_MENUMODELSEL;
const char STR_MENUSETUP[]  = TR_MENUSETUP;
const char STR_MENUFLIGHTMODE[]  = TR_MENUFLIGHTMODE;
const char STR_MENUFLIGHTMODES[]  = TR_MENUFLIGHTMODES;

#ifdef HELI
const char STR_MENUHELISETUP[]  = TR_MENUHELISETUP;
#endif

const char STR_MENUINPUTS[]  = TR_MENUINPUTS;
const char STR_MENULIMITS[]  = TR_MENULIMITS;
const char STR_MENUCURVES[]  = TR_MENUCURVES;
const char STR_MENUCURVE[]  = TR_MENUCURVE;
const char STR_MENULOGICALSWITCH[]  = TR_MENULOGICALSWITCH;
const char STR_MENULOGICALSWITCHES[]  = TR_MENULOGICALSWITCHES;
const char STR_MENUCUSTOMFUNC[]  = TR_MENUCUSTOMFUNC;

#if defined(LUA)
const char STR_MENUCUSTOMSCRIPTS[]  = TR_MENUCUSTOMSCRIPTS;
#endif

#if defined(TELEMETRY_FRSKY)
const char STR_MENUTELEMETRY[]  = TR_MENUTELEMETRY;
const char STR_LIMIT[]  = TR_LIMIT;
#endif


const char STR_MENUSTAT[]  = TR_MENUSTAT;
const char STR_MENUDEBUG[]  = TR_MENUDEBUG;
const char * const STR_MONITOR_CHANNELS[] = { TR_MONITOR_CHANNELS1, TR_MONITOR_CHANNELS2, TR_MONITOR_CHANNELS3, TR_MONITOR_CHANNELS4 };
const char STR_MONITOR_SWITCHES[]  = TR_MONITOR_SWITCHES;
const char STR_MONITOR_OUTPUT_DESC[]  = TR_MONITOR_OUTPUT_DESC;
const char STR_MONITOR_MIXER_DESC[]  = TR_MONITOR_MIXER_DESC;
const char STR_MENUGLOBALVARS[]  = TR_MENUGLOBALVARS;

#if defined(DSM2) || defined(PXX)
const char STR_RECEIVER_NUM[]  = TR_RECEIVER_NUM;
const char STR_RECEIVER[]  = TR_RECEIVER;
const char STR_REBIND[]  = TR_REBIND;
const char STR_REG_OK[]  = TR_REG_OK;
const char STR_BIND_OK[]  = TR_BIND_OK;
#endif

const char STR_SYNCMENU[]  = TR_SYNCMENU;
const char STR_INTERNALRF[]  = TR_INTERNALRF;
const char STR_EXTERNALRF[]  = TR_EXTERNALRF;
const char STR_MODULE_TELEMETRY[]  = TR_MODULE_TELEMETRY;
const char STR_MODULE_TELEM_ON[]  = TR_MODULE_TELEM_ON;
const char STR_COUNTRYCODE[]  = TR_COUNTRYCODE;
const char STR_USBMODE[]  = TR_USBMODE;
const char STR_JACKMODE[]  = TR_JACKMODE;
const char STR_FAILSAFE[]  = TR_FAILSAFE;
const char STR_FAILSAFESET[]  = TR_FAILSAFESET;
const char STR_REG_ID[]  = TR_REG_ID;
const char STR_OWNER_ID[]  = TR_OWNER_ID;
const char STR_PINMAPSET[]  = TR_PINMAPSET;
const char STR_HOLD[]  = TR_HOLD;
const char STR_NONE[]  = TR_NONE;
const char STR_MENUSENSOR[]  = TR_MENUSENSOR;
const char STR_POWERMETER_PEAK[]  = TR_POWERMETER_PEAK;
const char STR_POWERMETER_POWER[]  = TR_POWERMETER_POWER;
const char STR_POWERMETER_ATTN[]  = TR_POWERMETER_ATTN;
const char STR_POWERMETER_FREQ[]  = TR_POWERMETER_FREQ;
const char STR_MENUTOOLS[]  = TR_MENUTOOLS;
const char STR_TURN_OFF_RECEIVER          []  = TR_TURN_OFF_RECEIVER          ;
const char STR_STOPPING              []  = TR_STOPPING              ;
const char STR_MENU_SPECTRUM_ANALYSER[]  = TR_MENU_SPECTRUM_ANALYSER;
const char STR_MENU_POWER_METER[]  = TR_MENU_POWER_METER;
const char STR_SENSOR[]  = TR_SENSOR;
const char STR_DISABLE_INTERNAL[]  = TR_DISABLE_INTERNAL;

const char STR_INVERT_THR[]  = TR_INVERT_THR;
const char STR_AND_SWITCH[]  = TR_AND_SWITCH;
const char STR_SF[]  = TR_SF;
const char STR_GF[]  = TR_GF;

const char STR_MINRSSI[]  = TR_MINRSSI;
const char STR_LATITUDE[]  = TR_LATITUDE;
const char STR_LONGITUDE[]  = TR_LONGITUDE;

const char STR_SHUTDOWN[]  = TR_SHUTDOWN;
const char STR_SAVEMODEL[]  = TR_SAVEMODEL;

#if defined(PCBX9E)
const char STR_POWEROFF[]  = TR_POWEROFF;
#endif

const char STR_BATT_CALIB[]  = TR_BATT_CALIB;

const char STR_VOLTAGE[]  = TR_VOLTAGE;
const char STR_CURRENT[]  = TR_CURRENT;

const char STR_CURRENT_CALIB[]  = TR_CURRENT_CALIB;
const char STR_UNITSSYSTEM[]    = TR_UNITSSYSTEM;
const char STR_VOICELANG[]  = TR_VOICELANG;
const char STR_MODELIDUSED[]  = TR_MODELIDUSED;
const char STR_BEEP_VOLUME[]  = INDENT TR_BEEP_VOLUME;
const char STR_WAV_VOLUME[]  = INDENT TR_WAV_VOLUME;
const char STR_BG_VOLUME[]  = INDENT TR_BG_VOLUME;
const char STR_PERSISTENT_MAH[]  = TR_PERSISTENT_MAH;

const char STR_SELECT_MODEL[]  = TR_SELECT_MODEL;
const char STR_CREATE_CATEGORY[]  = TR_CREATE_CATEGORY;
const char STR_RENAME_CATEGORY[]  = TR_RENAME_CATEGORY;
const char STR_DELETE_CATEGORY[]  = TR_DELETE_CATEGORY;
const char STR_CREATE_MODEL[]  = TR_CREATE_MODEL;
const char STR_DUPLICATE_MODEL[]  = TR_DUPLICATE_MODEL;
const char STR_COPY_MODEL[]  = TR_COPY_MODEL;
const char STR_MOVE_MODEL[]  = TR_MOVE_MODEL;
const char STR_DELETE_MODEL[]  = TR_DELETE_MODEL;
const char STR_EDIT[]  = TR_EDIT;
const char STR_INSERT_BEFORE[]  = TR_INSERT_BEFORE;
const char STR_INSERT_AFTER[]  = TR_INSERT_AFTER;
const char STR_COPY[]  = TR_COPY;
const char STR_MOVE[]  = TR_MOVE;
const char STR_PASTE[]  = TR_PASTE;
const char STR_PASTE_AFTER[]  = TR_PASTE_AFTER;
const char STR_PASTE_BEFORE[]  = TR_PASTE_BEFORE;
const char STR_INSERT[]  = TR_INSERT;
const char STR_DELETE[]  = TR_DELETE;
const char STR_RESET_FLIGHT[]  = TR_RESET_FLIGHT;
const char STR_RESET_TIMER1[]  = TR_RESET_TIMER1;
const char STR_RESET_TIMER2[]  = TR_RESET_TIMER2;
const char STR_RESET_TIMER3[]  = TR_RESET_TIMER3;
const char STR_RESET_TELEMETRY[]  = TR_RESET_TELEMETRY;
const char STR_STATISTICS[]  = TR_STATISTICS;
const char STR_ABOUT_US[]  = TR_ABOUT_US;
const char STR_USB_JOYSTICK[]  = TR_USB_JOYSTICK;
const char STR_USB_MASS_STORAGE[]  = TR_USB_MASS_STORAGE;
const char STR_USB_SERIAL[]  = TR_USB_SERIAL;
const char STR_SETUP_SCREENS[]  = TR_SETUP_SCREENS;
const char STR_MONITOR_SCREENS[]  = TR_MONITOR_SCREENS;

#if defined(MULTIMODULE)
const char STR_MULTI_CUSTOM[]  = TR_MULTI_CUSTOM;
const char STR_MULTI_RFTUNE[]  = TR_MULTI_RFTUNE;
const char STR_MULTI_TELEMETRY[]  = TR_MULTI_TELEMETRY;
const char STR_MULTI_VIDFREQ[]  = TR_MULTI_VIDFREQ;
const char STR_MULTI_OPTION[]  = TR_MULTI_OPTION;
const char STR_MULTI_AUTOBIND[]  = TR_MULTI_AUTOBIND;
const char STR_MULTI_DSM_AUTODTECT[]  = TR_MULTI_DSM_AUTODTECT;
const char STR_MULTI_LOWPOWER[]  = TR_MULTI_LOWPOWER;
const char STR_MODULE_NO_SERIAL_MODE[]  = TR_MODULE_NO_SERIAL_MODE;
const char STR_MODULE_NO_INPUT[]  = TR_MODULE_NO_INPUT;
const char STR_MODULE_WAITFORBIND[]  = TR_MODULE_WAITFORBIND;
const char STR_MODULE_NO_TELEMETRY[]  = TR_MODULE_NO_TELEMETRY;
const char STR_MODULE_BINDING[]  = TR_MODULE_BINDING;
const char STR_PROTOCOL_INVALID[]  = TR_PROTOCOL_INVALID;
const char STR_MODULE_STATUS[]  = TR_MODULE_STATUS;
const char STR_MODULE_SYNC[]  = TR_MODULE_SYNC;
const char STR_MULTI_SERVOFREQ[]  = TR_MULTI_SERVOFREQ;
#if LCD_W < 212
const char STR_SUBTYPE[]  = TR_SUBTYPE;
#endif
#endif

const char STR_RESET_BTN[]  = TR_RESET_BTN;
const char STR_DEBUG[]  = TR_DEBUG;
const char STR_KEYS_BTN[]  = TR_KEYS_BTN;
const char STR_ANALOGS_BTN[]  = TR_ANALOGS_BTN;
const char STR_CALIB_BTN[]  = TR_CALIB_BTN;

#if defined(SDCARD)
const char STR_BACKUP_MODEL[]  = TR_BACKUP_MODEL;
const char STR_RESTORE_MODEL[]  = TR_RESTORE_MODEL;
const char STR_DELETE_ERROR[]  = TR_DELETE_ERROR;
const char STR_SDCARD_ERROR[]  = TR_SDCARD_ERROR;
const char STR_NO_SDCARD[]  = TR_NO_SDCARD;
const char STR_SDCARD_FULL[]  = TR_SDCARD_FULL;
const char STR_INCOMPATIBLE[]  = TR_INCOMPATIBLE;
const char STR_LOGS_PATH[]  = LOGS_PATH;
const char STR_LOGS_EXT[]  = LOGS_EXT;
const char STR_MODELS_PATH[]  = MODELS_PATH;
const char STR_MODELS_EXT[]  = MODELS_EXT;
#endif

const char STR_CAT_NOT_EMPTY[]  = TR_CAT_NOT_EMPTY;
const char STR_WARNING[]  = TR_WARNING;
const char STR_THROTTLEWARN[]  = TR_THROTTLEWARN;
const char STR_ALARMSWARN[]  = TR_ALARMSWARN;
const char STR_SWITCHWARN[]  = TR_SWITCHWARN;
const char STR_FAILSAFEWARN[]  = TR_FAILSAFEWARN;
#if defined(NIGHTLY_BUILD_WARNING)
const char STR_NIGHTLY_WARNING[]  = TR_NIGHTLY_WARNING;
const char STR_NIGHTLY_NOTSAFE[]  = TR_NIGHTLY_NOTSAFE;
#endif
const char STR_WRONG_SDCARDVERSION[]  = TR_WRONG_SDCARDVERSION;
const char STR_WRONG_PCBREV[]  = TR_WRONG_PCBREV;
const char STR_EMERGENCY_MODE[]  = TR_EMERGENCY_MODE;
const char STR_NO_FAILSAFE[]  = TR_NO_FAILSAFE;
const char STR_KEYSTUCK[]  = TR_KEYSTUCK;

const char STR_SPEAKER_VOLUME[]  = TR_SPEAKER_VOLUME;
const char STR_LCD[]  = TR_LCD;
const char STR_BRIGHTNESS[]  = TR_BRIGHTNESS;
const char STR_CPU_TEMP[]  = TR_CPU_TEMP;
const char STR_CPU_CURRENT[]  = TR_CPU_CURRENT;
const char STR_CPU_MAH[]  = TR_CPU_MAH;
const char STR_COPROC[]  = TR_COPROC;
const char STR_COPROC_TEMP[]  = TR_COPROC_TEMP;
const char STR_TEMPWARNING[]  = TR_TEMPWARNING;
const char STR_CAPAWARNING[]  = TR_CAPAWARNING;
const char STR_FUNC[]  = TR_FUNC;
const char STR_V1[]  = TR_V1;
const char STR_V2[]  = TR_V2;
const char STR_DURATION[]  = TR_DURATION;
const char STR_DELAY[]  = TR_DELAY;
const char STR_SD_CARD[]  = TR_SD_CARD;
const char STR_SDHC_CARD[]  = TR_SDHC_CARD;
const char STR_NO_SOUNDS_ON_SD[]  = TR_NO_SOUNDS_ON_SD;
const char STR_NO_MODELS_ON_SD[]  = TR_NO_MODELS_ON_SD;
const char STR_NO_BITMAPS_ON_SD[]  = TR_NO_BITMAPS_ON_SD;
const char STR_NO_SCRIPTS_ON_SD[]  = TR_NO_SCRIPTS_ON_SD;
const char STR_SCRIPT_SYNTAX_ERROR[]  = TR_SCRIPT_SYNTAX_ERROR;
const char STR_SCRIPT_PANIC[]  = TR_SCRIPT_PANIC;
const char STR_SCRIPT_KILLED[]  = TR_SCRIPT_KILLED;
const char STR_SCRIPT_ERROR[]  = TR_SCRIPT_ERROR;
const char STR_PLAY_FILE[]  = TR_PLAY_FILE;
const char STR_ASSIGN_BITMAP[]  = TR_ASSIGN_BITMAP;
#if defined(PCBHORUS)
const char STR_ASSIGN_SPLASH[]  = TR_ASSIGN_SPLASH;
#endif
const char STR_EXECUTE_FILE[]  = TR_EXECUTE_FILE;
const char STR_DELETE_FILE[]  = TR_DELETE_FILE;
const char STR_COPY_FILE[]  = TR_COPY_FILE;
const char STR_RENAME_FILE[]  = TR_RENAME_FILE;
const char STR_SD_INFO[]  = TR_SD_INFO;
const char STR_SD_FORMAT[]  = TR_SD_FORMAT;
const char STR_REMOVED[]  = TR_REMOVED;
const char STR_NA[]  = TR_NA;
const char STR_HARDWARE[]  = TR_HARDWARE;
const char STR_FORMATTING[]  = TR_FORMATTING;
const char STR_TEMP_CALIB[]  = TR_TEMP_CALIB;
const char STR_TIME[]  = TR_TIME;
const char STR_MAXBAUDRATE[]  = TR_MAXBAUDRATE;
const char STR_BAUDRATE[]  = TR_BAUDRATE;
const char STR_SD_INFO_TITLE[]  = TR_SD_INFO_TITLE;
const char STR_SD_TYPE[]  = TR_SD_TYPE;
const char STR_SD_SPEED[]  = TR_SD_SPEED;
const char STR_SD_SECTORS[]  = TR_SD_SECTORS;
const char STR_SD_SIZE[]  = TR_SD_SIZE;
const char STR_TYPE[]  = TR_TYPE;
const char STR_GLOBAL_VARS[]  = TR_GLOBAL_VARS;
const char STR_GVARS[]  = TR_GVARS;
const char STR_GLOBAL_VAR[]  = TR_GLOBAL_VAR;
const char STR_OWN[]  = TR_OWN;
const char STR_ROTARY_ENCODER[]  = TR_ROTARY_ENCODER;
const char STR_DATE[]  = TR_DATE;
const char STR_CHANNELS_MONITOR[]  = TR_CHANNELS_MONITOR;
const char STR_MIXERS_MONITOR[]  = TR_MIXERS_MONITOR;
const char STR_PATH_TOO_LONG[]  = TR_PATH_TOO_LONG;
const char STR_VIEW_TEXT[]  = TR_VIEW_TEXT;
const char STR_FLASH_BOOTLOADER[]  = TR_FLASH_BOOTLOADER;
const char STR_FLASH_INTERNAL_MODULE[]  = TR_FLASH_INTERNAL_MODULE;
const char STR_FLASH_EXTERNAL_MODULE[]  = TR_FLASH_EXTERNAL_MODULE;
const char STR_FIRMWARE_UPDATE_ERROR[]  = TR_FIRMWARE_UPDATE_ERROR;
const char STR_FIRMWARE_UPDATE_SUCCESS[]  = TR_FIRMWARE_UPDATE_SUCCESS;
const char STR_FLASH_EXTERNAL_DEVICE[]  = TR_FLASH_EXTERNAL_DEVICE;
const char STR_CONFIRM_FORMAT[]  = TR_CONFIRM_FORMAT;
const char STR_CONFIRMRESET[]  = TR_CONFIRMRESET;
const char STR_TOO_MANY_LUA_SCRIPTS[]  = TR_TO_MANY_LUA_SCRIPTS;
const char STR_BLCOLOR[]   = TR_BLCOLOR;

  const char STR_MODELNAME[]  = TR_MODELNAME;
  const char STR_PHASENAME[]  = TR_PHASENAME;
  const char STR_MIXNAME[]  = TR_MIXNAME;
  const char STR_INPUTNAME[]  = TR_INPUTNAME;
  const char STR_EXPONAME[]  = TR_EXPONAME;

#if LCD_W >= 212
  const char * const STR_PHASES_HEADERS[] = TR_PHASES_HEADERS;
  const char * const STR_LIMITS_HEADERS[] = TR_LIMITS_HEADERS;
  const char * const STR_LSW_HEADERS[] = TR_LSW_HEADERS;
  const char * const STR_LSW_DESCRIPTIONS[] = TR_LSW_DESCRIPTIONS;
  const char * const STR_GVAR_HEADERS[] = TR_GVAR_HEADERS;
#endif

  const char STR_TRAINER[]  = TR_TRAINER;
  const char STR_MODULE_BIND[]   = TR_MODULE_BIND;
const char STR_PXX2_SELECT_RX[]  = TR_PXX2_SELECT_RX;
const char STR_PXX2_DEFAULT[]  = TR_PXX2_DEFAULT;
const char STR_BT_SELECT_DEVICE[]  = TR_BT_SELECT_DEVICE;
const char STR_BUTTON_DISCOVER[]  = TR_BUTTON_DISCOVER;
const char STR_BUTTON_INIT[]  = TR_BUTTON_INIT;
const char STR_WAITING[]  = TR_WAITING;
const char STR_RECEIVER_DELETE[]  = TR_RECEIVER_DELETE;
const char STR_RECEIVER_RESET[]  = TR_RECEIVER_RESET;
const char STR_SHARE[]  = TR_SHARE;
const char STR_BIND[]  = TR_BIND;
const char STR_TRANSFER_BUTTON[]  = TR_TRANSFER_BUTTON;
const char STR_RXADD_BUTTON[]  = TR_RXADD_BUTTON;
  const char STR_BINDING_1_8_TELEM_ON[]  = TR_BINDING_CH1_8_TELEM_ON;
  const char STR_BINDING_1_8_TELEM_OFF[]  = TR_BINDING_CH1_8_TELEM_OFF;
  const char STR_BINDING_9_16_TELEM_ON[]  = TR_BINDING_CH9_16_TELEM_ON;
  const char STR_BINDING_9_16_TELEM_OFF[]  = TR_BINDING_CH9_16_TELEM_OFF;
  const char STR_CHANNELRANGE[]  = TR_CHANNELRANGE;
  const char STR_RXFREQUENCY[]  = TR_RXFREQUENCY;
  const char STR_ANTENNASELECTION[]  = TR_ANTENNASELECTION;
  const char STR_ANTENNACONFIRM1[]  = TR_ANTENNACONFIRM1;
  const char STR_ANTENNACONFIRM2[]  = TR_ANTENNACONFIRM2;
  const char STR_R9MFLEXWARN1[]  = TR_R9MFLEXWARN1;
  const char STR_R9MFLEXWARN2[]  = TR_R9MFLEXWARN2;
  const char STR_SET[]  = TR_SET;
  const char STR_PREFLIGHT[]  = TR_PREFLIGHT;
  const char STR_CHECKLIST[]  = TR_CHECKLIST;
  const char STR_VIEW_NOTES[]  = TR_VIEW_NOTES;
  const char STR_MODEL_SELECT[]  = TR_MODEL_SELECT;
  const char STR_RESET_SUBMENU[]  = TR_RESET_SUBMENU;
  const char STR_LOWALARM[]  = TR_LOWALARM;
  const char STR_CRITICALALARM[]  = TR_CRITICALALARM;
  const char STR_RSSIALARM_WARN[]  = TR_RSSIALARM_WARN;
  const char STR_NO_RSSIALARM[]  = TR_NO_RSSIALARM;
  const char STR_DISABLE_ALARM[]  = TR_DISABLE_ALARM;
  const char STR_TELEMETRY_TYPE[]  = TR_TELEMETRY_TYPE;
  const char STR_TELEMETRY_SENSORS[]  = TR_TELEMETRY_SENSORS;
  const char STR_VALUE[]  = TR_VALUE;
const char STR_REPEAT[]  = TR_REPEAT;
const char STR_ENABLE[]  = TR_ENABLE;
  const char STR_TOPLCDTIMER[]  = TR_TOPLCDTIMER;
  const char STR_UNIT[]  = TR_UNIT;
  const char STR_TELEMETRY_NEWSENSOR[]  = TR_TELEMETRY_NEWSENSOR;
  const char STR_ID[]  = TR_ID;
  const char STR_PRECISION[]  = TR_PRECISION;
  const char STR_RATIO[]  = TR_RATIO;
  const char STR_FORMULA[]  = TR_FORMULA;
  const char STR_CELLINDEX[]  = TR_CELLINDEX;
  const char STR_LOGS[]  = TR_LOGS;
  const char STR_OPTIONS[]  = TR_OPTIONS;
  const char STR_ALTSENSOR[]  = TR_ALTSENSOR;
  const char STR_CELLSENSOR[]  = TR_CELLSENSOR;
  const char STR_GPSSENSOR[]  = TR_GPSSENSOR;
  const char STR_CURRENTSENSOR[]  = TR_CURRENTSENSOR;
  const char STR_AUTOOFFSET[]  = TR_AUTOOFFSET;
  const char STR_ONLYPOSITIVE[]  = TR_ONLYPOSITIVE;
  const char STR_FILTER[]  = TR_FILTER;
  const char STR_TELEMETRYFULL[]  = TR_TELEMETRYFULL;
  const char STR_SERVOS_OK[]  = TR_SERVOS_OK;
  const char STR_SERVOS_KO[]  = TR_SERVOS_KO;
  const char STR_INVERTED_SERIAL[]  = TR_INVERTED_SERIAL;
  const char STR_IGNORE_INSTANCE[]  = TR_IGNORE_INSTANCE;
  const char STR_DISCOVER_SENSORS[]  = TR_DISCOVER_SENSORS;
  const char STR_STOP_DISCOVER_SENSORS[]  = TR_STOP_DISCOVER_SENSORS;
  const char STR_DELETE_ALL_SENSORS[]  = TR_DELETE_ALL_SENSORS;
  const char STR_CONFIRMDELETE[]  = TR_CONFIRMDELETE;
  const char STR_SELECT_WIDGET[]  = TR_SELECT_WIDGET;
  const char STR_REMOVE_WIDGET[]  = TR_REMOVE_WIDGET;
  const char STR_WIDGET_SETTINGS[]  = TR_WIDGET_SETTINGS;
  const char STR_REMOVE_SCREEN[]  = TR_REMOVE_SCREEN;
  const char STR_SETUP_WIDGETS[]  = TR_SETUP_WIDGETS;
  const char STR_USER_INTERFACE[]  = TR_USER_INTERFACE;
  const char STR_THEME[]  = TR_THEME;
  const char STR_SETUP[]  = TR_SETUP;
  const char STR_LAYOUT[]  = TR_LAYOUT;
  const char STR_ADDMAINVIEW[]  = TR_ADDMAINVIEW;
  const char STR_BACKGROUND_COLOR[]  = TR_BACKGROUND_COLOR;
  const char STR_MAIN_COLOR[]  = TR_MAIN_COLOR;
  const char STR_TEXT_VIEWER[]  = TR_TEXT_VIEWER;
  const char STR_MULTI_RFPOWER[]  = TR_MULTI_RFPOWER;

  const char STR_BYTES[]  = TR_BYTES;
  const char STR_ANTENNAPROBLEM[]  = TR_ANTENNAPROBLEM;
  const char STR_MODULE[]  = TR_MODULE;
const char STR_RX_NAME[]  = TR_RX_NAME;
  const char STR_ENABLE_POPUP[]  = TR_ENABLE_POPUP;
  const char STR_DISABLE_POPUP[]  = TR_DISABLE_POPUP;
  const char STR_POPUP[]  = TR_POPUP;
  const char STR_MIN[]  = TR_MIN;
  const char STR_MAX[]  = TR_MAX;
  const char STR_CURVE_PRESET[]  = TR_CURVE_PRESET;
  const char STR_PRESET[]  = TR_PRESET;
  const char STR_MIRROR[]  = TR_MIRROR;
  const char STR_CLEAR[]  = TR_CLEAR;
  const char STR_RESET[]  = TR_RESET;
  const char STR_COUNT[]  = TR_COUNT;
  const char STR_PT[]  = TR_PT;
  const char STR_PTS[]  = TR_PTS;
  const char STR_SMOOTH[]  = TR_SMOOTH;
  const char STR_COPY_STICKS_TO_OFS[]  = TR_COPY_STICKS_TO_OFS;
  const char STR_COPY_TRIMS_TO_OFS[]  = TR_COPY_TRIMS_TO_OFS;
  const char STR_INCDEC[]  = TR_INCDEC;
  const char STR_GLOBALVAR[]  = TR_GLOBALVAR;
  const char STR_MIXSOURCE[]  = TR_MIXSOURCE;
  const char STR_CONSTANT[]  = TR_CONSTANT;
  const char STR_TOP_BAR[]  = TR_TOP_BAR;
  const char STR_ALTITUDE[]  = TR_ALTITUDE;
  const char STR_SCALE[]  = TR_SCALE;
  const char STR_VIEW_CHANNELS[]  = TR_VIEW_CHANNELS;
  const char STR_UART3MODE[]  = TR_UART3MODE;
  const char STR_THROTTLE_LABEL[]  = TR_THROTTLE_LABEL;
  const char STR_SCRIPT[]  = TR_SCRIPT;
  const char STR_INPUTS[]  = TR_INPUTS;
  const char STR_OUTPUTS[]  = TR_OUTPUTS;
  const char STR_MENU_INPUTS[]  = TR_MENU_INPUTS;
  const char STR_MENU_LUA[]  = TR_MENU_LUA;
  const char STR_MENU_STICKS[]  = TR_MENU_STICKS;
  const char STR_MENU_POTS[]  = TR_MENU_POTS;
  const char STR_MENU_MAX[]  = TR_MENU_MAX;
  const char STR_MENU_HELI[]  = TR_MENU_HELI;
  const char STR_MENU_TRIMS[]  = TR_MENU_TRIMS;
  const char STR_MENU_SWITCHES[]  = TR_MENU_SWITCHES;
  const char STR_MENU_LOGICAL_SWITCHES[]  = TR_MENU_LOGICAL_SWITCHES;
  const char STR_MENU_TRAINER[]  = TR_MENU_TRAINER;
  const char STR_MENU_CHANNELS[]  = TR_MENU_CHANNELS;
  const char STR_MENU_GVARS[]  = TR_MENU_GVARS;
  const char STR_MENU_TELEMETRY[]  = TR_MENU_TELEMETRY;
  const char STR_MENU_DISPLAY[]  = TR_MENU_DISPLAY;
  const char STR_MENU_OTHER[]  = TR_MENU_OTHER;
  const char STR_MENU_INVERT[]  = TR_MENU_INVERT;
  const char STR_JITTER_FILTER[]  = TR_JITTER_FILTER;
  const char STR_BUTTON_SHARE[]  = TR_BUTTON_SHARE;

#if MENUS_LOCK == 1
  const char STR_UNLOCKED[]  = TR_UNLOCKED;
  const char STR_MODS_FORBIDDEN[]  = TR_MODS_FORBIDDEN;
#endif

#if defined(PCBTARANIS) || defined(DSM2)
  const char STR_MODULE_RANGE[]  = TR_MODULE_RANGE;
  const char STR_RECEIVER_OPTIONS[]  = TR_RECEIVER_OPTIONS;
  const char STR_DEL_BUTTON[]  = TR_DEL_BUTTON;
#endif

#if defined(BLUETOOTH)
  const char STR_BLUETOOTH[]  = TR_BLUETOOTH;
  const char STR_BLUETOOTH_DISC[]  = TR_BLUETOOTH_DISC;
  const char STR_BLUETOOTH_INIT[]  = TR_BLUETOOTH_INIT;
  const char STR_BLUETOOTH_DIST_ADDR[]  = TR_BLUETOOTH_DIST_ADDR;
  const char STR_BLUETOOTH_LOCAL_ADDR[]  = TR_BLUETOOTH_LOCAL_ADDR;
  const char STR_BLUETOOTH_PIN_CODE[]  = TR_BLUETOOTH_PIN_CODE;
#endif


  const char STR_ABOUTUS[]  = TR_ABOUTUS;
  const char STR_ABOUT_OPENTX_1[]  = TR_ABOUT_OPENTX_1;
  const char STR_ABOUT_OPENTX_2[]  = TR_ABOUT_OPENTX_2;
  const char STR_ABOUT_OPENTX_3[]  = TR_ABOUT_OPENTX_3;
  const char STR_ABOUT_OPENTX_4[]  = TR_ABOUT_OPENTX_4;
  const char STR_ABOUT_OPENTX_5[]  = TR_ABOUT_OPENTX_5;

  const char STR_ABOUT_BERTRAND_1[]  = TR_ABOUT_BERTRAND_1;
  const char STR_ABOUT_BERTRAND_2[]  = TR_ABOUT_BERTRAND_2;
  const char STR_ABOUT_BERTRAND_3[]  = TR_ABOUT_BERTRAND_3;

  const char STR_ABOUT_MIKE_1[]  = TR_ABOUT_MIKE_1;
  const char STR_ABOUT_MIKE_2[]  = TR_ABOUT_MIKE_2;
  const char STR_ABOUT_MIKE_3[]  = TR_ABOUT_MIKE_3;
  const char STR_ABOUT_MIKE_4[]  = TR_ABOUT_MIKE_4;

  const char STR_ABOUT_ROMOLO_1[]  = TR_ABOUT_ROMOLO_1;
  const char STR_ABOUT_ROMOLO_2[]  = TR_ABOUT_ROMOLO_2;
  const char STR_ABOUT_ROMOLO_3[]  = TR_ABOUT_ROMOLO_3;

  const char STR_ABOUT_ANDRE_1[]  = TR_ABOUT_ANDRE_1;
  const char STR_ABOUT_ANDRE_2[]  = TR_ABOUT_ANDRE_2;
  const char STR_ABOUT_ANDRE_3[]  = TR_ABOUT_ANDRE_3;

  const char STR_ABOUT_ROB_1[]  = TR_ABOUT_ROB_1;
  const char STR_ABOUT_ROB_2[]  = TR_ABOUT_ROB_2;

  const char STR_ABOUT_MARTIN_1[]  = TR_ABOUT_MARTIN_1;
  const char STR_ABOUT_MARTIN_2[]  = TR_ABOUT_MARTIN_2;

  const char STR_ABOUT_KJELL_1[]  = TR_ABOUT_KJELL_1;
  const char STR_ABOUT_KJELL_2[]  = TR_ABOUT_KJELL_2;
  const char STR_ABOUT_KJELL_3[]  = TR_ABOUT_KJELL_3;
  const char STR_ABOUT_KJELL_4[]  = TR_ABOUT_KJELL_4;

  const char STR_ABOUT_HARDWARE_1[]  = TR_ABOUT_HARDWARE_1;
  const char STR_ABOUT_HARDWARE_2[]  = TR_ABOUT_HARDWARE_2;
  const char STR_ABOUT_HARDWARE_3[]  = TR_ABOUT_HARDWARE_3;

  const char STR_ABOUT_PARENTS_1[]  = TR_ABOUT_PARENTS_1;
  const char STR_ABOUT_PARENTS_2[]  = TR_ABOUT_PARENTS_2;
  const char STR_ABOUT_PARENTS_3[]  = TR_ABOUT_PARENTS_3;
  const char STR_ABOUT_PARENTS_4[]  = TR_ABOUT_PARENTS_4;
