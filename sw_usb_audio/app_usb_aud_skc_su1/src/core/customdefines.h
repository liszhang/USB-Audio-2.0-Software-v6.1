/** 
 * @file       customdefines.h
 * @brief      Defines relating to device configuration and customisation.
 *             For L1 USB Audio Reference Design
 * @author     Ross Owen, XMOS Limited
 */
#ifndef _CUSTOMDEFINES_H_
#define _CUSTOMDEFINES_H_


/*
 * Device configuration option defines.  Build can be customised but changing and adding defines here 
 *
 * Note, we check if they are already defined in Makefile 
 */

/* Enable/Disable MIDI - Default is MIDI off */
#ifndef MIDI
#define MIDI 		0			
#endif

/* Enable/Disable SPDIF output - Default is S/PDIF on */
#ifndef SPDIF
#define SPDIF		1			
#endif

/* Audio class version to run in - Default is 2.0 */
#ifndef AUDIO_CLASS
#define AUDIO_CLASS (2)			
#endif

/* Enable/disable fall back to Audio Class 1.0 when connected to FS hub. */
#ifndef AUDIO_CLASS_FALLBACK
#define AUDIO_CLASS_FALLBACK 1 
#endif

/* Defines relating to channel count and channel arrangement (Set to 0 for disable) */ 
//:audio_defs
/* Number of USB streaming channels - Default is 4 in 4 out */
#ifndef NUM_USB_CHAN_IN
#define NUM_USB_CHAN_IN   (4)         /* Device to Host */
#endif
#ifndef NUM_USB_CHAN_OUT
#define NUM_USB_CHAN_OUT  (4)         /* Host to Device */
#endif

/* Number of IS2 chans to DAC..*/
#ifndef I2S_CHANS_DAC
#define I2S_CHANS_DAC     (4)
#endif

/* Number of I2S chans from ADC */
#ifndef I2S_CHANS_ADC
#define I2S_CHANS_ADC     (4)
#endif

/* Run the CODEC as slave, Xcore as master 
 * Changing this define will cause CODECs to setup appropriately and XCore to be I2S slave
 */
#define CODEC_MASTER      0

/* Enable DFU interface, Note, requires a driver for Windows */
#define DFU             1

#define MIDI_SHIFT_TX   7


/* Master clock defines (in Hz) */
#define MCLK_441          (512*44100)   /* 44.1, 88.2 etc */
#define MCLK_48           (512*48000)   /* 48, 96 etc */

/* Maximum frequency device runs at */
#define MAX_FREQ                    (192000)       

/* Index of SPDIF TX channel (duplicated DAC channels 1/2) */
#define SPDIF_TX_INDEX              (0)

/* Default frequency device reports as running at */
/* Audio Class 1.0 friendly freq */       
#define DEFAULT_FREQ                (48000)            
//:
/***** Defines relating to USB descriptors etc *****/
//:usb_defs
#define VENDOR_ID   (0x20B1) /* XMOS VID */
#define PID_AUDIO_2 (0x0008) /* SKC_SU1 USB Audio Reference Design PID */
#define PID_AUDIO_1 (0x0009) /* SKC_SU1 Audio Reference Design PID */
#define BCD_DEVICE  (0x0610) /* Device release number in BCD: 0xJJMN
                              * JJ: Major, M: Minor, N: Sub-minor */
//:

/* Enable hostactive() calls */
#define HOST_ACTIVE_CALL   1

/* Enable/Disable example HID code */
#define HID_CONTROLS       0

/* Enable/Disable SU1 ADC */
#define SU1_ADC_ENABLE     0

/* Enable ADC based *EXAMPLE* volume control */
#define ADC_VOL_CONTROL    0

/* Define to use custom flash part not in tools by default 
 * Device is M25P40 */
#define DFU_FLASH_DEVICE \
{    \
    1, \
    256,                    /* page size */\
    1024,                   /* num pages */\
    3,                      /* address size */\
    8,                      /* log2 clock divider */\
    0x9f,                   /* SPI_RDID */\
    0,                      /* id dummy bytes */\
    3,                      /* id size in bytes */ \
    0x202013,               /* device id */\
    0xD8,                   /* SPI_SE */\
    0,                      /* full sector erase */\
    0x06,                   /* SPI_WREN */\
    0x04,                   /* SPI_WRDI */\
    PROT_TYPE_SR,           /* SR protection */\
    {{0x0c,0x0},{0,0}},     /* no values */\
    0x02,                   /* SPI_PP */\
    0x0b,                   /* SPI_READFAST */\
    1,                      /* 1 read dummy byte */\
    SECTOR_LAYOUT_REGULAR,  /* sane sectors */\
    {32768,{0,{0}}},        /* regular sector size */\
    0x05,                   /* SPI_RDSR */\
    0x01,                   /* no SPI_WRSR */\
    0x01,                   /* SPI_WIP_BIT_MASK */\
}

#endif
