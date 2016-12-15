 ///
 /// @file    redis.h
 /// @author  chinxi(chenchengxi993@gmail.com)
 /// @date    2016-12-15 14:59:04
 ///


#ifndef __REDIS_H__
#define __REDIS_H__

#include "redisConf.h"

#include <hiredis/hiredis.h>


namespace ccx{

class Redis
{
	public:
		Redis();
	public:
		void Connect();
		void disConnect();
	public:
		void setString(const string key, const string value);
		string getString(const string key);
	private:
		void freeReply();
		bool isError();
	private:
		RedisConf _conf;
		redisContext * _context;
		redisReply * _reply;
};
}

#endif
