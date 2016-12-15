 ///
 /// @file    test.cc
 /// @author  chinxi(chenchengxi993@gmail.com)
 /// @date    2016-12-15 16:27:33
 ///

#include "redis.h"

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main()
{
	ccx::Redis redis;
	redis.Connect();
	redis.setString("name", "ii");
	string temp = redis.getString("name");
	cout << temp << endl;
	redis.disConnect();
}
