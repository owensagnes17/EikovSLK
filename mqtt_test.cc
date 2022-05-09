#include <gtest/gtest.h>

#include "util.h"

TEST(MQTTTest, mqtt_option_init_by_config)
{
    neu_config_t config;
    memset(&config, 0, sizeof(neu_config_t));
    neu_mqtt_option_t option;
    memset(&option, 0, sizeof(neu_mqtt_option_t));
    config.buf = (char *) "{\"node_id\":5,\"params\":{\"client-id\":"
                          "116\",\"port\":1883,\"username\":\"\",\"password\":"
                          "\"\",\"ca\":\"\", \"cert\":\"\", \"key\":\"\"}}";

    int rc = mqtt_option_init(&config, &option);
    EXPECT_EQ(0, rc);
    mqtt_option_uninit(&option);
}
