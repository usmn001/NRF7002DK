
#ifndef PRES_SENS_FUNC_H
#define PRES_SENS_FUNC_H

#include "Temp_Sens.hpp"
namespace BME680
{
    constexpr uint8_t PAR_P1_LSB_REG        = 0x8E;       // Calibration data for pressure compensation
    constexpr uint8_t PAR_P1_MSB_REG        = 0x8F;       // Calibration data for pressure compensation
    constexpr uint8_t PAR_P2_LSB_REG        = 0x90;       // Calibration data for pressure compensation
    constexpr uint8_t PAR_P2_MSB_REG        = 0x91;       // Calibration data for pressure compensation
    constexpr uint8_t PAR_P3_REG            = 0x92;       // Calibration data for pressure compensation
    constexpr uint8_t PAR_P4_LSB_REG        = 0x94;       // Calibration data for pressure compensation
    constexpr uint8_t PAR_P4_MSB_REG        = 0x95;       // Calibration data for pressure compensation
    constexpr uint8_t PAR_P5_LSB_REG        = 0x96;       // Calibration data for pressure compensation
    constexpr uint8_t PAR_P5_MSB_REG        = 0x97;       // Calibration data for pressure compensation
    constexpr uint8_t PAR_P6_REG            = 0x99;       // Calibration data for pressure compensation
    constexpr uint8_t PAR_P7_REG            = 0x98;       // Calibration data for pressure compensation
    constexpr uint8_t PAR_P8_LSB_REG        = 0x9C;       // Calibration data for pressure compensation
    constexpr uint8_t PAR_P8_MSB_REG        = 0x9D;       // Calibration data for pressure compensation
    constexpr uint8_t PAR_P9_LSB_REG        = 0x9E;       // Calibration data for pressure compensation
    constexpr uint8_t PAR_P9_MSB_REG        = 0x9F;       // Calibration data for pressure compensation
    constexpr uint8_t PAR_P10_REG           = 0xA0;       // Calibration data for pressure compensation

    constexpr uint8_t PRESS_MSB_REG         = 0x1F;       // Bits 7:0
    constexpr uint8_t PRESS_LSB_REG         = 0x20;       // Bits 7:0
    constexpr uint8_t PRESS_XLSB_REG        = 0x21;       // Bits 7:4
    
    
    
    class Pres_Sens : public Temp_Sens
    {
    
    protected :
    Pres_Sens();    
    
    private :
    static uint16_t par_p1;
    static int16_t  par_p2;
    static int8_t   par_p3;
    static int16_t  par_p4;
    static int16_t  par_p5;
    static int8_t   par_p6;
    static int8_t   par_p7;
    static int16_t  par_p8;
    static int16_t  par_p9;
    static uint8_t  par_p10;
    

    public :
    static Pres_Sens & instance();
    //static Pres_Sens & get_instance() { return instance(); } // Alternative method to access the singleton instance
    virtual ret_i2c_en I2C_READ_SENS(float *result) override;
    virtual void CONFIG_CALIB() override;
    virtual ~Pres_Sens()=default;
    };
}

























#endif // BME680_FUNC_H