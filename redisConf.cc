 ///
 /// @file    redisConf.cc
 /// @author  chinxi(chenchengxi993@gmail.com)
 /// @date    2016-12-15 15:04:16
 ///

#include "redisConf.h"


#include <stdlib.h>
#include <json/json.h>

#include <string>
#include <iostream>
#include <fstream>

namespace ccx{

using std::ifstream;
using std::cout;
using std::endl;

RedisConf::RedisConf()
{
	getConf();
}

void RedisConf::getConf()
{
	ifstream ifs;
	ifs.open("redisConf.json");
	if(!ifs.good())
	{
		cout << "open RedisConf.json error" << endl;
		exit(EXIT_FAILURE);
	}

	Json::Value root;
	Json::Reader reader;
	if(!reader.parse(ifs, root, false))
	{
		cout << "RedisConf json reader error" << endl;
		exit(EXIT_FAILURE);
	}
	
	_ip = root["IP"].asString();
	_port = root["PORT"].asInt();
	ifs.close();
}

string RedisConf::getIP()
{
	return _ip;
}

int RedisConf::getPort()
{
	return _port;
}

}

