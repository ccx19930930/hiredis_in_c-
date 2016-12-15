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
	redis.setString("name", "lii");
	string s;
	redis.getString("name", s);
	cout << s << endl;
	redis.setString("age", "30");
	redis.getString("age", s);
	cout << s << endl;

	redis.disConnect();
}
