
#include "Pres_Sens.hpp"
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(Pressure_Sensor);


namespace BME680
{
    uint16_t Pres_Sens::par_p1{0};
    int16_t  Pres_Sens::par_p2{0};
    int8_t   Pres_Sens::par_p3{0};
    int16_t  Pres_Sens::par_p4{0};
    int16_t  Pres_Sens::par_p5{0};
    int8_t   Pres_Sens::par_p6{0};
    int8_t   Pres_Sens::par_p7{0};
    int16_t  Pres_Sens::par_p8{0};
    int16_t  Pres_Sens::par_p9{0};
    uint8_t  Pres_Sens::par_p10{0};
    
    
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

    }

    ret_i2c_en Pres_Sens::I2C_READ_SENS(float *result)
    {


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