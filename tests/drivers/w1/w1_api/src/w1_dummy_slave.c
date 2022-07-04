/*
 * Copyright (c) 2022 Thomas Stranger
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define DT_DRV_COMPAT test_w1_dummy_slave

#include <device.h>
#include <drivers/w1.h>

struct w1_dummy_slave_api {
};

static const struct w1_dummy_slave_api w1_dummy_slave_api1 = {};

static int w1_dummy_slave_init(const struct device *dev)
{
	return 0;
}

#define TEST_W1_DUMMY_SLAVE_DEFINE(inst)				       \
	DEVICE_DT_INST_DEFINE(inst, w1_dummy_slave_init, NULL, NULL, NULL,     \
			      POST_KERNEL, CONFIG_W1_INIT_PRIORITY,	       \
			      &w1_dummy_slave_api1);

DT_INST_FOREACH_STATUS_OKAY(TEST_W1_DUMMY_SLAVE_DEFINE)