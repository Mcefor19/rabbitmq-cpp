#include <iostream>
#include <string>
#include <rabbitmq-c/amqp.h>
#include <rabbitmq-c/tcp_socket.h>
#include <windows.h>
#include "utils.h"

using namespace std;

class rabbitmqBasic
{
public:
	rabbitmqBasic(string hostname, int port, string userName, string password);
	virtual ~rabbitmqBasic();

	void createNewConnection();
	void opernChannel(amqp_channel_t chID);
	void closeChannle(amqp_channel_t chID);
	void closeConnection();
	void destroyConnection();

	amqp_socket_t* createNewSocket();
	int openSocket();

	bool login();
	bool getRPCReply();
protected:
	string _hostname;
	string _userName;
	string _password;
	int _port;
	amqp_connection_state_t _conn;
private:
	amqp_socket_t* _socket = NULL;
};

