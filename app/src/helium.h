#ifndef HELIUM__H__
// Helium way of packing/decoding

#define LORAWAN_APP_DATA_BUFF_SIZE 200 //64
static uint8_t m_lora_app_data_buffer[LORAWAN_APP_DATA_BUFF_SIZE];
// buffer to send to lora_send
// struct lmh_app_data_t m_lora_app_data = {m_lora_app_data_buffer, 0, 0, 0, 0};
struct s_lora_app_data {
        uint8_t * buffer;
        uint8_t buffsize;
        uint8_t port;
        uint16_t rssi;
        uint8_t snr;
};

extern struct s_lora_app_data m_app_data ; //       = {m_lora_app_data_buffer, 0, 0, 0, 0};

// Helium Changes
// tell lorawan layer to cycle through only a subset of total channels
int setHeliumChannelsMask();
// lorawan subsystem call
int lorawan_setChannelsMask(uint16_t *);
void setHeliumTransmitBuff(struct s_mapper_data *mapper_data, struct s_lora_app_data *m_app_data);


# endif // HELIUM__H__
