/**
 *
 * \file
 *
 * \brief WINC1500 configuration.
 *
 * Copyright (c) 2016-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */

#ifndef CONF_WINC_H_INCLUDED
#define CONF_WINC_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "board.h"

/* This configuration files comes with empty settings! */
/* Default settings for SAML21 Xplained Pro with WINC on EXT1 are */
/* available in comments for reference. */
//#warning Please modify conf_winc.h for WINC module settings!

/*
   ---------------------------------
   ---------- PIN settings ---------
   ---------------------------------
*/

//#define CONF_WINC_PIN_RESET				PIN_PA15
#define CONF_WINC_PIN_RESET				PIN_PA03
#define CONF_WINC_PIN_CHIP_ENABLE		PIN_PB09
#define CONF_WINC_PIN_WAKE				PIN_PB08


#define CONF_WINC_SPI_MOSI				PIN_PA04
#define CONF_WINC_SPI_SCK				PIN_PA05
#define CONF_WINC_SPI_SS				PIN_PA06
#define CONF_WINC_SPI_MISO				PIN_PA07

/*
   ---------------------------------
   ---------- SPI settings ---------
   ---------------------------------
*/

#define CONF_WINC_USE_SPI				(1)

/** SPI pin and instance settings. */
#define CONF_WINC_SPI_MODULE			SERCOM0
#define CONF_WINC_SPI_SERCOM_MUX		SPI_SIGNAL_MUX_SETTING_D
#define CONF_WINC_SPI_PINMUX_PAD0		PINMUX_PA04D_SERCOM0_PAD0 /* in */
#define CONF_WINC_SPI_PINMUX_PAD1		PINMUX_PA05D_SERCOM0_PAD1 /* cs driven from software */
#define CONF_WINC_SPI_PINMUX_PAD2		PINMUX_UNUSED /* out */
#define CONF_WINC_SPI_PINMUX_PAD3		PINMUX_PA07D_SERCOM0_PAD3 /* sck */
#define CONF_WINC_SPI_CS_PIN			PIN_PA06

/** SPI interrupt pin. */
//#define CONF_WINC_SPI_INT_PIN			PIN_PA14
/*
#define CONF_WINC_SPI_INT_PIN			PIN_PA14A_EIC_EXTINT14
#define CONF_WINC_SPI_INT_MUX			MUX_PA14A_EIC_EXTINT14
#define CONF_WINC_SPI_INT_EIC			(14)
*/
										
#define CONF_WINC_SPI_INT_PIN			PIN_PA16A_EIC_EXTINT0
#define CONF_WINC_SPI_INT_MUX			MUX_PA16A_EIC_EXTINT0
#define CONF_WINC_SPI_INT_EIC			(0)

/** SPI clock. */
#define CONF_WINC_SPI_CLOCK				(12000000)

/*
   ---------------------------------
   --------- Debug Options ---------
   ---------------------------------
*/

#define CONF_WINC_DEBUG					(1)
#define CONF_WINC_PRINTF				printf

#ifdef __cplusplus
}
#endif

#endif /* CONF_WINC_H_INCLUDED */
