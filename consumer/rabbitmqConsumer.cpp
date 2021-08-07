#include "rabbitmqConsumer.h"

amqp_queue_declare_ok_t* rabbitmqConsumer::declareQueue(amqp_channel_t chID, string queueName)
{
	return amqp_queue_declare(_conn, chID, amqp_cstring_bytes(queueName.c_str()), 0, 0, 0, 1, amqp_empty_table);
}

void rabbitmqConsumer::bindQueue(amqp_channel_t chID, string queueName, string exchangeName, string bindingkey)
{
	amqp_queue_bind(_conn, chID, amqp_cstring_bytes(queueName.c_str()), amqp_cstring_bytes(exchangeName.c_str()),
		amqp_cstring_bytes(bindingkey.c_str()), amqp_empty_table);
}

void rabbitmqConsumer::basicConsume(amqp_channel_t chID, string queueName)
{
	amqp_basic_consume(_conn, chID, amqp_cstring_bytes(queueName.c_str()), amqp_empty_bytes, 0, 1, 0,amqp_empty_table);
}

void rabbitmqConsumer::recvMsg()
{
	amqp_rpc_reply_t ret;
	amqp_envelope_t envelope;

	amqp_maybe_release_buffers(_conn);
	ret = amqp_consume_message(_conn, &envelope, NULL, 0);

	if (AMQP_RESPONSE_NORMAL == ret.reply_type)
	{
		string str((char*)envelope.message.body.bytes, (char*)envelope.message.body.bytes + envelope.message.body.len);
		cout << (int)((char*)envelope.message.body.bytes)[0] << (int)((char*)envelope.message.body.bytes)[1] << endl;
		cout << str << endl;
		amqp_destroy_envelope(&envelope);
	}
}