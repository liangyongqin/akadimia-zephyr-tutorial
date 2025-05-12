/*
 * Copyright (c) 2025 liangyq <liangyongqincn@gmail.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/drivers/pinctrl.h>

int main(void)
{
    printk("clock mco demo");
#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(mco1))
	const struct device *dev1;

	dev1 = DEVICE_DT_GET(DT_NODELABEL(mco1));
	if (device_is_ready(dev1)) {
		printk("MCO1 device successfully configured\n");
	} else {
		printk("MCO1 device not ready\n");
		return -1;
	}
#endif /* mco1 */

#if DT_NODE_HAS_STATUS_OKAY(DT_NODELABEL(mco2))
	const struct device *dev2;

	dev2 = DEVICE_DT_GET(DT_NODELABEL(mco2));
	if (device_is_ready(dev2)) {
		printk("MCO2 device successfully configured\n");
	} else {
		printk("MCO2 device not ready\n");
		return -1;
	}
#endif /* mco2 */

	printk("\nDisplayed the status of all MCO devices - end of example.\n");
	return 0;
}