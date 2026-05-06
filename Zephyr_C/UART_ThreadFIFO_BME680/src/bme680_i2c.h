#ifndef BME680_FUNC_H
#define BME680_FUNC_H

#include <zephyr/kernel.h>        /* For using kernel services as we are using k_msleep() function*/
#include <zephyr/drivers/i2c.h>  /* Contains structure i2c_dt_spec, the macros I2C_DT_SPEC_GET(), and the functions, i2c_is_ready_dt(), i2c_write_dt() and i2c_read_dt().*/


#define STATUS_REG_ADDR       0x73
#define RESET_REG_ADDR        0xE0
#define ID_REG_ADDR           0xD0
#define CONFIG_REG_ADDR       0x75

#define CTRL_MEAS_REG_ADDR    0x74
#define CTRL_HUM_REG_ADDR     0x72
#define CTRL_GAS_REG_ADDR     0x71
#define CTRL_GAS_1_REG_ADDR   0x71
#define CTRL_GAS_0_REG_ADDR   0x70

#define TEMP_LSB_REG_ADDR     0x22
#define TEMP_MSB_REG_ADDR     0x23

#define PRESS_LSB_REG_ADDR    0x1F
#define PRESS_MSB_REG_ADDR    0x20
#define HUM_LSB_REG_ADDR      0x2A
#define HUM_MSB_REG_ADDR      0x2B




#define I2C1_NODE DT_NODELABEL(sensor1) /* Line uses the devicetree macro DT_NODELABEL() to get the node identifier symbol from i2c1, which will represent node i2c1 */


void i2c_init(void);


//int8_t i2c_write(uint8_t reg_addr, uint8_t *data, uint16_t len);
int8_t I2C_READ(const uint8_t reg_addr, uint8_t *data, size_t len);






#endif // BME680_FUNC_H