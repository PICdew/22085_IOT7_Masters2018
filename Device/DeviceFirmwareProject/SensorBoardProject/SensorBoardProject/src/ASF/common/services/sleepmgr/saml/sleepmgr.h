/**
 * \file
 *
 * \brief Chip-specific sleep manager configuration
 *
 * Copyright (c) 2014-2018 Microchip Technology Inc. and its subsidiaries.
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
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#ifndef SAM_SLEEPMGR_INCLUDED
#define SAM_SLEEPMGR_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <compiler.h>
#include <conf_sleepmgr.h>
#include <interrupt.h>
#include "system.h"

/**
 * \weakgroup sleepmgr_group
 * @{
 */

enum sleepmgr_mode {
	/** Active mode. */
	SLEEPMGR_ACTIVE = 0,

	/**
	 *  Idle mode.
	 *  Potential Wake Up sources: Synchronous(APB, AHB), asynchronous.
	 */
	SLEEPMGR_IDLE,

	/**
	 * Standby mode.
	 *  Potential Wake Up sources: Asynchronous.
	 */
	SLEEPMGR_STANDBY,

	/**
	 *  Backup mode.
	 *  Potential Wake Up sources: Backup reset detected by the RSTC.
	 */
	SLEEPMGR_BACKUP,

	/**
	 * Off mode.
	 * Potential Wake Up sources: External reset.
	 */
	SLEEPMGR_OFF,

	SLEEPMGR_NR_OF_MODES,
};

/**
 * \internal
 * \name Internal arrays
 * @{
 */
#if defined(CONFIG_SLEEPMGR_ENABLE) || defined(__DOXYGEN__)
/** Sleep mode lock counters */
extern uint8_t sleepmgr_locks[];
#endif /* CONFIG_SLEEPMGR_ENABLE */
/** @} */

static inline void sleepmgr_sleep(const enum sleepmgr_mode sleep_mode)
{
	Assert(sleep_mode != SLEEPMGR_ACTIVE);
#ifdef CONFIG_SLEEPMGR_ENABLE
	cpu_irq_disable();

	/* Enter the sleep mode. */
	switch (sleep_mode) {
	case SLEEPMGR_IDLE:
		system_set_sleepmode(SYSTEM_SLEEPMODE_IDLE);
		cpu_irq_enable();
		system_sleep();
		break;
	case SLEEPMGR_STANDBY:
		system_set_sleepmode(SYSTEM_SLEEPMODE_STANDBY);
		cpu_irq_enable();
		system_sleep();
		break;
	case SLEEPMGR_BACKUP:
		system_set_sleepmode(SYSTEM_SLEEPMODE_BACKUP);
		cpu_irq_enable();
		system_sleep();
		break;
	case SLEEPMGR_OFF:
		system_set_sleepmode(SYSTEM_SLEEPMODE_OFF);
		cpu_irq_enable();
		system_sleep();
		break;
	default:
		cpu_irq_enable();
		break;
	}
#else
	UNUSED(sleep_mode);
	cpu_irq_enable();
#endif /* CONFIG_SLEEPMGR_ENABLE */
}

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* SAM_SLEEPMGR_INCLUDED */
