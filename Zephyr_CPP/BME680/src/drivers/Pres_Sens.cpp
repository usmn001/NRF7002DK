
#include "Pres_Sens.hpp"
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(Pressure_Sensor);


namespace BME680
{
    Pres_Sens::Pres_Sens():Temp_Sens()
    {

    }

    Pres_Sens & Pres_Sens::instance()
    {
        static Pres_Sens instance; // This instance will be created only once and will be shared across the entire application
        return instance;
    }

    void Pres_Sens::CONFIG_CALIB()
    {
        uint8_t par_p1_temp[2] = {0};
        int16_t par_p2_temp[2] = {0};
        int16_t par_p4_temp[2] = {0};
        int16_t par_p5_temp[2] = {0};
        int16_t par_p8_temp[2] = {0};
        int16_t par_p9_temp[2] = {0};

        ret_i2c_en ret_stat = I2C_READ_OK;
        
        ret_stat = I2C_READ(PAR_P1_LSB_REG, &par_p1_temp[0]);
        if (ret_stat != I2C_READ_OK) 
        {
            LOG_ERR("I2C: Failed to read pressure par_p1  LSB calibration data\n");
            ret_stat = I2C_READ_NOK;
        }

        ret_stat = I2C_READ(PAR_P1_MSB_REG, &par_p1_temp[1]);
        if (ret_stat != I2C_READ_OK) 
        {
            LOG_ERR("I2C: Failed to read pressure par_p1  MSB calibration data\n");
            ret_stat = I2C_READ_NOK;
        }

        par_p1 = (uint16_t)((par_p1_temp[1] << 8) | par_p1_temp[0]); // Combine MSB and LSB for T1



        ret_stat = I2C_READ(PAR_P2_LSB_REG, (uint8_t*)&par_p2_temp[0]);
        if (ret_stat != I2C_READ_OK) 
        {
            LOG_ERR("I2C: Failed to read pressure par_p2  LSB calibration data\n");
            ret_stat = I2C_READ_NOK;
        }

        ret_stat = I2C_READ(PAR_P2_MSB_REG, (uint8_t*)&par_p2_temp[1]);
        if (ret_stat != I2C_READ_OK) 
        {
            LOG_ERR("I2C: Failed to read pressure par_p2  MSB calibration data\n");
            ret_stat = I2C_READ_NOK;
        }

        par_p2 = (int16_t)((par_p2_temp[1] << 8) | par_p1_temp[0]); // Combine MSB and LSB for T1

        
        ret_stat = I2C_READ(PAR_P3_REG, (uint8_t*)&par_p3);
        if (ret_stat != I2C_READ_OK) 
        {
            LOG_ERR("I2C: Failed to read temperature par_p3 LSB calibration data\n");
            ret_stat = I2C_READ_NOK;
        }
 
         
        ret_stat = I2C_READ(PAR_P4_LSB_REG, (uint8_t*)&par_p4_temp[0]);
        if (ret_stat != I2C_READ_OK) 
        {
            LOG_ERR("I2C: Failed to read pressure par_p4  LSB calibration data\n");
            ret_stat = I2C_READ_NOK;
        }

        ret_stat = I2C_READ(PAR_P4_MSB_REG, (uint8_t*)&par_p4_temp[1]);
        if (ret_stat != I2C_READ_OK) 
        {
            LOG_ERR("I2C: Failed to read pressure par_p4  MSB calibration data\n");
            ret_stat = I2C_READ_NOK;
        }

        par_p4 = (int16_t)((par_p4_temp[1] << 8) | par_p4_temp[0]); // Combine MSB and LSB for T1


        ret_stat = I2C_READ(PAR_P5_LSB_REG, (uint8_t*)&par_p5_temp[0]);
        if (ret_stat != I2C_READ_OK) 
        {
            LOG_ERR("I2C: Failed to read pressure par_p5  LSB calibration data\n");
            ret_stat = I2C_READ_NOK;
        }

        ret_stat = I2C_READ(PAR_P5_MSB_REG, (uint8_t*)&par_p5_temp[1]);
        if (ret_stat != I2C_READ_OK) 
        {
            LOG_ERR("I2C: Failed to read pressure par_p5  MSB calibration data\n");
            ret_stat = I2C_READ_NOK;
        }

        par_p5 = (int16_t)((par_p5_temp[1] << 8) | par_p5_temp[0]); // Combine MSB and LSB for T1


        ret_stat = I2C_READ(PAR_P6_REG, (uint8_t*)&par_p6);
        if (ret_stat != I2C_READ_OK) 
        {
            LOG_ERR("I2C: Failed to read pressure par_p6  LSB calibration data\n");
            ret_stat = I2C_READ_NOK;
        }

        ret_stat = I2C_READ(PAR_P7_REG, (uint8_t*)&par_p7);
        if (ret_stat != I2C_READ_OK) 
        {
            LOG_ERR("I2C: Failed to read pressure par_p7  MSB calibration data\n");
            ret_stat = I2C_READ_NOK;
        }


        ret_stat = I2C_READ(PAR_P8_LSB_REG, (uint8_t*)&par_p8_temp[0]);
        if (ret_stat != I2C_READ_OK) 
        {
            LOG_ERR("I2C: Failed to read pressure par_p8  LSB calibration data\n");
            ret_stat = I2C_READ_NOK;
        }

        ret_stat = I2C_READ(PAR_P8_MSB_REG, (uint8_t*)&par_p8_temp[1]);
        if (ret_stat != I2C_READ_OK) 
        {
            LOG_ERR("I2C: Failed to read pressure par_p8  MSB calibration data\n");
            ret_stat = I2C_READ_NOK;
        }

        par_p8 = (int16_t)((par_p8_temp[1] << 8) | par_p8_temp[0]); // Combine MSB and LSB for T1


        ret_stat = I2C_READ(PAR_P9_LSB_REG, (uint8_t*)&par_p9_temp[0]);
        if (ret_stat != I2C_READ_OK) 
        {
            LOG_ERR("I2C: Failed to read pressure par_p9  LSB calibration data\n");
            ret_stat = I2C_READ_NOK;
        }

        ret_stat = I2C_READ(PAR_P8_MSB_REG, (uint8_t*)&par_p9_temp[1]);
        if (ret_stat != I2C_READ_OK) 
        {
            LOG_ERR("I2C: Failed to read pressure par_p9  MSB calibration data\n");
            ret_stat = I2C_READ_NOK;
        }

        par_p9 = (int16_t)((par_p9_temp[1] << 8) | par_p9_temp[0]); // Combine MSB and LSB for T1


        ret_stat = I2C_READ(PAR_P10_REG, (uint8_t*)&par_p10);
        if (ret_stat != I2C_READ_OK) 
        {
            LOG_ERR("I2C: Failed to read pressure par_p10  MSB calibration data\n");
            ret_stat = I2C_READ_NOK;
        }

        var1 = ((float)t_fine / 2.0f) - 64000.0f;
        var2 = var1 * var1 * ((float)par_p6 / 131072.0f);
        var2 = var2 + (var1 * (float)par_p5 * 2.0f);
        var2 = (var2 / 4.0f) + ((float)par_p4 * 65536.0f);
        var1 = ((((float)par_p3 * var1 * var1) / 16384.0f) + ((float)par_p2 * var1)) / 524288.0f;
        var1 = (1.0f + (var1 / 32768.0f)) * (float)par_p1;

    }

    ret_i2c_en Pres_Sens::I2C_READ_SENS(float *result)
    {
        uint8_t pres_data[3] = {0}; // Array to hold the raw temperature data (MSB, LSB, XLSB)             
        uint8_t meas_status{0}; 
        float var1_n{0},var2_n{0},var3{0};
        int32_t press_raw{0}; 
        float press_comp{0};
        ret_i2c_en ret_stat = I2C_READ_OK;
        
        //LOG_INF("IN READ_SENS VAR1_INIT VALUE = %i, VAR2_INIT VALUE %i,VAR3 VALUE %i ",var1_n,var2_n,var3); 
        while((meas_status & 0x20)==0x20)
        {
            ret_stat = I2C_READ(MEAS_STAT_REG,&meas_status);
            if(ret_stat != I2C_READ_OK)
            {
            LOG_ERR("I2C: Failed To Read Measurement Status\n");
            ret_stat = I2C_READ_NOK; 
            }
        }
        
        int ret = i2c_burst_read_dt(&dev_i2c,PRESS_MSB_REG,pres_data,3);
        if (ret!=0) 
        {
            LOG_ERR("I2C: Failed to read temperature data MSB,LSB,XLSB\n");
            ret_stat = I2C_READ_NOK;
        }

       press_raw = (pres_data[0] << 12) | (pres_data[1] << 4) | (pres_data[2] >> 4); // Combine MSB, LSB, and XLSB for raw temperature
        
       press_comp = 1048576.0f - (float)press_raw;
       press_comp = ((press_comp - (var2 / 4096.0f)) * 6250.0f) / var1;
       var1_n = ((float)par_p9 * press_comp * press_comp) / 2147483648.0f;
       var2_n = press_comp * ((float)par_p8 / 32768.0f);
       var3 = (press_comp / 256.0f) * (press_comp / 256.0f) * (press_comp / 256.0f) * (par_p10 / 131072.0f);
       press_comp = press_comp + (var1_n + var2_n + var3 + ((float)par_p7 * 128.0f)) / 16.0f; 
       *result = press_comp;
        
        return ret_stat;
    }

}

    static int sensor_manager_init(void)
    {
        auto &temp_sensor = BME680::Temp_Sens::instance();
        temp_sensor.I2C_INIT();
        temp_sensor.I2C_READ_ID();
        temp_sensor.CONFIG_OSRS();
        temp_sensor.CONFIG_CALIB();
        
        auto &pres_sensor = BME680::Pres_Sens::instance();
        pres_sensor.CONFIG_CALIB();
        return 0;    
    }

SYS_INIT(sensor_manager_init, APPLICATION, 90);