#include "bme680_i2c.hpp"
#include <zephyr/logging/log.h>


LOG_MODULE_REGISTER(bme680_i2c);

namespace BME680
{

    Bme_sens::Bme_sens():dev_i2c(I2C_DT_SPEC_GET(I2C1_NODE))   /* Structure containing pointer to device node bme680  */
    {
   
    }

    ret_i2c_en Bme_sens::I2C_INIT()
    {
        ret_i2c_en ret_stat = I2C_INIT_OK;
        if(!device_is_ready(dev_i2c.bus))  /* Check if the I2C device is ready */
        {
            LOG_ERR("I2C: Device is not ready.\n");
            ret_stat = I2C_INIT_NOK;
        }
        else
        {
            LOG_INF("I2C: Device is ready.\n");
        }
        return ret_stat;
    }

    ret_i2c_en Bme_sens::I2C_READ(const uint8_t reg_addr, uint8_t *data, size_t len)
    {
        int ret;
        ret_i2c_en ret_stat = I2C_READ_NOK;
        ret = i2c_write_dt(&dev_i2c, &reg_addr, len); /* Write the register address to the sensor */
        if (ret < 0) 
        {
            LOG_ERR("I2C: Failed to write register address (err %d)\n", ret);
            ret_stat = I2C_READ_OK;
        }
    
        ret = i2c_read_dt(&dev_i2c, data, len); /* Read the data from the sensor */
        if (ret < 0) 
        {
            LOG_ERR("I2C: Failed to read data (err %d)\n", ret);
            ret_stat = I2C_READ_OK;
        }
    
        return ret_stat; 
    }

    ret_i2c_en Bme_sens::I2C_WRITE(const uint8_t reg_addr, uint8_t *data, size_t len)
    {
        int ret;
        ret_i2c_en ret_stat = I2C_WRITE_OK;
        ret = i2c_write_dt(&dev_i2c, &reg_addr, len); /* Write the register address to the sensor */
        if (ret < 0) 
        {
            LOG_ERR("I2C: Failed to write register address (err %d)\n", ret);
            ret_stat = I2C_WRITE_NOK;
        }

        ret = i2c_write_dt(&dev_i2c, data, len); /* Write the register address to the sensor */
        if (ret < 0) 
        {
            LOG_ERR("I2C: Failed to write register address (err %d)\n", ret);
            ret_stat = I2C_WRITE_NOK;
        }
    
        return ret_stat; 
    }

    ret_i2c_en Bme_sens::I2C_READ_ID(uint8_t *data, size_t len)
    {
        int ret{0};
        ret_i2c_en ret_stat = I2C_READ_NOK;
        ret = i2c_write_dt(&dev_i2c,&ID_REG, len); /* Write the register address to the sensor */
        if (ret < 0) 
        {
            LOG_ERR("I2C: Failed to write register address (err %d)\n", ret);
            ret_stat = I2C_READ_OK;
        }
    
        ret = i2c_read_dt(&dev_i2c, data, len); /* Read the data from the sensor */
        if (ret < 0) 
        {
            LOG_ERR("I2C: Failed to read data (err %d)\n", ret);
            ret_stat = I2C_READ_OK;
        }
    
        return ret_stat; 
    }


}