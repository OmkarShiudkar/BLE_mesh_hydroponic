/*
 * Copyright (c) 2020 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/** @file
 *  @brief Nordic mesh sensor sample
 */
#include <zephyr/bluetooth/bluetooth.h>
#include <bluetooth/mesh/models.h>
#include <bluetooth/mesh/dk_prov.h>
#include <dk_buttons_and_leds.h>
#include "model_handler.h"

#include <zephyr/drivers/adc.h>
#include <zephyr/drivers/gpio.h>

#define ADC_NODE DT_NODELABEL(adc)
static const struct device *const adc_dev = DEVICE_DT_GET(ADC_NODE);

#define ADC_RESOLUTION 10
#define ADC_OVERSAMPLING 4 /* 2^ADC_OVERSAMPLING samples are averaged */
#define ADC_MAX 4096
#define ADC_GAIN ADC_GAIN_1_5
#define ADC_REFERENCE ADC_REF_INTERNAL
#define ADC_REF_INTERNAL_MV 600UL
#define ADC_ACQUISITION_TIME ADC_ACQ_TIME(ADC_ACQ_TIME_MICROSECONDS, 10)
#define ADC_CHANNEL_ID 0
#define ADC_CHANNEL_INPUT SAADC_CH_PSELP_PSELP_AnalogInput0

static const struct adc_channel_cfg channel0_cfg = {
	.gain = ADC_GAIN,
	.reference = ADC_REFERENCE,
	.acquisition_time = ADC_ACQUISITION_TIME,
	.channel_id = ADC_CHANNEL_ID,
#if defined(CONFIG_ADC_CONFIGURABLE_INPUTS)
	.input_positive = ADC_CHANNEL_INPUT,
#endif
};

int16_t samplee_buffer[1];

struct adc_sequence sequencee = {
	.channels = BIT(ADC_CHANNEL_ID),
	.buffer = samplee_buffer,
	.buffer_size = sizeof(samplee_buffer),
	.resolution = ADC_RESOLUTION
	};

static void bt_ready(int err)
{
	if (err) {
		printk("Bluetooth init failed (err %d)\n", err);
		return;
	}

	printk("Bluetooth initialized\n");

	dk_leds_init();
	dk_buttons_init(NULL);

	err = bt_mesh_init(bt_mesh_dk_prov_init(), model_handler_init());
	if (err) {
		printk("Initializing mesh failed (err %d)\n", err);
		return;
	}

	if (IS_ENABLED(CONFIG_SETTINGS)) {
		settings_load();
	}

	/* This will be a no-op if settings_load() loaded provisioning info */
	bt_mesh_prov_enable(BT_MESH_PROV_ADV | BT_MESH_PROV_GATT);

	printk("Mesh initialized\n");
}

int main(void)
{
	int err;

	printk("Initializing...\n");

	err = bt_enable(bt_ready);
	if (err) {
		printk("Bluetooth init failed (err %d)\n", err);
	}
    while(1){
		int err2;

	if (!device_is_ready(adc_dev))
	{
		printk("adc_dev not ready\n");
		return -1;
	}

	err2 = adc_channel_setup(adc_dev, &channel0_cfg);
	if (err2 != 0)
	{
		printk("ADC channel setup failed with error %d. \n", err2);
		return -1;
	}

        err2 = adc_read(adc_dev, &sequencee);
		if (err2 != 0)
		{
			printk("ADC reading failed with error %d \n", err2);
		}
	int32_t my_value = samplee_buffer[0];

	printk("adc_value %d \n", my_value);

	k_msleep(5000);
	}
	return 0;
}
