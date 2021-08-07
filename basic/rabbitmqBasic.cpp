#include "rabbitmqBasic.h"

rabbitmqBasic::rabbitmqBasic(string hostname, int port, string userName, string password)
	:_hostname(hostname), _port(port), _userName(userName), _password(password)
{

}

rabbitmqBasic::~rabbitmqBasic()
{

}

void rabbitmqBasic::createNewConnection()
{
	_conn = amqp_new_connection();
}

void rabbitmqBasic::opernChannel(amqp_channel_t chID)
{
	amqp_channel_open(_conn, 1);
}

void rabbitmqBasic::closeChannle(amqp_channel_t chID)
{
	amqp_channel_close(_conn, chID, AMQP_REPLY_SUCCESS);
}

void rabbitmqBasic::closeConnection()
{
	amqp_connection_close(_conn, AMQP_REPLY_SUCCESS);
}

void rabbitmqBasic::destroyConnection()
{
	amqp_destroy_connection(_conn);
}

amqp_socket_t* rabbitmqBasic::createNewSocket()
{
	_socket = amqp_tcp_socket_new(_conn);
	return _socket;
}

int rabbitmqBasic::openSocket()
{
	return amqp_socket_open(_socket, _hostname.c_str(), _port);
}

bool rabbitmqBasic::login()
{
	amqp_rpc_reply_t reply_t = amqp_login(_conn, "/", 0, 131072, 0, AMQP_SASL_METHOD_PLAIN,
		_userName.c_str(), _password.c_str());
	if (reply_t.reply_type == amqp_response_type_enum::AMQP_RESPONSE_NORMAL)
		return true;
	return false;
}

bool rabbitmqBasic::getRPCReply()
{
	if (amqp_get_rpc_reply(_conn).reply_type == amqp_response_type_enum::AMQP_RESPONSE_NORMAL)
		return true;

	return false;
}