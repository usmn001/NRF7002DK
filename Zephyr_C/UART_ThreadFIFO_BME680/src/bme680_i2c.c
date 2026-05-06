#include "bme680_i2c.h"
#include <zephyr/logging/log.h>

static const struct i2c_dt_spec dev_i2c = I2C_DT_SPEC_GET(I2C1_NODE); /* Structure containing pointer to device node bme680  */
LOG_MODULE_REGISTER(bme680_i2c);

void i2c_init()
{
    if(!device_is_ready(dev_i2c.bus))  /* Check if the I2C device is ready */
    {
        LOG_ERR("I2C: Device is not ready.\n");
        return;
    }
    else
    {
        LOG_INF("I2C: Device is ready.\n");
    }
}

int8_t I2C_READ(const uint8_t reg_addr, uint8_t *data, size_t len)
{
    int ret;
    ret = i2c_write_dt(&dev_i2c, &reg_addr, len); /* Write the register address to the sensor */
    if (ret < 0) {
        LOG_ERR("I2C: Failed to write register address (err %d)\n", ret);
        return ret;
    }
    
    ret = i2c_read_dt(&dev_i2c, data, len); /* Read the data from the sensor */
    if (ret < 0) {
        LOG_ERR("I2C: Failed to read data (err %d)\n", ret);
        return ret;
    }
    
    return 0; /* Return 0 on success */
}

int8_t I2C_WRITE(const uint8_t reg_addr, uint8_t *data, size_t len)
{
    int ret;
    ret = i2c_write_dt(&dev_i2c, &reg_addr, len); /* Write the register address to the sensor */
    if (ret < 0) {
        LOG_ERR("I2C: Failed to write register address (err %d)\n", ret);
        return ret;
    }
     ret = i2c_write_dt(&dev_i2c, &reg_addr, len); /* Write the register address to the sensor */
    if (ret < 0) {
        LOG_ERR("I2C: Failed to write register address (err %d)\n", ret);
        return ret;
    }
    


    
    ret = i2c_read_dt(&dev_i2c, data, len); /* Read the data from the sensor */
    if (ret < 0) {
        LOG_ERR("I2C: Failed to read data (err %d)\n", ret);
        return ret;
    }
    
    return 0; /* Return 0 on success */
}