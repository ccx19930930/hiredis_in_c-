 ///
 /// @file    redis.cc
 /// @author  chinxi(chenchengxi993@gmail.com)
 /// @date    2016-12-15 15:11:38
 ///


#include "redis.h"

#include <string.h>
#include <stdlib.h>

#include <iostream>

namespace ccx{

using std::cout;
using std::endl;


Redis::Redis()
: _conf()
{
}

void Redis::Connect()
{
	_context = redisConnect(_conf.getIP().c_str(), _conf.getPort());
	cout << _conf.getIP() << "-" << _conf.getPort() << endl;
	if(_context && _context->err)
	{
		cout << "connect redis error" << endl;
		exit(EXIT_FAILURE);	
	}
	cout << "redis Connect success" << endl;
}

void Redis::disConnect()
{
	redisFree(_context);
	cout << "redis disConnect success" << endl;
}

void Redis::setString(const string key, const string value)
{
	freeReply();
	_reply = (redisReply*)redisCommand(_context, "SET %s %s", key.c_str(), value.c_str());
	if(!isError())
	{
		if (!(_reply->type == REDIS_REPLY_STATUS && strcasecmp(_reply->str,"OK") == 0))
		{
			cout << "Failed to execute SET(string)" << endl;
		}	
	}
}
string Redis::getString(const string key)
{
	freeReply();
	_reply = (redisReply*)redisCommand(_context, "GET %s", key.c_str());
	isError();
	if(_reply->type == REDIS_REPLY_STRING)
	{
		return _reply->str;
	}
	return NULL;
}

void Redis::freeReply()
{
	if(_reply)
	{
		freeReplyObject(_reply);
		_reply = NULL;
	}
}

bool Redis::isError()
{
	if(NULL == _reply)
	{
		freeReply();
		disConnect();
		Connect();
		return true;
	}
	return false;
}

}
