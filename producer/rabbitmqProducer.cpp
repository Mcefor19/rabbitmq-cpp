#include "rabbitmqProducer.h"

void rabbitmqProducer::basicPublish(amqp_channel_t chID, string exchangeName, string routingKey, amqp_bytes_t bytes)
{
	amqp_basic_publish(_conn, 1,
		amqp_cstring_bytes(exchangeName.c_str()), amqp_cstring_bytes(routingKey.c_str()), 0, 0, NULL,
		bytes);
}