
#include "lorawan_config.h"
#include "helium.h"
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(helium_mapper_utils);

struct s_lora_app_data m_app_data       = {m_lora_app_data_buffer, 0, 0, 0, 0};

// utils for Helium support
//
//  if defined, also add the lorawan__setChannlesMask() function to:
//  zephyr/subsys/lorawan/lorawan.c
//  Find it in this project at: Assets/zephyr/subsys/lorawan/lorawan.c

// Enabling 2nd block of 8 channels (8-15) + channel 65

int setHeliumChannelsMask()
{
	int ret = 0;
	uint16_t channelsMask[] = { 0xFF00, 0x0000, 0x0000, 0x0000, 0x0002, 0x0000};
        ret = lorawan_setChannelsMask(channelsMask);
        if (ret < 0) {
                LOG_ERR("lorawan_setChannelsMask failed: %d", ret);
                return ret;
        }
	return ret;
}

void setHeliumTransmitBuff(struct s_mapper_data *mapper_data, struct s_lora_app_data *m_app_data)
{

	LOG_WRN("Location: lat %d", mapper_data->lat);
	LOG_WRN("Location: long %d", mapper_data->lng);

	LOG_WRN("Location: accuracy %d", mapper_data->accuracy);
	LOG_WRN("Location: battery %d", mapper_data->battery);
	LOG_WRN("Location: alt %d", mapper_data->alt);
	LOG_WRN("Location: Fix %d", mapper_data->fix);
	LOG_WRN("Location: Satellites %d", mapper_data->satellites);

	// LOG_HEXDUMP_DBG(data_ptr, sizeof(struct s_mapper_data),
	LOG_HEXDUMP_WRN(mapper_data, sizeof(struct s_mapper_data),
		"mapper_data struct");


	m_app_data->port = 2; // gAppPort;
	m_app_data->buffer[0] = 0x09;
	//lat data

	m_app_data->buffer[1] = (mapper_data->lat & 0xFF000000) >> 24;
	m_app_data->buffer[2] = (mapper_data->lat & 0x00FF0000) >> 16;
	m_app_data->buffer[3] = (mapper_data->lat & 0x0000FF00) >> 8;
	m_app_data->buffer[4] =  mapper_data->lat & 0x000000FF;
	if(mapper_data->lat < 0)
	{
		m_app_data->buffer[5] = 'S';
	}
	else
	{
		m_app_data->buffer[5] = 'N';
	}
	//lon data
	m_app_data->buffer[6] = (mapper_data->lng & 0xFF000000) >> 24;
	m_app_data->buffer[7] = (mapper_data->lng & 0x00FF0000) >> 16;
	m_app_data->buffer[8] = (mapper_data->lng & 0x0000FF00) >> 8;
	m_app_data->buffer[9] =  mapper_data->lng & 0x000000FF;
	
	if(mapper_data->lng < 0)
	{
		m_app_data->buffer[10] = 'E';
	}
	else
	{
		m_app_data->buffer[10] = 'W';
	}

	m_app_data->buffer[12] = (mapper_data->alt & 0x0000FF00) >> 8;
	m_app_data->buffer[13] = (mapper_data->alt & 0x000000FF);
	m_app_data->buffer[14] = (mapper_data->accuracy & 0x0000FF00) >> 8;

	m_app_data->buffer[15] = (mapper_data->accuracy & 0x000000FF);
	m_app_data->buffer[16] = (mapper_data->battery & 0x0000FF00) >> 8;
	m_app_data->buffer[17] = (mapper_data->battery & 0x000000FF);
	m_app_data->buffer[18] = (mapper_data->satellites & 0x000000FF);
	m_app_data->buffer[19] = (mapper_data->fix & 0x000000FF);

	m_app_data->buffsize = 20;
	
	LOG_HEXDUMP_WRN(m_app_data->buffer, m_app_data->buffsize, //sizeof(struct s_mapper_data),
		"Raw LoRaWan data");


}
