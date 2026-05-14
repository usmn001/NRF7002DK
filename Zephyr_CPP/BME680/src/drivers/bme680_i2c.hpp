#ifndef BME680_FUNC_H
#define BME680_FUNC_H

#include <iostream>
#include <zephyr/kernel.h>        /* For using kernel services as we are using k_msleep() function*/
#include <zephyr/drivers/i2c.h>  /* Contains structure i2c_dt_spec, the macros I2C_DT_SPEC_GET(), and the functions, i2c_is_ready_dt(), i2c_write_dt() and i2c_read_dt().*/
#include <stdbool.h>

namespace BME680
{
    #define I2C1_NODE DT_NODELABEL(sensor1) /* Line uses the devicetree macro DT_NODELABEL() to get the node identifier symbol from i2c1, which will represent node i2c1 */

    constexpr uint8_t STATUS_REG            = 0x73;
    constexpr uint8_t RESET_REG             = 0xE0;
    constexpr uint8_t ID_REG                = 0xD0;
    constexpr uint8_t CONFIG_REG            = 0x75;

    constexpr uint8_t CTRL_HUM_REG          = 0x72;
    constexpr uint8_t CTRL_GAS_REG          = 0x71;
    constexpr uint8_t CTRL_GAS_1_REG        = 0x71;
    constexpr uint8_t CTRL_GAS_0_REG        = 0x70;

    // TEMPERATURE , PRESSURE,HUMIDITY, GAS DATA REGISTERS
    constexpr uint8_t TEMP_MSB_REG          = 0x22;       // Bits 7:0 
    constexpr uint8_t TEMP_LSB_REG          = 0x23;       // Bits 7:0
    constexpr uint8_t TEMP_XLSB_REG         = 0x24;       // Bits 7:4

    constexpr uint8_t HUM_MSB_REG           = 0x25;       // Bits 7:0
    constexpr uint8_t HUM_LSB_REG           = 0x26;       // Bits 7:0

    constexpr uint8_t PRESS_MSB_REG         = 0x1F;       // Bits 7:0
    constexpr uint8_t PRESS_LSB_REG         = 0x20;       // Bits 7:0
    constexpr uint8_t PRESS_XLSB_REG        = 0x21;       // Bits 7:4

    // GAS SENSOR RESISTANCE DATA REGISTERS
    constexpr uint8_t GAS_R_MSB_REG         = 0x2A;        // Bits 7:0
    constexpr uint8_t GAS_R_LSB_REG         = 0x2B;        // Bits 7:6 , Bits 3 :0 For Gas Sensor Resistance Range.
    
    /* 
    TEMP,PRES,HUM,GAS MEASUREMENT STATUS REG
    Measuring bit is set to “1‟ only during gas measurements, goes to “0‟ as soon as measurement is completed and data
    transferred to data registers.  
    */
    constexpr uint8_t MEAS_STAT_REG         = 0x1D;       // Bit position is 6 For Gas Status
                                                          // Bit Position is 5 For Temp, Pressure, Humidity Status  
    
    
    constexpr uint8_t CTRL_TEMP_PRES_REG    = 0x74;

    // CTRL REGISTER MODE BITS CONTROLLING SENSOR MODES
    constexpr uint8_t CTRL_MODE_SLEEP       = 0x00;   
    constexpr uint8_t CTRL_MODE_FORCED      = 0x01;
    
    // CTRL REGISTER TEMPERATURE BITS
    constexpr uint8_t CTRL_TEMP_SAMP1       = 0x20;   
    constexpr uint8_t CTRL_TEMP_SAMP2       = 0x40;
    constexpr uint8_t CTRL_TEMP_SAMP4       = 0x60; 
    constexpr uint8_t CTRL_TEMP_SAMP8       = 0x80;
    constexpr uint8_t CTRL_TEMP_SAMP16      = 0xA0;
    
    // CTRL REGISTER PRESSURE SAMPLING BITS
    constexpr uint8_t CTRL_PRES_SAMP1        = CTRL_TEMP_SAMP1>>3;   
    constexpr uint8_t CTRL_PRES_SAMP2        = CTRL_TEMP_SAMP2>>3; 
    constexpr uint8_t CTRL_PRES_SAMP4        = CTRL_TEMP_SAMP4>>3;  
    constexpr uint8_t CTRL_PRES_SAMP8        = CTRL_TEMP_SAMP8>>3; 
    constexpr uint8_t CTRL_PRES_SAMP16       = CTRL_TEMP_SAMP16>>3; 
    
    typedef enum : uint8_t  
    {    
        I2C_READ_OK   = 0,
        I2C_READ_NOK  = 1,
        I2C_WRITE_OK  = 2,
        I2C_WRITE_NOK = 3,
        I2C_INIT_OK   = 4,
        I2C_INIT_NOK  = 5
    }ret_i2c_en;


    class Bme_sens
    {
        private :
        const struct i2c_dt_spec dev_i2c;   /* Structure containing pointer to device node bme680  */
        public : 
        Bme_sens();
        ~Bme_sens();
        ret_i2c_en I2C_INIT();
        ret_i2c_en I2C_WRITE(const uint8_t reg_addr, uint8_t *data, size_t len);
        ret_i2c_en I2C_READ(const uint8_t reg_addr, uint8_t *data, size_t len);
        ret_i2c_en I2C_READ_ID(uint8_t *data, size_t len);
        ret_i2c_en I2C_READ_TEMP(uint8_t *data, size_t len);
        ret_i2c_en I2C_READ_PRESSURE(uint8_t *data, size_t len);
    };
}

#endif // BME680_FUNC_H