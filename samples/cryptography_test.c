#include "../sstring/sstring.h"

int main(void)
{
	sstring msg = new_sstring(1, "");
	sstring key = new_sstring(1, "");
	printf("MESSAGE:\n");
	if (msg.in(&msg, true, 1024 * 1024) == false)
	{
		printf("ERR: could not get the message.\n");
		msg.destructor(&msg);
		key.destructor(&key);
		return -1;
	}
	printf("KEY:\n");
	if (key.in(&key, true, 1024 * 1024) == false)
	{
		printf("ERR: could not get the key.\n");
		msg.destructor(&msg);
		key.destructor(&key);
		return -1;
	}
	printf("ENCRYPTED MESSAGE:\n");
	if (msg.encrypt(&msg, key.c_str(&key)) == false)
	{
		printf("ERR: could not encrypt the message.\n");
		msg.destructor(&msg);
		key.destructor(&key);
		return -1;
	}
	msg.print(&msg, true, "");
	printf("DECRYPTED MESSAGE:\n");
	if (msg.decrypt(&msg, key.c_str(&key)) == false)
	{
		printf("ERR: could not decrypt the message.\n");
		msg.destructor(&msg);
		key.destructor(&key);
		return -1;
	}
	msg.print(&msg, true, "");
	msg.destructor(&msg);
	key.destructor(&key);
	return 0;
}