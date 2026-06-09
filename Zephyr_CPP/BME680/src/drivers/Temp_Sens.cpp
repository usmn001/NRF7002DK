#include "Temp_Sens.hpp"
#include <zephyr/logging/log.h>
#include <zephyr/kernel.h>
#include <zephyr/init.h>

LOG_MODULE_REGISTER(Temp_Sensor);

namespace BME680
{
    uint16_t Temp_Sens::t_par_t1{0};
    int16_t Temp_Sens::t_par_t2{0};
    int8_t  Temp_Sens::t_par_t3{0}; 
    
    Temp_Sens::Temp_Sens():dev_i2c(I2C_DT_SPEC_GET(I2C1_NODE))   /* Structure containing pointer to device node bme680  */
    {
       
    }

   Temp_Sens & Temp_Sens::instance()
    {
  
        static Temp_Sens instance; // This instance will be created only once and will be shared across the entire application
        return instance;
    }

    void Temp_Sens::I2C_INIT()
    {
        if(!device_is_ready(dev_i2c.bus))  /* Check if the I2C device is ready */
        {
            LOG_ERR("I2C: Device is not ready.\n");
        }
        else
        {
            LOG_INF("I2C: Device is ready.\n");
        }
    }

    void Temp_Sens::I2C_READ_ID()
    {
        uint8_t data{0}; 
        I2C_READ(ID_REG, &data); /* Read the sensor ID from the BME680 sensor */    
        LOG_INF("BME680 Sensor ID: %x \n", data);
    }

    ret_i2c_en Temp_Sens::I2C_READ(const uint8_t reg_addr, uint8_t *data)
    {
        int ret{0};
        ret_i2c_en ret_stat = I2C_READ_OK;
        ret = i2c_reg_read_byte_dt(&dev_i2c, reg_addr, data); /* Read a byte of data from the specified register address of the BME680 sensor */
        if (ret < 0)
        {
            LOG_ERR("I2C read failed (%d)", ret);
            ret_stat = I2C_READ_NOK;
        }
        return ret_stat; 
    }

    ret_i2c_en Temp_Sens::I2C_WRITE(const uint8_t reg_addr, uint8_t *data)
    {
        int ret{0};
        ret_i2c_en ret_stat = I2C_WRITE_OK;
        uint8_t tx_buf[2] =   { reg_addr, *data }; /* Buffer to hold the register address and data to be written */
        uint8_t read_back_data{0}; /* Variable to hold the data read back for verification */
        ret = i2c_write_dt(&dev_i2c,tx_buf, sizeof(tx_buf));

        if (ret < 0)
        {
            LOG_ERR("I2C write failed (%d)", ret);
            ret_stat = I2C_WRITE_NOK;
        }

        ret = I2C_READ(reg_addr, &read_back_data); /* Read back the register value to verify the write operation */
        if (ret != I2C_READ_OK || read_back_data != tx_buf[1])
        {
            LOG_ERR("I2C write verification failed. Written value: %x, Read value: %x\n", tx_buf[1], read_back_data);
            ret_stat = I2C_WRITE_NOK;
        }
    
        return ret_stat; 
    }

    ret_i2c_en Temp_Sens::CONFIG_MODE()
    {
        ret_i2c_en ret_stat = I2C_FORCED_MODE_OK;
        uint8_t osrs_mode_r{0};
        uint8_t osrs_mode_w{0};
       
        I2C_READ(CTRL_TEMP_PRES_REG, &osrs_mode_r); 
        osrs_mode_r &= ~0x03;
        osrs_mode_w = CTRL_MODE_FORCED | osrs_mode_r;

        I2C_WRITE(CTRL_TEMP_PRES_REG, &osrs_mode_w); /* Write the mode setting to the control register */
        I2C_READ(CTRL_TEMP_PRES_REG, &osrs_mode_r); 
        
        if(osrs_mode_r != osrs_mode_w)
        {
            LOG_ERR("BME680 forced mode configuration mismatch. Written value: %x, Read value: %x \n", osrs_mode_w, osrs_mode_r);
            ret_stat = I2C_FORCED_MODE_NOK;
        }
        return ret_stat; 
    }

    void Temp_Sens::CONFIG_CALIB()
    {
        ret_i2c_en ret_stat = I2C_READ_OK;
        uint8_t temp_par_t1[2] = {0}; // Calibration parameter T1
        uint8_t temp_par_t2[2]={0}; // Calibration parameter T2
        uint8_t temp_par_t3{0};  // Calibration parameter T3

        ret_stat = I2C_READ(TEMP_PAR_T1_LSB_REG, &temp_par_t1[0]);
        if (ret_stat != I2C_READ_OK) 
        {
            LOG_ERR("I2C: Failed to read temperature par_t1  LSB calibration data\n");
            ret_stat = I2C_READ_NOK;
        }

        ret_stat = I2C_READ(TEMP_PAR_T1_MSB_REG, &temp_par_t1[1]);
        if (ret_stat != I2C_READ_OK) 
        {
            LOG_ERR("I2C: Failed to read temperature par_t1  MSB calibration data\n");
            ret_stat = I2C_READ_NOK;
        }

        t_par_t1 = (uint16_t)((temp_par_t1[1] << 8) | temp_par_t1[0]); // Combine MSB and LSB for T1


        ret_stat = I2C_READ(TEMP_PAR_T2_LSB_REG, &temp_par_t2[0]);
        if (ret_stat != I2C_READ_OK) 
        {
            LOG_ERR("I2C: Failed to read temperature par_t2  LSB calibration data\n");
            ret_stat = I2C_READ_NOK;
        }
        ret_stat = I2C_READ(TEMP_PAR_T2_MSB_REG, &temp_par_t2[1]);
        if (ret_stat != I2C_READ_OK) 
        {
            LOG_ERR("I2C: Failed to read temperature par_t2  MSB calibration data\n");
            ret_stat = I2C_READ_NOK;
        } 

        t_par_t2 = (int16_t)(((uint16_t)temp_par_t2[1] << 8) | temp_par_t2[0]);

        ret_stat = I2C_READ(TEMP_PAR_T3_LSB_REG, &temp_par_t3);
        if (ret_stat != I2C_READ_OK) 
        {
            LOG_ERR("I2C: Failed to read temperature par_t3  LSB calibration data\n");
            ret_stat = I2C_READ_NOK;
        } 
        t_par_t3 = (int8_t)temp_par_t3;
    }

    void Temp_Sens::CONFIG_OSRS()
    {
        uint8_t osrs_r{0};
        uint8_t osrs_w{0};
        ret_i2c_en ret_stat = I2C_WRITE_OK;

        osrs_w |=  CTRL_TEMP_SAMP2<<5;
        osrs_w |=  CTRL_PRES_SAMP16<<2;
        

        ret_stat = I2C_WRITE(CTRL_TEMP_PRES_REG, &osrs_w); /* Write the updated control register value back to the sensor */
        ret_stat = I2C_READ(CTRL_TEMP_PRES_REG, &osrs_r); // Read the current value of the control register
        if(osrs_r == osrs_w)
        {
            LOG_INF("BME680 CTRL_TEMP_PRES_REG successfully configured. Current value: %x\n", osrs_r);
        }

        // Configure humidity oversampling settings in the CTRL_HUM_Reg 
        osrs_w = CTRL_HUM_SAMP2;                  // Clear the humidity oversampling bits (bits 2:0)
        ret_stat = I2C_WRITE(CTRL_HUM_REG, &osrs_w); // Write the humidity oversampling setting to the CTRL_HUM_REG */
        ret_stat = I2C_READ(CTRL_HUM_REG, &osrs_r); // Read back the CTRL_HUM_REG to verify the humidity oversampling setting
        if(osrs_r == osrs_w)
        {
            LOG_INF("BME680 CTRL_HUM_REG successfully configured. Current value: %x\n", osrs_r);
        }

    }

    ret_i2c_en Temp_Sens::I2C_READ_SENS(float *result)
    {
        uint8_t temp_data[3] = {0}; // Array to hold the raw temperature data (MSB, LSB, XLSB)             
        uint8_t meas_status{0}; 
        int32_t var1{0}, var2{0},var3{0}, t_fine{0};
        float temp_comp{0.0f};

        ret_i2c_en ret_stat = I2C_READ_OK;


        while((meas_status & 0x80)!=0x80)
        {
            ret_stat = I2C_READ(MEAS_STAT_REG,&meas_status);
            if(ret_stat != I2C_READ_OK)
            {
            LOG_ERR("I2C: Failed To Read Measurement Status\n");
            ret_stat = I2C_READ_NOK; 
            }
        }
        
        int ret = i2c_burst_read_dt(&dev_i2c,TEMP_MSB_REG,temp_data,3);
        if (ret!=0) 
        {
            LOG_ERR("I2C: Failed to read temperature data MSB,LSB,XLSB\n");
            ret_stat = I2C_READ_NOK;
        }
      
        int32_t temp_adc = ((int32_t)temp_data[0] << 12) | ((int32_t)temp_data[1] << 4) | ((int32_t)temp_data[2] >> 4); // Combine MSB, LSB, and XLSB for raw temperature


        /* Perform temperature compensation using the raw temperature data and calibration parameters */
        /* The compensation formula is based on the BME680 datasheet and may require additional calibration parameters for accurate results. For simplicity, this example assumes a basic compensation formula. */  

       
        var1 = (((int32_t)temp_adc >> 3) - ((int32_t)t_par_t1 << 1));
        var2 = (var1 * ((int32_t)t_par_t2)) >> 11;
        var3 = ((var1 >> 1) * (var1 >> 1)) >> 12;
        var3 = (var3 * ((int32_t)t_par_t3 << 4)) >> 14;
        t_fine = var2 + var3;
        temp_comp = ((float)(((t_fine*5)+128)>>8))/100.0f; // Compensated temperature in Celsius

        *result = temp_comp; // Final compensated temperature in Celsius
        
        return ret_stat;
    }

   
}

