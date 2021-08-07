#pragma once
#include "rabbitmqBasic.h"
class rabbitmqConsumer :
    public rabbitmqBasic
{
public:

    rabbitmqConsumer(string hostname, int port, string userName, string password)
        :rabbitmqBasic(hostname, port, userName, password)
    {

    }
    amqp_queue_declare_ok_t* declareQueue(amqp_channel_t chID, string queueName);
    void bindQueue(amqp_channel_t chID, string queueName, string exchangeName, string bindingkey);
    void basicConsume(amqp_channel_t chID, string queueName);
    void recvMsg();
};

