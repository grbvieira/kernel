/* Copyright (C) 2015 Samsung Electronics.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __MODEM_NOTIFIER_H__
#define __MODEM_NOTIFIER_H__

/* refer to enum modem_state  */
enum modem_event {
	MODEM_EVENT_RESET	= 1,
	MODEM_EVENT_EXIT,
	MODEM_EVENT_ONLINE	= 4,
	MODEM_EVENT_OFFLINE	= 5,
	MODEM_EVENT_WATCHDOG	= 9,
};

enum modem_voice_call_event {
	MODEM_VOICE_CALL_OFF	= 0,
	MODEM_VOICE_CALL_ON	= 1,
};

#if IS_ENABLED(CONFIG_SHM_IPC)
extern int register_modem_event_notifier(struct notifier_block *nb);
#ifdef CONFIG_EXYNOS_MODEM_IF
extern void modem_notify_event(enum modem_event evt, void *mc);
#else
extern void modem_notify_event(enum modem_event evt);
#endif
#else
static inline int register_modem_event_notifier(struct notifier_block *nb)
{
	return 0;
}
static inline void modem_notify_event(enum modem_event evt) {}
#endif

#if defined(CONFIG_SUSPEND_DURING_VOICE_CALL)
extern int register_modem_voice_call_event_notifier(struct notifier_block *nb);
extern void modem_voice_call_notify_event(enum modem_voice_call_event evt, void *data);
#else
static inline int register_modem_voice_call_event_notifier(struct notifier_block *nb)
{
	return 0;
}
static inline void modem_voice_call_notify_event(enum modem_voice_call_event evt, void *data) {}
#endif

#endif/*__MODEM_NOTIFIER_H__*/
