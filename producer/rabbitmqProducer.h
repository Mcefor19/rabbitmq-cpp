#pragma once
#include "rabbitmqBasic.h"
class rabbitmqProducer :
    public rabbitmqBasic
{
public:
    rabbitmqProducer(string hostname, int port, string userName, string password) :
        rabbitmqBasic(hostname, port, userName, password)
    {

    }
    void basicPublish(amqp_channel_t chID, string exchangeName, string routingKey, amqp_bytes_t bytes);
};

