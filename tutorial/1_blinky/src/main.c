#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define SLEEP_TIME_MS   1000

#define LED_RED_NODE DT_ALIAS(led0)

static const struct gpio_dt_spec led_red = GPIO_DT_SPEC_GET(LED_RED_NODE, gpios);

int main(void)
{
    int ret = 0;
    bool led_state = true;

    printf("Device %s init\n", led_red.port->name);

    if (!gpio_is_ready_dt(&led_red)) {
        printf("Device %s is not ready\n", led_red.port->name);
		return 0;
	}

    ret = gpio_pin_configure_dt(&led_red, GPIO_OUTPUT_ACTIVE);
    if (ret < 0)
    {
        printf("Device %s configuration failed\n", led_red.port->name);
        return 0;
    }

    while (1)
    {
        ret = gpio_pin_toggle_dt(&led_red);
		if (ret < 0) {
            printf("Device %s toggle failed\n", led_red.port->name);
			return 0;
		}

		led_state = !led_state;
		k_msleep(SLEEP_TIME_MS);
    }

    return 0;
}
