#include <Arduino.h>
#include "BluetoothA2DPSinkQueued.h"

// https://github.com/pschatzmann/ESP32-A2DP/wiki/External-DAC

BluetoothA2DPSinkQueued a2dp_sink;

// ------------------------------------------------------------------------------
// I2S Output Connection Pins
#define I2S_DOUT       22
#define I2S_LRC        25
#define I2S_BCLK       26

// Internal DAC Output Pins
#define DAC_1_OUT      25
#define DAC_2_OUT      26

// ------------------------------------------------------------------------------
// ------------------------------------------------------------------------------

void setup() 
{
    static i2s_config_t i2s_config = 
    {
        .mode = (i2s_mode_t) (I2S_MODE_MASTER | I2S_MODE_TX),
        .sample_rate = 44100, // Corrected by info from bluetooth.
        .bits_per_sample = (i2s_bits_per_sample_t)32,
        .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
        .communication_format = (i2s_comm_format_t) (I2S_COMM_FORMAT_STAND_I2S),
        .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1, // default interrupt priority
        .dma_buf_count = 16, // Tim, Was 8
        .dma_buf_len = 256,  // Tim, Was 64
        .use_apll = true, // Tim, this seems reduce noice.
        .tx_desc_auto_clear = true, // Tim K: Turned off to reduce popping noise     
    };  

    a2dp_sink.set_i2s_config(i2s_config);  

    a2dp_sink.set_i2s_ringbuffer_size(2 * 32 * 1024);
    
    
    a2dp_sink.set_auto_reconnect(true);
    a2dp_sink.start("Tims-WRover-Speakers");
}

// ------------------------------------------------------------------------------
// ------------------------------------------------------------------------------

void loop() {
    delay(10000);
}

// ------------------------------------------------------------------------------
// ------------------------------------------------------------------------------

